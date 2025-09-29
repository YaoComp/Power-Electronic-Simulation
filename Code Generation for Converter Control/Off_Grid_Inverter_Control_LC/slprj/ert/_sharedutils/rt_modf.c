/*
 * File: rt_modf.c
 *
 * Code generated for Simulink model 'Off_Grid_Inverter_Control_LC'.
 *
 * Model version                  : 1.123
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Mon Sep 29 17:31:54 2025
 */

#include "rt_modf.h"
#include <math.h>
#include <float.h>
#include <stdbool.h>

float rt_modf(float u0, float u1)
{
  float q;
  float y;
  bool yEq;
  y = u0;
  if (u1 == 0.0F) {
    if (u0 == 0.0F) {
      y = u1;
    }
  } else if (u0 == 0.0F) {
    y = 0.0F / u1;
  } else {
    y = (float)fmod((double)u0, (double)u1);
    yEq = (y == 0.0F);
    if (!yEq && (u1 > (float)floor((double)u1))) {
      q = (float)fabs((double)((float)(u0 / u1)));
      yEq = ((float)fabs((double)((float)(q - (float)floor((double)((float)(q +
        0.5F)))))) <= (FLT_EPSILON * q));
    }

    if (yEq) {
      y = 0.0F;
    } else if ((u0 < 0.0F) != (u1 < 0.0F)) {
      y += u1;
    } else {
      /* no actions */
    }
  }

  return y;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
