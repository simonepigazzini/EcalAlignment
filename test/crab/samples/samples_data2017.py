########
# Data
########

#        CRAB task name          DAS name                                 
samples['DoubleElectron2017A']   = ['/DoubleEG/Run2017A-ZElectron-PromptReco-v2/RAW-RECO',        ['outputFile=treeECALAlignment.root']]

#config.Data.useParent = True           # Important!

 


########
# Alternative global configuration
########

config.JobType.psetName = '../reco_RAW2DIGI_RECO2017.py'
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


config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/      TO BE FIXED'
config.Data.lumiMask = "/afs/cern.ch/cms/   TO BE FIXED"
config.General.workArea     = 'crab_projects_Jun22AlignmentEEEB_closure'
config.JobType.inputFiles = ['../EBAlign_2015.db','../EEAlign_2015.db']
#config.Data.runRange = '277148-279119'
#
#

## hadd /tmp/amassiro/ECALalignDATA_runD.root /tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/2016/Aug11AlignmentEEEB_dump/DoubleEG/crab_DoubleElectron2016D/*/*/*.root
#   ls /tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/2016/Aug29AlignmentEEEB_dump_AfterICHEP/DoubleEG/
#    crab_DoubleElectron2016E/160829_102157/  crab_DoubleElectron2016F/160829_102232/  crab_DoubleElectron2016G/160829_102224/







