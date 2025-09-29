/*
 * File: dq2abc.c
 *
 * Code generated for Simulink model 'Off_Grid_Inverter_Control_LC'.
 *
 * Model version                  : 1.123
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Mon Sep 29 17:31:54 2025
 */

#include "dq2abc.h"
#include "dq2AlphaBeta.h"
#include "AlphaBetaZero2abc.h"

/*
 * Output and update for atomic system:
 *    'dq2abc' ('LibraryForCodeGeneration:125')
 *    'dq2abc' ('LibraryForCodeGeneration:125')
 */
void dq2abc(const float rtu_dq[2], float rtu_wt, float rty_abc[3])
{
  float rtb_Fcn;
  float rtb_Fcn1;

  /* Outputs for Atomic SubSystem: 'dq2&#x3B1;&#x3B2;' ('LibraryForCodeGeneration:117') */
  dq2AlphaBeta(rtu_dq, rtu_wt, &rtb_Fcn, &rtb_Fcn1);

  /* End of Outputs for SubSystem: 'dq2&#x3B1;&#x3B2;' ('LibraryForCodeGeneration:117') */

  /* Outputs for Atomic SubSystem: '&#x3B1;&#x3B2;02abc' ('LibraryForCodeGeneration:96') */

  /* Constant: 'Constant' ('LibraryForCodeGeneration:133') */
  AlphaBetaZero2abc(rtb_Fcn, rtb_Fcn1, 0.0F, rty_abc);

  /* End of Outputs for SubSystem: '&#x3B1;&#x3B2;02abc' ('LibraryForCodeGeneration:96') */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
