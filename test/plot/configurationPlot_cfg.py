import FWCore.ParameterSet.Config as cms

process = cms.Process("TEST")


process.ConfigurationToDraw = cms.PSet(
  nameInFileRoot = cms.string("/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amkrishn/ECALalignment2022run3Commisioning/data/2022C/EGamma/crab_EcalAlignment_RERECO_2022C_with_rotationEE/220812_190006/0000/treeECALAlignment_run3_withRotationEE.root"),  #data after alignment
  nameInFileRootComparison = cms.string("/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amkrishn/ECALalignment2022run3Commisioning/MC/DYJetsToLL_M-50_TuneCP5_13p6TeV-madgraphMLM-pythia8/crab_MC_2022_Run3commisioning/220705_182016/0000/treeECALAlignment_MC2022.root"),  #MC
    nameOutputDir = cms.string("/eos/user/a/amkrishn/www/EcalAlignment/MC2022_run3Commisioning/validation_plots/with_rotationEE/test"),  #output directory
  commonCut = cms.string("electrons_classification==0 && ETSC>20 && mll<100 && mll>80"),
    specialZeroTesla = cms.untracked.int32(2),   # 2 = special binning for public

    onlyRMS = cms.untracked.int32(1),   # 1 = special for public to show only RMS

  treeName = cms.untracked.string("ntupleEcalAlignment/myTree"),  
  
  nameInFileRootAlternative = cms.untracked.string("/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amkrishn/ECALalignment2022run3Commisioning/data/automationOutputHadd/treeECALAlignment_run3Commissioning_2022C.root"),  #data before alignment


)

