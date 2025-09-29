/*
 * File: Off_Grid_Inverter_Control_LC.c
 *
 * Code generated for Simulink model 'Off_Grid_Inverter_Control_LC'.
 *
 * Model version                  : 1.123
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Mon Sep 29 17:45:21 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives:
 *    1. MISRA C:2012 guidelines
 *    2. Safety precaution
 *    3. Traceability
 * Validation result: Not run
 */

#include "Off_Grid_Inverter_Control_LC.h"
#include <stdbool.h>
#include "Off_Grid_Inverter_Control_LC_private.h"
#include <stdint.h>
#include <math.h>
#include "zero_crossing_types.h"
#include <float.h>

/* Block signals (default storage) */
B_Off_Grid_Inverter_Control_L_T Off_Grid_Inverter_Control_LC_B;

/* Block states (default storage) */
DW_Off_Grid_Inverter_Control__T Off_Grid_Inverter_Control_LC_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_Off_Grid_Inverter_Con_T Off_Grid_Inverter_Contr_PrevZCX;

/* Real-time model */
static RT_MODEL_Off_Grid_Inverter_Co_T Off_Grid_Inverter_Control_LC_M_;
RT_MODEL_Off_Grid_Inverter_Co_T *const Off_Grid_Inverter_Control_LC_M =
  &Off_Grid_Inverter_Control_LC_M_;

/*
 * System initialize for atomic system:
 *    '<S1>/PI Controller1'
 *    '<S1>/PI Controller2'
 *    '<S2>/PI Controller'
 *    '<S2>/PI Controller1'
 *    '<S3>/PI Controller'
 *    '<S3>/PI Controller1'
 *    '<S4>/PI Controller'
 *    '<S4>/PI Controller1'
 */
void PI_Controller_Init(DW_PI_Controller_T *localDW)
{
  /* InitializeConditions for Delay: '<S14>/Delay' */
  localDW->Delay_DSTATE = rtCP_pooled8;
}

/*
 * Output and update for atomic system:
 *    '<S1>/PI Controller1'
 *    '<S1>/PI Controller2'
 *    '<S2>/PI Controller'
 *    '<S2>/PI Controller1'
 *    '<S3>/PI Controller'
 *    '<S3>/PI Controller1'
 *    '<S4>/PI Controller'
 *    '<S4>/PI Controller1'
 */
float PI_Controller(float rtu_Error, bool rtu_Reset, float rtp_Kp, float rtp_Ts,
                    float rtp_Max, float rtp_Min, float rtp_Ki,
                    DW_PI_Controller_T *localDW, ZCE_PI_Controller_T *localZCE)
{
  float rty_Out_0;
  float rtb_Add2;
  float rtb_Delay;
  float rtb_Divide2_a;
  bool zcEvent;

  /* Product: '<S12>/Divide' incorporates:
   *  Constant: '<S12>/Constant'
   */
  rtb_Divide2_a = rtp_Kp * rtu_Error;

  /* Delay: '<S14>/Delay' */
  zcEvent = (rtu_Reset && (localZCE->Delay_Reset_ZCE != (ZCSigState)POS_ZCSIG));
  if (zcEvent) {
    localDW->Delay_DSTATE = rtCP_pooled8;
  }

  localZCE->Delay_Reset_ZCE = rtu_Reset ? ((ZCSigState)1U) : ((ZCSigState)0U);
  rtb_Delay = localDW->Delay_DSTATE;

  /* End of Delay: '<S14>/Delay' */

  /* Gain: '<S14>/Gain2' */
  rtb_Add2 = rtp_Ts * rtb_Delay;

  /* Sum: '<S12>/Add' */
  rtb_Divide2_a += rtb_Add2;

  /* Saturate: '<S12>/Saturation' */
  if (rtb_Divide2_a > rtp_Max) {
    rty_Out_0 = rtp_Max;
  } else if (rtb_Divide2_a < rtp_Min) {
    rty_Out_0 = rtp_Min;
  } else {
    rty_Out_0 = rtb_Divide2_a;
  }

  /* End of Saturate: '<S12>/Saturation' */

  /* Sum: '<S12>/Add1' */
  rtb_Divide2_a = rty_Out_0 - rtb_Divide2_a;

  /* Product: '<S12>/Divide1' incorporates:
   *  Constant: '<S12>/Constant1'
   */
  rtb_Add2 = rtu_Error * rtp_Ki;

  /* Product: '<S12>/Divide2' incorporates:
   *  Constant: '<S12>/Constant'
   *  Constant: '<S12>/Constant1'
   */
  rtb_Divide2_a = (rtb_Divide2_a * rtp_Ki) / rtp_Kp;

  /* Sum: '<S12>/Add2' */
  rtb_Add2 += rtb_Divide2_a;

  /* Sum: '<S14>/Add3' */
  rtb_Divide2_a = rtb_Add2 + rtb_Delay;

  /* Update for Delay: '<S14>/Delay' */
  localDW->Delay_DSTATE = rtb_Divide2_a;
  return rty_Out_0;
}

/*
 * Output and update for atomic system:
 *    '<S5>/abc2&#x3B1;&#x3B2;0'
 *    '<S6>/abc2&#x3B1;&#x3B2;0'
 *    '<S7>/abc2&#x3B1;&#x3B2;0'
 *    '<S43>/abc2&#x3B1;&#x3B2;0'
 *    '<S44>/abc2&#x3B1;&#x3B2;0'
 *    '<S49>/abc2&#x3B1;&#x3B2;0'
 *    '<S50>/abc2&#x3B1;&#x3B2;0'
 *    '<S55>/abc2&#x3B1;&#x3B2;0'
 *    '<S56>/abc2&#x3B1;&#x3B2;0'
 */
void abc2AlphaBetaZero(const float rtu_abc[3], float rty_u[3])
{
  float rtu_abc_0;
  float rtu_abc_1;
  float rtu_abc_2;
  float rty_u_0;
  int16_t i;

  /* Gain: '<S28>/Gain3' */
  rtu_abc_0 = rtu_abc[0];
  rtu_abc_1 = rtu_abc[1];
  rtu_abc_2 = rtu_abc[2];
  for (i = 0; i < 3; i++) {
    rty_u_0 = Off_Grid_Inverter_Contro_ConstP.pooled9[i] * rtu_abc_0;
    rty_u_0 += Off_Grid_Inverter_Contro_ConstP.pooled9[i + 3] * rtu_abc_1;
    rty_u_0 += Off_Grid_Inverter_Contro_ConstP.pooled9[i + 6] * rtu_abc_2;

    /* Gain: '<S28>/Gain1' */
    rty_u_0 *= rtCP_pooled10;
    rty_u[i] = rty_u_0;
  }

  /* End of Gain: '<S28>/Gain3' */
}

