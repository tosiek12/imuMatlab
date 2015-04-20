#include "Kalman.h"
float32_t Q_angle; // Process noise variance for the accelerometer
float32_t Q_bias; // Process noise variance for the gyro bias
float32_t R_measure; // Measurement noise variance - this is actually the variance of the measurement noise

float32_t angle; // The angle calculated by the Kalman filter - part of the 2x1 state vector
float32_t bias; // The gyro bias calculated by the Kalman filter - part of the 2x1 state vector
float32_t P[2][2]; // Error covariance matrix - This is a 2x2 matrix
float32_t K[2]; // Kalman gain - This is a 2x1 vector
float32_t y; // Angle difference
float32_t S; // Estimate error

float32_t compAngle;

void complementaryFilterStep(const float32_t newAngle, const float32_t newRate, const float32_t dt) {
	const float32_t alpha = 0.01;
	// Complementary filter
	compAngle = ((1-alpha) * (compAngle + newRate * dt))
			+ (alpha * newAngle);
}

void KalmanInitialize() {
	/* The variables are set like so, these can also be tuned by the user. */
	Q_angle = (float32_t)0.2;
	Q_bias = (float32_t)0.3;
	R_measure = (float32_t)0.3;
	angle = (float32_t)0; // Reset the angle
	bias = (float32_t)0; // Reset bias

	P[0][0] = 100; // Since we assume that the bias is 0 and we know the starting angle (use setAngle), the error covariance matrix is set like so - see: http://en.wikipedia.org/wiki/Kalman_filter#Example_application.2C_technical
	P[0][1] = 0;
	P[1][0] = 0;
	P[1][1] = 100;
}

// The angle in degrees and the rate in degrees per second and the dt in seconds
void stepOldVersion(const float32_t newAngle, const float32_t newRate, const float32_t dt) {
	// KasBot V2  -  Kalman filter module - http://www.x-firm.com/?page_id=145
	// See my blog post for more information: http://blog.tkjelectronics.dk/2012/09/a-practical-approach-to-kalman-filter-and-how-to-implement-it

	// Stage 1: Predict
	// Update xhat - Project the state ahead
	angle += dt * (newRate - bias);
	// Update estimation error covariance
	P[0][0] += dt * (dt * P[1][1] - P[0][1] - P[1][0] + Q_angle);
	P[0][1] += -dt * P[1][1];
	P[1][0] += -dt * P[1][1];
	P[1][1] += Q_bias * dt;

	// Stage 2: Correct
	// Calculate Kalman gain
	S = P[0][0] + R_measure;
	/* Step 5 */
	K[0] = P[0][0] / S;
	K[1] = P[1][0] / S;

	// Update estimate with measurement zk (newAngle)
	y = newAngle - angle;
	/* Step 6 */
	angle += K[0] * y;
	bias += K[1] * y;

	// Update the error covariance
	P[0][0] -= K[0] * P[0][0];
	P[0][1] -= K[0] * P[0][1];
	P[1][0] -= K[1] * P[0][0];
	P[1][1] -= K[1] * P[0][1];
	
	complementaryFilterStep(newAngle, newRate, dt);
}

