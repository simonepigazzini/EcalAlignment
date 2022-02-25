from WMCore.Configuration import Configuration
#from CRABClient.Configuration import Configuration

config = Configuration()
config.section_('General')
config.General.transferOutputs = True
#config.General.requestName = 'DATAsingleEle'
config.General.requestName = 'DATA2018UL_withCutBasedID'

config.section_('JobType')
#config.JobType.psetName = '../RAW2RECO_DATA_cfg.py'
config.JobType.psetName = '../Dump_DATA_cfg.py'
config.JobType.pluginName = 'Analysis'
config.JobType.outputFiles = ['treeECALAlignment.root']
config.JobType.pyCfgParams = ['inputFiles=FAKEINPUT', 'outputFile=treeECALAlignment.root']

config.section_('Data')
config.Data.inputDataset = '/EGamma/Run2018A-12Nov2019_UL2018-v2/MINIAOD' 
#config.Data.inputDataset = '/SingleElectron/Run2015B-PromptReco-v1/AOD'
#config.Data.inputDataset = '/DoubleElectron/Run2012D-22Jan2013-v1/AOD'
config.Data.unitsPerJob = 3   # since files based, 10 files per job  
config.Data.inputDBS = 'https://cmsweb.cern.ch/dbs/prod/global/DBSReader/'
#config.Data.publishDBS = 'https://cmsweb.cern.ch/dbs/prod/phys03/DBSWriter/'
config.Data.splitting = 'LumiBased'    # FileBased
config.Data.useParent = True           # Important!
config.Data.runRange = '315267-315322'
config.Data.lumiMask = '/afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions18/13TeV/DCSOnly/json_DCSONLY.txt'
#config.Data.outLFN = '/store/user/amassiro/ECAL/Alignment/test16Mar2015'
#config.Data.outLFN = '/store/group/dpg_ecal/alca_ecalcalib/amkrishn/ECAL_Alignment_test_Commissioning2021/' 
config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/amkrishn/ECAL_Alignment_2018UL_test/WithCutBasedID'

config.section_('Site')
config.Site.storageSite = 'T2_CH_CERN'
