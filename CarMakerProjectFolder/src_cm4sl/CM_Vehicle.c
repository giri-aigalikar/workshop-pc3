/*
 *****************************************************************************
 *  CarMaker - Version 14.0.1
 *  Virtual Test Driving Tool
 *
 *  Copyright ©1998-2025 IPG Automotive GmbH. All rights reserved.
 *  www.ipg-automotive.com
 *****************************************************************************
 *
 * Functions Overview
 * ==================
 *
 *	Vhcl_ModelCheck_BeforePre()
 *	Vhcl_ModelCheck_AfterPre()
 *	Vhcl_Param_SetDummy()
 *	Vhcl_Init()
 *	Vhcl_Register()
 *	Vhcl_DeclQuants()
 *	Vhcl_New()
 *	Vhcl_StaticCond_Calc()
 *	Vhcl_Calc()
 *	Vhcl_Calc_Part()			(CM4SL only)
 *	Vhcl_Snapshot_Take()
 *	Vhcl_Snapshot_Export2Inf()
 *	Vhcl_Delete()
 *	Vhcl_Cleanup()
 *
 *****************************************************************************
 */

#include <Global.h>

#if defined(WIN32)
# include <windows.h>
#endif

#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <CarMaker.h>
#include <TCPU.h>

#include <CarMaker4SL.h>

#include <Car/Vehicle_Car.h>
#include <Car/Car_CM4SL.h>

#include <Vehicle/VehicleControlApps.h>

#include "User.h"

/*
 * Vhcl_ModelCheck_BeforePre()
 *
 * before preprocessing
 */

int
Vhcl_ModelCheck_BeforePre(struct tInfos *Inf)
{
    ModelCheck_BeforePre_Begin();
    if (Vehicle.Model.Source == VehicleSource_BuiltIn && Car_ModelCheck_BeforePre(Inf) < 0) {
        goto ErrorReturn;
    }
    if (!BrakeDisabled && Brake_ModelCheck_BeforePre(Inf) < 0) {
        goto ErrorReturn;
    }
    if (!PowerTrainDisabled && PowerTrain_ModelCheck_BeforePre(Inf) < 0) {
        goto ErrorReturn;
    }
    if (Trailer_ModelCheck_BeforePre(Inf) < 0) {
        goto ErrorReturn;
    }
    ModelCheck_End();
    return 0;

ErrorReturn:
    ModelCheck_End();
    return -1;
}

/*
 * Vhcl_ModelCheck_AfterPre()
 *
 * after preprocessing
 */

int
Vhcl_ModelCheck_AfterPre(struct tInfos *Inf)
{
    ModelCheck_AfterPre_Begin();
    if (Vehicle.Model.Source == VehicleSource_BuiltIn && Car_ModelCheck_AfterPre(Inf) < 0) {
        goto ErrorReturn;
    }
    if (SimCore.Trailer.nTrailers != 0 && Trailer_ModelCheck_AfterPre(Inf) < 0) {
        goto ErrorReturn;
    }
    ModelCheck_End();
    return 0;

ErrorReturn:
    ModelCheck_End();
    return -1;
}

/*
 * Vhcl_Param_SetDummy()
 *
 *
 */

void
Vhcl_Param_SetDummy(struct tInfos *Inf)
{
    Car_Param_SetDummy(Inf);
}

/*
 * Vhcl_Init()
 *
 * Initialize all vehicle module components
 *
 * called:
 * - once at program start
 *
 */

int
Vhcl_Init(void)
{
    VehicleStruct_Init();

    Car_Init();
    Brake_Init();
    PowerTrain_Init();
    Trailer_Init();
    TrBrake_Init();

    return 0;
}

/*
 * Vhcl_Register()
 *
 * Register vehicle sub models
 *
 * called:
 * - once at program start
 */

