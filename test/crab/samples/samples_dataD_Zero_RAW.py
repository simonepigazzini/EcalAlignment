########
# Data
########

#        CRAB task name          DAS name                                 
samples['DoubleEG']   = ['/DoubleEG_0T/Run2015D-PromptReco-v4/AOD',  ['outputFile=treeECALAlignment.root']]
config.Data.useParent = True           # Important!


########
# Alternative global configuration
########

config.Data.splitting = 'LumiBased'    # FileBased
config.Data.unitsPerJob   = 10
# config.Data.runRange = '251562-254790'


config.JobType.psetName = '../reco_my_tag_RAW2DIGI_RECO_AOD.py'
config.JobType.maxMemoryMB = 2500    # 2.5 GB

#config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/DATA_08Dec2015_RunD_RAW_newTrk_myTag_0Tesla'
#config.Data.lumiMask = "/afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions15/13TeV/Cert_246908-260627_13TeV_PromptReco_Collisions15_ZeroTesla_25ns_JSON.txt"
#config.General.workArea     = 'crab_projects_08Dec2015_NewTrkAlign_RunD_RAW_myTag_0Tesla'
#config.Data.allowNonValidInputDataset = True
#config.JobType.inputFiles = ['../EBAlign_2015.db','../EEAlign_2015.db']


#config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/DATA_07Jan2016_RunD_RAW_Trk_0Tesla'
#config.Data.lumiMask = "/afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions15/13TeV/Cert_246908-260627_13TeV_PromptReco_Collisions15_ZeroTesla_25ns_JSON.txt"
#config.General.workArea     = 'crab_projects_07Jan2016_RunD_RAW_0Tesla'
#config.Data.allowNonValidInputDataset = True
##config.JobType.inputFiles = ['../EBAlign_2015.db','../EEAlign_2015.db']
## /media/data/amassiro/ECALalignment/2016/Jan14




#config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/DATA_18Jan2016_RunD_RAW_Trk_myECAL_EE_0Tesla'
#config.Data.lumiMask = "/afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions15/13TeV/Cert_246908-260627_13TeV_PromptReco_Collisions15_ZeroTesla_25ns_JSON.txt"
#config.General.workArea     = 'crab_projects_18Jan2016_RunD_RAW_0Tesla'
#config.Data.allowNonValidInputDataset = True
#config.JobType.inputFiles = ['../EEAlign_2015.db']
##hadd /tmp/amassiro/data_0T_EE.root /tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/DATA_18Jan2016_RunD_RAW_Trk_myECAL_EE_0Tesla/DoubleEG_0T/crab_DoubleEG/160118_174053/0000/tr*.root
## /media/data/amassiro/ECALalignment/2016/Jan14/data_0T_EE.root





#config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/DATA_19Jan2016_RunD_RAW_Trk_myECAL_EE_0Tesla'
#config.Data.lumiMask = "/afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions15/13TeV/Cert_246908-260627_13TeV_PromptReco_Collisions15_ZeroTesla_25ns_JSON.txt"
#config.General.workArea     = 'crab_projects_19Jan2016_RunD_RAW_0Tesla'
#config.Data.allowNonValidInputDataset = True
#config.JobType.inputFiles = ['../EEAlign_2015.db']





config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/DATA_19Jan2016_RunD_RAW_Trk_myECAL_EE_and_EB_0Tesla'
config.Data.lumiMask = "/afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions15/13TeV/Cert_246908-260627_13TeV_PromptReco_Collisions15_ZeroTesla_25ns_JSON.txt"
config.General.workArea     = 'crab_projects_19Jan2016_RunD_RAW_0Tesla_EE_and_EB'
config.Data.allowNonValidInputDataset = True
config.JobType.inputFiles = ['../EEAlign_2015.db', '../EBAlign_2015.db']











