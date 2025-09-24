/*
 * File: PQ_Control_LCL.h
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

#ifndef RTW_HEADER_PQ_Control_LCL_h_
#define RTW_HEADER_PQ_Control_LCL_h_
#ifndef PQ_Control_LCL_COMMON_INCLUDES_
#define PQ_Control_LCL_COMMON_INCLUDES_
#include <stdbool.h>
#include <stdint.h>
#include "complex_types.h"
#endif                                 /* PQ_Control_LCL_COMMON_INCLUDES_ */

#include "PQ_Control_LCL_types.h"
#include "zero_crossing_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Internal Data Grouped For Same Function, for system '<S1>/Discreted First Order Low-Pass Filter' */
typedef struct {
  float Delay_DSTATE[2];               /* '<S12>/Delay' */
} FuncInternalData0_DiscretedFi_T;

/* Internal Data Grouped For Same Function, for system '<S1>/Integrator with Wrapped State1' */
typedef struct {
  float Integrator_DSTATE;             /* '<S14>/Integrator' */
} FuncInternalData0_Wrapped_Int_T;

/* Internal Data Grouped For Same Function, for system '<S1>/PI Controller' */
typedef struct {
  float Delay_DSTATE;                  /* '<S21>/Delay' */
  ZCSigState Delay_Reset_ZCE;          /* '<S21>/Delay' */
} FuncInternalData0_PI_Controll_T;

/* Internal Data Grouped For Same Function, for system '<Root>/DSRF-PLL' */
typedef struct {
  FuncInternalData0_PI_Controll_T FuncInternalData0_PIController;/* '<S1>/PI Controller' */
  FuncInternalData0_Wrapped_Int_T FuncInternalData0_Integratorwi;
                                     /* '<S1>/Integrator with Wrapped State1' */
  FuncInternalData0_DiscretedFi_T FuncInternalData0_DiscretedFir;
                             /* '<S1>/Discreted First Order Low-Pass Filter1' */
  FuncInternalData0_DiscretedFi_T FuncInternalData0_DiscretedFi_m;
                              /* '<S1>/Discreted First Order Low-Pass Filter' */
  float Memory2_PreviousInput[2];      /* '<S1>/Memory2' */
  float Memory1_PreviousInput[2];      /* '<S1>/Memory1' */
  float Memory_PreviousInput;          /* '<S1>/Memory' */
} FuncInternalData0_DSRF_PLL_T;

/* Internal Data Grouped For Same Function, for system '<Root>/Sequency_Separator1' */
typedef struct {
  float Delay1[160];                   /* '<S7>/Delay1' */
} FuncInternalData0_Sequency_Se_T;

/* Internal Data Grouped For Same Function, for system '<Root>' */
typedef struct {
  FuncInternalData0_Sequency_Se_T FuncInternalData0_Sequency_Sep;/* '<Root>/Sequency_Separator1' */
  FuncInternalData0_PI_Controll_T FuncInternalData0_PIController;/* '<S6>/PI Controller1' */
  FuncInternalData0_PI_Controll_T FuncInternalData0_PIControlle_m;/* '<S6>/PI Controller' */
  FuncInternalData0_PI_Controll_T FuncInternalData0_PIControlle_c;/* '<S4>/PI Controller2' */
  FuncInternalData0_PI_Controll_T FuncInternalData0_PIControlle_k;/* '<S4>/PI Controller1' */
  FuncInternalData0_DSRF_PLL_T FuncInternalData0_DSRFPLL;/* '<Root>/DSRF-PLL' */
  float Ec_ABC_Line[3];                /* '<Root>/Divide' */
  float Ec_ABC_Phase[3];            /* '<Root>/Line2Phase_Voltage_Conversion' */
  float Ec_dq_p[2];                    /* '<Root>/DSRF-PLL' */
  float Ic_ABC[3];                     /* '<Root>/Divide1' */
  float Ic_ABC_p[3];                   /* '<Root>/Sequency_Separator1' */
  float Ic_dq_p[2];                    /* '<S9>/abc2dq1' */
  float PQ_REF[2];                     /* '<Root>/Divide2' */
  float Ic_dq_p_ref[2];                /* '<S5>/Signal Conversion' */
  float Uc_dq_p[2];                    /* '<S6>/Divide' */
  float Ec_dq_n[2];                    /* '<Root>/DSRF-PLL' */
  float Ic_ABC_n[3];                   /* '<Root>/Sequency_Separator1' */
  float Ic_dq_n[2];                    /* '<S9>/abc2dq2' */
  float Ic_dq_n_ref[2];                /* '<S5>/Signal Conversion1' */
  float Uc_dq_n[2];                    /* '<S4>/Divide' */
  float Mabc[3];                       /* '<S3>/Multiport Switch' */
  float wt;                            /* '<Root>/DSRF-PLL' */
  float UDC;                           /* '<Root>/Divide3' */
} FuncInternalData0_PQ_Control__T;

