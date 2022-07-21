# Auto generated configuration file
# using: 
# Revision: 1.19 
# Source: /local/reps/CMSSW/CMSSW/Configuration/Applications/python/ConfigBuilder.py,v 
# with command line options: reco -s RAW2DIGI,L1Reco,RECO,PAT --conditions auto:run3_data_prompt --data --era Run3 --filein=/store/data/Run2022B/EGamma/RAW-RECO/ZElectron-PromptReco-v1/000/355/381/00000/83cd8150-e426-4809-9af6-635b24fefc67.root
import FWCore.ParameterSet.Config as cms

from Configuration.Eras.Era_Run3_cff import Run3

process = cms.Process('EcalAlignment',Run3)


# manage input variables
from FWCore.ParameterSet.VarParsing import VarParsing
options = VarParsing ('analysis')
# add a list of strings for events to process
options.parseArguments()



# import of standard configurations
process.load('Configuration.StandardSequences.Services_cff')
process.load('SimGeneral.HepPDTESSource.pythiapdt_cfi')
process.load('FWCore.MessageService.MessageLogger_cfi')
process.load('Configuration.EventContent.EventContent_cff')
process.load('Configuration.StandardSequences.GeometryRecoDB_cff')
process.load('Configuration.StandardSequences.MagneticField_cff')
process.load('Configuration.StandardSequences.RawToDigi_Data_cff')
process.load('Configuration.StandardSequences.L1Reco_cff')
process.load('Configuration.StandardSequences.Reconstruction_Data_cff')
process.load('PhysicsTools.PatAlgos.slimming.metFilterPaths_cff')
process.load('Configuration.StandardSequences.PAT_cff')
process.load('Configuration.StandardSequences.EndOfProcess_cff')
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(-1),
    output = cms.optional.untracked.allowed(cms.int32,cms.PSet)
)

# Input source
process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring('/store/data/Run2022B/EGamma/RAW-RECO/ZElectron-PromptReco-v1/000/355/680/00000/f94fc5bf-3509-4501-ba6a-9dcb930cbd8a.root'),
    secondaryFileNames = cms.untracked.vstring()
)

process.options = cms.untracked.PSet(
    FailPath = cms.untracked.vstring(),
    IgnoreCompletely = cms.untracked.vstring(),
    Rethrow = cms.untracked.vstring(),
    SkipEvent = cms.untracked.vstring(),
    accelerators = cms.untracked.vstring('*'),
    allowUnscheduled = cms.obsolete.untracked.bool,
    canDeleteEarly = cms.untracked.vstring(),
    deleteNonConsumedUnscheduledModules = cms.untracked.bool(True),
    dumpOptions = cms.untracked.bool(False),
    emptyRunLumiMode = cms.obsolete.untracked.string,
    eventSetup = cms.untracked.PSet(
        forceNumberOfConcurrentIOVs = cms.untracked.PSet(
            allowAnyLabel_=cms.required.untracked.uint32
        ),
        numberOfConcurrentIOVs = cms.untracked.uint32(0)
    ),
    fileMode = cms.untracked.string('FULLMERGE'),
    forceEventSetupCacheClearOnNewRun = cms.untracked.bool(False),
    makeTriggerResults = cms.obsolete.untracked.bool,
    numberOfConcurrentLuminosityBlocks = cms.untracked.uint32(0),
    numberOfConcurrentRuns = cms.untracked.uint32(1),
    numberOfStreams = cms.untracked.uint32(0),
    numberOfThreads = cms.untracked.uint32(1),
    printDependencies = cms.untracked.bool(False),
    sizeOfStackForThreadsInKB = cms.optional.untracked.uint32,
    throwIfIllegalParameter = cms.untracked.bool(True),
    wantSummary = cms.untracked.bool(False)
)

# Production Info
process.configurationMetadata = cms.untracked.PSet(
    annotation = cms.untracked.string('reco nevts:1'),
    name = cms.untracked.string('Applications'),
    version = cms.untracked.string('$Revision: 1.19 $')
)

# Output definition

process.RECOSIMoutput = cms.OutputModule("PoolOutputModule",
    dataset = cms.untracked.PSet(
        dataTier = cms.untracked.string(''),
        filterName = cms.untracked.string('')
    ),
    fileName = cms.untracked.string('reco_RAW2DIGI_L1Reco_RECO_PAT.root'),
    outputCommands = process.RECOSIMEventContent.outputCommands,
    splitLevel = cms.untracked.int32(0)
)

