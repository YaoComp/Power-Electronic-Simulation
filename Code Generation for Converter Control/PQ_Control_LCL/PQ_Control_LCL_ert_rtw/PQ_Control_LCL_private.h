/*
 * File: PQ_Control_LCL_private.h
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

#ifndef RTW_HEADER_PQ_Control_LCL_private_h_
#define RTW_HEADER_PQ_Control_LCL_private_h_
#include <stdbool.h>
#include <stdint.h>
#include "complex_types.h"
#include "zero_crossing_types.h"
#include "PQ_Control_LCL.h"
#include "PQ_Control_LCL_types.h"

/* Variable: Ts_Control
 * Referenced by:
 *   '<Root>/DSRF-PLL'
 *   '<S4>/PI Controller1'
 *   '<S4>/PI Controller2'
 *   '<S6>/PI Controller'
 *   '<S6>/PI Controller1'
 */
#define rtCP_pooled1                   (6.25E-5F)

/* Pooled Parameter (Mixed Expressions)
 * Referenced by:
 *   '<S4>/PI Controller1'
 *   '<S4>/PI Controller2'
 *   '<S6>/PI Controller'
 *   '<S6>/PI Controller1'
 */
#define rtCP_pooled2                   (2.0F)

/* Pooled Parameter (Mixed Expressions)
 * Referenced by:
 *   '<S4>/PI Controller1'
 *   '<S4>/PI Controller2'
 *   '<S6>/PI Controller'
 *   '<S6>/PI Controller1'
 */
#define rtCP_pooled3                   (-2.0F)

/* Mask Parameter: IntegratorwithWrappedState1_rtw
 * Referenced by: '<S1>/Integrator with Wrapped State1'
 */
#define rtCP_IntegratorwithWrappedSta_o (6.28318548F)

/* Mask Parameter: PIController_rtw_collapsed_sub_
 * Referenced by: '<S1>/PI Controller'
 */
#define rtCP_PIController_rtw_collapsed (222.0F)

/* Mask Parameter: PIController_rtw_collapsed_su_o
 * Referenced by: '<S1>/PI Controller'
 */
#define rtCP_PIController_rtw_collaps_l (628.318542F)

/* Mask Parameter: PIController_rtw_collapsed_su_g
 * Referenced by: '<S1>/PI Controller'
 */
#define rtCP_PIController_rtw_collap_ln (-628.318542F)

/* Mask Parameter: PIController_rtw_collapsed_su_e
 * Referenced by: '<S1>/PI Controller'
 */
#define rtCP_PIController_rtw_collaps_n (24689.1484F)

/* Mask Parameter: IntegratorwithWrappedState1_r_p
 * Referenced by: '<S1>/Integrator with Wrapped State1'
 */
#define rtCP_IntegratorwithWrappedState (0.0F)

/* Pooled Parameter (Mixed Expressions)
 * Referenced by:
 *   '<S1>/Memory'
 *   '<S1>/Memory1'
 *   '<S1>/Memory2'
 *   '<S5>/Constant'
 *   '<S7>/Zero'
 *   '<S7>/Delay1'
 *   '<S12>/Delay'
 *   '<S13>/Delay'
 *   '<S14>/Integrator'
 *   '<S34>/Constant'
 *   '<S35>/Constant'
 *   '<S21>/Delay'
 *   '<S25>/Delay'
 *   '<S26>/Delay'
 *   '<S29>/Delay'
 *   '<S30>/Delay'
 */
#define rtCP_pooled4                   (0.0F)

/* Pooled Parameter (Expression: Ts*Wc-1)
 * Referenced by:
 *   '<S12>/Gain1'
 *   '<S13>/Gain1'
 */
#define rtCP_pooled5                   (-0.986118078F)

/* Pooled Parameter (Expression: Ts*Wc)
 * Referenced by:
 *   '<S12>/Gain2'
 *   '<S13>/Gain2'
 */
#define rtCP_pooled6                   (0.0138819125F)

/* Computed Parameter: Integrator_gainval
 * Referenced by: '<S14>/Integrator'
 */
#define rtCP_Integrator_gainval        (6.25E-5F)

/* Pooled Parameter (Expression: 2/3)
 * Referenced by:
 *   '<S16>/Gain1'
 *   '<S31>/Gain1'
 *   '<S43>/Gain1'
 *   '<S45>/Gain1'
 *   '<S47>/Gain1'
 */
#define rtCP_pooled8                   (0.666666687F)

/* Computed Parameter: Constant_Value
 * Referenced by: '<S1>/Constant'
 */
#define rtCP_Constant_Value            (6.28318548F)

/* Computed Parameter: Constant1_Value
 * Referenced by: '<S1>/Constant1'
 */
#define rtCP_Constant1_Value           (50.0F)

/* Computed Parameter: Gain_Gain
 * Referenced by: '<S10>/Gain'
 */
#define rtCP_Gain_Gain                 (2.0F)

