from WMCore.Configuration import Configuration

config = Configuration()
config.section_('General')
config.General.transferOutputs = True
#config.General.requestName = 'EcalAlignment_dump_DATA'
config.General.requestName = 'EcalAlignment_RERECO_2022C_with_symmMCbias'

config.section_('JobType')
#config.JobType.psetName = '../RAW2RECO_DATA_cfg.py'
config.JobType.psetName = '../rereco_cfg.py'
config.JobType.pluginName = 'Analysis'
config.JobType.outputFiles = ['treeECALAlignment.root']
config.JobType.pyCfgParams = ['inputFiles=FAKEINPUT', 'outputFile=treeECALAlignment.root']
config.JobType.maxMemoryMB = 5000 
config.JobType.inputFiles = ['EEAlign_run3_v4.db','EBAlign_run3_v0.db']
#config.JobType.priority = 30
#config.JobType.numCores = 2

config.section_('Data')
#config.Data.inputDataset = '/EGamma/Run2018A-12Nov2019_UL2018-v2/MINIAOD' 
#config.Data.inputDataset = '/SingleElectron/Run2015B-PromptReco-v1/AOD'
config.Data.inputDataset = '/EGamma/Run2022C-ZElectron-PromptReco-v1/RAW-RECO'
config.Data.unitsPerJob = 3   # since files based, 3 files per job  
#config.Data.inputDBS = 'https://cmsweb.cern.ch/dbs/prod/global/DBSReader/'
#config.Data.publishDBS = 'https://cmsweb.cern.ch/dbs/prod/phys03/DBSWriter/'
config.Data.splitting = 'FileBased'    # LumiBased
#config.Data.splitting = 'Automatic'
#config.Data.useParent = True           #Important! is it?
config.Data.runRange = '355862-356719'

#config.Data.outLFN = '/store/user/amassiro/ECAL/Alignment/test16Mar2015'
#config.Data.outLFN = '/store/group/dpg_ecal/alca_ecalcalib/amkrishn/ECAL_Alignment_test_Commissioning2021/' 
config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/amkrishn/ECALalignment2022run3Commisioning/data/2022C'

config.section_('Site')
config.Site.storageSite = 'T2_CH_CERN'
