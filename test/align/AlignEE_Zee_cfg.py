import FWCore.ParameterSet.Config as cms

process = cms.Process("Minimization")

process.inputTree = cms.PSet(
  nameTree = cms.string("ntupleEcalAlignment/myTree"),
  #selection = cms.string("(ETSC>20 && met>30 && mishits <= 0 && MT>30)"),

  #selection = cms.string("(electrons_classification==0 && ETSC>20)"),
  #selection = cms.string("(electrons_classification==0 && ETSC>30) && ((abs(eta) <= 1.5 && (eleTrkIso + eleEcalIso + eleHcalIsoD1 + eleHcalIsoD2)/pT < 0.07 && abs(SigmaIEtaIEta)<0.01) || (abs(eta) >= 1.5 && (eleTrkIso + eleEcalIso + eleHcalIsoD1 + eleHcalIsoD2)/pT < 0.06 && abs(SigmaIEtaIEta)<0.03))"),
  selection = cms.string("(electrons_classification==0 && ETSC>20) && mll<95 && mll>85 && ((abs(eta) <= 1.5 && (eleTrkIso + eleEcalIso + eleHcalIsoD1 + eleHcalIsoD2)/pT < 0.07 && abs(SigmaIEtaIEta)<0.01) || (abs(eta) >= 1.5 && (eleTrkIso + eleEcalIso + eleHcalIsoD1 + eleHcalIsoD2)/pT < 0.06 && abs(SigmaIEtaIEta)<0.03))"),


#selection = cms.string("(1)"),
  #selection = cms.string("(eleFBrem<0.8)"),
#  selection = cms.string("(eleFBrem<0.8&&eleCharge>0)"),
  #selection = cms.string("(eleFBrem<0.8&&eleCharge<0)"),
#  selection = cms.string("1"),


  traslationX = cms.bool(True),
  traslationY = cms.bool(True),
  traslationZ = cms.bool(True),
#  rotationPhi   = cms.bool(True), # True
  rotationPhi = cms.bool(False),
  rotationTheta = cms.bool(False),
  rotationPsi   = cms.bool(False), # True

  setRotationPhi   = cms.untracked.double(0),
  setRotationTheta = cms.untracked.double(0),
  setRotationPsi   = cms.untracked.double(0),

# Put MC Deta and DPhi bias values here:

# For eg: these are 2017 values (Plots for ref: https://indico.cern.ch/event/648996/contributions/2638537/attachments/1484713/2304818/TanviWamorkar_MoCaJun28.pdf)
# DPhi values are different for electrons and positrons because of their opposite bending in the Phi direction under the magnetic field
# DEta values follow the sequence: EB+, EE+, EB-, EE-
# DPhi values follow the sequence: [Positron: EB+, EE+, EB-, EE-], [Electron: EB+, EE+, EB-, EE-]
DetaBias = cms.untracked.string(" (x>0.0 && x<1.5)  * (-0.27e-3) \
                                   +(x>1.5)           * (-0.09e-3)    \
                                   +(x<0.0 && x>-1.5) * (0.17e-3)    \
                                   +(x<-1.5)          * (0.14e-3) \
                                   + y*0"),

  DphiBias = cms.untracked.string(" (y>0)*    \
                                  ((x>0.0 && x<1.5)   * (1.02e-3)  \
                                 + (x>1.5)            * (0.46e-3)  \
                                 + (x<0.0 && x>-1.5)  * (0.28e-3)  \
                                 + (x<-1.5)           * (0.48e-03)) \
                                 + (y<0)*   \
                                   ((x>0.0 && x<1.5)   * (-0.23e-03) \
                                 + (x>1.5)             * (-0.38e-03) \
                                 + (x<0.0 && x>-1.5)  * (-0.93e-03)  \
                                 + (x<-1.5)           * (-0.33e-03))"),
  ## change input file appropriately
  inputFiles    = cms.vstring(
          'file:///eos/cms/store/group/dpg_ecal/alca_ecalcalib/twamorka/UltraLegacy_WithTrackerConditions_Conditions2/DoubleEG/crab_ZElectron-2017B-RAWReco-v1/190502_160024/0000/treeECALAlignment_499.root'

    )
)


process.outputTree = cms.PSet(
  outputFile = cms.string("myEEAlignment")
)