# Additional output definition

# Other statements
from Configuration.AlCa.GlobalTag import GlobalTag
process.GlobalTag = GlobalTag(process.GlobalTag, 'auto:run3_data_prompt', '')

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
process.L1Reco_step = cms.Path(process.L1Reco)
process.reconstruction_step = cms.Path(process.reconstruction)
process.Flag_BadChargedCandidateFilter = cms.Path(process.BadChargedCandidateFilter)
process.Flag_BadChargedCandidateSummer16Filter = cms.Path(process.BadChargedCandidateSummer16Filter)
process.Flag_BadPFMuonDzFilter = cms.Path(process.BadPFMuonDzFilter)
process.Flag_BadPFMuonFilter = cms.Path(process.BadPFMuonFilter)
process.Flag_BadPFMuonSummer16Filter = cms.Path(process.BadPFMuonSummer16Filter)
process.Flag_CSCTightHalo2015Filter = cms.Path(process.CSCTightHalo2015Filter)
process.Flag_CSCTightHaloFilter = cms.Path(process.CSCTightHaloFilter)
process.Flag_CSCTightHaloTrkMuUnvetoFilter = cms.Path(process.CSCTightHaloTrkMuUnvetoFilter)
process.Flag_EcalDeadCellBoundaryEnergyFilter = cms.Path(process.EcalDeadCellBoundaryEnergyFilter)
process.Flag_EcalDeadCellTriggerPrimitiveFilter = cms.Path(process.EcalDeadCellTriggerPrimitiveFilter)
process.Flag_HBHENoiseFilter = cms.Path(process.HBHENoiseFilterResultProducer+process.HBHENoiseFilter)
process.Flag_HBHENoiseIsoFilter = cms.Path(process.HBHENoiseFilterResultProducer+process.HBHENoiseIsoFilter)
process.Flag_HcalStripHaloFilter = cms.Path(process.HcalStripHaloFilter)
process.Flag_METFilters = cms.Path(process.metFilters)
process.Flag_chargedHadronTrackResolutionFilter = cms.Path(process.chargedHadronTrackResolutionFilter)
process.Flag_ecalBadCalibFilter = cms.Path(process.ecalBadCalibFilter)
process.Flag_ecalLaserCorrFilter = cms.Path(process.ecalLaserCorrFilter)
process.Flag_eeBadScFilter = cms.Path(process.eeBadScFilter)
process.Flag_globalSuperTightHalo2016Filter = cms.Path(process.globalSuperTightHalo2016Filter)
process.Flag_globalTightHalo2016Filter = cms.Path(process.globalTightHalo2016Filter)
process.Flag_goodVertices = cms.Path(process.primaryVertexFilter)
process.Flag_hcalLaserEventFilter = cms.Path(process.hcalLaserEventFilter)
process.Flag_hfNoisyHitsFilter = cms.Path(process.hfNoisyHitsFilter)
process.Flag_muonBadTrackFilter = cms.Path(process.muonBadTrackFilter)
process.Flag_trackingFailureFilter = cms.Path(process.goodVertices+process.trackingFailureFilter)
process.Flag_trkPOGFilters = cms.Path(process.trkPOGFilters)
process.Flag_trkPOG_logErrorTooManyClusters = cms.Path(~process.logErrorTooManyClusters)
process.Flag_trkPOG_manystripclus53X = cms.Path(~process.manystripclus53X)
process.Flag_trkPOG_toomanystripclus53X = cms.Path(~process.toomanystripclus53X)
process.endjob_step = cms.EndPath(process.endOfProcess)
process.RECOSIMoutput_step = cms.EndPath(process.RECOSIMoutput)


################################################################################
################################################################################
################################################################################
################## create ntuple for ECAL alignment purposes ###################

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
    recHitCollection_EB = cms.InputTag("reducedEgamma","reducedEBRecHits"),    #   "reducedEcalRecHitsEB"),
    recHitCollection_EE = cms.InputTag("reducedEgamma","reducedEERecHits"),     #   "reducedEcalRecHitsEE"),
    #recHitCollection_EB = cms.InputTag("reducedEcalRecHitsEB"),
    #recHitCollection_EE = cms.InputTag("reducedEcalRecHitsEE"),
