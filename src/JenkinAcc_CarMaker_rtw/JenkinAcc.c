/*
 * JenkinAcc.c
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

#include <infoc.h>
#include <Log.h>
#include <InfoParam.h>
#include <DataDict.h>
#include <MatSupp.h>
#include "JenkinAcc.h"
#include "JenkinAcc_private.h"
#include "JenkinAcc_wrap.h"

/* CarMaker: Compile- and link-time checks for the right Matlab version. */
#if MATSUPP_NUMVER == 90900

/* The following statement will cause an "unresolved symbol" error when
   linking with a MatSupp library built for the wrong Matlab version. */
extern int MATSUPP_VARNAME(MatSupp, MATSUPP_NUMVER);
void *MATSUPP_VARNAME(MODEL, MATSUPP_NUMVER) = &MATSUPP_VARNAME(MatSupp,
  MATSUPP_NUMVER);

#else
# error Compiler options unsuitable for C code created with Matlab 9.9
#endif

const cmVehicleControlOut JenkinAcc_rtZcmVehicleControlOut = {
  0.0,                                 /* SST */
  0.0,                                 /* Key */

  {
    0.0,                               /* s0 */
    0.0,                               /* s1 */
    0.0,                               /* s2 */
    0.0,                               /* s3 */
    0.0                                /* s4 */
  },                                   /* UserSignal */
  0.0,                                 /* GearNo */
  0.0,                                 /* SelectorCtrl */
  0.0,                                 /* Brake */
  0.0,                                 /* BrakePark */
  0.0,                                 /* BrakeLever */
  0.0,                                 /* Clutch */
  0.0,                                 /* Gas */

  {
    0.0,                               /* Ang */
    0.0,                               /* AngVel */
    0.0,                               /* AngAcc */
    0.0                                /* Trq */
  },                                   /* Steering */

  {
    0.0,                               /* RollAng */
    0.0                                /* RollAngVel */
  },                                   /* Rider */

  {
    0.0,                               /* LowBeam */
    0.0,                               /* HighBeam */
    0.0,                               /* Daytime */
    0.0,                               /* ParkL */
    0.0,                               /* ParkR */
    0.0,                               /* IndL */
    0.0,                               /* IndR */
    0.0,                               /* FogFrontL */
    0.0,                               /* FogFrontR */
    0.0,                               /* FogRear */
    0.0,                               /* Brake */
    0.0                                /* Reverse */
  }                                    /* Lights */
} ;                                    /* cmVehicleControlOut ground */

const cmVehicleControlIn JenkinAcc_rtZcmVehicleControlIn = { 0.0,/* SST */
  0.0,                                 /* Key */
  { 0.0,                               /* s0 */
    0.0,                               /* s1 */
    0.0,                               /* s2 */
    0.0,                               /* s3 */
    0.0                                /* s4 */
  },                                   /* UserSignal */
  0.0,                                 /* GearNo */
  0.0,                                 /* SelectorCtrl */
  0.0,                                 /* Brake */
  0.0,                                 /* BrakePark */
  0.0,                                 /* BrakeLever */
  0.0,                                 /* Clutch */
  0.0,                                 /* Gas */
  { 0.0,                               /* Ang */
    0.0,                               /* AngVel */
    0.0,                               /* AngAcc */
    0.0                                /* Trq */
  },                                   /* Steering */
  { 0.0,                               /* RollAng */
    0.0                                /* RollAngVel */
  },                                   /* Rider */
  { 0.0,                               /* LowBeam */
    0.0,                               /* HighBeam */
    0.0,                               /* Daytime */
    0.0,                               /* ParkL */
    0.0,                               /* ParkR */
    0.0,                               /* IndL */
    0.0,                               /* IndR */
    0.0,                               /* FogFrontL */
    0.0,                               /* FogFrontR */
    0.0,                               /* FogRear */
    0.0,                               /* Brake */
    0.0                                /* Reverse */
  }                                    /* Lights */
};

