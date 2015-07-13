########
# Data
########

#        CRAB task name          DAS name                                                                                                              
samples['SingleElectron']   = ['/SingleElectron/Run2015B-PromptReco-v1/AOD',  ['outputFile=treeECALAlignment.root']]
samples['DoubleEG']          = ['/DoubleEG/Run2015B-PromptReco-v1/AOD',  ['outputFile=treeECALAlignment.root']]


########
# Alternative global configuration
########

config.JobType.psetName = '../Dump_DATA_cfg.py'
config.Data.unitsPerJob   = 10
config.Data.outLFNDirBase = '/store/user/amassiro/ECAL/Alignment/data09Jul2015'
config.Data.lumiMask = "json.txt"

config.General.workArea     = 'crab_projects_13July'


