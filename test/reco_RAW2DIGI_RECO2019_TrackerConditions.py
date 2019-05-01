# Auto generated configuration file
# using:
# Revision: 1.19
# Source: /local/reps/CMSSW/CMSSW/Configuration/Applications/python/ConfigBuilder.py,v
# with command line options: reco -s RAW2DIGI,L1Reco,RECO,RECOSIM,EI,PAT -n 100 --filein=/store/data/Run2018A/EGamma/RAW-RECO/ZElectron-PromptReco-v1/000/315/488/00000/44D99B63-AA4E-E811-855D-FA163EC6FA1A.root --data --conditions=101X_dataRun2_Prompt_v9 --era Run2_2018 --runUnscheduled --nThreads=4
import FWCore.ParameterSet.Config as cms

from Configuration.StandardSequences.Eras import eras

#process = cms.Process('SuperRECO',eras.Run2_2018)

process = cms.Process('EcalAlignment', eras.Run2_2018)

# manage input variables
from FWCore.ParameterSet.VarParsing import VarParsing
options = VarParsing ('analysis')
# add a list of strings for events to process
process.options = cms.untracked.PSet(wantSummary = cms.untracked.bool(True))
#process.options = cms.untracked.PSet( allowUnscheduled = cms.untracked.bool(True) )

options.parseArguments()

process.load('Configuration.StandardSequences.L1Reco_cff')
process.load("RecoVertex.BeamSpotProducer.BeamSpot_cff")

# import of standard configurations
process.load('Configuration.StandardSequences.Services_cff')
process.load('SimGeneral.HepPDTESSource.pythiapdt_cfi')
process.load('FWCore.MessageService.MessageLogger_cfi')
process.load('Configuration.EventContent.EventContent_cff')
process.load('Configuration.StandardSequences.GeometryRecoDB_cff')
process.load('Configuration.StandardSequences.MagneticField_AutoFromDBCurrent_cff')
process.load('Configuration.StandardSequences.RawToDigi_Data_cff')
#process.load('Configuration.StandardSequences.L1Reco_cff')
process.load('Configuration.StandardSequences.Reconstruction_Data_cff')
#process.load('Configuration.StandardSequences.RecoSim_cff')
#process.load('CommonTools.ParticleFlow.EITopPAG_cff')
#process.load('PhysicsTools.PatAlgos.slimming.metFilterPaths_cff')
#process.load('Configuration.StandardSequences.PAT_cff')
process.load('Configuration.StandardSequences.EndOfProcess_cff')
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(10)
)

# Input source
process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring('/store/data/Run2017F/DoubleEG/RAW-RECO/ZElectron-09May2018-v1/80005/48DF7EE7-1360-E811-985D-FA163EB82297.root'),
    secondaryFileNames = cms.untracked.vstring()
)

process.options = cms.untracked.PSet(

)

# Production Info
process.configurationMetadata = cms.untracked.PSet(
    annotation = cms.untracked.string('reco nevts:100'),
    name = cms.untracked.string('Applications'),
    version = cms.untracked.string('$Revision: 1.19 $')
)

# Output definition

process.RECOSIMoutput = cms.OutputModule("PoolOutputModule",
    dataset = cms.untracked.PSet(
        dataTier = cms.untracked.string(''),
        filterName = cms.untracked.string('')
    ),
    fileName = cms.untracked.string('reco_RAW2DIGI_RECO.root'),
                                         #outputCommands = process.RECOSIMEventContent.outputCommands,
     outputCommands= cms.untracked.vstring("drop *"),
    splitLevel = cms.untracked.int32(0)
)

# Additional output definition

