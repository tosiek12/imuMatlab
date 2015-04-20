/* Include files */

#include <stddef.h>
#include "blas.h"
#include "polaczenie_sfun.h"
#include "c1_polaczenie.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(NULL,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static void initialize_c1_polaczenie(SFc1_polaczenieInstanceStruct
  *chartInstance);
static void initialize_params_c1_polaczenie(SFc1_polaczenieInstanceStruct
  *chartInstance);
static void enable_c1_polaczenie(SFc1_polaczenieInstanceStruct *chartInstance);
static void disable_c1_polaczenie(SFc1_polaczenieInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c1_polaczenie(SFc1_polaczenieInstanceStruct *
  chartInstance);
static void set_sim_state_c1_polaczenie(SFc1_polaczenieInstanceStruct
  *chartInstance, const mxArray *c1_st);
static void finalize_c1_polaczenie(SFc1_polaczenieInstanceStruct *chartInstance);
static void sf_c1_polaczenie(SFc1_polaczenieInstanceStruct *chartInstance);
static void initSimStructsc1_polaczenie(SFc1_polaczenieInstanceStruct
  *chartInstance);
static void registerMessagesc1_polaczenie(SFc1_polaczenieInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber);
static void c1_emlrt_marshallIn(SFc1_polaczenieInstanceStruct *chartInstance,
  const mxArray *c1_double, const char_T *c1_identifier, real_T c1_y[9]);
static void c1_b_emlrt_marshallIn(SFc1_polaczenieInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[9]);
static uint8_T c1_c_emlrt_marshallIn(SFc1_polaczenieInstanceStruct
  *chartInstance, const mxArray *c1_b_is_active_c1_polaczenie, const char_T
  *c1_identifier);
static uint8_T c1_d_emlrt_marshallIn(SFc1_polaczenieInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void init_dsm_address_info(SFc1_polaczenieInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c1_polaczenie(SFc1_polaczenieInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c1_is_active_c1_polaczenie = 0U;
}

static void initialize_params_c1_polaczenie(SFc1_polaczenieInstanceStruct
  *chartInstance)
{
}

static void enable_c1_polaczenie(SFc1_polaczenieInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c1_polaczenie(SFc1_polaczenieInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static const mxArray *get_sim_state_c1_polaczenie(SFc1_polaczenieInstanceStruct *
  chartInstance)
{
  const mxArray *c1_st;
  const mxArray *c1_y = NULL;
  int32_T c1_i0;
  real_T c1_u[9];
  const mxArray *c1_b_y = NULL;
  uint8_T c1_b_u;
  const mxArray *c1_c_y = NULL;
  real_T (*c1_d_y)[9];
  c1_d_y = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellarray(2), FALSE);
  for (c1_i0 = 0; c1_i0 < 9; c1_i0++) {
    c1_u[c1_i0] = (*c1_d_y)[c1_i0];
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 9), FALSE);
  sf_mex_setcell(c1_y, 0, c1_b_y);
  c1_b_u = chartInstance->c1_is_active_c1_polaczenie;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 1, c1_c_y);
  sf_mex_assign(&c1_st, c1_y, FALSE);
  return c1_st;
}

static void set_sim_state_c1_polaczenie(SFc1_polaczenieInstanceStruct
  *chartInstance, const mxArray *c1_st)
{
  const mxArray *c1_u;
  real_T (*c1_y)[9];
  c1_y = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  c1_u = sf_mex_dup(c1_st);
  c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 0)), "y",
                      *c1_y);
  chartInstance->c1_is_active_c1_polaczenie = c1_c_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 1)),
     "is_active_c1_polaczenie");
  sf_mex_destroy(&c1_u);
  sf_mex_destroy(&c1_st);
}

static void finalize_c1_polaczenie(SFc1_polaczenieInstanceStruct *chartInstance)
{
}

static void sf_c1_polaczenie(SFc1_polaczenieInstanceStruct *chartInstance)
{
  int32_T c1_i1;
  uint16_T c1_u[9];
  const mxArray *c1_y = NULL;
  static char_T c1_cv0[5] = { 'i', 'n', 't', '1', '6' };

  char_T c1_b_u[5];
  const mxArray *c1_b_y = NULL;
  real_T (*c1_c_y)[9];
  uint16_T (*c1_c_u)[9];
  c1_c_y = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  c1_c_u = (uint16_T (*)[9])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  for (c1_i1 = 0; c1_i1 < 9; c1_i1++) {
    c1_u[c1_i1] = (*c1_c_u)[c1_i1];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 5, 0U, 1U, 0U, 1, 9), FALSE);
  for (c1_i1 = 0; c1_i1 < 5; c1_i1++) {
    c1_b_u[c1_i1] = c1_cv0[c1_i1];
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_b_u, 10, 0U, 1U, 0U, 2, 1, 5),
                FALSE);
  c1_emlrt_marshallIn(chartInstance, sf_mex_call("double", 1U, 1U, 14,
    sf_mex_call("typecast", 1U, 2U, 14, c1_y, 14, c1_b_y)), "double", *c1_c_y);
}

