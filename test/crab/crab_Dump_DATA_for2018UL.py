from WMCore.Configuration import Configuration

config = Configuration()
config.section_('General')
config.General.transferOutputs = True
#config.General.requestName = 'DATAsingleEle'
#config.General.requestName = 'DATAdoubleEle22Jun_RAWRECO_v4'
#config.General.requestName = 'DATAdoubleEle28Jun_RAWRECO_RunA_v3_newdata'
#config.General.requestName = 'Data2018_MiniAOD_rawreco_test'
#config.General.requestName = 'Data2018_MiniAOD_rawreco_4Jun2018_newselections_withphion_onlyforEE'
#config.General.requestName = 'Data2018_MiniAOD_rawreco_post4Jun2018i_B_v1_postalignment'
# config.General.requestName = 'ZElectron-PromptReco-2018A-v1'
# config.General.requestName = 'ZElectron-PromptReco-2018A-v2'
# config.General.requestName = 'ZElectron-PromptReco-2018A-v3'
#config.General.requestName = 'ZElectron-PromptReco-2018B-v1'
#config.General.requestName = 'ZElectron-PromptReco-2018B-v2'
#config.General.requestName = 'ZElectron-PromptReco-2018C-v2'
config.General.requestName = 'EGamma_2018C_v1_RAW'
config.section_('JobType')
#config.JobType.psetName = '../RAW2RECO_DATA_cfg.py'
#config.JobType.psetName = '../Dump_DATA_cfg_2018.py'
#config.JobType.psetName = '../reco_RAW2DIGI_RECO2017.py'
#config.JobType.psetName = '../reco_RAW2DIGI_RECO2018.py'
config.JobType.psetName = '../config_for2018UL_new.py'
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
#config.Data.inputDataset = '/EGamma/Run2018A-PromptReco-v1/MINIAOD'
#config.Data.inputDataset = '/EGamma/Run2018A-ZElectron-PromptReco-v1/RAW-RECO'
#config.Data.inputDataset = '/EGamma/Run2018B-ZElectron-PromptReco-v1/RAW-RECO'
#config.Data.inputDataset = '/EGamma/Run2018C-ZElectron-PromptReco-v3/RAW-RECO'
#config.Data.inputDataset = '/EGamma/Run2018A-v1/RAW'
#config.Data.inputDataset = '/EGamma/Run2018A-EcalESAlign-PromptReco-v1/ALCARECO'
#config.Data.inputDataset = '/EGamma/Run2018C-ZElectron-PromptReco-v2/RAW-RECO'
config.Data.inputDataset = '/EGamma/Run2018C-v1/RAW'

config.Data.unitsPerJob = 10   # since files based, 10 files per job
config.Data.inputDBS = 'https://cmsweb.cern.ch/dbs/prod/global/DBSReader/'
#config.Data.publishDBS = 'https://cmsweb.cern.ch/dbs/prod/phys03/DBSWriter/'
config.Data.splitting = 'LumiBased'
#config.Data.splitting = 'FileBased'# FileBased
#config.Data.useParent = True           # Important!
#config.Data.runRange = '319579-319580'
#config.Data.runRange = '193650-193686'
#config.Data.runRange = '316060-316219'
# config.Data.runRange = '317434-318944'
config.Data.lumiMask = '/afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions18/13TeV/DCSOnly/json_DCSONLY.txt'
#config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/twamorka/28Jun_RunA_v3_newdata'
#config.JobType.inputFiles = ['../EBAlign_2015_jun282017.db','../EEAlign_2015_jun282017_rotationon.db']
#config.JobType.inputFiles = ['../EBAlign_2018.db','../EEAlign_2018.db']
#config.JobType.inputFiles = ['../EBAlign_2018_25May_check.db','../EEAlign_2018_25May_check.db']
#config.JobType.inputFiles = ['../EBAlign_2018_6May.db','../EEAlign_2018_25May_check.db']
#config.JobType.inputFiles = ['../EBAlign_2018_3Jun_newselections.db','../EEAlign_2018_3Jun_newselections_onlyphion.db']
# config.JobType.inputFiles = ['../EBAlign_2018_post4Jun.db','../EEAlign_2018_post4Jun.db']
#config.JobType.inputFiles = ['../EBAlign_2018_postJun4_repriseJul9.db','../EEAlign_2018_postJun4_repriseJul9.db']
#config.JobType.inputFiles = ['../EBAlign_2018_postJun4_repriseJul12.db','../EEAlign_2018_postJun4_repriseJul12.db']
#config.JobType.inputFiles = ['../EBAlign_2018_postJun4_repriseJul12_angleson.db','../EEAlign_2018_postJun4_repriseJul12_angleson.db']
#config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/twamorka/Alignment_2018/Run2018C_v3/'
#config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/twamorka/Alignment_2018/Run2018C_v2/'
config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/twamorka/'
config.section_('Site')
config.Site.storageSite = 'T2_CH_CERN'