# Other statements
from Configuration.AlCa.GlobalTag import GlobalTag
#process.GlobalTag = GlobalTag(process.GlobalTag, '101X_dataRun2_Prompt_v9', '')
#process.GlobalTag = GlobalTag(process.GlobalTag, '101X_dataRun2_Prompt_v10', '')
# process.GlobalTag = GlobalTag(process.GlobalTag, '101X_dataRun2_Prompt_v11', '')
#process.GlobalTag = GlobalTag(process.GlobalTag, '101X_dataRun2_Prompt_v11','')
process.GlobalTag = GlobalTag(process.GlobalTag, '106X_dataRun2_trackerAlignment2017_v1', '')

process.GlobalTag.toGet = cms.VPSet(


#                                     cms.PSet(record = cms.string("EEAlignmentRcd"),
#                                     tag = cms.string("EEAlignment_measured_v05_offline"),
# # #                                    connect = cms.string("sqlite_file:EEAlign_2018_postJun4_repriseJul12.db")
# # #                                    connect = cms.string("sqlite_file:EEAlign_2018_postJun4_repriseJul9.db")
# #                                              #connect = cms.string("sqlite_file:EEAlign_2018_25May_check.db")
# # #                                    connect = cms.string("sqlite_file:EEAlign_2018_3Jun_newselections_onlyphion.db")
# #                                      connect = cms.string("sqlite_file:EEAlign_2018_postJun4_repriseJul12_angleson.db")
#                                     #connect = cms.string("sqlite_file:EEAlign_2018_6May.db")
#                                     connect = cms.string("sqlite_file:EEAlign_2018_test.db")
#                                     ),
#
#
#                                     cms.PSet(record = cms.string("EBAlignmentRcd"),
#                                     tag = cms.string("EBAlignment_measured_v05_offline"),
#                                     #connect = cms.string("sqlite_file:EBAlign_2018_6May.db")
#                                     connect = cms.string("sqlite_file:EBAlign_2018_test.db")
# #                                    # connect = cms.string("sqlite_file:EBAlign_2018_postJun4_repriseJul12.db")
# #  #                                   connect = cms.string("sqlite_file:EBAlign_2018_postJun4_repriseJul9.db")
# #   #                                  connect = cms.string("sqlite_file:EBAlign_2018_3Jun_newselections.db")
# #                                     connect = cms.string("sqlite_file:EBAlign_2018_postJun4_repriseJul12_angleson.db")
#                                              ),

#                                     cms.PSet(record = cms.string("TkAlignmentRcd"),
#                                     tag = cms.string("TrackerAlignment_SummerCamp2018_testRunB"),
#                                     #connect = cms.string("sqlite_file:EBAlign_2018_6May.db")
#                                     connect = cms.string("sqlite_file:EBAlign_2018_test.db")
# #                                    # connect = cms.string("sqlite_file:EBAlign_2018_postJun4_repriseJul12.db")
# #  #                                   connect = cms.string("sqlite_file:EBAlign_2018_postJun4_repriseJul9.db")
# #   #                                  connect = cms.string("sqlite_file:EBAlign_2018_3Jun_newselections.db")
# #                                     connect = cms.string("sqlite_file:EBAlign_2018_postJun4_repriseJul12_angleson.db")
#                                              ),
                                    cms.PSet(record = cms.string("EcalPedestalsRcd"),
                                    tag = cms.string("EcalPedestals_timestamp_UltraLegacy_2017_v1"),
                                    connect = cms.string("frontier://FrontierProd/CMS_CONDITIONS")
                                             ),
                                   cms.PSet(record = cms.string("EcalPulseShapesRcd"),
                                   tag = cms.string("EcalPulseShapes_UltraLegacy2017_calib"),
                                   connect = cms.string("frontier://FrontierProd/CMS_CONDITIONS")
                                                ),
                                   cms.PSet(record = cms.string("EcalLaserAPDPNRatiosRcd"),
                                   tag = cms.string("EcalLaserAPDPNRatios_rereco2017_v3"),
                                   connect = cms.string("frontier://FrontierProd/CMS_CONDITIONS")
                                                ),
                                   cms.PSet(record = cms.string("EcalLaserAlphasRcd"),
                                   tag = cms.string("EcalLaserAlphas_EB152-150_EE116_107_SICoptimized17"),
                                   connect = cms.string("frontier://FrontierProd/CMS_CONDITIONS")
                                               ),
                                   cms.PSet(record = cms.string("EcalPFRecHitThresholdsRcd"),
                                   tag = cms.string("EcalPFRecHitThresholds_UL_2017_mc_v2_mixedsigmas"),
                                   connect = cms.string("frontier://FrontierProd/CMS_CONDITIONS")
                                               ),
                                   cms.PSet(record = cms.string("TrackerAlignmentRcd"),
                                   tag = cms.string("TrackerAlignment_2017_ultralegacy_v1"),
                                   connect = cms.string("frontier://FrontierProd/CMS_CONDITIONS")
                                               ),
                                    cms.PSet(record = cms.string("TrackerAlignmentErrorExtendedRcd"),
                                    tag = cms.string("TrackerAlignmentExtendedErrors_2017_ultralegacy_v1"),
                                    connect = cms.string("frontier://FrontierProd/CMS_CONDITIONS")
                                                ),
                                    cms.PSet(record = cms.string("TrackerSurfaceDeformationRcd"),
                                    tag = cms.string("TrackerSurfaceDeformations_2017_ultralegacy_v1"),
                                    connect = cms.string("frontier://FrontierProd/CMS_CONDITIONS")
                                                ),
                                    cms.PSet(record = cms.string("SiPixelTemplateDBObjectRcd"),
                                    tag = cms.string("SiPixelTemplateDBObject_38T_v15_offline"),
                                    connect = cms.string("frontier://FrontierProd/CMS_CONDITIONS")
                                                ),
                                    cms.PSet(record = cms.string("SiPixelLorentzAngleRcd"),
                                    tag = cms.string("SiPixelLorentzAngle_v11_offline"),
                                    connect = cms.string("frontier://FrontierProd/CMS_CONDITIONS")
                                                ),
                                    cms.PSet(record = cms.string("SiPixelGenErrorDBObjectRcd"),
                                    tag = cms.string("SiPixelGenErrorDBObject_38T_v9_offline"),
                                    connect = cms.string("frontier://FrontierProd/CMS_CONDITIONS")
                                                ),
                                    cms.PSet(record = cms.string("SiPixel2DTemplateDBObjectRcd"),
                                    tag = cms.string("SiPixel2DTemplateDBObject_38T_v2_offline"),
                                    connect = cms.string("frontier://FrontierProd/CMS_CONDITIONS")
                                                )                                          

)
# process.GlobalTag.toGet = cms.VPSet(
#
#
#                                     cms.PSet(record = cms.string("EEAlignmentRcd"),
#                                     tag = cms.string("EEAlignment_measured_v05_offline"),
#                                     connect = cms.string("sqlite_file:EEAlign_2018_6May.db")
#                                              #connect = cms.string("sqlite_file:EEAlign_2018_25May_check.db")
# #                                    connect = cms.string("sqlite_file:EEAlign_2018_3Jun_newselections_onlyphion.db")
#                                     ),
#
#
#                                     cms.PSet(record = cms.string("EBAlignmentRcd"),
#                                     tag = cms.string("EBAlignment_measured_v05_offline"),
#                                     connect = cms.string("sqlite_file:EBAlign_2018_6May.db")
#   #                                  connect = cms.string("sqlite_file:EBAlign_2018_3Jun_newselections.db")
#                                              ),
#
#
#                                     #EcalPedestals_Legacy2017_time_v1
#                                     #EcalPulseShapes_October2017_rereco_v1
#
# )
# process.GlobalTag.toGet = cms.VPSet(
#
#
#                                     cms.PSet(record = cms.string("EEAlignmentRcd"),
#                                     tag = cms.string("EEAlignment_measured_v05_offline"),
#                                     connect = cms.string("sqlite_file:EEAlign_2018_post4Jun.db")
#                                              #connect = cms.string("sqlite_file:EEAlign_2018_25May_check.db")
# #                                    connect = cms.string("sqlite_file:EEAlign_2018_3Jun_newselections_onlyphion.db")
#                                     ),
#
#
#                                     cms.PSet(record = cms.string("EBAlignmentRcd"),
#                                     tag = cms.string("EBAlignment_measured_v05_offline"),
#                                     connect = cms.string("sqlite_file:EBAlign_2018_post4Jun.db")
#   #                                  connect = cms.string("sqlite_file:EBAlign_2018_3Jun_newselections.db")
#                                              ),
#
#
#                                     #EcalPedestals_Legacy2017_time_v1
#                                     #EcalPulseShapes_October2017_rereco_v1
#
# )