/* Constant parameters (default storage) */
typedef struct {
  /* Pooled Parameter (Expression: [ 1   -1/2   -1/2; 0   sqrt(3)/2   -sqrt(3)/2; 1/2  1/2  1/2 ] )
   * Referenced by:
   *   '<S16>/Gain3'
   *   '<S31>/Gain3'
   *   '<S43>/Gain3'
   *   '<S45>/Gain3'
   *   '<S47>/Gain3'
   */
  float pooled7[9];

  /* Pooled Parameter (Expression: [ 1   0   1; -1/2  sqrt(3)/2   1; -1/2  -sqrt(3)/2  1 ] )
   * Referenced by:
   *   '<S32>/Gain3'
   *   '<S33>/Gain3'
   *   '<S37>/Gain3'
   *   '<S39>/Gain3'
   */
  float pooled11[9];
} ConstP_PQ_Control_LCL_T;

/* Parameters (default storage) */
struct P_PQ_Control_LCL_T_ {
  float Inom;                          /* Variable: Inom
                                        * Referenced by:
                                        *   '<Root>/Constant2'
                                        *   '<Root>/Constant5'
                                        *   '<S4>/Constant2'
                                        *   '<S6>/Constant2'
                                        */
  float Ki_Idq;                        /* Variable: Ki_Idq
                                        * Referenced by:
                                        *   '<S4>/PI Controller1'
                                        *   '<S4>/PI Controller2'
                                        *   '<S6>/PI Controller'
                                        *   '<S6>/PI Controller1'
                                        */
  float Kp_Idq;                        /* Variable: Kp_Idq
                                        * Referenced by:
                                        *   '<S4>/PI Controller1'
                                        *   '<S4>/PI Controller2'
                                        *   '<S6>/PI Controller'
                                        *   '<S6>/PI Controller1'
                                        */
  float Udc_ref;                       /* Variable: Udc_ref
                                        * Referenced by:
                                        *   '<Root>/Constant6'
                                        *   '<S4>/Constant6'
                                        *   '<S6>/Constant6'
                                        */
  float Unom_Phase;                    /* Variable: Unom_Phase
                                        * Referenced by:
                                        *   '<Root>/Constant3'
                                        *   '<Root>/Constant4'
                                        *   '<S4>/Constant1'
                                        *   '<S4>/Constant3'
                                        *   '<S6>/Constant1'
                                        *   '<S6>/Constant3'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_PQ_Control_LCL_T {
  const char * volatile errorStatus;
};

/* Block parameters (default storage) */
extern P_PQ_Control_LCL_T PQ_Control_LCL_P;

/* Internal Data Grouped For Same Function */
extern FuncInternalData0_PQ_Control__T PQ_Control_LC_FuncInternalData0;

/* Constant parameters (default storage) */
extern const ConstP_PQ_Control_LCL_T PQ_Control_LCL_ConstP;

/* Model entry point functions */
extern void PQ_Control_Initialize(void);
extern void PQ_Control_Terminate(void);

/* Customized model step function */
extern void PQ_Control_Step(float arg_Mabc1[3], const float arg_PQ_Ref1[2],
  const float *arg_Udc1, const float arg_If_abc1[3], const float arg_Ic_abc1[3],
  const float arg_Ec_abc1[3], const bool *arg_Reset1);

/* Real-time Model object */
extern RT_MODEL_PQ_Control_LCL_T *const PQ_Control_LCL_M;

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
 * '<Root>' : 'PQ_Control_LCL'
 * '<S1>'   : 'PQ_Control_LCL/DSRF-PLL'
 * '<S2>'   : 'PQ_Control_LCL/Line2Phase_Voltage_Conversion'
 * '<S3>'   : 'PQ_Control_LCL/Moduation'
 * '<S4>'   : 'PQ_Control_LCL/Negative Sequency Current Regulator'
 * '<S5>'   : 'PQ_Control_LCL/PQ2Idq'
 * '<S6>'   : 'PQ_Control_LCL/Positive Sequency Current Regulator'
 * '<S7>'   : 'PQ_Control_LCL/Sequency_Separator1'
 * '<S8>'   : 'PQ_Control_LCL/Udq2Uabc'
 * '<S9>'   : 'PQ_Control_LCL/abc2dq_p1'
 * '<S10>'  : 'PQ_Control_LCL/DSRF-PLL/Decoupling Network'
 * '<S11>'  : 'PQ_Control_LCL/DSRF-PLL/Decoupling Network1'
 * '<S12>'  : 'PQ_Control_LCL/DSRF-PLL/Discreted First Order Low-Pass Filter'
 * '<S13>'  : 'PQ_Control_LCL/DSRF-PLL/Discreted First Order Low-Pass Filter1'
 * '<S14>'  : 'PQ_Control_LCL/DSRF-PLL/Integrator with Wrapped State1'
 * '<S15>'  : 'PQ_Control_LCL/DSRF-PLL/PI Controller'
 * '<S16>'  : 'PQ_Control_LCL/DSRF-PLL/abc2&#x3B1;&#x3B2;0'
 * '<S17>'  : 'PQ_Control_LCL/DSRF-PLL/&#x3B1;&#x3B2;2dq'
 * '<S18>'  : 'PQ_Control_LCL/DSRF-PLL/&#x3B1;&#x3B2;2dq1'
 * '<S19>'  : 'PQ_Control_LCL/DSRF-PLL/Integrator with Wrapped State1/Compare To Constant'
 * '<S20>'  : 'PQ_Control_LCL/DSRF-PLL/Integrator with Wrapped State1/Compare To Constant1'
 * '<S21>'  : 'PQ_Control_LCL/DSRF-PLL/PI Controller/Discrete-Time Integrator'
 * '<S22>'  : 'PQ_Control_LCL/Moduation/Subsystem'
 * '<S23>'  : 'PQ_Control_LCL/Negative Sequency Current Regulator/PI Controller1'
 * '<S24>'  : 'PQ_Control_LCL/Negative Sequency Current Regulator/PI Controller2'
 * '<S25>'  : 'PQ_Control_LCL/Negative Sequency Current Regulator/PI Controller1/Discrete-Time Integrator'
 * '<S26>'  : 'PQ_Control_LCL/Negative Sequency Current Regulator/PI Controller2/Discrete-Time Integrator'
 * '<S27>'  : 'PQ_Control_LCL/Positive Sequency Current Regulator/PI Controller'
 * '<S28>'  : 'PQ_Control_LCL/Positive Sequency Current Regulator/PI Controller1'
 * '<S29>'  : 'PQ_Control_LCL/Positive Sequency Current Regulator/PI Controller/Discrete-Time Integrator'
 * '<S30>'  : 'PQ_Control_LCL/Positive Sequency Current Regulator/PI Controller1/Discrete-Time Integrator'
 * '<S31>'  : 'PQ_Control_LCL/Sequency_Separator1/abc2&#x3B1;&#x3B2;0'
 * '<S32>'  : 'PQ_Control_LCL/Sequency_Separator1/&#x3B1;&#x3B2;02abc'
 * '<S33>'  : 'PQ_Control_LCL/Sequency_Separator1/&#x3B1;&#x3B2;02abc1'
 * '<S34>'  : 'PQ_Control_LCL/Udq2Uabc/dq2abc'
 * '<S35>'  : 'PQ_Control_LCL/Udq2Uabc/dq2abc1'
 * '<S36>'  : 'PQ_Control_LCL/Udq2Uabc/dq2abc/dq2&#x3B1;&#x3B2;0'
 * '<S37>'  : 'PQ_Control_LCL/Udq2Uabc/dq2abc/&#x3B1;&#x3B2;02abc'
 * '<S38>'  : 'PQ_Control_LCL/Udq2Uabc/dq2abc1/dq2&#x3B1;&#x3B2;0'
 * '<S39>'  : 'PQ_Control_LCL/Udq2Uabc/dq2abc1/&#x3B1;&#x3B2;02abc'
 * '<S40>'  : 'PQ_Control_LCL/abc2dq_p1/abc2dq1'
 * '<S41>'  : 'PQ_Control_LCL/abc2dq_p1/abc2dq2'
 * '<S42>'  : 'PQ_Control_LCL/abc2dq_p1/abc2dq3'
 * '<S43>'  : 'PQ_Control_LCL/abc2dq_p1/abc2dq1/abc2&#x3B1;&#x3B2;0'
 * '<S44>'  : 'PQ_Control_LCL/abc2dq_p1/abc2dq1/&#x3B1;&#x3B2;2dq'
 * '<S45>'  : 'PQ_Control_LCL/abc2dq_p1/abc2dq2/abc2&#x3B1;&#x3B2;0'
 * '<S46>'  : 'PQ_Control_LCL/abc2dq_p1/abc2dq2/&#x3B1;&#x3B2;2dq'
 * '<S47>'  : 'PQ_Control_LCL/abc2dq_p1/abc2dq3/abc2&#x3B1;&#x3B2;0'
 * '<S48>'  : 'PQ_Control_LCL/abc2dq_p1/abc2dq3/&#x3B1;&#x3B2;2dq'
 */

/*-
 * Requirements for '<Root>': PQ_Control_LCL

 */
#endif                                 /* RTW_HEADER_PQ_Control_LCL_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
