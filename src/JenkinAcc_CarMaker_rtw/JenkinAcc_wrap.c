/***************************************************** target specific file ***/
/*  Wrapper module for Simulink models                                        */
/*  ------------------------------------------------------------------------  */
/*  (c) IPG Automotive GmbH    www.ipg-automotive.com   Fon: +49.721.98520-0  */
/*  Bannwaldallee 60      D-76185 Karlsruhe   Germany   Fax: +49.721.98520-99 */
/******************************************************************************/

#ifndef IS_CAR
# define IS_CAR
#endif

#include "Global.h"

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <math.h>

#include "simstruc.h"
#include "rt_sim.h"
#include "simstruc_types.h"

#include "SimCore.h"
#include "Log.h"
#include "MatSupp.h"
#include "ModelManager.h"

#include "VehicleControl.h"

#include "JenkinAcc.h"
#include "JenkinAcc_wrap.h"


#define QUOTE1(name)	#name
#define QUOTE(name)	QUOTE1(name)		/* need to expand name */

#ifndef CLASSIC_INTERFACE
# define EXPAND_CONCAT(name1,name2) name1 ## name2
# define CONCAT(name1,name2) EXPAND_CONCAT(name1,name2)
# define MODEL_INITIALIZE CONCAT(MODEL,_initialize)
# define MODEL_STEP       CONCAT(MODEL,_step)
# define MODEL_TERMINATE  CONCAT(MODEL,_terminate)
# define RT_MDL_TYPE      CONCAT(MODEL,_M_TYPE)
#endif

extern const char JenkinAcc_LibIdent[];
const char JenkinAcc_LibIdent[] = "(@@)" QUOTE(MODEL) " " ARCH " 1.0 " BUILDDATE;

static const char Modelname[] = QUOTE(MODEL);
static const tModelClass Modelclass = ModelClass_VehicleControl;
static tMatSuppSampling SampleParams;


static void
DoOneStep (rtModel_JenkinAcc *rtm)
{
#ifdef CLASSIC_INTERFACE
    real_T tnext;

    tnext = rt_SimGetNextSampleHit(rtmGetTimingData(rtm),
				   rtmGetNumSampleTimes(rtm));
    rtsiSetSolverStopTime(rtmGetRTWSolverInfo(rtm),tnext);

    rtmiOutputs(rtmGetRTWRTModelMethodsInfo(rtm),0);
    rtmiUpdate(rtmGetRTWRTModelMethodsInfo(rtm),0);
    rt_SimUpdateDiscreteTaskSampleHits(rtmGetNumSampleTimes(rtm),
				       rtmGetTimingData(rtm),
				       rtmGetSampleHitPtr(rtm),
				       rtmGetTPtr(rtm));

    if (rtmGetSampleTime(rtm,0) == CONTINUOUS_SAMPLE_TIME) {
	if (rtmGetNumContStates(rtm) > 0) {
	    rt_ODEUpdateContinuousStates(rtmGetRTWSolverInfo(rtm));
	} else {
	    rtsiSetT(rtmGetRTWSolverInfo(rtm), rtsiGetSolverStopTime(rtmGetRTWSolverInfo(rtm)));
	}
    }
#else
    MODEL_STEP(rtm);
#endif
}


/*
 * Define dictionary entries made from tunable parameters.
 * The function will actually be called twice, first with tuns==NULL.
 */
static void
DeclParameterQuants (struct tMatSuppTunables *tuns)
{
    /*MatSupp_TunDDictDefScalar(tuns, "MyParam", INFOMAT_DOUBLE, "kappa", "kg/s");*/
}


