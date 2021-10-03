# Auto generated configuration file
# using: 
# Revision: 1.19 
# Source: /local/reps/CMSSW/CMSSW/Configuration/Applications/python/ConfigBuilder.py,v 
# with command line options: reco -s RAW2DIGI,RECO -n 100 --filein=/store/data/Run2015B/DoubleEG/RAW/v1/000/251/562/00000/EEBA3AAA-9428-E511-861B-02163E012073.root --data --conditions=74X_dataRun2_Prompt_v0 --nThreads=4 --customise Configuration/DataProcessing/RecoTLR.customiseDataRun2Common
import FWCore.ParameterSet.Config as cms

process = cms.Process('EcalAlignment')


# manage input variables
from FWCore.ParameterSet.VarParsing import VarParsing
options = VarParsing ('analysis')
# add a list of strings for events to process
process.options   = cms.untracked.PSet(wantSummary = cms.untracked.bool(True))

options.parseArguments()



# import of standard configurations
process.load('Configuration.StandardSequences.Services_cff')
process.load('SimGeneral.HepPDTESSource.pythiapdt_cfi')
process.load('FWCore.MessageService.MessageLogger_cfi')
process.load('Configuration.EventContent.EventContent_cff')
process.load('Configuration.StandardSequences.GeometryRecoDB_cff')
process.load('Configuration.StandardSequences.MagneticField_AutoFromDBCurrent_cff')
process.load('Configuration.StandardSequences.RawToDigi_Data_cff')
process.load('Configuration.StandardSequences.Reconstruction_Data_cff')
process.load('Configuration.StandardSequences.EndOfProcess_cff')
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_condDBv2_cff')

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(100)
)

# Input source
process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring (options.inputFiles),
    #fileNames = cms.untracked.vstring('/store/data/Run2015B/DoubleEG/RAW/v1/000/251/562/00000/EEBA3AAA-9428-E511-861B-02163E012073.root'),
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
    eventAutoFlushCompressedSize = cms.untracked.int32(5242880),
    fileName = cms.untracked.string('reco_RAW2DIGI_RECO.root'),
    #outputCommands = process.RECOSIMEventContent.outputCommands,
    outputCommands = cms.untracked.vstring("drop *"),
    splitLevel = cms.untracked.int32(0)
)

# Additional output definition

###########################
## new tracker alignment ##
process.load("Configuration.StandardSequences.FrontierConditions_GlobalTag_condDBv2_cff")
process.GlobalTag.globaltag = '74X_dataRun2_Prompt_v0'
process.GlobalTag.toGet = cms.VPSet(

          cms.PSet(record = cms.string("TrackerAlignmentRcd"),
           tag = cms.string("Alignments"),
           connect = cms.untracked.string("sqlite_file:alignments_MP.db")
          ),
          #cms.PSet(record = cms.string("TrackerAlignmentRcd"),
                   #tag = cms.string("TrackerAlignment_forRun2015D_v0"),
                   #connect = cms.untracked.string("frontier://FrontierProd/CMS_CONDITIONS")
                  #),
          cms.PSet(record = cms.string("TrackerAlignmentErrorExtendedRcd"),
                   tag = cms.string("TrackerAlignmentExtendedErrors_forRun2015C"),
                   connect = cms.untracked.string("frontier://FrontierProd/CMS_CONDITIONS")
                  ),
          cms.PSet(record = cms.string("SiPixelTemplateDBObjectRcd"),
                   tag = cms.string("SiPixelTemplateDBObject_38T_2015_v3_hltvalidation"),
                   connect = cms.untracked.string("frontier://FrontierProd/CMS_CONDITIONS")
                  ),
          cms.PSet(record = cms.string("SiPixelLorentzAngleRcd"),
                   tag = cms.string("SiPixelLorentzAngle_2015_v3_hltvalidation"),
                   connect = cms.untracked.string("frontier://FrontierProd/CMS_CONDITIONS")
                  ),
          cms.PSet(record = cms.string("SiPixelGenErrorDBObjectRcd"),
                   tag = cms.string("SiPixelGenErrorDBObject_38T_2015_v3_hltvalidation"),
                   connect = cms.untracked.string("frontier://FrontierProd/CMS_CONDITIONS")
                  ),
          cms.PSet(record = cms.string("SiStripLorentzAngleRcd"),
                   tag = cms.string("SiStripLorentzAngleDeco_v3_offline"),
                   connect = cms.untracked.string("frontier://FrontierProd/CMS_CONDITIONS"),
                   label = cms.untracked.string("deconvolution") 
                  ),
          cms.PSet(record = cms.string("SiStripBackPlaneCorrectionRcd"),
                   tag = cms.string("SiStripBackPlaneCorrection_deco_GR10_v4_offline"),
                   connect = cms.untracked.string("frontier://FrontierProd/CMS_CONDITIONS")
                  ),
         
)

