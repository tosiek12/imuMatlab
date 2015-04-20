/* Include files */

#include <stddef.h>
#include "blas.h"
#include "obliczeniaOffline6_sfun.h"
#include "c3_obliczeniaOffline6.h"
#include "mwmathutil.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(NULL,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static void initialize_c3_obliczeniaOffline6
  (SFc3_obliczeniaOffline6InstanceStruct *chartInstance);
static void initialize_params_c3_obliczeniaOffline6
  (SFc3_obliczeniaOffline6InstanceStruct *chartInstance);
static void enable_c3_obliczeniaOffline6(SFc3_obliczeniaOffline6InstanceStruct
  *chartInstance);
static void disable_c3_obliczeniaOffline6(SFc3_obliczeniaOffline6InstanceStruct *
  chartInstance);
static const mxArray *get_sim_state_c3_obliczeniaOffline6
  (SFc3_obliczeniaOffline6InstanceStruct *chartInstance);
static void set_sim_state_c3_obliczeniaOffline6
  (SFc3_obliczeniaOffline6InstanceStruct *chartInstance, const mxArray *c3_st);
static void finalize_c3_obliczeniaOffline6(SFc3_obliczeniaOffline6InstanceStruct
  *chartInstance);
static void sf_c3_obliczeniaOffline6(SFc3_obliczeniaOffline6InstanceStruct
  *chartInstance);
static void initSimStructsc3_obliczeniaOffline6
  (SFc3_obliczeniaOffline6InstanceStruct *chartInstance);
static void registerMessagesc3_obliczeniaOffline6
  (SFc3_obliczeniaOffline6InstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber);
static void c3_info_helper(c3_ResolvedFunctionInfo c3_info[22]);
static void c3_eml_error(SFc3_obliczeniaOffline6InstanceStruct *chartInstance);
static void c3_b_eml_error(SFc3_obliczeniaOffline6InstanceStruct *chartInstance);
static void c3_emlrt_marshallIn(SFc3_obliczeniaOffline6InstanceStruct
  *chartInstance, const mxArray *c3_anglesInRadian, const char_T *c3_identifier,
  real_T c3_y[3]);
static void c3_b_emlrt_marshallIn(SFc3_obliczeniaOffline6InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[3]);
static uint8_T c3_c_emlrt_marshallIn(SFc3_obliczeniaOffline6InstanceStruct
  *chartInstance, const mxArray *c3_b_is_active_c3_obliczeniaOffline6, const
  char_T *c3_identifier);
static uint8_T c3_d_emlrt_marshallIn(SFc3_obliczeniaOffline6InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void init_dsm_address_info(SFc3_obliczeniaOffline6InstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c3_obliczeniaOffline6
  (SFc3_obliczeniaOffline6InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c3_is_active_c3_obliczeniaOffline6 = 0U;
}

static void initialize_params_c3_obliczeniaOffline6
  (SFc3_obliczeniaOffline6InstanceStruct *chartInstance)
{
}

static void enable_c3_obliczeniaOffline6(SFc3_obliczeniaOffline6InstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c3_obliczeniaOffline6(SFc3_obliczeniaOffline6InstanceStruct *
  chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static const mxArray *get_sim_state_c3_obliczeniaOffline6
  (SFc3_obliczeniaOffline6InstanceStruct *chartInstance)
{
  const mxArray *c3_st;
  const mxArray *c3_y = NULL;
  int32_T c3_i0;
  real_T c3_u[3];
  const mxArray *c3_b_y = NULL;
  uint8_T c3_b_u;
  const mxArray *c3_c_y = NULL;
  real_T (*c3_anglesInRadian)[3];
  c3_anglesInRadian = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c3_st = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_createcellarray(2), FALSE);
  for (c3_i0 = 0; c3_i0 < 3; c3_i0++) {
    c3_u[c3_i0] = (*c3_anglesInRadian)[c3_i0];
  }

  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_setcell(c3_y, 0, c3_b_y);
  c3_b_u = chartInstance->c3_is_active_c3_obliczeniaOffline6;
  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", &c3_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 1, c3_c_y);
  sf_mex_assign(&c3_st, c3_y, FALSE);
  return c3_st;
}

static void set_sim_state_c3_obliczeniaOffline6
  (SFc3_obliczeniaOffline6InstanceStruct *chartInstance, const mxArray *c3_st)
{
  const mxArray *c3_u;
  real_T (*c3_anglesInRadian)[3];
  c3_anglesInRadian = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c3_u = sf_mex_dup(c3_st);
  c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 0)),
                      "anglesInRadian", *c3_anglesInRadian);
  chartInstance->c3_is_active_c3_obliczeniaOffline6 = c3_c_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 1)),
     "is_active_c3_obliczeniaOffline6");
  sf_mex_destroy(&c3_u);
  sf_mex_destroy(&c3_st);
}

