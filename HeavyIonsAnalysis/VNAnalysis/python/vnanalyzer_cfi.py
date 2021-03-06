import FWCore.ParameterSet.Config as cms

vnanalyzer = cms.EDAnalyzer("VNAnalyzer",
                            vertexTag_=cms.InputTag("hiSelectedVertex"),
                            centralityTag_=cms.InputTag("hiCentrality"),
                            inputPlanesTag_ = cms.InputTag("hiEvtPlaneFlat"),
                            centralityBinTag_ = cms.InputTag("centralityBin","HFtowers"),
                            pfTag = cms.untracked.InputTag("particleFlowTmp"),
                            centralityVariable = cms.string("HFtowers"),
                            nonDefaultGlauberModel = cms.string(""),
                            EPOrder_ = cms.untracked.int32(2),
                            FlatOrder_ = cms.untracked.int32(9),
                            NumFlatBins_ = cms.untracked.int32(40),
                            caloCentRef_ = cms.untracked.double(80.),
                            caloCentRefWidth_ = cms.untracked.double(5.0),
                            CentBinCompression_ = cms.untracked.int32(5),
                            trackTag_=cms.InputTag("hiGeneralTracks"),
                            Noffmin_ = cms.untracked.int32 (-1),
                            Noffmax_ = cms.untracked.int32 (12000),
                            minrun_ = cms.untracked.int32(262500),
                            maxrun_ = cms.untracked.int32(264000),
                            minvtx_ = cms.untracked.double(-20.0),
                            maxvtx_ = cms.untracked.double(20.0),
                            effTable_ = cms.string(''),
                            reso = cms.untracked.double(0.2),
                            bCaloMatching = cms.untracked.bool(True),
                            nvtx_ = cms.untracked.int32(100),
                            minvz_ = cms.untracked.double(-15.),
                            maxvz_ = cms.untracked.double(15.),
                            dzdzerror_ = cms.untracked.double(3.0),
                            d0d0error_ = cms.untracked.double(3.0),
                            pterror_ = cms.untracked.double(0.1),
                            MB_ = cms.untracked.bool(True)
 )
