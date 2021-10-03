# Auto generated configuration file
# using: 
# Revision: 1.222.2.6 
# Source: /cvs_server/repositories/CMSSW/CMSSW/Configuration/PyReleaseValidation/python/ConfigBuilder.py,v 
# with command line options: step2 -s RAW2DIGI,L1Reco,RECO --data --datatier RECO --eventcontent RECO --conditions GR10_P_V11::All --scenario pp --no_exec --magField AutoFromDBCurrent --process reRECO --customise Configuration/GlobalRuns/reco_TLR_38X.py --cust_function customisePPData --filein=outSkim_1_1_GlC.root
import FWCore.ParameterSet.Config as cms

####### option parsing
from FWCore.ParameterSet.VarParsing import VarParsing
options = VarParsing ('python')
# add a list of strings for events to process
options.register ('isMC', False, VarParsing.multiplicity.singleton, VarParsing.varType.bool, 'is MC or is Data')
options.parseArguments()
print options






process = cms.Process('EcalAlignment')



# import of standard configurations
process.load('Configuration.StandardSequences.Services_cff')
process.load('SimGeneral.HepPDTESSource.pythiapdt_cfi')
process.load('FWCore.MessageService.MessageLogger_cfi')
process.load('Configuration.StandardSequences.GeometryDB_cff')
process.load('Configuration.StandardSequences.MagneticField_AutoFromDBCurrent_cff')

if options.isMC :
    process.load('SimGeneral.MixingModule.mixNoPU_cfi')
    process.load('Configuration.StandardSequences.RawToDigi_cff')
    process.load('Configuration.StandardSequences.Reconstruction_cff')
else :
    process.load('Configuration.StandardSequences.RawToDigi_Data_cff')
    process.load('Configuration.StandardSequences.Reconstruction_Data_cff')


process.load('Configuration.StandardSequences.L1Reco_cff')
process.load('Configuration.StandardSequences.EndOfProcess_cff')
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')
process.load('Configuration.EventContent.EventContent_cff')

process.configurationMetadata = cms.untracked.PSet(
    version = cms.untracked.string('$Revision: 1.1 $'),
    annotation = cms.untracked.string('step2 nevts:1'),
    name = cms.untracked.string('PyReleaseValidation')
)

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(-1)
)

process.options = cms.untracked.PSet(
)

# Input source
process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(options.inputFiles)
    #fileNames = cms.untracked.vstring(
        #'file:/tmp/amassiro/FEE043A5-93D4-E111-84DC-0030486790C0.root'
        #'file:/data2/amassiro/CMSSWRoot/DATA2012/DoubleElectron_Run2012B-ZElectron-13Jul2012-v1_RAW-RECO/FEE043A5-93D4-E111-84DC-0030486790C0.root'
        #amassiro@cmsneu:/data/amassiro/CMSSWRoot/DATA2012/DoubleElectron_Run2012B-ZElectron-13Jul2012-v1_RAW-RECO/
    #) 
    )

#.root
#process.source.inputCommands = cms.untracked.vstring("drop *_MEtoEDMConverter_*_*", "keep FEDRawDataCollection_*_*_*")
#process.source.inputCommands = cms.untracked.vstring("drop *_*_*_RECO", "drop *_MEtoEDMConverter_*_*", "keep FEDRawDataCollection_*_*_*")
process.source.inputCommands = cms.untracked.vstring(
        "drop *",
        #"drop *_*_*_RECO",
        "drop *_MEtoEDMConverter_*_*",
        "keep FEDRawDataCollection_*_*_*",
        #"keep *_gsfElectrons_*_*"
        )

# Output definition
process.RECOoutput = cms.OutputModule("PoolOutputModule",
    splitLevel = cms.untracked.int32(0),
    eventAutoFlushCompressedSize = cms.untracked.int32(5242880),
    outputCommands = process.RECOEventContent.outputCommands,
    fileName = cms.untracked.string("recooutput.root"),
    dataset = cms.untracked.PSet(
        filterName = cms.untracked.string(''),
        dataTier = cms.untracked.string('RECO')
    )
)


