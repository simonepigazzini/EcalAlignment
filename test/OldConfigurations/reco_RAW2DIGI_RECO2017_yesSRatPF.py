# Auto generated configuration file
# using: 
# Revision: 1.19 
# Source: /local/reps/CMSSW/CMSSW/Configuration/Applications/python/ConfigBuilder.py,v 
# with command line options: reco -s RAW2DIGI,RECO -n 100 --filein=/store/data/Run2017A/Commissioning2/ALCARECO/TkAlMinBias-PromptReco-v1/000/295/315/00000/22FBAC87-3945-E711-BF76-02163E019B49.root --data --conditions=92X_dataRun2_Prompt_v4 --nThreads=4
import FWCore.ParameterSet.Config as cms

process = cms.Process('EcalAlignment')

# manage input variables
from FWCore.ParameterSet.VarParsing import VarParsing
options = VarParsing ('analysis')
# add a list of strings for events to process
process.options = cms.untracked.PSet(wantSummary = cms.untracked.bool(True))

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
process.load('Configuration.StandardSequences.Reconstruction_Data_cff')
process.load('Configuration.StandardSequences.EndOfProcess_cff')
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')


process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(100)
)

# Input source
process.source = cms.Source("PoolSource",
    #fileNames = cms.untracked.vstring('root://cms-xrd-global.cern.ch//store/data/Run2017A/Commissioning3/RAW-RECO/EcalActivity-PromptReco-v1/000/295/315/00000/44FECA1A-3645-E711-8092-02163E011B25.root','root://cms-xrd-global.cern.ch//store/data/Run2017A/Commissioning3/RAW-RECO/EcalActivity-PromptReco-v1/000/295/317/00000/02955DA6-4F45-E711-A71B-02163E012381.root','root://cms-xrd-global.cern.ch//store/data/Run2017A/Commissioning3/RAW-RECO/EcalActivity-PromptReco-v1/000/295/318/00000/F6B22E65-6245-E711-A71E-02163E013727.root','root://cms-xrd-global.cern.ch//store/data/Run2017A/Commissioning3/RAW-RECO/EcalActivity-PromptReco-v1/000/295/320/00000/D6393D8E-3C45-E711-A01D-02163E0122C3.root','root://cms-xrd-global.cern.ch//store/data/Run2017A/Commissioning3/RAW-RECO/EcalActivity-PromptReco-v1/000/295/323/00000/CE3DD246-5745-E711-88CF-02163E013932.root'),
    fileNames = cms.untracked.vstring(options.inputFiles),
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
   # outputCommands = process.RECOSIMEventContent.outputCommands,
    outputCommands= cms.untracked.vstring("drop *"),
    splitLevel = cms.untracked.int32(0)
)

# Additional output definition

# Other statements
from Configuration.AlCa.GlobalTag import GlobalTag
#process.GlobalTag = GlobalTag(process.GlobalTag, '92X_dataRun2_Prompt_v4', '')
process.GlobalTag.globaltag = '92X_dataRun2_Prompt_v9'






#process.load("Configuration.StandardSequences.FrontierConditions_GlobalTag_cff")

process.GlobalTag.toGet = cms.VPSet(


         cms.PSet(record = cms.string("EcalPedestalsRcd"),
            tag = cms.string("EcalPedestals_Legacy2017_time_v1"),
            connect = cms.string("frontier://FrontierProd/CMS_CONDITIONS")
            ),


         cms.PSet(record = cms.string("EcalPulseShapesRcd"),
            tag = cms.string("EcalPulseShapes_October2017_rereco_v1"),
            connect = cms.string("frontier://FrontierProd/CMS_CONDITIONS")
            ),


 #EcalPedestals_Legacy2017_time_v1 
 #EcalPulseShapes_October2017_rereco_v1
 
        ) 



# Path and EndPath definitions
process.raw2digi_step = cms.Path(process.RawToDigi)
process.reconstruction_step = cms.Path(process.reconstruction)
process.endjob_step = cms.EndPath(process.endOfProcess)
process.RECOSIMoutput_step = cms.EndPath(process.RECOSIMoutput)


########################################
#
# activate/deactivate SR@PF
#

#process.particleFlowRecHitECAL.producers = cms.VPSet(
          #cms.PSet(
            #name = cms.string("PFEBRecHitCreator"),
            #src  = cms.InputTag("ecalRecHit","EcalRecHitsEB"),
            #qualityTests = cms.VPSet(
                 #cms.PSet(
                 #name = cms.string("PFRecHitQTestThreshold"),
                 #srFlags = cms.InputTag("ecalDigis"),
                 #threshold = cms.double(0.08)
                 #),
                 #cms.PSet(
                 #name = cms.string("PFRecHitQTestECAL"),
                 #cleaningThreshold = cms.double(2.0),
                 #timingCleaning = cms.bool(True),
                 #topologicalCleaning = cms.bool(True),
                 #skipTTRecoveredHits = cms.bool(True)
                 #)
            #)
          #),
         #cms.PSet(
           #name = cms.string("PFEERecHitCreator"),
           #src  = cms.InputTag("ecalRecHit","EcalRecHitsEE"),
           #qualityTests = cms.VPSet(
                #cms.PSet(
                #name = cms.string("PFRecHitQTestThreshold"),
                #srFlags = cms.InputTag("ecalDigis"),
                #threshold = cms.double(0.3)
                #),
                #cms.PSet(
                #name = cms.string("PFRecHitQTestECAL"),
                #cleaningThreshold = cms.double(2.0),
                #timingCleaning = cms.bool(True),
                #topologicalCleaning = cms.bool(True),
                #skipTTRecoveredHits = cms.bool(True)
                #)
           #)
         #)
    #)  


########################################
########################################




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




# Schedule definition
process.schedule = cms.Schedule(process.raw2digi_step,process.reconstruction_step,process.endjob_step,process.pEcalAlignment,process.RECOSIMoutput_step)
#process.schedule = cms.Schedule(process.pEcalAlignment)
from PhysicsTools.PatAlgos.tools.helpers import associatePatAlgosToolsTask
associatePatAlgosToolsTask(process)

#Setup FWK for multithreaded
#process.options.numberOfThreads=cms.untracked.uint32(4)
#process.options.numberOfStreams=cms.untracked.uint32(0)


# Customisation from command line
from Configuration.DataProcessing.RecoTLR import customiseDataRun2Common 

#call to customisation function customiseDataRun2Common imported from Configuration.DataProcessing.RecoTLR
process = customiseDataRun2Common(process)

# Add early deletion of temporary data products to reduce peak memory need
from Configuration.StandardSequences.earlyDeleteSettings_cff import customiseEarlyDelete
process = customiseEarlyDelete(process)
# End adding early deletion
