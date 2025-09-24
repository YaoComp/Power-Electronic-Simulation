/*
 * File: PQ_Control_LCL.c
 *
 * Code generated for Simulink model 'PQ_Control_LCL'.
 *
 * Model version                  : 1.88
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Mon Apr 28 19:35:53 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives:
 *    1. MISRA C:2012 guidelines
 *    2. Safety precaution
 *    3. Traceability
 * Validation result: Passed (21), Warning (1), Error (0)
 */

#include "PQ_Control_LCL.h"
#include <stdbool.h>
#include "PQ_Control_LCL_private.h"
#include <stdint.h>
#include <math.h>
#include "zero_crossing_types.h"

/* Internal Data Grouped For Same Function */
FuncInternalData0_PQ_Control__T PQ_Control_LC_FuncInternalData0;

/* Real-time model */
static RT_MODEL_PQ_Control_LCL_T PQ_Control_LCL_M_;
RT_MODEL_PQ_Control_LCL_T *const PQ_Control_LCL_M = &PQ_Control_LCL_M_;

/*
 * Output and update for atomic system:
 *    '<S1>/Discreted First Order Low-Pass Filter'
 *    '<S1>/Discreted First Order Low-Pass Filter1'
 */
void DiscretedFirstOrderLowPassFilte(float rtu_u, float rtu_u_i, float rty_y[2],
  FuncInternalData0_DiscretedFi_T *PQ_Control_LCL_FuncGroup0)
{
  float rtb_Add3_c_idx_0;
  float rtb_Gain1_k_idx_0;
  float rtb_Gain1_k_idx_1;

  /* Delay: '<S12>/Delay' */
  rtb_Add3_c_idx_0 = PQ_Control_LCL_FuncGroup0->Delay_DSTATE[0];

  /* Gain: '<S12>/Gain1' */
  rtb_Gain1_k_idx_0 = rtCP_pooled5 * rtb_Add3_c_idx_0;

  /* Gain: '<S12>/Gain2' */
  rtb_Add3_c_idx_0 *= rtCP_pooled6;
  rty_y[0] = rtb_Add3_c_idx_0;

  /* Delay: '<S12>/Delay' */
  rtb_Add3_c_idx_0 = PQ_Control_LCL_FuncGroup0->Delay_DSTATE[1];

  /* Gain: '<S12>/Gain1' */
  rtb_Gain1_k_idx_1 = rtCP_pooled5 * rtb_Add3_c_idx_0;

  /* Gain: '<S12>/Gain2' */
  rtb_Add3_c_idx_0 *= rtCP_pooled6;
  rty_y[1] = rtb_Add3_c_idx_0;

  /* Sum: '<S12>/Add3' */
  rtb_Add3_c_idx_0 = rtu_u - rtb_Gain1_k_idx_0;
  rtb_Gain1_k_idx_1 = rtu_u_i - rtb_Gain1_k_idx_1;

  /* Update for Delay: '<S12>/Delay' */
  PQ_Control_LCL_FuncGroup0->Delay_DSTATE[0] = rtb_Add3_c_idx_0;
  PQ_Control_LCL_FuncGroup0->Delay_DSTATE[1] = rtb_Gain1_k_idx_1;
}

/* Outputs for atomic system: '<S1>/Integrator with Wrapped State1' */
void Wrapped_Integrator(float *rty_y, float rtp_WrappedStateLowerValue, float
  rtp_WrappedStateUpperValue, FuncInternalData0_Wrapped_Int_T
  *PQ_Control_LCL_FuncGroup0)
{
  bool rtb_Compare;
  bool rtb_Compare_d;

  /* RelationalOperator: '<S19>/Compare' incorporates:
   *  Constant: '<S19>/Constant'
   */
  rtb_Compare = (PQ_Control_LCL_FuncGroup0->Integrator_DSTATE <
                 rtp_WrappedStateLowerValue);

  /* RelationalOperator: '<S20>/Compare' incorporates:
   *  Constant: '<S20>/Constant'
   */
  rtb_Compare_d = (PQ_Control_LCL_FuncGroup0->Integrator_DSTATE >=
                   rtp_WrappedStateUpperValue);

  /* Logic: '<S14>/Logical Operator' */
  rtb_Compare = (rtb_Compare || rtb_Compare_d);

  /* DiscreteIntegrator: '<S14>/Integrator' */
  if (rtb_Compare) {
    PQ_Control_LCL_FuncGroup0->Integrator_DSTATE = rtCP_pooled4;
  }

  *rty_y = PQ_Control_LCL_FuncGroup0->Integrator_DSTATE;

  /* End of DiscreteIntegrator: '<S14>/Integrator' */
}

/* Update for atomic system: '<S1>/Integrator with Wrapped State1' */
void Wrapped_Integrator_Update(float rtu_u, FuncInternalData0_Wrapped_Int_T
  *PQ_Control_LCL_FuncGroup0)
{
  /* Update for DiscreteIntegrator: '<S14>/Integrator' */
  PQ_Control_LCL_FuncGroup0->Integrator_DSTATE += rtCP_Integrator_gainval *
    rtu_u;
}

/*
 * System initialize for atomic system:
 *    '<S1>/PI Controller'
 *    '<S4>/PI Controller1'
 *    '<S4>/PI Controller2'
 *    '<S6>/PI Controller'
 *    '<S6>/PI Controller1'
 */
void PI_Controller_Init(FuncInternalData0_PI_Controll_T
  *PQ_Control_LCL_FuncGroup0)
{
  /* InitializeConditions for Delay: '<S21>/Delay' */
  PQ_Control_LCL_FuncGroup0->Delay_DSTATE = rtCP_pooled4;
}

/*
 * Output and update for atomic system:
 *    '<S1>/PI Controller'
 *    '<S4>/PI Controller1'
 *    '<S4>/PI Controller2'
 *    '<S6>/PI Controller'
 *    '<S6>/PI Controller1'
 */
