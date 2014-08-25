from WMCore.Configuration import Configuration

config = Configuration()
config.section_('General')
config.General.transferOutput = False
config.General.requestName = 'MC'

config.section_('JobType')
config.JobType.psetName = '../Dump_MC_cfg.py'
config.JobType.pluginName = 'Analysis'
config.JobType.outputFiles = ['treeECALAlignment.root']
config.JobType.pyCfgParams = ['inputFiles=FAKEINPUT', 'outputFile=treeECALAlignment.root']
config.section_('Data')

config.Data.inputDataset = '/DYToEE_M_50_628_EGamma_13TeV/Summer12-PU_S14_DESIGN70_V7-v1/AODSIM'
config.Data.unitsPerJob = 10000
config.Data.dbsUrl = 'https://cmsweb.cern.ch/dbs/prod/global/DBSReader/'
config.Data.publishDbsUrl = 'https://cmsweb.cern.ch/dbs/prod/phys03/DBSWriter/'
config.Data.splitting = 'FileBased'    #'EventBased'

#config.section_('User')
#config.User.email = 'Andrea.Massironi@cern.ch'

config.section_('Site')
#config.Site.blacklist = ['T0', 'T1']
config.Site.storageSite = 'T2_CH_CERN'
