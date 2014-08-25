import FWCore.ParameterSet.Config as cms

process = cms.Process("TEST")

process.inputTree = cms.PSet(
  nameTree = cms.string("ntupleEcalAlignment/myTree"),
  #selection = cms.string("(ETSC>20 && met>20 && mishits <= 0 && MT>30)"),
   
   selection = cms.string("(ETSC>30 && met>30 && mishits <= 0 && MT>50) && ((abs(eta) <= 1.5 && (eleTrkIso + eleEcalIso + eleHcalIsoD1 + eleHcalIsoD2)/pT < 0.07 && abs(SigmaIEtaIEta)<0.01) || (abs(eta) >= 1.5 && (eleTrkIso + eleEcalIso + eleHcalIsoD1 + eleHcalIsoD2)/pT < 0.06 && abs(SigmaIEtaIEta)<0.03))"),
     
  #selection = cms.string("(1)"),
   #selection = cms.string("(eleFBrem<0.8)"),
#  selection = cms.string("(eleFBrem<0.3)"),
#  selection = cms.string("(eleFBrem<0.8&&eleCharge>0)"),
#  selection = cms.string("(eleFBrem<0.8&&eleCharge<0)"),
 # selection = cms.string("1"),
  traslationX = cms.bool(True),
  traslationY = cms.bool(True),
  traslationZ = cms.bool(True),
  rotationPhi   = cms.bool(False),
  rotationTheta = cms.bool(False),
  rotationPsi   = cms.bool(False),

  setRotationPhi   = cms.untracked.double(0),
  setRotationTheta = cms.untracked.double(0),
  setRotationPsi   = cms.untracked.double(0),

  DetaBias = cms.untracked.string("(x>0 && x<1.5) * (-0.000249) + (x>1.5) * (-8.3e-05) + (x<0 && x>-1.5) * (0.000291) + (x<-1.5) * (8.3e-05) + y*0"), 
  DphiBias = cms.untracked.string("(y>0)*((x>0 && x<1.5) * 0.0015 + (x>1.5) * 0.00136 + (x<0 && x>-1.5) * 0.000719 + (x<-1.5) * 0.00139) + (y<0)*((x>0 && x<1.5) * (-0.000813) + (x>1.5) * (-0.00139) + (x<0 && x>-1.5) * (-0.00157) + (x<-1.5) * (-0.00142))"),


  #inputFilesPosition    = cms.untracked.string(
         #'myEBAlignment_2010_OLD.txt'
    #),

  inputFiles    = cms.vstring(
          '/tmp/amassiro/EcalAlignment_RawReco_Tag_FT_R_53_LV4_05Aug2013.root'
    )
)


process.outputTree = cms.PSet(
  outputFile = cms.string("myEBAlignment_2011_new2011MCbias_reprocessing.txt")
)

