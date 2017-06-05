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

#process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_condDBv2_cff')
#process.load('Configuration.Geometry.GeometryExtended2015Reco_cff')
process.load('Configuration.StandardSequences.L1Reco_cff')
print "I AM HERE 1.1"
#process.load('Configuration.StandardSequences.RawToDigi_Data_cff')
#process.load('RecoLocalCalo.EcalRecProducers.ecalMultiFitUncalibRecHit_cfi')
#process.load('RecoLocalCalo.EcalRecProducers.ecalUncalibRecHit_cfi')
#process.load('RecoLocalCalo.EcalRecProducers.ecalRecHit_cfi')
process.load("RecoVertex.BeamSpotProducer.BeamSpot_cff")
print "I AM HERE 1.2"




# import of standard configurations
process.load('Configuration.StandardSequences.Services_cff')
print "I AM HERE 2.1"
process.load('SimGeneral.HepPDTESSource.pythiapdt_cfi')
print "I AM HERE 2.2"
process.load('FWCore.MessageService.MessageLogger_cfi')
print "I AM HERE 2.3"
process.load('Configuration.EventContent.EventContent_cff')
print " I AM HERE 2.4"
process.load('Configuration.StandardSequences.GeometryRecoDB_cff')
print "I AM HERE 2.5"
process.load('Configuration.StandardSequences.MagneticField_AutoFromDBCurrent_cff')
print " I AM HERE 2.6"
process.load('Configuration.StandardSequences.RawToDigi_Data_cff')
print " I AM HERE 2.7"
process.load('Configuration.StandardSequences.Reconstruction_Data_cff')
print " I AM HERE 2.8"
process.load('Configuration.StandardSequences.EndOfProcess_cff')
print "I AM HERE 2.9"
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')
print "I AM HERE 2.10"

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(100)
)

