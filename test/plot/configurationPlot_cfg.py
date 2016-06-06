import FWCore.ParameterSet.Config as cms

process = cms.Process("TEST")

# scp amassiro@cmsneu.cern.ch:/media/data/amassiro/ECALalignment/2016/May25/MC/ECAL_DYMC.root  /tmp/amassiro/
# scp amassiro@cmsneu.cern.ch:/media/data/amassiro/ECALalignment/2016/May25/MC/ECAL_DYMC_small.root    /tmp/amassiro/
# cp /tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/MC07May2016/DYToEE_NNPDF30_13TeV-powheg-pythia8/ECAL_DYMC_small.root    /tmp/amassiro/ 


#process.ConfigurationToDraw = cms.PSet(
  #nameInFileRoot = cms.string("/tmp/amassiro/data_noECAL_newTrk_24Nov.root"),
  #nameInFileRootComparison = cms.string("/tmp/amassiro/ECAL_DYMC.root"),
  #nameOutputDir = cms.string("2016TCodeCompiled_NewTrk_NewPix_ZeroECAL_27May"),
  #commonCut = cms.string("electrons_classification==0 && ETSC>20 && mll<95 && mll>85"),
  #specialZeroTesla = cms.untracked.int32(0),
#)

#process.ConfigurationToDraw = cms.PSet(
  #nameInFileRoot = cms.string("/tmp/amassiro/data_newECAL_newTrk_25Nov.root"),
  #nameInFileRootComparison = cms.string("/tmp/amassiro/ECAL_DYMC.root"),
  #nameOutputDir = cms.string("2016TCodeCompiled_NewTrk_NewPix_NewECAL_27May"),
  #commonCut = cms.string("electrons_classification==0 && ETSC>20 && mll<95 && mll>85"),
  #specialZeroTesla = cms.untracked.int32(0),
#)


#process.ConfigurationToDraw = cms.PSet(
  #nameInFileRoot = cms.string("/tmp/amassiro/data_newECAL_newTrk_EEfix_28Nov.root"),
  #nameInFileRootComparison = cms.string("/tmp/amassiro/ECAL_DYMC.root"),
  #nameOutputDir = cms.string("2016TCodeCompiled_NewTrk_NewPix_NewECAL_EEfix_28May"),
  #commonCut = cms.string("electrons_classification==0 && ETSC>20 && mll<95 && mll>85"),
  #specialZeroTesla = cms.untracked.int32(0),
#)



#process.ConfigurationToDraw = cms.PSet(
  #nameInFileRoot = cms.string("/tmp/amassiro/data_newECAL_newTrk_EEfix_SignOk_29May.root"),
  #nameInFileRootComparison = cms.string("/tmp/amassiro/ECAL_DYMC.root"),
  #nameOutputDir = cms.string("2016TCodeCompiled_NewTrk_NewPix_NewECAL_EEfix_SignFix_29May"),
  #commonCut = cms.string("electrons_classification==0 && ETSC>20 && mll<95 && mll>85"),
  #specialZeroTesla = cms.untracked.int32(0),
#)



#process.ConfigurationToDraw = cms.PSet(
  #nameInFileRoot = cms.string("/tmp/amassiro/data_oldECAL_newTrk_30May.root"),
  #nameInFileRootComparison = cms.string("/tmp/amassiro/ECAL_DYMC.root"),
  #nameOutputDir = cms.string("2016TCodeCompiled_oldECAL_newTrk_30May"),
  #commonCut = cms.string("electrons_classification==0 && ETSC>20 && mll<95 && mll>85"),
  #specialZeroTesla = cms.untracked.int32(0),
#)


#process.ConfigurationToDraw = cms.PSet(
  #nameInFileRoot = cms.string("/tmp/amassiro/data_newECAL_newTrk_EEfix_SignOk_30May_andNewEB.root"),
  #nameInFileRootComparison = cms.string("/tmp/amassiro/ECAL_DYMC.root"),
  #nameOutputDir = cms.string("2016TCodeCompiled_newECAL_newTrk_1Jun"),
  #commonCut = cms.string("electrons_classification==0 && ETSC>20 && mll<95 && mll>85"),
  #specialZeroTesla = cms.untracked.int32(0),
