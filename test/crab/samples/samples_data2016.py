########
# Data
########

#        CRAB task name          DAS name                                 
#samples['SingleElectron']   = ['/SingleElectron/Run2016B-PromptReco-v2/AOD',  ['outputFile=treeECALAlignment.root']]
samples['DoubleElectron']   = ['/DoubleEG/Run2016B-PromptReco-v2/AOD',        ['outputFile=treeECALAlignment.root']]
config.Data.useParent = True           # Important!

 


########
# Alternative global configuration
########

#config.JobType.psetName = '../Dump_DATA_cfg.py'
#config.Data.splitting = 'LumiBased'    # FileBased
#config.Data.unitsPerJob   = 10
# config.Data.runRange = '251562-254790'


config.Data.splitting = 'LumiBased'    # FileBased
#config.Data.splitting = 'FileBased'    # FileBased
#config.Data.unitsPerJob   = 1
config.Data.unitsPerJob   = 3   # 1 is creating 12k jobs ... max from crab is 10k


config.JobType.psetName = '../reco_RAW2DIGI_RECO_AOD.py'
config.JobType.maxMemoryMB = 2500    # 2.5 GB

#config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/2016/May17ZeroAlignmentEEEB'
##config.Data.lumiMask = "/afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions16/13TeV/DCSOnly/json_DCSONLY.txt"
##config.Data.lumiMask = "/afs/cern.ch/user/c/cmkuo/public/ForShervin/ecal_good_runs_Bon_20160512.json"
#config.Data.lumiMask = "ecal_good_runs_Bon_20160512.json"
#config.General.workArea     = 'crab_projects_May17ZeroAlignmentEEEB'
#config.Data.allowNonValidInputDataset = True
#config.JobType.inputFiles = ['../EBAlign_2015.db','../EEAlign_2015.db']




#config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/2016/May17TeslaFrom2015AlignmentEEEB'
##config.Data.lumiMask = "/afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions16/13TeV/DCSOnly/json_DCSONLY.txt"
##config.Data.lumiMask = "/afs/cern.ch/user/c/cmkuo/public/ForShervin/ecal_good_runs_Bon_20160512.json"
#config.Data.lumiMask = "ecal_good_runs_Bon_20160512.json"
#config.General.workArea     = 'crab_projects_May17TeslaFrom2015AlignmentEEEB'
#config.Data.allowNonValidInputDataset = True
#config.JobType.inputFiles = ['../EBAlign_2015.db','../EEAlign_2015.db']






##config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/2016/May18ZeroAlignmentEEEB'
#config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/2016/May18ZeroAlignmentEEEB_bis'
##config.Data.lumiMask = "/afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions16/13TeV/DCSOnly/json_DCSONLY.txt"
##config.Data.lumiMask = "/afs/cern.ch/user/c/cmkuo/public/ForShervin/ecal_good_runs_Bon_20160512.json"
#config.Data.lumiMask = "ecal_good_runs_Bon_20160512.json"
##config.General.workArea     = 'crab_projects_May18ZeroAlignmentEEEB'
#config.General.workArea     = 'crab_projects_May18ZeroAlignmentEEEB_bis'
#config.Data.allowNonValidInputDataset = True
#config.JobType.inputFiles = ['../EBAlign_2015.db','../EEAlign_2015.db']




##config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/2016/May18TeslaFrom2015AlignmentEEEB'
#config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/2016/May18TeslaFrom2015AlignmentEEEB_bis'
##config.Data.lumiMask = "/afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions16/13TeV/DCSOnly/json_DCSONLY.txt"
##config.Data.lumiMask = "/afs/cern.ch/user/c/cmkuo/public/ForShervin/ecal_good_runs_Bon_20160512.json"
#config.Data.lumiMask = "ecal_good_runs_Bon_20160512.json"
##config.General.workArea     = 'crab_projects_May18TeslaFrom2015AlignmentEEEB'
#config.General.workArea     = 'crab_projects_May18TeslaFrom2015AlignmentEEEB_bis'
#config.Data.allowNonValidInputDataset = True
#config.JobType.inputFiles = ['../EBAlign_2015.db','../EEAlign_2015.db']
##hadd /tmp/amassiro/ecal_fromLastYear.root /tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/2016/May18TeslaFrom2015AlignmentEEEB_bis/SingleElectron/crab_SingleElectron/160518_213655/0000/treeECALAlignment_*.root