static void initSimStructsc1_polaczenie(SFc1_polaczenieInstanceStruct
  *chartInstance)
{
}

static void registerMessagesc1_polaczenie(SFc1_polaczenieInstanceStruct
  *chartInstance)
{
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber)
{
}

const mxArray *sf_c1_polaczenie_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  sf_mex_assign(&c1_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), FALSE);
  return c1_nameCaptureInfo;
}

static void c1_emlrt_marshallIn(SFc1_polaczenieInstanceStruct *chartInstance,
  const mxArray *c1_double, const char_T *c1_identifier, real_T c1_y[9])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_double), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_double);
}

static void c1_b_emlrt_marshallIn(SFc1_polaczenieInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[9])
{
  real_T c1_dv0[9];
  int32_T c1_i2;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv0, 1, 0, 0U, 1, 0U, 1, 9);
  for (c1_i2 = 0; c1_i2 < 9; c1_i2++) {
    c1_y[c1_i2] = c1_dv0[c1_i2];
  }

  sf_mex_destroy(&c1_u);
}

static uint8_T c1_c_emlrt_marshallIn(SFc1_polaczenieInstanceStruct
  *chartInstance, const mxArray *c1_b_is_active_c1_polaczenie, const char_T
  *c1_identifier)
{
  uint8_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_is_active_c1_polaczenie), &c1_thisId);
  sf_mex_destroy(&c1_b_is_active_c1_polaczenie);
  return c1_y;
}

static uint8_T c1_d_emlrt_marshallIn(SFc1_polaczenieInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint8_T c1_y;
  uint8_T c1_u0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u0, 1, 3, 0U, 0, 0U, 0);
  c1_y = c1_u0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void init_dsm_address_info(SFc1_polaczenieInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

void sf_c1_polaczenie_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1223130260U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2237083285U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(180653291U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1626259468U);
}

mxArray *sf_c1_polaczenie_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("KQH19PVe8k9CktD9MI5ERE");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(9);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(5));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(9);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c1_polaczenie_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c1_polaczenie(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"y\",},{M[8],M[0],T\"is_active_c1_polaczenie\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_polaczenie_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const char* sf_get_instance_specialization(void)
{
  return "WNRrkih3779aGQHYSxY0fD";
}

static void sf_opaque_initialize_c1_polaczenie(void *chartInstanceVar)
{
  initialize_params_c1_polaczenie((SFc1_polaczenieInstanceStruct*)
    chartInstanceVar);
  initialize_c1_polaczenie((SFc1_polaczenieInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c1_polaczenie(void *chartInstanceVar)
{
  enable_c1_polaczenie((SFc1_polaczenieInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c1_polaczenie(void *chartInstanceVar)
{
  disable_c1_polaczenie((SFc1_polaczenieInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c1_polaczenie(void *chartInstanceVar)
{
  sf_c1_polaczenie((SFc1_polaczenieInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c1_polaczenie(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c1_polaczenie
    ((SFc1_polaczenieInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_polaczenie();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_raw2high'.\n");
  }

  return plhs[0];
}

extern void sf_internal_set_sim_state_c1_polaczenie(SimStruct* S, const mxArray *
  st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_polaczenie();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c1_polaczenie((SFc1_polaczenieInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c1_polaczenie(SimStruct* S)
{
  return sf_internal_get_sim_state_c1_polaczenie(S);
}

static void sf_opaque_set_sim_state_c1_polaczenie(SimStruct* S, const mxArray
  *st)
{
  sf_internal_set_sim_state_c1_polaczenie(S, st);
}

static void sf_opaque_terminate_c1_polaczenie(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_polaczenieInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_polaczenie_optimization_info();
    }

    finalize_c1_polaczenie((SFc1_polaczenieInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc1_polaczenie((SFc1_polaczenieInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_polaczenie(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_polaczenie((SFc1_polaczenieInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c1_polaczenie(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_polaczenie_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      1);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,1,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,1,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,1);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,1,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,1,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 1; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,1);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1691308100U));
  ssSetChecksum1(S,(3627789872U));
  ssSetChecksum2(S,(4003764681U));
  ssSetChecksum3(S,(4067434201U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c1_polaczenie(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c1_polaczenie(SimStruct *S)
{
  SFc1_polaczenieInstanceStruct *chartInstance;
  chartInstance = (SFc1_polaczenieInstanceStruct *)utMalloc(sizeof
    (SFc1_polaczenieInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc1_polaczenieInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c1_polaczenie;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c1_polaczenie;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c1_polaczenie;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c1_polaczenie;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c1_polaczenie;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c1_polaczenie;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c1_polaczenie;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c1_polaczenie;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_polaczenie;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_polaczenie;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c1_polaczenie;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->S = S;
  ssSetUserData(S,(void *)(&(chartInstance->chartInfo)));/* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
}

void c1_polaczenie_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_polaczenie(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_polaczenie(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_polaczenie(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_polaczenie_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