#    recHitCollection_EB = cms.InputTag("ecalRecHit","EcalRecHitsEB"),
#    recHitCollection_EE = cms.InputTag("ecalRecHit","EcalRecHitsEE"),
    EleTag              = cms.InputTag("slimmedElectrons"),  # "patElectrons"
    TrackTag            = cms.InputTag("generalTracks"),
    CALOMetTag          = cms.InputTag("slimmedMETs"),      # "patMETs"
    vtxTag              = cms.InputTag("goodPrimaryVertices"),
    isMC                = cms.untracked.bool(False),
    genEvtInfoTag       = cms.untracked.InputTag("generator")
    )



process.TFileService = cms.Service(
    "TFileService",
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
  src = cms.InputTag("offlineSlimmedPrimaryVertices"),     # "offlinePrimaryVertices"
  cut = cms.string(VERTEX_SEL),
  filter = cms.bool(True),
)

# filter on primary vertex
process.primaryVertexFilter = cms.EDFilter(
    "GoodVertexFilter",
    vertexCollection = cms.InputTag("offlineSlimmedPrimaryVertices"),     # "offlinePrimaryVertices"
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
    "PATElectronSelector",   #"GsfElectronSelector",
    src = cms.InputTag("slimmedElectrons"),  # "gedGsfElectrons"
    #"GsfElectronSelector",
    #src = cms.InputTag("gedGsfElectrons"),  # -> new!
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
    #*process.patDefaultSequence
    *process.FilterPatDefaultSequenceEvents   # |-> counter
    *process.ntupleEcalAlignment
    )



# Schedule definition
process.schedule = cms.Schedule(process.raw2digi_step,process.L1Reco_step,process.reconstruction_step,process.Flag_HBHENoiseFilter,process.Flag_HBHENoiseIsoFilter,process.Flag_CSCTightHaloFilter,process.Flag_CSCTightHaloTrkMuUnvetoFilter,process.Flag_CSCTightHalo2015Filter,process.Flag_globalTightHalo2016Filter,process.Flag_globalSuperTightHalo2016Filter,process.Flag_HcalStripHaloFilter,process.Flag_hcalLaserEventFilter,process.Flag_EcalDeadCellTriggerPrimitiveFilter,process.Flag_EcalDeadCellBoundaryEnergyFilter,process.Flag_ecalBadCalibFilter,process.Flag_goodVertices,process.Flag_eeBadScFilter,process.Flag_ecalLaserCorrFilter,process.Flag_trkPOGFilters,process.Flag_chargedHadronTrackResolutionFilter,process.Flag_muonBadTrackFilter,process.Flag_BadChargedCandidateFilter,process.Flag_BadPFMuonFilter,process.Flag_BadPFMuonDzFilter,process.Flag_hfNoisyHitsFilter,process.Flag_BadChargedCandidateSummer16Filter,process.Flag_BadPFMuonSummer16Filter,process.Flag_trkPOG_manystripclus53X,process.Flag_trkPOG_toomanystripclus53X,process.Flag_trkPOG_logErrorTooManyClusters,process.Flag_METFilters,process.endjob_step,process.pEcalAlignment,process.RECOSIMoutput_step)
process.schedule.associate(process.patTask)
from PhysicsTools.PatAlgos.tools.helpers import associatePatAlgosToolsTask
associatePatAlgosToolsTask(process)


# customisation of the process.

# Automatic addition of the customisation function from PhysicsTools.PatAlgos.slimming.miniAOD_tools
from PhysicsTools.PatAlgos.slimming.miniAOD_tools import miniAOD_customizeAllData 

#call to customisation function miniAOD_customizeAllData imported from PhysicsTools.PatAlgos.slimming.miniAOD_tools
process = miniAOD_customizeAllData(process)

# End of customisation functions

# Customisation from command line

#Have logErrorHarvester wait for the same EDProducers to finish as those providing data for the OutputModule
from FWCore.Modules.logErrorHarvester_cff import customiseLogErrorHarvesterUsingOutputCommands
process = customiseLogErrorHarvesterUsingOutputCommands(process)

# Add early deletion of temporary data products to reduce peak memory need
from Configuration.StandardSequences.earlyDeleteSettings_cff import customiseEarlyDelete
process = customiseEarlyDelete(process)
# End adding early deletion
