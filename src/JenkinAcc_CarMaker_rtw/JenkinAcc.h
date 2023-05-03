/*
 * JenkinAcc.h
 *
 * Sponsored Third Party Support License -- for use only to support
 * products interfaced to MathWorks software under terms specified in your
 * company's restricted use license agreement.
 *
 * Code generation for model "JenkinAcc".
 *
 * Model version              : 1.4
 * Simulink Coder version : 9.4 (R2020b) 29-Jul-2020
 * C source code generated on : Mon May  1 15:18:40 2023
 *
 * Target selection: CarMaker.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_JenkinAcc_h_
#define RTW_HEADER_JenkinAcc_h_
#include <math.h>
#include <stddef.h>
#include <string.h>
#ifndef JenkinAcc_COMMON_INCLUDES_
#define JenkinAcc_COMMON_INCLUDES_
#include <stdlib.h>
#include <Global.h>
#include <TextUtils.h>
#include <DataDict.h>
#include <InfoUtils.h>
#include <InfoParam.h>
#include <DirectVarAccess.h>
#include <SimCore.h>
#include <Vehicle/Sensor_Object.h>
#include <Traffic.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* JenkinAcc_COMMON_INCLUDES_ */

#include "JenkinAcc_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_zcfcn.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlockIO
#define rtmGetBlockIO(rtm)             ((rtm)->blockIO)
#endif

#ifndef rtmSetBlockIO
#define rtmSetBlockIO(rtm, val)        ((rtm)->blockIO = (val))
#endif

#ifndef rtmGetPrevZCSigState
#define rtmGetPrevZCSigState(rtm)      ((rtm)->prevZCSigState)
#endif

#ifndef rtmSetPrevZCSigState
#define rtmSetPrevZCSigState(rtm, val) ((rtm)->prevZCSigState = (val))
#endif

#ifndef rtmGetRootDWork
#define rtmGetRootDWork(rtm)           ((rtm)->dwork)
#endif

#ifndef rtmSetRootDWork
#define rtmSetRootDWork(rtm, val)      ((rtm)->dwork = (val))
#endif

#ifndef rtmGetU
#define rtmGetU(rtm)                   ((rtm)->inputs)
#endif

#ifndef rtmSetU
#define rtmSetU(rtm, val)              ((rtm)->inputs = (val))
#endif

#ifndef rtmGetY
#define rtmGetY(rtm)                   ((rtm)->outputs)
#endif

#ifndef rtmSetY
#define rtmSetY(rtm, val)              ((rtm)->outputs = (val))
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#define JenkinAcc_M_TYPE               RT_MODEL_JenkinAcc_T

/* Definition required by CarMaker */
#ifndef rtmGetStepSize
# define rtmGetStepSize(rtm)           0.001
#endif