# Input source
process.source = cms.Source("PoolSource",
   # fileNames = cms.untracked.vstring('file:B8F0DC07-5845-E711-8318-02163E019E8D.root'),
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
process.GlobalTag.globaltag = '92X_dataRun2_Prompt_v4'






#process.load("Configuration.StandardSequences.FrontierConditions_GlobalTag_cff")

#process.GlobalTag.toGet = cms.VPSet(


       # May 23 recipe
              #cms.PSet(record = cms.string("TrackerAlignmentRcd"),
                       #tag =  cms.string("TrackerAlignment_MP_Run2016B"),
                       #connect = cms.string('frontier://FrontierProd/CMS_CONDITIONS')
                       #),
                                             
       # May 24 recipe, definitive!
              #cms.PSet(record = cms.string("TrackerAlignmentRcd"),
                       #tag =  cms.string("TrackerAlignment_MP_Run2016B_v2"),
                       #connect = cms.string('frontier://FrontierProd/CMS_CONDITIONS')
                       #),
              #cms.PSet(record = cms.string("TrackerAlignmentErrorExtendedRcd"),
                       #tag =  cms.string("TrackerAlignmentExtendedErrors_MP_Run2016B"),
                       #connect = cms.string('frontier://FrontierProd/CMS_CONDITIONS')
                       #),
              #cms.PSet(record = cms.string("SiPixelTemplateDBObjectRcd"),
                       #tag =  cms.string("SiPixelTemplateDBObject_38T_2016_v1_hltvalidation"),
                       #connect = cms.string('frontier://FrontierProd/CMS_CONDITIONS')
                       #),
       
       
          #cms.PSet(record = cms.string("TrackerAlignmentRcd"),
           #tag = cms.string("Alignments"),
           #connect = cms.untracked.string("sqlite_file:alignments_MP.db")
          #),
          ##cms.PSet(record = cms.string("TrackerAlignmentRcd"),
                   ##tag = cms.string("TrackerAlignment_forRun2015D_v0"),
                   ##connect = cms.untracked.string("frontier://FrontierProd/CMS_CONDITIONS")
                  ##),
          #cms.PSet(record = cms.string("TrackerAlignmentErrorExtendedRcd"),
                   #tag = cms.string("TrackerAlignmentExtendedErrors_forRun2015C"),
                   #connect = cms.untracked.string("frontier://FrontierProd/CMS_CONDITIONS")
                  #),
          #cms.PSet(record = cms.string("SiPixelTemplateDBObjectRcd"),
                   #tag = cms.string("SiPixelTemplateDBObject_38T_2015_v3_hltvalidation"),
                   #connect = cms.untracked.string("frontier://FrontierProd/CMS_CONDITIONS")
                  #),
          #cms.PSet(record = cms.string("SiPixelLorentzAngleRcd"),
                   #tag = cms.string("SiPixelLorentzAngle_2015_v3_hltvalidation"),
                   #connect = cms.untracked.string("frontier://FrontierProd/CMS_CONDITIONS")
                  #),
          #cms.PSet(record = cms.string("SiPixelGenErrorDBObjectRcd"),
                   #tag = cms.string("SiPixelGenErrorDBObject_38T_2015_v3_hltvalidation"),
                   #connect = cms.untracked.string("frontier://FrontierProd/CMS_CONDITIONS")
                  #),
          #cms.PSet(record = cms.string("SiStripLorentzAngleRcd"),
                   #tag = cms.string("SiStripLorentzAngleDeco_v3_offline"),
                   #connect = cms.untracked.string("frontier://FrontierProd/CMS_CONDITIONS"),
                   #label = cms.untracked.string("deconvolution") 
                  #),
          #cms.PSet(record = cms.string("SiStripBackPlaneCorrectionRcd"),
                   #tag = cms.string("SiStripBackPlaneCorrection_deco_GR10_v4_offline"),
                   #connect = cms.untracked.string("frontier://FrontierProd/CMS_CONDITIONS")
                  #),
         ##)
                  ##cms.PSet(record = cms.string("TrackerAlignmentRcd"),
                 ##tag = cms.string("testTag"),
                 ##connect = cms.untracked.string('sqlite_file:TkAlignment.db')
                 ###connect = cms.untracked.string('sqlite_file:/afs/cern.ch/work/c/chmartin/public/pp3.8T_2015_Alignment/Local_DB/TkAlignment.db')
                ##),
          ##cms.PSet(record = cms.string("EBAlignmentRcd"),
             ##tag = cms.string("EBAlignment_measured_v08_offline"),
             ##connect = cms.untracked.string("sqlite_file:EBAlign_2015.db")   #### New ####
             ##),
          #cms.PSet(record = cms.string("EEAlignmentRcd"),
             #tag = cms.string("EEAlignment_measured_v05_offline"),
             ##connect = cms.untracked.string("sqlite_file:dbEcalAlignment/EEAlign_2015.db")  #### New ####
             ##connect = cms.untracked.string("sqlite_file:/afs/cern.ch/user/a/amassiro/public/ECAL_Alignment/2015/23Jul/EEAlign_2015.db")  #### New ####
             #connect = cms.untracked.string("sqlite_file:EEAlign_2015.db")  #### New ####
             ##connect = cms.untracked.string("sqlite_file:/afs/cern.ch/user/a/amassiro/public/ECAL_Alignment/2015/31Aug/EEAlign_2015.db")  #### New ####
             #),
          #cms.PSet(record = cms.string("EBAlignmentRcd"),
             #tag = cms.string("EBAlignment_measured_v05_offline"),
             #connect = cms.untracked.string("sqlite_file:EBAlign_2015.db")  #### New ####
             ##connect = cms.untracked.string("sqlite_file:/afs/cern.ch/user/a/amassiro/public/ECAL_Alignment/2015/31Aug/EBAlign_2015.db")  #### New ####
             #)

         # cms.PSet(record = cms.string("EEAlignmentRcd"),
            # tag = cms.string("EEAlignment_measured_v05_offline"),
            # connect = cms.string("sqlite_file:EEAlign_2015.db")   #### The ZERO ####
            # ),
         # cms.PSet(record = cms.string("EBAlignmentRcd"),
            # tag = cms.string("EBAlignment_measured_v05_offline"),
            # connect = cms.string("sqlite_file:EBAlign_2015.db")   #### The ZERO ####
            # ),
        # ) 



# Path and EndPath definitions
process.raw2digi_step = cms.Path(process.RawToDigi)
print "I AM HERE 3.1"
process.reconstruction_step = cms.Path(process.reconstruction)
print "I AM HERE 3.2"
process.endjob_step = cms.EndPath(process.endOfProcess)
print "I AM HERE 3.3"
process.RECOSIMoutput_step = cms.EndPath(process.RECOSIMoutput)
print "I AM HERE 3.4"




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
print " I AM HERE 4"
process.patElectrons.addElectronID = cms.bool(False)

# ---- remove MC references ----

from PhysicsTools.PatAlgos.tools.coreTools import removeMCMatching
#removeMCMatching(process, ['All'], outputModules=[], postfix="")
process.makePatElectrons.remove(process.electronMatch)
print " I AM HERE 5.1"
process.makePatMuons.remove(process.muonMatch)
print "I AM HERE 5.2"
#process.patCandidates.remove(process.makePatTaus)
process.makePatTaus.remove(process.tauMatch)
print "I AM HERE 5.3"
process.makePatTaus.remove(process.tauGenJets)
print "I AM HERE 5.4"
process.makePatTaus.remove(process.tauGenJetsSelectorAllHadrons)
print "I AM HERE 5.5"
process.makePatTaus.remove(process.tauGenJetMatch)
print "I AM HERE 5.6"
process.cleanPatTaus.preselection = cms.string('tauID("decayModeFinding") > 0.5 & tauID("byLooseCombinedIsolationDeltaBetaCorr3Hits") > 0.5 & tauID("againstMuonTight3") > 0.5 ')
print "I AM HERE 5.7"    

process.patMETs.addGenMET = cms.bool(False)
print "I AM HERE 5.8"

process.makePatJets.remove(process.patJetPartonMatch)
print " I AM HERE 5.9"
process.makePatJets.remove(process.patJetGenJetMatch)
print "I AM HERE 5.10"
process.makePatJets.remove(process.patJetFlavourIdLegacy)
print "I AM HERE 5.11"
process.makePatJets.remove(process.patJetFlavourId)
print "I AM HERE 5.12"


process.makePatPhotons.remove(process.photonMatch)
print "I AM HERE 5.13"
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
print "I AM HERE 6"
process.load('HLTrigger/HLTfilters/hltLevel1GTSeed_cfi')
print "I AM HERE 7"
process.hltLevel1GTSeed.L1TechTriggerSeeding = cms.bool(True)
print "I AM HERE 8"
process.hltLevel1GTSeed.L1SeedsLogicalExpression = cms.string('0 AND (40 OR 41) AND NOT (36 OR 37 OR 38 OR 39)')
print "I AM HERE 9"

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
process.schedule = cms.Schedule(process.raw2digi_step,process.reconstruction_step,process.endjob_step,process.RECOSIMoutput_step,process.pEcalAlignment)
from PhysicsTools.PatAlgos.tools.helpers import associatePatAlgosToolsTask
associatePatAlgosToolsTask(process)

#Setup FWK for multithreaded
process.options.numberOfThreads=cms.untracked.uint32(4)
process.options.numberOfStreams=cms.untracked.uint32(0)


# Customisation from command line
from Configuration.DataProcessing.RecoTLR import customiseDataRun2Common 

#call to customisation function customiseDataRun2Common imported from Configuration.DataProcessing.RecoTLR
process = customiseDataRun2Common(process)

# Add early deletion of temporary data products to reduce peak memory need
from Configuration.StandardSequences.earlyDeleteSettings_cff import customiseEarlyDelete
process = customiseEarlyDelete(process)
# End adding early deletion