process.out = cms.OutputModule("PoolOutputModule",
  outputCommands = cms.untracked.vstring(
        #'keep *',
       'drop *'
       #'keep *_gsfElectrons_*_*'
       #'keep *_*_*_EcalAlignmentBIS'
       #'drop *_gsfElectron_*_*',
       #'drop *_gsfElectronCores_*_*'
        ),
  fileName = cms.untracked.string("outCMSSW.root")
)

  
# Additional output definition

# Other statements
from Configuration.AlCa.GlobalTag import GlobalTag

if options.isMC :
    process.GlobalTag = GlobalTag(process.GlobalTag, 'DESIGN71_V5::All', '')    
else :
    process.GlobalTag.globaltag = 'GR_E_V42::All'  # fix HCAL reconstruction
    #process.GlobalTag.globaltag = 'GR_R_71_V4::All'


#process.GlobalTag.toGet = cms.VPSet(
      #cms.PSet(record = cms.string("EcalIntercalibConstantsRcd"),
             #tag = cms.string("EcalIntercalibConstants_Bon_V20100803"),
             #connect = cms.untracked.string("frontier://FrontierProd/CMS_COND_31X_ECAL")
             #),
    #cms.PSet(record = cms.string("EcalADCToGeVConstantRcd"),
             #tag = cms.string("EcalADCToGeVConstant_Bon_V20100803"),
             #connect = cms.untracked.string("frontier://FrontierProd/CMS_COND_31X_ECAL")
             #),


  #  cms.PSet(record = cms.string("EBAlignmentRcd"),
  #           tag = cms.string("EBAlignment_measured_v07_offline"),
  #           connect = cms.untracked.string("frontier://FrontierProd/CMS_COND_34X_ECAL")   #### New ####
  #           ),
  #  cms.PSet(record = cms.string("EEAlignmentRcd"),
  #           tag = cms.string("EEAlignment_measured_v07_offline"),
  #           connect = cms.untracked.string("frontier://FrontierProd/CMS_COND_34X_ECAL")  #### New ####
  #           )



    #cms.PSet(record = cms.string("EBAlignmentRcd"),
             #tag = cms.string("EBAlignment_measured_v08_offline"),
             #connect = cms.untracked.string("sqlite_file:EBAlign_2012.db")   #### New ####
             #),
    #cms.PSet(record = cms.string("EEAlignmentRcd"),
             #tag = cms.string("EEAlignment_measured_v08_offline"),
             #connect = cms.untracked.string("sqlite_file:EEAlign_2012.db")  #### New ####
             #),
    #cms.PSet(record = cms.string("ESAlignmentRcd"),
             #tag = cms.string("ESAlignment_measured_v01_offline"),
             #connect = cms.untracked.string("frontier://FrontierProd/CMS_COND_31X_PRESHOWER")
             #),
    #cms.PSet(record = cms.string("EcalLaserAlphasRcd"),
             #tag = cms.string("EcalLaserAlphas_test_prompt"),
             #connect = cms.untracked.string("frontier://FrontierProd/CMS_COND_31X_ECAL")
             #),
    #cms.PSet(record = cms.string("EcalLaserAPDPNRatiosRcd"),
             #tag = cms.string("EcalLaserAPDPNRatios_v0_online"),
             #connect = cms.untracked.string("frontier://FrontierPrep/CMS_COND_ECAL")
             #),
    #cms.PSet(record = cms.string("GlobalPositionRcd"),
             #tag = cms.string("GlobalAlignment_v2_offline"),
             #connect = cms.untracked.string("frontier://FrontierProd/CMS_COND_31X_ALIGNMENT")
             #),

    #cms.PSet(record = cms.string("TrackerAlignmentRcd"),
             #tag = cms.string("Alignments"),
             #connect = cms.untracked.string("sqlite_file:/afs/cern.ch/cms/CAF/CMSALCA/ALCA_TRACKERALIGN/MP/MPproduction/mp1280/jobData/jobm/alignments_MP_fixed.db")
             #)
    #cms.PSet(record = cms.string("TrackerAlignmentErrorRcd"),
             #tag = cms.string("TrackerAlignmentErrors_GR10_v2_offline"),
             #connect = cms.untracked.string("frontier://FrontierProd/CMS_COND_31X_ALIGNMENT")
             #)
    #)


