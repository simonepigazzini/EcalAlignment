########
# Data
########

#        CRAB task name          DAS name                                                                                                              
#samples['SingleElectron']   = ['/SingleElectron/Run2015C-PromptReco-v1/AOD',  ['outputFile=treeECALAlignment.root']]
#samples['DoubleEG']         = ['/DoubleEG/Run2015C-PromptReco-v1/AOD',  ['outputFile=treeECALAlignment.root']]

samples['SingleElectron']   = ['/SingleElectron/CMSSW_7_4_11_patch1-Run2015C_HLTnewconditions0_74X_dataRun2_HLTValidation_forPostTS2_v0-v1/RECO',  ['outputFile=treeECALAlignment.root']]

 


########
# Alternative global configuration
########

config.JobType.psetName = '../Dump_DATA_cfg.py'
config.Data.splitting = 'LumiBased'    # FileBased
config.Data.unitsPerJob   = 10
config.Data.runRange = '251562-254790'

#config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/DATA29Aug2015AODAllData'
#config.Data.lumiMask = "/afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions15/13TeV/Cert_246908-254879_13TeV_PromptReco_Collisions15_JSON.txt"
#config.General.workArea     = 'crab_projects_27Aug_PromptTrkAlign'




config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/DATA15Sep2015AODAllDataRunC'
config.Data.lumiMask = "/afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions15/13TeV/Cert_246908-254879_13TeV_PromptReco_Collisions15_JSON.txt"
config.General.workArea     = 'crab_projects_15Sep_PromptTrkAlign_RunC'
config.Data.allowNonValidInputDataset = True