static void finalize_c3_obliczeniaOffline6(SFc3_obliczeniaOffline6InstanceStruct
  *chartInstance)
{
}

static void sf_c3_obliczeniaOffline6(SFc3_obliczeniaOffline6InstanceStruct
  *chartInstance)
{
  real_T c3_anglesInRadian[3];
  real32_T c3_x;
  int32_T c3_i1;
  real_T (*c3_b_anglesInRadian)[3];
  real32_T (*c3_acceleration)[3];
  c3_b_anglesInRadian = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c3_acceleration = (real32_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  c3_anglesInRadian[0] = muSingleScalarAtan2((*c3_acceleration)[1],
    (*c3_acceleration)[2]);
  c3_x = (*c3_acceleration)[1] * (*c3_acceleration)[1] + (*c3_acceleration)[2] *
    (*c3_acceleration)[2];
  if (c3_x < 0.0F) {
    c3_eml_error(chartInstance);
  }

  c3_anglesInRadian[1] = muSingleScalarAtan2(-(*c3_acceleration)[0],
    muSingleScalarSqrt(c3_x));
  c3_x = ((*c3_acceleration)[0] * (*c3_acceleration)[0] + (*c3_acceleration)[1] *
          (*c3_acceleration)[1]) + (*c3_acceleration)[2] * (*c3_acceleration)[2];
  if (c3_x < 0.0F) {
    c3_eml_error(chartInstance);
  }

  c3_x = (*c3_acceleration)[2] / muSingleScalarSqrt(c3_x);
  if ((c3_x < -1.0F) || (1.0F < c3_x)) {
    c3_b_eml_error(chartInstance);
  }

  c3_anglesInRadian[2] = muSingleScalarAcos(c3_x);
  for (c3_i1 = 0; c3_i1 < 3; c3_i1++) {
    (*c3_b_anglesInRadian)[c3_i1] = c3_anglesInRadian[c3_i1];
  }
}

static void initSimStructsc3_obliczeniaOffline6
  (SFc3_obliczeniaOffline6InstanceStruct *chartInstance)
{
}

static void registerMessagesc3_obliczeniaOffline6
  (SFc3_obliczeniaOffline6InstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber)
{
}

const mxArray *sf_c3_obliczeniaOffline6_get_eml_resolved_functions_info(void)
{
  const mxArray *c3_nameCaptureInfo;
  c3_ResolvedFunctionInfo c3_info[22];
  const mxArray *c3_m0 = NULL;
  int32_T c3_i2;
  c3_ResolvedFunctionInfo *c3_r0;
  c3_nameCaptureInfo = NULL;
  c3_info_helper(c3_info);
  sf_mex_assign(&c3_m0, sf_mex_createstruct("nameCaptureInfo", 1, 22), FALSE);
  for (c3_i2 = 0; c3_i2 < 22; c3_i2++) {
    c3_r0 = &c3_info[c3_i2];
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c3_r0->context)), "context", "nameCaptureInfo",
                    c3_i2);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c3_r0->name)), "name", "nameCaptureInfo", c3_i2);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c3_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c3_i2);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c3_r0->resolved)), "resolved", "nameCaptureInfo",
                    c3_i2);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c3_i2);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c3_i2);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c3_i2);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c3_i2);
  }

  sf_mex_assign(&c3_nameCaptureInfo, c3_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c3_nameCaptureInfo);
  return c3_nameCaptureInfo;
}