###########################
###########################
          
# Path and EndPath definitions
process.raw2digi_step = cms.Path(process.RawToDigi)
process.reconstruction_step = cms.Path(process.reconstruction)
process.endjob_step = cms.EndPath(process.endOfProcess)
process.RECOSIMoutput_step = cms.EndPath(process.RECOSIMoutput)





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
process.makePatElectrons.remove(process.electronMatch)
process.makePatMuons.remove(process.muonMatch)

#process.patCandidates.remove(process.makePatTaus)
process.makePatTaus.remove(process.tauMatch)
process.makePatTaus.remove(process.tauGenJets)
process.makePatTaus.remove(process.tauGenJetsSelectorAllHadrons)
process.makePatTaus.remove(process.tauGenJetMatch)


process.makePatJets.remove(process.patJetPartonMatch)
process.makePatJets.remove(process.patJetGenJetMatch)
process.makePatJets.remove(process.patJetFlavourIdLegacy)
process.makePatJets.remove(process.patJetFlavourId)



process.makePatPhotons.remove(process.photonMatch)

#process.patJetPartonMatch+process.patJetGenJetMatch+process.patJetFlavourIdLegacy+process.patJetFlavourId

#from PhysicsTools.PatAlgos.tools.coreTools import *
#removeMCMatching(process, names=['All'], outputModules=[])
#process.patMuons.embedGenMatch = cms.bool(False)
#process.makePatElectrons.remove(process.electronMatch)
#process.makePatMuons.remove(process.muonMatch)

process.options.allowUnscheduled = cms.untracked.bool(False)
#process.options.allowUnscheduled = cms.untracked.bool(True)


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
    #fileName = cms.string("EcalAlignment.root")
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



### some fix for the stream
process.csctfDigis.producer       = cms.InputTag("hltSelectedElectronFEDListProducerGsf:StreamElectronRawFed")

process.dttfDigis.DTTF_FED_Source = cms.InputTag("hltSelectedElectronFEDListProducerGsf:StreamElectronRawFed")

process.ecalDigis.InputLabel      = cms.InputTag("hltSelectedElectronFEDListProducerGsf:StreamElectronRawFed")

process.ecalPreshowerDigis.sourceTag = cms.InputTag("hltSelectedElectronFEDListProducerGsf:StreamElectronRawFed")

process.castorDigis.InputLabel    = cms.InputTag("hltSelectedElectronFEDListProducerGsf:StreamElectronRawFed")

process.gctDigis.inputLabel       = cms.InputTag("hltSelectedElectronFEDListProducerGsf:StreamElectronRawFed")

process.gtDigis.DaqGtInputTag     = cms.InputTag("hltSelectedElectronFEDListProducerGsf:StreamElectronRawFed")

process.gtEvmDigis.EvmGtInputTag  = cms.InputTag("hltSelectedElectronFEDListProducerGsf:StreamElectronRawFed")

process.hcalDigis.InputLabel      = cms.InputTag("hltSelectedElectronFEDListProducerGsf:StreamElectronRawFed")

process.muonCSCDigis.InputObjects = cms.InputTag("hltSelectedElectronFEDListProducerGsf:StreamElectronRawFed")

process.muonDTDigis.inputLabel    = cms.InputTag("hltSelectedElectronFEDListProducerGsf:StreamElectronRawFed")

process.muonRPCDigis.InputLabel   = cms.InputTag("hltSelectedElectronFEDListProducerGsf:StreamElectronRawFed")

process.scalersRawToDigi.scalersInputTag = cms.InputTag("hltSelectedElectronFEDListProducerGsf:StreamElectronRawFed")

process.siPixelDigis.InputLabel   = cms.InputTag("hltSelectedElectronFEDListProducerGsf:StreamElectronRawFed")

process.siStripDigis.ProductLabel = cms.InputTag("hltSelectedElectronFEDListProducerGsf:StreamElectronRawFed")






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


########################################################

# Schedule definition
process.schedule = cms.Schedule(process.raw2digi_step,process.reconstruction_step,process.endjob_step,process.RECOSIMoutput_step,process.pEcalAlignment)

#Setup FWK for multithreaded
process.options.numberOfThreads=cms.untracked.uint32(4)
process.options.numberOfStreams=cms.untracked.uint32(0)

# customisation of the process.

# Automatic addition of the customisation function from Configuration.DataProcessing.RecoTLR
from Configuration.DataProcessing.RecoTLR import customiseDataRun2Common 

#call to customisation function customiseDataRun2Common imported from Configuration.DataProcessing.RecoTLR
process = customiseDataRun2Common(process)

# End of customisation functions
