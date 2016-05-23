import FWCore.ParameterSet.Config as cms

process = cms.Process("TEST")

process.inputTree = cms.PSet(
  nameTree = cms.string("ntupleEcalAlignment/myTree"),
  #selection = cms.string("(ETSC>20 && met>30 && mishits <= 0 && MT>30)"),
  
  #selection = cms.string("(electrons_classification==0 && ETSC>20)"),    
  selection = cms.string("(electrons_classification==0 && ETSC>30) && ((abs(eta) <= 1.5 && (eleTrkIso + eleEcalIso + eleHcalIsoD1 + eleHcalIsoD2)/pT < 0.07 && abs(SigmaIEtaIEta)<0.01) || (abs(eta) >= 1.5 && (eleTrkIso + eleEcalIso + eleHcalIsoD1 + eleHcalIsoD2)/pT < 0.06 && abs(SigmaIEtaIEta)<0.03))"),

#selection = cms.string("(1)"),
  #selection = cms.string("(eleFBrem<0.8)"),
#  selection = cms.string("(eleFBrem<0.8&&eleCharge>0)"),
  #selection = cms.string("(eleFBrem<0.8&&eleCharge<0)"),
#  selection = cms.string("1"),


  traslationX = cms.bool(True),
  traslationY = cms.bool(True),
  traslationZ = cms.bool(True),
  rotationPhi   = cms.bool(True), # True
  rotationTheta = cms.bool(False),
  rotationPsi   = cms.bool(False), # True

  setRotationPhi   = cms.untracked.double(0),
  setRotationTheta = cms.untracked.double(0),
  setRotationPsi   = cms.untracked.double(0),

  #DetaBias = cms.untracked.string("(x>0.0 && x<1.5)   * (-(0.4e-3)) + (x>1.5 && x<2.0)   * (2.45513e-03*(x-1.75))   + (x>2.0)            * ((6.137825e-04)/2.)   + (x<0.0 && x>-1.5)  * (0.4e-3)   + (x<-1.5 && x>-2.0) * (2.45513e-03*(x+1.75))        + (x<-2.0)           * ((-6.137825e-04)/2.) + y*0"),
  #DetaBias = cms.untracked.string("(x>0.0 && x<1.5)   * (-(0.23e-3)) + (x>1.5 && x<2.0)   * (2.45513e-03*(x-1.75))   + (x>2.0)            * ((6.137825e-04)/2.)   + (x<0.0 && x>-1.5)  * (0.23e-3)   + (x<-1.5 && x>-2.0) * (2.45513e-03*(x+1.75))        + (x<-2.0)           * ((-6.137825e-04)/2.) + y*0"),
  #DetaBias = cms.untracked.string("(x>0.0 && x<1.5)   * (-(0.23e-3)) + (x>1.5) * (-0.05e-3) + (x<0.0 && x>-1.5)  * (0.23e-3)   + (x<-1.5) * (0.05e-3) + y*0"),   # TEST
  #DphiBias = cms.untracked.string("(y>0)*((x>0.0 && x<1.5)   * (1.46233e-03)  + (x>1.5)            * (2.73084e-03)  + (x<0.0 && x>-1.5)  * (6.59298e-04)  + (x<-1.5)           * (2.57010e-03)) + \
                                   #(y<0)*((x>0.0 && x<1.5)   * (-7.24105e-04)  + (x>1.5)            * (-1.992615e-03)  + (x<0.0 && x>-1.5)  * (-1.527137e-03)  + (x<-1.5)           * (-3.437939e-03))"),
        
  # 2016

  #
  DetaBias = cms.untracked.string("    (x>0.0 && x<1.5)   * (-(0.30e-3)) \
                                     + (x>1.5)            * (0.05)  \
                                     + (x<0.0 && x>-1.5)  * (0.19e-3)  \
                                     + (x<-1.5)           * (-(0.01e-3))   \
                                     + y*0"),  
  
  DphiBias = cms.untracked.string("(y>0)*    \
                                  ((x>0.0 && x<1.5)   * (1.49e-03)  \
                                 + (x>1.5)            * (2.15e-03)  \
                                 + (x<0.0 && x>-1.5)  * (0.74e-03)  \
                                 + (x<-1.5)           * (2.16e-03)) \
                                 + (y<0)*   \
                                   ((x>0.0 && x<1.5)   * (-0.67e-03) \
                                 + (x>1.5)             * (-2.03e-03) \
                                 + (x<0.0 && x>-1.5)  * (-1.39e-03)  \
                                 + (x<-1.5)           * (-2.05e-03))"),
        
        
  #inputFilesPosition    = cms.untracked.string(
         #'myEEAlignment_2010_OLD.txt'
  #),
   
  inputFiles    = cms.vstring(
          #'root://eoscms.cern.ch//store/user/amassiro/ECAL/Alignment/test13Mar2015/DYToEE_M-50_Tune4C_13TeV-pythia8/crab_DYll/150315_215425/0000/treeECALAlignment_2.root'
               #'root://eoscms.cern.ch//store/user/amassiro/ECAL/Alignment/test13Mar2015/DYToEE_M-50_Tune4C_13TeV-pythia8/crab_DYll/150315_215425/0000/treeECALAlignment_1.root',

          #'root://eoscms.cern.ch//eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/DATA14Jul2015/SingleElectron/crab_SingleElectron/150715_154047/treeECALAlignment_DATA_oldTrkAlign.root'
          #'file:/tmp/amassiro/treeECALAlignment_DATA_oldTrkAlign.root'
          
          #/tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/DATA22Jul2015AODRAW/SingleElectron/crab_SingleElectron/150721_164215/
          #'file:/tmp/amassiro/dataNewTrk.root'

          #/tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/DATA29Jul2015AODRAWAllData/SingleElectron/crab_SingleElectron/150728_162006/treeECALnewTrkOldEcal.root
          #'file:/tmp/amassiro/treeECALnewTrkOldEcal.root'

   #hadd /tmp/amassiro/treeECALAlignment.root \
        #/tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/DATA29Aug2015AODAllData/SingleElectron/crab_SingleElectron/150827_143017/treeECALAlignment.root    \
        #/tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/DATA29Aug2015AODRAWAllData/SingleElectron/crab_SingleElectron/150826_214823/treeECALAlignment.root  

          'file:/tmp/amassiro/treeECALAlignment.root'


    #'crab/DATAJSONPrompt_SingleElectron_Run2011A-PromptReco-v4_AOD.root'
         #'crab/DATAJSONRawRecoRealign_Correct_Rome_CorrectReAlignDB/SingleElectron_Run2011A-WElectron-PromptSkim-v4_RAW-RECO/newsum.root'
         #'EcalAlignmentJoin.root'
    )
)


process.outputTree = cms.PSet(
  #outputFile = cms.string("myEEAlignment_2015_MCtest.txt")
  #outputFile = cms.string("myEEAlignment_2015_OldTrkAlign.txt")
  #outputFile = cms.string("myEEAlignment_2015_NewTrkAlign.txt")
  #outputFile = cms.string("myEEAlignment_2015_NewTrkAlign_31Aug2015.txt")
  #outputFile = cms.string("myEEAlignment_2015_NewTrkAlign_13Oct2015.txt")
  #outputFile = cms.string("myEEAlignment_2015_NewTrkAlign_23Oct2015.txt")
  #outputFile = cms.string("myEEAlignment_2015_NewTrkAlign_26Oct2015.txt")
  outputFile = cms.string("myEEAlignment_2016_NewTrkAlign_23May2016.txt")
)

