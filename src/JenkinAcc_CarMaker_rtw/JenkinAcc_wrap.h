/***************************************************** target specific file ***/
/*  Wrapper module for Simulink models                                        */
/*  ------------------------------------------------------------------------  */
/*  (c) IPG Automotive GmbH    www.ipg-automotive.com   Fon: +49.721.98520-0  */
/*  Bannwaldallee 60      D-76185 Karlsruhe   Germany   Fax: +49.721.98520-99 */
/******************************************************************************/

#ifndef __JENKINACC_WRAP_H__
#define __JENKINACC_WRAP_H__
#ifndef IS_CAR
# define IS_CAR
#endif

#ifdef __cplusplus

extern "C" {

#endif

  struct tInfos;
  struct tMdlBdyFrame;
  struct tMatSuppDictDef;
  struct tMatSuppTunables;

#ifdef CLASSIC_INTERFACE
# define rtModel_JenkinAcc             RT_MODEL_JenkinAcc_T
#else
# define rtModel_JenkinAcc             tag_RTM_JenkinAcc_T
#endif                                 //CLASSIC_INTERFACE

#define ExternalInputs_JenkinAcc       ExtU_JenkinAcc_T
#define ExternalOutputs_JenkinAcc      ExtY_JenkinAcc_T
#ifndef JenkinAcc_rtModel

  typedef struct rtModel_JenkinAcc rtModel_JenkinAcc;

#endif

  /* Model registration function */
  rtModel_JenkinAcc *JenkinAcc (struct tInfos *Inf);

#if defined(CLASSIC_INTERFACE) && !defined(CM4SLDS)

  void rt_ODECreateIntegrationData (RTWSolverInfo *si);
  void rt_ODEUpdateContinuousStates(RTWSolverInfo *si);
  void rt_ODEDestroyIntegrationData(RTWSolverInfo *si);

#endif

  /* Dictionary variables and other items of the model */
  extern struct tMatSuppDictDef *JenkinAcc_DictDefines;
  extern struct tMdlBdyFrame *JenkinAcc_BdyFrameDefines;

  /* Wrapper functions */
  void JenkinAcc_SetParams (rtModel_JenkinAcc *rtm,
      struct tMatSuppTunables *tuns,
      struct tInfos *Inf);
  int JenkinAcc_Register (void);

#ifdef __cplusplus

}
#endif
#endif                                 /* __JENKINACC_WRAP_H__ */
