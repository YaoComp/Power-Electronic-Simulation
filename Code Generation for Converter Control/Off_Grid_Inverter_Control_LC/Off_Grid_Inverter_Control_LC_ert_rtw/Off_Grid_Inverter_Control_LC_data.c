/*
 * File: Off_Grid_Inverter_Control_LC_data.c
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

/* Constant parameters (default storage) */
const ConstP_Off_Grid_Inverter_Cont_T Off_Grid_Inverter_Contro_ConstP = {
  /* Pooled Parameter (Expression: [ 1   -1/2   -1/2; 0   sqrt(3)/2   -sqrt(3)/2; 1/2  1/2  1/2 ] )
   * Referenced by:
   *   '<S28>/Gain3'
   *   '<S31>/Gain3'
   *   '<S34>/Gain3'
   *   '<S45>/Gain3'
   *   '<S47>/Gain3'
   *   '<S51>/Gain3'
   *   '<S53>/Gain3'
   *   '<S57>/Gain3'
   *   '<S59>/Gain3'
   */
  { 1.0F, 0.0F, 0.5F, -0.5F, 0.866025388F, 0.5F, -0.5F, -0.866025388F, 0.5F },

  /* Pooled Parameter (Expression: [ 1   0   1; -1/2  sqrt(3)/2   1; -1/2  -sqrt(3)/2  1 ] )
   * Referenced by:
   *   '<S29>/Gain3'
   *   '<S30>/Gain3'
   *   '<S32>/Gain3'
   *   '<S33>/Gain3'
   *   '<S35>/Gain3'
   *   '<S36>/Gain3'
   *   '<S40>/Gain3'
   *   '<S42>/Gain3'
   */
  { 1.0F, -0.5F, -0.5F, 0.0F, 0.866025388F, -0.866025388F, 1.0F, 1.0F, 1.0F }
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