/* Model step function */
void JenkinAcc_step(RT_MODEL_JenkinAcc_T *const JenkinAcc_M)
{
  B_JenkinAcc_T *JenkinAcc_B = JenkinAcc_M->blockIO;
  DW_JenkinAcc_T *JenkinAcc_DW = JenkinAcc_M->dwork;
  PrevZCX_JenkinAcc_T *JenkinAcc_PrevZCX = JenkinAcc_M->prevZCSigState;
  ExtU_JenkinAcc_T *JenkinAcc_U = (ExtU_JenkinAcc_T *) JenkinAcc_M->inputs;
  ExtY_JenkinAcc_T *JenkinAcc_Y = (ExtY_JenkinAcc_T *) JenkinAcc_M->outputs;
  real_T rtb_dvms;
  real_T rtb_targetdetected_0;
  real_T rtb_u35ax1;
  uint8_T rtb_Compare;
  boolean_T rtb_targetdetected;
  ZCEventType zcEvent;

  /* S-Function (cm_sensor_object): '<S18>/S-Function' */
  {
    const tObjectSensor *os;
    int sindex;
    static tObjectSensor ZeroSensor = { .relvTargetObjId = -1 };

    if (JenkinAcc_DW->SFunction_IWORK.SIsFirstStep) {
      JenkinAcc_DW->SFunction_IWORK.SIndex = ObjectSensor_FindIndexForName(
        "RadarL");
      JenkinAcc_DW->SFunction_PWORK.SSensor = ObjectSensor_GetByIndex
        (JenkinAcc_DW->SFunction_IWORK.SIndex);
      if (JenkinAcc_DW->SFunction_PWORK.SSensor == NULL) {
        JenkinAcc_DW->SFunction_PWORK.SSensor = &ZeroSensor;
        JenkinAcc_DW->SFunction_IWORK.SIndex = -1;
      }

      JenkinAcc_DW->SFunction_IWORK.SIsFirstStep = 0;
    }

    sindex = JenkinAcc_DW->SFunction_IWORK.SIndex;
    os = (const tObjectSensor *)JenkinAcc_DW->SFunction_PWORK.SSensor;
    JenkinAcc_B->SFunction_o1 = sindex;
    JenkinAcc_B->SFunction_o2[0] = os->trtype;
    JenkinAcc_B->SFunction_o2[1] = os->Range;
    JenkinAcc_B->SFunction_o2[2] = os->FoV[0];
    JenkinAcc_B->SFunction_o2[3] = os->FoV[1];
    JenkinAcc_B->SFunction_o2[4] = os->rot_zyx[0];
    JenkinAcc_B->SFunction_o2[5] = os->rot_zyx[1];
    JenkinAcc_B->SFunction_o2[6] = os->rot_zyx[2];
    JenkinAcc_B->SFunction_o2[7] = os->DrvLaneCurv;
    JenkinAcc_B->SFunction_o3 = os->nObsvObjects;
    JenkinAcc_B->SFunction_o4[0] = os->Targ_Dtct;
    JenkinAcc_B->SFunction_o4[1] = os->relvTargetObjId;
  }

  /* S-Function (cm_sensor_object_obj): '<S19>/S-Function' */
  {
    int osindex, obindex;
    const tObjectSensor *os;
    const tObjectSensorObj *ob;
    static tObjectSensor ZeroSensor = { .relvTargetObjId = -1 };

    static tObjectSensorObj ZeroObject = { .ObjId = -1 };

    osindex = JenkinAcc_B->SFunction_o1;
    if (SimCore.State != SCState_Simulate ||
        (os = ObjectSensor_GetByIndex(osindex)) == NULL) {
      os = &ZeroSensor;
      osindex = -1;
    }

    obindex = JenkinAcc_B->SFunction_o4[1];
    if (obindex == 99999) {
      obindex = os->relvTargetObjId;
    } else {
    }

    ob = ObjectSensor_GetObjectByObjId(osindex, obindex);
    if (ob == NULL) {
      ob = &ZeroObject;
      obindex = -1;
    }

    JenkinAcc_B->SFunction_o1_a = obindex;
    JenkinAcc_B->SFunction_o2_e[0] = Traffic_ObjId2TrfId(ob->ObjId);
    JenkinAcc_B->SFunction_o2_e[1] = ob->w;
    JenkinAcc_B->SFunction_o2_e[2] = ob->h;
    JenkinAcc_B->SFunction_o2_e[3] = ob->l;
    JenkinAcc_B->SFunction_o2_e[4] = ob->zOff;
    JenkinAcc_B->SFunction_o2_e[5] = ob->ObjId;
    JenkinAcc_B->SFunction_o3_m[0] = ob->obsv;
    JenkinAcc_B->SFunction_o3_m[1] = ob->dtct;
    JenkinAcc_B->SFunction_o4_c[0] = ob->RefPnt.ds[0];
    JenkinAcc_B->SFunction_o4_c[1] = ob->RefPnt.ds[1];
    JenkinAcc_B->SFunction_o4_c[2] = ob->RefPnt.ds[2];
    JenkinAcc_B->SFunction_o4_c[3] = ob->RefPnt.ds_p;
    JenkinAcc_B->SFunction_o4_c[4] = ob->RefPnt.dv[0];
    JenkinAcc_B->SFunction_o4_c[5] = ob->RefPnt.dv[1];
    JenkinAcc_B->SFunction_o4_c[6] = ob->RefPnt.dv[2];
    JenkinAcc_B->SFunction_o4_c[7] = ob->RefPnt.dv_p;
    JenkinAcc_B->SFunction_o4_c[8] = ob->RefPnt.alpha_p;
    JenkinAcc_B->SFunction_o4_c[9] = ob->RefPnt.theta_p;
    JenkinAcc_B->SFunction_o4_c[10] = ob->RefPnt.r_zyx[0];
    JenkinAcc_B->SFunction_o4_c[11] = ob->RefPnt.r_zyx[1];
    JenkinAcc_B->SFunction_o4_c[12] = ob->RefPnt.r_zyx[2];
    JenkinAcc_B->SFunction_o5[0] = ob->NearPnt.ds[0];
    JenkinAcc_B->SFunction_o5[1] = ob->NearPnt.ds[1];
    JenkinAcc_B->SFunction_o5[2] = ob->NearPnt.ds[2];
    JenkinAcc_B->SFunction_o5[3] = ob->NearPnt.ds_p;
    JenkinAcc_B->SFunction_o5[4] = ob->NearPnt.dv[0];
    JenkinAcc_B->SFunction_o5[5] = ob->NearPnt.dv[1];
    JenkinAcc_B->SFunction_o5[6] = ob->NearPnt.dv[2];
    JenkinAcc_B->SFunction_o5[7] = ob->NearPnt.dv_p;
    JenkinAcc_B->SFunction_o5[8] = ob->NearPnt.alpha_p;
    JenkinAcc_B->SFunction_o5[9] = ob->NearPnt.theta_p;
    JenkinAcc_B->SFunction_o5[10] = ob->NearPnt.r_zyx[0];
    JenkinAcc_B->SFunction_o5[11] = ob->NearPnt.r_zyx[1];
    JenkinAcc_B->SFunction_o5[12] = ob->NearPnt.r_zyx[2];
    JenkinAcc_B->SFunction_o6[0] = ob->incangle[0];
    JenkinAcc_B->SFunction_o6[1] = ob->incangle[1];
    JenkinAcc_B->SFunction_o6[2] = ob->ImgArea_NearP;
    JenkinAcc_B->SFunction_o6[3] = ob->ImgArea_LeftP;
    JenkinAcc_B->SFunction_o6[4] = ob->ImgArea_RightP;
  }

  /* S-Function (read_dict): '<S5>/Is ACC enabled' */
  {
    tDDictEntry *e;
    e = (tDDictEntry *)JenkinAcc_DW->IsACCenabled_PWORK.Entry;
    if (!JenkinAcc_DW->IsACCenabled_IWORK.Checked) {
      JenkinAcc_DW->IsACCenabled_IWORK.Checked = 1;
      DDictErrorUponFakedEntry(e, "Model 'JenkinAcc'");
    }

    JenkinAcc_B->IsACCenabled = e->GetFunc(e->Var);
  }

  /* Logic: '<S5>/Logical Operator' */
  rtb_targetdetected = ((JenkinAcc_B->IsACCenabled != 0.0) &&
                        (JenkinAcc_B->SFunction_o4[0] != 0.0));

  /* Switch: '<S5>/Switch1' incorporates:
   *  Constant: '<S5>/Target dv'
   */
  if (rtb_targetdetected) {
    rtb_dvms = JenkinAcc_B->SFunction_o5[7];
  } else {
    rtb_dvms = JenkinAcc_P.Targetdv_Value;
  }

  /* End of Switch: '<S5>/Switch1' */

  /* S-Function (read_dict): '<S7>/Read User desired time gap' */
  {
    tDDictEntry *e;
    e = (tDDictEntry *)JenkinAcc_DW->ReadUserdesiredtimegap_PWORK.Entry;
    if (!JenkinAcc_DW->ReadUserdesiredtimegap_IWORK.Checked) {
      JenkinAcc_DW->ReadUserdesiredtimegap_IWORK.Checked = 1;
      DDictErrorUponFakedEntry(e, "Model 'JenkinAcc'");
    }

    JenkinAcc_B->ReadUserdesiredtimegap = e->GetFunc(e->Var);
  }

  /* S-Function (read_infoparam): '<S3>/Read init brake threshold from Inf' */
  {
    const double *vec = InfoParam_GetVec
      (JenkinAcc_DW->ReadinitbrakethresholdfromInf_PWORK.InfoParam, NULL);
    JenkinAcc_B->ReadinitbrakethresholdfromInf = *vec++;
  }

  /* S-Function (read_dict): '<S7>/Is ACC enabled' */
  {
    tDDictEntry *e;
    e = (tDDictEntry *)JenkinAcc_DW->IsACCenabled_PWORK_b.Entry;
    if (!JenkinAcc_DW->IsACCenabled_IWORK_n.Checked) {
      JenkinAcc_DW->IsACCenabled_IWORK_n.Checked = 1;
      DDictErrorUponFakedEntry(e, "Model 'JenkinAcc'");
    }

    JenkinAcc_B->IsACCenabled_i = e->GetFunc(e->Var);
  }

  /* Switch: '<S3>/Switch Brake  ACC on//off' incorporates:
   *  Inport: '<Root>/FromCM'
   *  RelationalOperator: '<S3>/Relational Operator'
   */
  if (JenkinAcc_U->FromCM.Brake > JenkinAcc_B->ReadinitbrakethresholdfromInf) {
    /* Switch: '<S3>/Switch Brake  ACC on//off' incorporates:
     *  Constant: '<S3>/ACC Off'
     */
    JenkinAcc_B->SwitchBrakeACConoff = JenkinAcc_P.ACCOff_Value;
  } else {
    /* Switch: '<S3>/Switch Brake  ACC on//off' */
    JenkinAcc_B->SwitchBrakeACConoff = JenkinAcc_B->IsACCenabled_i;
  }

  /* End of Switch: '<S3>/Switch Brake  ACC on//off' */

  /* RelationalOperator: '<S11>/Compare' incorporates:
   *  Constant: '<S11>/Constant'
   */
  rtb_Compare = (uint8_T)((int32_T)rtb_targetdetected > (int32_T)
    JenkinAcc_P.Constant_Value_n);

  /* Outputs for Enabled SubSystem: '<S6>/Desired Distance Calculation with time gap' incorporates:
   *  EnablePort: '<S8>/Enable'
   */
  /* Logic: '<S6>/Logical Operator' */
  if ((JenkinAcc_B->SwitchBrakeACConoff != 0.0) && (rtb_Compare != 0)) {
    /* S-Function (read_dict): '<S8>/Read Car.v[m//s]' */
    {
      tDDictEntry *e;
      e = (tDDictEntry *)JenkinAcc_DW->ReadCarvms_PWORK_k.Entry;
      if (!JenkinAcc_DW->ReadCarvms_IWORK_n.Checked) {
        JenkinAcc_DW->ReadCarvms_IWORK_n.Checked = 1;
        DDictErrorUponFakedEntry(e, "Model 'JenkinAcc'");
      }

      JenkinAcc_B->ReadCarvms_n = e->GetFunc(e->Var);
    }

    /* S-Function (read_infoparam): '<S8>/Read init min distance from Inf' */
    {
      const double *vec = InfoParam_GetVec
        (JenkinAcc_DW->ReadinitmindistancefromInf_PWORK.InfoParam, NULL);
      JenkinAcc_B->ReadinitmindistancefromInf = *vec++;
    }

    /* MinMax: '<S8>/MinMax' incorporates:
     *  Product: '<S8>/Product'
     *  Sum: '<S8>/Add'
     */
    JenkinAcc_B->MinMax = fmax((rtb_dvms + JenkinAcc_B->ReadCarvms_n) *
      JenkinAcc_B->ReadUserdesiredtimegap,
      JenkinAcc_B->ReadinitmindistancefromInf);

    /* S-Function (write_dict): '<S8>/Write desired distance' */
    {
      tDDictEntry *e;
      real_T value;
      e = (tDDictEntry *)JenkinAcc_DW->Writedesireddistance_PWORK.Entry;
      if (!JenkinAcc_DW->Writedesireddistance_IWORK.Checked) {
        JenkinAcc_DW->Writedesireddistance_IWORK.Checked = 1;
        DDictErrorUponFakedEntry(e, "Model 'JenkinAcc'");
      }

      value = JenkinAcc_B->MinMax;
      DVA_PokeSL(e, value);
    }
  }

  /* End of Logic: '<S6>/Logical Operator' */
  /* End of Outputs for SubSystem: '<S6>/Desired Distance Calculation with time gap' */

  /* S-Function (read_dict): '<S7>/Read User desired speed' */
  {
    tDDictEntry *e;
    e = (tDDictEntry *)JenkinAcc_DW->ReadUserdesiredspeed_PWORK.Entry;
    if (!JenkinAcc_DW->ReadUserdesiredspeed_IWORK.Checked) {
      JenkinAcc_DW->ReadUserdesiredspeed_IWORK.Checked = 1;
      DDictErrorUponFakedEntry(e, "Model 'JenkinAcc'");
    }

    JenkinAcc_B->ReadUserdesiredspeed = e->GetFunc(e->Var);
  }

  /* S-Function (read_dict): '<S7>/Read Simulation Time' */
  {
    tDDictEntry *e;
    e = (tDDictEntry *)JenkinAcc_DW->ReadSimulationTime_PWORK.Entry;
    if (!JenkinAcc_DW->ReadSimulationTime_IWORK.Checked) {
      JenkinAcc_DW->ReadSimulationTime_IWORK.Checked = 1;
      DDictErrorUponFakedEntry(e, "Model 'JenkinAcc'");
    }

    JenkinAcc_B->ReadSimulationTime = e->GetFunc(e->Var);
  }

  /* S-Function (read_infoparam): '<S7>/Read Init Velocity' */
  {
    const double *vec = InfoParam_GetVec
      (JenkinAcc_DW->ReadInitVelocity_PWORK.InfoParam, NULL);
    JenkinAcc_B->ReadInitVelocity = *vec++;
  }

  /* S-Function (read_dict): '<S7>/Read Car.v[m//s]' */
  {
    tDDictEntry *e;
    e = (tDDictEntry *)JenkinAcc_DW->ReadCarvms_PWORK.Entry;
    if (!JenkinAcc_DW->ReadCarvms_IWORK.Checked) {
      JenkinAcc_DW->ReadCarvms_IWORK.Checked = 1;
      DDictErrorUponFakedEntry(e, "Model 'JenkinAcc'");
    }

    JenkinAcc_B->ReadCarvms = e->GetFunc(e->Var);
  }

  /* Switch: '<S7>/ACC Active ACC//Actual Speed' */
  if (JenkinAcc_B->IsACCenabled_i >=
      JenkinAcc_P.ACCActiveACCActualSpeed_Threshold) {
    /* Switch: '<S7>/Switch' */
    if (JenkinAcc_B->ReadSimulationTime > JenkinAcc_P.Switch_Threshold) {
      /* Switch: '<S7>/ACC Active ACC//Actual Speed' */
      JenkinAcc_B->ACCActiveACCActualSpeed = JenkinAcc_B->ReadUserdesiredspeed;
    } else {
      /* Switch: '<S7>/ACC Active ACC//Actual Speed' incorporates:
       *  Gain: '<S7>/kmh2ms'
       */
      JenkinAcc_B->ACCActiveACCActualSpeed = JenkinAcc_P.kmh2ms_Gain *
        JenkinAcc_B->ReadInitVelocity;
    }

    /* End of Switch: '<S7>/Switch' */
  } else {
    /* Switch: '<S7>/ACC Active ACC//Actual Speed' */
    JenkinAcc_B->ACCActiveACCActualSpeed = JenkinAcc_B->ReadCarvms;
  }

  /* End of Switch: '<S7>/ACC Active ACC//Actual Speed' */

  /* Outputs for Atomic SubSystem: '<S6>/Speed Control Algorithm' */
  /* S-Function (read_dict): '<S13>/Read Car.v[m//s]' */
  {
    tDDictEntry *e;
    e = (tDDictEntry *)JenkinAcc_DW->ReadCarvms_PWORK_e.Entry;
    if (!JenkinAcc_DW->ReadCarvms_IWORK_h.Checked) {
      JenkinAcc_DW->ReadCarvms_IWORK_h.Checked = 1;
      DDictErrorUponFakedEntry(e, "Model 'JenkinAcc'");
    }

    JenkinAcc_B->ReadCarvms_h = e->GetFunc(e->Var);
  }

  /* S-Function (read_infoparam): '<S13>/Read init spdctrl.kv from Inf' */
  {
    const double *vec = InfoParam_GetVec
      (JenkinAcc_DW->ReadinitspdctrlkvfromInf_PWORK.InfoParam, NULL);
    JenkinAcc_B->ReadinitspdctrlkvfromInf = *vec++;
  }

  /* Product: '<S13>/Divide' incorporates:
   *  Sum: '<S13>/Sum'
   */
  rtb_u35ax1 = (JenkinAcc_B->ACCActiveACCActualSpeed - JenkinAcc_B->ReadCarvms_h)
    / JenkinAcc_B->ReadinitspdctrlkvfromInf;

  /* End of Outputs for SubSystem: '<S6>/Speed Control Algorithm' */

  /* Outputs for Atomic SubSystem: '<S6>/Distance Control Algorithm' */
  /* S-Function (read_infoparam): '<S12>/Read init distctrl.kd from Inf' */
  {
    const double *vec = InfoParam_GetVec
      (JenkinAcc_DW->ReadinitdistctrlkdfromInf_PWORK.InfoParam, NULL);
    JenkinAcc_B->ReadinitdistctrlkdfromInf = *vec++;
  }

  /* S-Function (read_infoparam): '<S12>/Read init distctrl.kv from Inf1' */
  {
    const double *vec = InfoParam_GetVec
      (JenkinAcc_DW->ReadinitdistctrlkvfromInf1_PWORK.InfoParam, NULL);
    JenkinAcc_B->ReadinitdistctrlkvfromInf1 = *vec++;
  }

  /* End of Outputs for SubSystem: '<S6>/Distance Control Algorithm' */

  /* Switch: '<S6>/desired or NOTSET' */
  if (JenkinAcc_B->SwitchBrakeACConoff >= JenkinAcc_P.desiredorNOTSET_Threshold)
  {
    /* Switch: '<S6>/desired Ax' incorporates:
     *  Saturate: '<S10>/-0.35<=ax<=1'
     */
    if (rtb_Compare >= JenkinAcc_P.desiredAx_Threshold) {
      /* Switch: '<S5>/Switch' incorporates:
       *  Constant: '<S5>/No target'
       */
      if (rtb_targetdetected) {
        rtb_targetdetected_0 = JenkinAcc_B->SFunction_o5[3];
      } else {
        rtb_targetdetected_0 = JenkinAcc_P.Notarget_Value;
      }

      /* End of Switch: '<S5>/Switch' */

      /* Outputs for Atomic SubSystem: '<S6>/Speed Control Algorithm' */
      /* Saturate: '<S10>/-0.35<=ax<=1' */
      if (rtb_u35ax1 > JenkinAcc_P.u35ax1_UpperSat) {
        rtb_u35ax1 = JenkinAcc_P.u35ax1_UpperSat;
      } else {
        if (rtb_u35ax1 < JenkinAcc_P.u35ax1_LowerSat) {
          rtb_u35ax1 = JenkinAcc_P.u35ax1_LowerSat;
        }
      }

      /* End of Outputs for SubSystem: '<S6>/Speed Control Algorithm' */

      /* Outputs for Atomic SubSystem: '<S6>/Distance Control Algorithm' */
      /* MinMax: '<S12>/MinMax' incorporates:
       *  Product: '<S12>/Divide'
       *  Product: '<S12>/Divide1'
       *  Sum: '<S12>/Add'
       *  Sum: '<S12>/Subtract'
       */
      rtb_u35ax1 = fmin((rtb_targetdetected_0 - JenkinAcc_B->MinMax) /
                        JenkinAcc_B->ReadinitdistctrlkdfromInf + rtb_dvms /
                        JenkinAcc_B->ReadinitdistctrlkvfromInf1, rtb_u35ax1);

      /* Saturate: '<S9>/-2.5<=ax<=1' */
      if (rtb_u35ax1 > JenkinAcc_P.u5ax1_UpperSat) {
        /* Switch: '<S6>/desired or NOTSET' */
        JenkinAcc_B->desiredorNOTSET = JenkinAcc_P.u5ax1_UpperSat;
      } else if (rtb_u35ax1 < JenkinAcc_P.u5ax1_LowerSat) {
        /* Switch: '<S6>/desired or NOTSET' */
        JenkinAcc_B->desiredorNOTSET = JenkinAcc_P.u5ax1_LowerSat;
      } else {
        /* Switch: '<S6>/desired or NOTSET' */
        JenkinAcc_B->desiredorNOTSET = rtb_u35ax1;
      }

      /* End of Saturate: '<S9>/-2.5<=ax<=1' */
      /* End of Outputs for SubSystem: '<S6>/Distance Control Algorithm' */
    } else {
      /* Outputs for Atomic SubSystem: '<S6>/Speed Control Algorithm' */
      if (rtb_u35ax1 > JenkinAcc_P.u35ax1_UpperSat) {
        /* Saturate: '<S10>/-0.35<=ax<=1' incorporates:
         *  Switch: '<S6>/desired or NOTSET'
         */
        JenkinAcc_B->desiredorNOTSET = JenkinAcc_P.u35ax1_UpperSat;
      } else if (rtb_u35ax1 < JenkinAcc_P.u35ax1_LowerSat) {
        /* Saturate: '<S10>/-0.35<=ax<=1' incorporates:
         *  Switch: '<S6>/desired or NOTSET'
         */
        JenkinAcc_B->desiredorNOTSET = JenkinAcc_P.u35ax1_LowerSat;
      } else {
        /* Switch: '<S6>/desired or NOTSET' incorporates:
         *  Saturate: '<S10>/-0.35<=ax<=1'
         */
        JenkinAcc_B->desiredorNOTSET = rtb_u35ax1;
      }

      /* End of Outputs for SubSystem: '<S6>/Speed Control Algorithm' */
    }

    /* End of Switch: '<S6>/desired Ax' */
  } else {
    /* Switch: '<S6>/desired or NOTSET' incorporates:
     *  Constant: '<S6>/Ax is NOTSET'
     */
    JenkinAcc_B->desiredorNOTSET = JenkinAcc_P.AxisNOTSET_Value;
  }

  /* End of Switch: '<S6>/desired or NOTSET' */

  /* S-Function (write_dict): '<S1>/Write desired Ax' */
  {
    tDDictEntry *e;
    real_T value;
    e = (tDDictEntry *)JenkinAcc_DW->WritedesiredAx_PWORK.Entry;
    if (!JenkinAcc_DW->WritedesiredAx_IWORK.Checked) {
      JenkinAcc_DW->WritedesiredAx_IWORK.Checked = 1;
      DDictErrorUponFakedEntry(e, "Model 'JenkinAcc'");
    }

    value = JenkinAcc_B->desiredorNOTSET;
    DVA_PokeSL(e, value);
  }

  /* S-Function (write_dict): '<S3>/Write ACC IsActive' */
  {
    tDDictEntry *e;
    real_T value;
    e = (tDDictEntry *)JenkinAcc_DW->WriteACCIsActive_PWORK.Entry;
    if (!JenkinAcc_DW->WriteACCIsActive_IWORK.Checked) {
      JenkinAcc_DW->WriteACCIsActive_IWORK.Checked = 1;
      DDictErrorUponFakedEntry(e, "Model 'JenkinAcc'");
    }

    value = JenkinAcc_B->SwitchBrakeACConoff;
    DVA_PokeSL(e, value);
  }

  /* S-Function (write_dict): '<S3>/Write desired Ax' */
  {
    tDDictEntry *e;
    real_T value;
    e = (tDDictEntry *)JenkinAcc_DW->WritedesiredAx_PWORK_p.Entry;
    if (!JenkinAcc_DW->WritedesiredAx_IWORK_i.Checked) {
      JenkinAcc_DW->WritedesiredAx_IWORK_i.Checked = 1;
      DDictErrorUponFakedEntry(e, "Model 'JenkinAcc'");
    }

    value = JenkinAcc_B->desiredorNOTSET;
    DVA_PokeSL(e, value);
  }

  /* S-Function (write_dict): '<S7>/Write desired speed' */
  {
    tDDictEntry *e;
    real_T value;
    e = (tDDictEntry *)JenkinAcc_DW->Writedesiredspeed_PWORK.Entry;
    if (!JenkinAcc_DW->Writedesiredspeed_IWORK.Checked) {
      JenkinAcc_DW->Writedesiredspeed_IWORK.Checked = 1;
      DDictErrorUponFakedEntry(e, "Model 'JenkinAcc'");
    }

    value = JenkinAcc_B->ACCActiveACCActualSpeed;
    DVA_PokeSL(e, value);
  }

  /* S-Function (read_infoparam): '<S7>/Read init desired time gap from Inf' */
  {
    const double *vec = InfoParam_GetVec
      (JenkinAcc_DW->ReadinitdesiredtimegapfromInf_PWORK.InfoParam, NULL);
    JenkinAcc_B->ReadinitdesiredtimegapfromInf = *vec++;
  }

  /* Outputs for Triggered SubSystem: '<S7>/Init Desired time gap quantity' incorporates:
   *  TriggerPort: '<S14>/Trigger'
   */
  /* Memory: '<S7>/Memory' */
  zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                     &JenkinAcc_PrevZCX->InitDesiredtimegapquantity_Trig_ZCE,
                     (JenkinAcc_DW->Memory_PreviousInput));
  if (zcEvent != NO_ZCEVENT) {
    /* S-Function (write_dict): '<S14>/Write init time gap' */
    {
      tDDictEntry *e;
      real_T value;
      e = (tDDictEntry *)JenkinAcc_DW->Writeinittimegap_PWORK.Entry;
      if (!JenkinAcc_DW->Writeinittimegap_IWORK.Checked) {
        JenkinAcc_DW->Writeinittimegap_IWORK.Checked = 1;
        DDictErrorUponFakedEntry(e, "Model 'JenkinAcc'");
      }

      value = JenkinAcc_B->ReadinitdesiredtimegapfromInf;
      DVA_PokeSL(e, value);
    }
  }

  /* End of Outputs for SubSystem: '<S7>/Init Desired time gap quantity' */
  /* S-Function (read_infoparam): '<S15>/Read init p-gain from Inf' */
  {
    const double *vec = InfoParam_GetVec
      (JenkinAcc_DW->ReadinitpgainfromInf_PWORK.InfoParam, NULL);
    JenkinAcc_B->ReadinitpgainfromInf = *vec++;
  }

  /* S-Function (read_dict): '<S16>/Read Car.ax' */
  {
    tDDictEntry *e;
    e = (tDDictEntry *)JenkinAcc_DW->ReadCarax_PWORK.Entry;
    if (!JenkinAcc_DW->ReadCarax_IWORK.Checked) {
      JenkinAcc_DW->ReadCarax_IWORK.Checked = 1;
      DDictErrorUponFakedEntry(e, "Model 'JenkinAcc'");
    }

    JenkinAcc_B->ReadCarax = e->GetFunc(e->Var);
  }

  /* Sum: '<S16>/Subtract' */
  rtb_dvms = JenkinAcc_B->desiredorNOTSET - JenkinAcc_B->ReadCarax;

  /* Product: '<S15>/p-gain' */
  rtb_u35ax1 = JenkinAcc_B->ReadinitpgainfromInf * rtb_dvms;

  /* S-Function (read_infoparam): '<S15>/Read init i-gain from Inf' */
  {
    const double *vec = InfoParam_GetVec
      (JenkinAcc_DW->ReadinitigainfromInf_PWORK.InfoParam, NULL);
    JenkinAcc_B->ReadinitigainfromInf = *vec++;
  }

  /* RelationalOperator: '<S4>/Relational Operator' incorporates:
   *  Constant: '<S4>/Ax is NOTSET'
   */
  rtb_targetdetected = (JenkinAcc_B->desiredorNOTSET !=
                        JenkinAcc_P.AxisNOTSET_Value_e);

  /* Switch: '<S17>/Switch Ax  Init I-Part' incorporates:
   *  Inport: '<Root>/FromCM'
   *  Memory: '<S17>/Memory'
   */
  if (rtb_targetdetected) {
    rtb_targetdetected_0 = JenkinAcc_DW->Memory_PreviousInput_b;
  } else {
    rtb_targetdetected_0 = JenkinAcc_U->FromCM.Gas;
  }

  /* End of Switch: '<S17>/Switch Ax  Init I-Part' */

  /* Sum: '<S17>/Add1' incorporates:
   *  Product: '<S15>/i-gain'
   */
  rtb_dvms = rtb_dvms * JenkinAcc_B->ReadinitigainfromInf + rtb_targetdetected_0;

  /* Sum: '<S15>/Add' */
  rtb_u35ax1 += rtb_dvms;

  /* Saturate: '<S15>/Saturation' */
  if (rtb_u35ax1 > JenkinAcc_P.Saturation_UpperSat) {
    rtb_u35ax1 = JenkinAcc_P.Saturation_UpperSat;
  } else {
    if (rtb_u35ax1 < JenkinAcc_P.Saturation_LowerSat) {
      rtb_u35ax1 = JenkinAcc_P.Saturation_LowerSat;
    }
  }

  /* End of Saturate: '<S15>/Saturation' */

  /* Saturate: '<S17>/Saturation' */
  if (rtb_dvms > JenkinAcc_P.Saturation_UpperSat_f) {
    /* Update for Memory: '<S17>/Memory' */
    JenkinAcc_DW->Memory_PreviousInput_b = JenkinAcc_P.Saturation_UpperSat_f;
  } else if (rtb_dvms < JenkinAcc_P.Saturation_LowerSat_e) {
    /* Update for Memory: '<S17>/Memory' */
    JenkinAcc_DW->Memory_PreviousInput_b = JenkinAcc_P.Saturation_LowerSat_e;
  } else {
    /* Update for Memory: '<S17>/Memory' */
    JenkinAcc_DW->Memory_PreviousInput_b = rtb_dvms;
  }

  /* End of Saturate: '<S17>/Saturation' */

  /* Switch: '<S1>/Switch Ax  Brake on//off' incorporates:
   *  Switch: '<S1>/Switch Ax  Gas on//off'
   */
  if (rtb_targetdetected) {
    /* Saturate: '<S4>/Brake if -1<x<0' */
    if (rtb_u35ax1 > JenkinAcc_P.Brakeif1x0_UpperSat) {
      rtb_dvms = JenkinAcc_P.Brakeif1x0_UpperSat;
    } else if (rtb_u35ax1 < JenkinAcc_P.Brakeif1x0_LowerSat) {
      rtb_dvms = JenkinAcc_P.Brakeif1x0_LowerSat;
    } else {
      rtb_dvms = rtb_u35ax1;
    }

    /* End of Saturate: '<S4>/Brake if -1<x<0' */

    /* Outport: '<Root>/ToCM' incorporates:
     *  Gain: '<S4>/Gain'
     */
    JenkinAcc_Y->ToCM.Brake = JenkinAcc_P.Gain_Gain * rtb_dvms;

    /* Saturate: '<S4>/Gas  if 0<=x<=1' */
    if (rtb_u35ax1 > JenkinAcc_P.Gasif0x1_UpperSat) {
      /* Outport: '<Root>/ToCM' */
      JenkinAcc_Y->ToCM.Gas = JenkinAcc_P.Gasif0x1_UpperSat;
    } else if (rtb_u35ax1 < JenkinAcc_P.Gasif0x1_LowerSat) {
      /* Outport: '<Root>/ToCM' */
      JenkinAcc_Y->ToCM.Gas = JenkinAcc_P.Gasif0x1_LowerSat;
    } else {
      /* Outport: '<Root>/ToCM' */
      JenkinAcc_Y->ToCM.Gas = rtb_u35ax1;
    }

    /* End of Saturate: '<S4>/Gas  if 0<=x<=1' */
  } else {
    /* Outport: '<Root>/ToCM' incorporates:
     *  Inport: '<Root>/FromCM'
     */
    JenkinAcc_Y->ToCM.Brake = JenkinAcc_U->FromCM.Brake;
    JenkinAcc_Y->ToCM.Gas = JenkinAcc_U->FromCM.Gas;
  }

  /* End of Switch: '<S1>/Switch Ax  Brake on//off' */

  /* Outport: '<Root>/ToCM' incorporates:
   *  BusCreator generated from: '<Root>/ToCM'
   *  Inport: '<Root>/FromCM'
   */
  JenkinAcc_Y->ToCM.SST = JenkinAcc_U->FromCM.SST;
  JenkinAcc_Y->ToCM.Key = JenkinAcc_U->FromCM.Key;
  JenkinAcc_Y->ToCM.UserSignal = JenkinAcc_U->FromCM.UserSignal;
  JenkinAcc_Y->ToCM.GearNo = JenkinAcc_U->FromCM.GearNo;
  JenkinAcc_Y->ToCM.SelectorCtrl = JenkinAcc_U->FromCM.SelectorCtrl;
  JenkinAcc_Y->ToCM.BrakePark = JenkinAcc_U->FromCM.BrakePark;
  JenkinAcc_Y->ToCM.BrakeLever = JenkinAcc_U->FromCM.BrakeLever;
  JenkinAcc_Y->ToCM.Clutch = JenkinAcc_U->FromCM.Clutch;
  JenkinAcc_Y->ToCM.Steering = JenkinAcc_U->FromCM.Steering;
  JenkinAcc_Y->ToCM.Rider = JenkinAcc_U->FromCM.Rider;
  JenkinAcc_Y->ToCM.Lights = JenkinAcc_U->FromCM.Lights;

  /* Update for Memory: '<S7>/Memory' incorporates:
   *  Constant: '<S7>/Constant'
   */
  JenkinAcc_DW->Memory_PreviousInput = JenkinAcc_P.Constant_Value;
}

