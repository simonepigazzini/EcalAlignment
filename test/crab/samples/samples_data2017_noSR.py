########
# Data
########

#        CRAB task name          DAS name                                 
#samples['DoubleElectrin2017B_v1']   = ['/DoubleEG/Run2017B-ZElectron-PromptReco-v1/RAW-RECO',        ['outputFile=treeECALAlignment.root']]
samples['DoubleElectrin2017C_v1']   = ['/DoubleEG/Run2017C-ZElectron-PromptReco-v1/RAW-RECO',        ['outputFile=treeECALAlignment.root']]
samples['DoubleElectrin2017D_v1']   = ['/DoubleEG/Run2017D-ZElectron-PromptReco-v1/RAW-RECO',        ['outputFile=treeECALAlignment.root']]



#config.Data.useParent = True           # Important!




########
# Alternative global configuration
########

config.JobType.psetName = '../reco_RAW2DIGI_RECO2017_noSRatPF.py'
config.Data.splitting = 'LumiBased'    # FileBased
config.Data.unitsPerJob   = 10
# config.Data.runRange = '251562-254790'


####config.Data.splitting = 'LumiBased'    # FileBased
#####config.Data.splitting = 'FileBased'    # FileBased
#####config.Data.unitsPerJob   = 1
####config.Data.unitsPerJob   = 3   # 1 is creating 12k jobs ... max from crab is 10k

#config.JobType.psetName = '../reco_RAW2DIGI_RECO_AOD.py'
#config.JobType.maxMemoryMB = 2500    # 2.5 GB








################


config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/amassiro/16Oct/noSRatPF/'    
config.Data.lumiMask = "/afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions17/13TeV/PromptReco/Cert_294927-303825_13TeV_PromptReco_Collisions17_JSON.txt"  
config.General.workArea     = 'crab_projects_noSRatPF'