/* Block signals (default storage) */
typedef struct {
  real_T SFunction_o1;                 /* '<S18>/S-Function' */
  real_T SFunction_o2[8];              /* '<S18>/S-Function' */
  real_T SFunction_o3;                 /* '<S18>/S-Function' */
  real_T SFunction_o4[2];              /* '<S18>/S-Function' */
  real_T SFunction_o1_a;               /* '<S19>/S-Function' */
  real_T SFunction_o2_e[6];            /* '<S19>/S-Function' */
  real_T SFunction_o3_m[2];            /* '<S19>/S-Function' */
  real_T SFunction_o4_c[13];           /* '<S19>/S-Function' */
  real_T SFunction_o5[13];             /* '<S19>/S-Function' */
  real_T SFunction_o6[5];              /* '<S19>/S-Function' */
  real_T IsACCenabled;                 /* '<S5>/Is ACC enabled' */
  real_T ReadUserdesiredtimegap;       /* '<S7>/Read User desired time gap' */
  real_T ReadinitbrakethresholdfromInf;
                                 /* '<S3>/Read init brake threshold from Inf' */
  real_T IsACCenabled_i;               /* '<S7>/Is ACC enabled' */
  real_T SwitchBrakeACConoff;          /* '<S3>/Switch Brake  ACC on//off' */
  real_T ReadUserdesiredspeed;         /* '<S7>/Read User desired speed' */
  real_T ReadSimulationTime;           /* '<S7>/Read Simulation Time' */
  real_T ReadInitVelocity;             /* '<S7>/Read Init Velocity' */
  real_T ReadCarvms;                   /* '<S7>/Read Car.v[m//s]' */
  real_T ACCActiveACCActualSpeed;      /* '<S7>/ACC Active ACC//Actual Speed' */
  real_T desiredorNOTSET;              /* '<S6>/desired or NOTSET' */
  real_T ReadinitdesiredtimegapfromInf;
                                /* '<S7>/Read init desired time gap from Inf' */
  real_T ReadinitpgainfromInf;         /* '<S15>/Read init p-gain from Inf' */
  real_T ReadCarax;                    /* '<S16>/Read Car.ax' */
  real_T ReadinitigainfromInf;         /* '<S15>/Read init i-gain from Inf' */
  real_T ReadCarvms_h;                 /* '<S13>/Read Car.v[m//s]' */
  real_T ReadinitspdctrlkvfromInf;   /* '<S13>/Read init spdctrl.kv from Inf' */
  real_T ReadinitdistctrlkdfromInf; /* '<S12>/Read init distctrl.kd from Inf' */
  real_T ReadinitdistctrlkvfromInf1;
                                   /* '<S12>/Read init distctrl.kv from Inf1' */
  real_T ReadCarvms_n;                 /* '<S8>/Read Car.v[m//s]' */
  real_T ReadinitmindistancefromInf;/* '<S8>/Read init min distance from Inf' */
  real_T MinMax;                       /* '<S8>/MinMax' */
} B_JenkinAcc_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Memory_PreviousInput;         /* '<S7>/Memory' */
  real_T Memory_PreviousInput_b;       /* '<S17>/Memory' */
  struct {
    void *SSensor;
  } SFunction_PWORK;                   /* '<S18>/S-Function' */

  struct {
    void *SSensor;
  } SFunction_PWORK_i;                 /* '<S19>/S-Function' */

  struct {
    void *Entry;
  } IsACCenabled_PWORK;                /* '<S5>/Is ACC enabled' */

  struct {
    void *Entry;
  } ReadUserdesiredtimegap_PWORK;      /* '<S7>/Read User desired time gap' */

  struct {
    void *InfoParam;
  } ReadinitbrakethresholdfromInf_PWORK;
                                 /* '<S3>/Read init brake threshold from Inf' */

  struct {
    void *Entry;
  } IsACCenabled_PWORK_b;              /* '<S7>/Is ACC enabled' */

  struct {
    void *Entry;
  } ReadUserdesiredspeed_PWORK;        /* '<S7>/Read User desired speed' */

  struct {
    void *Entry;
  } ReadSimulationTime_PWORK;          /* '<S7>/Read Simulation Time' */

  struct {
    void *InfoParam;
  } ReadInitVelocity_PWORK;            /* '<S7>/Read Init Velocity' */

  struct {
    void *Entry;
  } ReadCarvms_PWORK;                  /* '<S7>/Read Car.v[m//s]' */

  struct {
    void *Entry;
  } WritedesiredAx_PWORK;              /* '<S1>/Write desired Ax' */

  struct {
    void *Entry;
  } WriteACCIsActive_PWORK;            /* '<S3>/Write ACC IsActive' */

  struct {
    void *Entry;
  } WritedesiredAx_PWORK_p;            /* '<S3>/Write desired Ax' */

  struct {
    void *Entry;
  } Writedesiredspeed_PWORK;           /* '<S7>/Write desired speed' */

  struct {
    void *InfoParam;
  } ReadinitdesiredtimegapfromInf_PWORK;
                                /* '<S7>/Read init desired time gap from Inf' */

  struct {
    void *InfoParam;
  } ReadinitpgainfromInf_PWORK;        /* '<S15>/Read init p-gain from Inf' */

  struct {
    void *Entry;
  } ReadCarax_PWORK;                   /* '<S16>/Read Car.ax' */

  struct {
    void *InfoParam;
  } ReadinitigainfromInf_PWORK;        /* '<S15>/Read init i-gain from Inf' */

  struct {
    void *Entry;
  } Writeinittimegap_PWORK;            /* '<S14>/Write init time gap' */

  struct {
    void *Entry;
  } ReadCarvms_PWORK_e;                /* '<S13>/Read Car.v[m//s]' */

  struct {
    void *InfoParam;
  } ReadinitspdctrlkvfromInf_PWORK;  /* '<S13>/Read init spdctrl.kv from Inf' */

  struct {
    void *InfoParam;
  } ReadinitdistctrlkdfromInf_PWORK;/* '<S12>/Read init distctrl.kd from Inf' */

  struct {
    void *InfoParam;
  } ReadinitdistctrlkvfromInf1_PWORK;
                                   /* '<S12>/Read init distctrl.kv from Inf1' */

  struct {
    void *Entry;
  } ReadCarvms_PWORK_k;                /* '<S8>/Read Car.v[m//s]' */

  struct {
    void *InfoParam;
  } ReadinitmindistancefromInf_PWORK;
                                    /* '<S8>/Read init min distance from Inf' */

  struct {
    void *Entry;
  } Writedesireddistance_PWORK;        /* '<S8>/Write desired distance' */

  struct {
    int_T SIndex;
    int_T SIsFirstStep;
  } SFunction_IWORK;                   /* '<S18>/S-Function' */

  struct {
    int_T SIsFirstStep;
    int_T OSIndex;
  } SFunction_IWORK_i;                 /* '<S19>/S-Function' */

  struct {
    int_T Checked;
  } IsACCenabled_IWORK;                /* '<S5>/Is ACC enabled' */

  struct {
    int_T Checked;
  } ReadUserdesiredtimegap_IWORK;      /* '<S7>/Read User desired time gap' */

  struct {
    int_T Checked;
  } IsACCenabled_IWORK_n;              /* '<S7>/Is ACC enabled' */

  struct {
    int_T Checked;
  } ReadUserdesiredspeed_IWORK;        /* '<S7>/Read User desired speed' */

  struct {
    int_T Checked;
  } ReadSimulationTime_IWORK;          /* '<S7>/Read Simulation Time' */

  struct {
    int_T Checked;
  } ReadCarvms_IWORK;                  /* '<S7>/Read Car.v[m//s]' */

  struct {
    int_T Checked;
  } WritedesiredAx_IWORK;              /* '<S1>/Write desired Ax' */

  struct {
    int_T Checked;
  } WriteACCIsActive_IWORK;            /* '<S3>/Write ACC IsActive' */

  struct {
    int_T Checked;
  } WritedesiredAx_IWORK_i;            /* '<S3>/Write desired Ax' */

  struct {
    int_T Checked;
  } Writedesiredspeed_IWORK;           /* '<S7>/Write desired speed' */

  struct {
    int_T Checked;
  } ReadCarax_IWORK;                   /* '<S16>/Read Car.ax' */

  struct {
    int_T Checked;
  } Writeinittimegap_IWORK;            /* '<S14>/Write init time gap' */

  struct {
    int_T Checked;
  } ReadCarvms_IWORK_h;                /* '<S13>/Read Car.v[m//s]' */

  struct {
    int_T Checked;
  } ReadCarvms_IWORK_n;                /* '<S8>/Read Car.v[m//s]' */

  struct {
    int_T Checked;
  } Writedesireddistance_IWORK;        /* '<S8>/Write desired distance' */
} DW_JenkinAcc_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState InitDesiredtimegapquantity_Trig_ZCE;
                                     /* '<S7>/Init Desired time gap quantity' */
} PrevZCX_JenkinAcc_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Expression: xdefaults
   * Referenced by: '<S8>/Read init min distance from Inf'
   */
  real_T ReadinitmindistancefromInf_DefValue;

  /* Expression: xdefaults
   * Referenced by: '<S12>/Read init distctrl.kd from Inf'
   */
  real_T ReadinitdistctrlkdfromInf_DefValue;

  /* Expression: xdefaults
   * Referenced by: '<S12>/Read init distctrl.kv from Inf1'
   */
  real_T ReadinitdistctrlkvfromInf1_DefValue;

  /* Expression: xdefaults
   * Referenced by: '<S13>/Read init spdctrl.kv from Inf'
   */
  real_T ReadinitspdctrlkvfromInf_DefValue;

  /* Expression: xdefaults
   * Referenced by: '<S3>/Read init brake threshold from Inf'
   */
  real_T ReadinitbrakethresholdfromInf_DefValue;

  /* Expression: xdefaults
   * Referenced by: '<S7>/Read Init Velocity'
   */
  real_T ReadInitVelocity_DefValue;

  /* Expression: xdefaults
   * Referenced by: '<S7>/Read init desired time gap from Inf'
   */
  real_T ReadinitdesiredtimegapfromInf_DefValue;

  /* Pooled Parameter (Expression: xdefaults)
   * Referenced by:
   *   '<S15>/Read init i-gain from Inf'
   *   '<S15>/Read init p-gain from Inf'
   */
  real_T pooled1;
} ConstP_JenkinAcc_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  cmVehicleControlIn FromCM;           /* '<Root>/FromCM' */
} ExtU_JenkinAcc_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  cmVehicleControlOut ToCM;            /* '<Root>/ToCM' */
} ExtY_JenkinAcc_T;