# Path and EndPath definitions
process.raw2digi_step = cms.Path(process.RawToDigi)
process.L1Reco_step = cms.Path(process.L1Reco)
process.reconstruction_step = cms.Path(process.reconstruction)
process.endjob_step = cms.Path(process.endOfProcess)
process.RECOoutput_step = cms.EndPath(process.RECOoutput)

# Schedule definition
#process.schedule = cms.Schedule(process.raw2digi_step,process.L1Reco_step,process.reconstruction_step,process.endjob_step,process.RECOoutput_step)

# https://twiki.cern.ch/twiki/bin/view/CMSPublic/SWGuideFrontierConditions?redirectedfrom=CMS.SWGuideFrontierConditions#311X_Releases  


############################
## Dump the output Python ##
############################

processDumpFile = open('processDump.py', 'w')
print >> processDumpFile, process.dumpPython()



################################################################################
################################################################################
################################################################################
################## create ntuple for ECAL alignment purposes ###################

if options.isMC :

    # Automatic addition of the customisation function from SLHCUpgradeSimulations.Configuration.postLS1Customs
    from SLHCUpgradeSimulations.Configuration.postLS1Customs import customisePostLS1 

    #call to customisation function customisePostLS1 imported from SLHCUpgradeSimulations.Configuration.postLS1Customs
    process = customisePostLS1(process)

    # fix for stream & csc MC
    #process.csc2DRecHits.wireDigiTag = cms.InputTag("muonCSCDigis","MuonCSCWireDigi")
    #process.csc2DRecHits.stripDigiTag = cms.InputTag("muonCSCDigis","MuonCSCStripDigi")


###############################
## fix for next PAT sequence ##
process.pfBasedElectronIsoSequence.remove(process.elPFIsoDepositCharged)
process.electronPFIsolationDepositsSequence.remove( process.elPFIsoDepositCharged )

process.pfBasedElectronIsoSequence.remove(process.elPFIsoDepositChargedAll)
process.electronPFIsolationDepositsSequence.remove( process.elPFIsoDepositChargedAll )

process.pfBasedElectronIsoSequence.remove( process.elPFIsoDepositGamma )
process.electronPFIsolationDepositsSequence.remove( process.elPFIsoDepositGamma )

process.pfBasedElectronIsoSequence.remove( process.elPFIsoDepositNeutral )
process.electronPFIsolationDepositsSequence.remove( process.elPFIsoDepositNeutral )

process.pfBasedElectronIsoSequence.remove( process.elPFIsoDepositPU )
process.electronPFIsolationDepositsSequence.remove( process.elPFIsoDepositPU )



##--------------------------
## Define PAT sequence
##--------------------------
process.load("PhysicsTools.PatAlgos.patSequences_cff")
##process.patDefaultSequence.remove( process.elPFIsoDepositCharged )
#process.makePatElectrons.remove( process.elPFIsoDepositCharged )
#process.electronPFIsolationDepositsSequence.remove( process.elPFIsoDepositCharged )

#process.patDefaultSequence.remove( process.elPFIsoDepositChargedAll )
#process.makePatElectrons.remove( process.elPFIsoDepositChargedAll )
#process.electronPFIsolationDepositsSequence.remove( process.elPFIsoDepositChargedAll )

#process.patDefaultSequence.remove( process.elPFIsoDepositGamma )
#process.makePatElectrons.remove( process.elPFIsoDepositGamma )
#process.electronPFIsolationDepositsSequence.remove( process.elPFIsoDepositGamma )

#process.patDefaultSequence.remove( process.elPFIsoDepositNeutral )
#process.makePatElectrons.remove( process.elPFIsoDepositNeutral )
#process.electronPFIsolationDepositsSequence.remove( process.elPFIsoDepositNeutral )

