/*
 * File: Off_Grid_Inverter_Control_LC_private.h
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

#ifndef RTW_HEADER_Off_Grid_Inverter_Control_LC_private_h_
#define RTW_HEADER_Off_Grid_Inverter_Control_LC_private_h_
#include <stdbool.h>
#include <stdint.h>
#include "complex_types.h"
#include "zero_crossing_types.h"
#include "Off_Grid_Inverter_Control_LC.h"
#include "Off_Grid_Inverter_Control_LC_types.h"

/* Variable: Ki_Idq
 * Referenced by:
 *   '<S1>/PI Controller1'
 *   '<S1>/PI Controller2'
 *   '<S3>/PI Controller'
 *   '<S3>/PI Controller1'
 */
#define rtCP_pooled1                   (6.31654692F)

/* Variable: Ki_Phase
 * Referenced by:
 *   '<S2>/PI Controller'
 *   '<S2>/PI Controller1'
 *   '<S4>/PI Controller'
 *   '<S4>/PI Controller1'
 */
#define rtCP_pooled2                   (10.0F)

/* Variable: Kp_Idq
 * Referenced by:
 *   '<S1>/PI Controller1'
 *   '<S1>/PI Controller2'
 *   '<S3>/PI Controller'
 *   '<S3>/PI Controller1'
 */
#define rtCP_pooled3                   (2.0106194F)

/* Variable: Kp_Phase
 * Referenced by:
 *   '<S2>/PI Controller'
 *   '<S2>/PI Controller1'
 *   '<S4>/PI Controller'
 *   '<S4>/PI Controller1'
 */
#define rtCP_pooled4                   (0.21F)

/* Variable: Ts_Control
 * Referenced by:
 *   '<S1>/PI Controller1'
 *   '<S1>/PI Controller2'
 *   '<S2>/PI Controller'
 *   '<S2>/PI Controller1'
 *   '<S3>/PI Controller'
 *   '<S3>/PI Controller1'
 *   '<S4>/PI Controller'
 *   '<S4>/PI Controller1'
 */
#define rtCP_pooled5                   (6.25E-5F)

/* Pooled Parameter (Mixed Expressions)
 * Referenced by:
 *   '<S1>/PI Controller1'
 *   '<S1>/PI Controller2'
 *   '<S2>/PI Controller'
 *   '<S2>/PI Controller1'
 *   '<S3>/PI Controller'
 *   '<S3>/PI Controller1'
 *   '<S4>/PI Controller'
 *   '<S4>/PI Controller1'
 */
#define rtCP_pooled6                   (2.0F)

/* Pooled Parameter (Mixed Expressions)
 * Referenced by:
 *   '<S1>/PI Controller1'
 *   '<S1>/PI Controller2'
 *   '<S2>/PI Controller'
 *   '<S2>/PI Controller1'
 *   '<S3>/PI Controller'
 *   '<S3>/PI Controller1'
 *   '<S4>/PI Controller'
 *   '<S4>/PI Controller1'
 */
#define rtCP_pooled7                   (-2.0F)

/* Pooled Parameter (Mixed Expressions)
 * Referenced by:
 *   '<S5>/Zero'
 *   '<S5>/Delay1'
 *   '<S6>/Zero'
 *   '<S6>/Delay1'
 *   '<S7>/Zero'
 *   '<S7>/Delay1'
 *   '<S37>/Constant'
 *   '<S38>/Constant'
 *   '<S14>/Delay'
 *   '<S15>/Delay'
 *   '<S18>/Delay'
 *   '<S19>/Delay'
 *   '<S22>/Delay'
 *   '<S23>/Delay'
 *   '<S26>/Delay'
 *   '<S27>/Delay'
 */
#define rtCP_pooled8                   (0.0F)

/* Pooled Parameter (Expression: 2/3)
 * Referenced by:
 *   '<S28>/Gain1'
 *   '<S31>/Gain1'
 *   '<S34>/Gain1'
 *   '<S45>/Gain1'
 *   '<S47>/Gain1'
 *   '<S51>/Gain1'
 *   '<S53>/Gain1'
 *   '<S57>/Gain1'
 *   '<S59>/Gain1'
 */
#define rtCP_pooled10                  (0.666666687F)

/* Pooled Parameter (Expression: 1/2)
 * Referenced by:
 *   '<S5>/Gain1'
 *   '<S6>/Gain1'
 *   '<S7>/Gain1'
 */
#define rtCP_pooled12                  (0.5F)

