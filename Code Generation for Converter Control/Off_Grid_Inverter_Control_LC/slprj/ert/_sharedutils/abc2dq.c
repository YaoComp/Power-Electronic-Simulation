/*
 * File: abc2dq.c
 *
 * Code generated for Simulink model 'Off_Grid_Inverter_Control_LC'.
 *
 * Model version                  : 1.123
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Mon Sep 29 17:31:54 2025
 */

#include "abc2dq.h"
#include "abc2AlphaBetaZero.h"
#include "AlphaBeta2dq.h"

/*
 * Output and update for atomic system:
 *    'abc2dq' ('LibraryForCodeGeneration:86')
 *    'abc2dq' ('LibraryForCodeGeneration:86')
 *    'abc2dq' ('LibraryForCodeGeneration:86')
 *    'abc2dq' ('LibraryForCodeGeneration:86')
 *    'abc2dq' ('LibraryForCodeGeneration:86')
 *    'abc2dq' ('LibraryForCodeGeneration:86')
 */
void abc2dq(const float rtu_abc[3], float rtu_wt, float rty_dq[2])
{
  float rtb_Gain1[3];
  float rtb_Fcn;
  float rtb_Fcn1;

  /* Outputs for Atomic SubSystem: 'abc2&#x3B1;&#x3B2;0' ('LibraryForCodeGeneration:56') */
  abc2AlphaBetaZero(rtu_abc, rtb_Gain1);

  /* End of Outputs for SubSystem: 'abc2&#x3B1;&#x3B2;0' ('LibraryForCodeGeneration:56') */

  /* Outputs for Atomic SubSystem: '&#x3B1;&#x3B2;2dq' ('LibraryForCodeGeneration:78') */

  /* Gain: 'Gain1' ('LibraryForCodeGeneration:53') */
  AlphaBeta2dq(&rtb_Gain1[0], rtu_wt, &rtb_Fcn, &rtb_Fcn1);

  /* End of Outputs for SubSystem: '&#x3B1;&#x3B2;2dq' ('LibraryForCodeGeneration:78') */

  /* SignalConversion: 'Signal Conversion' ('LibraryForCodeGeneration:134') */
  rty_dq[0] = rtb_Fcn;
  rty_dq[1] = rtb_Fcn1;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