/* Model initialize function */
void JenkinAcc_initialize(RT_MODEL_JenkinAcc_T *const JenkinAcc_M)
{
  DW_JenkinAcc_T *JenkinAcc_DW = JenkinAcc_M->dwork;
  B_JenkinAcc_T *JenkinAcc_B = JenkinAcc_M->blockIO;

  /* Start for S-Function (cm_sensor_object): '<S18>/S-Function' */
  JenkinAcc_DW->SFunction_IWORK.SIsFirstStep = 1;

  /* Start for S-Function (cm_sensor_object_obj): '<S19>/S-Function' */
  JenkinAcc_DW->SFunction_IWORK_i.SIsFirstStep = 1;

  /* Start for S-Function (read_dict): '<S5>/Is ACC enabled' */
  {
    char **namevec = CM_Names2StrVec("AccelCtrl.ACC.IsActive", NULL);
    JenkinAcc_DW->IsACCenabled_IWORK.Checked = 0;
    JenkinAcc_DW->IsACCenabled_PWORK.Entry = (void *)DDictGetEntryOrFake
      (namevec[0]);
    CM_FreeStrVec(namevec);
  }

  /* Start for S-Function (read_dict): '<S7>/Read User desired time gap' */
  {
    char **namevec = CM_Names2StrVec("AccelCtrl.ACC.DesiredTGap", NULL);
    JenkinAcc_DW->ReadUserdesiredtimegap_IWORK.Checked = 0;
    JenkinAcc_DW->ReadUserdesiredtimegap_PWORK.Entry = (void *)
      DDictGetEntryOrFake(namevec[0]);
    CM_FreeStrVec(namevec);
  }

  /* Start for S-Function (read_infoparam): '<S3>/Read init brake threshold from Inf' */
  JenkinAcc_DW->ReadinitbrakethresholdfromInf_PWORK.InfoParam = InfoParam_Create
    (InfoParam_Vehicle, "AccelCtrl.ACC.BrakeThreshold", 1,
     &JenkinAcc_ConstP.ReadinitbrakethresholdfromInf_DefValue, 1);
  InfoParam_Read(JenkinAcc_DW->ReadinitbrakethresholdfromInf_PWORK.InfoParam, 0);

  /* Start for S-Function (read_dict): '<S7>/Is ACC enabled' */
  {
    char **namevec = CM_Names2StrVec("AccelCtrl.ACC.IsActive", NULL);
    JenkinAcc_DW->IsACCenabled_IWORK_n.Checked = 0;
    JenkinAcc_DW->IsACCenabled_PWORK_b.Entry = (void *)DDictGetEntryOrFake
      (namevec[0]);
    CM_FreeStrVec(namevec);
  }

  /* Start for Enabled SubSystem: '<S6>/Desired Distance Calculation with time gap' */

  /* Start for S-Function (read_dict): '<S8>/Read Car.v[m//s]' */
  {
    char **namevec = CM_Names2StrVec("Car.v", NULL);
    JenkinAcc_DW->ReadCarvms_IWORK_n.Checked = 0;
    JenkinAcc_DW->ReadCarvms_PWORK_k.Entry = (void *)DDictGetEntryOrFake
      (namevec[0]);
    CM_FreeStrVec(namevec);
  }

  /* Start for S-Function (read_infoparam): '<S8>/Read init min distance from Inf' */
  JenkinAcc_DW->ReadinitmindistancefromInf_PWORK.InfoParam = InfoParam_Create
    (InfoParam_Vehicle, "AccelCtrl.ACC.DistMin", 1,
     &JenkinAcc_ConstP.ReadinitmindistancefromInf_DefValue, 1);
  InfoParam_Read(JenkinAcc_DW->ReadinitmindistancefromInf_PWORK.InfoParam, 0);

  /* Start for S-Function (write_dict): '<S8>/Write desired distance' */
  {
    char **namevec = CM_Names2StrVec("AccelCtrl.ACC.DesiredDist", NULL);
    JenkinAcc_DW->Writedesireddistance_IWORK.Checked = 0;
    JenkinAcc_DW->Writedesireddistance_PWORK.Entry = (void *)DDictGetEntryOrFake
      (namevec[0]);
    CM_FreeStrVec(namevec);
  }

  /* End of Start for SubSystem: '<S6>/Desired Distance Calculation with time gap' */

  /* Start for S-Function (read_dict): '<S7>/Read User desired speed' */
  {
    char **namevec = CM_Names2StrVec("AccelCtrl.ACC.DesiredSpd", NULL);
    JenkinAcc_DW->ReadUserdesiredspeed_IWORK.Checked = 0;
    JenkinAcc_DW->ReadUserdesiredspeed_PWORK.Entry = (void *)DDictGetEntryOrFake
      (namevec[0]);
    CM_FreeStrVec(namevec);
  }

  /* Start for S-Function (read_dict): '<S7>/Read Simulation Time' */
  {
    char **namevec = CM_Names2StrVec("Time", NULL);
    JenkinAcc_DW->ReadSimulationTime_IWORK.Checked = 0;
    JenkinAcc_DW->ReadSimulationTime_PWORK.Entry = (void *)DDictGetEntryOrFake
      (namevec[0]);
    CM_FreeStrVec(namevec);
  }

  /* Start for S-Function (read_infoparam): '<S7>/Read Init Velocity' */
  JenkinAcc_DW->ReadInitVelocity_PWORK.InfoParam = InfoParam_Create
    (InfoParam_Testrun, "DrivMan.Init.Velocity", 1,
     &JenkinAcc_ConstP.ReadInitVelocity_DefValue, 1);
  InfoParam_Read(JenkinAcc_DW->ReadInitVelocity_PWORK.InfoParam, 0);

  /* Start for S-Function (read_dict): '<S7>/Read Car.v[m//s]' */
  {
    char **namevec = CM_Names2StrVec("Car.v", NULL);
    JenkinAcc_DW->ReadCarvms_IWORK.Checked = 0;
    JenkinAcc_DW->ReadCarvms_PWORK.Entry = (void *)DDictGetEntryOrFake(namevec[0]);
    CM_FreeStrVec(namevec);
  }

  /* Start for Atomic SubSystem: '<S6>/Speed Control Algorithm' */

  /* Start for S-Function (read_dict): '<S13>/Read Car.v[m//s]' */
  {
    char **namevec = CM_Names2StrVec("Car.v", NULL);
    JenkinAcc_DW->ReadCarvms_IWORK_h.Checked = 0;
    JenkinAcc_DW->ReadCarvms_PWORK_e.Entry = (void *)DDictGetEntryOrFake
      (namevec[0]);
    CM_FreeStrVec(namevec);
  }

  /* Start for S-Function (read_infoparam): '<S13>/Read init spdctrl.kv from Inf' */
  JenkinAcc_DW->ReadinitspdctrlkvfromInf_PWORK.InfoParam = InfoParam_Create
    (InfoParam_Vehicle, "AccelCtrl.ACC.SpdCtrl.kv", 1,
     &JenkinAcc_ConstP.ReadinitspdctrlkvfromInf_DefValue, 1);
  InfoParam_Read(JenkinAcc_DW->ReadinitspdctrlkvfromInf_PWORK.InfoParam, 0);

  /* End of Start for SubSystem: '<S6>/Speed Control Algorithm' */

  /* Start for Atomic SubSystem: '<S6>/Distance Control Algorithm' */

  /* Start for S-Function (read_infoparam): '<S12>/Read init distctrl.kd from Inf' */
  JenkinAcc_DW->ReadinitdistctrlkdfromInf_PWORK.InfoParam = InfoParam_Create
    (InfoParam_Vehicle, "AccelCtrl.ACC.DistCtrl.kd", 1,
     &JenkinAcc_ConstP.ReadinitdistctrlkdfromInf_DefValue, 1);
  InfoParam_Read(JenkinAcc_DW->ReadinitdistctrlkdfromInf_PWORK.InfoParam, 0);

  /* Start for S-Function (read_infoparam): '<S12>/Read init distctrl.kv from Inf1' */
  JenkinAcc_DW->ReadinitdistctrlkvfromInf1_PWORK.InfoParam = InfoParam_Create
    (InfoParam_Vehicle, "AccelCtrl.ACC.DistCtrl.kv", 1,
     &JenkinAcc_ConstP.ReadinitdistctrlkvfromInf1_DefValue, 1);
  InfoParam_Read(JenkinAcc_DW->ReadinitdistctrlkvfromInf1_PWORK.InfoParam, 0);

  /* End of Start for SubSystem: '<S6>/Distance Control Algorithm' */

  /* Start for S-Function (write_dict): '<S1>/Write desired Ax' */
  {
    char **namevec = CM_Names2StrVec("AccelCtrl.DesiredAx", NULL);
    JenkinAcc_DW->WritedesiredAx_IWORK.Checked = 0;
    JenkinAcc_DW->WritedesiredAx_PWORK.Entry = (void *)DDictGetEntryOrFake
      (namevec[0]);
    CM_FreeStrVec(namevec);
  }

  /* Start for S-Function (write_dict): '<S3>/Write ACC IsActive' */
  {
    char **namevec = CM_Names2StrVec("AccelCtrl.ACC.IsActive", NULL);
    JenkinAcc_DW->WriteACCIsActive_IWORK.Checked = 0;
    JenkinAcc_DW->WriteACCIsActive_PWORK.Entry = (void *)DDictGetEntryOrFake
      (namevec[0]);
    CM_FreeStrVec(namevec);
  }

  /* Start for S-Function (write_dict): '<S3>/Write desired Ax' */
  {
    char **namevec = CM_Names2StrVec("AccelCtrl.ACC.DesiredAx", NULL);
    JenkinAcc_DW->WritedesiredAx_IWORK_i.Checked = 0;
    JenkinAcc_DW->WritedesiredAx_PWORK_p.Entry = (void *)DDictGetEntryOrFake
      (namevec[0]);
    CM_FreeStrVec(namevec);
  }

  /* Start for S-Function (write_dict): '<S7>/Write desired speed' */
  {
    char **namevec = CM_Names2StrVec("AccelCtrl.ACC.DesiredSpd", NULL);
    JenkinAcc_DW->Writedesiredspeed_IWORK.Checked = 0;
    JenkinAcc_DW->Writedesiredspeed_PWORK.Entry = (void *)DDictGetEntryOrFake
      (namevec[0]);
    CM_FreeStrVec(namevec);
  }

  /* Start for S-Function (read_infoparam): '<S7>/Read init desired time gap from Inf' */
  JenkinAcc_DW->ReadinitdesiredtimegapfromInf_PWORK.InfoParam = InfoParam_Create
    (InfoParam_Vehicle, "AccelCtrl.ACC.DesrTGap", 1,
     &JenkinAcc_ConstP.ReadinitdesiredtimegapfromInf_DefValue, 1);
  InfoParam_Read(JenkinAcc_DW->ReadinitdesiredtimegapfromInf_PWORK.InfoParam, 0);

  /* Start for Triggered SubSystem: '<S7>/Init Desired time gap quantity' */

  /* Start for S-Function (write_dict): '<S14>/Write init time gap' */
  {
    char **namevec = CM_Names2StrVec("AccelCtrl.ACC.DesiredTGap", NULL);
    JenkinAcc_DW->Writeinittimegap_IWORK.Checked = 0;
    JenkinAcc_DW->Writeinittimegap_PWORK.Entry = (void *)DDictGetEntryOrFake
      (namevec[0]);
    CM_FreeStrVec(namevec);
  }

  /* End of Start for SubSystem: '<S7>/Init Desired time gap quantity' */

  /* Start for S-Function (read_infoparam): '<S15>/Read init p-gain from Inf' */
  JenkinAcc_DW->ReadinitpgainfromInf_PWORK.InfoParam = InfoParam_Create
    (InfoParam_Vehicle, "AccelCtrl.p", 1, &JenkinAcc_ConstP.pooled1, 1);
  InfoParam_Read(JenkinAcc_DW->ReadinitpgainfromInf_PWORK.InfoParam, 0);

  /* Start for S-Function (read_dict): '<S16>/Read Car.ax' */
  {
    char **namevec = CM_Names2StrVec("Car.ax", NULL);
    JenkinAcc_DW->ReadCarax_IWORK.Checked = 0;
    JenkinAcc_DW->ReadCarax_PWORK.Entry = (void *)DDictGetEntryOrFake(namevec[0]);
    CM_FreeStrVec(namevec);
  }

  /* Start for S-Function (read_infoparam): '<S15>/Read init i-gain from Inf' */
  JenkinAcc_DW->ReadinitigainfromInf_PWORK.InfoParam = InfoParam_Create
    (InfoParam_Vehicle, "AccelCtrl.i", 1, &JenkinAcc_ConstP.pooled1, 1);
  InfoParam_Read(JenkinAcc_DW->ReadinitigainfromInf_PWORK.InfoParam, 0);

  /* InitializeConditions for Memory: '<S7>/Memory' */
  JenkinAcc_DW->Memory_PreviousInput = JenkinAcc_P.Memory_InitialCondition;

  /* InitializeConditions for Memory: '<S17>/Memory' */
  JenkinAcc_DW->Memory_PreviousInput_b = JenkinAcc_P.Memory_InitialCondition_g;

  /* SystemInitialize for Enabled SubSystem: '<S6>/Desired Distance Calculation with time gap' */
  /* SystemInitialize for MinMax: '<S8>/MinMax' incorporates:
   *  Outport: '<S8>/desired distance'
   */
  JenkinAcc_B->MinMax = JenkinAcc_P.desireddistance_Y0;

  /* End of SystemInitialize for SubSystem: '<S6>/Desired Distance Calculation with time gap' */
}

