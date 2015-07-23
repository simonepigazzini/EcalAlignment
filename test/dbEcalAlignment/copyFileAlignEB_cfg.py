import FWCore.ParameterSet.Config as cms

process = cms.Process("TEST")
#process.load("EcalTrivialAlignment_cfi")
process.load("CalibCalorimetry.EcalTrivialCondModules.EcalTrivialCondRetriever_cfi")

process.EcalTrivialConditionRetriever.getEBAlignmentFromFile = cms.untracked.bool(True)
process.EcalTrivialConditionRetriever.EBAlignmentFile = cms.untracked.string('EcalValidation/EcalAlignment/test/myEBAlignment_2015_NewTrkAlign.txt')


process.load("CondCore.DBCommon.CondDBCommon_cfi")

#process.CondDBCommon.connect = 'sqlite_file:EBAlign_2010_GlobalAlignment.db'
#process.CondDBCommon.connect = 'sqlite_file:EBAlign_2011.db'
#process.CondDBCommon.connect = 'sqlite_file:EBAlign_2010_NoAlign.db'

process.CondDBCommon.connect = 'sqlite_file:EBAlign_2015.db'

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
          record = cms.string('EBAlignmentRcd'),
          tag = cms.string('EBAlignment_measured_v05_offline')
       )
    )
)

process.dbCopy = cms.EDAnalyzer("EcalDBCopy",
    timetype = cms.string('runnumber'),
    toCopy = cms.VPSet( 
       cms.PSet(
          record = cms.string('EBAlignmentRcd'),
          container = cms.string('EBAlignment')
       )
    )
)


process.prod = cms.EDAnalyzer("EcalTrivialObjectAnalyzer")

process.p = cms.Path(process.prod*process.dbCopy)

