#ifndef RTW_HEADER_BMSSOCEstimation_h_
#define RTW_HEADER_BMSSOCEstimation_h_
#ifndef BMSSOCEstimation_COMMON_INCLUDES_
#define BMSSOCEstimation_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "sl_AsyncioQueue/AsyncioQueueCAPI.h"
#include "simstruc.h"
#include "fixedpoint.h"
#endif
#include "BMSSOCEstimation_types.h"
#include "rtw_modelmap_simtarget.h"
#include <string.h>
#include "rt_nonfinite.h"
#include <stddef.h>
extern real_T rtP__PlntBattChrgMax2f2BatteryDCDC_sldd_ ; extern real_T
rtP__PlntBattNumCellPar2f2BatteryDCDC_sldd_ ; extern real_T
rtP__PlntBattSocInit2f2BatteryDCDC_sldd_ ; extern void bbzyccyfe5 ( void ) ;
extern void hue3c0yakn ( void ) ; extern void ioolb10wj0 ( void ) ; extern
void BMSSOCEstimation ( const real32_T * e4051bwwkz , real32_T * bjpjid5gap ,
real32_T * g1ypzcddoc , real32_T * hyfhu3uvbm ) ; extern void kcczw4j51s (
void ) ; extern void dllaarzzct ( SimStruct * _mdlRefSfcnS , int_T
mdlref_TID0 , void * sysRanPtr , int contextTid , rtwCAPI_ModelMappingInfo *
rt_ParentMMI , const char_T * rt_ChildPath , int_T rt_ChildMMIIdx , int_T
rt_CSTATEIdx ) ; extern void mr_BMSSOCEstimation_MdlInfoRegFcn ( SimStruct *
mdlRefSfcnS , char_T * modelName , int_T * retVal ) ; extern mxArray *
mr_BMSSOCEstimation_GetDWork ( ) ; extern void mr_BMSSOCEstimation_SetDWork (
const mxArray * ssDW ) ; extern void
mr_BMSSOCEstimation_RegisterSimStateChecksum ( SimStruct * S ) ; extern
mxArray * mr_BMSSOCEstimation_GetSimStateDisallowedBlocks ( ) ; extern const
rtwCAPI_ModelMappingStaticInfo * BMSSOCEstimation_GetCAPIStaticMap ( void ) ;
void mr_BMSSOCEstimation_CreateInitRestoreData ( ) ; void
mr_BMSSOCEstimation_CopyFromInitRestoreData ( ) ; void
mr_BMSSOCEstimation_DestroyInitRestoreData ( ) ;
#endif