static void
JenkinAcc_DeclQuants (void *MP)
{
    rtModel_JenkinAcc *rtm = (rtModel_JenkinAcc *)MP;
    int i;

    /*Log("%s_DeclQuants()\n", Modelname);*/

    if (rtm == NULL) {
	/* Remember body frames defined in this model for later registration. */
        MdlBdyFrame_Add(JenkinAcc_BdyFrameDefines);

	/* Define dict entries for non-dynamically allocated variables. */
	if ((i = MatSupp_DeclQuants(JenkinAcc_DictDefines)) >= 0) {
	    LogErrF(EC_Init, "Model '%s': Error defining quantity '%s'",
		    Modelname, JenkinAcc_DictDefines[i].Name);
	}

	/* Define dict entries for tunable parameters (with dummy address). */
	DeclParameterQuants(NULL);
    } else {
	/* Define dict entries for dynamically allocated variables. */
    }
}


/*
 * JenkinAcc_SetParams() will be invoked indirectly by the generated
 * model C code each time JenkinAcc_New() is called.
 */
void
JenkinAcc_SetParams (rtModel_JenkinAcc *rtm, struct tMatSuppTunables *tuns,
		   struct tInfos *Inf)
{
    /*Log("%s_SetParams()\n", Modelname);*/

    /*
     * Parameter tuning - Part 1
     * This is the place to modify parameters of a storage class
     * other than 'SimulinkGlobal'.
     */

    if (tuns == NULL)
        return;

    /* Define dict entries for tunable parameters (address update). */
    DeclParameterQuants(tuns);

    /*
     * Parameter tuning - Part 2
     * This is the place to modify parameters of storage class
     * 'SimulinkGlobal', e.g. using the CarMaker target's tunable parameter
     * interface.
     */

    const char *prefix = Model_Class2Str(Modelclass);
    MatSupp_TunReadAllOpt(tuns, Inf, prefix);
    /*MatSupp_TunReadAll(tuns, ...);*/
    /*MatSupp_TunReadDef(tuns, ...);*/
    /*MatSupp_TunRead(tuns, ...);*/
}


static void *
JenkinAcc_New (struct tInfos *Inf, const char *KindKey)
{
    rtModel_JenkinAcc *rtm;
    double rtmSampleTime;
    const char *ModelKind;
    int VersionId = 0;

    if ((ModelKind = SimCore_GetKindInfo(Inf, Modelclass, KindKey,
	 				 0, PARAMID, &VersionId)) == NULL)
	return NULL;

    /*Log("%s_New()\n", Modelname);*/

    MatSupp_ResetQuants(JenkinAcc_DictDefines);

    rtm = MODEL(Inf);

#ifdef CLASSIC_INTERFACE
    rtmSetT(rtm, 0.0);
    rtmSetTFinal(rtm, -1 /*run forever*/);

    rtmiInitializeSizes(rtmGetRTWRTModelMethodsInfo(rtm));
    rtmiInitializeSampleTimes(rtmGetRTWRTModelMethodsInfo(rtm));
    rt_SimInitTimingEngine(rtmGetNumSampleTimes(rtm),
			   rtmGetStepSize(rtm),
			   rtmGetSampleTimePtr(rtm),
			   rtmGetOffsetTimePtr(rtm),
			   rtmGetSampleHitPtr(rtm),
			   rtmGetSampleTimeTaskIDPtr(rtm),
			   rtmGetTStart(rtm),
			   &rtmGetSimTimeStep(rtm),
			   &rtmGetTimingData(rtm));
    if (rtmGetNumContStates(rtm) > 0) {
	rt_ODECreateIntegrationData(rtmGetRTWSolverInfo(rtm));
    } else {
	rtsiSetSolverName(rtmGetRTWSolverInfo(rtm), "FixedStepDiscrete");
    }
    rtsiSetVariableStepSolver(rtmGetRTWSolverInfo(rtm), 0);
#endif

    rtmSampleTime = (double) rtmGetStepSize(rtm);
    if (MatSupp_Sampling (&SampleParams, SimCore.DeltaT, rtmSampleTime) !=0) {
	LogErrF(EC_Init, "Model '%s': The sample times of the plugin model and the application have to be integer multiples",Modelname);
	return NULL;
    }

#ifdef CLASSIC_INTERFACE
    rtmiStart(rtmGetRTWRTModelMethodsInfo(rtm));
#else
    MODEL_INITIALIZE(rtm);
#endif

    return rtm; /* Will be passed as MP to the other functions. */
}


