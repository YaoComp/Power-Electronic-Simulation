/*
 * File: ert_main.c
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

#include <stddef.h>
#include <stdio.h>            /* This example main program uses printf/fflush */
#include "Off_Grid_Inverter_Control_LC.h" /* Model header file */

/* Global variables used by function prototype control */

/* '<Root>/time' */
static float arg_time = 0.0F;

/* '<Root>/Ec_abc' */
static float arg_Ec_abc[3] = { 0.0F, 0.0F, 0.0F };

/* '<Root>/IL_abc' */
static float arg_IL_abc[3] = { 0.0F, 0.0F, 0.0F };

/* '<Root>/Ic_abc' */
static float arg_Ic_abc[3] = { 0.0F, 0.0F, 0.0F };

/* '<Root>/Udc' */
static float arg_Udc = 0.0F;

/* '<Root>/Uc_dq_p_ref' */
static float arg_Uc_dq_p_ref[2] = { 0.0F, 0.0F };

/* '<Root>/Uc_dq_n_re' */
static float arg_Uc_dq_n_re[2] = { 0.0F, 0.0F };

/* '<Root>/Reset' */
static bool arg_Reset = false;

/* '<Root>/M_abc' */
static float arg_M_abc[3];

/*
 * Associating rt_OneStep with a real-time clock or interrupt service routine
 * is what makes the generated code "real-time".  The function rt_OneStep is
 * always associated with the base rate of the model.  Subrates are managed
 * by the base rate from inside the generated code.  Enabling/disabling
 * interrupts and floating point context switches are target specific.  This
 * example code indicates where these should take place relative to executing
 * the generated code step function.  Overrun behavior should be tailored to
 * your application needs.  This example simply sets an error status in the
 * real-time model and returns from rt_OneStep.
 */
void rt_OneStep(void);
void rt_OneStep(void)
{
  static bool OverrunFlag = false;

  /* Disable interrupts here */

  /* Check for overrun */
  if (OverrunFlag) {
    rtmSetErrorStatus(Off_Grid_Inverter_Control_LC_M, "Overrun");
    return;
  }

  OverrunFlag = true;

  /* Save FPU context here (if necessary) */
  /* Re-enable timer or interrupt here */
  /* Set model inputs here */

  /* Step the model */
  Off_Grid_Inverter_Control_LC_step(&arg_time, arg_M_abc, arg_Ec_abc, arg_IL_abc,
    arg_Ic_abc, &arg_Udc, arg_Uc_dq_p_ref, arg_Uc_dq_n_re, &arg_Reset);

  /* Get model outputs here */

  /* Indicate task complete */
  OverrunFlag = false;

  /* Disable interrupts here */
  /* Restore FPU context here (if necessary) */
  /* Enable interrupts here */
}

/*
 * The example main function illustrates what is required by your
 * application code to initialize, execute, and terminate the generated code.
 * Attaching rt_OneStep to a real-time clock is target specific. This example
 * illustrates how you do this relative to initializing the model.
 */
int main(int argc, const char *argv[])
{
  /* Unused arguments */
  (void)(argc);
  (void)(argv);

  /* Initialize model */
  Off_Grid_Inverter_Control_LC_initialize();

  /* Attach rt_OneStep to a timer or interrupt service routine with
   * period 6.25E-5 seconds (base rate of the model) here.
   * The call syntax for rt_OneStep is
   *
   *  rt_OneStep();
   */
  printf("Warning: The simulation will run forever. "
         "Generated ERT main won't simulate model step behavior. "
         "To change this behavior select the 'MAT-file logging' option.\n");
  fflush((NULL));
  while (rtmGetErrorStatus(Off_Grid_Inverter_Control_LC_M) == (NULL)) {
    /*  Perform application tasks here */
  }

  /* Terminate model */
  Off_Grid_Inverter_Control_LC_terminate();
  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