float PI_Controller(float rtu_Error, bool rtu_Reset, float rtp_Kp, float rtp_Ts,
                    float rtp_Max, float rtp_Min, float rtp_Ki,
                    FuncInternalData0_PI_Controll_T *PQ_Control_LCL_FuncGroup0)
{
  float rty_Out_0;
  float rtb_Add2_dn;
  float rtb_Delay_o;
  float rtb_Divide2_m;
  bool zcEvent;

  /* Product: '<S15>/Divide' incorporates:
   *  Constant: '<S15>/Constant'
   */
  rtb_Divide2_m = rtp_Kp * rtu_Error;

  /* Delay: '<S21>/Delay' */
  zcEvent = (rtu_Reset && (PQ_Control_LCL_FuncGroup0->Delay_Reset_ZCE !=
              (ZCSigState)POS_ZCSIG));
  if (zcEvent) {
    PQ_Control_LCL_FuncGroup0->Delay_DSTATE = rtCP_pooled4;
  }

  PQ_Control_LCL_FuncGroup0->Delay_Reset_ZCE = rtu_Reset ? ((ZCSigState)1U) :
    ((ZCSigState)0U);
  rtb_Delay_o = PQ_Control_LCL_FuncGroup0->Delay_DSTATE;

  /* End of Delay: '<S21>/Delay' */

  /* Gain: '<S21>/Gain2' */
  rtb_Add2_dn = rtp_Ts * rtb_Delay_o;

  /* Sum: '<S15>/Add' */
  rtb_Divide2_m += rtb_Add2_dn;

  /* Saturate: '<S15>/Saturation' */
  if (rtb_Divide2_m > rtp_Max) {
    rty_Out_0 = rtp_Max;
  } else if (rtb_Divide2_m < rtp_Min) {
    rty_Out_0 = rtp_Min;
  } else {
    rty_Out_0 = rtb_Divide2_m;
  }

  /* End of Saturate: '<S15>/Saturation' */

  /* Sum: '<S15>/Add1' */
  rtb_Divide2_m = rty_Out_0 - rtb_Divide2_m;

  /* Product: '<S15>/Divide1' incorporates:
   *  Constant: '<S15>/Constant1'
   */
  rtb_Add2_dn = rtu_Error * rtp_Ki;

  /* Product: '<S15>/Divide2' incorporates:
   *  Constant: '<S15>/Constant'
   *  Constant: '<S15>/Constant1'
   */
  rtb_Divide2_m = (rtb_Divide2_m * rtp_Ki) / rtp_Kp;

  /* Sum: '<S15>/Add2' */
  rtb_Add2_dn += rtb_Divide2_m;

  /* Sum: '<S21>/Add3' */
  rtb_Divide2_m = rtb_Add2_dn + rtb_Delay_o;

  /* Update for Delay: '<S21>/Delay' */
  PQ_Control_LCL_FuncGroup0->Delay_DSTATE = rtb_Divide2_m;
  return rty_Out_0;
}

/*
 * Output and update for atomic system:
 *    '<S1>/abc2&#x3B1;&#x3B2;0'
 *    '<S7>/abc2&#x3B1;&#x3B2;0'
 *    '<S40>/abc2&#x3B1;&#x3B2;0'
 *    '<S41>/abc2&#x3B1;&#x3B2;0'
 *    '<S42>/abc2&#x3B1;&#x3B2;0'
 */
void abc2AlphaBetaZero(const float rtu_abc[3], float rty_u[3])
{
  float rtu_abc_0;
  float rtu_abc_1;
  float rtu_abc_2;
  float rty_u_0;
  int16_t i;

  /* Gain: '<S16>/Gain3' */
  rtu_abc_0 = rtu_abc[0];
  rtu_abc_1 = rtu_abc[1];
  rtu_abc_2 = rtu_abc[2];
  for (i = 0; i < 3; i++) {
    rty_u_0 = PQ_Control_LCL_ConstP.pooled7[i] * rtu_abc_0;
    rty_u_0 += PQ_Control_LCL_ConstP.pooled7[i + 3] * rtu_abc_1;
    rty_u_0 += PQ_Control_LCL_ConstP.pooled7[i + 6] * rtu_abc_2;

    /* Gain: '<S16>/Gain1' */
    rty_u_0 *= rtCP_pooled8;
    rty_u[i] = rty_u_0;
  }

  /* End of Gain: '<S16>/Gain3' */
}

/*
 * Output and update for atomic system:
 *    '<S1>/&#x3B1;&#x3B2;2dq'
 *    '<S1>/&#x3B1;&#x3B2;2dq1'
 *    '<S40>/&#x3B1;&#x3B2;2dq'
 *    '<S41>/&#x3B1;&#x3B2;2dq'
 *    '<S42>/&#x3B1;&#x3B2;2dq'
 */
void AlphaBeta2dq(const float rtu_u[2], float rtu_wt, float *rty_dq, float
                  *rty_dq_o)
{
  float tmp;
  float tmp_0;

  /* Fcn: '<S17>/Fcn' incorporates:
   *  Fcn: '<S17>/Fcn1'
   */
  tmp = sinf(rtu_wt);
  tmp_0 = cosf(rtu_wt);
  *rty_dq = (rtu_u[0] * tmp_0) + (rtu_u[1] * tmp);

  /* Fcn: '<S17>/Fcn1' */
  *rty_dq_o = (-rtu_u[0] * tmp) + (rtu_u[1] * tmp_0);
}

/* System initialize for atomic system: '<Root>/DSRF-PLL' */
void DSRF_PLL_Init(FuncInternalData0_DSRF_PLL_T *PQ_Control_LCL_FuncGroup0)
{
  /* SystemInitialize for Atomic SubSystem: '<S1>/PI Controller' */
  PI_Controller_Init(&PQ_Control_LCL_FuncGroup0->FuncInternalData0_PIController);

  /* End of SystemInitialize for SubSystem: '<S1>/PI Controller' */
}

