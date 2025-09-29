/*
 * File: abc2AlphaBetaZero.c
 *
 * Code generated for Simulink model 'Off_Grid_Inverter_Control_LC'.
 *
 * Model version                  : 1.123
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Mon Sep 29 17:31:54 2025
 */

#include "abc2AlphaBetaZero.h"
#include <stdint.h>

const float rtCP_pooled9_0vf7yJRn[9] = { 1.0F, 0.0F, 0.5F, -0.5F, 0.866025388F,
  0.5F, -0.5F, -0.866025388F, 0.5F } ;

/*
 * Output and update for atomic system:
 *    'abc2&#x3B1;&#x3B2;0' ('LibraryForCodeGeneration:56')
 *    'abc2&#x3B1;&#x3B2;0' ('LibraryForCodeGeneration:56')
 *    'abc2&#x3B1;&#x3B2;0' ('LibraryForCodeGeneration:56')
 *    'abc2&#x3B1;&#x3B2;0' ('LibraryForCodeGeneration:56')
 *    'abc2&#x3B1;&#x3B2;0' ('LibraryForCodeGeneration:56')
 *    'abc2&#x3B1;&#x3B2;0' ('LibraryForCodeGeneration:56')
 *    'abc2&#x3B1;&#x3B2;0' ('LibraryForCodeGeneration:56')
 *    'abc2&#x3B1;&#x3B2;0' ('LibraryForCodeGeneration:56')
 *    'abc2&#x3B1;&#x3B2;0' ('LibraryForCodeGeneration:56')
 */
void abc2AlphaBetaZero(const float rtu_abc[3], float rty_u[3])
{
  float rtu_abc_0;
  float rtu_abc_1;
  float rtu_abc_2;
  float rty_u_0;
  int16_t i;

  /* Gain: 'Gain3' ('LibraryForCodeGeneration:54') */
  rtu_abc_0 = rtu_abc[0];
  rtu_abc_1 = rtu_abc[1];
  rtu_abc_2 = rtu_abc[2];
  for (i = 0; i < 3; i++) {
    rty_u_0 = rtCP_pooled9_0vf7yJRn[i] * rtu_abc_0;
    rty_u_0 += rtCP_pooled9_0vf7yJRn[i + 3] * rtu_abc_1;
    rty_u_0 += rtCP_pooled9_0vf7yJRn[i + 6] * rtu_abc_2;

    /* Gain: 'Gain1' ('LibraryForCodeGeneration:53') */
    rty_u_0 *= 0.666666687F;
    rty_u[i] = rty_u_0;
  }

  /* End of Gain: 'Gain3' ('LibraryForCodeGeneration:54') */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
