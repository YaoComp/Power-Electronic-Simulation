/*
 * File: AlphaBetaZero2abc.c
 *
 * Code generated for Simulink model 'Off_Grid_Inverter_Control_LC'.
 *
 * Model version                  : 1.122
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Mon Sep 29 17:15:02 2025
 */

#include "AlphaBetaZero2abc.h"
#include <stdint.h>

const float rtCP_pooled11_7JchAWrK[9] = { 1.0F, -0.5F, -0.5F, 0.0F, 0.866025388F,
  -0.866025388F, 1.0F, 1.0F, 1.0F } ;

/*
 * Output and update for atomic system:
 *    '&#x3B1;&#x3B2;02abc' ('Off_Grid_Inverter_Control_LC:2510:130')
 *    '&#x3B1;&#x3B2;02abc1' ('Off_Grid_Inverter_Control_LC:2510:131')
 *    '&#x3B1;&#x3B2;02abc' ('Off_Grid_Inverter_Control_LC:2545:130')
 *    '&#x3B1;&#x3B2;02abc1' ('Off_Grid_Inverter_Control_LC:2545:131')
 *    '&#x3B1;&#x3B2;02abc' ('Off_Grid_Inverter_Control_LC:2565:130')
 *    '&#x3B1;&#x3B2;02abc1' ('Off_Grid_Inverter_Control_LC:2565:131')
 *    '&#x3B1;&#x3B2;02abc' ('Off_Grid_Inverter_Control_LC:2521:123')
 *    '&#x3B1;&#x3B2;02abc' ('Off_Grid_Inverter_Control_LC:2522:123')
 */
void AlphaBetaZero2abc(float rtu_u, float rtu_u_j, float rtu_u_k, float rty_abc
  [3])
{
  float rty_abc_0;
  int16_t i;

  /* Gain: 'Gain3' ('Off_Grid_Inverter_Control_LC:2510:130:95') */
  for (i = 0; i < 3; i++) {
    rty_abc_0 = rtCP_pooled11_7JchAWrK[i] * rtu_u;
    rty_abc_0 += rtCP_pooled11_7JchAWrK[i + 3] * rtu_u_j;
    rty_abc_0 += rtCP_pooled11_7JchAWrK[i + 6] * rtu_u_k;
    rty_abc[i] = rty_abc_0;
  }

  /* End of Gain: 'Gain3' ('Off_Grid_Inverter_Control_LC:2510:130:95') */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