/* Output and update for atomic system: '<Root>/DSRF-PLL' */
void DSRF_PLL(const float rtu_ABC[3], float *rty_Frequency, float *rty_wt, float
              rty_dq_p[2], float rty_dq_n[2], float rtp_Ts,
              FuncInternalData0_DSRF_PLL_T *PQ_Control_LCL_FuncGroup0)
{
  float rtb_Gain1[3];
  float Add;
  float rtb_Add1_j;
  float rtb_Add1_o;
  float rtb_Add_ce;
  float rtb_Add_k;
  float rtb_Divide1;
  float rtb_Divide2_h;
  float rtb_Divide3_i;
  float rtb_Divide_h;
  float rtb_Fcn;
  float rtb_Fcn1;
  float rtb_Gain_d;
  float rtb_Memory;
  float rtb_Memory1_idx_0;
  float rtb_Memory1_idx_1;
  float rtb_Saturation_p;

  /* Fcn: '<S18>/Fcn' incorporates:
   *  Constant: '<S1>/Constant'
   *  Constant: '<S1>/Constant1'
   *  Product: '<S1>/Divide1'
   */
  rtb_Fcn = rtCP_Constant_Value * rtCP_Constant1_Value;

  /* Outputs for Atomic SubSystem: '<S1>/abc2&#x3B1;&#x3B2;0' */
  abc2AlphaBetaZero(rtu_ABC, rtb_Gain1);

  /* End of Outputs for SubSystem: '<S1>/abc2&#x3B1;&#x3B2;0' */

  /* Memory: '<S1>/Memory' */
  rtb_Memory = PQ_Control_LCL_FuncGroup0->Memory_PreviousInput;

  /* Outputs for Atomic SubSystem: '<S1>/&#x3B1;&#x3B2;2dq' */

  /* Gain: '<S16>/Gain1' */
  AlphaBeta2dq(&rtb_Gain1[0], rtb_Memory, &rtb_Fcn1, &rtb_Saturation_p);

  /* End of Outputs for SubSystem: '<S1>/&#x3B1;&#x3B2;2dq' */

  /* Memory: '<S1>/Memory2' */
  rtb_Memory1_idx_0 = PQ_Control_LCL_FuncGroup0->Memory2_PreviousInput[0];
  rtb_Memory1_idx_1 = PQ_Control_LCL_FuncGroup0->Memory2_PreviousInput[1];

  /* Gain: '<S10>/Gain' */
  rtb_Divide1 = rtCP_Gain_Gain * rtb_Memory;

  /* Trigonometry: '<S10>/Cos1' */
  rtb_Divide_h = sinf(rtb_Divide1);

  /* Product: '<S10>/Divide2' */
  rtb_Divide3_i = rtb_Memory1_idx_0 * rtb_Divide_h;

  /* Trigonometry: '<S10>/Cos' */
  rtb_Divide1 = cosf(rtb_Divide1);

  /* Product: '<S10>/Divide3' */
  rtb_Divide2_h = rtb_Memory1_idx_1 * rtb_Divide1;

  /* Sum: '<S10>/Add1' */
  rtb_Add1_j = rtb_Saturation_p + rtb_Divide3_i - rtb_Divide2_h;

  /* Outputs for Atomic SubSystem: '<S1>/PI Controller' */

  /* Constant: '<S1>/Zero' */
  rtb_Saturation_p = PI_Controller(rtb_Add1_j, rtCP_Zero_Value,
    rtCP_PIController_rtw_collapsed, rtp_Ts, rtCP_PIController_rtw_collaps_l,
    rtCP_PIController_rtw_collap_ln, rtCP_PIController_rtw_collaps_n,
    &PQ_Control_LCL_FuncGroup0->FuncInternalData0_PIController);

  /* End of Outputs for SubSystem: '<S1>/PI Controller' */

  /* Sum: '<S1>/Add' */
  Add = rtb_Fcn + rtb_Saturation_p;

  /* Product: '<S10>/Divide' */
  rtb_Divide1 *= rtb_Memory1_idx_0;

  /* Product: '<S10>/Divide1' */
  rtb_Divide_h *= rtb_Memory1_idx_1;

  /* Sum: '<S10>/Add' */
  rtb_Add_ce = rtb_Fcn1 - rtb_Divide1 - rtb_Divide_h;

  /* Gain: '<S1>/Gain' */
  rtb_Gain_d = rtCP_pooled9 * rtb_Memory;

  /* Outputs for Atomic SubSystem: '<S1>/&#x3B1;&#x3B2;2dq1' */

  /* Gain: '<S16>/Gain1' */
  AlphaBeta2dq(&rtb_Gain1[0], rtb_Gain_d, &rtb_Fcn, &rtb_Fcn1);

  /* End of Outputs for SubSystem: '<S1>/&#x3B1;&#x3B2;2dq1' */

  /* Gain: '<S11>/Gain' */
  rtb_Divide2_h = rtCP_Gain_Gain_m * rtb_Gain_d;

  /* Trigonometry: '<S11>/Cos' */
  rtb_Divide3_i = cosf(rtb_Divide2_h);

  /* Memory: '<S1>/Memory1' */
  rtb_Memory1_idx_0 = PQ_Control_LCL_FuncGroup0->Memory1_PreviousInput[0];
  rtb_Memory1_idx_1 = PQ_Control_LCL_FuncGroup0->Memory1_PreviousInput[1];

  /* Product: '<S11>/Divide' */
  rtb_Divide_h = rtb_Divide3_i * rtb_Memory1_idx_0;

  /* Trigonometry: '<S11>/Cos1' */
  rtb_Divide2_h = sinf(rtb_Divide2_h);

  /* Product: '<S11>/Divide1' */
  rtb_Divide1 = rtb_Divide2_h * rtb_Memory1_idx_1;

  /* Sum: '<S11>/Add' */
  rtb_Add_k = rtb_Fcn - rtb_Divide_h + rtb_Divide1;

  /* Product: '<S11>/Divide2' */
  rtb_Divide2_h *= rtb_Memory1_idx_0;

  /* Product: '<S11>/Divide3' */
  rtb_Divide3_i *= rtb_Memory1_idx_1;

  /* Sum: '<S11>/Add1' */
  rtb_Add1_o = rtb_Fcn1 - rtb_Divide2_h - rtb_Divide3_i;

  /* Outputs for Atomic SubSystem: '<S1>/Discreted First Order Low-Pass Filter' */
  DiscretedFirstOrderLowPassFilte(rtb_Add_ce, rtb_Add1_j, rty_dq_p,
    &PQ_Control_LCL_FuncGroup0->FuncInternalData0_DiscretedFi_m);

  /* End of Outputs for SubSystem: '<S1>/Discreted First Order Low-Pass Filter' */

  /* Outputs for Atomic SubSystem: '<S1>/Discreted First Order Low-Pass Filter1' */
  DiscretedFirstOrderLowPassFilte(rtb_Add_k, rtb_Add1_o, rty_dq_n,
    &PQ_Control_LCL_FuncGroup0->FuncInternalData0_DiscretedFir);

  /* End of Outputs for SubSystem: '<S1>/Discreted First Order Low-Pass Filter1' */

  /* Product: '<S1>/Divide' incorporates:
   *  Constant: '<S1>/Constant'
   */
  *rty_Frequency = (1.0F / rtCP_Constant_Value) * Add;

  /* Outputs for Atomic SubSystem: '<S1>/Integrator with Wrapped State1' */
  Wrapped_Integrator(rty_wt, rtCP_IntegratorwithWrappedState,
                     rtCP_IntegratorwithWrappedSta_o,
                     &PQ_Control_LCL_FuncGroup0->FuncInternalData0_Integratorwi);

  /* End of Outputs for SubSystem: '<S1>/Integrator with Wrapped State1' */

  /* Update for Memory: '<S1>/Memory' */
  PQ_Control_LCL_FuncGroup0->Memory_PreviousInput = *rty_wt;

  /* Update for Memory: '<S1>/Memory2' */
  PQ_Control_LCL_FuncGroup0->Memory2_PreviousInput[0] = rty_dq_n[0];

  /* Update for Memory: '<S1>/Memory1' */
  PQ_Control_LCL_FuncGroup0->Memory1_PreviousInput[0] = rty_dq_p[0];

  /* Update for Memory: '<S1>/Memory2' */
  PQ_Control_LCL_FuncGroup0->Memory2_PreviousInput[1] = rty_dq_n[1];

  /* Update for Memory: '<S1>/Memory1' */
  PQ_Control_LCL_FuncGroup0->Memory1_PreviousInput[1] = rty_dq_p[1];

  /* Update for Atomic SubSystem: '<S1>/Integrator with Wrapped State1' */
  Wrapped_Integrator_Update(Add,
    &PQ_Control_LCL_FuncGroup0->FuncInternalData0_Integratorwi);

  /* End of Update for SubSystem: '<S1>/Integrator with Wrapped State1' */
}

/* Output and update for atomic system: '<Root>/Line2Phase_Voltage_Conversion' */
void Line2Phase_Voltage_Conversion(const float rtu_PhasePhase[3], float
  rty_PhaseGround[3])
{
  float rtb_Add1_p;
  float rtb_Add2;
  float rtb_Add_m;

  /* Gain: '<S2>/Gain' */
  rty_PhaseGround[0] = rtCP_Gain_Gain_e * rtu_PhasePhase[0];
  rty_PhaseGround[1] = rtCP_Gain_Gain_e * rtu_PhasePhase[1];
  rty_PhaseGround[2] = rtCP_Gain_Gain_e * rtu_PhasePhase[2];

  /* Sum: '<S2>/Add' */
  rtb_Add_m = rty_PhaseGround[1] - rty_PhaseGround[0];

  /* Sum: '<S2>/Add1' */
  rtb_Add1_p = rty_PhaseGround[0] - rty_PhaseGround[2];

  /* Sum: '<S2>/Add2' */
  rtb_Add2 = rty_PhaseGround[2] - rty_PhaseGround[1];

  /* SignalConversion: '<S2>/Signal Conversion' */
  rty_PhaseGround[0] = rtb_Add1_p;
  rty_PhaseGround[1] = rtb_Add_m;
  rty_PhaseGround[2] = rtb_Add2;
}