static void c3_info_helper(c3_ResolvedFunctionInfo c3_info[22])
{
  c3_info[0].context = "";
  c3_info[0].name = "atan2";
  c3_info[0].dominantType = "single";
  c3_info[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m";
  c3_info[0].fileTimeLo = 1343830372U;
  c3_info[0].fileTimeHi = 0U;
  c3_info[0].mFileTimeLo = 0U;
  c3_info[0].mFileTimeHi = 0U;
  c3_info[1].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m";
  c3_info[1].name = "eml_scalar_eg";
  c3_info[1].dominantType = "single";
  c3_info[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c3_info[1].fileTimeLo = 1286818796U;
  c3_info[1].fileTimeHi = 0U;
  c3_info[1].mFileTimeLo = 0U;
  c3_info[1].mFileTimeHi = 0U;
  c3_info[2].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m";
  c3_info[2].name = "eml_scalexp_alloc";
  c3_info[2].dominantType = "single";
  c3_info[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c3_info[2].fileTimeLo = 1352424860U;
  c3_info[2].fileTimeHi = 0U;
  c3_info[2].mFileTimeLo = 0U;
  c3_info[2].mFileTimeHi = 0U;
  c3_info[3].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m";
  c3_info[3].name = "eml_scalar_atan2";
  c3_info[3].dominantType = "single";
  c3_info[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_atan2.m";
  c3_info[3].fileTimeLo = 1286818720U;
  c3_info[3].fileTimeHi = 0U;
  c3_info[3].mFileTimeLo = 0U;
  c3_info[3].mFileTimeHi = 0U;
  c3_info[4].context = "";
  c3_info[4].name = "mpower";
  c3_info[4].dominantType = "single";
  c3_info[4].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c3_info[4].fileTimeLo = 1286818842U;
  c3_info[4].fileTimeHi = 0U;
  c3_info[4].mFileTimeLo = 0U;
  c3_info[4].mFileTimeHi = 0U;
  c3_info[5].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c3_info[5].name = "power";
  c3_info[5].dominantType = "single";
  c3_info[5].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c3_info[5].fileTimeLo = 1348191930U;
  c3_info[5].fileTimeHi = 0U;
  c3_info[5].mFileTimeLo = 0U;
  c3_info[5].mFileTimeHi = 0U;
  c3_info[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c3_info[6].name = "eml_scalar_eg";
  c3_info[6].dominantType = "single";
  c3_info[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c3_info[6].fileTimeLo = 1286818796U;
  c3_info[6].fileTimeHi = 0U;
  c3_info[6].mFileTimeLo = 0U;
  c3_info[6].mFileTimeHi = 0U;
  c3_info[7].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c3_info[7].name = "eml_scalexp_alloc";
  c3_info[7].dominantType = "single";
  c3_info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c3_info[7].fileTimeLo = 1352424860U;
  c3_info[7].fileTimeHi = 0U;
  c3_info[7].mFileTimeLo = 0U;
  c3_info[7].mFileTimeHi = 0U;
  c3_info[8].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c3_info[8].name = "floor";
  c3_info[8].dominantType = "double";
  c3_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c3_info[8].fileTimeLo = 1343830380U;
  c3_info[8].fileTimeHi = 0U;
  c3_info[8].mFileTimeLo = 0U;
  c3_info[8].mFileTimeHi = 0U;
  c3_info[9].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c3_info[9].name = "eml_scalar_floor";
  c3_info[9].dominantType = "double";
  c3_info[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c3_info[9].fileTimeLo = 1286818726U;
  c3_info[9].fileTimeHi = 0U;
  c3_info[9].mFileTimeLo = 0U;
  c3_info[9].mFileTimeHi = 0U;
  c3_info[10].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!scalar_float_power";
  c3_info[10].name = "eml_scalar_eg";
  c3_info[10].dominantType = "single";
  c3_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c3_info[10].fileTimeLo = 1286818796U;
  c3_info[10].fileTimeHi = 0U;
  c3_info[10].mFileTimeLo = 0U;
  c3_info[10].mFileTimeHi = 0U;
  c3_info[11].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!scalar_float_power";
  c3_info[11].name = "mtimes";
  c3_info[11].dominantType = "single";
  c3_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[11].fileTimeLo = 1289519692U;
  c3_info[11].fileTimeHi = 0U;
  c3_info[11].mFileTimeLo = 0U;
  c3_info[11].mFileTimeHi = 0U;
  c3_info[12].context = "";
  c3_info[12].name = "sqrt";
  c3_info[12].dominantType = "single";
  c3_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c3_info[12].fileTimeLo = 1343830386U;
  c3_info[12].fileTimeHi = 0U;
  c3_info[12].mFileTimeLo = 0U;
  c3_info[12].mFileTimeHi = 0U;
  c3_info[13].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c3_info[13].name = "eml_error";
  c3_info[13].dominantType = "char";
  c3_info[13].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c3_info[13].fileTimeLo = 1343830358U;
  c3_info[13].fileTimeHi = 0U;
  c3_info[13].mFileTimeLo = 0U;
  c3_info[13].mFileTimeHi = 0U;
  c3_info[14].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c3_info[14].name = "eml_scalar_sqrt";
  c3_info[14].dominantType = "single";
  c3_info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m";
  c3_info[14].fileTimeLo = 1286818738U;
  c3_info[14].fileTimeHi = 0U;
  c3_info[14].mFileTimeLo = 0U;
  c3_info[14].mFileTimeHi = 0U;
  c3_info[15].context = "";
  c3_info[15].name = "mrdivide";
  c3_info[15].dominantType = "single";
  c3_info[15].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c3_info[15].fileTimeLo = 1357951548U;
  c3_info[15].fileTimeHi = 0U;
  c3_info[15].mFileTimeLo = 1319729966U;
  c3_info[15].mFileTimeHi = 0U;
  c3_info[16].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c3_info[16].name = "rdivide";
  c3_info[16].dominantType = "single";
  c3_info[16].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c3_info[16].fileTimeLo = 1346510388U;
  c3_info[16].fileTimeHi = 0U;
  c3_info[16].mFileTimeLo = 0U;
  c3_info[16].mFileTimeHi = 0U;
  c3_info[17].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c3_info[17].name = "eml_scalexp_compatible";
  c3_info[17].dominantType = "single";
  c3_info[17].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m";
  c3_info[17].fileTimeLo = 1286818796U;
  c3_info[17].fileTimeHi = 0U;
  c3_info[17].mFileTimeLo = 0U;
  c3_info[17].mFileTimeHi = 0U;
  c3_info[18].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c3_info[18].name = "eml_div";
  c3_info[18].dominantType = "single";
  c3_info[18].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c3_info[18].fileTimeLo = 1313347810U;
  c3_info[18].fileTimeHi = 0U;
  c3_info[18].mFileTimeLo = 0U;
  c3_info[18].mFileTimeHi = 0U;
  c3_info[19].context = "";
  c3_info[19].name = "acos";
  c3_info[19].dominantType = "single";
  c3_info[19].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/acos.m";
  c3_info[19].fileTimeLo = 1343830366U;
  c3_info[19].fileTimeHi = 0U;
  c3_info[19].mFileTimeLo = 0U;
  c3_info[19].mFileTimeHi = 0U;
  c3_info[20].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/acos.m";
  c3_info[20].name = "eml_error";
  c3_info[20].dominantType = "char";
  c3_info[20].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c3_info[20].fileTimeLo = 1343830358U;
  c3_info[20].fileTimeHi = 0U;
  c3_info[20].mFileTimeLo = 0U;
  c3_info[20].mFileTimeHi = 0U;
  c3_info[21].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/acos.m";
  c3_info[21].name = "eml_scalar_acos";
  c3_info[21].dominantType = "single";
  c3_info[21].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_acos.m";
  c3_info[21].fileTimeLo = 1343830376U;
  c3_info[21].fileTimeHi = 0U;
  c3_info[21].mFileTimeLo = 0U;
  c3_info[21].mFileTimeHi = 0U;
}

static void c3_eml_error(SFc3_obliczeniaOffline6InstanceStruct *chartInstance)
{
  int32_T c3_i3;
  static char_T c3_cv0[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'E', 'l', 'F', 'u', 'n', 'D', 'o', 'm', 'a', 'i', 'n',
    'E', 'r', 'r', 'o', 'r' };

  char_T c3_u[30];
  const mxArray *c3_y = NULL;
  static char_T c3_cv1[4] = { 's', 'q', 'r', 't' };

  char_T c3_b_u[4];
  const mxArray *c3_b_y = NULL;
  for (c3_i3 = 0; c3_i3 < 30; c3_i3++) {
    c3_u[c3_i3] = c3_cv0[c3_i3];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 30), FALSE);
  for (c3_i3 = 0; c3_i3 < 4; c3_i3++) {
    c3_b_u[c3_i3] = c3_cv1[c3_i3];
  }

  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", c3_b_u, 10, 0U, 1U, 0U, 2, 1, 4),
                FALSE);
  sf_mex_call("error", 0U, 1U, 14, sf_mex_call("message", 1U, 2U, 14, c3_y, 14,
    c3_b_y));
}

static void c3_b_eml_error(SFc3_obliczeniaOffline6InstanceStruct *chartInstance)
{
  int32_T c3_i4;
  static char_T c3_cv2[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'E', 'l', 'F', 'u', 'n', 'D', 'o', 'm', 'a', 'i', 'n',
    'E', 'r', 'r', 'o', 'r' };

  char_T c3_u[30];
  const mxArray *c3_y = NULL;
  static char_T c3_cv3[4] = { 'a', 'c', 'o', 's' };

  char_T c3_b_u[4];
  const mxArray *c3_b_y = NULL;
  for (c3_i4 = 0; c3_i4 < 30; c3_i4++) {
    c3_u[c3_i4] = c3_cv2[c3_i4];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 30), FALSE);
  for (c3_i4 = 0; c3_i4 < 4; c3_i4++) {
    c3_b_u[c3_i4] = c3_cv3[c3_i4];
  }

  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", c3_b_u, 10, 0U, 1U, 0U, 2, 1, 4),
                FALSE);
  sf_mex_call("error", 0U, 1U, 14, sf_mex_call("message", 1U, 2U, 14, c3_y, 14,
    c3_b_y));
}

static void c3_emlrt_marshallIn(SFc3_obliczeniaOffline6InstanceStruct
  *chartInstance, const mxArray *c3_anglesInRadian, const char_T *c3_identifier,
  real_T c3_y[3])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_anglesInRadian), &c3_thisId,
                        c3_y);
  sf_mex_destroy(&c3_anglesInRadian);
}

