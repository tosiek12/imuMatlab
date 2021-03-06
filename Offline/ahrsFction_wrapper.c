/*
  *
  *   --- THIS FILE GENERATED BY S-FUNCTION BUILDER: 3.0 ---
  *
  *   This file is a wrapper S-function produced by the S-Function
  *   Builder which only recognizes certain fields.  Changes made
  *   outside these fields will be lost the next time the block is
  *   used to load, edit, and resave this file. This file will be overwritten
  *   by the S-function Builder block. If you want to edit this file by hand, 
  *   you must change it only in the area defined as:  
  *
  *        %%%-SFUNWIZ_wrapper_XXXXX_Changes_BEGIN 
  *            Your Changes go here
  *        %%%-SFUNWIZ_wrapper_XXXXXX_Changes_END
  *
  *   For better compatibility with the Simulink Coder, the
  *   "wrapper" S-function technique is used.  This is discussed
  *   in the Simulink Coder User's Manual in the Chapter titled,
  *   "Wrapper S-functions".
  *
  *   Created: Sun Dec  7 12:08:13 2014
  */


/*
 * Include Files
 *
 */
#if defined(MATLAB_MEX_FILE)
#include "tmwtypes.h"
#include "simstruc_types.h"
#else
#include "rtwtypes.h"
#endif

/* %%%-SFUNWIZ_wrapper_includes_Changes_BEGIN --- EDIT HERE TO _END */
#include <math.h>
#include <AHRS/MahonyAHRS.h>
#include <AHRS/MadgwickAHRS.h>
#include <AHRS/artykul.h>
//#include <Matlab_Ccode/AngleConvertion.h>
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define u_width 3
#define y_width 1
/*
 * Create external references here.  
 *
 */
/* %%%-SFUNWIZ_wrapper_externs_Changes_BEGIN --- EDIT HERE TO _END */
/* extern double func(double a); */
/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */

/*
 * Output functions
 *
 */
void ahrsFction_Outputs_wrapper(const real32_T *accIn,
                          const real32_T *gyroIn,
                          const real32_T *magIn,
                          const real32_T *Kp,
                          const real32_T *Ki,
                          real32_T *quat,
                          const real_T  *xD)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
// //Madgwick
// if(xD[0] == 0) {
//     q0 = 1;
//     q1 = 0;
//     q2 = 0;
//     q3 = 0;
// } else {
//     MadgwickAHRSupdate(gyroIn[0],gyroIn[1],gyroIn[2],accIn[0],accIn[1],accIn[2],magIn[0],magIn[1],magIn[2]);
// //     MadgwickAHRSupdateIMU(gyroIn[0],gyroIn[1],gyroIn[2],accIn[0],accIn[1],accIn[2]);
// }
// quat[0] = q0;
// quat[1] = q1;
// quat[2] = q2;
// quat[3] = q3;

// Mahony
if(xD[0] == 0) {
    q0 = 1;
    q1 = 0;
    q2 = 0;
    q3 = 0;
    twoKp = 2*Kp[0];
    twoKi = 2*Ki[0];
} else {
    MahonyAHRSupdate(gyroIn[0],gyroIn[1],gyroIn[2],accIn[0],accIn[1],accIn[2],magIn[0],magIn[1],magIn[2]);
//     MahonyAHRSupdateIMU(gyroIn[0],gyroIn[1],gyroIn[2],accIn[0],accIn[1],accIn[2]);
}
quat[0] = q0;
quat[1] = q1;
quat[2] = q2;
quat[3] = q3;

// //algorytm
// if(xD[0] == 0) {
//     filterInit();
// } else {
//     filterUpdate(gyroIn[0],gyroIn[1],gyroIn[2],accIn[0],accIn[1],accIn[2]);
//     quat[0] = SEq_1;
//     quat[1] = SEq_2;
//     quat[2] = SEq_3;
//     quat[3] = SEq_4;
// }
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}

/*
  * Updates function
  *
  */
void ahrsFction_Update_wrapper(const real32_T *accIn,
                          const real32_T *gyroIn,
                          const real32_T *magIn,
                          const real32_T *Kp,
                          const real32_T *Ki,
                          const real32_T *quat,
                          real_T *xD)
{
  /* %%%-SFUNWIZ_wrapper_Update_Changes_BEGIN --- EDIT HERE TO _END */
//isInitDone
if(xD[0] != 1) {
    xD[0] = 1;
}
/* %%%-SFUNWIZ_wrapper_Update_Changes_END --- EDIT HERE TO _BEGIN */
}