# Path and EndPath definitions
process.raw2digi_step = cms.Path(process.RawToDigi)
#process.L1Reco_step = cms.Path(process.L1Reco)
process.reconstruction_step = cms.Path(process.reconstruction)
#process.recosim_step = cms.Path(process.recosim)
#process.eventinterpretaion_step = cms.Path(process.EIsequence)
#process.Flag_trackingFailureFilter = cms.Path(process.goodVertices+process.trackingFailureFilter)
#process.Flag_goodVertices = cms.Path(process.primaryVertexFilter)
#process.Flag_CSCTightHaloFilter = cms.Path(process.CSCTightHaloFilter)
#process.Flag_trkPOGFilters = cms.Path(process.trkPOGFilters)
#process.Flag_HcalStripHaloFilter = cms.Path(process.HcalStripHaloFilter)
#process.Flag_trkPOG_logErrorTooManyClusters = cms.Path(~process.logErrorTooManyClusters)
#process.Flag_EcalDeadCellTriggerPrimitiveFilter = cms.Path(process.EcalDeadCellTriggerPrimitiveFilter)
#process.Flag_ecalLaserCorrFilter = cms.Path(process.ecalLaserCorrFilter)
#process.Flag_globalSuperTightHalo2016Filter = cms.Path(process.globalSuperTightHalo2016Filter)
#process.Flag_eeBadScFilter = cms.Path(process.eeBadScFilter)
#process.Flag_METFilters = cms.Path(process.metFilters)
#process.Flag_chargedHadronTrackResolutionFilter = cms.Path(process.chargedHadronTrackResolutionFilter)
#process.Flag_globalTightHalo2016Filter = cms.Path(process.globalTightHalo2016Filter)
#process.Flag_CSCTightHaloTrkMuUnvetoFilter = cms.Path(process.CSCTightHaloTrkMuUnvetoFilter)
#process.Flag_HBHENoiseIsoFilter = cms.Path(process.HBHENoiseFilterResultProducer+process.HBHENoiseIsoFilter)
#process.Flag_BadChargedCandidateSummer16Filter = cms.Path(process.BadChargedCandidateSummer16Filter)
#process.Flag_hcalLaserEventFilter = cms.Path(process.hcalLaserEventFilter)
#process.Flag_BadPFMuonFilter = cms.Path(process.BadPFMuonFilter)
#process.Flag_ecalBadCalibFilter = cms.Path(process.ecalBadCalibFilter)
#process.Flag_HBHENoiseFilter = cms.Path(process.HBHENoiseFilterResultProducer+process.HBHENoiseFilter)
#process.Flag_trkPOG_toomanystripclus53X = cms.Path(~process.toomanystripclus53X)
#process.Flag_EcalDeadCellBoundaryEnergyFilter = cms.Path(process.EcalDeadCellBoundaryEnergyFilter)
#process.Flag_BadChargedCandidateFilter = cms.Path(process.BadChargedCandidateFilter)
#process.Flag_trkPOG_manystripclus53X = cms.Path(~process.manystripclus53X)
#process.Flag_BadPFMuonSummer16Filter = cms.Path(process.BadPFMuonSummer16Filter)
#process.Flag_muonBadTrackFilter = cms.Path(process.muonBadTrackFilter)
#process.Flag_CSCTightHalo2015Filter = cms.Path(process.CSCTightHalo2015Filter)
process.endjob_step = cms.EndPath(process.endOfProcess)
process.RECOSIMoutput_step = cms.EndPath(process.RECOSIMoutput)

