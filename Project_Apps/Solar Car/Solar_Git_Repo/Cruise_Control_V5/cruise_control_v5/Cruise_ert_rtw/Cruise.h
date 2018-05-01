/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Cruise.h
 *
 * Code generated for Simulink model 'Cruise'.
 *
 * Model version                  : 1.45
 * Simulink Coder version         : 8.12 (R2017a) 16-Feb-2017
 * C/C++ source code generated on : Wed Feb 21 20:09:25 2018
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Microchip->PIC18
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Cruise_h_
#define RTW_HEADER_Cruise_h_
#include <stddef.h>
#include <math.h>
#ifndef Cruise_COMMON_INCLUDES_
# define Cruise_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* Cruise_COMMON_INCLUDES_ */

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

/* Constant parameters (auto storage) */
typedef struct {
  /* Expression: [NetDistancemiles;total_distmiles]
   * Referenced by: '<S5>/Prelookup'
   */
  real_T Prelookup_BreakpointsData[42];

  /* Expression: [energyTotal_noDrag';energySeg_noDrag';mult_vel_ToPower']
   * Referenced by: '<S5>/Direct Lookup Table (n-D)'
   */
  real_T DirectLookupTablenD_table[123];
} ConstP;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real_T SOC;                          /* '<Root>/SOC %' */
  real_T Reserve;                      /* '<Root>/Reserve %' */
  real_T BatteryCapacityWh;            /* '<Root>/Battery Capacity (Wh)' */
  real_T SafetyFactor;                 /* '<Root>/Safety Factor' */
  real_T MeasuredPowerW;               /* '<Root>/Measured Power (W)' */
  real_T SolarPowerW;                  /* '<Root>/Solar Power (W)' */
  real_T MeasuredVelocitymph;          /* '<Root>/Measured Velocity (mph)' */
  real_T TimeRemainingh;               /* '<Root>/Time Remaining (h)' */
  real_T NetDistancemiles;             /* '<Root>/Net Distance (miles)' */
} ExtU;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T Error;                        /* '<Root>/Error' */
  real_T OptimalVelocitymph;           /* '<Root>/Optimal Velocity (mph)' */
} ExtY;

/* Real-time Model Data Structure */
struct tag_RTM {
  const char_T * volatile errorStatus;
};

/* External inputs (root inport signals with auto storage) */
extern ExtU rtU;

/* External outputs (root outports fed by signals with auto storage) */
extern ExtY rtY;

/* Constant parameters (auto storage) */
extern const ConstP rtConstP;

/* Model entry point functions */
extern void Cruise_initialize(void);
extern void Cruise_step(void);

/* Real-time Model object */
extern RT_MODEL *const rtM;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S8>/Data Type Duplicate' : Unused code path elimination
 * Block '<S8>/Data Type Propagation' : Unused code path elimination
 * Block '<S3>/Scope1' : Unused code path elimination
 * Block '<S3>/Scope2' : Unused code path elimination
 * Block '<S4>/Display' : Unused code path elimination
 * Block '<S4>/Scope' : Unused code path elimination
 * Block '<S4>/Scope1' : Unused code path elimination
 * Block '<S4>/Scope2' : Unused code path elimination
 * Block '<S1>/Gain' : Unused code path elimination
 * Block '<S1>/Gain1' : Unused code path elimination
 * Block '<S1>/Scope1' : Unused code path elimination
 * Block '<S11>/Scope' : Unused code path elimination
 * Block '<S12>/Scope' : Unused code path elimination
 * Block '<S6>/Scope' : Unused code path elimination
 * Block '<S6>/Scope1' : Unused code path elimination
 * Block '<S6>/Scope2' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('Cruise_control_V4/Cruise Control System')    - opens subsystem Cruise_control_V4/Cruise Control System
 * hilite_system('Cruise_control_V4/Cruise Control System/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Cruise_control_V4'
 * '<S1>'   : 'Cruise_control_V4/Cruise Control System'
 * '<S2>'   : 'Cruise_control_V4/Cruise Control System/Calculate Available Energy'
 * '<S3>'   : 'Cruise_control_V4/Cruise Control System/Calculate Expected Completion Time'
 * '<S4>'   : 'Cruise_control_V4/Cruise Control System/Calculate Required Energy'
 * '<S5>'   : 'Cruise_control_V4/Cruise Control System/Get Lookup Table Values'
 * '<S6>'   : 'Cruise_control_V4/Cruise Control System/Set Optimal Speed'
 * '<S7>'   : 'Cruise_control_V4/Cruise Control System/Subsystem'
 * '<S8>'   : 'Cruise_control_V4/Cruise Control System/Calculate Expected Completion Time/Saturation Dynamic'
 * '<S9>'   : 'Cruise_control_V4/Cruise Control System/Calculate Required Energy/Net Distance'
 * '<S10>'  : 'Cruise_control_V4/Cruise Control System/Calculate Required Energy/Time Left'
 * '<S11>'  : 'Cruise_control_V4/Cruise Control System/Set Optimal Speed/Calculate Nominal Power'
 * '<S12>'  : 'Cruise_control_V4/Cruise Control System/Set Optimal Speed/Error Ratio'
 * '<S13>'  : 'Cruise_control_V4/Cruise Control System/Set Optimal Speed/Power to Speed'
 * '<S14>'  : 'Cruise_control_V4/Cruise Control System/Set Optimal Speed/Error Ratio/Speed to Expected Power'
 * '<S15>'  : 'Cruise_control_V4/Cruise Control System/Set Optimal Speed/Power to Speed/MATLAB Function'
 */
#endif                                 /* RTW_HEADER_Cruise_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
