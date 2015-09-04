########
# Data
########

#        CRAB task name          DAS name                                                                                                              
#samples['SingleElectron']   = ['/SingleElectron/Run2015B-v1/RAW',  ['outputFile=treeECALAlignment.root']]
#samples['DoubleEG']          = ['/DoubleEG/Run2015B-v1/RAW',  ['outputFile=treeECALAlignment.root']]

samples['SingleElectron']   = ['/SingleElectron/Run2015B-PromptReco-v1/AOD',  ['outputFile=treeECALAlignment.root']]
#samples['DoubleEG']          = ['/DoubleEG/Run2015B-PromptReco-v1/AOD',  ['outputFile=treeECALAlignment.root']]
config.Data.useParent = True           # Important!

########
# Alternative global configuration
########

config.Data.splitting = 'LumiBased'    # FileBased
#config.Data.splitting = 'FileBased'    # FileBased
config.Data.unitsPerJob   = 1   # 10 was too much? Error 50660: too much ram

#config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/DATA16Jul2015'
#config.Data.lumiMask = "/afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions15/13TeV/Cert_246908-251252_13TeV_PromptReco_Collisions15_JSON.txt"


#config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/DATA21Jul2015AODRAW'
#config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/DATA22Jul2015AODRAW'
#/afs/cern.ch/cms/CAF/CMSALCA/ALCA_ECALCALIB/json_ecalonly/251022-251562-Prompt-pfgEcal-noLaserProblem.json copied into json.txt
#config.Data.lumiMask = "json.txt"


#config.General.workArea     = 'crab_projects_17July_fromRaw'
#config.General.workArea     = 'crab_projects_21July_fromRaw'
#config.General.workArea     = 'crab_projects_22July_fromRaw'
#config.JobType.psetName = '../reco_RAW2DIGI_RECO_AOD.py'


#config.General.workArea     = 'crab_projects_23July_fromRaw_myTag'
#config.JobType.psetName = '../reco_my_tag_RAW2DIGI_RECO_AOD.py'
#config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/DATA23Jul2015AODRAWmyTag'


#config.General.workArea     = 'crab_projects_24July_fromRaw_myTag'
#config.JobType.psetName = '../reco_my_tag_RAW2DIGI_RECO_AOD.py'
#config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/DATA24Jul2015AODRAWmyTag'
#config.Data.lumiMask = "/afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions15/13TeV/Cert_246908-251642_13TeV_PromptReco_Collisions15_JSON.txt"

#config.General.workArea     = 'crab_projects_24July_fromRaw_myTag_allData'
#config.JobType.psetName = '../reco_my_tag_RAW2DIGI_RECO_AOD.py'
#config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/DATA24Jul2015AODRAWmyTagAllData'
#config.Data.lumiMask = "/afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions15/13TeV/Cert_246908-251883_13TeV_PromptReco_Collisions15_JSON.txt"

#config.General.workArea     = 'crab_projects_24July_fromRaw_allData'
#config.JobType.psetName = '../reco_RAW2DIGI_RECO_AOD.py'
#config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/DATA24Jul2015AODRAWAllData'
#config.Data.lumiMask = "/afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions15/13TeV/Cert_246908-251883_13TeV_PromptReco_Collisions15_JSON.txt"

#config.Data.splitting = 'FileBased'    # FileBased
#config.General.workArea     = 'crab_projects_27July_fromRaw_allData'
#config.JobType.psetName = '../reco_RAW2DIGI_RECO_AOD.py'
#config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/DATA27Jul2015AODRAWAllData'
#config.Data.lumiMask = "/afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions15/13TeV/Cert_246908-251883_13TeV_PromptReco_Collisions15_JSON.txt"


#config.General.workArea     = 'crab_projects_28July_fromRaw_allData'
#config.JobType.psetName = '../reco_RAW2DIGI_RECO_AOD.py'
#config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/DATA28Jul2015AODRAWAllData'
#config.Data.lumiMask = "/afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions15/13TeV/Cert_246908-251883_13TeV_PromptReco_Collisions15_JSON.txt"
#config.JobType.maxMemoryMB = 4000    # 4 GB


#config.General.workArea     = 'crab_projects_29July_fromRaw_allData'
#config.JobType.psetName = '../reco_RAW2DIGI_RECO_AOD.py'
#config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/DATA29Jul2015AODRAWAllData'
#config.Data.lumiMask = "/afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions15/13TeV/Cert_246908-251883_13TeV_PromptReco_Collisions15_JSON.txt"
#config.JobType.maxMemoryMB = 2500    # 2.5 GB
#config.JobType.maxJobRuntimeMin = 2800


#config.General.workArea     = 'crab_projects_29Aug_fromRaw_allDataB'
#config.JobType.psetName = '../reco_RAW2DIGI_RECO_AOD.py'
#config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/DATA29Aug2015AODRAWAllData'
#config.Data.lumiMask = "/afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions15/13TeV/Cert_246908-254349_13TeV_PromptReco_Collisions15_JSON.txt"
#config.JobType.maxMemoryMB = 2500    # 2.5 GB
#config.JobType.maxJobRuntimeMin = 2800


#config.General.workArea     = 'crab_projects_31Aug_fromRaw_newECAL_allData_RunB'
#config.JobType.psetName = '../reco_my_tag_RAW2DIGI_RECO_AOD.py'
#config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/DATA31Aug2015AODRAWAllDataRunB'
#config.Data.lumiMask = "/afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions15/13TeV/Cert_246908-254879_13TeV_PromptReco_Collisions15_JSON.txt"
#config.JobType.maxMemoryMB = 2500    # 2.5 GB
#config.JobType.maxJobRuntimeMin = 2800
#config.JobType.inputFiles = ['../EBAlign_2015.db','../EEAlign_2015.db', '../TkAlignment.db']




config.General.workArea     = 'crab_projects_04Sep_fromRaw_newECAL_allData_RunB'
config.JobType.psetName = '../reco_my_tag_RAW2DIGI_RECO_AOD.py'
config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/DATA04Sep2015AODRAWAllDataRunB'
config.Data.lumiMask = "/afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions15/13TeV/Cert_246908-254879_13TeV_PromptReco_Collisions15_JSON.txt"
config.JobType.maxMemoryMB = 2500    # 2.5 GB
config.JobType.maxJobRuntimeMin = 2800
config.JobType.inputFiles = ['../EBAlign_2015.db','../EEAlign_2015.db', '../TkAlignment.db']






#config.General.workArea     = 'crab_projects_31July_fromRaw_myTag_allData'
#config.JobType.psetName = '../reco_my_tag_RAW2DIGI_RECO_AOD.py'
#config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/DATA29Jul2015AODRAWAllDataMyTag'
#config.Data.lumiMask = "/afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions15/13TeV/Cert_246908-251883_13TeV_PromptReco_Collisions15_JSON.txt"
#config.JobType.maxMemoryMB = 2500    # 2.5 GB