static void c3_b_emlrt_marshallIn(SFc3_obliczeniaOffline6InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[3])
{
  real_T c3_dv0[3];
  int32_T c3_i5;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv0, 1, 0, 0U, 1, 0U, 1, 3);
  for (c3_i5 = 0; c3_i5 < 3; c3_i5++) {
    c3_y[c3_i5] = c3_dv0[c3_i5];
  }

  sf_mex_destroy(&c3_u);
}

static uint8_T c3_c_emlrt_marshallIn(SFc3_obliczeniaOffline6InstanceStruct
  *chartInstance, const mxArray *c3_b_is_active_c3_obliczeniaOffline6, const
  char_T *c3_identifier)
{
  uint8_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_b_is_active_c3_obliczeniaOffline6), &c3_thisId);
  sf_mex_destroy(&c3_b_is_active_c3_obliczeniaOffline6);
  return c3_y;
}

static uint8_T c3_d_emlrt_marshallIn(SFc3_obliczeniaOffline6InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  uint8_T c3_y;
  uint8_T c3_u0;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_u0, 1, 3, 0U, 0, 0U, 0);
  c3_y = c3_u0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void init_dsm_address_info(SFc3_obliczeniaOffline6InstanceStruct
  *chartInstance)
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

void sf_c3_obliczeniaOffline6_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3019373543U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(825083408U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3951198490U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2492669056U);
}