static void
JenkinAcc_Delete (void *MP)
{
    rtModel_JenkinAcc *rtm = (rtModel_JenkinAcc *)MP;

    /*Log("%s_Delete()\n", Modelname);*/

#ifdef CLASSIC_INTERFACE
    rt_SimDestroyTimingEngine(rtmGetTimingData(rtm));
    if (rtmGetNumContStates(rtm) > 0)
	rt_ODEDestroyIntegrationData(rtmGetRTWSolverInfo(rtm));
    rtmiTerminate(rtmGetRTWRTModelMethodsInfo(rtm));
#else
    MODEL_TERMINATE(rtm);
#endif
}


static int
JenkinAcc_Calc (void *MP, double dt)
{
    rtModel_JenkinAcc *rtm = (rtModel_JenkinAcc *)MP;
    int osCount=0;
    ExternalInputs_JenkinAcc  *in  = (ExternalInputs_JenkinAcc *) rtmGetU(rtm);
    ExternalOutputs_JenkinAcc *out = (ExternalOutputs_JenkinAcc *)rtmGetY(rtm);

    in->FromCM.SST		= VehicleControl.SST;
    in->FromCM.Key		= VehicleControl.Key;

    in->FromCM.UserSignal.s0= VehicleControl.UserSignal[0];
    in->FromCM.UserSignal.s1= VehicleControl.UserSignal[1];
    in->FromCM.UserSignal.s2= VehicleControl.UserSignal[2];
    in->FromCM.UserSignal.s3= VehicleControl.UserSignal[3];
    in->FromCM.UserSignal.s4= VehicleControl.UserSignal[4];

    in->FromCM.GearNo		= VehicleControl.GearNo;
    in->FromCM.SelectorCtrl	= VehicleControl.SelectorCtrl;
    in->FromCM.Brake		= VehicleControl.Brake;
    in->FromCM.BrakePark	= VehicleControl.BrakePark;
    in->FromCM.BrakeLever	= VehicleControl.BrakeLever;
    in->FromCM.Clutch		= VehicleControl.Clutch;
    in->FromCM.Gas		= VehicleControl.Gas;
    in->FromCM.Steering.Ang	= VehicleControl.Steering.Ang;
    in->FromCM.Steering.AngVel	= VehicleControl.Steering.AngVel;
    in->FromCM.Steering.AngAcc	= VehicleControl.Steering.AngAcc;
    in->FromCM.Steering.Trq	= VehicleControl.Steering.Trq;
    in->FromCM.Rider.RollAng	= VehicleControl.Rider.RollAng;
    in->FromCM.Rider.RollAngVel	= VehicleControl.Rider.RollAngVel;
    in->FromCM.Lights.LowBeam	= VehicleControl.Lights.LowBeam;
    in->FromCM.Lights.HighBeam	= VehicleControl.Lights.HighBeam;
    in->FromCM.Lights.Daytime	= VehicleControl.Lights.Daytime;
    in->FromCM.Lights.ParkL	= VehicleControl.Lights.ParkL;
    in->FromCM.Lights.ParkR	= VehicleControl.Lights.ParkR;
    in->FromCM.Lights.IndL	= VehicleControl.Lights.IndL;
    in->FromCM.Lights.IndR	= VehicleControl.Lights.IndR;
    in->FromCM.Lights.FogFrontL	= VehicleControl.Lights.FogFrontL;
    in->FromCM.Lights.FogFrontR	= VehicleControl.Lights.FogFrontR;
    in->FromCM.Lights.FogRear	= VehicleControl.Lights.FogRear;
    in->FromCM.Lights.Brake	= VehicleControl.Lights.Brake;
    in->FromCM.Lights.Reverse	= VehicleControl.Lights.Reverse;

    if (SampleParams.UnderSampFac) {	// Undersampling
     	if (++SampleParams.UnderSampCount == SampleParams.UnderSampFac) {
	    SampleParams.UnderSampCount=0;
	    DoOneStep(rtm);
     	}
    } else { 				// Oversampling (1..OverSampFac)
	do {
	    DoOneStep(rtm);
	} while (++osCount < SampleParams.OverSampFac);
    }

    VehicleControl.SST			= out->ToCM.SST;
    VehicleControl.Key			= out->ToCM.Key;

    VehicleControl.UserSignal[0]	= out->ToCM.UserSignal.s0;
    VehicleControl.UserSignal[1]	= out->ToCM.UserSignal.s1;
    VehicleControl.UserSignal[2]	= out->ToCM.UserSignal.s2;
    VehicleControl.UserSignal[3]	= out->ToCM.UserSignal.s3;
    VehicleControl.UserSignal[4]	= out->ToCM.UserSignal.s4;

    VehicleControl.GearNo		= out->ToCM.GearNo;
    VehicleControl.SelectorCtrl		= out->ToCM.SelectorCtrl;
    VehicleControl.Brake		= out->ToCM.Brake;
    VehicleControl.BrakePark		= out->ToCM.BrakePark;
    VehicleControl.BrakeLever		= out->ToCM.BrakeLever;
    VehicleControl.Clutch		= out->ToCM.Clutch;
    VehicleControl.Gas			= out->ToCM.Gas;
    VehicleControl.Steering.Ang		= out->ToCM.Steering.Ang;
    VehicleControl.Steering.AngVel	= out->ToCM.Steering.AngVel;
    VehicleControl.Steering.AngAcc	= out->ToCM.Steering.AngAcc;
    VehicleControl.Steering.Trq		= out->ToCM.Steering.Trq;
    VehicleControl.Rider.RollAng	= out->ToCM.Rider.RollAng;
    VehicleControl.Rider.RollAngVel	= out->ToCM.Rider.RollAngVel;
    VehicleControl.Lights.LowBeam	= out->ToCM.Lights.LowBeam;
    VehicleControl.Lights.HighBeam	= out->ToCM.Lights.HighBeam;
    VehicleControl.Lights.Daytime	= out->ToCM.Lights.Daytime;
    VehicleControl.Lights.ParkL		= out->ToCM.Lights.ParkL;
    VehicleControl.Lights.ParkR		= out->ToCM.Lights.ParkR;
    VehicleControl.Lights.IndL		= out->ToCM.Lights.IndL;
    VehicleControl.Lights.IndR		= out->ToCM.Lights.IndR;
    VehicleControl.Lights.FogFrontL	= out->ToCM.Lights.FogFrontL;
    VehicleControl.Lights.FogFrontR	= out->ToCM.Lights.FogFrontR;
    VehicleControl.Lights.FogRear	= out->ToCM.Lights.FogRear;
    VehicleControl.Lights.Brake		= out->ToCM.Lights.Brake;
    VehicleControl.Lights.Reverse	= out->ToCM.Lights.Reverse;
    return 0;
}


int
JenkinAcc_Register (void)
{
    tModelClassDescr m;

    /*Log("%s_Register()\n", Modelname);*/

    memset(&m, 0, sizeof(m));

    /* Parameter file identification number.
       You may change CompatVersionId to the the lowest parameter
       file version understood by your model code. */
    m.VehicleControl.VersionId		= PARAMID;
    m.VehicleControl.CompatVersionId	= m.VehicleControl.VersionId;

    m.VehicleControl.DeclQuants		= JenkinAcc_DeclQuants;
    m.VehicleControl.New		= JenkinAcc_New;
    m.VehicleControl.Calc		= JenkinAcc_Calc;
    m.VehicleControl.Delete		= JenkinAcc_Delete;
    /* Should only be used if the model doesn't read params from extra files */
    // m.VehicleControl.ParamsChanged	= ParamsChanged_IgnoreCheck;

    return Model_Register(Modelclass, Modelname, &m);
}

