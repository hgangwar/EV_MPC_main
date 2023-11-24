#ifndef RTW_HEADER_BMSStateMachine_h_
#define RTW_HEADER_BMSStateMachine_h_
#ifndef BMSStateMachine_COMMON_INCLUDES_
#define BMSStateMachine_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "sl_AsyncioQueue/AsyncioQueueCAPI.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "sf_runtime/sfc_sdi.h"
#endif
#include "BMSStateMachine_types.h"
#include "rtw_modelmap_simtarget.h"
#include <string.h>
#include "rt_nonfinite.h"
#include <stddef.h>
extern void c4qsdumjq2 ( real32_T * pwlp5l4a4i , boolean_T * bgba4belhh ,
boolean_T * azgg1ocqza , boolean_T * mj0cynmztp , boolean_T * i0hscfypvw ,
boolean_T * jkj3kgmxuf , boolean_T * lushghqlzg , boolean_T * hezlohk5zo ,
real32_T * bcdwlioiuc ) ; extern void b24n3fhfdi ( real32_T * pwlp5l4a4i ,
boolean_T * bgba4belhh , boolean_T * azgg1ocqza , boolean_T * mj0cynmztp ,
boolean_T * i0hscfypvw , boolean_T * jkj3kgmxuf , boolean_T * lushghqlzg ,
boolean_T * hezlohk5zo , real32_T * bcdwlioiuc ) ; extern void
BMSStateMachine ( const real32_T * oruhyddbro , const real32_T aatb5pl15z [
96 ] , const real32_T * c5cwh3kwbc , const real32_T * lbkohme3rp , const
real32_T * ibls2z0cot , const real32_T * d0lgxpofgn , const real32_T *
cx5scoxckm , const real32_T * iekdqsyjt0 , const real32_T * pjs15nw23z ,
const real32_T * ouprkmyayc , const real32_T * cqcv2k4hdc , const real32_T *
hlejwyzhbo , real32_T * pwlp5l4a4i , boolean_T * bgba4belhh , boolean_T *
azgg1ocqza , boolean_T * mj0cynmztp , boolean_T * i0hscfypvw , boolean_T *
jkj3kgmxuf , boolean_T * lushghqlzg , boolean_T * hezlohk5zo , real32_T *
bcdwlioiuc ) ; extern void jqgqne15uw ( void ) ; extern void n2eo0cythm (
SimStruct * _mdlRefSfcnS , int_T mdlref_TID0 , void * sysRanPtr , int
contextTid , rtwCAPI_ModelMappingInfo * rt_ParentMMI , const char_T *
rt_ChildPath , int_T rt_ChildMMIIdx , int_T rt_CSTATEIdx ) ; extern void
mr_BMSStateMachine_MdlInfoRegFcn ( SimStruct * mdlRefSfcnS , char_T *
modelName , int_T * retVal ) ; extern mxArray * mr_BMSStateMachine_GetDWork (
) ; extern void mr_BMSStateMachine_SetDWork ( const mxArray * ssDW ) ; extern
void mr_BMSStateMachine_RegisterSimStateChecksum ( SimStruct * S ) ; extern
mxArray * mr_BMSStateMachine_GetSimStateDisallowedBlocks ( ) ; extern const
rtwCAPI_ModelMappingStaticInfo * BMSStateMachine_GetCAPIStaticMap ( void ) ;
void mr_BMSStateMachine_CreateInitRestoreData ( ) ; void
mr_BMSStateMachine_CopyFromInitRestoreData ( ) ; void
mr_BMSStateMachine_DestroyInitRestoreData ( ) ;
#endif
