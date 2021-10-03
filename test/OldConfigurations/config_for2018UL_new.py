import FWCore.ParameterSet.Config as cms
from Configuration.StandardSequences.Eras import eras

process = cms.Process('RECO',eras.Run2_2017)
process.load('Configuration.StandardSequences.GeometryRecoDB_cff')
process.load('Configuration.StandardSequences.MagneticField_AutoFromDBCurrent_cff')
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_condDBv2_cff')
process.load("TrackPropagation.SteppingHelixPropagator.SteppingHelixPropagatorAlong_cfi")

process.load('Configuration.StandardSequences.Services_cff')
process.load('SimGeneral.HepPDTESSource.pythiapdt_cfi')
process.load('FWCore.MessageService.MessageLogger_cfi')
process.load('Configuration.EventContent.EventContent_cff')
process.load('Configuration.StandardSequences.RawToDigi_Data_cff')
process.load('Configuration.StandardSequences.L1Reco_cff')
process.load('Configuration.StandardSequences.Reconstruction_Data_cff')
process.load('Configuration.StandardSequences.AlCaRecoStreams_cff')
process.load('Configuration.StandardSequences.EndOfProcess_cff')
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')


# manage input variables
from FWCore.ParameterSet.VarParsing import VarParsing
options = VarParsing ('analysis')
# add a list of strings for events to process
process.options = cms.untracked.PSet(wantSummary = cms.untracked.bool(True))
#process.options = cms.untracked.PSet( allowUnscheduled = cms.untracked.bool(True) )

options.parseArguments()


###################### Modify following Global tag ################################

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(100)
)

# Input source
# from inputFiles_cfi import *
process.source = cms.Source("PoolSource",
    # fileNames = cms.untracked.vstring(FileNames)
    fileNames = cms.untracked.vstring('root://cms-xrd-global.cern.ch//store/data/Run2018C/EGamma/RAW/v1/000/320/026/00000/F0E4D83A-5E8D-E811-A7BE-FA163E8CC774.root'),
)

process.options = cms.untracked.PSet(
)



# Production Info
process.configurationMetadata = cms.untracked.PSet(
    annotation = cms.untracked.string('--step=RAW2DIGI,RECO,ALCA:EcalESAlign nevts:100'),
    name = cms.untracked.string('Applications'),
    version = cms.untracked.string('$Revision: 1.19 $')
    )

###################### Modify following Global tag ################################
## See https://twiki.cern.ch/twiki/bin/view/CMSPublic/SWGuideFrontierConditions

process.ALCARECOEventContent.outputCommands.extend(process.OutALCARECOEcalESAlign_noDrop.outputCommands)
from Configuration.AlCa.GlobalTag import GlobalTag
process.GlobalTag = GlobalTag(process.GlobalTag, '106X_dataRun2_newTkAl_v18', '')
# Default Parameter options


#process.options.numberOfThreads=cms.untracked.uint32(8)
process.options.numberOfStreams=cms.untracked.uint32(0)

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

process.raw2digi_step = cms.Path(process.RawToDigi)
# process.L1Reco_step = cms.Path(process.L1Reco)
process.reconstruction_step = cms.Path(process.reconstruction)
process.endjob_step = cms.EndPath(process.endOfProcess)
process.RECOSIMoutput_step = cms.EndPath(process.RECOSIMoutput)

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
process.schedule = cms.Schedule(process.raw2digi_step,process.reconstruction_step,process.endjob_step,process.pEcalAlignment,process.RECOSIMoutput_step)

#process.schedule = cms.Schedule(process.raw2digi_step,process.reconstruction_step)
#process.schedule = cms.Schedule(process.raw2digi_step,process.reconstruction_step,process.pathALCARECOEcalESAlign,process.esrechit,process.esaligntool)






