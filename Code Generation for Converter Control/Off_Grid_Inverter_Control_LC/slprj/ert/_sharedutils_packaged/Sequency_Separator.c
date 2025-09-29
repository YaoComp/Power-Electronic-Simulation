/*
 * File: Sequency_Separator.c
 *
 * Code generated for Simulink model 'Off_Grid_Inverter_Control_LC'.
 *
 * Model version                  : 1.122
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Mon Sep 29 17:04:31 2025
 */

#include "rtwtypes.h"
#include "Sequency_Separator.h"
#include "abc2AlphaBetaZero.h"
#include "AlphaBetaZero2abc.h"

/*
 * Output and update for atomic system:
 *    'Sequency_Separator1' ('Off_Grid_Inverter_Control_LC:2510')
 *    'Sequency_Separator2' ('Off_Grid_Inverter_Control_LC:2545')
 *    'Sequency_Separator3' ('Off_Grid_Inverter_Control_LC:2565')
 */
void Sequency_Separator(const real32_T rtu_Input_abc[3], real32_T
  rty_Outout_Positive[3], real32_T rty_Outout_negetive[3],
  DW_Sequency_Separator_T *localDW)
{
  real32_T rtb_Gain1[3];
  real32_T rtb_Gain1_k[3];
  real32_T rtb_Add1;
  real32_T rtb_Add2;
  real32_T rtb_Add3_b;
  real32_T rtb_Add4;
  real32_T rtb_Delay1_idx_0;
  real32_T rtb_Delay1_idx_1;
  int16_T Delay1_DSTATE_tmp;
  int16_T idxDelay;

  /* Gain: 'Gain1' ('Off_Grid_Inverter_Control_LC:2510:24') */
  rtb_Gain1[0] = 0.5F * rtu_Input_abc[0];
  rtb_Gain1[1] = 0.5F * rtu_Input_abc[1];
  rtb_Gain1[2] = 0.5F * rtu_Input_abc[2];

  /* Outputs for Atomic SubSystem: 'abc2&#x3B1;&#x3B2;0' ('Off_Grid_Inverter_Control_LC:2510:132') */
  abc2AlphaBetaZero(rtb_Gain1, rtb_Gain1_k);

  /* End of Outputs for SubSystem: 'abc2&#x3B1;&#x3B2;0' ('Off_Grid_Inverter_Control_LC:2510:132') */

  /* Delay: 'Delay1' ('Off_Grid_Inverter_Control_LC:2510:21') */
  rtb_Delay1_idx_0 = localDW->Delay1_DSTATE[0];
  rtb_Delay1_idx_1 = localDW->Delay1_DSTATE[1];

  /* Sum: 'Add1' ('Off_Grid_Inverter_Control_LC:2510:15') */
  rtb_Add1 = rtb_Gain1_k[0] - rtb_Delay1_idx_1;

  /* Sum: 'Add2' ('Off_Grid_Inverter_Control_LC:2510:16') */
  rtb_Add2 = rtb_Delay1_idx_0 + rtb_Gain1_k[1];

  /* Sum: 'Add3' ('Off_Grid_Inverter_Control_LC:2510:17') */
  rtb_Add3_b = rtb_Gain1_k[0] + rtb_Delay1_idx_1;

  /* Sum: 'Add4' ('Off_Grid_Inverter_Control_LC:2510:18') */
  rtb_Add4 = rtb_Gain1_k[1] - rtb_Delay1_idx_0;

  /* Outputs for Atomic SubSystem: '&#x3B1;&#x3B2;02abc' ('Off_Grid_Inverter_Control_LC:2510:130') */
  /* Constant: 'Zero' ('Off_Grid_Inverter_Control_LC:2510:28') */
  AlphaBetaZero2abc(rtb_Add1, rtb_Add2, 0.0F, rty_Outout_Positive);

  /* End of Outputs for SubSystem: '&#x3B1;&#x3B2;02abc' ('Off_Grid_Inverter_Control_LC:2510:130') */

  /* Outputs for Atomic SubSystem: '&#x3B1;&#x3B2;02abc1' ('Off_Grid_Inverter_Control_LC:2510:131') */
  AlphaBetaZero2abc(rtb_Add3_b, rtb_Add4, 0.0F, rty_Outout_negetive);

  /* End of Outputs for SubSystem: '&#x3B1;&#x3B2;02abc1' ('Off_Grid_Inverter_Control_LC:2510:131') */

  /* Update for Delay: 'Delay1' ('Off_Grid_Inverter_Control_LC:2510:21') */
  for (idxDelay = 0; idxDelay < 79; idxDelay++) {
    Delay1_DSTATE_tmp = (idxDelay + 1) * 2;
    localDW->Delay1_DSTATE[idxDelay * 2] = localDW->
      Delay1_DSTATE[Delay1_DSTATE_tmp];
    localDW->Delay1_DSTATE[(idxDelay * 2) + 1] = localDW->
      Delay1_DSTATE[Delay1_DSTATE_tmp + 1];
  }

  localDW->Delay1_DSTATE[158] = rtb_Gain1_k[0];
  localDW->Delay1_DSTATE[159] = rtb_Gain1_k[1];

  /* End of Update for Delay: 'Delay1' ('Off_Grid_Inverter_Control_LC:2510:21') */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
