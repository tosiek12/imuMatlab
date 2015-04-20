#ifndef __c1_polaczenie_h__
#define __c1_polaczenie_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
#ifndef typedef_SFc1_polaczenieInstanceStruct
#define typedef_SFc1_polaczenieInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint8_T c1_is_active_c1_polaczenie;
} SFc1_polaczenieInstanceStruct;

#endif                                 /*typedef_SFc1_polaczenieInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c1_polaczenie_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c1_polaczenie_get_check_sum(mxArray *plhs[]);
extern void c1_polaczenie_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
