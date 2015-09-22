########
# Data
########

#        CRAB task name          DAS name                      
samples['SingleElectron']   = ['/ElectronStream/Run2015B-v1/RAW',  ['outputFile=treeECALAlignment.root']]
#config.Data.useParent = True           # Important!

########
# Alternative global configuration
########

config.Data.splitting = 'LumiBased'    # FileBased
#config.Data.splitting = 'FileBased'    # FileBased
config.Data.unitsPerJob   = 1   # 10 was too much? Error 50660: too much ram


config.General.workArea     = 'crab_projects_22Sep_fromRaw_newECAL_lastTrk_allData_RunB_ElectronStream'
config.JobType.psetName = '../reco_STREAMRAW2DIGI_RECO_AOD.py'
config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/DATA22Sep2015AODRAWAllDataRunBlastTrkElectronStream'
config.Data.lumiMask = "/afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions15/13TeV/Cert_246908-254879_13TeV_PromptReco_Collisions15_JSON.txt"
config.JobType.maxMemoryMB = 2500    # 2.5 GB
config.JobType.maxJobRuntimeMin = 2800
config.JobType.inputFiles = ['../EBAlign_2015.db','../EEAlign_2015.db']

