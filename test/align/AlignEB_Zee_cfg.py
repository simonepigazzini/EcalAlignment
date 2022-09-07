import FWCore.ParameterSet.Config as cms

process = cms.Process("Minimization")

process.inputTree = cms.PSet(
  nameTree = cms.string("ntupleEcalAlignment/myTree"),


  #selection = cms.string("(electrons_classification==0 && ETSC>20)"),

  selection = cms.string("(electrons_classification==0 && ETSC>20) && mll<100 && mll>80  && ((abs(eta) <= 1.5 && (eleTrkIso + eleEcalIso + eleHcalIsoD1 + eleHcalIsoD2)/pT < 0.07 && abs(SigmaIEtaIEta)<0.01) || (abs(eta) >= 1.5 && (eleTrkIso + eleEcalIso + eleHcalIsoD1 + eleHcalIsoD2)/pT < 0.06 && abs(SigmaIEtaIEta)<0.03))"),

#selection = cms.string("(electrons_classification==0 && ETSC>40) && mll<95 && mll>85 && etaSC < 2.1 && etaSC > -2.1 && HoE<0.3 && eleEcalIso<15 && (abs(DeltaEtaIn)<(25e-3)) && (abs(DeltaPhiIn)<(10e-3))&& ((abs(eta) <= 1.5 && (eleTrkIso + eleEcalIso + eleHcalIsoD1 + eleHcalIsoD2)/pT < 0.07 && abs(SigmaIEtaIEta)<0.01) || (abs(eta) >= 1.5 && (eleTrkIso + eleEcalIso + eleHcalIsoD1 + eleHcalIsoD2)/pT < 0.06 && abs(SigmaIEtaIEta)<0.03))"),

 #selection = cms.string("(ETSC>30 && mishits <= 0 ) && ((abs(eta) <= 1.5 && (eleTrkIso + eleEcalIso + eleHcalIsoD1 + eleHcalIsoD2)/pT < 0.07 && abs(SigmaIEtaIEta)<0.01) || (abs(eta) >= 1.5 && (eleTrkIso + eleEcalIso + eleHcalIsoD1 + eleHcalIsoD2)/pT < 0.06 && abs(SigmaIEtaIEta)<0.03))"),
  #selection = cms.string("1"),

  #even = cms.untracked.bool(False), # only "odd" events are used
  #odd  = cms.untracked.bool(False), # only "even" events are used

## Chi^2 is calculated and minimized w.r.t the 3D translations (x,y,z) (plus three Euler angles in the endcap) is performed
## This is why traslationX, traslationY and traslationZ are set to True and rotationPhi, rotationTheta and rotationPsi are set to False. This means that the Chi2 will be calculated and minimized only w.r.t x, y and z.

  traslationX = cms.bool(True),
  traslationY = cms.bool(True),
  traslationZ = cms.bool(True),
    rotationPhi   = cms.bool(False),
    rotationTheta = cms.bool(False),
    rotationPsi   = cms.bool(False),

  setRotationPhi   = cms.untracked.double(0),
  setRotationTheta = cms.untracked.double(0),
  setRotationPsi   = cms.untracked.double(0),


# Put MC Deta and DPhi bias values here:

# DPhi values are different for electrons and positrons because of their opposite bending in the Phi direction under the magnetic field
# DEta values follow the sequence: EB+, EE+, EB-, EE-
# DPhi values follow the sequence: [Positron: EB+, EE+, EB-, EE-], [Electron: EB+, EE+, EB-, EE-]
# x = eta, y = charge

    DetaBias = cms.untracked.string(" (x>0.0 && x<1.5)  * (-0.17e-3)\
                                   +(x>1.5)           * (-0.36e-3)    \
                                   +(x<0.0 && x>-1.5) * (0.19e-3)    \
                                   +(x<-1.5)          * (0.26e-3) \
                                   + y*0"),

  DphiBias = cms.untracked.string(" (y>0)*    \
                                  ((x>0.0 && x<1.5)   * (0.95e-3)  \
                                 + (x>1.5)            * (0.07e-3)  \
                                 + (x<0.0 && x>-1.5)  * (0.26e-3)  \
                                 + (x<-1.5)           * (-0.1e-5)) \
                                 + (y<0)*   \
                                   ((x>0.0 && x<1.5)   * (-0.19e-3) \
                                 + (x>1.5)             * (0.18e-3) \
                                 + (x<0.0 && x>-1.5)  * (-0.85e-3)  \
                                 + (x<-1.5)           * (0.19e-3))"),
  ## change input file appropriately
  inputFiles    = cms.vstring(
      #    'file:///eos/cms/store/group/dpg_ecal/alca_ecalcalib/twamorka/UltraLegacy_WithTrackerConditions_Conditions2/DoubleEG/crab_ZElectron-2017B-RAWReco-v1/190502_160024/0000/treeECALAlignment_499.root'
      'file:///eos/cms/store/group/dpg_ecal/alca_ecalcalib/amkrishn/ECALalignment2022run3Commisioning/data/automationOutputHadd/treeECALAlignment_run3Commissioning_2022C.root'
    #'file:///eos/cms/store/group/dpg_ecal/alca_ecalcalib/amkrishn/ECALalignment2022run3Commisioning/data/automationOutputHadd/treeECALAlignment_run3Commissioning_2022C_860pb.root'
#'file:/afs/cern.ch/user/a/amkrishn/CMSSW_12_0_0/src/EcalValidation/EcalAlignment/test/output.root'

    )
)


process.outputTree = cms.PSet(
   outputFile = cms.string("EBAlignmentCoefficients")
)
