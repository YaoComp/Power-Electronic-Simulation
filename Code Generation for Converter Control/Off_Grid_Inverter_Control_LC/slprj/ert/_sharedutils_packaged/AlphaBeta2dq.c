/*
 * File: AlphaBeta2dq.c
 *
 * Code generated for Simulink model 'Off_Grid_Inverter_Control_LC'.
 *
 * Model version                  : 1.122
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Mon Sep 29 17:04:31 2025
 */

#include "rtwtypes.h"
#include "AlphaBeta2dq.h"
#include <math.h>

/*
 * Output and update for atomic system:
 *    '&#x3B1;&#x3B2;2dq' ('Off_Grid_Inverter_Control_LC:2529:84')
 *    '&#x3B1;&#x3B2;2dq' ('Off_Grid_Inverter_Control_LC:2530:84')
 *    '&#x3B1;&#x3B2;2dq' ('Off_Grid_Inverter_Control_LC:2560:84')
 *    '&#x3B1;&#x3B2;2dq' ('Off_Grid_Inverter_Control_LC:2561:84')
 *    '&#x3B1;&#x3B2;2dq' ('Off_Grid_Inverter_Control_LC:2571:84')
 *    '&#x3B1;&#x3B2;2dq' ('Off_Grid_Inverter_Control_LC:2572:84')
 */
void AlphaBeta2dq(const real32_T rtu_u[2], real32_T rtu_wt, real32_T *rty_dq,
                  real32_T *rty_dq_h)
{
  real32_T tmp;
  real32_T tmp_0;

  /* Fcn: 'Fcn' ('Off_Grid_Inverter_Control_LC:2529:84:65') incorporates:
   *  Fcn: 'Fcn1' ('Off_Grid_Inverter_Control_LC:2529:84:66')
   */
  tmp = (real32_T)sin((real_T)rtu_wt);
  tmp_0 = (real32_T)cos((real_T)rtu_wt);
  *rty_dq = (rtu_u[0] * tmp_0) + (rtu_u[1] * tmp);

  /* Fcn: 'Fcn1' ('Off_Grid_Inverter_Control_LC:2529:84:66') */
  *rty_dq_h = (-rtu_u[0] * tmp) + (rtu_u[1] * tmp_0);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
