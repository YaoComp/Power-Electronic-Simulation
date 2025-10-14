/*
 * File: rt_modf_snf.c
 *
 * Code generated for Simulink model 'Off_Grid_Inverter_Control_LC'.
 *
 * Model version                  : 1.122
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Mon Sep 29 17:15:02 2025
 */

#include "rt_modf_snf.h"
#include "rt_nonfinite.h"
#include <math.h>
#include <float.h>
#include <stdbool.h>

float rt_modf_snf(float u0, float u1)
{
  float q;
  float y;
  bool yEq;
  y = u0;
  if (u1 == 0.0F) {
    if (u0 == 0.0F) {
      y = u1;
    }
  } else if (rtIsNaNF(u0) || rtIsNaNF(u1) || rtIsInfF(u0)) {
    y = (rtNaNF);
  } else if (u0 == 0.0F) {
    y = 0.0F / u1;
  } else if (rtIsInfF(u1)) {
    if ((u1 < 0.0F) != (u0 < 0.0F)) {
      y = u1;
    }
  } else {
    y = (float)fmod((double)u0, (double)u1);
    yEq = (y == 0.0F);
    if (!yEq && (u1 > (float)floor((double)u1))) {
      q = (float)fabs((double)((float)(u0 / u1)));
      yEq = !((float)fabs((double)((float)(q - (float)floor((double)((float)(q +
        0.5F)))))) > (FLT_EPSILON * q));
    }

    if (yEq) {
      y = u1 * 0.0F;
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
