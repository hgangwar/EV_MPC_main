#ifndef RTW_HEADER_BMSOut_private_h_
#define RTW_HEADER_BMSOut_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "rtw_modelmap_simtarget.h"
#include "BMSOut_types.h"
#include "simtarget/slMdlrefSimTargetCoreHeaders.h"
#include "simtarget/slMdlrefSimTargetInstrumentationHeaders.h"
#include "messages/slMessagesSfcnBridge.h"
#include "sl_fileio_rtw.h"
extern const char_T * rt_GetMatSignalLoggingFileName ( void ) ; extern const
char_T * rt_GetMatSigLogSelectorFileName ( void ) ; extern void *
rt_GetOSigstreamManager ( void ) ; extern void * *
rt_GetOSigstreamManagerAddr ( void ) ; extern void * rt_slioCatalogue ( void
) ; extern void * * rt_slioCatalogueAddr ( void ) ; extern void
rt_ssSet_slErrMsg ( void * S , void * diag ) ; extern void
rt_ssReportDiagnosticAsWarning ( void * S , void * diag ) ; extern void
rt_ssReportDiagnosticAsInfo ( void * S , void * diag ) ; extern const char_T
* rt_CreateFullPathToTop ( const char_T * toppath , const char_T * subpath )
; extern boolean_T slIsRapidAcceleratorSimulating ( void ) ; extern void
rt_RAccelReplaceFromFilename ( const char_T * blockpath , char_T * fileNam )
; extern void rt_RAccelReplaceToFilename ( const char_T * blockpath , char_T
* fileNam ) ; extern void slsaCacheDWorkPointerForSimTargetOP ( void * ss ,
void * * ptr ) ; extern void slsaCacheDWorkDataForSimTargetOP ( void * ss ,
void * ptr , unsigned int sizeInBytes ) ; extern void
slsaSaveRawMemoryForSimTargetOP ( void * ss , const char_T * key , void * *
ptr , unsigned int sizeInBytes , void * ( * customOPSaveFcn ) ( void *
dworkPtr , unsigned int * sizeInBytes ) , void ( * customOPRestoreFcn ) (
void * dworkPtr , const void * data , unsigned int sizeInBytes ) ) ; extern
void * gblLoggingInterval ;
#ifndef rtmCancelTimerToRaiseEvent
#define rtmCancelTimerToRaiseEvent(rtm, timerIndex) simTgtCancelTimerToRaiseEvent(_ssGetRootSS((rtm)->_mdlRefSfcnS), [timerIndex])
#endif
#ifndef rtmDisableTaskUsingRateIndex
#define rtmDisableTaskUsingRateIndex(rtm, sti) simTgtDisableTaskUsingRateIndex(_ssGetRootSS((rtm)->_mdlRefSfcnS), hhvz4om4xd[sti])
#endif
#ifndef rtmEnableTaskUsingRateIndex
#define rtmEnableTaskUsingRateIndex(rtm, sti) simTgtEnableTaskUsingRateIndex(_ssGetRootSS((rtm)->_mdlRefSfcnS), hhvz4om4xd[sti])
#endif
#ifndef rtmIsFirstInitCond
#define rtmIsFirstInitCond(rtm) ssIsFirstInitCond((rtm)->_mdlRefSfcnS)
#endif
#ifndef rtmIsMajorTimeStep
#define rtmIsMajorTimeStep(rtm) ssIsMajorTimeStep((rtm)->_mdlRefSfcnS)
#endif
#ifndef rtmIsMinorTimeStep
#define rtmIsMinorTimeStep(rtm) ssIsMinorTimeStep((rtm)->_mdlRefSfcnS)
#endif
#ifndef rtmRaiseEvent
#define rtmRaiseEvent(rtm, runtimeEventIndex) simTgtRaiseEvent(_ssGetRootSS((rtm)->_mdlRefSfcnS), [runtimeEventIndex])
#endif
#ifndef rtmRaiseEventWithEnqueue
#define rtmRaiseEventWithEnqueue(rtm, runtimeEventIndex) simTgtRaiseEventWithEnqueue(_ssGetRootSS((rtm)->_mdlRefSfcnS), [runtimeEventIndex])
#endif
#ifndef rtmRaiseWhenTimerExpiresAfter
#define rtmRaiseWhenTimerExpiresAfter(rtm, timerIndex, isRecurring, afterDur, runtimeEventIndex) simTgtRaiseWhenTimerExpiresAfter(_ssGetRootSS((rtm)->_mdlRefSfcnS), [timerIndex], isRecurring, afterDur, [runtimeEventIndex])
#endif
#ifndef rtmRaiseWhenTimerExpiresAt
#define rtmRaiseWhenTimerExpiresAt(rtm, timerIndex, atT, runtimeEventIndex) simTgtRaiseWhenTimerExpiresAt(_ssGetRootSS((rtm)->_mdlRefSfcnS), [timerIndex], atT, [runtimeEventIndex])
#endif
#ifndef rtmIsSpecialSampleHit
#define rtmIsSpecialSampleHit(rtm, sti, prom_sti, tid) ssIsSpecialSampleHit( _ssGetRootSS((rtm)->_mdlRefSfcnS), hhvz4om4xd[sti], hhvz4om4xd[prom_sti], tid)
#endif
struct nvcht4hdfj { struct SimStruct_tag * _mdlRefSfcnS ; struct {
rtwCAPI_ModelMappingInfo mmi ; rtwCAPI_ModelMapLoggingInstanceInfo
mmiLogInstanceInfo ; sysRanDType * systemRan [ 2 ] ; int_T systemTid [ 2 ] ;
} DataMapInfo ; } ;
#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm) ((rtm)->DataMapInfo)
#endif
#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val) ((rtm)->DataMapInfo = (val))
#endif
#ifndef rtmGetClockTick0
#define rtmGetClockTick0(rtm) ssGetClockTick( _ssGetRootSS((rtm)->_mdlRefSfcnS), hhvz4om4xd[0])
#endif
#ifndef rtmGetClockTick1
#define rtmGetClockTick1(rtm) ssGetClockTick( _ssGetRootSS((rtm)->_mdlRefSfcnS), hhvz4om4xd[1])
#endif
#ifndef rtmGetClockTickH0
#define rtmGetClockTickH0(rtm) ssGetClockTickH( _ssGetRootSS((rtm)->_mdlRefSfcnS), hhvz4om4xd[0])
#endif
#ifndef rtmGetClockTickH1
#define rtmGetClockTickH1(rtm) ssGetClockTickH( _ssGetRootSS((rtm)->_mdlRefSfcnS), hhvz4om4xd[1])
#endif
#ifndef rtmGetLogOutput
#define rtmGetLogOutput(rtm) ssGetLogOutput((rtm)->_mdlRefSfcnS)
#endif
#ifndef rtmSetSampleHit
#define rtmSetSampleHit(rtm, sti, tid, val) _ssSetSampleHit(_ssGetRootSS((rtm)->_mdlRefSfcnS), hhvz4om4xd[sti], val)
#endif
#ifndef rtmIsSampleHit
#define rtmIsSampleHit(rtm, sti, tid) ssIsSampleHit( _ssGetRootSS((rtm)->_mdlRefSfcnS), hhvz4om4xd[sti], tid)
#endif
#ifndef rtmGetT
#define rtmGetT(rtm) (ssGetT((rtm)->_mdlRefSfcnS))
#endif
#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm) (ssGetTFinal((rtm)->_mdlRefSfcnS))
#endif
#ifndef rtmGetTNextWasAdjusted
#define rtmGetTNextWasAdjusted(rtm, sti) (ssGetTNextWasAdjusted((rtm)->_mdlRefSfcnS,  hhvz4om4xd[sti]))
#endif
#ifndef rtmGetTStart
#define rtmGetTStart(rtm) (ssGetTStart((rtm)->_mdlRefSfcnS))
#endif
#ifndef rtmGetTaskTime
#define rtmGetTaskTime(rtm, sti) ssGetTaskTime( _ssGetRootSS((rtm)->_mdlRefSfcnS), hhvz4om4xd[sti])
#endif
#ifndef rtmSetTaskTime
#define rtmSetTaskTime(rtm, sti, val) _ssSetTaskTime(_ssGetRootSS((rtm)->_mdlRefSfcnS), hhvz4om4xd[sti], val)
#endif
#ifndef rtmGetTimeOfLastOutput
#define rtmGetTimeOfLastOutput(rtm) (ssGetTimeOfLastOutput((rtm)->_mdlRefSfcnS))
#endif
#ifndef rtmGetVarNextHitTime
#define rtmGetVarNextHitTime(rtm, sti) (_ssGetVarNextHitTime((rtm)->_mdlRefSfcnS,  (int)(ssGetOffsetTime(_ssGetRootSS((rtm)->_mdlRefSfcnS), hhvz4om4xd[sti+2]))))
#endif
#ifndef rtmSetVarNextHitTime
#define rtmSetVarNextHitTime(rtm, sti, val) ssSetTimeOfNextVarHit((rtm)->_mdlRefSfcnS,  hhvz4om4xd[sti], val)
#endif
typedef struct { oq5eurmbom rtm ; } pcu03dvoe3p ; extern int_T hhvz4om4xd [ 2
] ; extern pcu03dvoe3p pcu03dvoe3 ;
#endif