# Schedule definition
#process.schedule = cms.Schedule(process.raw2digi_step,process.L1Reco_step,process.reconstruction_step,process.recosim_step,process.eventinterpretaion_step,process.Flag_HBHENoiseFilter,process.Flag_HBHENoiseIsoFilter,process.Flag_CSCTightHaloFilter,process.Flag_CSCTightHaloTrkMuUnvetoFilter,process.Flag_CSCTightHalo2015Filter,process.Flag_globalTightHalo2016Filter,process.Flag_globalSuperTightHalo2016Filter,process.Flag_HcalStripHaloFilter,process.Flag_hcalLaserEventFilter,process.Flag_EcalDeadCellTriggerPrimitiveFilter,process.Flag_EcalDeadCellBoundaryEnergyFilter,process.Flag_ecalBadCalibFilter,process.Flag_goodVertices,process.Flag_eeBadScFilter,process.Flag_ecalLaserCorrFilter,process.Flag_trkPOGFilters,process.Flag_chargedHadronTrackResolutionFilter,process.Flag_muonBadTrackFilter,process.Flag_BadChargedCandidateFilter,process.Flag_BadPFMuonFilter,process.Flag_BadChargedCandidateSummer16Filter,process.Flag_BadPFMuonSummer16Filter,process.Flag_trkPOG_manystripclus53X,process.Flag_trkPOG_toomanystripclus53X,process.Flag_trkPOG_logErrorTooManyClusters,process.Flag_METFilters,process.endjob_step,process.RECOSIMoutput_step)