/*
 * Output and update for atomic system:
 *    '<S5>/&#x3B1;&#x3B2;02abc'
 *    '<S5>/&#x3B1;&#x3B2;02abc1'
 *    '<S6>/&#x3B1;&#x3B2;02abc'
 *    '<S6>/&#x3B1;&#x3B2;02abc1'
 *    '<S7>/&#x3B1;&#x3B2;02abc'
 *    '<S7>/&#x3B1;&#x3B2;02abc1'
 *    '<S37>/&#x3B1;&#x3B2;02abc'
 *    '<S38>/&#x3B1;&#x3B2;02abc'
 */
void AlphaBetaZero2abc(float rtu_u, float rtu_u_k, float rtu_u_n, float rty_abc
  [3])
{
  float rty_abc_0;
  int16_t i;

  /* Gain: '<S29>/Gain3' */
  for (i = 0; i < 3; i++) {
    rty_abc_0 = Off_Grid_Inverter_Contro_ConstP.pooled11[i] * rtu_u;
    rty_abc_0 += Off_Grid_Inverter_Contro_ConstP.pooled11[i + 3] * rtu_u_k;
    rty_abc_0 += Off_Grid_Inverter_Contro_ConstP.pooled11[i + 6] * rtu_u_n;
    rty_abc[i] = rty_abc_0;
  }

  /* End of Gain: '<S29>/Gain3' */
}

/*
 * Output and update for atomic system:
 *    '<Root>/Sequency_Separator1'
 *    '<Root>/Sequency_Separator2'
 *    '<Root>/Sequency_Separator3'
 */
void Sequency_Separator(const float rtu_Input_abc[3], float rty_Outout_Positive
  [3], float rty_Outout_negetive[3], DW_Sequency_Separator_T *localDW)
{
  float rtb_Gain1[3];
  float rtb_Gain1_k[3];
  float rtb_Add1;
  float rtb_Add2;
  float rtb_Add3_b;
  float rtb_Add4;
  float rtb_Delay1_idx_0;
  float rtb_Delay1_idx_1;
  int16_t Delay1_DSTATE_tmp;
  int16_t idxDelay;

  /* Gain: '<S5>/Gain1' */
  rtb_Gain1[0] = rtCP_pooled12 * rtu_Input_abc[0];
  rtb_Gain1[1] = rtCP_pooled12 * rtu_Input_abc[1];
  rtb_Gain1[2] = rtCP_pooled12 * rtu_Input_abc[2];

  /* Outputs for Atomic SubSystem: '<S5>/abc2&#x3B1;&#x3B2;0' */
  abc2AlphaBetaZero(rtb_Gain1, rtb_Gain1_k);

  /* End of Outputs for SubSystem: '<S5>/abc2&#x3B1;&#x3B2;0' */

  /* Delay: '<S5>/Delay1' */
  rtb_Delay1_idx_0 = localDW->Delay1_DSTATE[0];
  rtb_Delay1_idx_1 = localDW->Delay1_DSTATE[1];

  /* Sum: '<S5>/Add1' */
  rtb_Add1 = rtb_Gain1_k[0] - rtb_Delay1_idx_1;

  /* Sum: '<S5>/Add2' */
  rtb_Add2 = rtb_Delay1_idx_0 + rtb_Gain1_k[1];

  /* Sum: '<S5>/Add3' */
  rtb_Add3_b = rtb_Gain1_k[0] + rtb_Delay1_idx_1;

  /* Sum: '<S5>/Add4' */
  rtb_Add4 = rtb_Gain1_k[1] - rtb_Delay1_idx_0;

  /* Outputs for Atomic SubSystem: '<S5>/&#x3B1;&#x3B2;02abc' */
  /* Constant: '<S5>/Zero' */
  AlphaBetaZero2abc(rtb_Add1, rtb_Add2, rtCP_pooled8, rty_Outout_Positive);

  /* End of Outputs for SubSystem: '<S5>/&#x3B1;&#x3B2;02abc' */

  /* Outputs for Atomic SubSystem: '<S5>/&#x3B1;&#x3B2;02abc1' */
  AlphaBetaZero2abc(rtb_Add3_b, rtb_Add4, rtCP_pooled8, rty_Outout_negetive);

  /* End of Outputs for SubSystem: '<S5>/&#x3B1;&#x3B2;02abc1' */

  /* Update for Delay: '<S5>/Delay1' */
  for (idxDelay = 0; idxDelay < 79; idxDelay++) {
    Delay1_DSTATE_tmp = (idxDelay + 1) * 2;
    localDW->Delay1_DSTATE[idxDelay * 2] = localDW->
      Delay1_DSTATE[Delay1_DSTATE_tmp];
    localDW->Delay1_DSTATE[(idxDelay * 2) + 1] = localDW->
      Delay1_DSTATE[Delay1_DSTATE_tmp + 1];
  }

  localDW->Delay1_DSTATE[158] = rtb_Gain1_k[0];
  localDW->Delay1_DSTATE[159] = rtb_Gain1_k[1];

  /* End of Update for Delay: '<S5>/Delay1' */
}

/*
 * Output and update for atomic system:
 *    '<S37>/dq2&#x3B1;&#x3B2;0'
 *    '<S38>/dq2&#x3B1;&#x3B2;0'
 */
void dq2AlphaBeta(const float rtu_dq[2], float rtu_wt, float *rty_u, float
                  *rty_u_o)
{
  float tmp;
  float tmp_0;

  /* Fcn: '<S39>/Fcn' incorporates:
   *  Fcn: '<S39>/Fcn1'
   */
  tmp = (float)sin((double)rtu_wt);
  tmp_0 = (float)cos((double)rtu_wt);
  *rty_u = (rtu_dq[0] * tmp_0) - (rtu_dq[1] * tmp);

  /* Fcn: '<S39>/Fcn1' */
  *rty_u_o = (rtu_dq[0] * tmp) + (rtu_dq[1] * tmp_0);
}

/*
 * Output and update for atomic system:
 *    '<S8>/dq2abc'
 *    '<S8>/dq2abc1'
 */
