import FWCore.ParameterSet.Config as cms
import sys

process = cms.Process("FlatCalib")

process.load("FWCore.MessageService.MessageLogger_cfi")
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')
process.load("RecoHI.HiEvtPlaneAlgos.HiEvtPlane_cfi")
process.load("RecoHI.HiEvtPlaneAlgos.hiEvtPlaneFlat_cfi")
process.load("HeavyIonsAnalysis.HiEvtPlaneCalib/checkflattening_cfi")
process.load("RecoHI.HiCentralityAlgos.CentralityBin_cfi")
process.load("CondCore.DBCommon.CondDBCommon_cfi")
process.load('GeneratorInterface.HiGenCommon.HeavyIon_cff')
process.load("HeavyIonsAnalysis.Configuration.hfCoincFilter_cff")
process.load("HeavyIonsAnalysis.Configuration.analysisFilters_cff")
process.load("HeavyIonsAnalysis.Configuration.collisionEventSelection_cff")

from Configuration.AlCa.GlobalTag import GlobalTag
process.GlobalTag = GlobalTag(process.GlobalTag, '75X_dataRun2_v13', '')
process.GlobalTag.snapshotTime = cms.string("9999-12-31 23:59:59.000")


process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )
process.MessageLogger.cerr.FwkReport.reportEvery=1000

process.CondDBCommon.connect = "sqlite_file:HeavyIonRPRcd_75x_v01_offline.db"
process.PoolDBESSource = cms.ESSource("PoolDBESSource",
                                       process.CondDBCommon,
                                       toGet = cms.VPSet(cms.PSet(record = cms.string('HeavyIonRPRcd'),
                                                                  tag = cms.string('HeavyIonRPRcd_75x_v01_offline')
                                                                  )
                                                         )
                                      )
process.es_prefer_flatparms = cms.ESPrefer('PoolDBESSource','')


import FWCore.PythonUtilities.LumiList as LumiList
goodLumiSecs = LumiList.LumiList(filename = 'Cert_262548-263757_PromptReco_HICollisions15_JSON.txt').getCMSSWString().split(',')

readFiles = cms.untracked.vstring()
secFiles = cms.untracked.vstring() 

process.source = cms.Source ("PoolSource",fileNames = cms.untracked.vstring(),
                             inputCommands=cms.untracked.vstring(
        'keep *',
        'drop *_hiEvtPlane_*_*'
)
 )

process.TFileService = cms.Service("TFileService",
    fileName = cms.string("check.root")
)

import HLTrigger.HLTfilters.hltHighLevel_cfi
process.minBias = HLTrigger.HLTfilters.hltHighLevel_cfi.hltHighLevel.clone()
process.minBias.HLTPaths = [
                "HLT_HIL1MinimumBiasHF1AND_*",
                "HLT_HIL1MinimumBiasHF2AND_*"
]

process.dump = cms.EDAnalyzer("EventContentAnalyzer")

process.hiEvtPlane.loadDB = cms.bool(True)
process.p = cms.Path(process.minBias*process.hfCoincFilter3*process.primaryVertexFilter*process.centralityBin*process.hiEvtPlane*process.hiEvtPlaneFlat*process.checkflattening)



                        

