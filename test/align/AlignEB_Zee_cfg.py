import FWCore.ParameterSet.Config as cms

process = cms.Process("Minimization")

process.inputTree = cms.PSet(
  nameTree = cms.string("ntupleEcalAlignment/myTree"),


  #selection = cms.string("(electrons_classification==0 && ETSC>20)"),

  selection = cms.string("electrons_classification==0 && ETSC>20 && pT>20 && mll<95 && mll>85 && EGMcutBasedElectronIDloose == 1"),

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
    DetaBias = cms.untracked.string(" (x>0.0 && x<1.5)  * (-0.000220745) \
                                   +(x>1.5)           * (-6.32983e-05) \
                                   +(x<0.0 && x>-1.5) * (4.21639e-05) \
                                   +(x<-1.5)          * (4.21639e-05) \
                                   + y*0"),

  DphiBias = cms.untracked.string(" (y>0)*    \
                                  ((x>0.0 && x<1.5)   * (0.00135071)  \
                                 + (x>1.5)            * (0.00107073)  \
                                 + (x<0.0 && x>-1.5)  * (0.00108263)  \
                                 + (x<-1.5)           * (0.00108263))  \
                                 + (y<0)*   \
                                   ((x>0.0 && x<1.5)   * (-0.00057967) \
                                 + (x>1.5)             * (-0.000969591) \
                                 + (x<0.0 && x>-1.5)  * (-0.000970262)  \
                                 + (x<-1.5)           * (-0.000970262))"),

  ## change input file appropriately
  inputFiles    = cms.vstring(
      #    'file:///eos/cms/store/group/dpg_ecal/alca_ecalcalib/twamorka/UltraLegacy_WithTrackerConditions_Conditions2/DoubleEG/crab_ZElectron-2017B-RAWReco-v1/190502_160024/0000/treeECALAlignment_499.root'
    #  'file:/afs/cern.ch/user/a/amkrishn/private/ECAL_Alignment/data/test_forAmrutha.root'
 'file:/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amkrishn/ECAL_Alignment_2018UL_test/WithCutBasedID/EGamma/crab_DATA2018UL_withCutBasedID/211213_125955/0000/treeECALAlignment_withCutBasedID_full.root'

    )
)


process.outputTree = cms.PSet(
   outputFile = cms.string("EBAlignment_UL2018test_new.txt")
)
