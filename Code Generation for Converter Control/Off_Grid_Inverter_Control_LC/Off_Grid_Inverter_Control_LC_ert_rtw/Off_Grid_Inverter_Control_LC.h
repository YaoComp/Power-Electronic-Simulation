/*
 * File: Off_Grid_Inverter_Control_LC.h
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

#ifndef RTW_HEADER_Off_Grid_Inverter_Control_LC_h_
#define RTW_HEADER_Off_Grid_Inverter_Control_LC_h_
#ifndef Off_Grid_Inverter_Control_LC_COMMON_INCLUDES_
#define Off_Grid_Inverter_Control_LC_COMMON_INCLUDES_
#include <stdbool.h>
#include <stdint.h>
#include "complex_types.h"
#endif                       /* Off_Grid_Inverter_Control_LC_COMMON_INCLUDES_ */

#include <stddef.h>
#include "Off_Grid_Inverter_Control_LC_types.h"
#include "zero_crossing_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<S1>/PI Controller1' */
typedef struct {
  float Delay_DSTATE;                  /* '<S14>/Delay' */
} DW_PI_Controller_T;

/* Zero-crossing (trigger) state for system '<S1>/PI Controller1' */
typedef struct {
  ZCSigState Delay_Reset_ZCE;          /* '<S14>/Delay' */
} ZCE_PI_Controller_T;

/* Block states (default storage) for system '<Root>/Sequency_Separator1' */
typedef struct {
  float Delay1_DSTATE[160];            /* '<S5>/Delay1' */
} DW_Sequency_Separator_T;

/* Block signals (default storage) */
typedef struct {
  float Ec_ABC_Phase[3];               /* '<Root>/Divide2' */
  float Ec_ABC_p[3];                   /* '<Root>/Sequency_Separator2' */
  float wt;                            /* '<Root>/Mod' */
  float Ec_dq_p[2];                    /* '<S10>/abc2dq1' */
  float IL_ABC[3];                     /* '<Root>/Divide1' */
  float IL_ABC_p[3];                   /* '<Root>/Sequency_Separator1' */
  float IL_dq_p[2];                    /* '<S9>/abc2dq1' */
  float Ic_ABC[3];                     /* '<Root>/Divide4' */
  float Ic_ABC_p[3];                   /* '<Root>/Sequency_Separator3' */
  float Ic_dq_p[2];                    /* '<S11>/abc2dq1' */
  float UDC;                           /* '<Root>/Divide3' */
  float Uc_dq_p[2];                    /* '<S3>/Divide' */
  float Ec_ABC_n[3];                   /* '<Root>/Sequency_Separator2' */
  float Ec_dq_n[2];                    /* '<S10>/abc2dq2' */
  float IL_ABC_n[3];                   /* '<Root>/Sequency_Separator1' */
  float IL_dq_n[2];                    /* '<S9>/abc2dq2' */
  float Ic_ABC_n[3];                   /* '<Root>/Sequency_Separator3' */
  float Ic_dq_n[2];                    /* '<S11>/abc2dq2' */
  float Uc_dq_n[2];                    /* '<S1>/Divide' */
  float Mabc[3];                       /* '<S8>/Saturation' */
} B_Off_Grid_Inverter_Control_L_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  DW_Sequency_Separator_T Sequency_Separator3;/* '<Root>/Sequency_Separator3' */
  DW_Sequency_Separator_T Sequency_Separator2;/* '<Root>/Sequency_Separator2' */
  DW_Sequency_Separator_T Sequency_Separator1;/* '<Root>/Sequency_Separator1' */
  DW_PI_Controller_T PIController1_h;  /* '<S4>/PI Controller1' */
  DW_PI_Controller_T PIController_d;   /* '<S4>/PI Controller' */
  DW_PI_Controller_T PIController1_i;  /* '<S3>/PI Controller1' */
  DW_PI_Controller_T PIController_h;   /* '<S3>/PI Controller' */
  DW_PI_Controller_T PIController1_l;  /* '<S2>/PI Controller1' */
  DW_PI_Controller_T PIController;     /* '<S2>/PI Controller' */
  DW_PI_Controller_T PIController2;    /* '<S1>/PI Controller2' */
  DW_PI_Controller_T PIController1;    /* '<S1>/PI Controller1' */
} DW_Off_Grid_Inverter_Control__T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCE_PI_Controller_T PIController1_h; /* '<S4>/PI Controller1' */
  ZCE_PI_Controller_T PIController_d;  /* '<S4>/PI Controller' */
  ZCE_PI_Controller_T PIController1_i; /* '<S3>/PI Controller1' */
  ZCE_PI_Controller_T PIController_h;  /* '<S3>/PI Controller' */
  ZCE_PI_Controller_T PIController1_l; /* '<S2>/PI Controller1' */
  ZCE_PI_Controller_T PIController;    /* '<S2>/PI Controller' */
  ZCE_PI_Controller_T PIController2;   /* '<S1>/PI Controller2' */
  ZCE_PI_Controller_T PIController1;   /* '<S1>/PI Controller1' */
} PrevZCX_Off_Grid_Inverter_Con_T;