/*
 * Output and update for atomic system:
 *    '<S7>/&#x3B1;&#x3B2;02abc'
 *    '<S7>/&#x3B1;&#x3B2;02abc1'
 *    '<S34>/&#x3B1;&#x3B2;02abc'
 *    '<S35>/&#x3B1;&#x3B2;02abc'
 */
void AlphaBetaZero2abc(float rtu_u, float rtu_u_p, float rtu_u_b, float rty_abc
  [3])
{
  float rty_abc_0;
  int16_t i;

  /* Gain: '<S32>/Gain3' */
  for (i = 0; i < 3; i++) {
    rty_abc_0 = PQ_Control_LCL_ConstP.pooled11[i] * rtu_u;
    rty_abc_0 += PQ_Control_LCL_ConstP.pooled11[i + 3] * rtu_u_p;
    rty_abc_0 += PQ_Control_LCL_ConstP.pooled11[i + 6] * rtu_u_b;
    rty_abc[i] = rty_abc_0;
  }

  /* End of Gain: '<S32>/Gain3' */
}

/* Output and update for atomic system: '<Root>/Sequency_Separator1' */
void Sequency_Separator(const float rtu_Input_abc[3], float rty_Outout_Positive
  [3], float rty_Outout_negetive[3], FuncInternalData0_Sequency_Se_T
  *PQ_Control_LCL_FuncGroup0)
{
  float rtb_Gain1[3];
  float rtb_Gain1_g[3];
  float rtb_Add1_e;
  float rtb_Add2;
  float rtb_Add3;
  float rtb_Add4;
  float rtb_Delay1_idx_0;
  float rtb_Delay1_idx_1;
  int16_t Delay1_tmp;
  int16_t idxDelay;

  /* Gain: '<S7>/Gain1' */
  rtb_Gain1[0] = rtCP_pooled10 * rtu_Input_abc[0];
  rtb_Gain1[1] = rtCP_pooled10 * rtu_Input_abc[1];
  rtb_Gain1[2] = rtCP_pooled10 * rtu_Input_abc[2];

  /* Outputs for Atomic SubSystem: '<S7>/abc2&#x3B1;&#x3B2;0' */
  abc2AlphaBetaZero(rtb_Gain1, rtb_Gain1_g);

  /* End of Outputs for SubSystem: '<S7>/abc2&#x3B1;&#x3B2;0' */

  /* Delay: '<S7>/Delay1' */
  rtb_Delay1_idx_0 = PQ_Control_LCL_FuncGroup0->Delay1[0];
  rtb_Delay1_idx_1 = PQ_Control_LCL_FuncGroup0->Delay1[1];

  /* Sum: '<S7>/Add1' */
  rtb_Add1_e = rtb_Gain1_g[0] - rtb_Delay1_idx_1;

  /* Sum: '<S7>/Add2' */
  rtb_Add2 = rtb_Delay1_idx_0 + rtb_Gain1_g[1];

  /* Sum: '<S7>/Add3' */
  rtb_Add3 = rtb_Gain1_g[0] + rtb_Delay1_idx_1;

  /* Sum: '<S7>/Add4' */
  rtb_Add4 = rtb_Gain1_g[1] - rtb_Delay1_idx_0;

  /* Outputs for Atomic SubSystem: '<S7>/&#x3B1;&#x3B2;02abc' */
  /* Constant: '<S7>/Zero' */
  AlphaBetaZero2abc(rtb_Add1_e, rtb_Add2, rtCP_pooled4, rty_Outout_Positive);

  /* End of Outputs for SubSystem: '<S7>/&#x3B1;&#x3B2;02abc' */

  /* Outputs for Atomic SubSystem: '<S7>/&#x3B1;&#x3B2;02abc1' */
  AlphaBetaZero2abc(rtb_Add3, rtb_Add4, rtCP_pooled4, rty_Outout_negetive);

  /* End of Outputs for SubSystem: '<S7>/&#x3B1;&#x3B2;02abc1' */

  /* Update for Delay: '<S7>/Delay1' */
  for (idxDelay = 0; idxDelay < 79; idxDelay++) {
    Delay1_tmp = (idxDelay + 1) * 2;
    PQ_Control_LCL_FuncGroup0->Delay1[idxDelay * 2] =
      PQ_Control_LCL_FuncGroup0->Delay1[Delay1_tmp];
    PQ_Control_LCL_FuncGroup0->Delay1[(idxDelay * 2) + 1] =
      PQ_Control_LCL_FuncGroup0->Delay1[Delay1_tmp + 1];
  }

  PQ_Control_LCL_FuncGroup0->Delay1[158] = rtb_Gain1_g[0];
  PQ_Control_LCL_FuncGroup0->Delay1[159] = rtb_Gain1_g[1];

  /* End of Update for Delay: '<S7>/Delay1' */
}

/*
 * Output and update for atomic system:
 *    '<S34>/dq2&#x3B1;&#x3B2;0'
 *    '<S35>/dq2&#x3B1;&#x3B2;0'
 */
void dq2AlphaBeta(const float rtu_dq[2], float rtu_wt, float *rty_u, float
                  *rty_u_n)
{
  float tmp;
  float tmp_0;

  /* Fcn: '<S36>/Fcn' incorporates:
   *  Fcn: '<S36>/Fcn1'
   */
  tmp = sinf(rtu_wt);
  tmp_0 = cosf(rtu_wt);
  *rty_u = (rtu_dq[0] * tmp_0) - (rtu_dq[1] * tmp);

  /* Fcn: '<S36>/Fcn1' */
  *rty_u_n = (rtu_dq[0] * tmp) + (rtu_dq[1] * tmp_0);
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

  /* Outputs for Atomic SubSystem: '<S34>/dq2&#x3B1;&#x3B2;0' */
  dq2AlphaBeta(rtu_dq, rtu_wt, &rtb_Fcn, &rtb_Fcn1);

  /* End of Outputs for SubSystem: '<S34>/dq2&#x3B1;&#x3B2;0' */

  /* Outputs for Atomic SubSystem: '<S34>/&#x3B1;&#x3B2;02abc' */

  /* Constant: '<S34>/Constant' */
  AlphaBetaZero2abc(rtb_Fcn, rtb_Fcn1, rtCP_pooled4, rty_abc);

  /* End of Outputs for SubSystem: '<S34>/&#x3B1;&#x3B2;02abc' */
}

/*
 * Output and update for atomic system:
 *    '<S9>/abc2dq1'
 *    '<S9>/abc2dq2'
 *    '<S9>/abc2dq3'
 */