#process.patDefaultSequence.remove( process.elPFIsoDepositPU )
#process.makePatElectrons.remove( process.elPFIsoDepositPU )
#process.electronPFIsolationDepositsSequence.remove( process.elPFIsoDepositPU )




##--------------------------
## Define PAT sequence
##--------------------------

## Standard PAT Configuration File
#process.load("PhysicsTools.PatAlgos.patSequences_cff")
#process.load("PhysicsTools.PatAlgos.producersLayer1.patCandidates_cff")
#process.load("PhysicsTools.PatAlgos.selectionLayer1.selectedPatCandidates_cff")



#process.load("EcalValidation.EcalAlignment.MyPat_cfi")
#process.load("PhysicsTools.PatAlgos.patSequences_cff")
#process.patDefaultSequence.remove( process.elPFIsoDepositCharged )

########################from PhysicsTools.PatAlgos.patSequences_cff import *

#########################patDefaultSequence.patCandidates.makePatElectrons.remove(elPFIsoDepositCharged)
########################patDefaultSequence.remove(elPFIsoDepositCharged)
########################process.mypatDefaultSequence = cms.Sequence()
########################process.mypatDefaultSequence = patDefaultSequence

from PhysicsTools.PatAlgos.tools.coreTools import *
# remove MC matching from the default sequence
if not options.isMC :
    removeMCMatching(process, ['All'])


# bugfix for DATA Run2011 (begin)
#removeSpecificPATObjects( process, ['Taus'] )
#process.patDefaultSequence.remove( process.patTaus )
# bugfix for DATA Run2011 (end)

## not used! (begin)
#removeSpecificPATObjects( process, ['Jets'] )
#process.patDefaultSequence.remove( process.patJetCorrections )
#process.patDefaultSequence.remove( process.patJets )
## not used (end)

## my DATA Run2012 (begin)
## process.patDefaultSequence.remove( process.pfJetMETcorr )
## process.patDefaultSequence.remove( process.pfType1CorrectedMet )
## process.patDefaultSequence.remove( process.pfType1p2CorrectedMet )

## my DATA Run2012 (end)


#process.patElectrons.electronSource = cms.InputTag("gsfElectrons::EcalAlignment")

#process.patElectrons.addElectronID = cms.bool(False)
  
## Add tcMET and pfMET
#from PhysicsTools.PatAlgos.tools.metTools import *
#addTcMET(process, 'TC')
#addPfMET(process, 'PF')



##--------------------------------
## correct dependencies RECO / PAT
## to avoid strange loop dependencies
##--------------------------------

#process.pfPileUpIso.PFCandidates       = cms.InputTag("particleFlowTmp")
#process.pfNoPileUpIso.bottomCollection = cms.InputTag("particleFlowTmp")




#process.pfPileUp.PFCandidates          = cms.InputTag("particleFlowTmpPtrs")
#process.pfPileUpIso.PFCandidates       = cms.InputTag("particleFlowTmpPtrs")

process.pfPileUp.PFCandidates          = cms.InputTag("particleFlowTmpPtrs")
process.pfPileUpIso.PFCandidates       = cms.InputTag("particleFlowTmpPtrs")
process.pfNoPileUp.bottomCollection    = cms.InputTag("particleFlowTmpPtrs")
process.pfNoPileUpIso.bottomCollection = cms.InputTag("particleFlowTmpPtrs")


process.patMuons.embedCaloMETMuonCorrs = cms.bool(False)


process.makePatJets = cms.Sequence(process.patJetCorrections+process.patJetCharge+process.patJets)
process.makePatPhotons = cms.Sequence(process.pfParticleSelectionForIsoSequence+process.pfPhotonIsolationSequence+process.patPhotons)
process.makePatTaus = cms.Sequence(process.patHPSPFTauDiscrimination+process.patPFCandidateIsoDepositSelection+process.patPFTauIsolation+process.patTaus)

process.patMuons.isoDeposits = cms.PSet()
process.patMuons.embedGenMatch = cms.bool(False)
process.patMuons.isolationValues = cms.PSet()        


process.particleFlow.GsfElectrons = cms.InputTag("gedGsfElectronsTmp") ## -> does it work?