#config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/2016/May23AlignmentEEEB_newTrk2016'
#config.Data.lumiMask = "/afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions16/13TeV/Cert_271036-273450_13TeV_PromptReco_Collisions16_JSON_NoL1T.txt"
#config.General.workArea     = 'crab_projects_May23AlignmentEEEB_newTrk2016'
#config.Data.allowNonValidInputDataset = True
#config.JobType.inputFiles = ['../EBAlign_2015.db','../EEAlign_2015.db']   # this is the zero alignment for EE/EB
## hadd /tmp/amassiro/data_noECAL_newTrk.root  /tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/2016/May23AlignmentEEEB_newTrk2016/DoubleEG/crab_DoubleElectron/160523_123338/0000/tree*.root



## latest and greates trakcer and pixel tag
#config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/2016/May24AlignmentEEEB_newTrk2016'
#config.Data.lumiMask = "/afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions16/13TeV/Cert_271036-273450_13TeV_PromptReco_Collisions16_JSON_NoL1T.txt"
#config.General.workArea     = 'crab_projects_May24AlignmentEEEB_newTrk2016'
#config.Data.allowNonValidInputDataset = True
#config.JobType.inputFiles = ['../EBAlign_2015.db','../EEAlign_2015.db']   # this is the zero alignment for EE/EB
## hadd /tmp/amassiro/data_noECAL_newTrk_24Nov.root  /tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/2016/May24AlignmentEEEB_newTrk2016/DoubleEG/crab_DoubleElectron/160524_135137/*/tree*.root


## latest and greates trakcer and pixel tag and new ECAL
#config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/2016/May25AlignmentEEEB_newTrk2016_newECAL'
#config.Data.lumiMask = "/afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions16/13TeV/Cert_271036-273450_13TeV_PromptReco_Collisions16_JSON_NoL1T.txt"
#config.General.workArea     = 'crab_projects_May25AlignmentEEEB_newTrk2016_newECAL'
#config.Data.allowNonValidInputDataset = True
#config.JobType.inputFiles = ['../EBAlign_2015.db','../EEAlign_2015.db']   # this is the new ECAL alignment
## hadd /tmp/amassiro/data_newECAL_newTrk_25Nov.root    /tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/2016/May25AlignmentEEEB_newTrk2016_newECAL/DoubleEG/crab_DoubleElectron/160525_111346/*/tree*.root


## latest and greates trakcer and pixel tag and new ECAL  -> after corrected ECAL 
#config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/2016/May27AlignmentEEEB_newTrk2016_newECAL'
#config.Data.lumiMask = "/afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions16/13TeV/Cert_271036-273730_13TeV_PromptReco_Collisions16_JSON.txt"
#config.General.workArea     = 'crab_projects_May27AlignmentEEEB_newTrk2016_newECAL'
#config.Data.allowNonValidInputDataset = True
#config.JobType.inputFiles = ['../EBAlign_2015.db','../EEAlign_2015.db']   # this is the new ECAL alignment
## hadd /tmp/amassiro/data_newECAL_newTrk_EEfix_28Nov.root    /tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/2016/May27AlignmentEEEB_newTrk2016_newECAL/DoubleEG/crab_DoubleElectron/160527_143339/*/tree*.root


# latest and greates trakcer and pixel tag and new ECAL  -> after corrected ECAL and redone because the previous one was not working ... maybe not updated EEdb?
#    I think wrong Dx and Dy -> this is transformed in a bad Deta in the endcap
#config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/2016/May28AlignmentEEEB_newTrk2016_newECAL'
#config.Data.lumiMask = "/afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions16/13TeV/Cert_271036-273450_13TeV_PromptReco_Collisions16_JSON_NoL1T.txt"
#config.General.workArea     = 'crab_projects_May28AlignmentEEEB_newTrk2016_newECAL'
#config.Data.allowNonValidInputDataset = True
#config.JobType.inputFiles = ['../EBAlign_2015.db','../EEAlign_2015.db']   # this is the new ECAL alignment
#  Used this one: myEEAlignment_2016_NewTrkAlign_newPix_28May2016.txt