##################################
#### costumization for Stage2 ####

from HLTrigger.Configuration.customizeHLTforALL import customizeHLTforAll
#process = customizeHLTforAll(process,"GRun",_customInfo)

from HLTrigger.Configuration.customizeHLTforCMSSW import customizeHLTforCMSSW
process = customizeHLTforCMSSW(process,"GRun")

################################################################################
################################################################################
################################################################################
################## create ntuple for ECAL alignment purposes ###################


#--------------------------
#Define PAT sequence
#--------------------------

# Standard PAT Configuration File
process.load("PhysicsTools.PatAlgos.patSequences_cff")
process.patElectrons.addElectronID = cms.bool(False)

# ---- remove MC references ----

from PhysicsTools.PatAlgos.tools.coreTools import removeMCMatching
removeMCMatching(process, ['All'], outputModules=[], postfix="")
#removeMCMatching(process, ['All'])

#process.makePatElectrons.remove(process.electronMatch)
#process.makePatMuons.remove(process.muonMatch)




#process.patCandidates.remove(process.makePatTaus)
#process.makePatTaus.remove(process.tauMatch)
#process.makePatTaus.remove(process.tauGenJets)
#process.makePatTaus.remove(process.tauGenJetsSelectorAllHadrons)
#process.makePatTaus.remove(process.tauGenJetMatch)
process.cleanPatTaus.preselection = cms.string('tauID("decayModeFinding") > 0.5 & tauID("byLooseCombinedIsolationDeltaBetaCorr3Hits") > 0.5 & tauID("againstMuonTight3") > 0.5 ')


process.patMETs.addGenMET = cms.bool(False)


#process.makePatJets.remove(process.patJetPartonMatch)
#process.makePatJets.remove(process.patJetGenJetMatch)
#process.makePatJets.remove(process.patJetFlavourIdLegacy)
#process.makePatJets.remove(process.patJetFlavourId)


#process.makePatPhotons.remove(process.photonMatch)
#process.patJetPartonMatch+process.patJetGenJetMatch+process.patJetFlavourIdLegacy+process.patJetFlavourId

