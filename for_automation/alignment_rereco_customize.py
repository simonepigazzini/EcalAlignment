# manage input variables                                                                                                                                                                                  
from FWCore.ParameterSet.VarParsing import VarParsing

def customize_alignment_reco(process):

    options = VarParsing ('analysis')
    # add a list of strings for events to process                                                                                                                                                             
    options.parseArguments()

    process.GlobalTag.toGet = cms.VPSet(


                                        cms.PSet(record = cms.string("EEAlignmentRcd"),
                                        tag = cms.string("EEAlignment_measured_run3_v4_offline"),
                                        connect = cms.string("sqlite_file:EEAlign_run3_v4.db")
                                                #connect = cms.string("sqlite_file:EEAlign_2018_25May_check.db")                                                                                             
                                        #connect = cms.string("sqlite_file:EEAlign_2018_3Jun_newselections_onlyphion.db")                                                                                      
                                    ),
    #                                                                                                                                                                                                          
    #                                                                                                                                                                                                          
                                        cms.PSet(record = cms.string("EBAlignmentRcd"),
                                        tag = cms.string("EBAlignment_measured_run3_v0_offline"),
                                        connect = cms.string("sqlite_file:EBAlign_run3_v0.db")
    #   #                                  connect = cms.string("sqlite_file:EBAlign_2018_3Jun_newselections.db")                                                                                              
                                                ),

    #                                                                                                                                                                                                          
    #                                     #EcalPedestals_Legacy2017_time_v1                                                                                                                                    
    #                                     #EcalPulseShapes_October2017_rereco_v1                                                                                                                               
    #                                                                                                                                                                                                          
    )

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


    process.schedule += cms.Schedule(
    process.pEcalAlignment        # | -> selections and ntuple                                                                                                                                              
    )

    return process

