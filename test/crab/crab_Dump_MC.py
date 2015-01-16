from WMCore.Configuration import Configuration

config = Configuration()
config.section_('General')
config.General.transferOutputs = True
config.General.requestName = 'MC'

config.section_('JobType')
config.JobType.psetName = '../Dump_MC_cfg.py'
config.JobType.pluginName = 'Analysis'
config.JobType.outputFiles = ['treeECALAlignment.root']
config.JobType.pyCfgParams = ['inputFiles=FAKEINPUT', 'outputFile=treeECALAlignment.root']
config.section_('Data')

config.Data.inputDataset = '/DYToEE_M-50_Tune4C_13TeV-pythia8/Phys14DR-PU40bx25_tsg_castor_PHYS14_25_V1-v2/AODSIM'
config.Data.unitsPerJob = 10000
config.Data.inputDBS = 'https://cmsweb.cern.ch/dbs/prod/global/DBSReader/'
#config.Data.publishDBS = 'https://cmsweb.cern.ch/dbs/prod/phys03/DBSWriter/'
config.Data.splitting = 'FileBased'    #'EventBased'

config.Data.outLFN = '/store/user/amassiro/ECAL/Alignment/test16Jan2015'

config.section_('Site')
config.Site.storageSite = 'T2_CH_CERN'
