########
# Data
########

#        CRAB task name          DAS name
#samples['DoubleElectron2017A_v2']   = ['/DoubleEG/Run2017A-ZElectron-PromptReco-v2/RAW-RECO',        ['outputFile=treeECALAlignment.root']]
#samples['DoubleElectron2017A_v3']   = ['/DoubleEG/Run2017A-ZElectron-PromptReco-v3/RAW-RECO',        ['outputFile=treeECALAlignment.root']]
#samples['DoubleElectrin2017B_v1']   = ['/DoubleEG/Run2017B-ZElectron-PromptReco-v1/RAW-RECO',        ['outputFile=treeECALAlignment.root']]

# samples['ZElectron-PromptReco-v1']   = ['/EGamma/Run2018A-ZElectron-PromptReco-v1/RAW-RECO',        ['outputFile=treeECALAlignment.root']]
samples['ZElectron-2017F-RAWReco-v1']   = ['/DoubleEG/Run2017F-ZElectron-09May2018-v1/RAW-RECO',        ['outputFile=treeECALAlignment.root']]
samples['ZElectron-2017E-RAWReco-v1']   = ['/DoubleEG/Run2017E-ZElectron-17Nov2017-v1/RAW-RECO',        ['outputFile=treeECALAlignment.root']]
samples['ZElectron-2017D-RAWReco-v1']   = ['/DoubleEG/Run2017D-ZElectron-17Nov2017-v1/RAW-RECO',        ['outputFile=treeECALAlignment.root']]
samples['ZElectron-2017C-RAWReco-v1']   = ['/DoubleEG/Run2017C-ZElectron-17Nov2017-v1/RAW-RECO',        ['outputFile=treeECALAlignment.root']]
samples['ZElectron-2017B-RAWReco-v1']   = ['/DoubleEG/Run2017B-ZElectron-17Nov2017-v1/RAW-RECO',        ['outputFile=treeECALAlignment.root']]

#config.Data.useParent = True           # Important!




########
# Alternative global configuration
########

# config.JobType.psetName = '../reco_RAW2DIGI_RECO2018.py'
config.JobType.psetName = '../reco_RAW2DIGI_RECO2019_TrackerConditions.py'
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


#config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/twamorka/24Jun_postalignment_v3'     #TO BE FIXED'
# config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/twamorka/Alignment_2018/RawReco_4May2018'
config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/twamorka/UltraLegacy_WithTrackerConditions'
#config.Data.lumiMask = "/afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions18/13TeV/DCSOnly/json_DCSONLY.txt"   #TO BE FIXED
# config.General.workArea     = 'crab_projects_May4_2018_rawreco_v1'
config.General.workArea     = 'crab_projects_ECAL_LegacyConditions_WithTracker'
# config.JobType.inputFiles = ['../EBAlign_2018.db','../EEAlign_2018.db']
#config.Data.runRange = '277148-279119'
#
#

## hadd /tmp/amassiro/ECALalignDATA_runD.root /tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/2016/Aug11AlignmentEEEB_dump/DoubleEG/crab_DoubleElectron2016D/*/*/*.root
#   ls /tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/2016/Aug29AlignmentEEEB_dump_AfterICHEP/DoubleEG/