void dq2abc(const float rtu_dq[2], float rtu_wt, float rty_abc[3])
{
  float rtb_Fcn;
  float rtb_Fcn1;

  /* Outputs for Atomic SubSystem: '<S37>/dq2&#x3B1;&#x3B2;0' */
  dq2AlphaBeta(rtu_dq, rtu_wt, &rtb_Fcn, &rtb_Fcn1);

  /* End of Outputs for SubSystem: '<S37>/dq2&#x3B1;&#x3B2;0' */

  /* Outputs for Atomic SubSystem: '<S37>/&#x3B1;&#x3B2;02abc' */

  /* Constant: '<S37>/Constant' */
  AlphaBetaZero2abc(rtb_Fcn, rtb_Fcn1, rtCP_pooled8, rty_abc);

  /* End of Outputs for SubSystem: '<S37>/&#x3B1;&#x3B2;02abc' */
}

/*
 * Output and update for atomic system:
 *    '<S43>/&#x3B1;&#x3B2;2dq'
 *    '<S44>/&#x3B1;&#x3B2;2dq'
 *    '<S49>/&#x3B1;&#x3B2;2dq'
 *    '<S50>/&#x3B1;&#x3B2;2dq'
 *    '<S55>/&#x3B1;&#x3B2;2dq'
 *    '<S56>/&#x3B1;&#x3B2;2dq'
 */
void AlphaBeta2dq(const float rtu_u[2], float rtu_wt, float *rty_dq, float
                  *rty_dq_p)
{
  float tmp;
  float tmp_0;

  /* Fcn: '<S46>/Fcn' incorporates:
   *  Fcn: '<S46>/Fcn1'
   */
  tmp = (float)sin((double)rtu_wt);
  tmp_0 = (float)cos((double)rtu_wt);
  *rty_dq = (rtu_u[0] * tmp_0) + (rtu_u[1] * tmp);

  /* Fcn: '<S46>/Fcn1' */
  *rty_dq_p = (-rtu_u[0] * tmp) + (rtu_u[1] * tmp_0);
}

/*
 * Output and update for atomic system:
 *    '<S9>/abc2dq1'
 *    '<S9>/abc2dq2'
 *    '<S10>/abc2dq1'
 *    '<S10>/abc2dq2'
 *    '<S11>/abc2dq1'
 *    '<S11>/abc2dq2'
 */
void abc2dq(const float rtu_abc[3], float rtu_wt, float rty_dq[2])
{
  float rtb_Gain1[3];
  float rtb_Fcn;
  float rtb_Fcn1;

  /* Outputs for Atomic SubSystem: '<S43>/abc2&#x3B1;&#x3B2;0' */
  abc2AlphaBetaZero(rtu_abc, rtb_Gain1);

  /* End of Outputs for SubSystem: '<S43>/abc2&#x3B1;&#x3B2;0' */

  /* Outputs for Atomic SubSystem: '<S43>/&#x3B1;&#x3B2;2dq' */

  /* Gain: '<S45>/Gain1' */
  AlphaBeta2dq(&rtb_Gain1[0], rtu_wt, &rtb_Fcn, &rtb_Fcn1);

  /* End of Outputs for SubSystem: '<S43>/&#x3B1;&#x3B2;2dq' */

  /* SignalConversion: '<S43>/Signal Conversion' */
  rty_dq[0] = rtb_Fcn;
  rty_dq[1] = rtb_Fcn1;
}

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

