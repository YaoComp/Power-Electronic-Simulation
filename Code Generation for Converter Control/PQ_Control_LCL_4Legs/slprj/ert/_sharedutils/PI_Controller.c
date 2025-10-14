/*
 * File: PI_Controller.c
 *
 * Code generated for Simulink model 'Off_Grid_Inverter_Control_LC'.
 *
 * Model version                  : 1.122
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Mon Sep 29 17:15:02 2025
 */

#include "PI_Controller.h"
#include <stdbool.h>
#include "zero_crossing_types.h"

/*
 * System initialize for atomic system:
 *    'PI Controller1' ('Off_Grid_Inverter_Control_LC:2453')
 *    'PI Controller2' ('Off_Grid_Inverter_Control_LC:2454')
 *    'PI Controller' ('Off_Grid_Inverter_Control_LC:2647')
 *    'PI Controller1' ('Off_Grid_Inverter_Control_LC:2648')
 *    'PI Controller' ('Off_Grid_Inverter_Control_LC:2503')
 *    'PI Controller1' ('Off_Grid_Inverter_Control_LC:2504')
 *    'PI Controller' ('Off_Grid_Inverter_Control_LC:2607')
 *    'PI Controller1' ('Off_Grid_Inverter_Control_LC:2608')
 */
void PI_Controller_Init(DW_PI_Controller_T *localDW)
{
  /* InitializeConditions for Delay: 'Delay' ('Off_Grid_Inverter_Control_LC:2453:247:244') */
  localDW->Delay_DSTATE = 0.0F;
}

/*
 * Output and update for atomic system:
 *    'PI Controller1' ('Off_Grid_Inverter_Control_LC:2453')
 *    'PI Controller2' ('Off_Grid_Inverter_Control_LC:2454')
 *    'PI Controller' ('Off_Grid_Inverter_Control_LC:2647')
 *    'PI Controller1' ('Off_Grid_Inverter_Control_LC:2648')
 *    'PI Controller' ('Off_Grid_Inverter_Control_LC:2503')
 *    'PI Controller1' ('Off_Grid_Inverter_Control_LC:2504')
 *    'PI Controller' ('Off_Grid_Inverter_Control_LC:2607')
 *    'PI Controller1' ('Off_Grid_Inverter_Control_LC:2608')
 */
void PI_Controller(float rtu_Error, bool rtu_Reset, float *rty_Out, float rtp_Kp,
                   float rtp_Ts, float rtp_Max, float rtp_Min, float rtp_Ki,
                   DW_PI_Controller_T *localDW, ZCE_PI_Controller_T *localZCE)
{
  float rtb_Add2;
  float rtb_Delay;
  float rtb_Divide2_b;
  bool zcEvent;

  /* Product: 'Divide' ('Off_Grid_Inverter_Control_LC:2453:144') incorporates:
   *  Constant: 'Constant' ('Off_Grid_Inverter_Control_LC:2453:141')
   */
  rtb_Divide2_b = rtp_Kp * rtu_Error;

  /* Delay: 'Delay' ('Off_Grid_Inverter_Control_LC:2453:247:244') */
  zcEvent = (rtu_Reset && (localZCE->Delay_Reset_ZCE != (ZCSigState)POS_ZCSIG));
  if (zcEvent) {
    localDW->Delay_DSTATE = 0.0F;
  }

  localZCE->Delay_Reset_ZCE = rtu_Reset ? ((ZCSigState)1U) : ((ZCSigState)0U);
  rtb_Delay = localDW->Delay_DSTATE;

  /* End of Delay: 'Delay' ('Off_Grid_Inverter_Control_LC:2453:247:244') */

  /* Gain: 'Gain2' ('Off_Grid_Inverter_Control_LC:2453:247:245') */
  rtb_Add2 = rtp_Ts * rtb_Delay;

  /* Sum: 'Add' ('Off_Grid_Inverter_Control_LC:2453:138') */
  rtb_Divide2_b += rtb_Add2;

  /* Saturate: 'Saturation' ('Off_Grid_Inverter_Control_LC:2453:147') */
  if (rtb_Divide2_b > rtp_Max) {
    *rty_Out = rtp_Max;
  } else if (rtb_Divide2_b < rtp_Min) {
    *rty_Out = rtp_Min;
  } else {
    *rty_Out = rtb_Divide2_b;
  }

  /* End of Saturate: 'Saturation' ('Off_Grid_Inverter_Control_LC:2453:147') */

  /* Sum: 'Add1' ('Off_Grid_Inverter_Control_LC:2453:139') */
  rtb_Divide2_b = *rty_Out - rtb_Divide2_b;

  /* Product: 'Divide1' ('Off_Grid_Inverter_Control_LC:2453:145') incorporates:
   *  Constant: 'Constant1' ('Off_Grid_Inverter_Control_LC:2453:142')
   */
  rtb_Add2 = rtu_Error * rtp_Ki;

  /* Product: 'Divide2' ('Off_Grid_Inverter_Control_LC:2453:146') incorporates:
   *  Constant: 'Constant' ('Off_Grid_Inverter_Control_LC:2453:141')
   *  Constant: 'Constant1' ('Off_Grid_Inverter_Control_LC:2453:142')
   */
  rtb_Divide2_b = (rtb_Divide2_b * rtp_Ki) / rtp_Kp;

  /* Sum: 'Add2' ('Off_Grid_Inverter_Control_LC:2453:140') */
  rtb_Add2 += rtb_Divide2_b;

  /* Sum: 'Add3' ('Off_Grid_Inverter_Control_LC:2453:247:243') */
  rtb_Divide2_b = rtb_Add2 + rtb_Delay;

  /* Update for Delay: 'Delay' ('Off_Grid_Inverter_Control_LC:2453:247:244') */
  localDW->Delay_DSTATE = rtb_Divide2_b;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
