import FWCore.ParameterSet.Config as cms

process = cms.Process("TEST")
#process.load("EcalTrivialAlignment_cfi")
process.load("CalibCalorimetry.EcalTrivialCondModules.EcalTrivialCondRetriever_cfi")

process.EcalTrivialConditionRetriever.getEEAlignmentFromFile = cms.untracked.bool(True)
#process.EcalTrivialConditionRetriever.EEAlignmentFile = cms.untracked.string('EcalValidation/EcalAlignment/test/myEEAlignment_2015_NewTrkAlign.txt')
#process.EcalTrivialConditionRetriever.EEAlignmentFile = cms.untracked.string('EcalValidation/EcalAlignment/test/myEEAlignment_2015.txt')
#process.EcalTrivialConditionRetriever.EEAlignmentFile = cms.untracked.string('EcalValidation/EcalAlignment/test/myEEAlignment_2015_combined.txt')
#process.EcalTrivialConditionRetriever.EEAlignmentFile = cms.untracked.string('EcalValidation/EcalAlignment/test/myEEAlignment_2015_combined_27Oct.txt')

# 0 Tesla
#process.EcalTrivialConditionRetriever.EEAlignmentFile = cms.untracked.string('EcalValidation/EcalAlignment/test/myEEAlignment_2015_0Tesla_combined.txt')
process.EcalTrivialConditionRetriever.EEAlignmentFile = cms.untracked.string('EcalValidation/EcalAlignment/test/myEEAlignment_2015_0Tesla_19Jan_combined.txt')



process.load("CondCore.DBCommon.CondDBCommon_cfi")

#process.CondDBCommon.connect = 'sqlite_file:EEAlign_2010_GlobalAlignment.db'
#process.CondDBCommon.connect = 'sqlite_file:EEAlign_2011.db'
#process.CondDBCommon.connect = 'sqlite_file:EEAlign_2010_NoAlign.db'

process.CondDBCommon.connect = 'sqlite_file:EEAlign_2015.db'

process.MessageLogger = cms.Service("MessageLogger",
    debugModules = cms.untracked.vstring('*'),
    destinations = cms.untracked.vstring('cout')
)

process.source = cms.Source("EmptyIOVSource",
    firstValue = cms.uint64(1),
    lastValue = cms.uint64(1),
    timetype = cms.string('runnumber'),
    interval = cms.uint64(1)
)

process.PoolDBOutputService = cms.Service("PoolDBOutputService",
    process.CondDBCommon,
    timetype = cms.untracked.string('runnumber'),
    toPut = cms.VPSet(
       cms.PSet(
          record = cms.string('EEAlignmentRcd'),
          tag = cms.string('EEAlignment_measured_v05_offline')
       )
    )
)

process.dbCopy = cms.EDAnalyzer("EcalDBCopy",
    timetype = cms.string('runnumber'),
    toCopy = cms.VPSet( 
       cms.PSet(
          record = cms.string('EEAlignmentRcd'),
          container = cms.string('EEAlignment')
       )
    )
)


process.prod = cms.EDAnalyzer("EcalTrivialObjectAnalyzer")

process.p = cms.Path(process.prod*process.dbCopy)


