from WMCore.Configuration import Configuration

config = Configuration()
config.section_('General')
config.General.transferOutputs = True
config.General.requestName = 'crab_MC_2022_afterBugFix'

config.section_('JobType')
config.JobType.psetName = '../Dump_MC_cfg.py'
config.JobType.pluginName = 'Analysis'
config.JobType.outputFiles = ['treeECALAlignment.root']
config.JobType.pyCfgParams = ['inputFiles=FAKEINPUT', 'outputFile=treeECALAlignment.root']

config.section_('Data')
#config.Data.inputDataset = '/DYToEE_M-50_Tune4C_13TeV-pythia8/Phys14DR-PU40bx25_tsg_castor_PHYS14_25_V1-v2/AODSIM'
#config.Data.inputDataset = '/DYToEE_M-50_Tune4C_13TeV-pythia8/Phys14DR-PU40bx25_tsg_castor_PHYS14_25_V1-v2/AODSIM'
config.Data.inputDataset = '/DYJetsToLL_M-50_TuneCP5_13p6TeV-madgraphMLM-pythia8/Run3Winter22MiniAOD-122X_mcRun3_2021_realistic_v9_ext1-v1/MINIAODSIM'
config.Data.unitsPerJob = 2   # since files based, 10 files per job
config.Data.inputDBS = 'https://cmsweb.cern.ch/dbs/prod/global/DBSReader/'
#config.Data.publishDBS = 'https://cmsweb.cern.ch/dbs/prod/phys03/DBSWriter/'
config.Data.splitting = 'FileBased'

#config.Data.outLFN = '/store/user/amassiro/ECAL/Alignment/test16Jan2015'
config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/amkrishn/ECALalignment2022run3Commisioning/MC/DYJetsToLL_M-50_TuneCP5_13p6TeV-madgraphMLM-pythia8/'
config.section_('Site')
config.Site.storageSite = 'T2_CH_CERN'