mxArray *sf_c3_obliczeniaOffline6_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("eSWBes4k4NX9HwZ5GvHJRC");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(9));
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
      pr[0] = (double)(3);
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

mxArray *sf_c3_obliczeniaOffline6_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c3_obliczeniaOffline6(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"anglesInRadian\",},{M[8],M[0],T\"is_active_c3_obliczeniaOffline6\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c3_obliczeniaOffline6_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const char* sf_get_instance_specialization(void)
{
  return "XQb5RYA5nFBgKadmEvHh0E";
}

static void sf_opaque_initialize_c3_obliczeniaOffline6(void *chartInstanceVar)
{
  initialize_params_c3_obliczeniaOffline6((SFc3_obliczeniaOffline6InstanceStruct*)
    chartInstanceVar);
  initialize_c3_obliczeniaOffline6((SFc3_obliczeniaOffline6InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c3_obliczeniaOffline6(void *chartInstanceVar)
{
  enable_c3_obliczeniaOffline6((SFc3_obliczeniaOffline6InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c3_obliczeniaOffline6(void *chartInstanceVar)
{
  disable_c3_obliczeniaOffline6((SFc3_obliczeniaOffline6InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c3_obliczeniaOffline6(void *chartInstanceVar)
{
  sf_c3_obliczeniaOffline6((SFc3_obliczeniaOffline6InstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c3_obliczeniaOffline6(SimStruct*
  S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c3_obliczeniaOffline6
    ((SFc3_obliczeniaOffline6InstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c3_obliczeniaOffline6();/* state var info */
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

extern void sf_internal_set_sim_state_c3_obliczeniaOffline6(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c3_obliczeniaOffline6();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c3_obliczeniaOffline6((SFc3_obliczeniaOffline6InstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c3_obliczeniaOffline6(SimStruct* S)
{
  return sf_internal_get_sim_state_c3_obliczeniaOffline6(S);
}

static void sf_opaque_set_sim_state_c3_obliczeniaOffline6(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c3_obliczeniaOffline6(S, st);
}

static void sf_opaque_terminate_c3_obliczeniaOffline6(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc3_obliczeniaOffline6InstanceStruct*) chartInstanceVar)
      ->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_obliczeniaOffline6_optimization_info();
    }

    finalize_c3_obliczeniaOffline6((SFc3_obliczeniaOffline6InstanceStruct*)
      chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc3_obliczeniaOffline6((SFc3_obliczeniaOffline6InstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c3_obliczeniaOffline6(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c3_obliczeniaOffline6
      ((SFc3_obliczeniaOffline6InstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c3_obliczeniaOffline6(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_obliczeniaOffline6_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      3);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,3,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,3,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,3);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,3,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,3,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,3);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(312896086U));
  ssSetChecksum1(S,(1811658432U));
  ssSetChecksum2(S,(4022686227U));
  ssSetChecksum3(S,(386951905U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c3_obliczeniaOffline6(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c3_obliczeniaOffline6(SimStruct *S)
{
  SFc3_obliczeniaOffline6InstanceStruct *chartInstance;
  chartInstance = (SFc3_obliczeniaOffline6InstanceStruct *)utMalloc(sizeof
    (SFc3_obliczeniaOffline6InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc3_obliczeniaOffline6InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c3_obliczeniaOffline6;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c3_obliczeniaOffline6;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c3_obliczeniaOffline6;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c3_obliczeniaOffline6;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c3_obliczeniaOffline6;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c3_obliczeniaOffline6;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c3_obliczeniaOffline6;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c3_obliczeniaOffline6;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c3_obliczeniaOffline6;
  chartInstance->chartInfo.mdlStart = mdlStart_c3_obliczeniaOffline6;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c3_obliczeniaOffline6;
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

void c3_obliczeniaOffline6_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c3_obliczeniaOffline6(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c3_obliczeniaOffline6(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c3_obliczeniaOffline6(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c3_obliczeniaOffline6_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