#from PhysicsTools.PatAlgos.tools.coreTools import *
#removeMCMatching(process, names=['All'], outputModules=[])
#process.patMuons.embedGenMatch = cms.bool(False)
#process.makePatElectrons.remove(process.electronMatch)
#process.makePatMuons.remove(process.muonMatch)

#process.options.allowUnscheduled = cms.untracked.bool(False)
process.options.allowUnscheduled = cms.untracked.bool(True)


#--------------------------
# AllPassFilter
#--------------------------

process.AllEvents                      = cms.EDProducer("EventCountProducer")
process.FilterL1FilterEvents           = cms.EDProducer("EventCountProducer")
process.FilterGoodVertexFilterEvents   = cms.EDProducer("EventCountProducer")
process.FilterNoScrapingFilterEvents   = cms.EDProducer("EventCountProducer")
process.FilterElectronFilterEvents     = cms.EDProducer("EventCountProducer")
process.FilterReRECOEvents             = cms.EDProducer("EventCountProducer")
process.FilterPatDefaultSequenceEvents = cms.EDProducer("EventCountProducer")


#--------------------------
# Z skim
#--------------------------


#--------------------------
# Ntple
#--------------------------

process.ntupleEcalAlignment = cms.EDAnalyzer(
                                             'EcalAlignment',
                                             recHitCollection_EB = cms.InputTag("reducedEcalRecHitsEB"),
                                             recHitCollection_EE = cms.InputTag("reducedEcalRecHitsEE"),
                                             #    recHitCollection_EB = cms.InputTag("ecalRecHit","EcalRecHitsEB"),
                                             #    recHitCollection_EE = cms.InputTag("ecalRecHit","EcalRecHitsEE"),
                                             EleTag              = cms.InputTag("patElectrons"),
                                             TrackTag            = cms.InputTag("generalTracks"),
                                             CALOMetTag          = cms.InputTag("patMETs"),
                                             vtxTag              = cms.InputTag("goodPrimaryVertices"),
                                             isMC                = cms.untracked.bool(False),
                                             genEvtInfoTag       = cms.untracked.InputTag("generator")
                                             )



process.TFileService = cms.Service(
                                   "TFileService",
                                   # fileName = cms.string("EcalAlignment.root")
                                   fileName = cms.string(options.outputFile)
                                   )


#--------------------------
# filters
#--------------------------

# filter on PhysDeclared bit
process.skimming = cms.EDFilter(
                                "PhysDecl",
                                applyfilter = cms.untracked.bool(True),
                                debugOn = cms.untracked.bool(False),
                                HLTriggerResults = cms.InputTag("TriggerResults","","HLT")
                                )

# filter on bit = and (40 || 41) and !(bit36 || bit37 || bit38 || bit39)
process.load('L1TriggerConfig.L1GtConfigProducers.L1GtTriggerMaskTechTrigConfig_cff')
process.load('HLTrigger/HLTfilters/hltLevel1GTSeed_cfi')
process.hltLevel1GTSeed.L1TechTriggerSeeding = cms.bool(True)
process.hltLevel1GTSeed.L1SeedsLogicalExpression = cms.string('0 AND (40 OR 41) AND NOT (36 OR 37 OR 38 OR 39)')


VERTEX_SEL=("!isFake && ndof > 4 && abs(z) <= 24 && position.Rho <= 2")

process.goodPrimaryVertices = cms.EDFilter("VertexSelector",
                                           src = cms.InputTag("offlinePrimaryVertices"),
                                           cut = cms.string(VERTEX_SEL),
                                           filter = cms.bool(True),
                                           )

# filter on primary vertex
process.primaryVertexFilter = cms.EDFilter(
                                           "GoodVertexFilter",
                                           vertexCollection = cms.InputTag('offlinePrimaryVertices'),
                                           minimumNDOF = cms.uint32(4) ,
                                           maxAbsZ = cms.double(24),
                                           maxd0 = cms.double(2)
                                           )

