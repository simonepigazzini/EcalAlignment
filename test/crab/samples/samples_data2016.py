########
# Data
########

#        CRAB task name          DAS name                                 
samples['SingleElectron']   = ['/SingleElectron/Run2016B-PromptReco-v2/AOD',  ['outputFile=treeECALAlignment.root']]
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
config.Data.unitsPerJob   = 1

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




#config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/2016/May18TeslaFrom2015AlignmentEEEB'
config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/2016/May18TeslaFrom2015AlignmentEEEB_bis'
#config.Data.lumiMask = "/afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions16/13TeV/DCSOnly/json_DCSONLY.txt"
#config.Data.lumiMask = "/afs/cern.ch/user/c/cmkuo/public/ForShervin/ecal_good_runs_Bon_20160512.json"
config.Data.lumiMask = "ecal_good_runs_Bon_20160512.json"
#config.General.workArea     = 'crab_projects_May18TeslaFrom2015AlignmentEEEB'
config.General.workArea     = 'crab_projects_May18TeslaFrom2015AlignmentEEEB_bis'
config.Data.allowNonValidInputDataset = True
config.JobType.inputFiles = ['../EBAlign_2015.db','../EEAlign_2015.db']
#hadd /tmp/amassiro/ecal_fromLastYear.root /tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/2016/May18TeslaFrom2015AlignmentEEEB_bis/SingleElectron/crab_SingleElectron/160518_213655/0000/treeECALAlignment_*.root




