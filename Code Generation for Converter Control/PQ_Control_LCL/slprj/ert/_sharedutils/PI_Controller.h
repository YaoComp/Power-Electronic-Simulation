/*
 * File: PI_Controller.h
 *
 * Code generated for Simulink model 'Off_Grid_Inverter_Control_LC'.
 *
 * Model version                  : 1.122
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Mon Sep 29 17:15:02 2025
 */

#ifndef RTW_HEADER_PI_Controller_h_
#define RTW_HEADER_PI_Controller_h_
#include <stdbool.h>
#include "zero_crossing_types.h"

/* Block states (default storage) for system 'PI Controller1' ('Off_Grid_Inverter_Control_LC:2453') */
typedef struct {
  float Delay_DSTATE;/* 'Delay' ('Off_Grid_Inverter_Control_LC:2453:247:244') */
} DW_PI_Controller_T;

/* Zero-crossing (trigger) state for system 'PI Controller1' ('Off_Grid_Inverter_Control_LC:2453') */
typedef struct {
  ZCSigState Delay_Reset_ZCE;
                     /* 'Delay' ('Off_Grid_Inverter_Control_LC:2453:247:244') */
} ZCE_PI_Controller_T;

extern void PI_Controller_Init(DW_PI_Controller_T *localDW);
extern void PI_Controller(float rtu_Error, bool rtu_Reset, float *rty_Out, float
  rtp_Kp, float rtp_Ts, float rtp_Max, float rtp_Min, float rtp_Ki,
  DW_PI_Controller_T *localDW, ZCE_PI_Controller_T *localZCE);

#endif                                 /* RTW_HEADER_PI_Controller_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