void abc2dq(const float rtu_abc[3], float rtu_wt, float rty_dq[2])
{
  float rtb_Gain1[3];
  float rtb_Fcn;
  float rtb_Fcn1;

  /* Outputs for Atomic SubSystem: '<S40>/abc2&#x3B1;&#x3B2;0' */
  abc2AlphaBetaZero(rtu_abc, rtb_Gain1);

  /* End of Outputs for SubSystem: '<S40>/abc2&#x3B1;&#x3B2;0' */

  /* Outputs for Atomic SubSystem: '<S40>/&#x3B1;&#x3B2;2dq' */

  /* Gain: '<S43>/Gain1' */
  AlphaBeta2dq(&rtb_Gain1[0], rtu_wt, &rtb_Fcn, &rtb_Fcn1);

  /* End of Outputs for SubSystem: '<S40>/&#x3B1;&#x3B2;2dq' */

  /* SignalConversion: '<S40>/Signal Conversion' */
  rty_dq[0] = rtb_Fcn;
  rty_dq[1] = rtb_Fcn1;
}

/* Model step function */
void PQ_Control_Step(float arg_Mabc1[3], const float arg_PQ_Ref1[2], const float
                     *arg_Udc1, const float arg_If_abc1[3], const float
                     arg_Ic_abc1[3], const float arg_Ec_abc1[3], const bool
                     *arg_Reset1)
{
  float rtb_Add_i[3];
  float rtb_Gain3[3];
  float rtb_Gain3_c[3];
  float rtb_Gain3_p[3];
  float rtb_If_ABC[3];
  float rtb_SignalConversion_m[3];
  float rtb_Gain2_aq[2];
  float rtb_Gain2_b[2];
  float rtb_Gain2_h[2];
  float rtb_SignalConversion[2];
  float rtb_SignalConversion_d[2];
  float Integrator;
  float rtb_Divide;
  float rtb_Divide2;
  float rtb_Divide2_e;
  float rtb_Divide3;
  float rtb_Divide4;
  float rtb_Gain2;
  float rtb_Negetive_wt;
  float rtb_Saturation_2;
  float rtb_Saturation_idx_0;
  float rtb_Saturation_idx_1;
  float rtb_Saturation_idx_2;
  float rtb_Saturation_n;
  float rtb_Sum2;
  float rtb_Sum3;

  /* Product: '<Root>/Divide' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Constant3'
   *  Inport: '<Root>/Ec_abc'
   */
  PQ_Control_LC_FuncInternalData0.Ec_ABC_Line[0] = (arg_Ec_abc1[0] /
    PQ_Control_LCL_P.Unom_Phase) / rtCP_Constant_Value_k;
  PQ_Control_LC_FuncInternalData0.Ec_ABC_Line[1] = (arg_Ec_abc1[1] /
    PQ_Control_LCL_P.Unom_Phase) / rtCP_Constant_Value_k;
  PQ_Control_LC_FuncInternalData0.Ec_ABC_Line[2] = (arg_Ec_abc1[2] /
    PQ_Control_LCL_P.Unom_Phase) / rtCP_Constant_Value_k;

  /* Outputs for Atomic SubSystem: '<Root>/Line2Phase_Voltage_Conversion' */
  Line2Phase_Voltage_Conversion(PQ_Control_LC_FuncInternalData0.Ec_ABC_Line,
    rtb_SignalConversion_m);

  /* End of Outputs for SubSystem: '<Root>/Line2Phase_Voltage_Conversion' */

  /* SignalConversion generated from: '<Root>/Line2Phase_Voltage_Conversion' */
  PQ_Control_LC_FuncInternalData0.Ec_ABC_Phase[0] = rtb_SignalConversion_m[0];
  PQ_Control_LC_FuncInternalData0.Ec_ABC_Phase[1] = rtb_SignalConversion_m[1];
  PQ_Control_LC_FuncInternalData0.Ec_ABC_Phase[2] = rtb_SignalConversion_m[2];

  /* Outputs for Atomic SubSystem: '<Root>/DSRF-PLL' */
  DSRF_PLL(PQ_Control_LC_FuncInternalData0.Ec_ABC_Phase, &rtb_Divide,
           &Integrator, rtb_Gain2_aq, rtb_Gain2_b, rtCP_pooled1,
           &PQ_Control_LC_FuncInternalData0.FuncInternalData0_DSRFPLL);

  /* End of Outputs for SubSystem: '<Root>/DSRF-PLL' */

  /* SignalConversion generated from: '<Root>/DSRF-PLL' */
  PQ_Control_LC_FuncInternalData0.Ec_dq_p[0] = rtb_Gain2_aq[0];
  PQ_Control_LC_FuncInternalData0.Ec_dq_p[1] = rtb_Gain2_aq[1];

  /* Product: '<Root>/Divide1' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Constant2'
   *  Inport: '<Root>/Ic_abc'
   */
  PQ_Control_LC_FuncInternalData0.Ic_ABC[0] = (arg_Ic_abc1[0] /
    PQ_Control_LCL_P.Inom) / rtCP_Constant_Value_k;
  PQ_Control_LC_FuncInternalData0.Ic_ABC[1] = (arg_Ic_abc1[1] /
    PQ_Control_LCL_P.Inom) / rtCP_Constant_Value_k;
  PQ_Control_LC_FuncInternalData0.Ic_ABC[2] = (arg_Ic_abc1[2] /
    PQ_Control_LCL_P.Inom) / rtCP_Constant_Value_k;

  /* Outputs for Atomic SubSystem: '<Root>/Sequency_Separator1' */
  Sequency_Separator(PQ_Control_LC_FuncInternalData0.Ic_ABC, rtb_Gain3_c,
                     rtb_Gain3_p,
                     &PQ_Control_LC_FuncInternalData0.FuncInternalData0_Sequency_Sep);

  /* End of Outputs for SubSystem: '<Root>/Sequency_Separator1' */

  /* SignalConversion generated from: '<Root>/Sequency_Separator1' */
  PQ_Control_LC_FuncInternalData0.Ic_ABC_p[0] = rtb_Gain3_c[0];
  PQ_Control_LC_FuncInternalData0.Ic_ABC_p[1] = rtb_Gain3_c[1];
  PQ_Control_LC_FuncInternalData0.Ic_ABC_p[2] = rtb_Gain3_c[2];

  /* SignalConversion generated from: '<Root>/DSRF-PLL' */
  PQ_Control_LC_FuncInternalData0.wt = Integrator;

  /* Outputs for Atomic SubSystem: '<S9>/abc2dq1' */
  abc2dq(PQ_Control_LC_FuncInternalData0.Ic_ABC_p,
         PQ_Control_LC_FuncInternalData0.wt, rtb_SignalConversion_d);

  /* End of Outputs for SubSystem: '<S9>/abc2dq1' */

  /* SignalConversion generated from: '<S9>/abc2dq1' */
  PQ_Control_LC_FuncInternalData0.Ic_dq_p[0] = rtb_SignalConversion_d[0];

  /* Product: '<Root>/Divide2' incorporates:
   *  Constant: '<Root>/Constant1'
   *  Constant: '<Root>/Constant4'
   *  Constant: '<Root>/Constant5'
   *  Inport: '<Root>/PQ_Ref'
   */
  rtb_Sum3 = ((arg_PQ_Ref1[0] / PQ_Control_LCL_P.Unom_Phase) /
              PQ_Control_LCL_P.Inom) / rtCP_Constant1_Value_l;
  PQ_Control_LC_FuncInternalData0.PQ_REF[0] = rtb_Sum3;

  /* SignalConversion: '<S5>/Signal Conversion' */
  PQ_Control_LC_FuncInternalData0.Ic_dq_p_ref[0] = rtb_Sum3;

  /* SignalConversion generated from: '<S9>/abc2dq1' */
  PQ_Control_LC_FuncInternalData0.Ic_dq_p[1] = rtb_SignalConversion_d[1];

  /* Product: '<Root>/Divide2' incorporates:
   *  Constant: '<Root>/Constant1'
   *  Constant: '<Root>/Constant4'
   *  Constant: '<Root>/Constant5'
   *  Inport: '<Root>/PQ_Ref'
   */
  rtb_Sum3 = ((arg_PQ_Ref1[1] / PQ_Control_LCL_P.Unom_Phase) /
              PQ_Control_LCL_P.Inom) / rtCP_Constant1_Value_l;
  PQ_Control_LC_FuncInternalData0.PQ_REF[1] = rtb_Sum3;

  /* SignalConversion: '<S5>/Signal Conversion' */
  PQ_Control_LC_FuncInternalData0.Ic_dq_p_ref[1] = rtb_Sum3;

  /* Sum: '<S6>/Sum' */
  rtb_Sum3 = PQ_Control_LC_FuncInternalData0.Ic_dq_p_ref[0] -
    PQ_Control_LC_FuncInternalData0.Ic_dq_p[0];

  /* Product: '<S6>/Divide2' incorporates:
   *  Constant: '<S6>/Constant1'
   *  Constant: '<S6>/Constant2'
   */
  rtb_Divide2 = (rtb_Sum3 * PQ_Control_LCL_P.Inom) / PQ_Control_LCL_P.Unom_Phase;

  /* Outputs for Atomic SubSystem: '<S6>/PI Controller' */
  /* Inport: '<Root>/Reset' */
  rtb_Saturation_n = PI_Controller(rtb_Divide2, *arg_Reset1,
    PQ_Control_LCL_P.Kp_Idq, rtCP_pooled1, rtCP_pooled2, rtCP_pooled3,
    PQ_Control_LCL_P.Ki_Idq,
    &PQ_Control_LC_FuncInternalData0.FuncInternalData0_PIControlle_m);

  /* End of Outputs for SubSystem: '<S6>/PI Controller' */

  /* Product: '<S6>/Divide3' incorporates:
   *  Constant: '<S6>/Constant1'
   *  Constant: '<S6>/Constant2'
   */
  rtb_Sum3 = (PQ_Control_LC_FuncInternalData0.Ic_dq_p[1] * PQ_Control_LCL_P.Inom)
    / PQ_Control_LCL_P.Unom_Phase;

  /* Gain: '<S6>/Gain' */
  rtb_Sum3 *= rtCP_pooled12;

  /* Product: '<Root>/Divide4' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Constant2'
   *  Inport: '<Root>/If_abc'
   */
  rtb_If_ABC[0] = (arg_If_abc1[0] / PQ_Control_LCL_P.Inom) /
    rtCP_Constant_Value_k;
  rtb_If_ABC[1] = (arg_If_abc1[1] / PQ_Control_LCL_P.Inom) /
    rtCP_Constant_Value_k;
  rtb_If_ABC[2] = (arg_If_abc1[2] / PQ_Control_LCL_P.Inom) /
    rtCP_Constant_Value_k;

  /* Outputs for Atomic SubSystem: '<S9>/abc2dq3' */
  abc2dq(rtb_If_ABC, PQ_Control_LC_FuncInternalData0.wt, rtb_Gain2_h);

  /* End of Outputs for SubSystem: '<S9>/abc2dq3' */

  /* Gain: '<S6>/Gain2' */
  rtb_Gain2_h[0] *= rtCP_Gain2_Gain;
  rtb_Gain2_h[1] *= rtCP_Gain2_Gain;

  /* Sum: '<S6>/Sum2' */
  rtb_Sum3 = PQ_Control_LC_FuncInternalData0.Ec_dq_p[0] - rtb_Saturation_n +
    rtb_Sum3 - rtb_Gain2_h[0];

  /* Sum: '<S6>/Sum1' */
  rtb_Sum2 = PQ_Control_LC_FuncInternalData0.Ic_dq_p_ref[1] -
    PQ_Control_LC_FuncInternalData0.Ic_dq_p[1];

  /* Product: '<S6>/Divide4' incorporates:
   *  Constant: '<S6>/Constant1'
   *  Constant: '<S6>/Constant2'
   */
  rtb_Divide4 = (rtb_Sum2 * PQ_Control_LCL_P.Inom) / PQ_Control_LCL_P.Unom_Phase;

  /* Outputs for Atomic SubSystem: '<S6>/PI Controller1' */
  /* Inport: '<Root>/Reset' */
  rtb_Saturation_n = PI_Controller(rtb_Divide4, *arg_Reset1,
    PQ_Control_LCL_P.Kp_Idq, rtCP_pooled1, rtCP_pooled2, rtCP_pooled3,
    PQ_Control_LCL_P.Ki_Idq,
    &PQ_Control_LC_FuncInternalData0.FuncInternalData0_PIController);

  /* End of Outputs for SubSystem: '<S6>/PI Controller1' */

  /* Product: '<S6>/Divide5' incorporates:
   *  Constant: '<S6>/Constant1'
   *  Constant: '<S6>/Constant2'
   */
  rtb_Sum2 = (PQ_Control_LC_FuncInternalData0.Ic_dq_p[0] * PQ_Control_LCL_P.Inom)
    / PQ_Control_LCL_P.Unom_Phase;

  /* Gain: '<S6>/Gain1' */
  rtb_Sum2 *= rtCP_pooled12;

  /* Sum: '<S6>/Sum3' */
  rtb_Sum2 = PQ_Control_LC_FuncInternalData0.Ec_dq_p[1] - rtb_Saturation_n -
    rtb_Sum2 - rtb_Gain2_h[1];

  /* Product: '<Root>/Divide3' incorporates:
   *  Constant: '<Root>/Constant6'
   *  Inport: '<Root>/Udc'
   */
  PQ_Control_LC_FuncInternalData0.UDC = *arg_Udc1 / PQ_Control_LCL_P.Udc_ref;

  /* Product: '<S6>/Divide' incorporates:
   *  Constant: '<S6>/Constant'
   *  Constant: '<S6>/Constant3'
   *  Constant: '<S6>/Constant6'
   */
  PQ_Control_LC_FuncInternalData0.Uc_dq_p[0] = (((rtb_Sum3 *
    PQ_Control_LCL_P.Unom_Phase) * rtCP_pooled13) /
    PQ_Control_LC_FuncInternalData0.UDC) / PQ_Control_LCL_P.Udc_ref;
  PQ_Control_LC_FuncInternalData0.Uc_dq_p[1] = (((rtb_Sum2 *
    PQ_Control_LCL_P.Unom_Phase) * rtCP_pooled13) /
    PQ_Control_LC_FuncInternalData0.UDC) / PQ_Control_LCL_P.Udc_ref;

  /* Outputs for Atomic SubSystem: '<S8>/dq2abc' */
  dq2abc(PQ_Control_LC_FuncInternalData0.Uc_dq_p,
         PQ_Control_LC_FuncInternalData0.wt, rtb_Gain3);

  /* End of Outputs for SubSystem: '<S8>/dq2abc' */

  /* SignalConversion generated from: '<Root>/DSRF-PLL' */
  PQ_Control_LC_FuncInternalData0.Ec_dq_n[0] = rtb_Gain2_b[0];
  PQ_Control_LC_FuncInternalData0.Ec_dq_n[1] = rtb_Gain2_b[1];

  /* SignalConversion generated from: '<Root>/Sequency_Separator1' */
  PQ_Control_LC_FuncInternalData0.Ic_ABC_n[0] = rtb_Gain3_p[0];
  PQ_Control_LC_FuncInternalData0.Ic_ABC_n[1] = rtb_Gain3_p[1];
  PQ_Control_LC_FuncInternalData0.Ic_ABC_n[2] = rtb_Gain3_p[2];

  /* Gain: '<S9>/Gain' */
  rtb_Negetive_wt = rtCP_pooled9 * PQ_Control_LC_FuncInternalData0.wt;

  /* Outputs for Atomic SubSystem: '<S9>/abc2dq2' */
  abc2dq(PQ_Control_LC_FuncInternalData0.Ic_ABC_n, rtb_Negetive_wt,
         rtb_SignalConversion);

  /* End of Outputs for SubSystem: '<S9>/abc2dq2' */

  /* SignalConversion generated from: '<S9>/abc2dq2' */
  PQ_Control_LC_FuncInternalData0.Ic_dq_n[0] = rtb_SignalConversion[0];
  PQ_Control_LC_FuncInternalData0.Ic_dq_n[1] = rtb_SignalConversion[1];

  /* SignalConversion: '<S5>/Signal Conversion1' incorporates:
   *  Constant: '<S5>/Constant'
   */
  PQ_Control_LC_FuncInternalData0.Ic_dq_n_ref[0] = rtCP_pooled4;
  PQ_Control_LC_FuncInternalData0.Ic_dq_n_ref[1] = rtCP_pooled4;

  /* Sum: '<S4>/Sum' */
  rtb_Sum2 = PQ_Control_LC_FuncInternalData0.Ic_dq_n_ref[0] -
    PQ_Control_LC_FuncInternalData0.Ic_dq_n[0];

  /* Product: '<S4>/Divide2' incorporates:
   *  Constant: '<S4>/Constant1'
   *  Constant: '<S4>/Constant2'
   */
  rtb_Divide2_e = (rtb_Sum2 * PQ_Control_LCL_P.Inom) /
    PQ_Control_LCL_P.Unom_Phase;

  /* Outputs for Atomic SubSystem: '<S4>/PI Controller1' */
  /* Inport: '<Root>/Reset' */
  rtb_Saturation_n = PI_Controller(rtb_Divide2_e, *arg_Reset1,
    PQ_Control_LCL_P.Kp_Idq, rtCP_pooled1, rtCP_pooled2, rtCP_pooled3,
    PQ_Control_LCL_P.Ki_Idq,
    &PQ_Control_LC_FuncInternalData0.FuncInternalData0_PIControlle_k);

  /* End of Outputs for SubSystem: '<S4>/PI Controller1' */

  /* Product: '<S4>/Divide1' incorporates:
   *  Constant: '<S4>/Constant1'
   *  Constant: '<S4>/Constant2'
   */
  rtb_Sum2 = (PQ_Control_LC_FuncInternalData0.Ic_dq_n[1] * PQ_Control_LCL_P.Inom)
    / PQ_Control_LCL_P.Unom_Phase;

  /* Gain: '<S4>/Gain' */
  rtb_Sum2 *= rtCP_pooled12;

  /* Sum: '<S4>/Sum2' */
  rtb_Sum2 = PQ_Control_LC_FuncInternalData0.Ec_dq_n[0] - rtb_Saturation_n -
    rtb_Sum2;

  /* Sum: '<S4>/Sum1' */
  rtb_Sum3 = PQ_Control_LC_FuncInternalData0.Ic_dq_n_ref[1] -
    PQ_Control_LC_FuncInternalData0.Ic_dq_n[1];

  /* Product: '<S4>/Divide3' incorporates:
   *  Constant: '<S4>/Constant1'
   *  Constant: '<S4>/Constant2'
   */
  rtb_Divide3 = (rtb_Sum3 * PQ_Control_LCL_P.Inom) / PQ_Control_LCL_P.Unom_Phase;

  /* Outputs for Atomic SubSystem: '<S4>/PI Controller2' */
  /* Inport: '<Root>/Reset' */
  rtb_Saturation_n = PI_Controller(rtb_Divide3, *arg_Reset1,
    PQ_Control_LCL_P.Kp_Idq, rtCP_pooled1, rtCP_pooled2, rtCP_pooled3,
    PQ_Control_LCL_P.Ki_Idq,
    &PQ_Control_LC_FuncInternalData0.FuncInternalData0_PIControlle_c);

  /* End of Outputs for SubSystem: '<S4>/PI Controller2' */

  /* Product: '<S4>/Divide4' incorporates:
   *  Constant: '<S4>/Constant1'
   *  Constant: '<S4>/Constant2'
   */
  rtb_Sum3 = (PQ_Control_LC_FuncInternalData0.Ic_dq_n[0] * PQ_Control_LCL_P.Inom)
    / PQ_Control_LCL_P.Unom_Phase;

  /* Gain: '<S4>/Gain1' */
  rtb_Sum3 *= rtCP_pooled12;

  /* Sum: '<S4>/Sum3' */
  rtb_Sum3 += PQ_Control_LC_FuncInternalData0.Ec_dq_n[1] - rtb_Saturation_n;

  /* Product: '<S4>/Divide' incorporates:
   *  Constant: '<S4>/Constant'
   *  Constant: '<S4>/Constant3'
   *  Constant: '<S4>/Constant6'
   */
  PQ_Control_LC_FuncInternalData0.Uc_dq_n[0] = (((rtb_Sum2 *
    PQ_Control_LCL_P.Unom_Phase) * rtCP_pooled13) /
    PQ_Control_LC_FuncInternalData0.UDC) / PQ_Control_LCL_P.Udc_ref;
  PQ_Control_LC_FuncInternalData0.Uc_dq_n[1] = (((rtb_Sum3 *
    PQ_Control_LCL_P.Unom_Phase) * rtCP_pooled13) /
    PQ_Control_LC_FuncInternalData0.UDC) / PQ_Control_LCL_P.Udc_ref;

  /* Gain: '<S8>/Gain2' */
  rtb_Gain2 = rtCP_pooled9 * PQ_Control_LC_FuncInternalData0.wt;

  /* Outputs for Atomic SubSystem: '<S8>/dq2abc1' */
  dq2abc(PQ_Control_LC_FuncInternalData0.Uc_dq_n, rtb_Gain2, rtb_Add_i);

  /* End of Outputs for SubSystem: '<S8>/dq2abc1' */

  /* Sum: '<S8>/Add' */
  rtb_Saturation_idx_2 = rtb_Add_i[0];

  /* Sum: '<S8>/Add' */
  rtb_Saturation_idx_2 += rtb_Gain3[0];

  /* Saturate: '<S8>/Saturation' */
  if (rtb_Saturation_idx_2 > rtCP_Saturation_UpperSat) {
    rtb_Saturation_idx_0 = rtCP_Saturation_UpperSat;
  } else if (rtb_Saturation_idx_2 < rtCP_Saturation_LowerSat) {
    rtb_Saturation_idx_0 = rtCP_Saturation_LowerSat;
  } else {
    rtb_Saturation_idx_0 = rtb_Saturation_idx_2;
  }

  /* Sum: '<S8>/Add' */
  rtb_Saturation_idx_2 = rtb_Add_i[1];

  /* Sum: '<S8>/Add' */
  rtb_Saturation_idx_2 += rtb_Gain3[1];

  /* Saturate: '<S8>/Saturation' */
  if (rtb_Saturation_idx_2 > rtCP_Saturation_UpperSat) {
    rtb_Saturation_idx_1 = rtCP_Saturation_UpperSat;
  } else if (rtb_Saturation_idx_2 < rtCP_Saturation_LowerSat) {
    rtb_Saturation_idx_1 = rtCP_Saturation_LowerSat;
  } else {
    rtb_Saturation_idx_1 = rtb_Saturation_idx_2;
  }

  /* Sum: '<S8>/Add' */
  rtb_Saturation_idx_2 = rtb_Add_i[2];

  /* Sum: '<S8>/Add' */
  rtb_Saturation_idx_2 += rtb_Gain3[2];

  /* Saturate: '<S8>/Saturation' */
  if (rtb_Saturation_idx_2 > rtCP_Saturation_UpperSat) {
    rtb_Saturation_idx_2 = rtCP_Saturation_UpperSat;
  } else if (rtb_Saturation_idx_2 < rtCP_Saturation_LowerSat) {
    rtb_Saturation_idx_2 = rtCP_Saturation_LowerSat;
  } else {
    /* no actions */
  }

  /* Outputs for Atomic SubSystem: '<Root>/Moduation' */
  /* MultiPortSwitch: '<S3>/Multiport Switch' incorporates:
   *  Constant: '<S3>/Constant'
   */
  if (rtCP_Constant_Value_j == 1U) {
    /* MultiPortSwitch: '<S3>/Multiport Switch' */
    PQ_Control_LC_FuncInternalData0.Mabc[0] = rtb_Saturation_idx_0;
    PQ_Control_LC_FuncInternalData0.Mabc[1] = rtb_Saturation_idx_1;
    PQ_Control_LC_FuncInternalData0.Mabc[2] = rtb_Saturation_idx_2;
  } else {
    /* MinMax: '<S22>/Max1' */
    rtb_Sum3 = rtb_Saturation_idx_0;

    /* MinMax: '<S22>/Max' */
    rtb_Sum2 = rtb_Saturation_idx_0;

    /* MinMax: '<S22>/Max1' */
    rtb_Saturation_2 = rtb_Saturation_idx_1;
    rtb_Sum3 = fminf(rtb_Sum3, rtb_Saturation_2);

    /* MinMax: '<S22>/Max' */
    rtb_Sum2 = fmaxf(rtb_Sum2, rtb_Saturation_2);

    /* MinMax: '<S22>/Max1' */
    rtb_Saturation_2 = rtb_Saturation_idx_2;
    rtb_Sum3 = fminf(rtb_Sum3, rtb_Saturation_2);

    /* MinMax: '<S22>/Max' */
    rtb_Sum2 = fmaxf(rtb_Sum2, rtb_Saturation_2);

    /* Sum: '<S22>/Add' */
    rtb_Sum3 += rtb_Sum2;

    /* Gain: '<S22>/Gain' */
    rtb_Sum3 *= rtCP_pooled10;

    /* Sum: '<S22>/Add1' */
    rtb_Saturation_idx_0 -= rtb_Sum3;

    /* MultiPortSwitch: '<S3>/Multiport Switch' */
    PQ_Control_LC_FuncInternalData0.Mabc[0] = rtb_Saturation_idx_0;

    /* Sum: '<S22>/Add1' */
    rtb_Saturation_idx_0 = rtb_Saturation_idx_1;
    rtb_Saturation_idx_0 -= rtb_Sum3;

    /* MultiPortSwitch: '<S3>/Multiport Switch' */
    PQ_Control_LC_FuncInternalData0.Mabc[1] = rtb_Saturation_idx_0;

    /* Sum: '<S22>/Add1' */
    rtb_Saturation_idx_0 = rtb_Saturation_idx_2;
    rtb_Saturation_idx_0 -= rtb_Sum3;

    /* MultiPortSwitch: '<S3>/Multiport Switch' */
    PQ_Control_LC_FuncInternalData0.Mabc[2] = rtb_Saturation_idx_0;
  }

  /* End of MultiPortSwitch: '<S3>/Multiport Switch' */
  /* End of Outputs for SubSystem: '<Root>/Moduation' */

  /* Outport: '<Root>/Mabc' */
  arg_Mabc1[0] = PQ_Control_LC_FuncInternalData0.Mabc[0];
  arg_Mabc1[1] = PQ_Control_LC_FuncInternalData0.Mabc[1];
  arg_Mabc1[2] = PQ_Control_LC_FuncInternalData0.Mabc[2];
}