#)



#process.ConfigurationToDraw = cms.PSet(
  #nameInFileRoot = cms.string("/tmp/amassiro/data_newECAL_newTrk_EEfix_SignOk_30May_andNewEB_newJSON.root"),
  #nameInFileRootComparison = cms.string("/tmp/amassiro/ECAL_DYMC.root"),
  #nameOutputDir = cms.string("2016TCodeCompiled_newECAL_newTrk_1Jun_newJSON"),
  #commonCut = cms.string("electrons_classification==0 && ETSC>20 && mll<95 && mll>85"),
  #specialZeroTesla = cms.untracked.int32(0),
#)




################################################################
# Pre-filter
#
# TFile *f1 = new TFile("/tmp/amassiro/data_newECAL_newTrk_EEfix_SignOk_30May_andNewEB_newJSON.root");
# TTree *ntuple = (TTree*) f1->Get("ntupleEcalAlignment/myTree");
# TFile *f2 = new TFile("/tmp/amassiro/data_newECAL_newTrk_EEfix_SignOk_30May_andNewEB_newJSON_small.root","recreate");
# TTree *small = ntuple->CopyTree("(electrons_classification==0 && ETSC>20 && ((abs(eta)<=1.5 && (eleTrkIso+eleEcalIso+eleHcalIsoD1+eleHcalIsoD2)/pT<0.07 && abs(SigmaIEtaIEta)<0.01) || (abs(eta)>=1.5 && (eleTrkIso+eleEcalIso+eleHcalIsoD1+eleHcalIsoD2)/pT<0.06 && abs(SigmaIEtaIEta)<0.03)) ) && electrons_classification==0 && ETSC>20 && mll<95 && mll>85");
# small->Write();
# .q
#
#
# TFile *f1 = new TFile("/tmp/amassiro/data_oldECAL_newTrk_30May.root");
# TTree *ntuple = (TTree*) f1->Get("ntupleEcalAlignment/myTree");
# TFile *f2 = new TFile("/tmp/amassiro/data_oldECAL_newTrk_30May_small.root","recreate");
# TTree *small = ntuple->CopyTree("(electrons_classification==0 && ETSC>20 && ((abs(eta)<=1.5 && (eleTrkIso+eleEcalIso+eleHcalIsoD1+eleHcalIsoD2)/pT<0.07 && abs(SigmaIEtaIEta)<0.01) || (abs(eta)>=1.5 && (eleTrkIso+eleEcalIso+eleHcalIsoD1+eleHcalIsoD2)/pT<0.06 && abs(SigmaIEtaIEta)<0.03)) ) && electrons_classification==0 && ETSC>20 && mll<95 && mll>85");
# small->Write();
# .q
#
################################################################
#
#
# cp /tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/2016/May31AlignmentEEEB_newTrk2016_newECAL_signFix_andNewEB_newJSON/DoubleEG/crab_DoubleElectron/data_newECAL_newTrk_EEfix_SignOk_30May_andNewEB_newJSON_small.root   /tmp/amassiro/ 
# cp /tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/2016/May28AlignmentEEEB_newTrk2016_oldECALfrom2015/DoubleEG/data_oldECAL_newTrk_30May_small.root   /tmp/amassiro/ 
#
#

process.ConfigurationToDraw = cms.PSet(
  nameInFileRoot = cms.string("/tmp/amassiro/data_newECAL_newTrk_EEfix_SignOk_30May_andNewEB_newJSON_small.root"),
  nameInFileRootComparison = cms.string("/tmp/amassiro/ECAL_DYMC_small.root"),
  nameOutputDir = cms.string("2016TCodeCompiled_newECAL_newTrk_1Jun_newJSON_forPublic"),
  commonCut = cms.string("electrons_classification==0 && ETSC>20 && mll<95 && mll>85"),
  specialZeroTesla = cms.untracked.int32(2),   # special binning for public

  onlyRMS = cms.untracked.int32(1),   # special for public to show only RMS

  treeName = cms.untracked.string("myTree"),  
  
  nameInFileRootAlternative = cms.untracked.string("/tmp/amassiro/data_oldECAL_newTrk_30May_small.root"),

)