/* Parameters (default storage) */
struct P_JenkinAcc_T_ {
  real_T desireddistance_Y0;           /* Expression: 0
                                        * Referenced by: '<S8>/desired distance'
                                        */
  real_T u5ax1_UpperSat;               /* Expression: 1
                                        * Referenced by: '<S9>/-2.5<=ax<=1'
                                        */
  real_T u5ax1_LowerSat;               /* Expression: -2.5
                                        * Referenced by: '<S9>/-2.5<=ax<=1'
                                        */
  real_T u35ax1_UpperSat;              /* Expression: 1
                                        * Referenced by: '<S10>/-0.35<=ax<=1'
                                        */
  real_T u35ax1_LowerSat;              /* Expression: -0.35
                                        * Referenced by: '<S10>/-0.35<=ax<=1'
                                        */
  real_T AxisNOTSET_Value;             /* Expression: -99999
                                        * Referenced by: '<S6>/Ax is NOTSET'
                                        */
  real_T kmh2ms_Gain;                  /* Expression: 0.28
                                        * Referenced by: '<S7>/kmh2ms'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S7>/Switch'
                                        */
  real_T ACCOff_Value;                 /* Expression: 0
                                        * Referenced by: '<S3>/ACC Off'
                                        */
  real_T Targetdv_Value;               /* Expression: -1
                                        * Referenced by: '<S5>/Target dv'
                                        */
  real_T Notarget_Value;               /* Expression: -1
                                        * Referenced by: '<S5>/No target'
                                        */
  real_T Brakeif1x0_UpperSat;          /* Expression: 0
                                        * Referenced by: '<S4>/Brake if -1<x<0'
                                        */
  real_T Brakeif1x0_LowerSat;          /* Expression: -1
                                        * Referenced by: '<S4>/Brake if -1<x<0'
                                        */
  real_T Gain_Gain;                    /* Expression: -1
                                        * Referenced by: '<S4>/Gain'
                                        */
  real_T Gasif0x1_UpperSat;            /* Expression: 1
                                        * Referenced by: '<S4>/Gas  if 0<=x<=1'
                                        */
  real_T Gasif0x1_LowerSat;            /* Expression: 0
                                        * Referenced by: '<S4>/Gas  if 0<=x<=1'
                                        */
  real_T ACCActiveACCActualSpeed_Threshold;/* Expression: 1
                                            * Referenced by: '<S7>/ACC Active ACC//Actual Speed'
                                            */
  real_T desiredorNOTSET_Threshold;    /* Expression: 1
                                        * Referenced by: '<S6>/desired or NOTSET'
                                        */
  real_T Memory_InitialCondition;      /* Expression: 0
                                        * Referenced by: '<S7>/Memory'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S7>/Constant'
                                        */
  real_T AxisNOTSET_Value_e;           /* Expression: -99999
                                        * Referenced by: '<S4>/Ax is NOTSET'
                                        */
  real_T Memory_InitialCondition_g;    /* Expression: 0
                                        * Referenced by: '<S17>/Memory'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 1
                                        * Referenced by: '<S15>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -1
                                        * Referenced by: '<S15>/Saturation'
                                        */
  real_T Saturation_UpperSat_f;        /* Expression: 1
                                        * Referenced by: '<S17>/Saturation'
                                        */
  real_T Saturation_LowerSat_e;        /* Expression: -1
                                        * Referenced by: '<S17>/Saturation'
                                        */
  boolean_T Constant_Value_n;          /* Computed Parameter: Constant_Value_n
                                        * Referenced by: '<S11>/Constant'
                                        */
  uint8_T desiredAx_Threshold;        /* Computed Parameter: desiredAx_Threshold
                                       * Referenced by: '<S6>/desired Ax'
                                       */
};

