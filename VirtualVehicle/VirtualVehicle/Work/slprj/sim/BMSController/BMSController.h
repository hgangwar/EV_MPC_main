#ifndef RTW_HEADER_BMSController_h_
#define RTW_HEADER_BMSController_h_
#ifndef BMSController_COMMON_INCLUDES_
#define BMSController_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "sl_AsyncioQueue/AsyncioQueueCAPI.h"
#include "simstruc.h"
#include "fixedpoint.h"
#endif
#include "BMSController_types.h"
#include "model_reference_types.h"
#include "rtw_modelmap_simtarget.h"
#include <string.h>
#include "rt_nonfinite.h"
#include <stddef.h>
extern real_T rtP__PlntBattChrgMax2f2BatteryDCDC_sldd_ ; extern real_T
rtP__PlntBattNumCellPar2f2BatteryDCDC_sldd_ ; extern real_T
rtP__PlntBattSocInit2f2BatteryDCDC_sldd_ ; extern void ah533pbmux ( void ) ;
extern void p2t1vykwji ( void ) ; extern void n3ldsg2m4a ( void ) ; extern
void dolsr1ry0j ( void ) ; extern void dhe0j1g5mvTID0 ( const real32_T
adxekd5tio [ 96 ] , const real32_T j3wvkhbfe4 [ 96 ] , const real32_T *
alolnomync , const real32_T * gr0s1ny5og , const real32_T * cne0zycowu ,
const real32_T * lvjqgkdjmc ) ; extern void dhe0j1g5mvTID1 ( void ) ; extern
void BMSControllerTID0 ( boolean_T * e4kvz4supm , real32_T * a3l2j3y4lx ,
real32_T * niiizijeve , real32_T * kvl2ul33en , real32_T * e2rd4hsap2 ,
real32_T * oqx2ehimcf , real32_T * nhnyktxrfk , real32_T * h4i5vc02af ,
boolean_T * chullyjun0 , boolean_T * gamv4ws2w2 , boolean_T * lxuopn21da ,
boolean_T * jcpgvzmuwo , boolean_T * jqswid45re , boolean_T * amy4ujr4ow ,
boolean_T kv4f4pyu01 [ 96 ] ) ; extern void BMSControllerTID1 ( void ) ;
extern void g10dj1kimi ( void ) ; extern void lftbpoqxym ( SimStruct *
_mdlRefSfcnS , int_T mdlref_TID0 , int_T mdlref_TID1 , void * sysRanPtr , int
contextTid , rtwCAPI_ModelMappingInfo * rt_ParentMMI , const char_T *
rt_ChildPath , int_T rt_ChildMMIIdx , int_T rt_CSTATEIdx ) ; extern void
mr_BMSController_MdlInfoRegFcn ( SimStruct * mdlRefSfcnS , char_T * modelName
, int_T * retVal ) ; extern mxArray * mr_BMSController_GetDWork ( ) ; extern
void mr_BMSController_SetDWork ( const mxArray * ssDW ) ; extern void
mr_BMSController_RegisterSimStateChecksum ( SimStruct * S ) ; extern mxArray
* mr_BMSController_GetSimStateDisallowedBlocks ( ) ; extern const
rtwCAPI_ModelMappingStaticInfo * BMSController_GetCAPIStaticMap ( void ) ;
void mr_BMSController_CreateInitRestoreData ( ) ; void
mr_BMSController_CopyFromInitRestoreData ( ) ; void
mr_BMSController_DestroyInitRestoreData ( ) ;
#endif
