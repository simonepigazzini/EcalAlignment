from WMCore.Configuration import Configuration

config = Configuration()
config.section_('General')
config.General.transferOutputs = True
config.General.requestName = 'MC_2018_new'

config.section_('JobType')
config.JobType.psetName = '../Dump_MC_cfg.py'
config.JobType.pluginName = 'Analysis'
config.JobType.outputFiles = ['treeECALAlignment.root']
config.JobType.pyCfgParams = ['inputFiles=FAKEINPUT', 'outputFile=treeECALAlignment.root']

config.section_('Data')
#config.Data.inputDataset = '/DYToEE_M-50_Tune4C_13TeV-pythia8/Phys14DR-PU40bx25_tsg_castor_PHYS14_25_V1-v2/AODSIM'
config.Data.inputDataset = '/DYJetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/RunIISummer19UL18MiniAOD-106X_upgrade2018_realistic_v11_L1v1-v1/MINIAODSIM'
#config.Data.inputDataset = '/DY1JetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/RunIISummer19UL18MiniAODv2-106X_upgrade2018_realistic_v16_L1v1-v1/MINIAODSIM'
config.Data.unitsPerJob = 3   # since files based, 10 files per job
config.Data.inputDBS = 'https://cmsweb.cern.ch/dbs/prod/global/DBSReader/'
#config.Data.publishDBS = 'https://cmsweb.cern.ch/dbs/prod/phys03/DBSWriter/'
config.Data.splitting = 'FileBased'    #'LumiBased'

#config.Data.outLFN = '/store/user/amassiro/ECAL/Alignment/test16Jan2015'
config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/amkrishn/ECAL_Alignment_2018UL_test/MC_new/'
config.section_('Site')
config.Site.storageSite = 'T2_CH_CERN'
