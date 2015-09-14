########
# Data
########

#        CRAB task name          DAS name                                                                                                              

samples['SingleElectron']   = ['/SingleElectron/Run2015C-PromptReco-v1/AOD',  ['outputFile=treeECALAlignment.root']]
#samples['DoubleEG']          = ['/DoubleEG/Run2015B-PromptReco-v1/AOD',  ['outputFile=treeECALAlignment.root']]
config.Data.useParent = True           # Important!

########
# Alternative global configuration
########

config.Data.splitting = 'LumiBased'    # FileBased
#config.Data.splitting = 'FileBased'    # FileBased
config.Data.unitsPerJob   = 1   # 10 was too much? Error 50660: too much ram
config.Data.runRange = '251562-254790'



#config.General.workArea     = 'crab_projects_29Aug_fromRaw_allDataC'
#config.JobType.psetName = '../reco_RAW2DIGI_RECO_AOD.py'
#config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/DATA29Aug2015AODRAWAllData'
#config.Data.lumiMask = "/afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions15/13TeV/Cert_246908-254879_13TeV_PromptReco_Collisions15_JSON.txt"
#config.JobType.maxMemoryMB = 2500    # 2.5 GB



#config.General.workArea     = 'crab_projects_31Aug_fromRaw_newECAL_allData_RunC'
#config.JobType.psetName = '../reco_my_tag_RAW2DIGI_RECO_AOD.py'
#config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/DATA31Aug2015AODRAWAllDataRunC'
#config.Data.lumiMask = "/afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions15/13TeV/Cert_246908-254879_13TeV_PromptReco_Collisions15_JSON.txt"
#config.JobType.maxMemoryMB = 2500    # 2.5 GB
#config.JobType.inputFiles = ['../EBAlign_2015.db','../EEAlign_2015.db', '../TkAlignment.db']




#config.General.workArea     = 'crab_projects_04Sep_fromRaw_newECAL_allData_RunC'
#config.JobType.psetName = '../reco_my_tag_RAW2DIGI_RECO_AOD.py'
#config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/DATA04Sep2015AODRAWAllDataRunC'
#config.Data.lumiMask = "/afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions15/13TeV/Cert_246908-254879_13TeV_PromptReco_Collisions15_JSON.txt"
#config.JobType.maxMemoryMB = 2500    # 2.5 GB
#config.JobType.inputFiles = ['../EBAlign_2015.db','../EEAlign_2015.db', '../TkAlignment.db']



#config.General.workArea     = 'crab_projects_05Sep_fromRaw_newECAL_allData_RunC'
#config.JobType.psetName = '../reco_my_tag_RAW2DIGI_RECO_AOD.py'
#config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/DATA05Sep2015AODRAWAllDataRunC'
#config.Data.lumiMask = "/afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions15/13TeV/Cert_246908-254879_13TeV_PromptReco_Collisions15_JSON.txt"
#config.JobType.maxMemoryMB = 2500    # 2.5 GB
#config.JobType.inputFiles = ['../EBAlign_2015.db','../EEAlign_2015.db', '../TkAlignment.db']



#config.General.workArea     = 'crab_projects_05Sep_fromRaw_newECAL_lastTrk_allData_RunC'
#config.JobType.psetName = '../reco_my_tag_RAW2DIGI_RECO_AOD.py'
#config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/DATA05Sep2015AODRAWAllDataRunClastTrk'
#config.Data.lumiMask = "/afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions15/13TeV/Cert_246908-254879_13TeV_PromptReco_Collisions15_JSON.txt"
#config.JobType.maxMemoryMB = 2500    # 2.5 GB
#config.JobType.inputFiles = ['../EBAlign_2015.db','../EEAlign_2015.db']



config.General.workArea     = 'crab_projects_07Sep_fromRaw_newECAL_lastTrk_allData_RunC'
config.JobType.psetName = '../reco_my_tag_RAW2DIGI_RECO_AOD.py'
config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/DATA07Sep2015AODRAWAllDataRunClastTrk'
config.Data.lumiMask = "/afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions15/13TeV/Cert_246908-254879_13TeV_PromptReco_Collisions15_JSON.txt"
config.JobType.maxMemoryMB = 2500    # 2.5 GB
config.JobType.inputFiles = ['../EBAlign_2015.db','../EEAlign_2015.db', '../alignments_MP.db']





