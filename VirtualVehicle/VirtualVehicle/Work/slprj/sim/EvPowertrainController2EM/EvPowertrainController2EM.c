#include "EvPowertrainController2EM.h"
#include "rtwtypes.h"
#include "EvPowertrainController2EM_private.h"
#include "mwmathutil.h"
#include <emmintrin.h>
#include "minimum_hZ1kyuym.h"
#include <string.h>
#include "EvPowertrainController2EM_capi.h"
#include "look1_binlcapw.h"
#include "plook_bincpa.h"
#include "intrp2d_la_pw.h"
#include "look1_pbinlcapw.h"
#include "rt_nonfinite.h"
#define eiwqcockbc (0.0005)
static RegMdlInfo rtMdlInfo_EvPowertrainController2EM [ 45 ] = { {
"oaq0dqotmrc" , MDL_INFO_NAME_MDLREF_DWORK , 0 , - 1 , ( void * )
"EvPowertrainController2EM" } , { "d22elv45sz" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"EvPowertrainController2EM" } , { "cf2jbuujei" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"EvPowertrainController2EM" } , { "imxvkaamrn" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"EvPowertrainController2EM" } , { "mqfccoe4mr" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"EvPowertrainController2EM" } , { "aafhhvk4fd" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"EvPowertrainController2EM" } , { "dakpmricvu" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"EvPowertrainController2EM" } , { "cmkwqqszqu" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"EvPowertrainController2EM" } , { "o5eh0yjn15" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"EvPowertrainController2EM" } , { "p24s0hi0ib" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"EvPowertrainController2EM" } , { "hitypd5sqf" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"EvPowertrainController2EM" } , { "pr35qox4vo" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"EvPowertrainController2EM" } , { "cpxpfpdja3" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"EvPowertrainController2EM" } , { "bwwdwvebxa" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"EvPowertrainController2EM" } , { "c1a2ev3yvr" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"EvPowertrainController2EM" } , { "dfeuqru533" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"EvPowertrainController2EM" } , { "g0tpyzslmq" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"EvPowertrainController2EM" } , { "e3ptmay5nu" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"EvPowertrainController2EM" } , { "pbpffdp5dj" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"EvPowertrainController2EM" } , { "cqealxsqr5" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"EvPowertrainController2EM" } , { "d443wer2uj" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"EvPowertrainController2EM" } , { "g3ndjszvz2" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"EvPowertrainController2EM" } , { "iihvuu1gpc" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"EvPowertrainController2EM" } , { "EvPowertrainController2EM" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , 0 , ( NULL ) } , { "lfqanzh3hu" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"EvPowertrainController2EM" } , { "jcdbqlaivn" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"EvPowertrainController2EM" } , { "nwcwzcnldx" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"EvPowertrainController2EM" } , { "cufix8_En1" , MDL_INFO_ID_CMPLX_DATA_TYPE
, 0 , - 1 , ( void * ) "ufix8_En1" } , { "ufix8_En1" , MDL_INFO_ID_DATA_TYPE
, 0 , - 1 , ( NULL ) } , { "cufix32_En8" , MDL_INFO_ID_CMPLX_DATA_TYPE , 0 ,
- 1 , ( void * ) "ufix32_En8" } , { "ufix32_En8" , MDL_INFO_ID_DATA_TYPE , 0
, - 1 , ( NULL ) } , {
"mr_EvPowertrainController2EM_GetSimStateDisallowedBlocks" ,
MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * ) "EvPowertrainController2EM"
} , { "mr_EvPowertrainController2EM_extractBitFieldFromCellArrayWithOffset" ,
MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * ) "EvPowertrainController2EM"
} , { "mr_EvPowertrainController2EM_cacheBitFieldToCellArrayWithOffset" ,
MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * ) "EvPowertrainController2EM"
} , { "mr_EvPowertrainController2EM_restoreDataFromMxArrayWithOffset" ,
MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * ) "EvPowertrainController2EM"
} , { "mr_EvPowertrainController2EM_cacheDataToMxArrayWithOffset" ,
MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * ) "EvPowertrainController2EM"
} , { "mr_EvPowertrainController2EM_extractBitFieldFromMxArray" ,
MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * ) "EvPowertrainController2EM"
} , { "mr_EvPowertrainController2EM_cacheBitFieldToMxArray" ,
MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * ) "EvPowertrainController2EM"
} , { "mr_EvPowertrainController2EM_restoreDataFromMxArray" ,
MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * ) "EvPowertrainController2EM"
} , { "mr_EvPowertrainController2EM_cacheDataAsMxArray" ,
MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * ) "EvPowertrainController2EM"
} , { "mr_EvPowertrainController2EM_RegisterSimStateChecksum" ,
MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * ) "EvPowertrainController2EM"
} , { "mr_EvPowertrainController2EM_SetDWork" , MDL_INFO_ID_MODEL_FCN_NAME ,
0 , - 1 , ( void * ) "EvPowertrainController2EM" } , {
"mr_EvPowertrainController2EM_GetDWork" , MDL_INFO_ID_MODEL_FCN_NAME , 0 , -
1 , ( void * ) "EvPowertrainController2EM" } , {
"EvPowertrainController2EM.h" , MDL_INFO_MODEL_FILENAME , 0 , - 1 , ( NULL )
} , { "EvPowertrainController2EM.c" , MDL_INFO_MODEL_FILENAME , 0 , - 1 , (
void * ) "EvPowertrainController2EM" } } ; jtbbqdj1ooz jtbbqdj1oo = { 0.01 ,
0.01 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 1.0 , - 1.0 , 0.0 , 1.0 , - 1.0 , 0.0 ,
- 1.0 , 0.0 , 1.0 , { 0.0 , 2.2613065326633164 , 4.5226130653266328 ,
6.78391959798995 , 9.0452261306532655 , 11.306532663316583 , 13.5678391959799
, 15.829145728643216 , 18.090452261306531 , 20.35175879396985 ,
22.613065326633166 , 24.874371859296481 , 27.1356783919598 ,
29.396984924623116 , 31.658291457286431 , 33.91959798994975 ,
36.180904522613062 , 38.442211055276381 , 40.7035175879397 ,
42.964824120603012 , 45.226130653266331 , 47.48743718592965 ,
49.748743718592962 , 52.010050251256281 , 54.2713567839196 ,
56.532663316582912 , 58.793969849246231 , 61.05527638190955 ,
63.316582914572862 , 65.577889447236174 , 67.8391959798995 ,
70.100502512562812 , 72.361809045226124 , 74.62311557788945 ,
76.884422110552762 , 79.145728643216074 , 81.4070351758794 ,
83.668341708542712 , 85.929648241206024 , 88.19095477386935 ,
90.452261306532662 , 92.713567839195974 , 94.9748743718593 ,
97.236180904522612 , 99.497487437185924 , 101.75879396984925 ,
104.02010050251256 , 106.28140703517587 , 108.5427135678392 ,
110.80402010050251 , 113.06532663316582 , 115.32663316582915 ,
117.58793969849246 , 119.84924623115577 , 122.1105527638191 ,
124.37185929648241 , 126.63316582914572 , 128.89447236180905 ,
131.15577889447235 , 133.41708542713567 , 135.678391959799 ,
137.9396984924623 , 140.20100502512562 , 142.46231155778895 ,
144.72361809045225 , 146.98492462311557 , 149.2462311557789 ,
151.5075376884422 , 153.76884422110552 , 156.03015075376885 ,
158.29145728643215 , 160.55276381909547 , 162.8140703517588 ,
165.0753768844221 , 167.33668341708542 , 169.59798994974875 ,
171.85929648241205 , 174.12060301507537 , 176.3819095477387 ,
178.643216080402 , 180.90452261306532 , 183.16582914572865 ,
185.42713567839195 , 187.68844221105527 , 189.9497487437186 ,
192.2110552763819 , 194.47236180904522 , 196.73366834170855 ,
198.99497487437185 , 201.25628140703517 , 203.5175879396985 ,
205.7788944723618 , 208.04020100502512 , 210.30150753768845 ,
212.56281407035175 , 214.82412060301507 , 217.0854271356784 ,
219.3467336683417 , 221.60804020100502 , 223.86934673366835 ,
226.13065326633165 , 228.39195979899498 , 230.6532663316583 ,
232.9145728643216 , 235.17587939698493 , 237.43718592964825 ,
239.69849246231155 , 241.95979899497488 , 244.2211055276382 ,
246.4824120603015 , 248.74371859296483 , 251.00502512562815 ,
253.26633165829145 , 255.52763819095478 , 257.7889447236181 ,
260.0502512562814 , 262.3115577889447 , 264.57286432160805 ,
266.83417085427135 , 269.09547738693465 , 271.356783919598 ,
273.6180904522613 , 275.8793969849246 , 278.14070351758795 ,
280.40201005025125 , 282.66331658291455 , 284.9246231155779 ,
287.1859296482412 , 289.4472361809045 , 291.70854271356785 ,
293.96984924623115 , 296.23115577889445 , 298.4924623115578 ,
300.7537688442211 , 303.0150753768844 , 305.27638190954775 ,
307.53768844221105 , 309.79899497487435 , 312.0603015075377 ,
314.321608040201 , 316.5829145728643 , 318.84422110552765 ,
321.10552763819095 , 323.36683417085425 , 325.6281407035176 ,
327.8894472361809 , 330.1507537688442 , 332.41206030150755 ,
334.67336683417085 , 336.93467336683415 , 339.1959798994975 ,
341.4572864321608 , 343.7185929648241 , 345.97989949748745 ,
348.24120603015075 , 350.50251256281405 , 352.7638190954774 ,
355.0251256281407 , 357.286432160804 , 359.54773869346735 ,
361.80904522613065 , 364.07035175879395 , 366.3316582914573 ,
368.5929648241206 , 370.8542713567839 , 373.11557788944725 ,
375.37688442211055 , 377.63819095477385 , 379.8994974874372 ,
382.1608040201005 , 384.4221105527638 , 386.68341708542715 ,
388.94472361809045 , 391.20603015075375 , 393.4673366834171 ,
395.7286432160804 , 397.9899497487437 , 400.25125628140705 ,
402.51256281407035 , 404.77386934673365 , 407.035175879397 ,
409.2964824120603 , 411.5577889447236 , 413.81909547738695 ,
416.08040201005025 , 418.34170854271355 , 420.6030150753769 ,
422.8643216080402 , 425.1256281407035 , 427.38693467336685 ,
429.64824120603015 , 431.90954773869345 , 434.1708542713568 ,
436.4321608040201 , 438.6934673366834 , 440.95477386934675 ,
443.21608040201005 , 445.47738693467335 , 447.7386934673367 , 450.0 } , - 1.0
, 0.0 , - 1.0 , 0.0 , 1.0 , { 0.0 , 2.2613065326633164 , 4.5226130653266328 ,
6.78391959798995 , 9.0452261306532655 , 11.306532663316583 , 13.5678391959799
, 15.829145728643216 , 18.090452261306531 , 20.35175879396985 ,
22.613065326633166 , 24.874371859296481 , 27.1356783919598 ,
29.396984924623116 , 31.658291457286431 , 33.91959798994975 ,
36.180904522613062 , 38.442211055276381 , 40.7035175879397 ,
42.964824120603012 , 45.226130653266331 , 47.48743718592965 ,
49.748743718592962 , 52.010050251256281 , 54.2713567839196 ,
56.532663316582912 , 58.793969849246231 , 61.05527638190955 ,
63.316582914572862 , 65.577889447236174 , 67.8391959798995 ,
70.100502512562812 , 72.361809045226124 , 74.62311557788945 ,
76.884422110552762 , 79.145728643216074 , 81.4070351758794 ,
83.668341708542712 , 85.929648241206024 , 88.19095477386935 ,
90.452261306532662 , 92.713567839195974 , 94.9748743718593 ,
97.236180904522612 , 99.497487437185924 , 101.75879396984925 ,
104.02010050251256 , 106.28140703517587 , 108.5427135678392 ,
110.80402010050251 , 113.06532663316582 , 115.32663316582915 ,
117.58793969849246 , 119.84924623115577 , 122.1105527638191 ,
124.37185929648241 , 126.63316582914572 , 128.89447236180905 ,
131.15577889447235 , 133.41708542713567 , 135.678391959799 ,
137.9396984924623 , 140.20100502512562 , 142.46231155778895 ,
144.72361809045225 , 146.98492462311557 , 149.2462311557789 ,
151.5075376884422 , 153.76884422110552 , 156.03015075376885 ,
158.29145728643215 , 160.55276381909547 , 162.8140703517588 ,
165.0753768844221 , 167.33668341708542 , 169.59798994974875 ,
171.85929648241205 , 174.12060301507537 , 176.3819095477387 ,
178.643216080402 , 180.90452261306532 , 183.16582914572865 ,
185.42713567839195 , 187.68844221105527 , 189.9497487437186 ,
192.2110552763819 , 194.47236180904522 , 196.73366834170855 ,
198.99497487437185 , 201.25628140703517 , 203.5175879396985 ,
205.7788944723618 , 208.04020100502512 , 210.30150753768845 ,
212.56281407035175 , 214.82412060301507 , 217.0854271356784 ,
219.3467336683417 , 221.60804020100502 , 223.86934673366835 ,
226.13065326633165 , 228.39195979899498 , 230.6532663316583 ,
232.9145728643216 , 235.17587939698493 , 237.43718592964825 ,
239.69849246231155 , 241.95979899497488 , 244.2211055276382 ,
246.4824120603015 , 248.74371859296483 , 251.00502512562815 ,
253.26633165829145 , 255.52763819095478 , 257.7889447236181 ,
260.0502512562814 , 262.3115577889447 , 264.57286432160805 ,
266.83417085427135 , 269.09547738693465 , 271.356783919598 ,
273.6180904522613 , 275.8793969849246 , 278.14070351758795 ,
280.40201005025125 , 282.66331658291455 , 284.9246231155779 ,
287.1859296482412 , 289.4472361809045 , 291.70854271356785 ,
293.96984924623115 , 296.23115577889445 , 298.4924623115578 ,
300.7537688442211 , 303.0150753768844 , 305.27638190954775 ,
307.53768844221105 , 309.79899497487435 , 312.0603015075377 ,
314.321608040201 , 316.5829145728643 , 318.84422110552765 ,
321.10552763819095 , 323.36683417085425 , 325.6281407035176 ,
327.8894472361809 , 330.1507537688442 , 332.41206030150755 ,
334.67336683417085 , 336.93467336683415 , 339.1959798994975 ,
341.4572864321608 , 343.7185929648241 , 345.97989949748745 ,
348.24120603015075 , 350.50251256281405 , 352.7638190954774 ,
355.0251256281407 , 357.286432160804 , 359.54773869346735 ,
361.80904522613065 , 364.07035175879395 , 366.3316582914573 ,
368.5929648241206 , 370.8542713567839 , 373.11557788944725 ,
375.37688442211055 , 377.63819095477385 , 379.8994974874372 ,
382.1608040201005 , 384.4221105527638 , 386.68341708542715 ,
388.94472361809045 , 391.20603015075375 , 393.4673366834171 ,
395.7286432160804 , 397.9899497487437 , 400.25125628140705 ,
402.51256281407035 , 404.77386934673365 , 407.035175879397 ,
409.2964824120603 , 411.5577889447236 , 413.81909547738695 ,
416.08040201005025 , 418.34170854271355 , 420.6030150753769 ,
422.8643216080402 , 425.1256281407035 , 427.38693467336685 ,
429.64824120603015 , 431.90954773869345 , 434.1708542713568 ,
436.4321608040201 , 438.6934673366834 , 440.95477386934675 ,
443.21608040201005 , 445.47738693467335 , 447.7386934673367 , 450.0 } , - 1.0
, 0.0 , - 1.0 , 0.0 , 0.0 , 1.0 , 0.0 , - 1.0 , 0.0 , 1.0 , 0.8 , 0.9 , 0.0 ,
0.0 , 0.0 , 0.0 , - 1.5 , - 1.0 , 0.8 , 0.9 , 0.0 , - 1.0 , 0.01 , - 1.0 ,
1.0 , 0.0 , 1.0 , 0.0 , - 1.0 , 0.0 , 1.0 , 0.8 , 0.9 , 0.0 , 0.0 , - 1.5 , -
1.0 , 0.8 , 0.9 , 0.0 , - 1.0 , 0.01 , - 1.0 , 1.0 , 0.0 , 0.0 , 0.0001 , 0.0
, 0.001 , 0.0 , 0.001 , 0.001 , 25.0 , 0.0 , - 0.1 , 0.1 , 0.0 , 0.0 , 0.0 ,
0.001 , { 25.0 , 25.0 , 100.0 } , { 0.0 , 0.8 , 1.0 } , 0.0 , 0.0 , 0.0 , 0.0
, 1.0 , 0.0 , 1.0 , 0.0 , - 1.0 , 0.0 , 1.0 , 0.0 , - 1.0 , 0.0 , 0.0 , 1.0 ,
1.0 , 0.0 , 1.0 , - 1.0 , 0.0 , 1.0 , - 1.0 , 0.0 , - 1.0 , - 1.0 , 100.0 ,
500.0 , - 500.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 2560000000U , { 13U , 10U } ,
{ 13U , 10U } , 200U , 200U } ; void iihvuu1gpc ( nwcwzcnldx * const
jcaapsdo3t , cpxpfpdja3 * localDW ) { if ( ( ssGetSimMode ( jcaapsdo3t ->
_mdlRefSfcnS ) != SS_SIMMODE_EXTERNAL ) && ( ( jcaapsdo3t -> _mdlRefSfcnS )
-> mdlInfo -> rtwgenMode != SS_RTWGEN_MODELREFERENCE_RTW_TARGET ) ) { { if (
slIsRapidAcceleratorSimulating ( ) || ( ssGetSimMode ( jcaapsdo3t ->
_mdlRefSfcnS ) == SS_SIMMODE_NORMAL ) || ssRTWGenIsAccelerator ( jcaapsdo3t
-> _mdlRefSfcnS ) ) { bool isStreamoutAlreadyRegistered = false ; {
sdiSignalSourceInfoU srcInfo ; sdiLabelU loggedName = sdiGetLabelFromChars (
"Subtract" ) ; sdiLabelU origSigName = sdiGetLabelFromChars ( "" ) ;
sdiLabelU propName = sdiGetLabelFromChars ( "Subtract" ) ; sdiLabelU
blockPath = sdiGetLabelFromChars (
"EvPowertrainController2EM/Energy Management/To Workspace" ) ; sdiLabelU
blockSID = sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath =
sdiGetLabelFromChars ( "" ) ; sdiDims sigDims ; sdiDims forEachMdlRefDims ;
int_T forEachMdlRefDimsArray [ 32 ] ; sdiLabelU sigName =
sdiGetLabelFromChars ( "Subtract" ) ; sdiAsyncQueueHandle hForEachParent = (
NULL ) ; sdiAsyncRepoDataTypeHandle hDT =
sdiAsyncRepoGetBuiltInDataTypeHandle ( DATA_TYPE_DOUBLE ) ; { sdiComplexity
sigComplexity = REAL ; sdiSampleTimeContinuity stCont =
SAMPLE_TIME_CONTINUOUS ; int_T sigDimsArray [ 1 ] = { 1 } ; sigDims . nDims =
1 ; sigDims . dimensions = sigDimsArray ; srcInfo . numBlockPathElems = 1 ;
srcInfo . fullBlockPath = ( sdiFullBlkPathU ) & blockPath ; srcInfo . SID = (
sdiSignalIDU ) & blockSID ; srcInfo . subPath = subPath ; srcInfo . portIndex
= 0 + 1 ; srcInfo . signalName = sigName ; srcInfo . sigSourceUUID = 0 ; if (
slIsRapidAcceleratorSimulating ( ) ) { forEachMdlRefDims . nDims = 0 ; } else
{ forEachMdlRefDims . nDims = slSigLogGetForEachDimsForRefModel ( jcaapsdo3t
-> _mdlRefSfcnS , forEachMdlRefDimsArray ) ; forEachMdlRefDims . dimensions =
forEachMdlRefDimsArray ; } if ( forEachMdlRefDims . nDims > 0 ) {
hForEachParent = sdiCreateForEachParent ( & srcInfo , jcaapsdo3t ->
DataMapInfo . mmi . InstanceMap . fullPath , ( NULL ) , loggedName ,
origSigName , propName , & forEachMdlRefDims ) ; sdiUpdateForEachLeafName ( &
srcInfo , hForEachParent ) ; { sdiLabelU varName = sdiGetLabelFromChars (
"simout" ) ; sdiRegisterWksVariable ( hForEachParent , varName , "timeseries"
) ; sdiFreeLabel ( varName ) ; } sdiAsyncRepoSetBlockPathDomain (
hForEachParent ) ; isStreamoutAlreadyRegistered = true ; } localDW ->
j0c0jhtxz1 . AQHandles = sdiStartAsyncioQueueCreation ( hDT , & srcInfo ,
jcaapsdo3t -> DataMapInfo . mmi . InstanceMap . fullPath ,
"ae40cb9d-e601-4495-b787-c93fa69d70ca" , sigComplexity , & sigDims ,
DIMENSIONS_MODE_FIXED , stCont , "" ) ; sdiCompleteAsyncioQueueCreation (
localDW -> j0c0jhtxz1 . AQHandles , hDT , & srcInfo ) ; if ( localDW ->
j0c0jhtxz1 . AQHandles ) { sdiSetSignalSampleTimeString ( localDW ->
j0c0jhtxz1 . AQHandles , "Continuous" , 0.0 , rtmGetTFinal ( jcaapsdo3t ) ) ;
sdiSetSignalRefRate ( localDW -> j0c0jhtxz1 . AQHandles , 0.0 ) ;
sdiSetRunStartTime ( localDW -> j0c0jhtxz1 . AQHandles , rtmGetTaskTime (
jcaapsdo3t , 0 ) ) ; sdiAsyncRepoSetSignalExportSettings ( localDW ->
j0c0jhtxz1 . AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName ( localDW
-> j0c0jhtxz1 . AQHandles , loggedName , origSigName , propName ) ;
sdiAsyncRepoSetBlockPathDomain ( localDW -> j0c0jhtxz1 . AQHandles ) ; if (
forEachMdlRefDims . nDims > 0 ) { sdiAttachForEachIterationToParent (
hForEachParent , localDW -> j0c0jhtxz1 . AQHandles , ( NULL ) ) ; if (
srcInfo . signalName != sigName ) { sdiFreeName ( srcInfo . signalName ) ; }
} } sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } if ( !
isStreamoutAlreadyRegistered ) { { sdiLabelU varName = sdiGetLabelFromChars (
"simout" ) ; sdiRegisterWksVariable ( localDW -> j0c0jhtxz1 . AQHandles ,
varName , "timeseries" ) ; sdiFreeLabel ( varName ) ; } } } } } } void
cqealxsqr5 ( real_T * hn2t2tghq3 , real_T * edcjsjvsbf , real_T * dcs1zebgq2
, real_T * megpmqfjrl , real_T * imfqdgtkm2 , cpxpfpdja3 * localDW ) {
int32_T i ; * hn2t2tghq3 = jtbbqdj1oo . P_130 ; localDW -> ns0ekabbmt [ 0 ] =
jtbbqdj1oo . P_142 ; localDW -> ns0ekabbmt [ 1 ] = jtbbqdj1oo . P_142 ; *
edcjsjvsbf = jtbbqdj1oo . P_143 ; * dcs1zebgq2 = jtbbqdj1oo . P_144 ; *
megpmqfjrl = jtbbqdj1oo . P_145 ; * imfqdgtkm2 = jtbbqdj1oo . P_146 ; for ( i
= 0 ; i < 201 ; i ++ ) { localDW -> gimarahrpl [ i ] = jtbbqdj1oo . P_57 ;
localDW -> glinugelel [ i ] = jtbbqdj1oo . P_65 ; localDW -> cg13f1zg3e [ i ]
= jtbbqdj1oo . P_66 ; localDW -> p5p4aaxq51 [ i ] = jtbbqdj1oo . P_78 ; }
localDW -> mnt5i0lw4q = jtbbqdj1oo . P_107 ; localDW -> o5t0xnvnze =
jtbbqdj1oo . P_108 ; localDW -> f12x4t2yjl = jtbbqdj1oo . P_120 ; localDW ->
ow2qkdjqul = jtbbqdj1oo . P_124 ; localDW -> bnr3irkvs1 = jtbbqdj1oo . P_127
; } void pbpffdp5dj ( real_T * hn2t2tghq3 , real_T * edcjsjvsbf , real_T *
dcs1zebgq2 , real_T * megpmqfjrl , real_T * imfqdgtkm2 , cpxpfpdja3 * localDW
) { int32_T i ; * hn2t2tghq3 = jtbbqdj1oo . P_130 ; localDW -> ns0ekabbmt [ 0
] = jtbbqdj1oo . P_142 ; localDW -> ns0ekabbmt [ 1 ] = jtbbqdj1oo . P_142 ; *
edcjsjvsbf = jtbbqdj1oo . P_143 ; * dcs1zebgq2 = jtbbqdj1oo . P_144 ; *
megpmqfjrl = jtbbqdj1oo . P_145 ; * imfqdgtkm2 = jtbbqdj1oo . P_146 ; for ( i
= 0 ; i < 201 ; i ++ ) { localDW -> gimarahrpl [ i ] = jtbbqdj1oo . P_57 ;
localDW -> glinugelel [ i ] = jtbbqdj1oo . P_65 ; localDW -> cg13f1zg3e [ i ]
= jtbbqdj1oo . P_66 ; localDW -> p5p4aaxq51 [ i ] = jtbbqdj1oo . P_78 ; }
localDW -> mnt5i0lw4q = jtbbqdj1oo . P_107 ; localDW -> o5t0xnvnze =
jtbbqdj1oo . P_108 ; localDW -> f12x4t2yjl = jtbbqdj1oo . P_120 ; localDW ->
ow2qkdjqul = jtbbqdj1oo . P_124 ; localDW -> bnr3irkvs1 = jtbbqdj1oo . P_127
; } void g3ndjszvz2 ( real_T * hn2t2tghq3 , real_T * edcjsjvsbf , real_T *
dcs1zebgq2 , real_T * megpmqfjrl , real_T * imfqdgtkm2 ) { * hn2t2tghq3 =
jtbbqdj1oo . P_130 ; * edcjsjvsbf = jtbbqdj1oo . P_143 ; * dcs1zebgq2 =
jtbbqdj1oo . P_144 ; * megpmqfjrl = jtbbqdj1oo . P_145 ; * imfqdgtkm2 =
jtbbqdj1oo . P_146 ; } void EvPowertrainController2EM ( nwcwzcnldx * const
jcaapsdo3t , const real_T * dikvztxmir , const real_T l2omu2n5t0 [ 4 ] ,
const real_T * ppjd0yjs10 , const real_T owziimmlv4 [ 2 ] , const real_T *
jx3m2p4tqq , const real_T * co4rfisdxd , const real_T * moz11gxboh , const
real_T * phebrbtq0p , real_T * hn2t2tghq3 , real_T gvnpst4w0k [ 2 ] , real_T
jg1dpl1t23 [ 4 ] , real_T * edcjsjvsbf , real_T * dcs1zebgq2 , real_T *
megpmqfjrl , real_T * imfqdgtkm2 , bwwdwvebxa * localB , cpxpfpdja3 * localDW
) { __m128d tmp ; __m128d tmp_p ; real_T adnwsv2a13 [ 201 ] ; real_T
fwh1ybwery [ 201 ] ; real_T g0mwm5df5k [ 201 ] ; real_T ikoagaviq4 [ 201 ] ;
real_T muk1vqfd31 [ 201 ] ; real_T fractions [ 2 ] ; real_T fractions_p [ 2 ]
; real_T tmp_e [ 2 ] ; real_T tmp_i [ 2 ] ; real_T akl4jylwt5 ; real_T
ba12yjhnae ; real_T dapypv1qpv ; real_T dhsrkgeanv ; real_T ipjizrw5pk_tmp ;
real_T jqumtuy4e3 ; real_T jvgykmagyc_tmp ; real_T lkw3efwvok ; real_T
lx3tgymwrh_idx_0 ; real_T lx3tgymwrh_idx_1 ; real_T m142e0s54t ; real_T
mweybw2gnb_idx_0 ; real_T mweybw2gnb_idx_1 ; real_T mweybw2gnb_idx_2 ; real_T
mweybw2gnb_idx_3 ; real_T n2fq14epk3 ; real_T prxlczghi0_idx_0 ; real_T
prxlczghi0_idx_1 ; int32_T i ; int32_T tmp_g ; int32_T tmp_m ; uint32_T
bpIndices [ 2 ] ; uint32_T bpIndices_p [ 2 ] ; uint32_T tmp_j ; boolean_T
eoaa5ck4cu [ 201 ] ; boolean_T jzltqxzg4n [ 201 ] ; boolean_T kcw0u0fwkc [
201 ] ; boolean_T exitg1 ; boolean_T gj2wmplzhf ; boolean_T hfvdvqatqv ; if (
rtmIsMajorTimeStep ( jcaapsdo3t ) ) { * hn2t2tghq3 = jtbbqdj1oo . P_130 ;
ipjizrw5pk_tmp = 1.0 / rtP__PlntWhlLdRadius2f2PassVeh_sldd_ * * ppjd0yjs10 ;
jqumtuy4e3 = rtP__PlntDiffrntlRatio2f2Drivetrain_sldd_ * ipjizrw5pk_tmp ;
m142e0s54t = look1_binlcapw ( jqumtuy4e3 ,
rtP__PlntEM1Spd2f2ElectricMachine1_sldd_ ,
rtP__PlntEM1Trq2f2ElectricMachine1_sldd_ , 13U ) ; if ( m142e0s54t *
jqumtuy4e3 >= jtbbqdj1oo . P_133 ) { jqumtuy4e3 = jtbbqdj1oo . P_131 ; } else
{ jqumtuy4e3 = jtbbqdj1oo . P_132 ; } akl4jylwt5 =
rtP__PlntDiffrntl2Ratio2f2Drivetrain_sldd_ * ipjizrw5pk_tmp ; n2fq14epk3 =
look1_binlcapw ( akl4jylwt5 , rtP__PlntEM2Spd2f2ElectricMachine2_sldd_ ,
rtP__PlntEM2Trq2f2ElectricMachine2_sldd_ , 13U ) ; if ( n2fq14epk3 *
akl4jylwt5 >= jtbbqdj1oo . P_136 ) { akl4jylwt5 = jtbbqdj1oo . P_134 ; } else
{ akl4jylwt5 = jtbbqdj1oo . P_135 ; } if ( (
rtP__PlntDiffrntlEff2f2Drivetrain_sldd_ < 0.0 ) && ( jqumtuy4e3 >
muDoubleScalarFloor ( jqumtuy4e3 ) ) ) { dapypv1qpv = - muDoubleScalarPower (
- rtP__PlntDiffrntlEff2f2Drivetrain_sldd_ , jqumtuy4e3 ) ; } else {
dapypv1qpv = muDoubleScalarPower ( rtP__PlntDiffrntlEff2f2Drivetrain_sldd_ ,
jqumtuy4e3 ) ; } if ( ( rtP__PlntDiffrntl2Eff2f2Drivetrain_sldd_ < 0.0 ) && (
akl4jylwt5 > muDoubleScalarFloor ( akl4jylwt5 ) ) ) { prxlczghi0_idx_0 = -
muDoubleScalarPower ( - rtP__PlntDiffrntl2Eff2f2Drivetrain_sldd_ , akl4jylwt5
) ; } else { prxlczghi0_idx_0 = muDoubleScalarPower (
rtP__PlntDiffrntl2Eff2f2Drivetrain_sldd_ , akl4jylwt5 ) ; } akl4jylwt5 = (
rtP__PlntDiffrntlRatio2f2Drivetrain_sldd_ * m142e0s54t * dapypv1qpv +
rtP__PlntDiffrntl2Ratio2f2Drivetrain_sldd_ * n2fq14epk3 * prxlczghi0_idx_0 )
* * dikvztxmir ; mweybw2gnb_idx_0 = rtP__PlntBrkFrntBias2f2PassVeh_sldd_ *
l2omu2n5t0 [ 0 ] ; mweybw2gnb_idx_1 = rtP__PlntBrkFrntBias2f2PassVeh_sldd_ *
l2omu2n5t0 [ 1 ] ; mweybw2gnb_idx_2 = rtP__PlntBrkRearBias2f2PassVeh_sldd_ *
l2omu2n5t0 [ 2 ] ; mweybw2gnb_idx_3 = rtP__PlntBrkRearBias2f2PassVeh_sldd_ *
l2omu2n5t0 [ 3 ] ; mweybw2gnb_idx_0 *= rtP__PlntBrkPrsFctr2f2PassVeh_sldd_ ;
mweybw2gnb_idx_1 *= rtP__PlntBrkPrsFctr2f2PassVeh_sldd_ ; mweybw2gnb_idx_2 *=
rtP__PlntBrkPrsFctr2f2PassVeh_sldd_ ; mweybw2gnb_idx_3 *=
rtP__PlntBrkPrsFctr2f2PassVeh_sldd_ ; m142e0s54t = jtbbqdj1oo . P_137 * *
moz11gxboh ; jqumtuy4e3 = * co4rfisdxd * m142e0s54t ; m142e0s54t = jtbbqdj1oo
. P_138 * * phebrbtq0p ; n2fq14epk3 = * co4rfisdxd * m142e0s54t ; ba12yjhnae
= jtbbqdj1oo . P_139 * * jx3m2p4tqq ; prxlczghi0_idx_0 = owziimmlv4 [ 0 ] ;
prxlczghi0_idx_1 = owziimmlv4 [ 1 ] ; m142e0s54t = look1_binlcapw (
owziimmlv4 [ 0 ] , rtP__PlntEM1Spd2f2ElectricMachine1_sldd_ ,
rtP__PlntEM1Trq2f2ElectricMachine1_sldd_ , 13U ) ; lkw3efwvok = m142e0s54t *
owziimmlv4 [ 0 ] ; if ( lkw3efwvok >= jtbbqdj1oo . P_37 ) { lkw3efwvok =
jtbbqdj1oo . P_35 ; } else { lkw3efwvok = jtbbqdj1oo . P_36 ; } if ( (
rtP__PlntDiffrntlEff2f2Drivetrain_sldd_ < 0.0 ) && ( lkw3efwvok >
muDoubleScalarFloor ( lkw3efwvok ) ) ) { dapypv1qpv = - muDoubleScalarPower (
- rtP__PlntDiffrntlEff2f2Drivetrain_sldd_ , lkw3efwvok ) ; } else {
dapypv1qpv = muDoubleScalarPower ( rtP__PlntDiffrntlEff2f2Drivetrain_sldd_ ,
lkw3efwvok ) ; } lx3tgymwrh_idx_0 = rtP__PlntDiffrntlRatio2f2Drivetrain_sldd_
* m142e0s54t * dapypv1qpv ; m142e0s54t = look1_binlcapw ( owziimmlv4 [ 1 ] ,
rtP__PlntEM2Spd2f2ElectricMachine2_sldd_ ,
rtP__PlntEM2Trq2f2ElectricMachine2_sldd_ , 13U ) ; lkw3efwvok = m142e0s54t *
owziimmlv4 [ 1 ] ; if ( lkw3efwvok >= jtbbqdj1oo . P_40 ) { lkw3efwvok =
jtbbqdj1oo . P_38 ; } else { lkw3efwvok = jtbbqdj1oo . P_39 ; } if ( (
rtP__PlntDiffrntl2Eff2f2Drivetrain_sldd_ < 0.0 ) && ( lkw3efwvok >
muDoubleScalarFloor ( lkw3efwvok ) ) ) { dapypv1qpv = - muDoubleScalarPower (
- rtP__PlntDiffrntl2Eff2f2Drivetrain_sldd_ , lkw3efwvok ) ; } else {
dapypv1qpv = muDoubleScalarPower ( rtP__PlntDiffrntl2Eff2f2Drivetrain_sldd_ ,
lkw3efwvok ) ; } lx3tgymwrh_idx_1 =
rtP__PlntDiffrntl2Ratio2f2Drivetrain_sldd_ * m142e0s54t * dapypv1qpv ;
jvgykmagyc_tmp = rtP__PlntBrkKinFricCffFrnt2f2PassVeh_sldd_ *
3.1415926535897931 * 0.0025000000000000005 *
rtP__PlntBrkPadMeanRadiusFrnt2f2PassVeh_sldd_ *
rtP__PlntBrkNumPadsFrnt2f2PassVeh_sldd_ / 4.0 ; m142e0s54t = ( (
jvgykmagyc_tmp * mweybw2gnb_idx_0 + jvgykmagyc_tmp * mweybw2gnb_idx_1 ) +
jvgykmagyc_tmp * mweybw2gnb_idx_2 ) + jvgykmagyc_tmp * mweybw2gnb_idx_3 ;
lkw3efwvok = look1_binlcapw ( * ppjd0yjs10 ,
rtP__CtrlVcuEvRegenBrkSpdBpt2f2EvVCU_sldd_ ,
rtP__CtrlVcuEvRegenBrkCutOff2f2EvVCU_sldd_ , 1U ) ; if ( * dikvztxmir >
jtbbqdj1oo . P_42 ) { mweybw2gnb_idx_0 = akl4jylwt5 ; } else {
mweybw2gnb_idx_0 = muDoubleScalarMin ( m142e0s54t , lx3tgymwrh_idx_0 +
lx3tgymwrh_idx_1 ) * ( lkw3efwvok * look1_binlcapw ( ba12yjhnae ,
rtP__CtrlVcuEvSocBpt2f2EvVCU_sldd_ , rtP__CtrlVcuEvChrgLmtBpt2f2EvVCU_sldd_ ,
10U ) ) * jtbbqdj1oo . P_41 ; } for ( i = 0 ; i < 200 ; i ++ ) { akl4jylwt5 =
jtbbqdj1oo . P_44 [ i ] ; if ( akl4jylwt5 * prxlczghi0_idx_1 >= jtbbqdj1oo .
P_46 ) { dapypv1qpv = jtbbqdj1oo . P_43 ; } else { dapypv1qpv = jtbbqdj1oo .
P_45 ; } if ( ( rtP__PlntDiffrntl2Eff2f2Drivetrain_sldd_ < 0.0 ) && (
dapypv1qpv > muDoubleScalarFloor ( dapypv1qpv ) ) ) { dapypv1qpv = -
muDoubleScalarPower ( - rtP__PlntDiffrntl2Eff2f2Drivetrain_sldd_ , dapypv1qpv
) ; } else { dapypv1qpv = muDoubleScalarPower (
rtP__PlntDiffrntl2Eff2f2Drivetrain_sldd_ , dapypv1qpv ) ; } if ( * dikvztxmir
> jtbbqdj1oo . P_48 ) { g0mwm5df5k [ i + 1 ] =
rtP__PlntDiffrntl2Ratio2f2Drivetrain_sldd_ * akl4jylwt5 * dapypv1qpv ; } else
{ g0mwm5df5k [ i + 1 ] = rtP__PlntDiffrntl2Ratio2f2Drivetrain_sldd_ *
akl4jylwt5 * dapypv1qpv * jtbbqdj1oo . P_47 ; } akl4jylwt5 = jtbbqdj1oo .
P_50 [ i ] ; if ( akl4jylwt5 * prxlczghi0_idx_0 >= jtbbqdj1oo . P_52 ) {
dapypv1qpv = jtbbqdj1oo . P_49 ; } else { dapypv1qpv = jtbbqdj1oo . P_51 ; }
if ( ( rtP__PlntDiffrntlEff2f2Drivetrain_sldd_ < 0.0 ) && ( dapypv1qpv >
muDoubleScalarFloor ( dapypv1qpv ) ) ) { dapypv1qpv = - muDoubleScalarPower (
- rtP__PlntDiffrntlEff2f2Drivetrain_sldd_ , dapypv1qpv ) ; } else {
dapypv1qpv = muDoubleScalarPower ( rtP__PlntDiffrntlEff2f2Drivetrain_sldd_ ,
dapypv1qpv ) ; } if ( * dikvztxmir > jtbbqdj1oo . P_54 ) { fwh1ybwery [ i + 1
] = rtP__PlntDiffrntlRatio2f2Drivetrain_sldd_ * akl4jylwt5 * dapypv1qpv ; }
else { fwh1ybwery [ i + 1 ] = rtP__PlntDiffrntlRatio2f2Drivetrain_sldd_ *
akl4jylwt5 * dapypv1qpv * jtbbqdj1oo . P_53 ; } } fwh1ybwery [ 0 ] =
mweybw2gnb_idx_0 ; g0mwm5df5k [ 0 ] = mweybw2gnb_idx_0 ; if ( * co4rfisdxd >=
jtbbqdj1oo . P_55 ) { akl4jylwt5 = jtbbqdj1oo . P_129 ; } else { akl4jylwt5 =
localB -> jovi3oh0hw ; } mweybw2gnb_idx_1 = * co4rfisdxd / 0.01 ; hfvdvqatqv
= ( * co4rfisdxd >= - jtbbqdj1oo . P_29 ) ; gj2wmplzhf = ( * co4rfisdxd <=
jtbbqdj1oo . P_29 ) ; if ( hfvdvqatqv && gj2wmplzhf ) { akl4jylwt5 *= 0.02 /
( 3.0 - muDoubleScalarPower ( mweybw2gnb_idx_1 , 2.0 ) ) ; } else {
akl4jylwt5 = * co4rfisdxd ; } akl4jylwt5 = jqumtuy4e3 / akl4jylwt5 ; if (
mweybw2gnb_idx_0 > jtbbqdj1oo . P_64 ) { ba12yjhnae = (
rtP__PlntVehDstCGRearAxl2f2PassVeh_sldd_ * rtP__PlntVehMass2f2PassVeh_sldd_ *
rtP__EnvGrvty2f2Environment_sldd_ - rtP__EnvGrvty2f2Environment_sldd_ *
rtP__PlntVehMass2f2PassVeh_sldd_ * ( rtP__PlntVehCGHgtAxl2f2PassVeh_sldd_ +
rtP__PlntWhlLdRadius2f2PassVeh_sldd_ ) * jtbbqdj1oo . P_60 ) / (
rtP__PlntVehDstCGFrntAxl2f2PassVeh_sldd_ +
rtP__PlntVehDstCGRearAxl2f2PassVeh_sldd_ ) *
rtP__PlntWhlLdRadius2f2PassVeh_sldd_ * jtbbqdj1oo . P_61 * jtbbqdj1oo . P_62
; } else { ba12yjhnae = jtbbqdj1oo . P_63 ; } if ( mweybw2gnb_idx_0 >= 0.0 )
{ for ( i = 0 ; i < 201 ; i ++ ) { if ( mweybw2gnb_idx_0 <= g0mwm5df5k [ i ]
) { fwh1ybwery [ i ] = mweybw2gnb_idx_0 - localDW -> glinugelel [ i ] ; } }
srUpdateBC ( localDW -> nx0zq5arfp ) ; } else { for ( i = 0 ; i < 201 ; i ++
) { mweybw2gnb_idx_3 = g0mwm5df5k [ i ] ; dhsrkgeanv = fwh1ybwery [ i ] ; if
( mweybw2gnb_idx_0 >= dhsrkgeanv ) { mweybw2gnb_idx_3 = mweybw2gnb_idx_0 -
localDW -> cg13f1zg3e [ i ] ; } if ( mweybw2gnb_idx_3 > jtbbqdj1oo . P_30 ) {
mweybw2gnb_idx_3 = jtbbqdj1oo . P_30 ; } else if ( mweybw2gnb_idx_3 <
dhsrkgeanv ) { mweybw2gnb_idx_3 = dhsrkgeanv ; } g0mwm5df5k [ i ] =
mweybw2gnb_idx_3 ; } srUpdateBC ( localDW -> mfbmya0nxt ) ; } if (
mweybw2gnb_idx_0 > jtbbqdj1oo . P_71 ) { lkw3efwvok = jtbbqdj1oo . P_63 ; }
else { lkw3efwvok = ( rtP__PlntVehDstCGRearAxl2f2PassVeh_sldd_ *
rtP__PlntVehMass2f2PassVeh_sldd_ * rtP__EnvGrvty2f2Environment_sldd_ -
rtP__EnvGrvty2f2Environment_sldd_ * rtP__PlntVehMass2f2PassVeh_sldd_ * (
rtP__PlntVehCGHgtAxl2f2PassVeh_sldd_ + rtP__PlntWhlLdRadius2f2PassVeh_sldd_ )
* jtbbqdj1oo . P_67 ) / ( rtP__PlntVehDstCGFrntAxl2f2PassVeh_sldd_ +
rtP__PlntVehDstCGRearAxl2f2PassVeh_sldd_ ) *
rtP__PlntWhlLdRadius2f2PassVeh_sldd_ * jtbbqdj1oo . P_68 * jtbbqdj1oo . P_69
* jtbbqdj1oo . P_70 ; } for ( i = 0 ; i < 201 ; i ++ ) { dhsrkgeanv =
fwh1ybwery [ i ] ; if ( dhsrkgeanv > ba12yjhnae ) { fwh1ybwery [ i ] =
ba12yjhnae ; } else if ( dhsrkgeanv < lkw3efwvok ) { fwh1ybwery [ i ] =
lkw3efwvok ; } } ba12yjhnae = jtbbqdj1oo . P_72 * lx3tgymwrh_idx_0 ;
mweybw2gnb_idx_2 = 1.0 / rtP__PlntDiffrntlRatio2f2Drivetrain_sldd_ ; for ( i
= 0 ; i < 201 ; i ++ ) { dhsrkgeanv = fwh1ybwery [ i ] ; if ( dhsrkgeanv >
lx3tgymwrh_idx_0 ) { dhsrkgeanv = lx3tgymwrh_idx_0 ; } else if ( dhsrkgeanv <
ba12yjhnae ) { dhsrkgeanv = ba12yjhnae ; } localB -> dzwvktzhbg [ i ] =
dhsrkgeanv ; if ( localDW -> gimarahrpl [ i ] * prxlczghi0_idx_0 >=
jtbbqdj1oo . P_59 ) { dapypv1qpv = jtbbqdj1oo . P_56 ; } else { dapypv1qpv =
jtbbqdj1oo . P_58 ; } if ( ( rtP__PlntDiffrntl2Eff2f2Drivetrain_sldd_ < 0.0 )
&& ( dapypv1qpv > muDoubleScalarFloor ( dapypv1qpv ) ) ) { dapypv1qpv = -
muDoubleScalarPower ( - rtP__PlntDiffrntl2Eff2f2Drivetrain_sldd_ , dapypv1qpv
) ; } else { dapypv1qpv = muDoubleScalarPower (
rtP__PlntDiffrntl2Eff2f2Drivetrain_sldd_ , dapypv1qpv ) ; } dapypv1qpv = 1.0
/ dapypv1qpv * ( mweybw2gnb_idx_2 * dhsrkgeanv ) ; localB -> fd1vvizdm5 [ i ]
= dapypv1qpv ; ikoagaviq4 [ i ] = prxlczghi0_idx_0 * dapypv1qpv ; muk1vqfd31
[ i ] = muDoubleScalarAbs ( localB -> fd1vvizdm5 [ i ] ) ; } bpIndices [ 0U ]
= plook_bincpa ( muDoubleScalarAbs ( prxlczghi0_idx_0 ) ,
rtP__PlntEM1Spd2f2ElectricMachine1_sldd_ , 13U , & mweybw2gnb_idx_2 , &
localDW -> nkr00y3cul ) ; fractions [ 0U ] = mweybw2gnb_idx_2 ; for ( i = 0 ;
i < 201 ; i ++ ) { bpIndices [ 1U ] = plook_bincpa ( muk1vqfd31 [ i ] ,
rtP__PlntEM1TrqEff2f2ElectricMachine1_sldd_ , 10U , & mweybw2gnb_idx_2 , &
localDW -> ijcpktnusb [ i ] ) ; fractions [ 1U ] = mweybw2gnb_idx_2 ;
muk1vqfd31 [ i ] = intrp2d_la_pw ( bpIndices , fractions ,
rtP__PlntEM1EffTbl2f2ElectricMachine1_sldd_ , 14U , jtbbqdj1oo . P_148 ) ; }
if ( mweybw2gnb_idx_0 > jtbbqdj1oo . P_85 ) { lkw3efwvok = (
rtP__EnvGrvty2f2Environment_sldd_ * rtP__PlntVehMass2f2PassVeh_sldd_ * (
rtP__PlntVehCGHgtAxl2f2PassVeh_sldd_ + rtP__PlntWhlLdRadius2f2PassVeh_sldd_ )
* jtbbqdj1oo . P_81 + rtP__PlntVehDstCGFrntAxl2f2PassVeh_sldd_ *
rtP__PlntVehMass2f2PassVeh_sldd_ * rtP__EnvGrvty2f2Environment_sldd_ ) / (
rtP__PlntVehDstCGFrntAxl2f2PassVeh_sldd_ +
rtP__PlntVehDstCGRearAxl2f2PassVeh_sldd_ ) *
rtP__PlntWhlLdRadius2f2PassVeh_sldd_ * jtbbqdj1oo . P_82 * jtbbqdj1oo . P_83
; } else { lkw3efwvok = jtbbqdj1oo . P_84 ; } if ( mweybw2gnb_idx_0 >
jtbbqdj1oo . P_90 ) { mweybw2gnb_idx_2 = jtbbqdj1oo . P_84 ; } else {
mweybw2gnb_idx_2 = ( rtP__EnvGrvty2f2Environment_sldd_ *
rtP__PlntVehMass2f2PassVeh_sldd_ * ( rtP__PlntVehCGHgtAxl2f2PassVeh_sldd_ +
rtP__PlntWhlLdRadius2f2PassVeh_sldd_ ) * jtbbqdj1oo . P_86 +
rtP__PlntVehDstCGFrntAxl2f2PassVeh_sldd_ * rtP__PlntVehMass2f2PassVeh_sldd_ *
rtP__EnvGrvty2f2Environment_sldd_ ) / (
rtP__PlntVehDstCGFrntAxl2f2PassVeh_sldd_ +
rtP__PlntVehDstCGRearAxl2f2PassVeh_sldd_ ) *
rtP__PlntWhlLdRadius2f2PassVeh_sldd_ * jtbbqdj1oo . P_87 * jtbbqdj1oo . P_88
* jtbbqdj1oo . P_89 ; } for ( i = 0 ; i < 201 ; i ++ ) { dhsrkgeanv =
jtbbqdj1oo . P_73 * muk1vqfd31 [ i ] ; mweybw2gnb_idx_3 = ikoagaviq4 [ i ] ;
if ( mweybw2gnb_idx_3 >= jtbbqdj1oo . P_76 ) { dapypv1qpv = jtbbqdj1oo . P_74
; } else { dapypv1qpv = jtbbqdj1oo . P_75 ; } if ( ( dhsrkgeanv < 0.0 ) && (
dapypv1qpv > muDoubleScalarFloor ( dapypv1qpv ) ) ) { dhsrkgeanv = -
muDoubleScalarPower ( - dhsrkgeanv , dapypv1qpv ) ; } else { dhsrkgeanv =
muDoubleScalarPower ( dhsrkgeanv , dapypv1qpv ) ; } muk1vqfd31 [ i ] =
dhsrkgeanv ; adnwsv2a13 [ i ] = mweybw2gnb_idx_3 * dhsrkgeanv ;
mweybw2gnb_idx_3 = g0mwm5df5k [ i ] ; if ( mweybw2gnb_idx_3 > lkw3efwvok ) {
ikoagaviq4 [ i ] = lkw3efwvok ; } else if ( mweybw2gnb_idx_3 <
mweybw2gnb_idx_2 ) { ikoagaviq4 [ i ] = mweybw2gnb_idx_2 ; } else {
ikoagaviq4 [ i ] = mweybw2gnb_idx_3 ; } } lkw3efwvok = jtbbqdj1oo . P_91 *
lx3tgymwrh_idx_1 ; mweybw2gnb_idx_2 = 1.0 /
rtP__PlntDiffrntl2Ratio2f2Drivetrain_sldd_ ; for ( i = 0 ; i < 201 ; i ++ ) {
mweybw2gnb_idx_3 = ikoagaviq4 [ i ] ; if ( mweybw2gnb_idx_3 >
lx3tgymwrh_idx_1 ) { mweybw2gnb_idx_3 = lx3tgymwrh_idx_1 ; } else if (
mweybw2gnb_idx_3 < lkw3efwvok ) { mweybw2gnb_idx_3 = lkw3efwvok ; } localB ->
mxl3qxjrqz [ i ] = mweybw2gnb_idx_3 ; if ( localDW -> p5p4aaxq51 [ i ] *
prxlczghi0_idx_1 >= jtbbqdj1oo . P_80 ) { dapypv1qpv = jtbbqdj1oo . P_77 ; }
else { dapypv1qpv = jtbbqdj1oo . P_79 ; } if ( (
rtP__PlntDiffrntl2Eff2f2Drivetrain_sldd_ < 0.0 ) && ( dapypv1qpv >
muDoubleScalarFloor ( dapypv1qpv ) ) ) { dapypv1qpv = - muDoubleScalarPower (
- rtP__PlntDiffrntl2Eff2f2Drivetrain_sldd_ , dapypv1qpv ) ; } else {
dapypv1qpv = muDoubleScalarPower ( rtP__PlntDiffrntl2Eff2f2Drivetrain_sldd_ ,
dapypv1qpv ) ; } dapypv1qpv = 1.0 / dapypv1qpv * ( mweybw2gnb_idx_2 *
mweybw2gnb_idx_3 ) ; localB -> fmppinmdui [ i ] = dapypv1qpv ; g0mwm5df5k [ i
] = prxlczghi0_idx_1 * dapypv1qpv ; muk1vqfd31 [ i ] = muDoubleScalarAbs (
localB -> fmppinmdui [ i ] ) ; } bpIndices_p [ 0U ] = plook_bincpa (
muDoubleScalarAbs ( prxlczghi0_idx_1 ) ,
rtP__PlntEM2Spd2f2ElectricMachine2_sldd_ , 13U , & mweybw2gnb_idx_2 , &
localDW -> gqk1jf1ek0 ) ; fractions_p [ 0U ] = mweybw2gnb_idx_2 ; for ( i = 0
; i < 201 ; i ++ ) { bpIndices_p [ 1U ] = plook_bincpa ( muk1vqfd31 [ i ] ,
rtP__PlntEM2TrqEff2f2ElectricMachine2_sldd_ , 10U , & mweybw2gnb_idx_2 , &
localDW -> nqv3ows0gj [ i ] ) ; fractions_p [ 1U ] = mweybw2gnb_idx_2 ;
muk1vqfd31 [ i ] = intrp2d_la_pw ( bpIndices_p , fractions_p ,
rtP__PlntEM2EffTbl2f2ElectricMachine2_sldd_ , 14U , jtbbqdj1oo . P_149 ) ; }
mweybw2gnb_idx_2 = * co4rfisdxd ; if ( mweybw2gnb_idx_2 > jtbbqdj1oo . P_96 )
{ mweybw2gnb_idx_2 = jtbbqdj1oo . P_96 ; } else if ( mweybw2gnb_idx_2 <
jtbbqdj1oo . P_97 ) { mweybw2gnb_idx_2 = jtbbqdj1oo . P_97 ; } for ( i = 0 ;
i < 201 ; i ++ ) { dhsrkgeanv = jtbbqdj1oo . P_92 * muk1vqfd31 [ i ] ;
mweybw2gnb_idx_3 = g0mwm5df5k [ i ] ; if ( mweybw2gnb_idx_3 >= jtbbqdj1oo .
P_95 ) { dapypv1qpv = jtbbqdj1oo . P_93 ; } else { dapypv1qpv = jtbbqdj1oo .
P_94 ; } if ( ( dhsrkgeanv < 0.0 ) && ( dapypv1qpv > muDoubleScalarFloor (
dapypv1qpv ) ) ) { dhsrkgeanv = - muDoubleScalarPower ( - dhsrkgeanv ,
dapypv1qpv ) ; } else { dhsrkgeanv = muDoubleScalarPower ( dhsrkgeanv ,
dapypv1qpv ) ; } muk1vqfd31 [ i ] = dhsrkgeanv ; dapypv1qpv =
mweybw2gnb_idx_3 * dhsrkgeanv + adnwsv2a13 [ i ] ; adnwsv2a13 [ i ] =
dapypv1qpv ; g0mwm5df5k [ i ] = dapypv1qpv / mweybw2gnb_idx_2 ; } if ( *
co4rfisdxd >= jtbbqdj1oo . P_98 ) { dapypv1qpv = jtbbqdj1oo . P_128 ; } else
{ dapypv1qpv = localB -> ccvcikyevv ; } hfvdvqatqv = ( * co4rfisdxd >= -
jtbbqdj1oo . P_28 ) ; gj2wmplzhf = ( * co4rfisdxd <= jtbbqdj1oo . P_28 ) ; if
( hfvdvqatqv && gj2wmplzhf ) { mweybw2gnb_idx_2 = 0.02 / ( 3.0 -
muDoubleScalarPower ( mweybw2gnb_idx_1 , 2.0 ) ) * dapypv1qpv ; } else {
mweybw2gnb_idx_2 = * co4rfisdxd ; } mweybw2gnb_idx_2 = 1.0 / mweybw2gnb_idx_2
* n2fq14epk3 ; hfvdvqatqv = ( mweybw2gnb_idx_0 >= jtbbqdj1oo . P_32 ) ; for (
i = 0 ; i < 201 ; i ++ ) { mweybw2gnb_idx_3 = g0mwm5df5k [ i ] ; if (
mweybw2gnb_idx_3 > akl4jylwt5 ) { mweybw2gnb_idx_3 = akl4jylwt5 ; } else if (
mweybw2gnb_idx_3 < mweybw2gnb_idx_2 ) { mweybw2gnb_idx_3 = mweybw2gnb_idx_2 ;
} muk1vqfd31 [ i ] = * co4rfisdxd * mweybw2gnb_idx_3 ; dhsrkgeanv =
fwh1ybwery [ i ] ; jzltqxzg4n [ i ] = ( ( lx3tgymwrh_idx_0 < dhsrkgeanv ) ||
( dhsrkgeanv < ba12yjhnae ) || ( ( dhsrkgeanv < jtbbqdj1oo . P_31 ) &&
hfvdvqatqv ) ) ; } hfvdvqatqv = ( mweybw2gnb_idx_0 >= jtbbqdj1oo . P_34 ) ;
for ( i = 0 ; i < 201 ; i ++ ) { mweybw2gnb_idx_3 = ikoagaviq4 [ i ] ;
kcw0u0fwkc [ i ] = ( ( lx3tgymwrh_idx_1 < mweybw2gnb_idx_3 ) || (
mweybw2gnb_idx_3 < lkw3efwvok ) || ( ( mweybw2gnb_idx_3 < jtbbqdj1oo . P_33 )
&& hfvdvqatqv ) ) ; mweybw2gnb_idx_3 = g0mwm5df5k [ i ] ; dapypv1qpv =
adnwsv2a13 [ i ] ; eoaa5ck4cu [ i ] = ( ( mweybw2gnb_idx_3 > akl4jylwt5 ) ||
( mweybw2gnb_idx_3 < mweybw2gnb_idx_2 ) || ( dapypv1qpv > jqumtuy4e3 ) || (
dapypv1qpv < n2fq14epk3 ) ) ; } jqumtuy4e3 = ipjizrw5pk_tmp ; if (
ipjizrw5pk_tmp > jtbbqdj1oo . P_100 ) { jqumtuy4e3 = jtbbqdj1oo . P_100 ; }
else if ( ipjizrw5pk_tmp < jtbbqdj1oo . P_101 ) { jqumtuy4e3 = jtbbqdj1oo .
P_101 ; } for ( i = 0 ; i <= 198 ; i += 2 ) { tmp = _mm_loadu_pd ( & localB
-> dzwvktzhbg [ i ] ) ; tmp_p = _mm_loadu_pd ( & localB -> mxl3qxjrqz [ i ] )
; _mm_storeu_pd ( & tmp_i [ 0 ] , _mm_mul_pd ( _mm_sub_pd ( _mm_set1_pd (
mweybw2gnb_idx_0 ) , _mm_add_pd ( tmp , tmp_p ) ) , _mm_set1_pd ( jqumtuy4e3
) ) ) ; tmp_e [ 0 ] = muDoubleScalarAbs ( tmp_i [ 0 ] ) ; tmp_e [ 1 ] =
muDoubleScalarAbs ( tmp_i [ 1 ] ) ; tmp = _mm_loadu_pd ( & tmp_e [ 0 ] ) ;
_mm_storeu_pd ( & fwh1ybwery [ i ] , _mm_mul_pd ( _mm_mul_pd ( tmp ,
_mm_set1_pd ( jtbbqdj1oo . P_102 ) ) , _mm_set1_pd ( jtbbqdj1oo . P_103 ) ) )
; } for ( i = 200 ; i < 201 ; i ++ ) { fwh1ybwery [ i ] = muDoubleScalarAbs (
( mweybw2gnb_idx_0 - ( localB -> dzwvktzhbg [ i ] + localB -> mxl3qxjrqz [ i
] ) ) * jqumtuy4e3 ) * jtbbqdj1oo . P_102 * jtbbqdj1oo . P_103 ; } if ( *
ppjd0yjs10 > jtbbqdj1oo . P_106 ) { jqumtuy4e3 = * ppjd0yjs10 - jtbbqdj1oo .
P_106 ; } else if ( * ppjd0yjs10 >= jtbbqdj1oo . P_105 ) { jqumtuy4e3 = 0.0 ;
} else { jqumtuy4e3 = * ppjd0yjs10 - jtbbqdj1oo . P_105 ; } jqumtuy4e3 *= 1.0
/ rtP__PlntWhlLdRadius2f2PassVeh_sldd_ ; if ( mweybw2gnb_idx_0 >= jtbbqdj1oo
. P_109 ) { dapypv1qpv = localDW -> mnt5i0lw4q ; } else { dapypv1qpv =
localDW -> o5t0xnvnze ; } n2fq14epk3 = jqumtuy4e3 * dapypv1qpv ; for ( i = 0
; i < 201 ; i ++ ) { if ( mweybw2gnb_idx_0 >= jtbbqdj1oo . P_104 ) {
dapypv1qpv = localB -> dzwvktzhbg [ i ] ; } else { dapypv1qpv = localB ->
mxl3qxjrqz [ i ] ; } mweybw2gnb_idx_3 = dapypv1qpv * jqumtuy4e3 - n2fq14epk3
; mweybw2gnb_idx_3 *= mweybw2gnb_idx_3 ; g0mwm5df5k [ i ] =
muDoubleScalarSqrt ( mweybw2gnb_idx_3 ) ; } jqumtuy4e3 = look1_pbinlcapw ( *
dikvztxmir , jtbbqdj1oo . P_112 , jtbbqdj1oo . P_111 , & localDW ->
j3gtt2mnys , 2U ) ; hfvdvqatqv = true ; i = 0 ; exitg1 = false ; while ( ( !
exitg1 ) && ( i < 201 ) ) { if ( ( ! jzltqxzg4n [ i ] ) || ( ! kcw0u0fwkc [ i
] ) || ( ! eoaa5ck4cu [ i ] ) ) { hfvdvqatqv = false ; exitg1 = true ; } else
{ i ++ ; } } if ( hfvdvqatqv ) { for ( i = 0 ; i < 201 ; i ++ ) { if (
jzltqxzg4n [ i ] ) { tmp_m = jtbbqdj1oo . P_150 ; } else { tmp_m = 0 ; } if (
kcw0u0fwkc [ i ] ) { tmp_g = jtbbqdj1oo . P_151 ; } else { tmp_g = 0 ; } if (
eoaa5ck4cu [ i ] ) { tmp_j = jtbbqdj1oo . P_147 ; } else { tmp_j = 0U ; }
ikoagaviq4 [ i ] = ( ( ( real_T ) ( ( ( ( uint32_T ) tmp_m << 7 ) + ( (
uint32_T ) tmp_g << 7 ) ) + tmp_j ) * 0.00390625 + jtbbqdj1oo . P_99 *
muk1vqfd31 [ i ] ) + fwh1ybwery [ i ] ) + jtbbqdj1oo . P_110 * g0mwm5df5k [ i
] * jqumtuy4e3 ; } minimum_hZ1kyuym ( ikoagaviq4 , & n2fq14epk3 , & i ) ;
jqumtuy4e3 = i ; } else { for ( i = 0 ; i < 201 ; i ++ ) { if ( jzltqxzg4n [
i ] ) { tmp_m = jtbbqdj1oo . P_150 ; } else { tmp_m = 0 ; } if ( kcw0u0fwkc [
i ] ) { tmp_g = jtbbqdj1oo . P_151 ; } else { tmp_g = 0 ; } if ( eoaa5ck4cu [
i ] ) { tmp_j = jtbbqdj1oo . P_147 ; } else { tmp_j = 0U ; } ikoagaviq4 [ i ]
= ( ( ( real_T ) ( ( ( ( uint32_T ) tmp_m << 7 ) + ( ( uint32_T ) tmp_g << 7
) ) + tmp_j ) * 0.00390625 + jtbbqdj1oo . P_99 * muk1vqfd31 [ i ] ) +
fwh1ybwery [ i ] ) + jtbbqdj1oo . P_110 * g0mwm5df5k [ i ] * jqumtuy4e3 ; }
minimum_hZ1kyuym ( ikoagaviq4 , & n2fq14epk3 , & i ) ; jqumtuy4e3 = i ; } i =
( int32_T ) jqumtuy4e3 - 1 ; localB -> lck1mvy5xl = localB -> dzwvktzhbg [ i
] ; localB -> pearyyfvki = localB -> mxl3qxjrqz [ i ] ; ipjizrw5pk_tmp =
localB -> lck1mvy5xl + localB -> pearyyfvki ; if ( ipjizrw5pk_tmp >
jtbbqdj1oo . P_113 ) { ipjizrw5pk_tmp = jtbbqdj1oo . P_113 ; } else if (
ipjizrw5pk_tmp < jtbbqdj1oo . P_114 ) { ipjizrw5pk_tmp = jtbbqdj1oo . P_114 ;
} ipjizrw5pk_tmp += m142e0s54t ; if ( ipjizrw5pk_tmp > jtbbqdj1oo . P_115 ) {
ipjizrw5pk_tmp = jtbbqdj1oo . P_115 ; } else if ( ipjizrw5pk_tmp < jtbbqdj1oo
. P_116 ) { ipjizrw5pk_tmp = jtbbqdj1oo . P_116 ; } m142e0s54t =
ipjizrw5pk_tmp / ( jvgykmagyc_tmp * 4.0 ) * ( 1.0 /
rtP__PlntBrkPrsFctr2f2PassVeh_sldd_ ) ; if ( m142e0s54t > jtbbqdj1oo . P_117
) { m142e0s54t = jtbbqdj1oo . P_117 ; } else if ( m142e0s54t < jtbbqdj1oo .
P_118 ) { m142e0s54t = jtbbqdj1oo . P_118 ; } jg1dpl1t23 [ 0 ] = m142e0s54t ;
jg1dpl1t23 [ 1 ] = m142e0s54t ; jg1dpl1t23 [ 2 ] = m142e0s54t ; jg1dpl1t23 [
3 ] = m142e0s54t ; if ( localDW -> f12x4t2yjl * prxlczghi0_idx_0 >=
jtbbqdj1oo . P_122 ) { m142e0s54t = jtbbqdj1oo . P_119 ; } else { m142e0s54t
= jtbbqdj1oo . P_121 ; } if ( ( rtP__PlntDiffrntlEff2f2Drivetrain_sldd_ < 0.0
) && ( m142e0s54t > muDoubleScalarFloor ( m142e0s54t ) ) ) { dapypv1qpv = -
muDoubleScalarPower ( - rtP__PlntDiffrntlEff2f2Drivetrain_sldd_ , m142e0s54t
) ; } else { dapypv1qpv = muDoubleScalarPower (
rtP__PlntDiffrntlEff2f2Drivetrain_sldd_ , m142e0s54t ) ; } localB ->
mtln4qjww2 = 1.0 / rtP__PlntDiffrntlRatio2f2Drivetrain_sldd_ * localB ->
lck1mvy5xl * ( 1.0 / dapypv1qpv ) ; lx3tgymwrh_idx_0 = localB -> mtln4qjww2 ;
if ( localDW -> ow2qkdjqul * prxlczghi0_idx_1 >= jtbbqdj1oo . P_126 ) {
m142e0s54t = jtbbqdj1oo . P_123 ; } else { m142e0s54t = jtbbqdj1oo . P_125 ;
} if ( ( rtP__PlntDiffrntl2Eff2f2Drivetrain_sldd_ < 0.0 ) && ( m142e0s54t >
muDoubleScalarFloor ( m142e0s54t ) ) ) { dapypv1qpv = - muDoubleScalarPower (
- rtP__PlntDiffrntl2Eff2f2Drivetrain_sldd_ , m142e0s54t ) ; } else {
dapypv1qpv = muDoubleScalarPower ( rtP__PlntDiffrntl2Eff2f2Drivetrain_sldd_ ,
m142e0s54t ) ; } localB -> gbysfqhlgd = 1.0 /
rtP__PlntDiffrntl2Ratio2f2Drivetrain_sldd_ * localB -> pearyyfvki * ( 1.0 /
dapypv1qpv ) ; lx3tgymwrh_idx_1 = localB -> gbysfqhlgd ; } if (
rtmIsMajorTimeStep ( jcaapsdo3t ) ) { localB -> kfjmbecbry = localDW ->
bnr3irkvs1 ; } localB -> c3fwouwrtz = rtmGetTaskTime ( jcaapsdo3t , 0 ) -
localB -> kfjmbecbry ; { if ( localDW -> j0c0jhtxz1 . AQHandles &&
ssGetLogOutput ( jcaapsdo3t -> _mdlRefSfcnS ) ) { sdiWriteSignal ( localDW ->
j0c0jhtxz1 . AQHandles , rtmGetTaskTime ( jcaapsdo3t , 0 ) , ( char * ) &
localB -> c3fwouwrtz + 0 ) ; } } if ( rtmIsMajorTimeStep ( jcaapsdo3t ) ) {
m142e0s54t = lx3tgymwrh_idx_0 - localDW -> ns0ekabbmt [ 0 ] ; if ( m142e0s54t
> jtbbqdj1oo . P_140 * eiwqcockbc ) { lx3tgymwrh_idx_0 = jtbbqdj1oo . P_140 *
eiwqcockbc + localDW -> ns0ekabbmt [ 0 ] ; } else if ( m142e0s54t <
jtbbqdj1oo . P_141 * eiwqcockbc ) { lx3tgymwrh_idx_0 = jtbbqdj1oo . P_141 *
eiwqcockbc + localDW -> ns0ekabbmt [ 0 ] ; } gvnpst4w0k [ 0 ] =
lx3tgymwrh_idx_0 ; localDW -> ns0ekabbmt [ 0 ] = lx3tgymwrh_idx_0 ;
m142e0s54t = lx3tgymwrh_idx_1 - localDW -> ns0ekabbmt [ 1 ] ; if ( m142e0s54t
> jtbbqdj1oo . P_140 * eiwqcockbc ) { lx3tgymwrh_idx_0 = jtbbqdj1oo . P_140 *
eiwqcockbc + localDW -> ns0ekabbmt [ 1 ] ; } else if ( m142e0s54t <
jtbbqdj1oo . P_141 * eiwqcockbc ) { lx3tgymwrh_idx_0 = jtbbqdj1oo . P_141 *
eiwqcockbc + localDW -> ns0ekabbmt [ 1 ] ; } else { lx3tgymwrh_idx_0 =
lx3tgymwrh_idx_1 ; } gvnpst4w0k [ 1 ] = lx3tgymwrh_idx_0 ; localDW ->
ns0ekabbmt [ 1 ] = lx3tgymwrh_idx_0 ; * edcjsjvsbf = jtbbqdj1oo . P_143 ; *
dcs1zebgq2 = jtbbqdj1oo . P_144 ; * megpmqfjrl = jtbbqdj1oo . P_145 ; *
imfqdgtkm2 = jtbbqdj1oo . P_146 ; } } void EvPowertrainController2EMTID2 (
bwwdwvebxa * localB ) { localB -> ccvcikyevv = - jtbbqdj1oo . P_128 ; localB
-> jovi3oh0hw = - jtbbqdj1oo . P_129 ; } void e3ptmay5nu ( nwcwzcnldx * const
jcaapsdo3t , bwwdwvebxa * localB , cpxpfpdja3 * localDW ) { if (
rtmIsMajorTimeStep ( jcaapsdo3t ) ) { memcpy ( & localDW -> gimarahrpl [ 0 ]
, & localB -> fd1vvizdm5 [ 0 ] , 201U * sizeof ( real_T ) ) ; memcpy ( &
localDW -> glinugelel [ 0 ] , & localB -> mxl3qxjrqz [ 0 ] , 201U * sizeof (
real_T ) ) ; memcpy ( & localDW -> cg13f1zg3e [ 0 ] , & localB -> dzwvktzhbg
[ 0 ] , 201U * sizeof ( real_T ) ) ; memcpy ( & localDW -> p5p4aaxq51 [ 0 ] ,
& localB -> fmppinmdui [ 0 ] , 201U * sizeof ( real_T ) ) ; localDW ->
mnt5i0lw4q = localB -> lck1mvy5xl ; localDW -> o5t0xnvnze = localB ->
pearyyfvki ; localDW -> f12x4t2yjl = localB -> mtln4qjww2 ; localDW ->
ow2qkdjqul = localB -> gbysfqhlgd ; localDW -> bnr3irkvs1 = localB ->
c3fwouwrtz ; } } void g0tpyzslmq ( nwcwzcnldx * const jcaapsdo3t , cpxpfpdja3
* localDW ) { if ( ( ssGetSimMode ( jcaapsdo3t -> _mdlRefSfcnS ) !=
SS_SIMMODE_EXTERNAL ) && ( ( jcaapsdo3t -> _mdlRefSfcnS ) -> mdlInfo ->
rtwgenMode != SS_RTWGEN_MODELREFERENCE_RTW_TARGET ) ) { if ( localDW ->
j0c0jhtxz1 . AQHandles ) { sdiTerminateStreaming ( & localDW -> j0c0jhtxz1 .
AQHandles ) ; } } } void dfeuqru533 ( nwcwzcnldx * const jcaapsdo3t ) { if (
! slIsRapidAcceleratorSimulating ( ) ) { slmrRunPluginEvent ( jcaapsdo3t ->
_mdlRefSfcnS , "EvPowertrainController2EM" ,
"SIMSTATUS_TERMINATING_MODELREF_ACCEL_EVENT" ) ; } } void d443wer2uj (
SimStruct * _mdlRefSfcnS , int_T mdlref_TID0 , int_T mdlref_TID1 , int_T
mdlref_TID2 , nwcwzcnldx * const jcaapsdo3t , bwwdwvebxa * localB ,
cpxpfpdja3 * localDW , void * sysRanPtr , int contextTid ,
rtwCAPI_ModelMappingInfo * rt_ParentMMI , const char_T * rt_ChildPath , int_T
rt_ChildMMIIdx , int_T rt_CSTATEIdx ) { rt_InitInfAndNaN ( sizeof ( real_T )
) ; jtbbqdj1oo . P_96 = rtInf ; jtbbqdj1oo . P_100 = rtInf ; jtbbqdj1oo .
P_114 = rtMinusInf ; jtbbqdj1oo . P_115 = rtInf ; ( void ) memset ( ( void *
) jcaapsdo3t , 0 , sizeof ( nwcwzcnldx ) ) ; jcaapsdo3t -> Timing .
mdlref_GlobalTID [ 0 ] = mdlref_TID0 ; jcaapsdo3t -> Timing .
mdlref_GlobalTID [ 1 ] = mdlref_TID1 ; jcaapsdo3t -> Timing .
mdlref_GlobalTID [ 2 ] = mdlref_TID2 ; jcaapsdo3t -> _mdlRefSfcnS = (
_mdlRefSfcnS ) ; if ( ! slIsRapidAcceleratorSimulating ( ) ) {
slmrRunPluginEvent ( jcaapsdo3t -> _mdlRefSfcnS , "EvPowertrainController2EM"
, "START_OF_SIM_MODEL_MODELREF_ACCEL_EVENT" ) ; } { int32_T i ; for ( i = 0 ;
i < 201 ; i ++ ) { localB -> dzwvktzhbg [ i ] = 0.0 ; } for ( i = 0 ; i < 201
; i ++ ) { localB -> fd1vvizdm5 [ i ] = 0.0 ; } for ( i = 0 ; i < 201 ; i ++
) { localB -> mxl3qxjrqz [ i ] = 0.0 ; } for ( i = 0 ; i < 201 ; i ++ ) {
localB -> fmppinmdui [ i ] = 0.0 ; } localB -> lck1mvy5xl = 0.0 ; localB ->
pearyyfvki = 0.0 ; localB -> mtln4qjww2 = 0.0 ; localB -> gbysfqhlgd = 0.0 ;
localB -> kfjmbecbry = 0.0 ; localB -> c3fwouwrtz = 0.0 ; localB ->
ccvcikyevv = 0.0 ; localB -> jovi3oh0hw = 0.0 ; } ( void ) memset ( ( void *
) localDW , 0 , sizeof ( cpxpfpdja3 ) ) ; { int32_T i ; for ( i = 0 ; i < 201
; i ++ ) { localDW -> gimarahrpl [ i ] = 0.0 ; } } { int32_T i ; for ( i = 0
; i < 201 ; i ++ ) { localDW -> glinugelel [ i ] = 0.0 ; } } { int32_T i ;
for ( i = 0 ; i < 201 ; i ++ ) { localDW -> cg13f1zg3e [ i ] = 0.0 ; } } {
int32_T i ; for ( i = 0 ; i < 201 ; i ++ ) { localDW -> p5p4aaxq51 [ i ] =
0.0 ; } } localDW -> mnt5i0lw4q = 0.0 ; localDW -> o5t0xnvnze = 0.0 ; localDW
-> f12x4t2yjl = 0.0 ; localDW -> ow2qkdjqul = 0.0 ; localDW -> ns0ekabbmt [ 0
] = 0.0 ; localDW -> ns0ekabbmt [ 1 ] = 0.0 ; localDW -> bnr3irkvs1 = 0.0 ;
EvPowertrainController2EM_InitializeDataMapInfo ( jcaapsdo3t , localDW ,
sysRanPtr , contextTid ) ; if ( ( rt_ParentMMI != ( NULL ) ) && (
rt_ChildPath != ( NULL ) ) ) { rtwCAPI_SetChildMMI ( * rt_ParentMMI ,
rt_ChildMMIIdx , & ( jcaapsdo3t -> DataMapInfo . mmi ) ) ; rtwCAPI_SetPath (
jcaapsdo3t -> DataMapInfo . mmi , rt_ChildPath ) ;
rtwCAPI_MMISetContStateStartIndex ( jcaapsdo3t -> DataMapInfo . mmi ,
rt_CSTATEIdx ) ; } } void mr_EvPowertrainController2EM_MdlInfoRegFcn (
SimStruct * mdlRefSfcnS , char_T * modelName , int_T * retVal ) { * retVal =
0 ; { boolean_T regSubmodelsMdlinfo = false ; ssGetRegSubmodelsMdlinfo (
mdlRefSfcnS , & regSubmodelsMdlinfo ) ; if ( regSubmodelsMdlinfo ) { } } *
retVal = 0 ; ssRegModelRefMdlInfo ( mdlRefSfcnS , modelName ,
rtMdlInfo_EvPowertrainController2EM , 45 ) ; * retVal = 1 ; } static void
mr_EvPowertrainController2EM_cacheDataAsMxArray ( mxArray * destArray ,
mwIndex i , int j , const void * srcData , size_t numBytes ) ; static void
mr_EvPowertrainController2EM_cacheDataAsMxArray ( mxArray * destArray ,
mwIndex i , int j , const void * srcData , size_t numBytes ) { mxArray *
newArray = mxCreateUninitNumericMatrix ( ( size_t ) 1 , numBytes ,
mxUINT8_CLASS , mxREAL ) ; memcpy ( ( uint8_T * ) mxGetData ( newArray ) , (
const uint8_T * ) srcData , numBytes ) ; mxSetFieldByNumber ( destArray , i ,
j , newArray ) ; } static void
mr_EvPowertrainController2EM_restoreDataFromMxArray ( void * destData , const
mxArray * srcArray , mwIndex i , int j , size_t numBytes ) ; static void
mr_EvPowertrainController2EM_restoreDataFromMxArray ( void * destData , const
mxArray * srcArray , mwIndex i , int j , size_t numBytes ) { memcpy ( (
uint8_T * ) destData , ( const uint8_T * ) mxGetData ( mxGetFieldByNumber (
srcArray , i , j ) ) , numBytes ) ; } static void
mr_EvPowertrainController2EM_cacheBitFieldToMxArray ( mxArray * destArray ,
mwIndex i , int j , uint_T bitVal ) ; static void
mr_EvPowertrainController2EM_cacheBitFieldToMxArray ( mxArray * destArray ,
mwIndex i , int j , uint_T bitVal ) { mxSetFieldByNumber ( destArray , i , j
, mxCreateDoubleScalar ( ( real_T ) bitVal ) ) ; } static uint_T
mr_EvPowertrainController2EM_extractBitFieldFromMxArray ( const mxArray *
srcArray , mwIndex i , int j , uint_T numBits ) ; static uint_T
mr_EvPowertrainController2EM_extractBitFieldFromMxArray ( const mxArray *
srcArray , mwIndex i , int j , uint_T numBits ) { const uint_T varVal = (
uint_T ) mxGetScalar ( mxGetFieldByNumber ( srcArray , i , j ) ) ; return
varVal & ( ( 1u << numBits ) - 1u ) ; } static void
mr_EvPowertrainController2EM_cacheDataToMxArrayWithOffset ( mxArray *
destArray , mwIndex i , int j , mwIndex offset , const void * srcData ,
size_t numBytes ) ; static void
mr_EvPowertrainController2EM_cacheDataToMxArrayWithOffset ( mxArray *
destArray , mwIndex i , int j , mwIndex offset , const void * srcData ,
size_t numBytes ) { uint8_T * varData = ( uint8_T * ) mxGetData (
mxGetFieldByNumber ( destArray , i , j ) ) ; memcpy ( ( uint8_T * ) & varData
[ offset * numBytes ] , ( const uint8_T * ) srcData , numBytes ) ; } static
void mr_EvPowertrainController2EM_restoreDataFromMxArrayWithOffset ( void *
destData , const mxArray * srcArray , mwIndex i , int j , mwIndex offset ,
size_t numBytes ) ; static void
mr_EvPowertrainController2EM_restoreDataFromMxArrayWithOffset ( void *
destData , const mxArray * srcArray , mwIndex i , int j , mwIndex offset ,
size_t numBytes ) { const uint8_T * varData = ( const uint8_T * ) mxGetData (
mxGetFieldByNumber ( srcArray , i , j ) ) ; memcpy ( ( uint8_T * ) destData ,
( const uint8_T * ) & varData [ offset * numBytes ] , numBytes ) ; } static
void mr_EvPowertrainController2EM_cacheBitFieldToCellArrayWithOffset (
mxArray * destArray , mwIndex i , int j , mwIndex offset , uint_T fieldVal )
; static void mr_EvPowertrainController2EM_cacheBitFieldToCellArrayWithOffset
( mxArray * destArray , mwIndex i , int j , mwIndex offset , uint_T fieldVal
) { mxSetCell ( mxGetFieldByNumber ( destArray , i , j ) , offset ,
mxCreateDoubleScalar ( ( real_T ) fieldVal ) ) ; } static uint_T
mr_EvPowertrainController2EM_extractBitFieldFromCellArrayWithOffset ( const
mxArray * srcArray , mwIndex i , int j , mwIndex offset , uint_T numBits ) ;
static uint_T
mr_EvPowertrainController2EM_extractBitFieldFromCellArrayWithOffset ( const
mxArray * srcArray , mwIndex i , int j , mwIndex offset , uint_T numBits ) {
const uint_T fieldVal = ( uint_T ) mxGetScalar ( mxGetCell (
mxGetFieldByNumber ( srcArray , i , j ) , offset ) ) ; return fieldVal & ( (
1u << numBits ) - 1u ) ; } mxArray * mr_EvPowertrainController2EM_GetDWork (
const oaq0dqotmrc * mdlrefDW ) { static const char_T * ssDWFieldNames [ 3 ] =
{ "rtb" , "rtdw" , "NULL->rtzce" , } ; mxArray * ssDW = mxCreateStructMatrix
( 1 , 1 , 3 , ssDWFieldNames ) ;
mr_EvPowertrainController2EM_cacheDataAsMxArray ( ssDW , 0 , 0 , ( const void
* ) & ( mdlrefDW -> rtb ) , sizeof ( mdlrefDW -> rtb ) ) ; { static const
char_T * rtdwDataFieldNames [ 19 ] = { "mdlrefDW->rtdw.gimarahrpl" ,
"mdlrefDW->rtdw.glinugelel" , "mdlrefDW->rtdw.cg13f1zg3e" ,
"mdlrefDW->rtdw.p5p4aaxq51" , "mdlrefDW->rtdw.mnt5i0lw4q" ,
"mdlrefDW->rtdw.o5t0xnvnze" , "mdlrefDW->rtdw.f12x4t2yjl" ,
"mdlrefDW->rtdw.ow2qkdjqul" , "mdlrefDW->rtdw.ns0ekabbmt" ,
"mdlrefDW->rtdw.bnr3irkvs1" , "mdlrefDW->rtdw.clhfo1klhy" ,
"mdlrefDW->rtdw.nkr00y3cul" , "mdlrefDW->rtdw.ijcpktnusb" ,
"mdlrefDW->rtdw.fbivvkkxil" , "mdlrefDW->rtdw.gqk1jf1ek0" ,
"mdlrefDW->rtdw.nqv3ows0gj" , "mdlrefDW->rtdw.j3gtt2mnys" ,
"mdlrefDW->rtdw.mfbmya0nxt" , "mdlrefDW->rtdw.nx0zq5arfp" , } ; mxArray *
rtdwData = mxCreateStructMatrix ( 1 , 1 , 19 , rtdwDataFieldNames ) ;
mr_EvPowertrainController2EM_cacheDataAsMxArray ( rtdwData , 0 , 0 , ( const
void * ) & ( mdlrefDW -> rtdw . gimarahrpl ) , sizeof ( mdlrefDW -> rtdw .
gimarahrpl ) ) ; mr_EvPowertrainController2EM_cacheDataAsMxArray ( rtdwData ,
0 , 1 , ( const void * ) & ( mdlrefDW -> rtdw . glinugelel ) , sizeof (
mdlrefDW -> rtdw . glinugelel ) ) ;
mr_EvPowertrainController2EM_cacheDataAsMxArray ( rtdwData , 0 , 2 , ( const
void * ) & ( mdlrefDW -> rtdw . cg13f1zg3e ) , sizeof ( mdlrefDW -> rtdw .
cg13f1zg3e ) ) ; mr_EvPowertrainController2EM_cacheDataAsMxArray ( rtdwData ,
0 , 3 , ( const void * ) & ( mdlrefDW -> rtdw . p5p4aaxq51 ) , sizeof (
mdlrefDW -> rtdw . p5p4aaxq51 ) ) ;
mr_EvPowertrainController2EM_cacheDataAsMxArray ( rtdwData , 0 , 4 , ( const
void * ) & ( mdlrefDW -> rtdw . mnt5i0lw4q ) , sizeof ( mdlrefDW -> rtdw .
mnt5i0lw4q ) ) ; mr_EvPowertrainController2EM_cacheDataAsMxArray ( rtdwData ,
0 , 5 , ( const void * ) & ( mdlrefDW -> rtdw . o5t0xnvnze ) , sizeof (
mdlrefDW -> rtdw . o5t0xnvnze ) ) ;
mr_EvPowertrainController2EM_cacheDataAsMxArray ( rtdwData , 0 , 6 , ( const
void * ) & ( mdlrefDW -> rtdw . f12x4t2yjl ) , sizeof ( mdlrefDW -> rtdw .
f12x4t2yjl ) ) ; mr_EvPowertrainController2EM_cacheDataAsMxArray ( rtdwData ,
0 , 7 , ( const void * ) & ( mdlrefDW -> rtdw . ow2qkdjqul ) , sizeof (
mdlrefDW -> rtdw . ow2qkdjqul ) ) ;
mr_EvPowertrainController2EM_cacheDataAsMxArray ( rtdwData , 0 , 8 , ( const
void * ) & ( mdlrefDW -> rtdw . ns0ekabbmt ) , sizeof ( mdlrefDW -> rtdw .
ns0ekabbmt ) ) ; mr_EvPowertrainController2EM_cacheDataAsMxArray ( rtdwData ,
0 , 9 , ( const void * ) & ( mdlrefDW -> rtdw . bnr3irkvs1 ) , sizeof (
mdlrefDW -> rtdw . bnr3irkvs1 ) ) ;
mr_EvPowertrainController2EM_cacheDataAsMxArray ( rtdwData , 0 , 10 , ( const
void * ) & ( mdlrefDW -> rtdw . clhfo1klhy ) , sizeof ( mdlrefDW -> rtdw .
clhfo1klhy ) ) ; mr_EvPowertrainController2EM_cacheDataAsMxArray ( rtdwData ,
0 , 11 , ( const void * ) & ( mdlrefDW -> rtdw . nkr00y3cul ) , sizeof (
mdlrefDW -> rtdw . nkr00y3cul ) ) ;
mr_EvPowertrainController2EM_cacheDataAsMxArray ( rtdwData , 0 , 12 , ( const
void * ) & ( mdlrefDW -> rtdw . ijcpktnusb ) , sizeof ( mdlrefDW -> rtdw .
ijcpktnusb ) ) ; mr_EvPowertrainController2EM_cacheDataAsMxArray ( rtdwData ,
0 , 13 , ( const void * ) & ( mdlrefDW -> rtdw . fbivvkkxil ) , sizeof (
mdlrefDW -> rtdw . fbivvkkxil ) ) ;
mr_EvPowertrainController2EM_cacheDataAsMxArray ( rtdwData , 0 , 14 , ( const
void * ) & ( mdlrefDW -> rtdw . gqk1jf1ek0 ) , sizeof ( mdlrefDW -> rtdw .
gqk1jf1ek0 ) ) ; mr_EvPowertrainController2EM_cacheDataAsMxArray ( rtdwData ,
0 , 15 , ( const void * ) & ( mdlrefDW -> rtdw . nqv3ows0gj ) , sizeof (
mdlrefDW -> rtdw . nqv3ows0gj ) ) ;
mr_EvPowertrainController2EM_cacheDataAsMxArray ( rtdwData , 0 , 16 , ( const
void * ) & ( mdlrefDW -> rtdw . j3gtt2mnys ) , sizeof ( mdlrefDW -> rtdw .
j3gtt2mnys ) ) ; mr_EvPowertrainController2EM_cacheDataAsMxArray ( rtdwData ,
0 , 17 , ( const void * ) & ( mdlrefDW -> rtdw . mfbmya0nxt ) , sizeof (
mdlrefDW -> rtdw . mfbmya0nxt ) ) ;
mr_EvPowertrainController2EM_cacheDataAsMxArray ( rtdwData , 0 , 18 , ( const
void * ) & ( mdlrefDW -> rtdw . nx0zq5arfp ) , sizeof ( mdlrefDW -> rtdw .
nx0zq5arfp ) ) ; mxSetFieldByNumber ( ssDW , 0 , 1 , rtdwData ) ; } ( void )
mdlrefDW ; return ssDW ; } void mr_EvPowertrainController2EM_SetDWork (
oaq0dqotmrc * mdlrefDW , const mxArray * ssDW ) { ( void ) ssDW ; ( void )
mdlrefDW ; mr_EvPowertrainController2EM_restoreDataFromMxArray ( ( void * ) &
( mdlrefDW -> rtb ) , ssDW , 0 , 0 , sizeof ( mdlrefDW -> rtb ) ) ; { const
mxArray * rtdwData = mxGetFieldByNumber ( ssDW , 0 , 1 ) ;
mr_EvPowertrainController2EM_restoreDataFromMxArray ( ( void * ) & ( mdlrefDW
-> rtdw . gimarahrpl ) , rtdwData , 0 , 0 , sizeof ( mdlrefDW -> rtdw .
gimarahrpl ) ) ; mr_EvPowertrainController2EM_restoreDataFromMxArray ( ( void
* ) & ( mdlrefDW -> rtdw . glinugelel ) , rtdwData , 0 , 1 , sizeof (
mdlrefDW -> rtdw . glinugelel ) ) ;
mr_EvPowertrainController2EM_restoreDataFromMxArray ( ( void * ) & ( mdlrefDW
-> rtdw . cg13f1zg3e ) , rtdwData , 0 , 2 , sizeof ( mdlrefDW -> rtdw .
cg13f1zg3e ) ) ; mr_EvPowertrainController2EM_restoreDataFromMxArray ( ( void
* ) & ( mdlrefDW -> rtdw . p5p4aaxq51 ) , rtdwData , 0 , 3 , sizeof (
mdlrefDW -> rtdw . p5p4aaxq51 ) ) ;
mr_EvPowertrainController2EM_restoreDataFromMxArray ( ( void * ) & ( mdlrefDW
-> rtdw . mnt5i0lw4q ) , rtdwData , 0 , 4 , sizeof ( mdlrefDW -> rtdw .
mnt5i0lw4q ) ) ; mr_EvPowertrainController2EM_restoreDataFromMxArray ( ( void
* ) & ( mdlrefDW -> rtdw . o5t0xnvnze ) , rtdwData , 0 , 5 , sizeof (
mdlrefDW -> rtdw . o5t0xnvnze ) ) ;
mr_EvPowertrainController2EM_restoreDataFromMxArray ( ( void * ) & ( mdlrefDW
-> rtdw . f12x4t2yjl ) , rtdwData , 0 , 6 , sizeof ( mdlrefDW -> rtdw .
f12x4t2yjl ) ) ; mr_EvPowertrainController2EM_restoreDataFromMxArray ( ( void
* ) & ( mdlrefDW -> rtdw . ow2qkdjqul ) , rtdwData , 0 , 7 , sizeof (
mdlrefDW -> rtdw . ow2qkdjqul ) ) ;
mr_EvPowertrainController2EM_restoreDataFromMxArray ( ( void * ) & ( mdlrefDW
-> rtdw . ns0ekabbmt ) , rtdwData , 0 , 8 , sizeof ( mdlrefDW -> rtdw .
ns0ekabbmt ) ) ; mr_EvPowertrainController2EM_restoreDataFromMxArray ( ( void
* ) & ( mdlrefDW -> rtdw . bnr3irkvs1 ) , rtdwData , 0 , 9 , sizeof (
mdlrefDW -> rtdw . bnr3irkvs1 ) ) ;
mr_EvPowertrainController2EM_restoreDataFromMxArray ( ( void * ) & ( mdlrefDW
-> rtdw . clhfo1klhy ) , rtdwData , 0 , 10 , sizeof ( mdlrefDW -> rtdw .
clhfo1klhy ) ) ; mr_EvPowertrainController2EM_restoreDataFromMxArray ( ( void
* ) & ( mdlrefDW -> rtdw . nkr00y3cul ) , rtdwData , 0 , 11 , sizeof (
mdlrefDW -> rtdw . nkr00y3cul ) ) ;
mr_EvPowertrainController2EM_restoreDataFromMxArray ( ( void * ) & ( mdlrefDW
-> rtdw . ijcpktnusb ) , rtdwData , 0 , 12 , sizeof ( mdlrefDW -> rtdw .
ijcpktnusb ) ) ; mr_EvPowertrainController2EM_restoreDataFromMxArray ( ( void
* ) & ( mdlrefDW -> rtdw . fbivvkkxil ) , rtdwData , 0 , 13 , sizeof (
mdlrefDW -> rtdw . fbivvkkxil ) ) ;
mr_EvPowertrainController2EM_restoreDataFromMxArray ( ( void * ) & ( mdlrefDW
-> rtdw . gqk1jf1ek0 ) , rtdwData , 0 , 14 , sizeof ( mdlrefDW -> rtdw .
gqk1jf1ek0 ) ) ; mr_EvPowertrainController2EM_restoreDataFromMxArray ( ( void
* ) & ( mdlrefDW -> rtdw . nqv3ows0gj ) , rtdwData , 0 , 15 , sizeof (
mdlrefDW -> rtdw . nqv3ows0gj ) ) ;
mr_EvPowertrainController2EM_restoreDataFromMxArray ( ( void * ) & ( mdlrefDW
-> rtdw . j3gtt2mnys ) , rtdwData , 0 , 16 , sizeof ( mdlrefDW -> rtdw .
j3gtt2mnys ) ) ; mr_EvPowertrainController2EM_restoreDataFromMxArray ( ( void
* ) & ( mdlrefDW -> rtdw . mfbmya0nxt ) , rtdwData , 0 , 17 , sizeof (
mdlrefDW -> rtdw . mfbmya0nxt ) ) ;
mr_EvPowertrainController2EM_restoreDataFromMxArray ( ( void * ) & ( mdlrefDW
-> rtdw . nx0zq5arfp ) , rtdwData , 0 , 18 , sizeof ( mdlrefDW -> rtdw .
nx0zq5arfp ) ) ; } } void
mr_EvPowertrainController2EM_RegisterSimStateChecksum ( SimStruct * S ) {
const uint32_T chksum [ 4 ] = { 1990274699U , 2336264357U , 3096985377U ,
3560978485U , } ; slmrModelRefRegisterSimStateChecksum ( S ,
"EvPowertrainController2EM" , & chksum [ 0 ] ) ; } mxArray *
mr_EvPowertrainController2EM_GetSimStateDisallowedBlocks ( ) { return ( NULL
) ; }
#if defined(_MSC_VER)
#pragma warning(disable: 4505) //unreferenced local function has been removed
#endif
