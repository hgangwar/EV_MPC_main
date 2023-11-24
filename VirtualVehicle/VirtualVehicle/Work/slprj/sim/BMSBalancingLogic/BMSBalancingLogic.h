#ifndef RTW_HEADER_BMSBalancingLogic_h_
#define RTW_HEADER_BMSBalancingLogic_h_
#ifndef BMSBalancingLogic_COMMON_INCLUDES_
#define BMSBalancingLogic_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "sl_AsyncioQueue/AsyncioQueueCAPI.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "sf_runtime/sfc_sdi.h"
#endif
#include "BMSBalancingLogic_types.h"
#include "rtw_modelmap_simtarget.h"
#include <string.h>
#include "rt_nonfinite.h"
#include <stddef.h>
extern void okbayvkvs0 ( boolean_T n4byhwdk3h [ 96 ] ) ; extern void
l0kmnlkf5y ( boolean_T n4byhwdk3h [ 96 ] ) ; extern void BMSBalancingLogic (
const real32_T * kzzpi5g2pn , const real32_T kecw5f4uup [ 96 ] , const
real32_T * h2x23ryqoh , const real32_T * erx1den1g5 , boolean_T n4byhwdk3h [
96 ] ) ; extern void jozn1uvmvd ( void ) ; extern void bjd0wkxsam ( SimStruct
* _mdlRefSfcnS , int_T mdlref_TID0 , void * sysRanPtr , int contextTid ,
rtwCAPI_ModelMappingInfo * rt_ParentMMI , const char_T * rt_ChildPath , int_T
rt_ChildMMIIdx , int_T rt_CSTATEIdx ) ; extern void
mr_BMSBalancingLogic_MdlInfoRegFcn ( SimStruct * mdlRefSfcnS , char_T *
modelName , int_T * retVal ) ; extern mxArray * mr_BMSBalancingLogic_GetDWork
( ) ; extern void mr_BMSBalancingLogic_SetDWork ( const mxArray * ssDW ) ;
extern void mr_BMSBalancingLogic_RegisterSimStateChecksum ( SimStruct * S ) ;
extern mxArray * mr_BMSBalancingLogic_GetSimStateDisallowedBlocks ( ) ;
extern const rtwCAPI_ModelMappingStaticInfo *
BMSBalancingLogic_GetCAPIStaticMap ( void ) ; void
mr_BMSBalancingLogic_CreateInitRestoreData ( ) ; void
mr_BMSBalancingLogic_CopyFromInitRestoreData ( ) ; void
mr_BMSBalancingLogic_DestroyInitRestoreData ( ) ;
#endif
