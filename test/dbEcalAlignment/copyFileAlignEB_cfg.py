import FWCore.ParameterSet.Config as cms

process = cms.Process("ECALAlignent")

process.load("CalibCalorimetry.EcalTrivialCondModules.EcalTrivialCondRetriever_cfi")

process.EcalTrivialConditionRetriever.getEBAlignmentFromFile = cms.untracked.bool(True)
process.EcalTrivialConditionRetriever.EBAlignmentFile = cms.untracked.string('EcalValidation/EcalAlignment/alignment_values/EBAlignment_test_combined.txt') ## Link to the txt file containing the EB Alignment coefficient (result of CombineRotoTraslations)

process.load("CondCore.DBCommon.CondDBCommon_cfi")

process.CondDBCommon.connect = 'sqlite_file:EBAlign_test.db' ## name of output .db file

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
