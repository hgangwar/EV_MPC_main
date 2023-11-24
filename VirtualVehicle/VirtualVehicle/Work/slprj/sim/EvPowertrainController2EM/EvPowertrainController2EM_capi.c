#include <stddef.h>
#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "EvPowertrainController2EM_capi_host.h"
#define sizeof(s) ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el) ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s) (s)
#ifndef SS_UINT64
#define SS_UINT64 19
#endif
#ifndef SS_INT64
#define SS_INT64 20
#endif
#else
#include "builtin_typeid_types.h"
#include "EvPowertrainController2EM.h"
#include "EvPowertrainController2EM_capi.h"
#include "EvPowertrainController2EM_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST
#define TARGET_STRING(s)               ((NULL))
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif
static rtwCAPI_Signals rtBlockSignals [ ] = { { 0 , 0 , ( NULL ) , ( NULL ) ,
0 , 0 , 0 , 0 , 0 } } ; static rtwCAPI_States rtBlockStates [ ] = { { 0 , - 1
, TARGET_STRING (
 "EvPowertrainController2EM/Energy Management/Hamiltonian computation \nand minimization/Unit Delay1"
) , TARGET_STRING ( "DSTATE" ) , "" , 0 , 0 , 0 , 0 , 0 , 0 , - 1 , 0 } , { 1
, - 1 , TARGET_STRING (
 "EvPowertrainController2EM/Energy Management/Hamiltonian computation \nand minimization/Unit Delay2"
) , TARGET_STRING ( "DSTATE" ) , "" , 0 , 0 , 0 , 0 , 0 , 0 , - 1 , 0 } , { 2
, - 1 , TARGET_STRING (
"EvPowertrainController2EM/Energy Management/Powertrain Constraints /Unit Delay"
) , TARGET_STRING ( "DSTATE" ) , "" , 0 , 0 , 1 , 0 , 0 , 0 , - 1 , 0 } , { 3
, - 1 , TARGET_STRING (
 "EvPowertrainController2EM/Energy Management/Powertrain Constraints /Unit Delay1"
) , TARGET_STRING ( "DSTATE" ) , "" , 0 , 0 , 1 , 0 , 0 , 0 , - 1 , 0 } , { 4
, - 1 , TARGET_STRING (
 "EvPowertrainController2EM/Energy Management/Convert Whl to EMTrq Vector/2EM/Unit Delay"
) , TARGET_STRING ( "DSTATE" ) , "" , 0 , 0 , 0 , 0 , 0 , 0 , - 1 , 0 } , { 5
, - 1 , TARGET_STRING (
 "EvPowertrainController2EM/Energy Management/Convert Whl to EMTrq Vector/2EM/Unit Delay1"
) , TARGET_STRING ( "DSTATE" ) , "" , 0 , 0 , 0 , 0 , 0 , 0 , - 1 , 0 } , { 6
, - 1 , TARGET_STRING (
 "EvPowertrainController2EM/Energy Management/Powertrain Constraints /EM Constraint Front/Tabular Power Loss Data/2EM or 3EM Dual Rear/WhlTrq2EMTrq/Unit Delay"
) , TARGET_STRING ( "DSTATE" ) , "" , 0 , 0 , 1 , 0 , 0 , 0 , - 1 , 0 } , { 7
, - 1 , TARGET_STRING (
 "EvPowertrainController2EM/Energy Management/Powertrain Constraints /EM Constraint Rear/Tabular Power Loss Data/2EM/WhlTrq2EMTrq/Unit Delay"
) , TARGET_STRING ( "DSTATE" ) , "" , 0 , 0 , 1 , 0 , 0 , 0 , - 1 , 0 } , { 0
, - 1 , ( NULL ) , ( NULL ) , ( NULL ) , 0 , 0 , 0 , 0 , 0 , 0 , - 1 , 0 } }
; static int_T rt_LoggedStateIdxList [ ] = { 4 , 5 , 1 , 2 , 6 , 7 , 0 , 3 }
;
#ifndef HOST_CAPI_BUILD
static void EvPowertrainController2EM_InitializeDataAddr ( void * dataAddr [
] , cpxpfpdja3 * localDW ) { dataAddr [ 0 ] = ( void * ) ( & localDW ->
mnt5i0lw4q ) ; dataAddr [ 1 ] = ( void * ) ( & localDW -> o5t0xnvnze ) ;
dataAddr [ 2 ] = ( void * ) ( & localDW -> glinugelel [ 0 ] ) ; dataAddr [ 3
] = ( void * ) ( & localDW -> cg13f1zg3e [ 0 ] ) ; dataAddr [ 4 ] = ( void *
) ( & localDW -> f12x4t2yjl ) ; dataAddr [ 5 ] = ( void * ) ( & localDW ->
ow2qkdjqul ) ; dataAddr [ 6 ] = ( void * ) ( & localDW -> gimarahrpl [ 0 ] )
; dataAddr [ 7 ] = ( void * ) ( & localDW -> p5p4aaxq51 [ 0 ] ) ; }
#endif
#ifndef HOST_CAPI_BUILD
static void EvPowertrainController2EM_InitializeVarDimsAddr ( int32_T *
vardimsAddr [ ] ) { vardimsAddr [ 0 ] = ( NULL ) ; }
#endif
#ifndef HOST_CAPI_BUILD
static void EvPowertrainController2EM_InitializeLoggingFunctions (
RTWLoggingFcnPtr loggingPtrs [ ] ) { loggingPtrs [ 0 ] = ( NULL ) ;
loggingPtrs [ 1 ] = ( NULL ) ; loggingPtrs [ 2 ] = ( NULL ) ; loggingPtrs [ 3
] = ( NULL ) ; loggingPtrs [ 4 ] = ( NULL ) ; loggingPtrs [ 5 ] = ( NULL ) ;
loggingPtrs [ 6 ] = ( NULL ) ; loggingPtrs [ 7 ] = ( NULL ) ; }
#endif
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap [ ] = { { "double" ,
"real_T" , 0 , 0 , sizeof ( real_T ) , ( uint8_T ) SS_DOUBLE , 0 , 0 , 0 } }
;
#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif
static TARGET_CONST rtwCAPI_ElementMap rtElementMap [ ] = { { ( NULL ) , 0 ,
0 , 0 , 0 } , } ; static rtwCAPI_DimensionMap rtDimensionMap [ ] = { {
rtwCAPI_SCALAR , 0 , 2 , 0 } , { rtwCAPI_VECTOR , 2 , 2 , 0 } } ; static
uint_T rtDimensionArray [ ] = { 1 , 1 , 201 , 1 } ; static const real_T
rtcapiStoredFloats [ ] = { 0.0005 , 0.0 } ; static rtwCAPI_FixPtMap
rtFixPtMap [ ] = { { ( NULL ) , ( NULL ) , rtwCAPI_FIX_RESERVED , 0 , 0 , (
boolean_T ) 0 } , } ; static rtwCAPI_SampleTimeMap rtSampleTimeMap [ ] = { {
( const void * ) & rtcapiStoredFloats [ 0 ] , ( const void * ) &
rtcapiStoredFloats [ 1 ] , ( int8_T ) 1 , ( uint8_T ) 0 } } ; static int_T
rtContextSystems [ 6 ] ; static rtwCAPI_LoggingMetaInfo loggingMetaInfo [ ] =
{ { 0 , 0 , "" , 0 } } ; static rtwCAPI_ModelMapLoggingStaticInfo
mmiStaticInfoLogging = { 6 , rtContextSystems , loggingMetaInfo , 0 , ( NULL
) , { 0 , ( NULL ) , ( NULL ) } , 0 , ( NULL ) } ; static
rtwCAPI_ModelMappingStaticInfo mmiStatic = { { rtBlockSignals , 0 , ( NULL )
, 0 , ( NULL ) , 0 } , { ( NULL ) , 0 , ( NULL ) , 0 } , { rtBlockStates , 8
} , { rtDataTypeMap , rtDimensionMap , rtFixPtMap , rtElementMap ,
rtSampleTimeMap , rtDimensionArray } , "float" , { 487929772U , 3370733154U ,
1422763203U , 2848044255U } , & mmiStaticInfoLogging , 0 , ( boolean_T ) 0 ,
rt_LoggedStateIdxList } ; const rtwCAPI_ModelMappingStaticInfo *
EvPowertrainController2EM_GetCAPIStaticMap ( void ) { return & mmiStatic ; }
#ifndef HOST_CAPI_BUILD
static void EvPowertrainController2EM_InitializeSystemRan ( nwcwzcnldx *
const jcaapsdo3t , sysRanDType * systemRan [ ] , cpxpfpdja3 * localDW , int_T
systemTid [ ] , void * rootSysRanPtr , int rootTid ) { UNUSED_PARAMETER (
jcaapsdo3t ) ; UNUSED_PARAMETER ( localDW ) ; systemRan [ 0 ] = ( sysRanDType
* ) rootSysRanPtr ; systemRan [ 1 ] = ( NULL ) ; systemRan [ 2 ] = (
sysRanDType * ) & localDW -> mfbmya0nxt ; systemRan [ 3 ] = ( sysRanDType * )
& localDW -> nx0zq5arfp ; systemRan [ 4 ] = ( NULL ) ; systemRan [ 5 ] = (
NULL ) ; systemTid [ 1 ] = jcaapsdo3t -> Timing . mdlref_GlobalTID [ 1 ] ;
systemTid [ 3 ] = jcaapsdo3t -> Timing . mdlref_GlobalTID [ 1 ] ; systemTid [
2 ] = jcaapsdo3t -> Timing . mdlref_GlobalTID [ 1 ] ; systemTid [ 4 ] =
jcaapsdo3t -> Timing . mdlref_GlobalTID [ 0 ] ; systemTid [ 5 ] = jcaapsdo3t
-> Timing . mdlref_GlobalTID [ 0 ] ; systemTid [ 0 ] = rootTid ;
rtContextSystems [ 0 ] = 0 ; rtContextSystems [ 1 ] = 0 ; rtContextSystems [
2 ] = 2 ; rtContextSystems [ 3 ] = 3 ; rtContextSystems [ 4 ] = 0 ;
rtContextSystems [ 5 ] = 0 ; }
#endif
#ifndef HOST_CAPI_BUILD
void EvPowertrainController2EM_InitializeDataMapInfo ( nwcwzcnldx * const
jcaapsdo3t , cpxpfpdja3 * localDW , void * sysRanPtr , int contextTid ) {
rtwCAPI_SetVersion ( jcaapsdo3t -> DataMapInfo . mmi , 1 ) ;
rtwCAPI_SetStaticMap ( jcaapsdo3t -> DataMapInfo . mmi , & mmiStatic ) ;
rtwCAPI_SetLoggingStaticMap ( jcaapsdo3t -> DataMapInfo . mmi , &
mmiStaticInfoLogging ) ; EvPowertrainController2EM_InitializeDataAddr (
jcaapsdo3t -> DataMapInfo . dataAddress , localDW ) ;
rtwCAPI_SetDataAddressMap ( jcaapsdo3t -> DataMapInfo . mmi , jcaapsdo3t ->
DataMapInfo . dataAddress ) ; EvPowertrainController2EM_InitializeVarDimsAddr
( jcaapsdo3t -> DataMapInfo . vardimsAddress ) ; rtwCAPI_SetVarDimsAddressMap
( jcaapsdo3t -> DataMapInfo . mmi , jcaapsdo3t -> DataMapInfo .
vardimsAddress ) ; rtwCAPI_SetPath ( jcaapsdo3t -> DataMapInfo . mmi , ( NULL
) ) ; rtwCAPI_SetFullPath ( jcaapsdo3t -> DataMapInfo . mmi , ( NULL ) ) ;
EvPowertrainController2EM_InitializeLoggingFunctions ( jcaapsdo3t ->
DataMapInfo . loggingPtrs ) ; rtwCAPI_SetLoggingPtrs ( jcaapsdo3t ->
DataMapInfo . mmi , jcaapsdo3t -> DataMapInfo . loggingPtrs ) ;
rtwCAPI_SetInstanceLoggingInfo ( jcaapsdo3t -> DataMapInfo . mmi , &
jcaapsdo3t -> DataMapInfo . mmiLogInstanceInfo ) ; rtwCAPI_SetChildMMIArray (
jcaapsdo3t -> DataMapInfo . mmi , ( NULL ) ) ; rtwCAPI_SetChildMMIArrayLen (
jcaapsdo3t -> DataMapInfo . mmi , 0 ) ;
EvPowertrainController2EM_InitializeSystemRan ( jcaapsdo3t , jcaapsdo3t ->
DataMapInfo . systemRan , localDW , jcaapsdo3t -> DataMapInfo . systemTid ,
sysRanPtr , contextTid ) ; rtwCAPI_SetSystemRan ( jcaapsdo3t -> DataMapInfo .
mmi , jcaapsdo3t -> DataMapInfo . systemRan ) ; rtwCAPI_SetSystemTid (
jcaapsdo3t -> DataMapInfo . mmi , jcaapsdo3t -> DataMapInfo . systemTid ) ;
rtwCAPI_SetGlobalTIDMap ( jcaapsdo3t -> DataMapInfo . mmi , & jcaapsdo3t ->
Timing . mdlref_GlobalTID [ 0 ] ) ; }
#else
#ifdef __cplusplus
extern "C" {
#endif
void EvPowertrainController2EM_host_InitializeDataMapInfo (
EvPowertrainController2EM_host_DataMapInfo_T * dataMap , const char * path )
{ rtwCAPI_SetVersion ( dataMap -> mmi , 1 ) ; rtwCAPI_SetStaticMap ( dataMap
-> mmi , & mmiStatic ) ; rtwCAPI_SetDataAddressMap ( dataMap -> mmi , ( NULL
) ) ; rtwCAPI_SetVarDimsAddressMap ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetPath ( dataMap -> mmi , path ) ; rtwCAPI_SetFullPath ( dataMap ->
mmi , ( NULL ) ) ; rtwCAPI_SetChildMMIArray ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( dataMap -> mmi , 0 ) ; }
#ifdef __cplusplus
}
#endif
#endif