/* Model step function */
void Off_Grid_Inverter_Control_LC_step(const float *arg_time, float arg_M_abc[3],
  const float arg_Ec_abc[3], const float arg_IL_abc[3], const float arg_Ic_abc[3],
  const float *arg_Udc, const float arg_Uc_dq_p_ref[2], const float
  arg_Uc_dq_n_re[2], const bool *arg_Reset)
{
  float rtb_Add[3];
  float rtb_Gain3[3];
  float rtb_Gain3_a[3];
  float rtb_Gain3_c[3];
  float rtb_Gain3_fu[3];
  float rtb_Gain3_j[3];
  float rtb_Gain3_k[3];
  float rtb_Gain3_n[3];
  float rtb_SignalConversion[2];
  float rtb_SignalConversion_a[2];
  float rtb_SignalConversion_c[2];
  float rtb_SignalConversion_g[2];
  float rtb_SignalConversion_l[2];
  float rtb_SignalConversion_pl[2];
  float rtb_Divide1;
  float rtb_Divide2;
  float rtb_Divide2_c;
  float rtb_Divide2_j;
  float rtb_Divide2_pm;
  float rtb_Divide3;
  float rtb_Divide4;
  float rtb_Divide4_l;
  float rtb_Divide4_o;
  float rtb_Gain2;
  float rtb_Negetive_wt;
  float rtb_Negetive_wt_e;
  float rtb_Negetive_wt_n;
  float rtb_Saturation;
  float rtb_Sum2;
  float rtb_Sum3;

  /* Product: '<Root>/Divide2' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Constant4'
   *  Inport: '<Root>/Ec_abc'
   */
  Off_Grid_Inverter_Control_LC_B.Ec_ABC_Phase[0] = (arg_Ec_abc[0] /
    rtCP_Constant_Value) / rtCP_pooled13;
  Off_Grid_Inverter_Control_LC_B.Ec_ABC_Phase[1] = (arg_Ec_abc[1] /
    rtCP_Constant_Value) / rtCP_pooled13;
  Off_Grid_Inverter_Control_LC_B.Ec_ABC_Phase[2] = (arg_Ec_abc[2] /
    rtCP_Constant_Value) / rtCP_pooled13;

  /* Outputs for Atomic SubSystem: '<Root>/Sequency_Separator2' */
  Sequency_Separator(Off_Grid_Inverter_Control_LC_B.Ec_ABC_Phase, rtb_Gain3_a,
                     rtb_Gain3_k,
                     &Off_Grid_Inverter_Control_LC_DW.Sequency_Separator2);

  /* End of Outputs for SubSystem: '<Root>/Sequency_Separator2' */

  /* SignalConversion generated from: '<Root>/Sequency_Separator2' */
  Off_Grid_Inverter_Control_LC_B.Ec_ABC_p[0] = rtb_Gain3_a[0];
  Off_Grid_Inverter_Control_LC_B.Ec_ABC_p[1] = rtb_Gain3_a[1];
  Off_Grid_Inverter_Control_LC_B.Ec_ABC_p[2] = rtb_Gain3_a[2];

  /* Gain: '<Root>/Gain' incorporates:
   *  Inport: '<Root>/time'
   */
  rtb_Divide1 = rtCP_Gain_Gain * *arg_time;

  /* Math: '<Root>/Mod' incorporates:
   *  Constant: '<Root>/Constant2'
   */
  Off_Grid_Inverter_Control_LC_B.wt = rt_modf(rtb_Divide1, rtCP_Constant2_Value);

  /* Outputs for Atomic SubSystem: '<S10>/abc2dq1' */
  abc2dq(Off_Grid_Inverter_Control_LC_B.Ec_ABC_p,
         Off_Grid_Inverter_Control_LC_B.wt, rtb_SignalConversion_l);

  /* End of Outputs for SubSystem: '<S10>/abc2dq1' */

  /* SignalConversion generated from: '<S10>/abc2dq1' */
  Off_Grid_Inverter_Control_LC_B.Ec_dq_p[0] = rtb_SignalConversion_l[0];
  Off_Grid_Inverter_Control_LC_B.Ec_dq_p[1] = rtb_SignalConversion_l[1];

  /* Product: '<Root>/Divide1' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Constant5'
   *  Inport: '<Root>/IL_abc'
   */
  Off_Grid_Inverter_Control_LC_B.IL_ABC[0] = (arg_IL_abc[0] / rtCP_pooled14) /
    rtCP_Constant_Value;
  Off_Grid_Inverter_Control_LC_B.IL_ABC[1] = (arg_IL_abc[1] / rtCP_pooled14) /
    rtCP_Constant_Value;
  Off_Grid_Inverter_Control_LC_B.IL_ABC[2] = (arg_IL_abc[2] / rtCP_pooled14) /
    rtCP_Constant_Value;

  /* Outputs for Atomic SubSystem: '<Root>/Sequency_Separator1' */
  Sequency_Separator(Off_Grid_Inverter_Control_LC_B.IL_ABC, rtb_Gain3_fu,
                     rtb_Gain3_n,
                     &Off_Grid_Inverter_Control_LC_DW.Sequency_Separator1);

  /* End of Outputs for SubSystem: '<Root>/Sequency_Separator1' */

  /* SignalConversion generated from: '<Root>/Sequency_Separator1' */
  Off_Grid_Inverter_Control_LC_B.IL_ABC_p[0] = rtb_Gain3_fu[0];
  Off_Grid_Inverter_Control_LC_B.IL_ABC_p[1] = rtb_Gain3_fu[1];
  Off_Grid_Inverter_Control_LC_B.IL_ABC_p[2] = rtb_Gain3_fu[2];

  /* Outputs for Atomic SubSystem: '<S9>/abc2dq1' */
  abc2dq(Off_Grid_Inverter_Control_LC_B.IL_ABC_p,
         Off_Grid_Inverter_Control_LC_B.wt, rtb_SignalConversion_g);

  /* End of Outputs for SubSystem: '<S9>/abc2dq1' */

  /* SignalConversion generated from: '<S9>/abc2dq1' */
  Off_Grid_Inverter_Control_LC_B.IL_dq_p[0] = rtb_SignalConversion_g[0];
  Off_Grid_Inverter_Control_LC_B.IL_dq_p[1] = rtb_SignalConversion_g[1];

  /* Product: '<Root>/Divide4' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Constant5'
   *  Inport: '<Root>/Ic_abc'
   */
  Off_Grid_Inverter_Control_LC_B.Ic_ABC[0] = (arg_Ic_abc[0] / rtCP_pooled14) /
    rtCP_Constant_Value;
  Off_Grid_Inverter_Control_LC_B.Ic_ABC[1] = (arg_Ic_abc[1] / rtCP_pooled14) /
    rtCP_Constant_Value;
  Off_Grid_Inverter_Control_LC_B.Ic_ABC[2] = (arg_Ic_abc[2] / rtCP_pooled14) /
    rtCP_Constant_Value;

  /* Outputs for Atomic SubSystem: '<Root>/Sequency_Separator3' */
  Sequency_Separator(Off_Grid_Inverter_Control_LC_B.Ic_ABC, rtb_Gain3_c,
                     rtb_Gain3_j,
                     &Off_Grid_Inverter_Control_LC_DW.Sequency_Separator3);

  /* End of Outputs for SubSystem: '<Root>/Sequency_Separator3' */

  /* SignalConversion generated from: '<Root>/Sequency_Separator3' */
  Off_Grid_Inverter_Control_LC_B.Ic_ABC_p[0] = rtb_Gain3_c[0];
  Off_Grid_Inverter_Control_LC_B.Ic_ABC_p[1] = rtb_Gain3_c[1];
  Off_Grid_Inverter_Control_LC_B.Ic_ABC_p[2] = rtb_Gain3_c[2];

  /* Outputs for Atomic SubSystem: '<S11>/abc2dq1' */
  abc2dq(Off_Grid_Inverter_Control_LC_B.Ic_ABC_p,
         Off_Grid_Inverter_Control_LC_B.wt, rtb_SignalConversion_pl);

  /* End of Outputs for SubSystem: '<S11>/abc2dq1' */

  /* SignalConversion generated from: '<S11>/abc2dq1' */
  Off_Grid_Inverter_Control_LC_B.Ic_dq_p[0] = rtb_SignalConversion_pl[0];
  Off_Grid_Inverter_Control_LC_B.Ic_dq_p[1] = rtb_SignalConversion_pl[1];

  /* Sum: '<S4>/Sum' incorporates:
   *  Inport: '<Root>/Uc_dq_p_ref'
   */
  rtb_Divide1 = arg_Uc_dq_p_ref[0] - Off_Grid_Inverter_Control_LC_B.Ec_dq_p[0];

  /* Product: '<S4>/Divide2' incorporates:
   *  Constant: '<S4>/Constant1'
   *  Constant: '<S4>/Constant2'
   */
  rtb_Divide2 = (rtb_Divide1 / rtCP_pooled14) * rtCP_pooled13;

  /* Outputs for Atomic SubSystem: '<S4>/PI Controller' */
  /* Inport: '<Root>/Reset' */
  rtb_Saturation = PI_Controller(rtb_Divide2, *arg_Reset, rtCP_pooled4,
    rtCP_pooled5, rtCP_pooled6, rtCP_pooled7, rtCP_pooled2,
    &Off_Grid_Inverter_Control_LC_DW.PIController_d,
    &Off_Grid_Inverter_Contr_PrevZCX.PIController_d);

  /* End of Outputs for SubSystem: '<S4>/PI Controller' */

  /* Product: '<S4>/Divide3' incorporates:
   *  Constant: '<S4>/Constant1'
   *  Constant: '<S4>/Constant2'
   */
  rtb_Divide1 = (Off_Grid_Inverter_Control_LC_B.Ec_dq_p[1] / rtCP_pooled14) *
    rtCP_pooled13;

  /* Gain: '<S4>/Gain' */
  rtb_Divide1 *= rtCP_pooled15;

  /* Product: '<S4>/Divide' incorporates:
   *  Constant: '<S4>/Constant3'
   */
  rtb_Sum3 = Off_Grid_Inverter_Control_LC_B.Ec_dq_p[0] * rtCP_pooled16;

  /* Sum: '<S4>/Sum2' */
  rtb_Divide1 = Off_Grid_Inverter_Control_LC_B.Ic_dq_p[0] - rtb_Saturation +
    rtb_Divide1 - rtb_Sum3;

  /* Sum: '<S3>/Sum' */
  rtb_Divide1 -= Off_Grid_Inverter_Control_LC_B.IL_dq_p[0];

  /* Product: '<S3>/Divide2' incorporates:
   *  Constant: '<S3>/Constant1'
   *  Constant: '<S3>/Constant2'
   */
  rtb_Divide2_pm = (rtb_Divide1 * rtCP_pooled14) / rtCP_pooled13;

  /* Outputs for Atomic SubSystem: '<S3>/PI Controller' */
  /* Inport: '<Root>/Reset' */
  rtb_Saturation = PI_Controller(rtb_Divide2_pm, *arg_Reset, rtCP_pooled3,
    rtCP_pooled5, rtCP_pooled6, rtCP_pooled7, rtCP_pooled1,
    &Off_Grid_Inverter_Control_LC_DW.PIController_h,
    &Off_Grid_Inverter_Contr_PrevZCX.PIController_h);

  /* End of Outputs for SubSystem: '<S3>/PI Controller' */

  /* Product: '<S3>/Divide3' incorporates:
   *  Constant: '<S3>/Constant1'
   *  Constant: '<S3>/Constant2'
   */
  rtb_Sum3 = (Off_Grid_Inverter_Control_LC_B.IL_dq_p[1] * rtCP_pooled14) /
    rtCP_pooled13;

  /* Gain: '<S3>/Gain' */
  rtb_Sum3 *= rtCP_pooled17;

  /* Sum: '<S3>/Sum2' */
  rtb_Sum3 += Off_Grid_Inverter_Control_LC_B.Ec_dq_p[0] - rtb_Saturation;

  /* Sum: '<S4>/Sum1' incorporates:
   *  Inport: '<Root>/Uc_dq_p_ref'
   */
  rtb_Divide1 = arg_Uc_dq_p_ref[1] - Off_Grid_Inverter_Control_LC_B.Ec_dq_p[1];

  /* Product: '<S4>/Divide4' incorporates:
   *  Constant: '<S4>/Constant1'
   *  Constant: '<S4>/Constant2'
   */
  rtb_Divide4 = (rtb_Divide1 / rtCP_pooled14) * rtCP_pooled13;

  /* Outputs for Atomic SubSystem: '<S4>/PI Controller1' */
  /* Inport: '<Root>/Reset' */
  rtb_Saturation = PI_Controller(rtb_Divide4, *arg_Reset, rtCP_pooled4,
    rtCP_pooled5, rtCP_pooled6, rtCP_pooled7, rtCP_pooled2,
    &Off_Grid_Inverter_Control_LC_DW.PIController1_h,
    &Off_Grid_Inverter_Contr_PrevZCX.PIController1_h);

  /* End of Outputs for SubSystem: '<S4>/PI Controller1' */

  /* Product: '<S4>/Divide5' incorporates:
   *  Constant: '<S4>/Constant1'
   *  Constant: '<S4>/Constant2'
   */
  rtb_Divide1 = (Off_Grid_Inverter_Control_LC_B.Ic_dq_p[0] / rtCP_pooled14) *
    rtCP_pooled13;

  /* Gain: '<S4>/Gain1' */
  rtb_Divide1 *= rtCP_pooled15;

  /* Product: '<S4>/Divide1' incorporates:
   *  Constant: '<S4>/Constant3'
   */
  rtb_Sum2 = Off_Grid_Inverter_Control_LC_B.Ec_dq_p[1] * rtCP_pooled16;

  /* Sum: '<S4>/Sum3' */
  rtb_Divide1 = Off_Grid_Inverter_Control_LC_B.Ic_dq_p[1] - rtb_Saturation -
    rtb_Divide1 - rtb_Sum2;

  /* Sum: '<S3>/Sum1' */
  rtb_Divide1 -= Off_Grid_Inverter_Control_LC_B.IL_dq_p[1];

  /* Product: '<S3>/Divide4' incorporates:
   *  Constant: '<S3>/Constant1'
   *  Constant: '<S3>/Constant2'
   */
  rtb_Divide4_o = (rtb_Divide1 * rtCP_pooled14) / rtCP_pooled13;

  /* Outputs for Atomic SubSystem: '<S3>/PI Controller1' */
  /* Inport: '<Root>/Reset' */
  rtb_Saturation = PI_Controller(rtb_Divide4_o, *arg_Reset, rtCP_pooled3,
    rtCP_pooled5, rtCP_pooled6, rtCP_pooled7, rtCP_pooled1,
    &Off_Grid_Inverter_Control_LC_DW.PIController1_i,
    &Off_Grid_Inverter_Contr_PrevZCX.PIController1_i);

  /* End of Outputs for SubSystem: '<S3>/PI Controller1' */

  /* Product: '<S3>/Divide5' incorporates:
   *  Constant: '<S3>/Constant1'
   *  Constant: '<S3>/Constant2'
   */
  rtb_Sum2 = (Off_Grid_Inverter_Control_LC_B.IL_dq_p[0] * rtCP_pooled14) /
    rtCP_pooled13;

  /* Gain: '<S3>/Gain1' */
  rtb_Sum2 *= rtCP_pooled17;

  /* Sum: '<S3>/Sum3' */
  rtb_Sum2 = Off_Grid_Inverter_Control_LC_B.Ec_dq_p[1] - rtb_Saturation -
    rtb_Sum2;

  /* Product: '<Root>/Divide3' incorporates:
   *  Constant: '<Root>/Constant6'
   *  Inport: '<Root>/Udc'
   */
  Off_Grid_Inverter_Control_LC_B.UDC = *arg_Udc / rtCP_pooled19;

  /* Product: '<S3>/Divide' incorporates:
   *  Constant: '<S3>/Constant'
   *  Constant: '<S3>/Constant3'
   *  Constant: '<S3>/Constant6'
   */
  Off_Grid_Inverter_Control_LC_B.Uc_dq_p[0] = (((rtb_Sum3 * rtCP_pooled13) *
    rtCP_pooled18) / Off_Grid_Inverter_Control_LC_B.UDC) / rtCP_pooled19;
  Off_Grid_Inverter_Control_LC_B.Uc_dq_p[1] = (((rtb_Sum2 * rtCP_pooled13) *
    rtCP_pooled18) / Off_Grid_Inverter_Control_LC_B.UDC) / rtCP_pooled19;

  /* Outputs for Atomic SubSystem: '<S8>/dq2abc' */
  dq2abc(Off_Grid_Inverter_Control_LC_B.Uc_dq_p,
         Off_Grid_Inverter_Control_LC_B.wt, rtb_Gain3);

  /* End of Outputs for SubSystem: '<S8>/dq2abc' */

  /* SignalConversion generated from: '<Root>/Sequency_Separator2' */
  Off_Grid_Inverter_Control_LC_B.Ec_ABC_n[0] = rtb_Gain3_k[0];
  Off_Grid_Inverter_Control_LC_B.Ec_ABC_n[1] = rtb_Gain3_k[1];
  Off_Grid_Inverter_Control_LC_B.Ec_ABC_n[2] = rtb_Gain3_k[2];

  /* Gain: '<S10>/Gain' */
  rtb_Negetive_wt = rtCP_pooled20 * Off_Grid_Inverter_Control_LC_B.wt;

  /* Outputs for Atomic SubSystem: '<S10>/abc2dq2' */
  abc2dq(Off_Grid_Inverter_Control_LC_B.Ec_ABC_n, rtb_Negetive_wt,
         rtb_SignalConversion_a);

  /* End of Outputs for SubSystem: '<S10>/abc2dq2' */

  /* SignalConversion generated from: '<S10>/abc2dq2' */
  Off_Grid_Inverter_Control_LC_B.Ec_dq_n[0] = rtb_SignalConversion_a[0];
  Off_Grid_Inverter_Control_LC_B.Ec_dq_n[1] = rtb_SignalConversion_a[1];

  /* SignalConversion generated from: '<Root>/Sequency_Separator1' */
  Off_Grid_Inverter_Control_LC_B.IL_ABC_n[0] = rtb_Gain3_n[0];
  Off_Grid_Inverter_Control_LC_B.IL_ABC_n[1] = rtb_Gain3_n[1];
  Off_Grid_Inverter_Control_LC_B.IL_ABC_n[2] = rtb_Gain3_n[2];

  /* Gain: '<S9>/Gain' */
  rtb_Negetive_wt_e = rtCP_pooled20 * Off_Grid_Inverter_Control_LC_B.wt;

  /* Outputs for Atomic SubSystem: '<S9>/abc2dq2' */
  abc2dq(Off_Grid_Inverter_Control_LC_B.IL_ABC_n, rtb_Negetive_wt_e,
         rtb_SignalConversion_c);

  /* End of Outputs for SubSystem: '<S9>/abc2dq2' */

  /* SignalConversion generated from: '<S9>/abc2dq2' */
  Off_Grid_Inverter_Control_LC_B.IL_dq_n[0] = rtb_SignalConversion_c[0];
  Off_Grid_Inverter_Control_LC_B.IL_dq_n[1] = rtb_SignalConversion_c[1];

  /* SignalConversion generated from: '<Root>/Sequency_Separator3' */
  Off_Grid_Inverter_Control_LC_B.Ic_ABC_n[0] = rtb_Gain3_j[0];
  Off_Grid_Inverter_Control_LC_B.Ic_ABC_n[1] = rtb_Gain3_j[1];
  Off_Grid_Inverter_Control_LC_B.Ic_ABC_n[2] = rtb_Gain3_j[2];

  /* Gain: '<S11>/Gain' */
  rtb_Negetive_wt_n = rtCP_pooled20 * Off_Grid_Inverter_Control_LC_B.wt;

  /* Outputs for Atomic SubSystem: '<S11>/abc2dq2' */
  abc2dq(Off_Grid_Inverter_Control_LC_B.Ic_ABC_n, rtb_Negetive_wt_n,
         rtb_SignalConversion);

  /* End of Outputs for SubSystem: '<S11>/abc2dq2' */

  /* SignalConversion generated from: '<S11>/abc2dq2' */
  Off_Grid_Inverter_Control_LC_B.Ic_dq_n[0] = rtb_SignalConversion[0];
  Off_Grid_Inverter_Control_LC_B.Ic_dq_n[1] = rtb_SignalConversion[1];

  /* Sum: '<S2>/Sum' incorporates:
   *  Inport: '<Root>/Uc_dq_n_re'
   */
  rtb_Sum2 = arg_Uc_dq_n_re[0] - Off_Grid_Inverter_Control_LC_B.Ec_dq_n[0];

  /* Product: '<S2>/Divide2' incorporates:
   *  Constant: '<S2>/Constant1'
   *  Constant: '<S2>/Constant2'
   */
  rtb_Divide2_j = (rtb_Sum2 / rtCP_pooled14) * rtCP_pooled13;

  /* Outputs for Atomic SubSystem: '<S2>/PI Controller' */
  /* Inport: '<Root>/Reset' */
  rtb_Saturation = PI_Controller(rtb_Divide2_j, *arg_Reset, rtCP_pooled4,
    rtCP_pooled5, rtCP_pooled6, rtCP_pooled7, rtCP_pooled2,
    &Off_Grid_Inverter_Control_LC_DW.PIController,
    &Off_Grid_Inverter_Contr_PrevZCX.PIController);

  /* End of Outputs for SubSystem: '<S2>/PI Controller' */

  /* Product: '<S2>/Divide3' incorporates:
   *  Constant: '<S2>/Constant1'
   *  Constant: '<S2>/Constant2'
   */
  rtb_Sum2 = (Off_Grid_Inverter_Control_LC_B.Ec_dq_n[1] / rtCP_pooled14) *
    rtCP_pooled13;

  /* Gain: '<S2>/Gain' */
  rtb_Sum2 *= rtCP_pooled15;

  /* Product: '<S2>/Divide6' incorporates:
   *  Constant: '<S2>/Constant3'
   */
  rtb_Sum3 = Off_Grid_Inverter_Control_LC_B.Ec_dq_n[1] * rtCP_pooled16;

  /* Sum: '<S2>/Sum2' */
  rtb_Sum2 = Off_Grid_Inverter_Control_LC_B.Ic_dq_n[0] - rtb_Saturation -
    rtb_Sum2 - rtb_Sum3;

  /* Sum: '<S1>/Sum' */
  rtb_Sum2 -= Off_Grid_Inverter_Control_LC_B.IL_dq_n[0];

  /* Product: '<S1>/Divide2' incorporates:
   *  Constant: '<S1>/Constant1'
   *  Constant: '<S1>/Constant2'
   */
  rtb_Divide2_c = (rtb_Sum2 * rtCP_pooled14) / rtCP_pooled13;

  /* Outputs for Atomic SubSystem: '<S1>/PI Controller1' */
  /* Inport: '<Root>/Reset' */
  rtb_Saturation = PI_Controller(rtb_Divide2_c, *arg_Reset, rtCP_pooled3,
    rtCP_pooled5, rtCP_pooled6, rtCP_pooled7, rtCP_pooled1,
    &Off_Grid_Inverter_Control_LC_DW.PIController1,
    &Off_Grid_Inverter_Contr_PrevZCX.PIController1);

  /* End of Outputs for SubSystem: '<S1>/PI Controller1' */

  /* Product: '<S1>/Divide1' incorporates:
   *  Constant: '<S1>/Constant1'
   *  Constant: '<S1>/Constant2'
   */
  rtb_Sum2 = (Off_Grid_Inverter_Control_LC_B.IL_dq_n[1] * rtCP_pooled14) /
    rtCP_pooled13;

  /* Gain: '<S1>/Gain' */
  rtb_Sum2 *= rtCP_pooled17;

  /* Sum: '<S1>/Sum2' */
  rtb_Sum2 = Off_Grid_Inverter_Control_LC_B.Ec_dq_n[0] - rtb_Saturation -
    rtb_Sum2;

  /* Sum: '<S2>/Sum1' incorporates:
   *  Inport: '<Root>/Uc_dq_n_re'
   */
  rtb_Sum3 = arg_Uc_dq_n_re[1] - Off_Grid_Inverter_Control_LC_B.Ec_dq_n[1];

  /* Product: '<S2>/Divide4' incorporates:
   *  Constant: '<S2>/Constant1'
   *  Constant: '<S2>/Constant2'
   */
  rtb_Divide4_l = (rtb_Sum3 / rtCP_pooled14) * rtCP_pooled13;

  /* Outputs for Atomic SubSystem: '<S2>/PI Controller1' */
  /* Inport: '<Root>/Reset' */
  rtb_Saturation = PI_Controller(rtb_Divide4_l, *arg_Reset, rtCP_pooled4,
    rtCP_pooled5, rtCP_pooled6, rtCP_pooled7, rtCP_pooled2,
    &Off_Grid_Inverter_Control_LC_DW.PIController1_l,
    &Off_Grid_Inverter_Contr_PrevZCX.PIController1_l);

  /* End of Outputs for SubSystem: '<S2>/PI Controller1' */

  /* Product: '<S2>/Divide5' incorporates:
   *  Constant: '<S2>/Constant1'
   *  Constant: '<S2>/Constant2'
   */
  rtb_Sum3 = (Off_Grid_Inverter_Control_LC_B.Ic_dq_n[0] / rtCP_pooled14) *
    rtCP_pooled13;

  /* Gain: '<S2>/Gain1' */
  rtb_Sum3 *= rtCP_pooled15;

  /* Product: '<S2>/Divide1' incorporates:
   *  Constant: '<S2>/Constant3'
   */
  rtb_Divide1 = Off_Grid_Inverter_Control_LC_B.Ec_dq_n[1] * rtCP_pooled16;

  /* Sum: '<S2>/Sum3' */
  rtb_Sum3 = Off_Grid_Inverter_Control_LC_B.Ic_dq_n[1] - rtb_Saturation +
    rtb_Sum3 - rtb_Divide1;

  /* Sum: '<S1>/Sum1' */
  rtb_Sum3 -= Off_Grid_Inverter_Control_LC_B.IL_dq_n[1];

  /* Product: '<S1>/Divide3' incorporates:
   *  Constant: '<S1>/Constant1'
   *  Constant: '<S1>/Constant2'
   */
  rtb_Divide3 = (rtb_Sum3 * rtCP_pooled14) / rtCP_pooled13;

  /* Outputs for Atomic SubSystem: '<S1>/PI Controller2' */
  /* Inport: '<Root>/Reset' */
  rtb_Saturation = PI_Controller(rtb_Divide3, *arg_Reset, rtCP_pooled3,
    rtCP_pooled5, rtCP_pooled6, rtCP_pooled7, rtCP_pooled1,
    &Off_Grid_Inverter_Control_LC_DW.PIController2,
    &Off_Grid_Inverter_Contr_PrevZCX.PIController2);

  /* End of Outputs for SubSystem: '<S1>/PI Controller2' */

  /* Product: '<S1>/Divide4' incorporates:
   *  Constant: '<S1>/Constant1'
   *  Constant: '<S1>/Constant2'
   */
  rtb_Sum3 = (Off_Grid_Inverter_Control_LC_B.IL_dq_n[0] * rtCP_pooled14) /
    rtCP_pooled13;

  /* Gain: '<S1>/Gain1' */
  rtb_Sum3 *= rtCP_pooled17;

  /* Sum: '<S1>/Sum3' */
  rtb_Sum3 += Off_Grid_Inverter_Control_LC_B.Ec_dq_n[1] - rtb_Saturation;

  /* Product: '<S1>/Divide' incorporates:
   *  Constant: '<S1>/Constant'
   *  Constant: '<S1>/Constant3'
   *  Constant: '<S1>/Constant6'
   */
  Off_Grid_Inverter_Control_LC_B.Uc_dq_n[0] = (((rtb_Sum2 * rtCP_pooled13) *
    rtCP_pooled18) / Off_Grid_Inverter_Control_LC_B.UDC) / rtCP_pooled19;
  Off_Grid_Inverter_Control_LC_B.Uc_dq_n[1] = (((rtb_Sum3 * rtCP_pooled13) *
    rtCP_pooled18) / Off_Grid_Inverter_Control_LC_B.UDC) / rtCP_pooled19;

  /* Gain: '<S8>/Gain2' */
  rtb_Gain2 = rtCP_pooled20 * Off_Grid_Inverter_Control_LC_B.wt;

  /* Outputs for Atomic SubSystem: '<S8>/dq2abc1' */
  dq2abc(Off_Grid_Inverter_Control_LC_B.Uc_dq_n, rtb_Gain2, rtb_Add);

  /* End of Outputs for SubSystem: '<S8>/dq2abc1' */

  /* Sum: '<S8>/Add' */
  rtb_Divide1 = rtb_Add[0];

  /* Sum: '<S8>/Add' */
  rtb_Divide1 += rtb_Gain3[0];

  /* Saturate: '<S8>/Saturation' */
  if (rtb_Divide1 > rtCP_Saturation_UpperSat) {
    /* Saturate: '<S8>/Saturation' */
    rtb_Divide1 = rtCP_Saturation_UpperSat;
  } else if (rtb_Divide1 < rtCP_Saturation_LowerSat) {
    /* Saturate: '<S8>/Saturation' */
    rtb_Divide1 = rtCP_Saturation_LowerSat;
  } else {
    /* no actions */
  }

  /* Saturate: '<S8>/Saturation' */
  Off_Grid_Inverter_Control_LC_B.Mabc[0] = rtb_Divide1;

  /* Outport: '<Root>/M_abc' */
  arg_M_abc[0] = rtb_Divide1;

  /* Sum: '<S8>/Add' */
  rtb_Divide1 = rtb_Add[1];

  /* Sum: '<S8>/Add' */
  rtb_Divide1 += rtb_Gain3[1];

  /* Saturate: '<S8>/Saturation' */
  if (rtb_Divide1 > rtCP_Saturation_UpperSat) {
    /* Saturate: '<S8>/Saturation' */
    rtb_Divide1 = rtCP_Saturation_UpperSat;
  } else if (rtb_Divide1 < rtCP_Saturation_LowerSat) {
    /* Saturate: '<S8>/Saturation' */
    rtb_Divide1 = rtCP_Saturation_LowerSat;
  } else {
    /* no actions */
  }

  /* Saturate: '<S8>/Saturation' */
  Off_Grid_Inverter_Control_LC_B.Mabc[1] = rtb_Divide1;

  /* Outport: '<Root>/M_abc' */
  arg_M_abc[1] = rtb_Divide1;

  /* Sum: '<S8>/Add' */
  rtb_Divide1 = rtb_Add[2];

  /* Sum: '<S8>/Add' */
  rtb_Divide1 += rtb_Gain3[2];

  /* Saturate: '<S8>/Saturation' */
  if (rtb_Divide1 > rtCP_Saturation_UpperSat) {
    /* Saturate: '<S8>/Saturation' */
    rtb_Divide1 = rtCP_Saturation_UpperSat;
  } else if (rtb_Divide1 < rtCP_Saturation_LowerSat) {
    /* Saturate: '<S8>/Saturation' */
    rtb_Divide1 = rtCP_Saturation_LowerSat;
  } else {
    /* no actions */
  }

  /* Saturate: '<S8>/Saturation' */
  Off_Grid_Inverter_Control_LC_B.Mabc[2] = rtb_Divide1;

  /* Outport: '<Root>/M_abc' */
  arg_M_abc[2] = rtb_Divide1;
}

