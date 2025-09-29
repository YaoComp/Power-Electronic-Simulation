/*
 * File: Sequency_Separator.c
 *
 * Code generated for Simulink model 'Off_Grid_Inverter_Control_LC'.
 *
 * Model version                  : 1.123
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Mon Sep 29 17:31:54 2025
 */

#include "Sequency_Separator.h"
#include "abc2AlphaBetaZero.h"
#include "AlphaBetaZero2abc.h"
#include <stdint.h>

/*
 * Output and update for atomic system:
 *    'Sequency_Separator' ('LibraryForCodeGeneration:13')
 *    'Sequency_Separator' ('LibraryForCodeGeneration:13')
 *    'Sequency_Separator' ('LibraryForCodeGeneration:13')
 */
void Sequency_Separator(const float rtu_Input_abc[3], float rty_Outout_Positive
  [3], float rty_Outout_negetive[3], DW_Sequency_Separator_T *localDW)
{
  float rtb_Gain1[3];
  float rtb_Gain1_k[3];
  float rtb_Add1;
  float rtb_Add2;
  float rtb_Add3_b;
  float rtb_Add4;
  float rtb_Delay1_idx_0;
  float rtb_Delay1_idx_1;
  int16_t Delay1_DSTATE_tmp;
  int16_t idxDelay;

  /* Gain: 'Gain1' ('LibraryForCodeGeneration:24') */
  rtb_Gain1[0] = 0.5F * rtu_Input_abc[0];
  rtb_Gain1[1] = 0.5F * rtu_Input_abc[1];
  rtb_Gain1[2] = 0.5F * rtu_Input_abc[2];

  /* Outputs for Atomic SubSystem: 'abc2&#x3B1;&#x3B2;0' ('LibraryForCodeGeneration:56') */
  abc2AlphaBetaZero(rtb_Gain1, rtb_Gain1_k);

  /* End of Outputs for SubSystem: 'abc2&#x3B1;&#x3B2;0' ('LibraryForCodeGeneration:56') */

  /* Delay: 'Delay1' ('LibraryForCodeGeneration:21') */
  rtb_Delay1_idx_0 = localDW->Delay1_DSTATE[0];
  rtb_Delay1_idx_1 = localDW->Delay1_DSTATE[1];

  /* Sum: 'Add1' ('LibraryForCodeGeneration:15') */
  rtb_Add1 = rtb_Gain1_k[0] - rtb_Delay1_idx_1;

  /* Sum: 'Add2' ('LibraryForCodeGeneration:16') */
  rtb_Add2 = rtb_Delay1_idx_0 + rtb_Gain1_k[1];

  /* Sum: 'Add3' ('LibraryForCodeGeneration:17') */
  rtb_Add3_b = rtb_Gain1_k[0] + rtb_Delay1_idx_1;

  /* Sum: 'Add4' ('LibraryForCodeGeneration:18') */
  rtb_Add4 = rtb_Gain1_k[1] - rtb_Delay1_idx_0;

  /* Outputs for Atomic SubSystem: '&#x3B1;&#x3B2;02abc' ('LibraryForCodeGeneration:96') */
  /* Constant: 'Zero' ('LibraryForCodeGeneration:28') */
  AlphaBetaZero2abc(rtb_Add1, rtb_Add2, 0.0F, rty_Outout_Positive);

  /* End of Outputs for SubSystem: '&#x3B1;&#x3B2;02abc' ('LibraryForCodeGeneration:96') */

  /* Outputs for Atomic SubSystem: '&#x3B1;&#x3B2;02abc' ('LibraryForCodeGeneration:96') */
  AlphaBetaZero2abc(rtb_Add3_b, rtb_Add4, 0.0F, rty_Outout_negetive);

  /* End of Outputs for SubSystem: '&#x3B1;&#x3B2;02abc' ('LibraryForCodeGeneration:96') */

  /* Update for Delay: 'Delay1' ('LibraryForCodeGeneration:21') */
  for (idxDelay = 0; idxDelay < 79; idxDelay++) {
    Delay1_DSTATE_tmp = (idxDelay + 1) * 2;
    localDW->Delay1_DSTATE[idxDelay * 2] = localDW->
      Delay1_DSTATE[Delay1_DSTATE_tmp];
    localDW->Delay1_DSTATE[(idxDelay * 2) + 1] = localDW->
      Delay1_DSTATE[Delay1_DSTATE_tmp + 1];
  }

  localDW->Delay1_DSTATE[158] = rtb_Gain1_k[0];
  localDW->Delay1_DSTATE[159] = rtb_Gain1_k[1];

  /* End of Update for Delay: 'Delay1' ('LibraryForCodeGeneration:21') */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
