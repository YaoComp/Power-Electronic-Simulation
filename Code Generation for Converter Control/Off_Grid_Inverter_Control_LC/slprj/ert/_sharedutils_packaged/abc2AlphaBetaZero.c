/*
 * File: abc2AlphaBetaZero.c
 *
 * Code generated for Simulink model 'Off_Grid_Inverter_Control_LC'.
 *
 * Model version                  : 1.122
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Mon Sep 29 17:04:31 2025
 */

#include "rtwtypes.h"
#include "abc2AlphaBetaZero.h"

const real32_T rtCP_pooled9_76AloHRm[9] = { 1.0F, 0.0F, 0.5F, -0.5F,
  0.866025388F, 0.5F, -0.5F, -0.866025388F, 0.5F } ;

/*
 * Output and update for atomic system:
 *    'abc2&#x3B1;&#x3B2;0' ('Off_Grid_Inverter_Control_LC:2510:132')
 *    'abc2&#x3B1;&#x3B2;0' ('Off_Grid_Inverter_Control_LC:2545:132')
 *    'abc2&#x3B1;&#x3B2;0' ('Off_Grid_Inverter_Control_LC:2565:132')
 *    'abc2&#x3B1;&#x3B2;0' ('Off_Grid_Inverter_Control_LC:2529:83')
 *    'abc2&#x3B1;&#x3B2;0' ('Off_Grid_Inverter_Control_LC:2530:83')
 *    'abc2&#x3B1;&#x3B2;0' ('Off_Grid_Inverter_Control_LC:2560:83')
 *    'abc2&#x3B1;&#x3B2;0' ('Off_Grid_Inverter_Control_LC:2561:83')
 *    'abc2&#x3B1;&#x3B2;0' ('Off_Grid_Inverter_Control_LC:2571:83')
 *    'abc2&#x3B1;&#x3B2;0' ('Off_Grid_Inverter_Control_LC:2572:83')
 */
void abc2AlphaBetaZero(const real32_T rtu_abc[3], real32_T rty_u[3])
{
  real32_T rtu_abc_0;
  real32_T rtu_abc_1;
  real32_T rtu_abc_2;
  real32_T rty_u_0;
  int16_T i;

  /* Gain: 'Gain3' ('Off_Grid_Inverter_Control_LC:2510:132:54') */
  rtu_abc_0 = rtu_abc[0];
  rtu_abc_1 = rtu_abc[1];
  rtu_abc_2 = rtu_abc[2];
  for (i = 0; i < 3; i++) {
    rty_u_0 = rtCP_pooled9_76AloHRm[i] * rtu_abc_0;
    rty_u_0 += rtCP_pooled9_76AloHRm[i + 3] * rtu_abc_1;
    rty_u_0 += rtCP_pooled9_76AloHRm[i + 6] * rtu_abc_2;

    /* Gain: 'Gain1' ('Off_Grid_Inverter_Control_LC:2510:132:53') */
    rty_u_0 *= 0.666666687F;
    rty_u[i] = rty_u_0;
  }

  /* End of Gain: 'Gain3' ('Off_Grid_Inverter_Control_LC:2510:132:54') */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