/* Model initialize function */
void Off_Grid_Inverter_Control_LC_initialize(void)
{
  Off_Grid_Inverter_Contr_PrevZCX.PIController1_h.Delay_Reset_ZCE = POS_ZCSIG;
  Off_Grid_Inverter_Contr_PrevZCX.PIController_d.Delay_Reset_ZCE = POS_ZCSIG;
  Off_Grid_Inverter_Contr_PrevZCX.PIController1_i.Delay_Reset_ZCE = POS_ZCSIG;
  Off_Grid_Inverter_Contr_PrevZCX.PIController_h.Delay_Reset_ZCE = POS_ZCSIG;
  Off_Grid_Inverter_Contr_PrevZCX.PIController1_l.Delay_Reset_ZCE = POS_ZCSIG;
  Off_Grid_Inverter_Contr_PrevZCX.PIController.Delay_Reset_ZCE = POS_ZCSIG;
  Off_Grid_Inverter_Contr_PrevZCX.PIController2.Delay_Reset_ZCE = POS_ZCSIG;
  Off_Grid_Inverter_Contr_PrevZCX.PIController1.Delay_Reset_ZCE = POS_ZCSIG;

  /* SystemInitialize for Atomic SubSystem: '<S4>/PI Controller' */
  PI_Controller_Init(&Off_Grid_Inverter_Control_LC_DW.PIController_d);

  /* End of SystemInitialize for SubSystem: '<S4>/PI Controller' */

  /* SystemInitialize for Atomic SubSystem: '<S3>/PI Controller' */
  PI_Controller_Init(&Off_Grid_Inverter_Control_LC_DW.PIController_h);

  /* End of SystemInitialize for SubSystem: '<S3>/PI Controller' */

  /* SystemInitialize for Atomic SubSystem: '<S4>/PI Controller1' */
  PI_Controller_Init(&Off_Grid_Inverter_Control_LC_DW.PIController1_h);

  /* End of SystemInitialize for SubSystem: '<S4>/PI Controller1' */

  /* SystemInitialize for Atomic SubSystem: '<S3>/PI Controller1' */
  PI_Controller_Init(&Off_Grid_Inverter_Control_LC_DW.PIController1_i);

  /* End of SystemInitialize for SubSystem: '<S3>/PI Controller1' */

  /* SystemInitialize for Atomic SubSystem: '<S2>/PI Controller' */
  PI_Controller_Init(&Off_Grid_Inverter_Control_LC_DW.PIController);

  /* End of SystemInitialize for SubSystem: '<S2>/PI Controller' */

  /* SystemInitialize for Atomic SubSystem: '<S1>/PI Controller1' */
  PI_Controller_Init(&Off_Grid_Inverter_Control_LC_DW.PIController1);

  /* End of SystemInitialize for SubSystem: '<S1>/PI Controller1' */

  /* SystemInitialize for Atomic SubSystem: '<S2>/PI Controller1' */
  PI_Controller_Init(&Off_Grid_Inverter_Control_LC_DW.PIController1_l);

  /* End of SystemInitialize for SubSystem: '<S2>/PI Controller1' */

  /* SystemInitialize for Atomic SubSystem: '<S1>/PI Controller2' */
  PI_Controller_Init(&Off_Grid_Inverter_Control_LC_DW.PIController2);

  /* End of SystemInitialize for SubSystem: '<S1>/PI Controller2' */
}

/* Model terminate function */
void Off_Grid_Inverter_Control_LC_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
