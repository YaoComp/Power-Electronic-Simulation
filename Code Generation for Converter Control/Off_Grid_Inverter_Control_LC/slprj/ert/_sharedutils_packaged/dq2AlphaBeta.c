/*
 * File: dq2AlphaBeta.c
 *
 * Code generated for Simulink model 'Off_Grid_Inverter_Control_LC'.
 *
 * Model version                  : 1.122
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Mon Sep 29 17:04:31 2025
 */

#include "rtwtypes.h"
#include "dq2AlphaBeta.h"
#include <math.h>

/*
 * Output and update for atomic system:
 *    'dq2&#x3B1;&#x3B2;0' ('Off_Grid_Inverter_Control_LC:2521:122')
 *    'dq2&#x3B1;&#x3B2;0' ('Off_Grid_Inverter_Control_LC:2522:122')
 */
void dq2AlphaBeta(const real32_T rtu_dq[2], real32_T rtu_wt, real32_T *rty_u,
                  real32_T *rty_u_a)
{
  real32_T tmp;
  real32_T tmp_0;

  /* Fcn: 'Fcn' ('Off_Grid_Inverter_Control_LC:2521:122:101') incorporates:
   *  Fcn: 'Fcn1' ('Off_Grid_Inverter_Control_LC:2521:122:102')
   */
  tmp = (real32_T)sin((real_T)rtu_wt);
  tmp_0 = (real32_T)cos((real_T)rtu_wt);
  *rty_u = (rtu_dq[0] * tmp_0) - (rtu_dq[1] * tmp);

  /* Fcn: 'Fcn1' ('Off_Grid_Inverter_Control_LC:2521:122:102') */
  *rty_u_a = (rtu_dq[0] * tmp) + (rtu_dq[1] * tmp_0);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
