import FWCore.ParameterSet.Config as cms

process = cms.Process("TEST")

process.ConfigurationToDraw = cms.PSet(
  nameInFileRoot = cms.string("/tmp/amassiro/data_noECAL_newTrk_24Nov.root"),
  nameInFileRootComparison = cms.string("/tmp/amassiro/ECAL_DYMC.root"),
  nameOutputDir = cms.string("2016TestNewCodeCompiled"),
  commonCut = cms.string("electrons_classification==0 && ETSC>30 && mll<95 && mll>85"),
  specialZeroTesla = cms.untracked.int32(0),
)

