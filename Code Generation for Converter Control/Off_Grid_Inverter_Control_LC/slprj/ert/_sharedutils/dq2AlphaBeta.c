/*
 * File: dq2AlphaBeta.c
 *
 * Code generated for Simulink model 'Off_Grid_Inverter_Control_LC'.
 *
 * Model version                  : 1.123
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Mon Sep 29 17:31:54 2025
 */

#include "dq2AlphaBeta.h"
#include <math.h>

/*
 * Output and update for atomic system:
 *    'dq2&#x3B1;&#x3B2;' ('LibraryForCodeGeneration:117')
 *    'dq2&#x3B1;&#x3B2;' ('LibraryForCodeGeneration:117')
 */
void dq2AlphaBeta(const float rtu_dq[2], float rtu_wt, float *rty_u, float
                  *rty_u_a)
{
  float tmp;
  float tmp_0;

  /* Fcn: 'Fcn' ('LibraryForCodeGeneration:101') incorporates:
   *  Fcn: 'Fcn1' ('LibraryForCodeGeneration:102')
   */
  tmp = (float)sin((double)rtu_wt);
  tmp_0 = (float)cos((double)rtu_wt);
  *rty_u = (rtu_dq[0] * tmp_0) - (rtu_dq[1] * tmp);

  /* Fcn: 'Fcn1' ('LibraryForCodeGeneration:102') */
  *rty_u_a = (rtu_dq[0] * tmp) + (rtu_dq[1] * tmp_0);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