/* Model terminate function */
void JenkinAcc_terminate(RT_MODEL_JenkinAcc_T * JenkinAcc_M)
{
  DW_JenkinAcc_T *JenkinAcc_DW = JenkinAcc_M->dwork;

  /* Terminate for S-Function (read_infoparam): '<S3>/Read init brake threshold from Inf' */
  InfoParam_Destroy(JenkinAcc_DW->ReadinitbrakethresholdfromInf_PWORK.InfoParam);

  /* Terminate for Enabled SubSystem: '<S6>/Desired Distance Calculation with time gap' */

  /* Terminate for S-Function (read_infoparam): '<S8>/Read init min distance from Inf' */
  InfoParam_Destroy(JenkinAcc_DW->ReadinitmindistancefromInf_PWORK.InfoParam);

  /* End of Terminate for SubSystem: '<S6>/Desired Distance Calculation with time gap' */

  /* Terminate for S-Function (read_infoparam): '<S7>/Read Init Velocity' */
  InfoParam_Destroy(JenkinAcc_DW->ReadInitVelocity_PWORK.InfoParam);

  /* Terminate for Atomic SubSystem: '<S6>/Speed Control Algorithm' */

  /* Terminate for S-Function (read_infoparam): '<S13>/Read init spdctrl.kv from Inf' */
  InfoParam_Destroy(JenkinAcc_DW->ReadinitspdctrlkvfromInf_PWORK.InfoParam);

  /* End of Terminate for SubSystem: '<S6>/Speed Control Algorithm' */

  /* Terminate for Atomic SubSystem: '<S6>/Distance Control Algorithm' */

  /* Terminate for S-Function (read_infoparam): '<S12>/Read init distctrl.kd from Inf' */
  InfoParam_Destroy(JenkinAcc_DW->ReadinitdistctrlkdfromInf_PWORK.InfoParam);

  /* Terminate for S-Function (read_infoparam): '<S12>/Read init distctrl.kv from Inf1' */
  InfoParam_Destroy(JenkinAcc_DW->ReadinitdistctrlkvfromInf1_PWORK.InfoParam);

  /* End of Terminate for SubSystem: '<S6>/Distance Control Algorithm' */

  /* Terminate for S-Function (read_infoparam): '<S7>/Read init desired time gap from Inf' */
  InfoParam_Destroy(JenkinAcc_DW->ReadinitdesiredtimegapfromInf_PWORK.InfoParam);

  /* Terminate for S-Function (read_infoparam): '<S15>/Read init p-gain from Inf' */
  InfoParam_Destroy(JenkinAcc_DW->ReadinitpgainfromInf_PWORK.InfoParam);

  /* Terminate for S-Function (read_infoparam): '<S15>/Read init i-gain from Inf' */
  InfoParam_Destroy(JenkinAcc_DW->ReadinitigainfromInf_PWORK.InfoParam);

  /* model code */
  rt_FREE(JenkinAcc_M->blockIO);
  rt_FREE(JenkinAcc_M->inputs);
  rt_FREE(JenkinAcc_M->outputs);
  rt_FREE(JenkinAcc_M->dwork);
  rt_FREE(JenkinAcc_M->prevZCSigState);
  rt_FREE(JenkinAcc_M);
}

