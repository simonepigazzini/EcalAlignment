# manage input variables                                                                                                                                                                                  
from FWCore.ParameterSet.VarParsing import VarParsing
options = VarParsing ('analysis')
# add a list of strings for events to process                                                                                                                                                             
options.parseArguments()

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

#process.outpath = cms.EndPath(process.out)                                                                                                                                                                


process.schedule = cms.Schedule(
   process.pEcalAlignment        # | -> selections and ntuple                                                                                                                                              
)


process.options.allowUnscheduled = cms.untracked.bool( True )