/* Constant parameters (default storage) */
typedef struct {
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
  float pooled9[9];

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
  float pooled11[9];
} ConstP_Off_Grid_Inverter_Cont_T;

/* Real-time Model Data Structure */
struct tag_RTM_Off_Grid_Inverter_Con_T {
  const char * volatile errorStatus;
};

/* Block signals (default storage) */
extern B_Off_Grid_Inverter_Control_L_T Off_Grid_Inverter_Control_LC_B;

/* Block states (default storage) */
extern DW_Off_Grid_Inverter_Control__T Off_Grid_Inverter_Control_LC_DW;

/* Zero-crossing (trigger) state */
extern PrevZCX_Off_Grid_Inverter_Con_T Off_Grid_Inverter_Contr_PrevZCX;

/* Constant parameters (default storage) */
extern const ConstP_Off_Grid_Inverter_Cont_T Off_Grid_Inverter_Contro_ConstP;

/* Model entry point functions */
extern void Off_Grid_Inverter_Control_LC_initialize(void);
extern void Off_Grid_Inverter_Control_LC_terminate(void);

/* Customized model step function */
extern void Off_Grid_Inverter_Control_LC_step(const float *arg_time, float
  arg_M_abc[3], const float arg_Ec_abc[3], const float arg_IL_abc[3], const
  float arg_Ic_abc[3], const float *arg_Udc, const float arg_Uc_dq_p_ref[2],
  const float arg_Uc_dq_n_re[2], const bool *arg_Reset);