#process.particleFlowPtrs.src           = cms.InputTag("particleFlowTmp")
    
process.muPFIsoDepositCharged.src      = cms.InputTag("muons1stStep")
process.muPFIsoDepositChargedAll.src   = cms.InputTag("muons1stStep")
process.muPFIsoDepositGamma.src        = cms.InputTag("muons1stStep")
process.muPFIsoDepositNeutral.src      = cms.InputTag("muons1stStep")
process.muPFIsoDepositPU.src           = cms.InputTag("muons1stStep")


#http://cmslxr.fnal.gov/lxr/source/CommonTools/ParticleFlow/python/Isolation/pfElectronIsolation_cff.py?v=CMSSW_7_2_0_pre6
#process.pfElectronIsolationSequence.replace(process.electronPFIsolationDepositsSequenXce+process.electronPFIsolationValuesSequence, process.electronPFIsolationValuesSequence)
#process.pfElectronIsolationSequence = cms.Sequence(
    ##process.electronPFIsolationDepositsSequenXce +
    #process.electronPFIsolationValuesSequence
#)

#process.patDefaultSequence.remove(process.particleFlowPtrs)
#process.patDefaultSequence.remove(patCandidates)
#process.patDefaultSequence.remove(selectedPatCandidates)
#process.patDefaultSequence.remove(cleanPatCandidates)
#process.patDefaultSequence.remove(countPatCandidates)
 
if not options.isMC :
    process.makePatElectrons.remove(process.electronMatch)
    process.makePatMuons.remove(process.muonMatch)




#from RecoParticleFlow/PFProducer/python/electronPFIsolationDeposits_cff.py import *
#process.elPFIsoDepositCharged = 


##--------------------------
## AllPassFilter
##--------------------------


##process.AllEvents                      = cms.EDProducer("EventCountProducer")
#process.load("EcalValidation.EcalAlignment.AllPassFilter_cfi")
##--------------------------
## Counter1: All read events
#process.AllEvents = process.AllPassFilter.clone()

#process.FilterL1FilterEvents           = cms.EDProducer("EventCountProducer")
#process.FilterGoodVertexFilterEvents   = cms.EDProducer("EventCountProducer")
#process.FilterNoScrapingFilterEvents   = cms.EDProducer("EventCountProducer")
#process.FilterElectronFilterEvents     = cms.EDProducer("EventCountProducer")
#process.FilterReRECOEvents             = cms.EDProducer("EventCountProducer")
#process.FilterPatDefaultSequenceEvents = cms.EDProducer("EventCountProducer")


##--------------------------
## ECAL alignment ntuple
##--------------------------

process.ntupleEcalAlignment = cms.EDAnalyzer(
    'EcalAlignment',

    recHitCollection_EB = cms.InputTag("reducedEcalRecHitsEB"),
    recHitCollection_EE = cms.InputTag("reducedEcalRecHitsEE"),
##    recHitCollection_EB = cms.InputTag("ecalRecHit","EcalRecHitsEB"),
##    recHitCollection_EE = cms.InputTag("ecalRecHit","EcalRecHitsEE"),
    EleTag              = cms.InputTag("patElectrons"),
    TrackTag            = cms.InputTag("generalTracks"),
    CALOMetTag          = cms.InputTag("patMETs"),
    vtxTag              = cms.InputTag("goodPrimaryVertices"),
    isMC                = cms.untracked.bool(False),
    debug               = cms.untracked.bool(False)
    )



process.TFileService = cms.Service(
    "TFileService",
    fileName = cms.string(options.outputFile)
    )


##--------------------------
## filters
##--------------------------

## filter on PhysDeclared bit
#process.skimming = cms.EDFilter(
    #"PhysDecl",
    #applyfilter = cms.untracked.bool(True),
    #debugOn = cms.untracked.bool(False),
    #HLTriggerResults = cms.InputTag("TriggerResults","","HLT")
    #)

