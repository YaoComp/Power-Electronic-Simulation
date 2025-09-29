/*
 * File: Sequency_Separator.h
 *
 * Code generated for Simulink model 'Off_Grid_Inverter_Control_LC'.
 *
 * Model version                  : 1.122
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Mon Sep 29 17:04:31 2025
 */

#ifndef RTW_HEADER_Sequency_Separator_h_
#define RTW_HEADER_Sequency_Separator_h_
#include "rtwtypes.h"

/* Block states (default storage) for system 'Sequency_Separator1' ('Off_Grid_Inverter_Control_LC:2510') */
typedef struct {
  real32_T Delay1_DSTATE[160];
                         /* 'Delay1' ('Off_Grid_Inverter_Control_LC:2510:21') */
} DW_Sequency_Separator_T;

extern void Sequency_Separator(const real32_T rtu_Input_abc[3], real32_T
  rty_Outout_Positive[3], real32_T rty_Outout_negetive[3],
  DW_Sequency_Separator_T *localDW);

#endif                                 /* RTW_HEADER_Sequency_Separator_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
