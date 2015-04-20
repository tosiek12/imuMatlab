#include "angles.h" 

extern float32_t XRollAngle;
extern float32_t YPitchAngle;
extern float32_t YPitchAngle2;
extern float32_t TiltAngle;
extern float32_t ZYawAngle[2];

void computeAngles(float32_t accIn[3], float32_t magIn[3]) {
	float32_t sqrt_result, arg1, arg2;
	//For Rotation xyz - widely used in aerospace - called 'aerospace rotation sequence'.
	const float32_t accNorm = (float32_t) sqrt((accIn[0])*(accIn[0]) + (accIn[1])*(accIn[1]) + (accIn[2])*(accIn[2]));
	float32_t acc[3];
	int signZ;	
	const float32_t mi = 0.01;
	
	const float32_t magNorm = (float32_t) sqrt((magIn[0])*(magIn[0]) + (magIn[1])*(magIn[1]) + (magIn[2])*(magIn[2]));
	const float32_t MaxB = 123;	//TODO: uzupelnic wartos max do skalowania.
	float32_t mag[3];
	
	//Normalise measurement:
	acc[0] = accIn[0] / accNorm;
	acc[1] = accIn[1] / accNorm;
	acc[2] = accIn[2] / accNorm;
	mag[0] = magIn[0] / magNorm;
	mag[1] = magIn[1] / magNorm;
	mag[2] = magIn[2] / magNorm;
	
	//wzór jest nieprawdziwy, gdy z=0 i y=0. nie ma jednego dobreg rozwiazania. Mozna np. aproksymować w ten sposob:
	if(acc[2] > 0) {
		signZ = 1;
	} else {
		signZ = -1;
	}
	sqrt_result = sqrt((acc[2])*(acc[2]) + mi*(acc[0])*(acc[0]));
	XRollAngle = atan2(acc[1], signZ*sqrt_result);
	//XRollAngle = atan2(acc[1], acc[2]); //old
	
	sqrt_result = sqrt((acc[2])*(acc[2]) + (acc[1])*(acc[1]));
	YPitchAngle = atan2(-(acc[0]),sqrt_result);
	//YPitchAngle2 = asin((float32_t)(-acc[0])/(float32_t)(g));
	//zawsze stabilne, gdy działa tylko grawitacja! 
	//Rozwazyc przypadek, gdy jest zewn. pole!
	
	sqrt_result = sqrt((acc[2])*(acc[2]) + (acc[0])*(acc[0]) + (acc[1])*(acc[1]));
	TiltAngle = acos((acc[2])/sqrt_result);

	arg1 = sin(XRollAngle)*mag[2] - cos(XRollAngle)*mag[1];
	arg2 = cos(YPitchAngle)*mag[0] + sin(XRollAngle)*sin(YPitchAngle)* mag[1] + cos(XRollAngle)*sin(YPitchAngle)*mag[2];
	ZYawAngle[0] = atan2(arg1,arg2);

	//ZYawAngle[0] += (5.0 + (16.0 / 60.0))*PI/180.0;//Positive declination
	if (ZYawAngle[0] < 0) {
		ZYawAngle[0] += 2*PI;
	} else if (ZYawAngle[0] > 2*PI) {
		ZYawAngle[0] -= 2*PI;
	}
	
	ZYawAngle[1] = -atan2(mag[1],mag[0]);
	if (ZYawAngle[1] < 0) {
		ZYawAngle[1] += 2*PI;
	} else if (ZYawAngle[1] > 2*PI) {
		ZYawAngle[1] -= 2*PI;
	}
}