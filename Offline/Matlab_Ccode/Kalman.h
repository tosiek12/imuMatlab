#ifndef KALMAN_H_
#define KALMAN_H_
#include "typedef.h"

extern float32_t Q_angle; // Process noise variance for the accelerometer
extern float32_t Q_bias; // Process noise variance for the gyro bias
extern float32_t R_measure; // Measurement noise variance - this is actually the variance of the measurement noise

extern float32_t angle; // The angle calculated by the Kalman filter - part of the 2x1 state vector
extern float32_t bias; // The gyro bias calculated by the Kalman filter - part of the 2x1 state vector
extern float32_t P[2][2]; // Error covariance matrix - This is a 2x2 matrix
extern float32_t K[2]; // Kalman gain - This is a 2x1 vector
extern float32_t y; // Angle difference
extern float32_t S; // Estimate error

extern float32_t compAngle;

void KalmanInitialize();
// The angle in degrees and the rate in degrees per second and the dt in seconds
void stepOldVersion(const float32_t newAngle, const float32_t newRate, const float32_t dt);

#endif /* KALMAN_H_ */
