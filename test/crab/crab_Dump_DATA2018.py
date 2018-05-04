from WMCore.Configuration import Configuration

config = Configuration()
config.section_('General')
config.General.transferOutputs = True
#config.General.requestName = 'DATAsingleEle'
#config.General.requestName = 'DATAdoubleEle22Jun_RAWRECO_v4'
#config.General.requestName = 'DATAdoubleEle28Jun_RAWRECO_RunA_v3_newdata'
#config.General.requestName = 'Data2018_MiniAOD_rawreco_test'
config.General.requestName = 'Data2018_MiniAOD_rawreco_3May2018_v6'

config.section_('JobType')
#config.JobType.psetName = '../RAW2RECO_DATA_cfg.py'
#config.JobType.psetName = '../Dump_DATA_cfg.py'
#config.JobType.psetName = '../reco_RAW2DIGI_RECO2017.py'
config.JobType.psetName = '../reco_RAW2DIGI_RECO2018.py'
config.JobType.pluginName = 'Analysis'
config.JobType.outputFiles = ['treeECALAlignment.root']
config.JobType.pyCfgParams = ['inputFiles=FAKEINPUT', 'outputFile=treeECALAlignment.root']

config.section_('Data')
#config.Data.inputDataset = '/SingleElectron/Run2015B-PromptReco-v1/AOD'
#config.Data.inputDataset = '/DoubleElectron/Run2012D-22Jan2013-v1/AOD'
#-------2017---------
#config.Data.inputDataset = '/DoubleEG/Run2017A-PromptReco-v3/MINIAOD'
#config.Data.inputDataset = '/DoubleEG/Run2017A-ZElectron-PromptReco-v3/RAW-RECO'
#-------2018---------
config.Data.inputDataset = '/EGamma/Run2018A-PromptReco-v1/MINIAOD'
#config.Data.inputDataset = '/EGamma/Run2018A-ZElectron-PromptReco-v1/RAW-RECO'
config.Data.unitsPerJob = 10   # since files based, 10 files per job
config.Data.inputDBS = 'https://cmsweb.cern.ch/dbs/prod/global/DBSReader/'
#config.Data.publishDBS = 'https://cmsweb.cern.ch/dbs/prod/phys03/DBSWriter/'
config.Data.splitting = 'LumiBased'
#config.Data.splitting = 'FileBased'# FileBased
config.Data.useParent = True           # Important!
#config.Data.runRange = '193650-193686'
config.Data.lumiMask = '/afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions18/13TeV/DCSOnly/json_DCSONLY.txt'
#config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/twamorka/28Jun_RunA_v3_newdata'
#config.JobType.inputFiles = ['../EBAlign_2015_jun282017.db','../EEAlign_2015_jun282017_rotationon.db']
config.JobType.inputFiles = ['../EBAlign_2018.db','../EEAlign_2018.db']
config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/twamorka/Alignment_2018/3May2018'
config.section_('Site')
config.Site.storageSite = 'T2_CH_CERN'
