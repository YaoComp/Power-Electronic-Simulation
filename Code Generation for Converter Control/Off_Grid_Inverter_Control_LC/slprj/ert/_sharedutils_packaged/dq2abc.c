/*
 * File: dq2abc.c
 *
 * Code generated for Simulink model 'Off_Grid_Inverter_Control_LC'.
 *
 * Model version                  : 1.122
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Mon Sep 29 17:04:31 2025
 */

#include "rtwtypes.h"
#include "dq2abc.h"
#include "dq2AlphaBeta.h"
#include "AlphaBetaZero2abc.h"

/*
 * Output and update for atomic system:
 *    'dq2abc' ('Off_Grid_Inverter_Control_LC:2521')
 *    'dq2abc1' ('Off_Grid_Inverter_Control_LC:2522')
 */
void dq2abc(const real32_T rtu_dq[2], real32_T rtu_wt, real32_T rty_abc[3])
{
  real32_T rtb_Fcn;
  real32_T rtb_Fcn1;

  /* Outputs for Atomic SubSystem: 'dq2&#x3B1;&#x3B2;0' ('Off_Grid_Inverter_Control_LC:2521:122') */
  dq2AlphaBeta(rtu_dq, rtu_wt, &rtb_Fcn, &rtb_Fcn1);

  /* End of Outputs for SubSystem: 'dq2&#x3B1;&#x3B2;0' ('Off_Grid_Inverter_Control_LC:2521:122') */

  /* Outputs for Atomic SubSystem: '&#x3B1;&#x3B2;02abc' ('Off_Grid_Inverter_Control_LC:2521:123') */

  /* Constant: 'Constant' ('Off_Grid_Inverter_Control_LC:2521:133') */
  AlphaBetaZero2abc(rtb_Fcn, rtb_Fcn1, 0.0F, rty_abc);

  /* End of Outputs for SubSystem: '&#x3B1;&#x3B2;02abc' ('Off_Grid_Inverter_Control_LC:2521:123') */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
