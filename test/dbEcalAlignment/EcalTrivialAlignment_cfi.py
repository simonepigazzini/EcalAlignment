import FWCore.ParameterSet.Config as cms

#from ​CalibCalorimetry.EcalTrivialCondModules.EcalTrivialCondRetriever_cfi import EcalTrivialConditionRetriever
#EcalTrivialConditionRetriever.getEEAlignmentFromFile = cms.untracked.bool(True)
#EcalTrivialConditionRetriever.EEAlignmentFile = cms.untracked.string('EcalValidation/EcalAlignment/test/myEEAlignment_2010.txt')
#EcalTrivialConditionRetriever.getESAlignmentFromFile = cms.untracked.bool(True)
#EcalTrivialConditionRetriever.ESAlignmentFile = cms.untracked.string('CalibCalorimetry/EcalTrivialCondModules/data/ESAlignment_2010.txt')
#EcalTrivialConditionRetriever.getEBAlignmentFromFile = cms.untracked.bool(True)
#EcalTrivialConditionRetriever.EBAlignmentFile = cms.untracked.string('EcalValidation/EcalAlignment/test/myEBAlignment_2010.txt')
    
    
EcalTrivialConditionRetriever = cms.ESSource("EcalTrivialConditionRetriever",
    getEEAlignmentFromFile = cms.untracked.bool(True),
    EEAlignmentFile = cms.untracked.string('EcalValidation/EcalAlignment/test/myEEAlignment_2010.txt'),
    getESAlignmentFromFile = cms.untracked.bool(True),
    ESAlignmentFile = cms.untracked.string('CalibCalorimetry/EcalTrivialCondModules/data/ESAlignment_2010.txt'),
    getEBAlignmentFromFile = cms.untracked.bool(True),
    EBAlignmentFile = cms.untracked.string('EcalValidation/EcalAlignment/test/myEBAlignment_2010.txt'),
    
    
    producedEcalClusterLocalContCorrParameters = cms.untracked.bool(True),
    producedEcalClusterCrackCorrParameters = cms.untracked.bool(True),
    producedEcalClusterEnergyCorrectionParameters = cms.untracked.bool(True),
    producedEcalClusterEnergyUncertaintyParameters = cms.untracked.bool(True),


)