int
Vhcl_Register(void)
{
    SimCore_SetVhclClass(VhclClass_Car_Id);

    Steering_Register_Dummy(); /* Dummy model, don't remove!!! */
    Tire_Register_Dummy();     /* Dummy model, don't remove!!! */
    Aero_Register_Dummy();     /* Dummy model, don't remove!!! */

    Susp_KnC_Register();
    Susp_FrcEl_Register();

    Susp_FrcSystem_Register_CM4SL();
    Susp_SpringSystem_Register_CM4SL();
    Susp_DamperSystem_Register_CM4SL();
    Susp_BufferSystem_Register_CM4SL();
    Susp_StabiSystem_Register_CM4SL();
    Susp_Spring_Register_CM4SL();
    Susp_ParasiticEffects_Register_CM4SL();
    Susp_Damper_Register_CM4SL();
    Susp_Buffer_Register_CM4SL();
    Susp_Stabi_Register_CM4SL();

    Steering_Register_GenAngle();
    Steering_Register_GenTorque();
    Steering_Register_Pfeffer();

    Env_Register_Generic();

    Aero_Register_Coeff6x1();

    Tire_Register_RTTire();
    Tire_Register_MagicFormula_52();
    Tire_Register_MagicFormula_61();
    Tire_Register_TASS_MF();
    Tire_Register_FTire();
    Tire_Register_TameTire();
    Tire_Register_IPGTire();

    Tire_Register_CM4SL();

    Brake_Register();

    PowerTrain_Register();

    VC_Register_AccelCtrl();
    VC_Register_GenLatCtrl();
    VC_Register_GenLongCtrl();

    VhclOperator_Register_IPGOperator();
    SelectorCtrlMapping_Register_Generic();

    TrfFollow_Register();
    TrfLaneChange_Register();

    return 0;
}

/*
 * Vhcl_DeclQuants()
 *
 * Add quantities to CarMaker's data dictionary
 *
 * called:
 * - once at program start
 */

int
Vhcl_DeclQuants(void)
{
    VehicleStruct_DeclQuants();

    if (Vehicle.Model.Source == VehicleSource_BuiltIn) {
        Car_DeclQuants();
        if (SimCore.Trailer.nTrailers != 0) {
            Trailer_DeclQuants();
            TrBrake_DeclQuants();
        }
    } else if (Vehicle.Model.Source == VehicleSource_ModelMgr) {
        VhclModel_DeclQuants();
    }

    Brake_DeclQuants();
    PowerTrain_DeclQuants();

    Model_ExportConfig(SimCore.Config.Inf);
    return 0;
}

/*
 * Vhcl_New()
 *
 * Prepare the vehicle model for a new Test Run.
 *
 * called:
 * - each Test Run start
 */