/* Model initialize function */
void PQ_Control_Initialize(void)
{
  PQ_Control_LC_FuncInternalData0.FuncInternalData0_PIController.Delay_Reset_ZCE
    = POS_ZCSIG;
  PQ_Control_LC_FuncInternalData0.FuncInternalData0_PIControlle_m.Delay_Reset_ZCE
    = POS_ZCSIG;
  PQ_Control_LC_FuncInternalData0.FuncInternalData0_PIControlle_c.Delay_Reset_ZCE
    = POS_ZCSIG;
  PQ_Control_LC_FuncInternalData0.FuncInternalData0_PIControlle_k.Delay_Reset_ZCE
    = POS_ZCSIG;
  PQ_Control_LC_FuncInternalData0.FuncInternalData0_DSRFPLL.FuncInternalData0_PIController.Delay_Reset_ZCE
    = POS_ZCSIG;

  /* SystemInitialize for Atomic SubSystem: '<Root>/DSRF-PLL' */
  DSRF_PLL_Init(&PQ_Control_LC_FuncInternalData0.FuncInternalData0_DSRFPLL);

  /* End of SystemInitialize for SubSystem: '<Root>/DSRF-PLL' */

  /* SystemInitialize for Atomic SubSystem: '<S6>/PI Controller' */
  PI_Controller_Init
    (&PQ_Control_LC_FuncInternalData0.FuncInternalData0_PIControlle_m);

  /* End of SystemInitialize for SubSystem: '<S6>/PI Controller' */

  /* SystemInitialize for Atomic SubSystem: '<S6>/PI Controller1' */
  PI_Controller_Init
    (&PQ_Control_LC_FuncInternalData0.FuncInternalData0_PIController);

  /* End of SystemInitialize for SubSystem: '<S6>/PI Controller1' */

  /* SystemInitialize for Atomic SubSystem: '<S4>/PI Controller1' */
  PI_Controller_Init
    (&PQ_Control_LC_FuncInternalData0.FuncInternalData0_PIControlle_k);

  /* End of SystemInitialize for SubSystem: '<S4>/PI Controller1' */

  /* SystemInitialize for Atomic SubSystem: '<S4>/PI Controller2' */
  PI_Controller_Init
    (&PQ_Control_LC_FuncInternalData0.FuncInternalData0_PIControlle_c);

  /* End of SystemInitialize for SubSystem: '<S4>/PI Controller2' */
}

/* Model terminate function */
void PQ_Control_Terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