## filter on bit = and (40 || 41) and !(bit36 || bit37 || bit38 || bit39)
#process.load('L1TriggerConfig.L1GtConfigProducers.L1GtTriggerMaskTechTrigConfig_cff')
#process.load('HLTrigger/HLTfilters/hltLevel1GTSeed_cfi')
#process.hltLevel1GTSeed.L1TechTriggerSeeding = cms.bool(True)
#process.hltLevel1GTSeed.L1SeedsLogicalExpression = cms.string('0 AND (40 OR 41) AND NOT (36 OR 37 OR 38 OR 39)')



VERTEX_SEL=("!isFake && ndof > 4 && abs(z) <= 24 && position.Rho <= 2")

process.goodPrimaryVertices = cms.EDFilter("VertexSelector",
  src = cms.InputTag("offlinePrimaryVertices"),
  cut = cms.string(VERTEX_SEL),
  filter = cms.bool(True),
)

## filter on primary vertex
#process.primaryVertexFilter = cms.EDFilter(
    #"GoodVertexFilter",
    #vertexCollection = cms.InputTag('offlinePrimaryVertices'),
    #minimumNDOF = cms.uint32(4) ,
    #maxAbsZ = cms.double(24),
    #maxd0 = cms.double(2)
    #)

## FilterOutScraping
#process.noscraping = cms.EDFilter(
    #"FilterOutScraping",
    #applyfilter = cms.untracked.bool(True),
    #debugOn = cms.untracked.bool(False),
    #numtrack = cms.untracked.uint32(10),
    #thresh = cms.untracked.double(0.25)
    #)

## select events with at least one gsf electron
process.highetele = cms.EDFilter(
    "GsfElectronSelector",
    #src = cms.InputTag("gsfElectrons","REDIGI311X"),
    #src = cms.InputTag("electrons","RECO"),
    #src = cms.InputTag("gsfElectrons","RECO"),
    src = cms.InputTag("gsfElectrons"),
    cut = cms.string("superCluster().get().energy()*sin(theta())> 0 ")
    )

#process.highetFilter = cms.EDFilter(
    #"CandViewCountFilter",
    #src = cms.InputTag("highetele"),
    #minNumber = cms.uint32(1)
    #)



##--------------------------
## paths
##--------------------------

#process.pEcalAlignmentFilter = cms.Path(
   #process.highetele
 #)


process.pEcalAlignment = cms.Path(
    #process.AllEvents   # |-> counter
    ##*process.skimming
    ##*process.FilterL1FilterEvents   # |-> counter
    ##*process.hltLevel1GTSeed
    #*process.FilterGoodVertexFilterEvents   # |-> counter   
    ##*process.primaryVertexFilter
    process.goodPrimaryVertices
    #*process.FilterNoScrapingFilterEvents   # |-> counter    
    ##*process.noscraping
    #*process.FilterElectronFilterEvents   # |-> counter   
    ##*process.highetele
    ##*process.highetFilter
    #*process.FilterReRECOEvents   # |-> counter   
    *process.patDefaultSequence
    #process.mypatDefaultSequence
    #*process.FilterPatDefaultSequenceEvents   # |-> counter
    *process.ntupleEcalAlignment
    )

process.patDefaultPath = cms.Path(process.patDefaultSequence)


#process.patCandidates.remove(process.makePatElectrons   )
#process.patCandidates.remove(process.makePatMuons       )
#process.patCandidates.remove(process.makePatTaus        )
#process.patCandidates.remove(process.makePatPhotons     )
#process.patCandidates.remove(process.makePatJets        )
#process.patCandidates.remove(process.makePatMETs        )
#process.patCandidates.remove(process.patCandidateSummary)


process.schedule = cms.Schedule(
   #process.pEcalAlignmentFilter, # | -> first filter! If run on RAW all
   process.raw2digi_step,        # | -> reconstruction
   process.L1Reco_step,          # | -> reconstruction
   process.reconstruction_step,  # | -> reconstruction
   process.endjob_step,          # | -> reconstruction
   #process.RECOoutput_step,      # | -> reconstruction
   #process.patDefaultPath,   # | -> pat creation
   process.pEcalAlignment        # | -> selections and ntuple
)


##process.schedule = cms.Schedule(
   ##process.pEcalAlignment        # | -> selections and ntuple
##)