/* Pooled Parameter (Expression: -1)
 * Referenced by:
 *   '<S1>/Gain'
 *   '<S8>/Gain2'
 *   '<S9>/Gain'
 */
#define rtCP_pooled9                   (-1.0F)

/* Computed Parameter: Gain_Gain_m
 * Referenced by: '<S11>/Gain'
 */
#define rtCP_Gain_Gain_m               (-2.0F)

/* Computed Parameter: Gain_Gain_e
 * Referenced by: '<S2>/Gain'
 */
#define rtCP_Gain_Gain_e               (0.333333343F)

/* Pooled Parameter (Expression: 1/2)
 * Referenced by:
 *   '<S7>/Gain1'
 *   '<S22>/Gain'
 */
#define rtCP_pooled10                  (0.5F)

/* Computed Parameter: Constant_Value_k
 * Referenced by: '<Root>/Constant'
 */
#define rtCP_Constant_Value_k          (1.41421354F)

/* Computed Parameter: Constant1_Value_l
 * Referenced by: '<Root>/Constant1'
 */
#define rtCP_Constant1_Value_l         (3.0F)

/* Pooled Parameter (Expression: 2*pi*Fnom_Grid*L_grid)
 * Referenced by:
 *   '<S4>/Gain'
 *   '<S4>/Gain1'
 *   '<S6>/Gain'
 *   '<S6>/Gain1'
 */
#define rtCP_pooled12                  (0.0628318563F)

/* Computed Parameter: Gain2_Gain
 * Referenced by: '<S6>/Gain2'
 */
#define rtCP_Gain2_Gain                (1.0F)

/* Pooled Parameter (Expression: 2*sqrt(2))
 * Referenced by:
 *   '<S4>/Constant'
 *   '<S6>/Constant'
 */
#define rtCP_pooled13                  (2.82842708F)

/* Computed Parameter: Saturation_UpperSat
 * Referenced by: '<S8>/Saturation'
 */
#define rtCP_Saturation_UpperSat       (1.15F)

/* Computed Parameter: Saturation_LowerSat
 * Referenced by: '<S8>/Saturation'
 */
#define rtCP_Saturation_LowerSat       (-1.15F)

/* Expression: Modulation
 * Referenced by: '<S3>/Constant'
 */
#define rtCP_Constant_Value_j          (2U)

/* Computed Parameter: Zero_Value
 * Referenced by: '<S1>/Zero'
 */
#define rtCP_Zero_Value                (false)

extern void DiscretedFirstOrderLowPassFilte(float rtu_u, float rtu_u_i, float
  rty_y[2], FuncInternalData0_DiscretedFi_T *PQ_Control_LCL_FuncGroup0);
extern void Wrapped_Integrator_Update(float rtu_u,
  FuncInternalData0_Wrapped_Int_T *PQ_Control_LCL_FuncGroup0);
extern void Wrapped_Integrator(float *rty_y, float rtp_WrappedStateLowerValue,
  float rtp_WrappedStateUpperValue, FuncInternalData0_Wrapped_Int_T
  *PQ_Control_LCL_FuncGroup0);
extern void PI_Controller_Init(FuncInternalData0_PI_Controll_T
  *PQ_Control_LCL_FuncGroup0);
extern float PI_Controller(float rtu_Error, bool rtu_Reset, float rtp_Kp, float
  rtp_Ts, float rtp_Max, float rtp_Min, float rtp_Ki,
  FuncInternalData0_PI_Controll_T *PQ_Control_LCL_FuncGroup0);
extern void abc2AlphaBetaZero(const float rtu_abc[3], float rty_u[3]);
extern void AlphaBeta2dq(const float rtu_u[2], float rtu_wt, float *rty_dq,
  float *rty_dq_o);
extern void DSRF_PLL_Init(FuncInternalData0_DSRF_PLL_T
  *PQ_Control_LCL_FuncGroup0);
extern void DSRF_PLL(const float rtu_ABC[3], float *rty_Frequency, float *rty_wt,
                     float rty_dq_p[2], float rty_dq_n[2], float rtp_Ts,
                     FuncInternalData0_DSRF_PLL_T *PQ_Control_LCL_FuncGroup0);
extern void Line2Phase_Voltage_Conversion(const float rtu_PhasePhase[3], float
  rty_PhaseGround[3]);
extern void AlphaBetaZero2abc(float rtu_u, float rtu_u_p, float rtu_u_b, float
  rty_abc[3]);
extern void Sequency_Separator(const float rtu_Input_abc[3], float
  rty_Outout_Positive[3], float rty_Outout_negetive[3],
  FuncInternalData0_Sequency_Se_T *PQ_Control_LCL_FuncGroup0);
extern void dq2AlphaBeta(const float rtu_dq[2], float rtu_wt, float *rty_u,
  float *rty_u_n);
extern void dq2abc(const float rtu_dq[2], float rtu_wt, float rty_abc[3]);
extern void abc2dq(const float rtu_abc[3], float rtu_wt, float rty_dq[2]);

#endif                                /* RTW_HEADER_PQ_Control_LCL_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
