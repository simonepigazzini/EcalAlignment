import FWCore.ParameterSet.Config as cms

process = cms.Process("TEST")

# scp amassiro@cmsneu.cern.ch:/media/data/amassiro/ECALalignment/2016/May25/MC/ECAL_DYMC.root  /tmp/amassiro/

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



process.ConfigurationToDraw = cms.PSet(
  nameInFileRoot = cms.string("/tmp/amassiro/data_newECAL_newTrk_EEfix_SignOk_30May_andNewEB_newJSON.root"),
  nameInFileRootComparison = cms.string("/tmp/amassiro/ECAL_DYMC.root"),
  nameOutputDir = cms.string("2016TCodeCompiled_newECAL_newTrk_1Jun_newJSON"),
  commonCut = cms.string("electrons_classification==0 && ETSC>20 && mll<95 && mll>85"),
  specialZeroTesla = cms.untracked.int32(0),
)



