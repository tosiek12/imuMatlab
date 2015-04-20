#ifndef ANGLES_H_ 
#define ANGLES_H_ 
#include "typedef.h"
#include <math.h>

//#define PI (float) 3.14
#define PI 3.14159265358979 

float32_t XRollAngle;
float32_t YPitchAngle;
float32_t YPitchAngle2;
float32_t TiltAngle;
float32_t ZYawAngle[2];

void computeAngles();

#endif