/*
 * File: PQ_Control_LCL_data.c
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

/* Block parameters (default storage) */
P_PQ_Control_LCL_T PQ_Control_LCL_P = {
  /* Variable: Inom
   * Referenced by:
   *   '<Root>/Constant2'
   *   '<Root>/Constant5'
   *   '<S4>/Constant2'
   *   '<S6>/Constant2'
   */
  184.082687F,

  /* Variable: Ki_Idq
   * Referenced by:
   *   '<S4>/PI Controller1'
   *   '<S4>/PI Controller2'
   *   '<S6>/PI Controller'
   *   '<S6>/PI Controller1'
   */
  14.2122307F,

  /* Variable: Kp_Idq
   * Referenced by:
   *   '<S4>/PI Controller1'
   *   '<S4>/PI Controller2'
   *   '<S6>/PI Controller'
   *   '<S6>/PI Controller1'
   */
  2.26194668F,

  /* Variable: Udc_ref
   * Referenced by:
   *   '<Root>/Constant6'
   *   '<S4>/Constant6'
   *   '<S6>/Constant6'
   */
  1500.0F,

  /* Variable: Unom_Phase
   * Referenced by:
   *   '<Root>/Constant3'
   *   '<Root>/Constant4'
   *   '<S4>/Constant1'
   *   '<S4>/Constant3'
   *   '<S6>/Constant1'
   *   '<S6>/Constant3'
   */
  398.371674F
};

/* Constant parameters (default storage) */
const ConstP_PQ_Control_LCL_T PQ_Control_LCL_ConstP = {
  /* Pooled Parameter (Expression: [ 1   -1/2   -1/2; 0   sqrt(3)/2   -sqrt(3)/2; 1/2  1/2  1/2 ] )
   * Referenced by:
   *   '<S16>/Gain3'
   *   '<S31>/Gain3'
   *   '<S43>/Gain3'
   *   '<S45>/Gain3'
   *   '<S47>/Gain3'
   */
  { 1.0F, 0.0F, 0.5F, -0.5F, 0.866025388F, 0.5F, -0.5F, -0.866025388F, 0.5F },

  /* Pooled Parameter (Expression: [ 1   0   1; -1/2  sqrt(3)/2   1; -1/2  -sqrt(3)/2  1 ] )
   * Referenced by:
   *   '<S32>/Gain3'
   *   '<S33>/Gain3'
   *   '<S37>/Gain3'
   *   '<S39>/Gain3'
   */
  { 1.0F, -0.5F, -0.5F, 0.0F, 0.866025388F, -0.866025388F, 1.0F, 1.0F, 1.0F }
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
