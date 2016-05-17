########
# Data
########

#        CRAB task name          DAS name                                 
samples['SingleElectron']   = ['/SingleElectron/Run2015D-PromptReco-v3/AOD',  ['outputFile=treeECALAlignment.root']]

 


########
# Alternative global configuration
########

config.JobType.psetName = '../Dump_DATA_cfg.py'
config.Data.splitting = 'LumiBased'    # FileBased
config.Data.unitsPerJob   = 10
# config.Data.runRange = '251562-254790'



config.JobType.psetName = '../reco_my_tag_RAW2DIGI_RECO_AOD.py'
config.JobType.maxMemoryMB = 2500    # 2.5 GB

config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/2016/May17ZeroAlignmentEEEB'
config.Data.lumiMask = "/afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions16/13TeV/DCSOnly/json_DCSONLY.txt"
config.General.workArea     = 'crab_projects_May17ZeroAlignmentEEEB'
config.Data.allowNonValidInputDataset = True
config.JobType.inputFiles = ['../EBAlign_2015.db','../EEAlign_2015.db']