/* Computed Parameter: Constant_Value
 * Referenced by: '<Root>/Constant'
 */
#define rtCP_Constant_Value            (1.41421354F)

/* Pooled Parameter (Expression: Unom_Phase)
 * Referenced by:
 *   '<Root>/Constant4'
 *   '<S1>/Constant1'
 *   '<S1>/Constant3'
 *   '<S2>/Constant1'
 *   '<S3>/Constant1'
 *   '<S3>/Constant3'
 *   '<S4>/Constant1'
 */
#define rtCP_pooled13                  (398.371674F)

/* Computed Parameter: Gain_Gain
 * Referenced by: '<Root>/Gain'
 */
#define rtCP_Gain_Gain                 (314.159271F)

/* Computed Parameter: Constant2_Value
 * Referenced by: '<Root>/Constant2'
 */
#define rtCP_Constant2_Value           (6.28318548F)

/* Pooled Parameter (Expression: Inom)
 * Referenced by:
 *   '<Root>/Constant5'
 *   '<S1>/Constant2'
 *   '<S2>/Constant2'
 *   '<S3>/Constant2'
 *   '<S4>/Constant2'
 */
#define rtCP_pooled14                  (184.082687F)

/* Pooled Parameter (Expression: 2*pi*Fnom_Grid*C_grid)
 * Referenced by:
 *   '<S2>/Gain'
 *   '<S2>/Gain1'
 *   '<S4>/Gain'
 *   '<S4>/Gain1'
 */
#define rtCP_pooled15                  (0.0141371666F)

/* Pooled Parameter (Expression: R_damping)
 * Referenced by:
 *   '<S2>/Constant3'
 *   '<S4>/Constant3'
 */
#define rtCP_pooled16                  (50.0F)

/* Pooled Parameter (Expression: 2*pi*Fnom_Grid*L_grid)
 * Referenced by:
 *   '<S1>/Gain'
 *   '<S1>/Gain1'
 *   '<S3>/Gain'
 *   '<S3>/Gain1'
 */
#define rtCP_pooled17                  (0.0628318563F)

/* Pooled Parameter (Expression: 2*sqrt(2))
 * Referenced by:
 *   '<S1>/Constant'
 *   '<S3>/Constant'
 */
#define rtCP_pooled18                  (2.82842708F)

/* Pooled Parameter (Expression: Udc_ref)
 * Referenced by:
 *   '<Root>/Constant6'
 *   '<S1>/Constant6'
 *   '<S3>/Constant6'
 */
#define rtCP_pooled19                  (1500.0F)

/* Pooled Parameter (Expression: -1)
 * Referenced by:
 *   '<S8>/Gain2'
 *   '<S9>/Gain'
 *   '<S10>/Gain'
 *   '<S11>/Gain'
 */
#define rtCP_pooled20                  (-1.0F)

/* Computed Parameter: Saturation_UpperSat
 * Referenced by: '<S8>/Saturation'
 */
#define rtCP_Saturation_UpperSat       (1.15F)

/* Computed Parameter: Saturation_LowerSat
 * Referenced by: '<S8>/Saturation'
 */
#define rtCP_Saturation_LowerSat       (-1.15F)

extern float rt_modf(float u0, float u1);
extern void PI_Controller_Init(DW_PI_Controller_T *localDW);
extern float PI_Controller(float rtu_Error, bool rtu_Reset, float rtp_Kp, float
  rtp_Ts, float rtp_Max, float rtp_Min, float rtp_Ki, DW_PI_Controller_T
  *localDW, ZCE_PI_Controller_T *localZCE);
extern void abc2AlphaBetaZero(const float rtu_abc[3], float rty_u[3]);
extern void AlphaBetaZero2abc(float rtu_u, float rtu_u_k, float rtu_u_n, float
  rty_abc[3]);
extern void Sequency_Separator(const float rtu_Input_abc[3], float
  rty_Outout_Positive[3], float rty_Outout_negetive[3], DW_Sequency_Separator_T *
  localDW);
extern void dq2AlphaBeta(const float rtu_dq[2], float rtu_wt, float *rty_u,
  float *rty_u_o);
extern void dq2abc(const float rtu_dq[2], float rtu_wt, float rty_abc[3]);
extern void AlphaBeta2dq(const float rtu_u[2], float rtu_wt, float *rty_dq,
  float *rty_dq_p);
extern void abc2dq(const float rtu_abc[3], float rtu_wt, float rty_dq[2]);

#endif                  /* RTW_HEADER_Off_Grid_Inverter_Control_LC_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
