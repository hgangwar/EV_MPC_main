#ifndef RTW_HEADER_BMSCurrPowerLimCalc_h_
#define RTW_HEADER_BMSCurrPowerLimCalc_h_
#ifndef BMSCurrPowerLimCalc_COMMON_INCLUDES_
#define BMSCurrPowerLimCalc_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "sl_AsyncioQueue/AsyncioQueueCAPI.h"
#include "simstruc.h"
#include "fixedpoint.h"
#endif
#include "BMSCurrPowerLimCalc_types.h"
#include "rtw_modelmap_simtarget.h"
#include <string.h>
#include "rt_nonfinite.h"
#include <stddef.h>
extern real_T rtP__PlntBattNumCellPar2f2BatteryDCDC_sldd_ ; extern void
BMSCurrPowerLimCalc ( const real32_T d51msl4tbc [ 96 ] , const real32_T
noulgqqcoo [ 96 ] , real32_T * oqmgsset2u , real32_T * kouqt1hzal , real32_T
* kv5an1dmb2 , real32_T * ii5nemx5k0 , real32_T * bnkpia5wne , real32_T *
jqa42ursw1 ) ; extern void du2aze3q0u ( void ) ; extern void mmipgl5oaa (
SimStruct * _mdlRefSfcnS , int_T mdlref_TID0 , void * sysRanPtr , int
contextTid , rtwCAPI_ModelMappingInfo * rt_ParentMMI , const char_T *
rt_ChildPath , int_T rt_ChildMMIIdx , int_T rt_CSTATEIdx ) ; extern void
mr_BMSCurrPowerLimCalc_MdlInfoRegFcn ( SimStruct * mdlRefSfcnS , char_T *
modelName , int_T * retVal ) ; extern mxArray *
mr_BMSCurrPowerLimCalc_GetDWork ( ) ; extern void
mr_BMSCurrPowerLimCalc_SetDWork ( const mxArray * ssDW ) ; extern void
mr_BMSCurrPowerLimCalc_RegisterSimStateChecksum ( SimStruct * S ) ; extern
mxArray * mr_BMSCurrPowerLimCalc_GetSimStateDisallowedBlocks ( ) ; extern
const rtwCAPI_ModelMappingStaticInfo * BMSCurrPowerLimCalc_GetCAPIStaticMap (
void ) ;
#endif
