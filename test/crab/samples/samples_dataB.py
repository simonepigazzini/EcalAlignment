########
# Data
########

#        CRAB task name          DAS name                                                                                                              
#samples['SingleElectron']   = ['/SingleElectron/Run2015B-PromptReco-v1/AOD',  ['outputFile=treeECALAlignment.root']]
#samples['DoubleEG']          = ['/DoubleEG/Run2015B-PromptReco-v1/AOD',  ['outputFile=treeECALAlignment.root']]


samples['SingleElectron']   = ['/SingleElectron/CMSSW_7_4_11_patch1-Run2015B_HLTnewconditions0_74X_dataRun2_HLTValidation_forPostTS2_fromRun2015B_v0-v1/RECO',  ['outputFile=treeECALAlignment.root']]



########
# Alternative global configuration
########

config.JobType.psetName = '../Dump_DATA_cfg.py'
config.Data.splitting = 'LumiBased'    # FileBased
config.Data.unitsPerJob   = 10
#config.Data.outLFNDirBase = '/store/user/amassiro/ECAL/Alignment/data09Jul2015'
#config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/DATA14Jul2015'
#config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/DATA22Jul2015_oldTrkAlign'
#config.Data.lumiMask = "json.txt"
#config.Data.lumiMask = "/afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions15/13TeV/DCSOnly/json_DCSONLY_Run2015B.txt"
#config.Data.lumiMask = "/afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions15/13TeV/Cert_246908-251252_13TeV_PromptReco_Collisions15_JSON.txt"
#config.Data.lumiMask = "json.txt"


#config.General.workArea     = 'crab_projects_15July'
#config.General.workArea     = 'crab_projects_22July_oldTrkAlign'




config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/DATA15Sep2015AODAllDataRunB'
config.Data.lumiMask = "/afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions15/13TeV/Cert_246908-254879_13TeV_PromptReco_Collisions15_JSON.txt"
config.General.workArea     = 'crab_projects_15Sep_PromptTrkAlign_RunB'
config.Data.allowNonValidInputDataset = True