/* Real-time Model Data Structure */
struct tag_RTM_JenkinAcc_T {
  const char_T *errorStatus;
  B_JenkinAcc_T *blockIO;
  PrevZCX_JenkinAcc_T *prevZCSigState;
  ExtU_JenkinAcc_T *inputs;
  ExtY_JenkinAcc_T *outputs;
  DW_JenkinAcc_T *dwork;
};

/* Block parameters (default storage) */
extern P_JenkinAcc_T JenkinAcc_P;

/* External data declarations for dependent source files */
extern const cmVehicleControlIn JenkinAcc_rtZcmVehicleControlIn;/* cmVehicleControlIn ground */
extern const cmVehicleControlOut JenkinAcc_rtZcmVehicleControlOut;/* cmVehicleControlOut ground */
extern const char *RT_MEMORY_ALLOCATION_ERROR;
extern P_JenkinAcc_T JenkinAcc_P;      /* parameters */

/* Constant parameters (default storage) */
extern const ConstP_JenkinAcc_T JenkinAcc_ConstP;

/* Model entry point functions */
struct tInfos;
extern RT_MODEL_JenkinAcc_T *JenkinAcc(struct tInfos *inf);
extern void JenkinAcc_initialize(RT_MODEL_JenkinAcc_T *const JenkinAcc_M);
extern void JenkinAcc_step(RT_MODEL_JenkinAcc_T *const JenkinAcc_M);
extern void JenkinAcc_terminate(RT_MODEL_JenkinAcc_T * JenkinAcc_M);

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
 * '<Root>' : 'JenkinAcc'
 * '<S1>'   : 'JenkinAcc/AccelCtrl'
 * '<S2>'   : 'JenkinAcc/IF_Out_Selector'
 * '<S3>'   : 'JenkinAcc/AccelCtrl/ACC ECU'
 * '<S4>'   : 'JenkinAcc/AccelCtrl/AccelCtrl'
 * '<S5>'   : 'JenkinAcc/AccelCtrl/Sensor'
 * '<S6>'   : 'JenkinAcc/AccelCtrl/ACC ECU/ACC Control'
 * '<S7>'   : 'JenkinAcc/AccelCtrl/ACC ECU/ACC User Input'
 * '<S8>'   : 'JenkinAcc/AccelCtrl/ACC ECU/ACC Control/Desired Distance Calculation with time gap'
 * '<S9>'   : 'JenkinAcc/AccelCtrl/ACC ECU/ACC Control/Distance Control Algorithm'
 * '<S10>'  : 'JenkinAcc/AccelCtrl/ACC ECU/ACC Control/Speed Control Algorithm'
 * '<S11>'  : 'JenkinAcc/AccelCtrl/ACC ECU/ACC Control/Target detected'
 * '<S12>'  : 'JenkinAcc/AccelCtrl/ACC ECU/ACC Control/Distance Control Algorithm/desired ax'
 * '<S13>'  : 'JenkinAcc/AccelCtrl/ACC ECU/ACC Control/Speed Control Algorithm/desired ax'
 * '<S14>'  : 'JenkinAcc/AccelCtrl/ACC ECU/ACC User Input/Init Desired time gap quantity'
 * '<S15>'  : 'JenkinAcc/AccelCtrl/AccelCtrl/PI-Controller'
 * '<S16>'  : 'JenkinAcc/AccelCtrl/AccelCtrl/controlled process variable '
 * '<S17>'  : 'JenkinAcc/AccelCtrl/AccelCtrl/PI-Controller/Integrator'
 * '<S18>'  : 'JenkinAcc/AccelCtrl/Sensor/Car ObjectSensor'
 * '<S19>'  : 'JenkinAcc/AccelCtrl/Sensor/Car ObjectSensor Object'
 */
#endif                                 /* RTW_HEADER_JenkinAcc_h_ */
