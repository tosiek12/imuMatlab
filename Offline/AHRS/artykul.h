#ifndef IMU_h
#define IMU_h

//----------------------------------------------------------------------------------------------------
// Variable declaration

extern float SEq_1, SEq_2, SEq_3, SEq_4; // estimated orientation quaternion elements

//---------------------------------------------------------------------------------------------------
// Function declaration

void filterUpdate(float w_x, float w_y, float w_z, float a_x, float a_y, float a_z);
void filterInit();
#endif
//=====================================================================================================
// End of file
//=====================================================================================================