/* Model data allocation function */
RT_MODEL_JenkinAcc_T *JenkinAcc(struct tInfos *inf)
{
  RT_MODEL_JenkinAcc_T *JenkinAcc_M;
  JenkinAcc_M = (RT_MODEL_JenkinAcc_T *) malloc(sizeof(RT_MODEL_JenkinAcc_T));
  if (JenkinAcc_M == NULL) {
    return NULL;
  }

  (void) memset((char *)JenkinAcc_M, 0,
                sizeof(RT_MODEL_JenkinAcc_T));
  MatSupp_Init();

  /* block I/O */
  {
    B_JenkinAcc_T *b = (B_JenkinAcc_T *) malloc(sizeof(B_JenkinAcc_T));
    rt_VALIDATE_MEMORY(JenkinAcc_M,b);
    JenkinAcc_M->blockIO = (b);
  }

  /* states (dwork) */
  {
    DW_JenkinAcc_T *dwork = (DW_JenkinAcc_T *) malloc(sizeof(DW_JenkinAcc_T));
    rt_VALIDATE_MEMORY(JenkinAcc_M,dwork);
    JenkinAcc_M->dwork = (dwork);
  }

  /* external inputs */
  {
    ExtU_JenkinAcc_T *JenkinAcc_U = (ExtU_JenkinAcc_T *) malloc(sizeof
      (ExtU_JenkinAcc_T));
    rt_VALIDATE_MEMORY(JenkinAcc_M,JenkinAcc_U);
    JenkinAcc_M->inputs = (((ExtU_JenkinAcc_T *) JenkinAcc_U));
  }

  /* external outputs */
  {
    ExtY_JenkinAcc_T *JenkinAcc_Y = (ExtY_JenkinAcc_T *) malloc(sizeof
      (ExtY_JenkinAcc_T));
    rt_VALIDATE_MEMORY(JenkinAcc_M,JenkinAcc_Y);
    JenkinAcc_M->outputs = (JenkinAcc_Y);
  }

  /* previous zero-crossing states */
  {
    PrevZCX_JenkinAcc_T *zc = (PrevZCX_JenkinAcc_T *) malloc(sizeof
      (PrevZCX_JenkinAcc_T));
    rt_VALIDATE_MEMORY(JenkinAcc_M,zc);
    JenkinAcc_M->prevZCSigState = (zc);
  }

  /* CarMaker parameter tuning */
  {
    JenkinAcc_SetParams(JenkinAcc_M, NULL, inf);
  }

  {
    B_JenkinAcc_T *JenkinAcc_B = JenkinAcc_M->blockIO;
    DW_JenkinAcc_T *JenkinAcc_DW = JenkinAcc_M->dwork;
    PrevZCX_JenkinAcc_T *JenkinAcc_PrevZCX = JenkinAcc_M->prevZCSigState;
    ExtU_JenkinAcc_T *JenkinAcc_U = (ExtU_JenkinAcc_T *) JenkinAcc_M->inputs;
    ExtY_JenkinAcc_T *JenkinAcc_Y = (ExtY_JenkinAcc_T *) JenkinAcc_M->outputs;

    /* block I/O */
    (void) memset(((void *) JenkinAcc_B), 0,
                  sizeof(B_JenkinAcc_T));

    /* states (dwork) */
    (void) memset((void *)JenkinAcc_DW, 0,
                  sizeof(DW_JenkinAcc_T));

    /* external inputs */
    JenkinAcc_U->FromCM = JenkinAcc_rtZcmVehicleControlIn;

    /* external outputs */
    JenkinAcc_Y->ToCM = JenkinAcc_rtZcmVehicleControlOut;

    /* previous zero-crossing states */
    {
      JenkinAcc_PrevZCX->InitDesiredtimegapquantity_Trig_ZCE =
        UNINITIALIZED_ZCSIG;
    }
  }

  return JenkinAcc_M;
}

