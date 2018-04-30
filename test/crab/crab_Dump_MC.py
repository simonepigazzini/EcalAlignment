from WMCore.Configuration import Configuration

config = Configuration()
config.section_('General')
config.General.transferOutputs = True
config.General.requestName = 'MC_2018'

config.section_('JobType')
config.JobType.psetName = '../Dump_MC_cfg.py'
config.JobType.pluginName = 'Analysis'
config.JobType.outputFiles = ['treeECALAlignment.root']
config.JobType.pyCfgParams = ['inputFiles=FAKEINPUT', 'outputFile=treeECALAlignment.root']

config.section_('Data')
#config.Data.inputDataset = '/DYToEE_M-50_Tune4C_13TeV-pythia8/Phys14DR-PU40bx25_tsg_castor_PHYS14_25_V1-v2/AODSIM'
#config.Data.inputDataset = '/DYToEE_M-50_Tune4C_13TeV-pythia8/Phys14DR-PU40bx25_tsg_castor_PHYS14_25_V1-v2/AODSIM'
config.Data.inputDataset = '/DYJetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/RunIISpring18MiniAOD-NZSPU40to70_100X_upgrade2018_realistic_v10-v2/MINIAODSIM'
config.Data.unitsPerJob = 10   # since files based, 10 files per job
config.Data.inputDBS = 'https://cmsweb.cern.ch/dbs/prod/global/DBSReader/'
#config.Data.publishDBS = 'https://cmsweb.cern.ch/dbs/prod/phys03/DBSWriter/'
config.Data.splitting = 'FileBased'    #'LumiBased'

#config.Data.outLFN = '/store/user/amassiro/ECAL/Alignment/test16Jan2015'
config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/twamorka/Alignment_2018/MC_2018'
config.section_('Site')
config.Site.storageSite = 'T2_CH_CERN'
