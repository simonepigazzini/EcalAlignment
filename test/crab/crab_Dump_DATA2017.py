from WMCore.Configuration import Configuration

config = Configuration()
config.section_('General')
config.General.transferOutputs = True
#config.General.requestName = 'DATAsingleEle'
#config.General.requestName = 'DATAdoubleEle22Jun_RAWRECO_v4'
config.General.requestName = 'DATAdoubleEle23Jun_RAWRECO_runA'
config.section_('JobType')
#config.JobType.psetName = '../RAW2RECO_DATA_cfg.py'
#config.JobType.psetName = '../Dump_DATA_cfg.py'
config.JobType.psetName = '../reco_RAW2DIGI_RECO2017.py'
config.JobType.pluginName = 'Analysis'
config.JobType.outputFiles = ['treeECALAlignment.root']
config.JobType.pyCfgParams = ['inputFiles=FAKEINPUT', 'outputFile=treeECALAlignment.root']

config.section_('Data')
#config.Data.inputDataset = '/SingleElectron/Run2015B-PromptReco-v1/AOD'
#config.Data.inputDataset = '/DoubleElectron/Run2012D-22Jan2013-v1/AOD'
#-------2017---------
#config.Data.inputDataset = '/DoubleEG/Run2017A-PromptReco-v3/MINIAOD'
config.Data.inputDataset = '/DoubleEG/Run2017A-ZElectron-PromptReco-v2/RAW-RECO'
config.Data.unitsPerJob = 10   # since files based, 10 files per job
config.Data.inputDBS = 'https://cmsweb.cern.ch/dbs/prod/global/DBSReader/'
#config.Data.publishDBS = 'https://cmsweb.cern.ch/dbs/prod/phys03/DBSWriter/'
config.Data.splitting = 'LumiBased'    # FileBased
config.Data.useParent = True           # Important!
#config.Data.runRange = '193650-193686'
config.Data.lumiMask = '/afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions17/13TeV/DCSOnly/json_DCSONLY.txt'
config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/twamorka/23Jun_Run2017A_v2_RAWRECO_parentsettrue'

config.section_('Site')
config.Site.storageSite = 'T2_CH_CERN'
