import FWCore.ParameterSet.Config as cms

process = cms.Process("TEST")

process.inputTree = cms.PSet(
  nameTree = cms.string("ntupleEcalAlignment/myTree"),
  
  selection = cms.string("(electrons_classification==0 && ETSC>30) && mll<95 && mll>85  && HoE<0.3 && eleEcalIso<15)")
  

  traslationX = cms.bool(True),
  traslationY = cms.bool(True),
  traslationZ = cms.bool(True),
  rotationPhi   = cms.bool(False), # True
  rotationTheta = cms.bool(False),
  rotationPsi   = cms.bool(False), # True

  setRotationPhi   = cms.untracked.double(0),
  setRotationTheta = cms.untracked.double(0),
  setRotationPsi   = cms.untracked.double(0),

  DetaBias = cms.untracked.string("(x>0.0 && x<1.5)   * (-(0.24e-3)) + (x>1.5) * (-1.35e-3) + (x<0.0 && x>-1.5)  * (0.24e-3)   + (x<-1.5) * (1.35e-3) + y*0"), 
  DphiBias = cms.untracked.string("(y>0)*((x>0.0 && x<1.5)   * (1.46233e-03)  + (x>1.5)            * (2.73084e-03)  + (x<0.0 && x>-1.5)  * (6.59298e-04)  + (x<-1.5)           * (2.57010e-03)) + \
                                   (y<0)*((x>0.0 && x<1.5)   * (-7.24105e-04)  + (x>1.5)            * (-1.992615e-03)  + (x<0.0 && x>-1.5)  * (-1.527137e-03)  + (x<-1.5)           * (-3.437939e-03))"),
        
  #inputFilesPosition    = cms.untracked.string(
         #'myEEAlignment_2010_OLD.txt'
  #),
   
  inputFiles    = cms.vstring(
          'file:/tmp/amassiro/data_0T.root.root'
    )
)


process.outputTree = cms.PSet(
  outputFile = cms.string("myEEAlignment_2015_18Jan2016_0Tesla.txt")
)



