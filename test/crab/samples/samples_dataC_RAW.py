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



config.General.workArea     = 'crab_projects_29Aug_fromRaw_allDataC'
config.JobType.psetName = '../reco_RAW2DIGI_RECO_AOD.py'
config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/DATA29Aug2015AODRAWAllData'
config.Data.lumiMask = "/afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions15/13TeV/Cert_246908-254879_13TeV_PromptReco_Collisions15_JSON.txt"
config.JobType.maxMemoryMB = 2500    # 2.5 GB