##  -----> this is GOOD!
## latest and greates trakcer and pixel tag and new ECAL  -> after corrected ECAL and redone because the previous one was not working
##  and now after the sign fix: why did it work before (last year) ?????
#config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/2016/May28AlignmentEEEB_newTrk2016_newECAL_signFix'
#config.Data.lumiMask = "/afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions16/13TeV/Cert_271036-273450_13TeV_PromptReco_Collisions16_JSON_NoL1T.txt"
#config.General.workArea     = 'crab_projects_May28AlignmentEEEB_newTrk2016_newECAL_signFix'
#config.Data.allowNonValidInputDataset = True
#config.JobType.inputFiles = ['../EBAlign_2015.db','../EEAlign_2015.db']   # this is the new ECAL alignment
## 
### hadd /tmp/amassiro/data_newECAL_newTrk_EEfix_SignOk_29May.root    /tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/2016/May28AlignmentEEEB_newTrk2016_newECAL_signFix/DoubleEG/crab_DoubleElectron/160528_222959/*/tree*.root




## latest and greates trakcer and pixel tag and old ECAL  -> Using 2015 ECAL, what was supposed to be in the prompt since day 0
#config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/2016/May28AlignmentEEEB_newTrk2016_oldECALfrom2015'
#config.Data.lumiMask = "/afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions16/13TeV/Cert_271036-273450_13TeV_PromptReco_Collisions16_JSON_NoL1T.txt"
#config.General.workArea     = 'crab_projects_May28AlignmentEEEB_newTrk2016_oldECALfrom2015'
#config.Data.allowNonValidInputDataset = True
#config.JobType.inputFiles = ['../EBAlign_2015.db','../EEAlign_2015.db']   # this is the new ECAL alignment
## 
#### hadd /tmp/amassiro/data_oldECAL_newTrk_30May.root    /tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/2016/May28AlignmentEEEB_newTrk2016_oldECALfrom2015/DoubleEG/crab_DoubleElectron/160529_213930/*/tree*.root






#  -----> this is GOOD! .... maybe also for EB  ---> YES, this is the definitive
# latest and greates trakcer and pixel tag and new ECAL  -> after corrected ECAL and redone because the previous one was not working
#  and now after the sign fix: why did it work before (last year) ?????
#config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/2016/May31AlignmentEEEB_newTrk2016_newECAL_signFix_andNewEB'
#config.Data.lumiMask = "/afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions16/13TeV/Cert_271036-273450_13TeV_PromptReco_Collisions16_JSON_NoL1T.txt"
#config.General.workArea     = 'crab_projects_May31AlignmentEEEB_newTrk2016_newECAL_signFix_andNewEB'
#config.Data.allowNonValidInputDataset = True
#config.JobType.inputFiles = ['../EBAlign_2015.db','../EEAlign_2015.db']   # this is the new ECAL alignment
## 
#### hadd /tmp/amassiro/data_newECAL_newTrk_EEfix_SignOk_30May_andNewEB.root    /tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/2016/May31AlignmentEEEB_newTrk2016_newECAL_signFix_andNewEB/DoubleEG/crab_DoubleElectron/160531_180853/*/tree*.root




#  -----> this is GOOD! .... same as before but new JSON
# latest and greates trakcer and pixel tag and new ECAL  -> after corrected ECAL and redone because the previous one was not working
#  and now after the sign fix: why did it work before (last year) ?????
config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/2016/May31AlignmentEEEB_newTrk2016_newECAL_signFix_andNewEB_newJSON'
config.Data.lumiMask = "/afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions16/13TeV/Cert_271036-273730_13TeV_PromptReco_Collisions16_JSON.txt"
config.General.workArea     = 'crab_projects_May31AlignmentEEEB_newTrk2016_newECAL_signFix_andNewEB_newJSON'
config.Data.allowNonValidInputDataset = True
config.JobType.inputFiles = ['../EBAlign_2015.db','../EEAlign_2015.db']   # this is the new ECAL alignment
# 
### 


















