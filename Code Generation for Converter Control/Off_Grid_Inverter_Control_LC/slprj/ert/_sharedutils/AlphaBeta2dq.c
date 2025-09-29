/*
 * File: AlphaBeta2dq.c
 *
 * Code generated for Simulink model 'Off_Grid_Inverter_Control_LC'.
 *
 * Model version                  : 1.123
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Mon Sep 29 17:31:54 2025
 */

#include "AlphaBeta2dq.h"
#include <math.h>

/*
 * Output and update for atomic system:
 *    '&#x3B1;&#x3B2;2dq' ('LibraryForCodeGeneration:78')
 *    '&#x3B1;&#x3B2;2dq' ('LibraryForCodeGeneration:78')
 *    '&#x3B1;&#x3B2;2dq' ('LibraryForCodeGeneration:78')
 *    '&#x3B1;&#x3B2;2dq' ('LibraryForCodeGeneration:78')
 *    '&#x3B1;&#x3B2;2dq' ('LibraryForCodeGeneration:78')
 *    '&#x3B1;&#x3B2;2dq' ('LibraryForCodeGeneration:78')
 */
void AlphaBeta2dq(const float rtu_u[2], float rtu_wt, float *rty_dq, float
                  *rty_dq_h)
{
  float tmp;
  float tmp_0;

  /* Fcn: 'Fcn' ('LibraryForCodeGeneration:65') incorporates:
   *  Fcn: 'Fcn1' ('LibraryForCodeGeneration:66')
   */
  tmp = (float)sin((double)rtu_wt);
  tmp_0 = (float)cos((double)rtu_wt);
  *rty_dq = (rtu_u[0] * tmp_0) + (rtu_u[1] * tmp);

  /* Fcn: 'Fcn1' ('LibraryForCodeGeneration:66') */
  *rty_dq_h = (-rtu_u[0] * tmp) + (rtu_u[1] * tmp_0);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
