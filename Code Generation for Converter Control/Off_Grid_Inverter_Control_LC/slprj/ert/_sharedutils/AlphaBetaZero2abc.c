/*
 * File: AlphaBetaZero2abc.c
 *
 * Code generated for Simulink model 'Off_Grid_Inverter_Control_LC'.
 *
 * Model version                  : 1.123
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Mon Sep 29 17:31:54 2025
 */

#include "AlphaBetaZero2abc.h"
#include <stdint.h>

const float rtCP_pooled11_Phv5irWG[9] = { 1.0F, -0.5F, -0.5F, 0.0F, 0.866025388F,
  -0.866025388F, 1.0F, 1.0F, 1.0F } ;

/*
 * Output and update for atomic system:
 *    '&#x3B1;&#x3B2;02abc' ('LibraryForCodeGeneration:96')
 *    '&#x3B1;&#x3B2;02abc' ('LibraryForCodeGeneration:96')
 *    '&#x3B1;&#x3B2;02abc' ('LibraryForCodeGeneration:96')
 *    '&#x3B1;&#x3B2;02abc' ('LibraryForCodeGeneration:96')
 *    '&#x3B1;&#x3B2;02abc' ('LibraryForCodeGeneration:96')
 *    '&#x3B1;&#x3B2;02abc' ('LibraryForCodeGeneration:96')
 *    '&#x3B1;&#x3B2;02abc' ('LibraryForCodeGeneration:96')
 *    '&#x3B1;&#x3B2;02abc' ('LibraryForCodeGeneration:96')
 */
void AlphaBetaZero2abc(float rtu_u, float rtu_u_j, float rtu_u_k, float rty_abc
  [3])
{
  float rty_abc_0;
  int16_t i;

  /* Gain: 'Gain3' ('LibraryForCodeGeneration:95') */
  for (i = 0; i < 3; i++) {
    rty_abc_0 = rtCP_pooled11_Phv5irWG[i] * rtu_u;
    rty_abc_0 += rtCP_pooled11_Phv5irWG[i + 3] * rtu_u_j;
    rty_abc_0 += rtCP_pooled11_Phv5irWG[i + 6] * rtu_u_k;
    rty_abc[i] = rty_abc_0;
  }

  /* End of Gain: 'Gain3' ('LibraryForCodeGeneration:95') */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
