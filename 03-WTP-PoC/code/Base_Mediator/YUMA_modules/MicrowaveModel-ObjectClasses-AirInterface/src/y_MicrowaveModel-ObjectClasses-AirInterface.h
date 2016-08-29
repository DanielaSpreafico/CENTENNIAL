
#ifndef _H_y_MicrowaveModel_ObjectClasses_AirInterface
#define _H_y_MicrowaveModel_ObjectClasses_AirInterface
/* 
 * Copyright (c) 2008-2012, Andy Bierman, All Rights Reserved.
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 *

*** Generated by yangdump 2.5-5

    Yuma SIL header
    module MicrowaveModel-ObjectClasses-AirInterface
    revision 2016-08-29
    namespace uri:onf:MicrowaveModel-ObjectClasses-AirInterface
    organization ONF (Open Networking Foundation) Open Transport Working Group - Wireless Transport Project

 */

#include <xmlstring.h>

#include "dlq.h"
#include "ncxtypes.h"
#include "op.h"
#include "status.h"
#include "val.h"

#ifdef __cplusplus
extern "C" {
#endif

#define y_MicrowaveModel_ObjectClasses_AirInterface_M_MicrowaveModel_ObjectClasses_AirInterface (const xmlChar *)"MicrowaveModel-ObjectClasses-AirInterface"
#define y_MicrowaveModel_ObjectClasses_AirInterface_R_MicrowaveModel_ObjectClasses_AirInterface (const xmlChar *)"2016-08-29"

#define y_MicrowaveModel_ObjectClasses_AirInterface_N_CoChannelGroup (const xmlChar *)"CoChannelGroup"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_MW_AirInterface_Pac (const xmlChar *)"MW_AirInterface_Pac"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_adaptiveModulationIsAvail (const xmlChar *)"adaptiveModulationIsAvail"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_adaptiveModulationIsOn (const xmlChar *)"adaptiveModulationIsOn"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_administrativeState (const xmlChar *)"administrativeState"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_airInterfaceCapability (const xmlChar *)"airInterfaceCapability"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_airInterfaceConfiguration (const xmlChar *)"airInterfaceConfiguration"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_airInterfaceCurrentPerformance (const xmlChar *)"airInterfaceCurrentPerformance"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_airInterfaceCurrentProblems (const xmlChar *)"airInterfaceCurrentProblems"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_airInterfaceHistoricalPerformances (const xmlChar *)"airInterfaceHistoricalPerformances"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_airInterfaceList (const xmlChar *)"airInterfaceList"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_airInterfaceName (const xmlChar *)"airInterfaceName"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_airInterfaceStatus (const xmlChar *)"airInterfaceStatus"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_alicIsAvail (const xmlChar *)"alicIsAvail"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_alicIsOn (const xmlChar *)"alicIsOn"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_alicIsUp (const xmlChar *)"alicIsUp"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_amDownshiftLevel (const xmlChar *)"amDownshiftLevel"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_amUpshiftLevel (const xmlChar *)"amUpshiftLevel"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_atpcIsAvail (const xmlChar *)"atpcIsAvail"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_atpcIsOn (const xmlChar *)"atpcIsOn"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_atpcIsUp (const xmlChar *)"atpcIsUp"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_atpcRange (const xmlChar *)"atpcRange"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_atpcThreshLower (const xmlChar *)"atpcThreshLower"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_atpcThreshUpper (const xmlChar *)"atpcThreshUpper"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_autoFreqSelectIsAvail (const xmlChar *)"autoFreqSelectIsAvail"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_autoFreqSelectIsOn (const xmlChar *)"autoFreqSelectIsOn"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_autoFreqSelectIsUp (const xmlChar *)"autoFreqSelectIsUp"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_autoFreqSelectRange (const xmlChar *)"autoFreqSelectRange"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_channelBandwidth (const xmlChar *)"channelBandwidth"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_coChannelGroupId (const xmlChar *)"coChannelGroupId"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_cryptographicKey (const xmlChar *)"cryptographicKey"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_cses (const xmlChar *)"cses"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_currentPerformanceData (const xmlChar *)"currentPerformanceData"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_currentProblemList (const xmlChar *)"currentProblemList"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_defectBlocksSum (const xmlChar *)"defectBlocksSum"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_duplexDistance (const xmlChar *)"duplexDistance"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_duplexDistanceIsVariable (const xmlChar *)"duplexDistanceIsVariable"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_elapsedTime (const xmlChar *)"elapsedTime"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_encryptionIsAvail (const xmlChar *)"encryptionIsAvail"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_encryptionIsOn (const xmlChar *)"encryptionIsOn"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_es (const xmlChar *)"es"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_granularityPeriod (const xmlChar *)"granularityPeriod"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_historicalPerformanceDataList (const xmlChar *)"historicalPerformanceDataList"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_historyDataId (const xmlChar *)"historyDataId"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_informationRate (const xmlChar *)"informationRate"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_informationRateCur (const xmlChar *)"informationRateCur"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_lastStatusChange (const xmlChar *)"lastStatusChange"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_layerProtocol (const xmlChar *)"layerProtocol"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_linkIsUp (const xmlChar *)"linkIsUp"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_localEndPointId (const xmlChar *)"localEndPointId"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_loopBackIsAvail (const xmlChar *)"loopBackIsAvail"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_loopBackIsOn (const xmlChar *)"loopBackIsOn"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_loopBackIsUp (const xmlChar *)"loopBackIsUp"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_maintenanceTimer (const xmlChar *)"maintenanceTimer"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_maintenanceTimerRange (const xmlChar *)"maintenanceTimerRange"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_mimoChannels (const xmlChar *)"mimoChannels"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_mimoIsAvail (const xmlChar *)"mimoIsAvail"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_mimoIsOn (const xmlChar *)"mimoIsOn"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_mimoIsUp (const xmlChar *)"mimoIsUp"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_modulationCur (const xmlChar *)"modulationCur"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_modulationIsOn (const xmlChar *)"modulationIsOn"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_modulationMax (const xmlChar *)"modulationMax"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_modulationMin (const xmlChar *)"modulationMin"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_modulationScheme (const xmlChar *)"modulationScheme"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_nameBinding (const xmlChar *)"nameBinding"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_objectClass (const xmlChar *)"objectClass"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_performanceData (const xmlChar *)"performanceData"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_periodEndTime (const xmlChar *)"periodEndTime"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_polarization (const xmlChar *)"polarization"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_powerIsOn (const xmlChar *)"powerIsOn"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_problemKindName (const xmlChar *)"problemKindName"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_problemKindSeverity (const xmlChar *)"problemKindSeverity"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_problemKindSeverityList (const xmlChar *)"problemKindSeverityList"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_problemName (const xmlChar *)"problemName"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_problemSeverity (const xmlChar *)"problemSeverity"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_radioPowerIsUp (const xmlChar *)"radioPowerIsUp"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_radioSignalID (const xmlChar *)"radioSignalID"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_receiverIsOn (const xmlChar *)"receiverIsOn"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_remoteEndPointId (const xmlChar *)"remoteEndPointId"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_rfTempAvg (const xmlChar *)"rfTempAvg"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_rfTempCur (const xmlChar *)"rfTempCur"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_rfTempMax (const xmlChar *)"rfTempMax"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_rfTempMin (const xmlChar *)"rfTempMin"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_rxChannelBandwidth (const xmlChar *)"rxChannelBandwidth"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_rxFrequency (const xmlChar *)"rxFrequency"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_rxFrequencyCur (const xmlChar *)"rxFrequencyCur"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_rxFrequencyMax (const xmlChar *)"rxFrequencyMax"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_rxFrequencyMin (const xmlChar *)"rxFrequencyMin"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_rxLevelAvg (const xmlChar *)"rxLevelAvg"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_rxLevelCur (const xmlChar *)"rxLevelCur"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_rxLevelMax (const xmlChar *)"rxLevelMax"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_rxLevelMin (const xmlChar *)"rxLevelMin"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_rxThreshold (const xmlChar *)"rxThreshold"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_scannerId (const xmlChar *)"scannerId"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_sequenceNumber (const xmlChar *)"sequenceNumber"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_ses (const xmlChar *)"ses"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_snirAvg (const xmlChar *)"snirAvg"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_snirCur (const xmlChar *)"snirCur"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_snirMax (const xmlChar *)"snirMax"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_snirMin (const xmlChar *)"snirMin"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_sortOfCoChannelGroup (const xmlChar *)"sortOfCoChannelGroup"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_supportedAlarms (const xmlChar *)"supportedAlarms"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_supportedChannelPlan (const xmlChar *)"supportedChannelPlan"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_supportedChannelPlanList (const xmlChar *)"supportedChannelPlanList"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_suspectIntervalFlag (const xmlChar *)"suspectIntervalFlag"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_time1024Symbols (const xmlChar *)"time1024Symbols"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_time1024SymbolsL (const xmlChar *)"time1024SymbolsL"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_time128Symbols (const xmlChar *)"time128Symbols"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_time16Symbols (const xmlChar *)"time16Symbols"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_time16SymbolsS (const xmlChar *)"time16SymbolsS"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_time2048Symbols (const xmlChar *)"time2048Symbols"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_time2048SymbolsL (const xmlChar *)"time2048SymbolsL"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_time256Symbols (const xmlChar *)"time256Symbols"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_time2Symbols (const xmlChar *)"time2Symbols"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_time32Symbols (const xmlChar *)"time32Symbols"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_time4096Symbols (const xmlChar *)"time4096Symbols"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_time4096SymbolsL (const xmlChar *)"time4096SymbolsL"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_time4Symbols (const xmlChar *)"time4Symbols"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_time4SymbolsS (const xmlChar *)"time4SymbolsS"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_time512Symbols (const xmlChar *)"time512Symbols"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_time512SymbolsL (const xmlChar *)"time512SymbolsL"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_time64Symbols (const xmlChar *)"time64Symbols"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_time8192Symbols (const xmlChar *)"time8192Symbols"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_time8192SymbolsL (const xmlChar *)"time8192SymbolsL"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_time8Symbols (const xmlChar *)"time8Symbols"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_timePeriod (const xmlChar *)"timePeriod"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_timeStamp (const xmlChar *)"timeStamp"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_timestamp (const xmlChar *)"timestamp"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_transmissionModeId (const xmlChar *)"transmissionModeId"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_transmissionModeList (const xmlChar *)"transmissionModeList"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_transmitterIsOn (const xmlChar *)"transmitterIsOn"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_txChannelBandwidth (const xmlChar *)"txChannelBandwidth"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_txFrequency (const xmlChar *)"txFrequency"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_txFrequencyCur (const xmlChar *)"txFrequencyCur"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_txFrequencyMax (const xmlChar *)"txFrequencyMax"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_txFrequencyMin (const xmlChar *)"txFrequencyMin"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_txLevelAvg (const xmlChar *)"txLevelAvg"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_txLevelCur (const xmlChar *)"txLevelCur"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_txLevelMax (const xmlChar *)"txLevelMax"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_txLevelMin (const xmlChar *)"txLevelMin"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_txPower (const xmlChar *)"txPower"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_txPowerMax (const xmlChar *)"txPowerMax"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_txPowerMin (const xmlChar *)"txPowerMin"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_typeOfEquipment (const xmlChar *)"typeOfEquipment"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_unavailability (const xmlChar *)"unavailability"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_xpdAvg (const xmlChar *)"xpdAvg"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_xpdCur (const xmlChar *)"xpdCur"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_xpdMax (const xmlChar *)"xpdMax"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_xpdMin (const xmlChar *)"xpdMin"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_xpicIsAvail (const xmlChar *)"xpicIsAvail"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_xpicIsOn (const xmlChar *)"xpicIsOn"
#define y_MicrowaveModel_ObjectClasses_AirInterface_N_xpicIsUp (const xmlChar *)"xpicIsUp"
/********************************************************************
* FUNCTION y_MicrowaveModel_ObjectClasses_AirInterface_init
* 
* initialize the MicrowaveModel-ObjectClasses-AirInterface server instrumentation library
* 
* INPUTS:
*    modname == requested module name
*    revision == requested version (NULL for any)
* 
* RETURNS:
*     error status
********************************************************************/
extern status_t y_MicrowaveModel_ObjectClasses_AirInterface_init (
    const xmlChar *modname,
    const xmlChar *revision);

/********************************************************************
* FUNCTION y_MicrowaveModel_ObjectClasses_AirInterface_init2
* 
* SIL init phase 2: non-config data structures
* Called after running config is loaded
* 
* RETURNS:
*     error status
********************************************************************/
extern status_t y_MicrowaveModel_ObjectClasses_AirInterface_init2 (void);

/********************************************************************
* FUNCTION y_MicrowaveModel_ObjectClasses_AirInterface_cleanup
*    cleanup the server instrumentation library
* 
********************************************************************/
extern void y_MicrowaveModel_ObjectClasses_AirInterface_cleanup (void);

status_t MicrowaveModel_ObjectClasses_AirInterface_MW_AirInterface_Pac_airInterfaceStatus_mro (val_value_t *parentval);
status_t MicrowaveModel_ObjectClasses_AirInterface_MW_AirInterface_Pac_airInterfaceCurrentPerformance_mro (val_value_t *parentval);


#ifdef __cplusplus
} /* end extern 'C' */
#endif

#endif