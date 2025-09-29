/*
 * File: PI_Controller.c
 *
 * Code generated for Simulink model 'Off_Grid_Inverter_Control_LC'.
 *
 * Model version                  : 1.123
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Mon Sep 29 17:31:54 2025
 */

#include "PI_Controller.h"
#include <stdbool.h>
#include "zero_crossing_types.h"

/*
 * System initialize for atomic system:
 *    'PI Controller' ('LibraryForCodeGeneration:135')
 *    'PI Controller' ('LibraryForCodeGeneration:135')
 *    'PI Controller' ('LibraryForCodeGeneration:135')
 *    'PI Controller' ('LibraryForCodeGeneration:135')
 *    'PI Controller' ('LibraryForCodeGeneration:135')
 *    'PI Controller' ('LibraryForCodeGeneration:135')
 *    'PI Controller' ('LibraryForCodeGeneration:135')
 *    'PI Controller' ('LibraryForCodeGeneration:135')
 */
void PI_Controller_Init(DW_PI_Controller_T *localDW)
{
  /* InitializeConditions for Delay: 'Delay' ('LibraryForCodeGeneration:244') */
  localDW->Delay_DSTATE = 0.0F;
}

/*
 * Output and update for atomic system:
 *    'PI Controller' ('LibraryForCodeGeneration:135')
 *    'PI Controller' ('LibraryForCodeGeneration:135')
 *    'PI Controller' ('LibraryForCodeGeneration:135')
 *    'PI Controller' ('LibraryForCodeGeneration:135')
 *    'PI Controller' ('LibraryForCodeGeneration:135')
 *    'PI Controller' ('LibraryForCodeGeneration:135')
 *    'PI Controller' ('LibraryForCodeGeneration:135')
 *    'PI Controller' ('LibraryForCodeGeneration:135')
 */
void PI_Controller(float rtu_Error, bool rtu_Reset, float *rty_Out, float rtp_Kp,
                   float rtp_Ts, float rtp_Max, float rtp_Min, float rtp_Ki,
                   DW_PI_Controller_T *localDW, ZCE_PI_Controller_T *localZCE)
{
  float rtb_Add2;
  float rtb_Delay;
  float rtb_Divide2_a;
  bool zcEvent;

  /* Product: 'Divide' ('LibraryForCodeGeneration:144') incorporates:
   *  Constant: 'Constant' ('LibraryForCodeGeneration:141')
   */
  rtb_Divide2_a = rtp_Kp * rtu_Error;

  /* Delay: 'Delay' ('LibraryForCodeGeneration:244') */
  zcEvent = (rtu_Reset && (localZCE->Delay_Reset_ZCE != (ZCSigState)POS_ZCSIG));
  if (zcEvent) {
    localDW->Delay_DSTATE = 0.0F;
  }

  localZCE->Delay_Reset_ZCE = rtu_Reset ? ((ZCSigState)1U) : ((ZCSigState)0U);
  rtb_Delay = localDW->Delay_DSTATE;

  /* End of Delay: 'Delay' ('LibraryForCodeGeneration:244') */

  /* Gain: 'Gain2' ('LibraryForCodeGeneration:245') */
  rtb_Add2 = rtp_Ts * rtb_Delay;

  /* Sum: 'Add' ('LibraryForCodeGeneration:138') */
  rtb_Divide2_a += rtb_Add2;

  /* Saturate: 'Saturation' ('LibraryForCodeGeneration:147') */
  if (rtb_Divide2_a > rtp_Max) {
    *rty_Out = rtp_Max;
  } else if (rtb_Divide2_a < rtp_Min) {
    *rty_Out = rtp_Min;
  } else {
    *rty_Out = rtb_Divide2_a;
  }

  /* End of Saturate: 'Saturation' ('LibraryForCodeGeneration:147') */

  /* Sum: 'Add1' ('LibraryForCodeGeneration:139') */
  rtb_Divide2_a = *rty_Out - rtb_Divide2_a;

  /* Product: 'Divide1' ('LibraryForCodeGeneration:145') incorporates:
   *  Constant: 'Constant1' ('LibraryForCodeGeneration:142')
   */
  rtb_Add2 = rtu_Error * rtp_Ki;

  /* Product: 'Divide2' ('LibraryForCodeGeneration:146') incorporates:
   *  Constant: 'Constant' ('LibraryForCodeGeneration:141')
   *  Constant: 'Constant1' ('LibraryForCodeGeneration:142')
   */
  rtb_Divide2_a = (rtb_Divide2_a * rtp_Ki) / rtp_Kp;

  /* Sum: 'Add2' ('LibraryForCodeGeneration:140') */
  rtb_Add2 += rtb_Divide2_a;

  /* Sum: 'Add3' ('LibraryForCodeGeneration:243') */
  rtb_Divide2_a = rtb_Add2 + rtb_Delay;

  /* Update for Delay: 'Delay' ('LibraryForCodeGeneration:244') */
  localDW->Delay_DSTATE = rtb_Divide2_a;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
