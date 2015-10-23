########
# Data
########

#        CRAB task name          DAS name                                 
samples['SingleElectron']   = ['/SingleElectron/Run2015D-PromptReco-v3/AOD',  ['outputFile=treeECALAlignment.root']]
samples['SingleElectronV4']   = ['/SingleElectron/Run2015D-PromptReco-v4/AOD',  ['outputFile=treeECALAlignment.root']]
config.Data.useParent = True           # Important!



########
# Alternative global configuration
########

config.Data.splitting = 'LumiBased'    # FileBased
config.Data.unitsPerJob   = 10
# config.Data.runRange = '251562-254790'

# 74X_dataRun2_Candidate_2015_10_09_09_41_36


#config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/DATA29Aug2015AODAllData'
#config.Data.lumiMask = "/afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions15/13TeV/Cert_246908-254879_13TeV_PromptReco_Collisions15_JSON.txt"
#config.General.workArea     = 'crab_projects_27Aug_PromptTrkAlign'



##config.JobType.psetName = '../reco_RAW2DIGI_RECO_AOD.py'
##config.JobType.maxMemoryMB = 2500    # 2.5 GB

##config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/DATA12Oct2015AODAllDataRunDRAW'
###config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/DATA13Oct2015AODAllDataRunDRAW'
##config.Data.lumiMask = "/afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions15/13TeV/Cert_246908-258159_13TeV_PromptReco_Collisions15_25ns_JSON_v3.txt"
##config.General.workArea     = 'crab_projects_12Oct_PromptTrkAlign_RunD_RAW'
###config.General.workArea     = 'crab_projects_13Oct_PromptTrkAlign_RunD_RAW'
##config.Data.allowNonValidInputDataset = True



#config.JobType.psetName = '../reco_my_tag_RAW2DIGI_RECO_AOD.py'
#config.JobType.maxMemoryMB = 2500    # 2.5 GB

#config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/DATA_14Oct2015_RunD_RAW_myTag'
#config.Data.lumiMask = "/afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions15/13TeV/Cert_246908-258159_13TeV_PromptReco_Collisions15_25ns_JSON_v3.txt"
#config.General.workArea     = 'crab_projects_14Oct_PromptTrkAlign_RunD_RAW_myTag'
#config.Data.allowNonValidInputDataset = True
#config.JobType.inputFiles = ['../EBAlign_2015.db','../EEAlign_2015.db']



config.JobType.psetName = '../reco_my_tag_RAW2DIGI_RECO_AOD.py'
config.JobType.maxMemoryMB = 2500    # 2.5 GB

config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/DATA_23Oct2015_RunD_RAW_myTag'
config.Data.lumiMask = "/afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions15/13TeV/Cert_246908-258750_13TeV_PromptReco_Collisions15_25ns_JSON.txt"
config.General.workArea     = 'crab_projects_23Oct_PromptTrkAlign_RunD_RAW_myTag'
config.Data.allowNonValidInputDataset = True
config.JobType.inputFiles = ['../EBAlign_2015.db','../EEAlign_2015.db']