int
Vhcl_New(void)
{
    int rv = 0;

    if (!SimCore.Vhcl.Modified) {
        Vhcl_Delete(1);
        if (Vehicle.Model.Source == VehicleSource_BuiltIn) {
            if (Car_SoftNew(SimCore.Vhcl.Inf) < 0) {
                rv |= 1 << 1;
            }
        }
        if (SimCore.Trailer.nTrailers != 0) {
            if (Trailer_SoftNew() < 0) {
                rv |= 1 << 5;
            }
        }

        Vehicle_CreateInstrMsg(SimCore.Vhcl.Inf);

        return rv > 0 ? -rv : 0;
    }

    /*** free existing vehicle before starting a new one */
    Vhcl_Delete(0);

    Vehicle.Model.Source = Vehicle.Model.NextSource;
    SteeringDisabled     = Vehicle_SubsystemDisabled(SimCore.Vhcl.Inf, "Steering");
    BrakeDisabled        = Vehicle_SubsystemDisabled(SimCore.Vhcl.Inf, "Brake");
    PowerTrainDisabled   = Vehicle_SubsystemDisabled(SimCore.Vhcl.Inf, "PowerTrain");

    Vehicle_InitVhclCfg(SimCore.Vhcl.Class);
    Vehicle_RegisterMdlFrames();

    if (Vehicle.Model.Source == VehicleSource_BuiltIn) {
        if (Car_New(SimCore.Vhcl.Inf) < 0) {
            rv |= 1 << 1;
        }
    } else if (Vehicle.Model.Source == VehicleSource_ModelMgr) {
        if (VhclModel_New(SimCore.Vhcl.Inf) != 0) {
            rv |= 1 << 1;
        }
    } else if (Vehicle.Model.Source == VehicleSource_CM4SL) {
        if (Vehicle_GetVhclCfg(SimCore.Vhcl.Inf, VhclClass_Car_Id) >= 0) {
            Car_Partial_New(SimCore.Vhcl.Inf);
            Vehicle_CreateVhclMsgFromCfg(VhclClass_Car_Id);
        } else {
            rv |= 1 << 1;
        }
    } else {
        LogErrF(EC_Init, "Vehicle dataset: Unsupported vehicle kind");
        rv |= 1 << 1;
    }

    if (!BrakeDisabled) {
        if (Brake_New(SimCore.Vhcl.Inf) < 0) {
            rv |= 1 << 3;
        }
    }
    if (BrakeDisabled) {
        Brake_DeclQuants();
    }

    if (!PowerTrainDisabled) {
        if (PowerTrain_New(SimCore.Vhcl.Inf) < 0) {
            rv |= 1 << 4;
        }
    } else {
        if (Vehicle_GetVhclCfg_PT(SimCore.Vhcl.Inf) < 0) {
            rv |= 1 << 4;
        }
        if (PowerTrain_CM4SL_New(SimCore.Vhcl.Inf) < 0) {
            rv |= 1 << 4;
        }
    }
    if (PowerTrainDisabled) {
        PowerTrain_DeclQuants();
    }

    if (SimCore.Trailer.nTrailers != 0) {
        if (Trailer_New() < 0) {
            SimCore.Trailer.nTrailers  = 0;
            rv                        |= 1 << 5;
        }

        if (!TrBrakeDisabled) {
            if (TrBrake_New() < 0) {
                SimCore.Trailer.nTrailers  = 0;
                rv                        |= 1 << 6;
            }
        }
    }

    Vehicle_CreateInstrMsg(SimCore.Vhcl.Inf);

    return rv > 0 ? -rv : 0;
}

/*
 * Vhcl_StaticCond_Calc()
 *
 * Get the vehicle into static conditions
 *
 * called:
 * - each Test Run start
 */

int
Vhcl_StaticCond_Calc(void)
{
    if (Vehicle.Model.Source == VehicleSource_BuiltIn) {
        if (Car_StaticCond_Calc() < 0) {
            return -1;
        }
    } else if (Vehicle.Model.Source == VehicleSource_CM4SL) {
        if (Car_CM4SL_StaticCond_Calc() < 0) {
            return -2;
        }
    }
    if (SimCore.Trailer.nTrailers != 0) {
        if (Trailer_StaticCond_Calc() < 0) {
            return -3;
        }

        if (CarAndTrailer_StaticCond_Calc() < 0) {
            return -4;
        }
    }

    return 0;
}

/*
 * Vhcl_Calc()
 *
 * called:
 * - each simulation cycle
 */