/* CarMaker dictionary definitions. */
extern tQuantEntry *JenkinAcc_main_DictDefines[];
static tQuantEntry DictDefines[] = {
  { (void*)0x01234567, (void*)0x89ABCDEF, NULL, 0, 0, 0, "", 0.0, 0.0 },

  { (void*)JenkinAcc_main_DictDefines, NULL, NULL, 0, 0, 0, "", 0.0, 0.0 },

  { "AccelCtrl.ACC.IsActive", "", "Char", 0, 2.0, 0.0, "DM", 1.0, 0.0 },

  { "AccelCtrl.ACC.DesiredTGap", "s", "Double4", 0, 0.0, 0.0, "DM", 0.0, 0.0 },

  { "AccelCtrl.ACC.DesiredSpd", "m/s", "Double4", 0, 0.0, 0.0, "DM", 0.0, 0.0 },

  { "AccelCtrl.ACC.DesiredAx", "m/s^2", "Double4", 0, 0.0, 0.0, "DM", 0.0, 0.0 },

  { "AccelCtrl.DesiredAx", "m/s^2", "Double4", 0, 0.0, 0.0, "DM", 0.0, 0.0 },

  { "AccelCtrl.ACC.DesiredDist", "m", "Double4", 0, 0.0, 0.0, "DM", 0.0, 0.0 },

  { NULL, NULL, NULL, 0, 0, 0, "", 0.0, 0.0 }
};

tQuantEntry *JenkinAcc_DictDefines = DictDefines;
tQuantEntry *JenkinAcc_main_DictDefines[] = {
  DictDefines,
  NULL
};

/* CarMaker bodyframe definitions. */
#ifndef RTMAKER

extern tMdlBdyFrame *JenkinAcc_main_BdyFrameDefines[];
static tMdlBdyFrame BdyFrameDefines[] = {
  { (void*)0x01234567 },

  { (void*)0x89ABCDEF },

  { (void*)JenkinAcc_main_BdyFrameDefines },

  { NULL }
};

tMdlBdyFrame *JenkinAcc_BdyFrameDefines = BdyFrameDefines;
tMdlBdyFrame *JenkinAcc_main_BdyFrameDefines[] = {
  BdyFrameDefines,
  NULL
};

#endif
