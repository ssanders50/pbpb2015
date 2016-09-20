import FWCore.ParameterSet.Config as cms
import sys

process = cms.Process("FlatCalib")

process.load("FWCore.MessageService.MessageLogger_cfi")
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')
process.load("RecoHI.HiEvtPlaneAlgos.HiEvtPlane_cfi")
process.load("HeavyIonsAnalysis.HiEvtPlaneCalib.hievtplaneflatcalib_cfi")
process.load("RecoHI.HiCentralityAlgos.CentralityBin_cfi")
process.load("CondCore.DBCommon.CondDBCommon_cfi")
process.load('GeneratorInterface.HiGenCommon.HeavyIon_cff')

from Configuration.AlCa.GlobalTag import GlobalTag
process.GlobalTag = GlobalTag(process.GlobalTag, '75X_dataRun2_ExpressHI_v2', '')
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


process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )
process.MessageLogger.cerr.FwkReport.reportEvery=1000

process.source = cms.Source("PoolSource",
                            fileNames = cms.untracked.vstring(        
       'root://cmsxrootd.fnal.gov//store/express/HIRun2015/HIExpressPhysics/FEVT/Express-v1/000/262/548/00000/06B207BA-6093-E511-A930-02163E011D8D.root',
       'root://cmsxrootd.fnal.gov//store/express/HIRun2015/HIExpressPhysics/FEVT/Express-v1/000/262/548/00000/0A494C39-6693-E511-8787-02163E01377B.root',
       'root://cmsxrootd.fnal.gov//store/express/HIRun2015/HIExpressPhysics/FEVT/Express-v1/000/262/548/00000/0AB8E7ED-6A93-E511-AF76-02163E012B58.root',
       'root://cmsxrootd.fnal.gov//store/express/HIRun2015/HIExpressPhysics/FEVT/Express-v1/000/262/548/00000/18C4EDDA-5D93-E511-A185-02163E01474C.root',
       'root://cmsxrootd.fnal.gov//store/express/HIRun2015/HIExpressPhysics/FEVT/Express-v1/000/262/548/00000/1C6CAEB2-6493-E511-8B19-02163E01447F.root',
       'root://cmsxrootd.fnal.gov//store/express/HIRun2015/HIExpressPhysics/FEVT/Express-v1/000/262/548/00000/2075EC3A-6E93-E511-99D7-02163E01457B.root',
       'root://cmsxrootd.fnal.gov//store/express/HIRun2015/HIExpressPhysics/FEVT/Express-v1/000/262/548/00000/22B7295C-6293-E511-86BD-02163E011802.root',
       'root://cmsxrootd.fnal.gov//store/express/HIRun2015/HIExpressPhysics/FEVT/Express-v1/000/262/548/00000/2637DCB6-6793-E511-85F9-02163E0145DD.root',
       'root://cmsxrootd.fnal.gov//store/express/HIRun2015/HIExpressPhysics/FEVT/Express-v1/000/262/548/00000/2A727AF9-6A93-E511-83DC-02163E014353.root',
       'root://cmsxrootd.fnal.gov//store/express/HIRun2015/HIExpressPhysics/FEVT/Express-v1/000/262/548/00000/34D797B8-6093-E511-832F-02163E013945.root',
       'root://cmsxrootd.fnal.gov//store/express/HIRun2015/HIExpressPhysics/FEVT/Express-v1/000/262/548/00000/661937CE-6E93-E511-8551-02163E0143DA.root',
       'root://cmsxrootd.fnal.gov//store/express/HIRun2015/HIExpressPhysics/FEVT/Express-v1/000/262/548/00000/66AD34BE-6093-E511-B605-02163E012732.root',
       'root://cmsxrootd.fnal.gov//store/express/HIRun2015/HIExpressPhysics/FEVT/Express-v1/000/262/548/00000/6A3F15DC-5D93-E511-8FF4-02163E014699.root',
       'root://cmsxrootd.fnal.gov//store/express/HIRun2015/HIExpressPhysics/FEVT/Express-v1/000/262/548/00000/701CA1C6-6D93-E511-8D35-02163E014544.root',
       'root://cmsxrootd.fnal.gov//store/express/HIRun2015/HIExpressPhysics/FEVT/Express-v1/000/262/548/00000/7C3527BB-6493-E511-9336-02163E012385.root',
       'root://cmsxrootd.fnal.gov//store/express/HIRun2015/HIExpressPhysics/FEVT/Express-v1/000/262/548/00000/7CD555F5-6A93-E511-9680-02163E0142E0.root',
       'root://cmsxrootd.fnal.gov//store/express/HIRun2015/HIExpressPhysics/FEVT/Express-v1/000/262/548/00000/823E70B8-6493-E511-B23E-02163E0133E6.root',
       'root://cmsxrootd.fnal.gov//store/express/HIRun2015/HIExpressPhysics/FEVT/Express-v1/000/262/548/00000/88629DD9-6E93-E511-BE8E-02163E01464F.root',
       'root://cmsxrootd.fnal.gov//store/express/HIRun2015/HIExpressPhysics/FEVT/Express-v1/000/262/548/00000/8AD2F9CF-6D93-E511-97FD-02163E013626.root',
       'root://cmsxrootd.fnal.gov//store/express/HIRun2015/HIExpressPhysics/FEVT/Express-v1/000/262/548/00000/9CD5AA51-6293-E511-B685-02163E0142A4.root',
       'root://cmsxrootd.fnal.gov//store/express/HIRun2015/HIExpressPhysics/FEVT/Express-v1/000/262/548/00000/9E8CFBBC-6093-E511-903E-02163E0145F9.root',
       'root://cmsxrootd.fnal.gov//store/express/HIRun2015/HIExpressPhysics/FEVT/Express-v1/000/262/548/00000/C27AC9DF-5D93-E511-BE9E-02163E014208.root',
       'root://cmsxrootd.fnal.gov//store/express/HIRun2015/HIExpressPhysics/FEVT/Express-v1/000/262/548/00000/C2FC9ECE-5D93-E511-8651-02163E01371F.root',
       'root://cmsxrootd.fnal.gov//store/express/HIRun2015/HIExpressPhysics/FEVT/Express-v1/000/262/548/00000/C654D8C8-6493-E511-ADAE-02163E011E27.root',
       'root://cmsxrootd.fnal.gov//store/express/HIRun2015/HIExpressPhysics/FEVT/Express-v1/000/262/548/00000/C86CF93B-6693-E511-8A9B-02163E011C7C.root',
       'root://cmsxrootd.fnal.gov//store/express/HIRun2015/HIExpressPhysics/FEVT/Express-v1/000/262/548/00000/CC6962D5-5D93-E511-9158-02163E01418A.root',
       'root://cmsxrootd.fnal.gov//store/express/HIRun2015/HIExpressPhysics/FEVT/Express-v1/000/262/548/00000/CED447AB-6793-E511-A4E4-02163E013515.root',
       'root://cmsxrootd.fnal.gov//store/express/HIRun2015/HIExpressPhysics/FEVT/Express-v1/000/262/548/00000/D009D2F0-6A93-E511-82FF-02163E014422.root',
       'root://cmsxrootd.fnal.gov//store/express/HIRun2015/HIExpressPhysics/FEVT/Express-v1/000/262/548/00000/DC45A14C-6693-E511-B1CF-02163E01229E.root',
       'root://cmsxrootd.fnal.gov//store/express/HIRun2015/HIExpressPhysics/FEVT/Express-v1/000/262/548/00000/E2CCAEE2-5D93-E511-889A-02163E011EBE.root',
       'root://cmsxrootd.fnal.gov//store/express/HIRun2015/HIExpressPhysics/FEVT/Express-v1/000/262/548/00000/F831BFBB-6793-E511-9B16-02163E01371D.root',
       'root://cmsxrootd.fnal.gov//store/express/HIRun2015/HIExpressPhysics/FEVT/Express-v1/000/262/548/00000/FCBD965E-6293-E511-B9A2-02163E01463B.root'
        ),
                            inputCommands=cms.untracked.vstring(
        'keep *',
        )

)

import HLTrigger.HLTfilters.hltHighLevel_cfi
process.minBias = HLTrigger.HLTfilters.hltHighLevel_cfi.hltHighLevel.clone()
process.minBias.HLTPaths = [
    "HLT_HIL1MinimumBiasHF1ANDExpress_v1"
]
process.source.duplicateCheckMode = cms.untracked.string('noDuplicateCheck')


process.TFileService = cms.Service("TFileService",
    fileName = cms.string("rpflat.root")
)

process.dump = cms.EDAnalyzer("EventContentAnalyzer")

process.hiEvtPlane.loadDB_ = cms.bool(True)
process.hiEvtPlaneFlatCalib.genFlatPsi_ = cms.untracked.bool(True)
process.p = cms.Path(process.minBias*process.centralityBin* process.hiEvtPlane * process.hiEvtPlaneFlatCalib)



                        