int
Vhcl_Calc_Part(double dt, CyclePart_t part)
{
    static int rv;

    if (IN_CAR_PART(part)) {
        if (IN_CAR_FIRST_PART(part)) {
            rv = 0; /* !!Init */
        }
        if (Vehicle.Model.Source == VehicleSource_BuiltIn) {
            if (!IN_TRAILER_PART(part) && Car_Calc_Part(dt, part) < 0) {
                rv = -1;
            }
        } else if (Vehicle.Model.Source == VehicleSource_ModelMgr) {
            if (IN_CAR_LAST_PART(part) && VhclModel_Calc(dt) < 0) {
                rv = -1;
            }
        } else if (Vehicle.Model.Source == VehicleSource_CM4SL) {
            if (IN_CAR_LAST_PART(part) && Car_CM4SL_Calc(dt) < 0) {
                rv = -1;
            }
        }
        if (Vehicle.Model.Source != VehicleSource_CM4SL) {
            if (IN_TRAILER_PART(part)) {
                if (SimCore.Trailer.nTrailers != 0) {
                    if (Trailer_Calc(dt) < 0) {
                        rv = -2;
                    }
                }
            }
        }
    }

    if (IN_BRAKE_PART(part)) {
        if (Vehicle.Model.Source == VehicleSource_CM4SL && !BrakeDisabled) {
            rv = 0; /* !!Init */
        }
        if (!BrakeDisabled) {
            if (Brake_Calc(dt) < 0) {
                rv = -3;
            }
        }
        if (SimCore.Trailer.nTrailers != 0) {
            if (!TrBrakeDisabled) {
                if (TrBrake_Calc(dt) < 0) {
                    rv = -4;
                }
            }
        }
        if (User_Brake_Calc(dt) < 0) {
            rv = -7;
        }
    }
    if (IN_BRAKEUPD_PART(part)) {
        if (Vehicle.Model.Source == VehicleSource_CM4SL && BrakeDisabled) {
            rv = 0; /* !!Init */
        }
        Brake_CalcPost(dt);
    }

    if (IN_POWERTRAIN_PART(part)) {
        if (!PowerTrainDisabled) {
            if (PowerTrain_Calc(dt) < 0) {
                rv = -5;
            }
        }
    }
    if (IN_POWERTRAINUPD_PART(part)) {
        if (PowerTrain_CM4SL_Calc(dt) < 0) {
            rv = -6;
        }

        PowerFlow_Calc();

        /* Delayed return of the real return code! */
        return rv;
    }

    return 0;
}

/*
 * Vhcl_Snapshot_Take()
 *
 * Takes a snapshot of the actual vehicle state.
 */

int
Vhcl_Snapshot_Take(void)
{
    if (Vehicle.Model.Source == VehicleSource_BuiltIn) {
        return Car_Snapshot_Take();
    } else {
        return 0;
    }
}

/*
 * Vhcl_Snapshot_Export2Inf()
 *
 * Exports all important informations to the model snapshot info handle.
 */

int
Vhcl_Snapshot_Export2Inf(void)
{
    if (Vehicle.Model.Source == VehicleSource_BuiltIn) {
        return Car_Snapshot_Export2Inf();
    } else {
        return 0;
    }
}

/*
 * Vhcl_TestRun_End_Delete()
 *
 * called:
 * - once, to release resources of parts of the vehicle model
 * - at the end of a test run
 * - called from App_TestRun_End()
 */

int
Vhcl_TestRun_End_Delete(void)
{
    return 0;
}

/*
 * Vhcl_Delete()
 *
 * called:
 * - once, to release vehicle model resources
 * - at the beginning before Vhcl_New() really starts
 * - called from App_TestRun_End()
 */

int
Vhcl_Delete(int soft)
{
    /* Soft delete: Only parts from vehicle, which are connected with other modules
       outside the vehicle module (e.g: Road-Handle) */
    if (soft) {
        if (Vehicle.Model.Source == VehicleSource_BuiltIn) {
            Car_SoftDelete();
        }
        Trailer_SoftDelete();
        return 0;
    }

    VehicleStruct_Delete();

    if (Vehicle.Model.Source == VehicleSource_BuiltIn) {
        Car_Delete();
    } else if (Vehicle.Model.Source == VehicleSource_ModelMgr) {
        VhclModel_Delete();
    }

    Trailer_Delete();
    if (!TrBrakeDisabled) {
        TrBrake_Delete();
    }

    if (!BrakeDisabled) {
        Brake_Delete();
    }

    if (!PowerTrainDisabled) {
        PowerTrain_Delete();
    } else {
        PowerTrain_CM4SL_Delete();
    }

    return 0;
}

/*
 * Vhcl_Cleanup()
 *
 * free all vehicle module components
 *
 * called:
 * - once at end of program
 */

void
Vhcl_Cleanup(void)
{
    /* !!! Don't change the order of the following function calls !!! */

    Trailer_Cleanup();
    if (!BrakeDisabled) {
        Brake_Cleanup();
    }
    if (!TrBrakeDisabled) {
        TrBrake_Cleanup();
    }
    if (!PowerTrainDisabled) {
        PowerTrain_Cleanup();
    }
    Car_Cleanup();
}