# FilterOutScraping
process.noscraping = cms.EDFilter(
                                  "FilterOutScraping",
                                  applyfilter = cms.untracked.bool(True),
                                  debugOn = cms.untracked.bool(False),
                                  numtrack = cms.untracked.uint32(10),
                                  thresh = cms.untracked.double(0.25)
                                  )

# select events with at least one gsf electron
process.highetele = cms.EDFilter(
                                 "GsfElectronSelector",
                                 src = cms.InputTag("gedGsfElectrons"),  # -> new!
                                 cut = cms.string("superCluster().get().energy()*sin(theta())> 0 ")
                                 )

process.highetFilter = cms.EDFilter(
                                    "CandViewCountFilter",
                                    src = cms.InputTag("highetele"),
                                    minNumber = cms.uint32(1)
                                    )



#--------------------------
# paths
#--------------------------

process.pEcalAlignment = cms.Path(
                                  process.AllEvents   # |-> counter
                                  #*process.skimming
                                  #*process.FilterL1FilterEvents   # |-> counter
                                  #*process.hltLevel1GTSeed
                                  #*process.FilterGoodVertexFilterEvents   # |-> counter
                                  #*process.primaryVertexFilter
                                  *process.goodPrimaryVertices
                                  #*process.FilterNoScrapingFilterEvents   # |-> counter
                                  #*process.noscraping
                                  #*process.FilterElectronFilterEvents   # |-> counter
                                  #*process.tagGsfSeq
                                  *process.highetele
                                  *process.highetFilter
                                  *process.FilterReRECOEvents   # |-> counter
                                  *process.patDefaultSequence
                                  *process.FilterPatDefaultSequenceEvents   # |-> counter
                                  *process.ntupleEcalAlignment
                                  )

#process.outpath = cms.EndPath(process.out)



#process.schedule = cms.Schedule(
#process.pEcalAlignment        # | -> selections and ntuple
#)





#process.schedule = cms.Schedule(process.raw2digi_step,process.L1Reco_step,process.reconstruction_step,process.eventinterpretaion_step,process.endjob_step,process.RECOSIMoutput_step)
#process.schedule = cms.Schedule(process.raw2digi_step,process.endjob_step,process.pEcalAlignment,process.RECOSIMoutput_step)
process.schedule = cms.Schedule(process.raw2digi_step,process.reconstruction_step,process.endjob_step,process.pEcalAlignment,process.RECOSIMoutput_step)
#process.schedule.associate(process.patTask)
from PhysicsTools.PatAlgos.tools.helpers import associatePatAlgosToolsTask
associatePatAlgosToolsTask(process)

#Setup FWK for multithreaded
#process.options.numberOfThreads=cms.untracked.uint32(4)
process.options.numberOfStreams=cms.untracked.uint32(0)

#do not add changes to your config after this point (unless you know what you are doing)
#from FWCore.ParameterSet.Utilities import convertToUnscheduled
#process=convertToUnscheduled(process)

# customisation of the process.

# Automatic addition of the customisation function from PhysicsTools.PatAlgos.slimming.miniAOD_tools
#from PhysicsTools.PatAlgos.slimming.miniAOD_tools import miniAOD_customizeAllData

#call to customisation function miniAOD_customizeAllData imported from PhysicsTools.PatAlgos.slimming.miniAOD_tools
#process = miniAOD_customizeAllData(process)

# End of customisation functions

# Customisation from command line

#Have logErrorHarvester wait for the same EDProducers to finish as those providing data for the OutputModule
from FWCore.Modules.logErrorHarvester_cff import customiseLogErrorHarvesterUsingOutputCommands
process = customiseLogErrorHarvesterUsingOutputCommands(process)

# Add early deletion of temporary data products to reduce peak memory need
from Configuration.StandardSequences.earlyDeleteSettings_cff import customiseEarlyDelete
process = customiseEarlyDelete(process)
# End adding early deletion