/* Real-time Model object */
extern RT_MODEL_Off_Grid_Inverter_Co_T *const Off_Grid_Inverter_Control_LC_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Off_Grid_Inverter_Control_LC'
 * '<S1>'   : 'Off_Grid_Inverter_Control_LC/Negative Sequency Current Regulator'
 * '<S2>'   : 'Off_Grid_Inverter_Control_LC/Negetive Sequency Volstge Regulator'
 * '<S3>'   : 'Off_Grid_Inverter_Control_LC/Positive Sequency Current Regulator'
 * '<S4>'   : 'Off_Grid_Inverter_Control_LC/Positive Sequency Volstge Regulator'
 * '<S5>'   : 'Off_Grid_Inverter_Control_LC/Sequency_Separator1'
 * '<S6>'   : 'Off_Grid_Inverter_Control_LC/Sequency_Separator2'
 * '<S7>'   : 'Off_Grid_Inverter_Control_LC/Sequency_Separator3'
 * '<S8>'   : 'Off_Grid_Inverter_Control_LC/Udq2Uabc'
 * '<S9>'   : 'Off_Grid_Inverter_Control_LC/abc2dq_p1'
 * '<S10>'  : 'Off_Grid_Inverter_Control_LC/abc2dq_p2'
 * '<S11>'  : 'Off_Grid_Inverter_Control_LC/abc2dq_p3'
 * '<S12>'  : 'Off_Grid_Inverter_Control_LC/Negative Sequency Current Regulator/PI Controller1'
 * '<S13>'  : 'Off_Grid_Inverter_Control_LC/Negative Sequency Current Regulator/PI Controller2'
 * '<S14>'  : 'Off_Grid_Inverter_Control_LC/Negative Sequency Current Regulator/PI Controller1/Discrete-Time Integrator'
 * '<S15>'  : 'Off_Grid_Inverter_Control_LC/Negative Sequency Current Regulator/PI Controller2/Discrete-Time Integrator'
 * '<S16>'  : 'Off_Grid_Inverter_Control_LC/Negetive Sequency Volstge Regulator/PI Controller'
 * '<S17>'  : 'Off_Grid_Inverter_Control_LC/Negetive Sequency Volstge Regulator/PI Controller1'
 * '<S18>'  : 'Off_Grid_Inverter_Control_LC/Negetive Sequency Volstge Regulator/PI Controller/Discrete-Time Integrator'
 * '<S19>'  : 'Off_Grid_Inverter_Control_LC/Negetive Sequency Volstge Regulator/PI Controller1/Discrete-Time Integrator'
 * '<S20>'  : 'Off_Grid_Inverter_Control_LC/Positive Sequency Current Regulator/PI Controller'
 * '<S21>'  : 'Off_Grid_Inverter_Control_LC/Positive Sequency Current Regulator/PI Controller1'
 * '<S22>'  : 'Off_Grid_Inverter_Control_LC/Positive Sequency Current Regulator/PI Controller/Discrete-Time Integrator'
 * '<S23>'  : 'Off_Grid_Inverter_Control_LC/Positive Sequency Current Regulator/PI Controller1/Discrete-Time Integrator'
 * '<S24>'  : 'Off_Grid_Inverter_Control_LC/Positive Sequency Volstge Regulator/PI Controller'
 * '<S25>'  : 'Off_Grid_Inverter_Control_LC/Positive Sequency Volstge Regulator/PI Controller1'
 * '<S26>'  : 'Off_Grid_Inverter_Control_LC/Positive Sequency Volstge Regulator/PI Controller/Discrete-Time Integrator'
 * '<S27>'  : 'Off_Grid_Inverter_Control_LC/Positive Sequency Volstge Regulator/PI Controller1/Discrete-Time Integrator'
 * '<S28>'  : 'Off_Grid_Inverter_Control_LC/Sequency_Separator1/abc2&#x3B1;&#x3B2;0'
 * '<S29>'  : 'Off_Grid_Inverter_Control_LC/Sequency_Separator1/&#x3B1;&#x3B2;02abc'
 * '<S30>'  : 'Off_Grid_Inverter_Control_LC/Sequency_Separator1/&#x3B1;&#x3B2;02abc1'
 * '<S31>'  : 'Off_Grid_Inverter_Control_LC/Sequency_Separator2/abc2&#x3B1;&#x3B2;0'
 * '<S32>'  : 'Off_Grid_Inverter_Control_LC/Sequency_Separator2/&#x3B1;&#x3B2;02abc'
 * '<S33>'  : 'Off_Grid_Inverter_Control_LC/Sequency_Separator2/&#x3B1;&#x3B2;02abc1'
 * '<S34>'  : 'Off_Grid_Inverter_Control_LC/Sequency_Separator3/abc2&#x3B1;&#x3B2;0'
 * '<S35>'  : 'Off_Grid_Inverter_Control_LC/Sequency_Separator3/&#x3B1;&#x3B2;02abc'
 * '<S36>'  : 'Off_Grid_Inverter_Control_LC/Sequency_Separator3/&#x3B1;&#x3B2;02abc1'
 * '<S37>'  : 'Off_Grid_Inverter_Control_LC/Udq2Uabc/dq2abc'
 * '<S38>'  : 'Off_Grid_Inverter_Control_LC/Udq2Uabc/dq2abc1'
 * '<S39>'  : 'Off_Grid_Inverter_Control_LC/Udq2Uabc/dq2abc/dq2&#x3B1;&#x3B2;0'
 * '<S40>'  : 'Off_Grid_Inverter_Control_LC/Udq2Uabc/dq2abc/&#x3B1;&#x3B2;02abc'
 * '<S41>'  : 'Off_Grid_Inverter_Control_LC/Udq2Uabc/dq2abc1/dq2&#x3B1;&#x3B2;0'
 * '<S42>'  : 'Off_Grid_Inverter_Control_LC/Udq2Uabc/dq2abc1/&#x3B1;&#x3B2;02abc'
 * '<S43>'  : 'Off_Grid_Inverter_Control_LC/abc2dq_p1/abc2dq1'
 * '<S44>'  : 'Off_Grid_Inverter_Control_LC/abc2dq_p1/abc2dq2'
 * '<S45>'  : 'Off_Grid_Inverter_Control_LC/abc2dq_p1/abc2dq1/abc2&#x3B1;&#x3B2;0'
 * '<S46>'  : 'Off_Grid_Inverter_Control_LC/abc2dq_p1/abc2dq1/&#x3B1;&#x3B2;2dq'
 * '<S47>'  : 'Off_Grid_Inverter_Control_LC/abc2dq_p1/abc2dq2/abc2&#x3B1;&#x3B2;0'
 * '<S48>'  : 'Off_Grid_Inverter_Control_LC/abc2dq_p1/abc2dq2/&#x3B1;&#x3B2;2dq'
 * '<S49>'  : 'Off_Grid_Inverter_Control_LC/abc2dq_p2/abc2dq1'
 * '<S50>'  : 'Off_Grid_Inverter_Control_LC/abc2dq_p2/abc2dq2'
 * '<S51>'  : 'Off_Grid_Inverter_Control_LC/abc2dq_p2/abc2dq1/abc2&#x3B1;&#x3B2;0'
 * '<S52>'  : 'Off_Grid_Inverter_Control_LC/abc2dq_p2/abc2dq1/&#x3B1;&#x3B2;2dq'
 * '<S53>'  : 'Off_Grid_Inverter_Control_LC/abc2dq_p2/abc2dq2/abc2&#x3B1;&#x3B2;0'
 * '<S54>'  : 'Off_Grid_Inverter_Control_LC/abc2dq_p2/abc2dq2/&#x3B1;&#x3B2;2dq'
 * '<S55>'  : 'Off_Grid_Inverter_Control_LC/abc2dq_p3/abc2dq1'
 * '<S56>'  : 'Off_Grid_Inverter_Control_LC/abc2dq_p3/abc2dq2'
 * '<S57>'  : 'Off_Grid_Inverter_Control_LC/abc2dq_p3/abc2dq1/abc2&#x3B1;&#x3B2;0'
 * '<S58>'  : 'Off_Grid_Inverter_Control_LC/abc2dq_p3/abc2dq1/&#x3B1;&#x3B2;2dq'
 * '<S59>'  : 'Off_Grid_Inverter_Control_LC/abc2dq_p3/abc2dq2/abc2&#x3B1;&#x3B2;0'
 * '<S60>'  : 'Off_Grid_Inverter_Control_LC/abc2dq_p3/abc2dq2/&#x3B1;&#x3B2;2dq'
 */

/*-
 * Requirements for '<Root>': Off_Grid_Inverter_Control_LC

 */
#endif                          /* RTW_HEADER_Off_Grid_Inverter_Control_LC_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
