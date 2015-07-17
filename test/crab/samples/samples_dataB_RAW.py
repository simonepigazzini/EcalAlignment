########
# Data
########

#        CRAB task name          DAS name                                                                                                              
#samples['SingleElectron']   = ['/SingleElectron/Run2015B-v1/RAW',  ['outputFile=treeECALAlignment.root']]
#samples['DoubleEG']          = ['/DoubleEG/Run2015B-v1/RAW',  ['outputFile=treeECALAlignment.root']]

samples['SingleElectron']   = ['/SingleElectron/Run2015B-PromptReco-v1/AOD',  ['outputFile=treeECALAlignment.root']]
samples['DoubleEG']          = ['/DoubleEG/Run2015B-PromptReco-v1/AOD',  ['outputFile=treeECALAlignment.root']]
config.Data.useParent = True           # Important!

########
# Alternative global configuration
########

config.JobType.psetName = '../reco_RAW2DIGI_RECO_AOD.py'
config.Data.splitting = 'LumiBased'    # FileBased
config.Data.unitsPerJob   = 10

#config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/DATA16Jul2015'
#config.Data.lumiMask = "/afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions15/13TeV/Cert_246908-251252_13TeV_PromptReco_Collisions15_JSON.txt"


config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/DATA17Jul2015AODRAW'
#/afs/cern.ch/cms/CAF/CMSALCA/ALCA_ECALCALIB/json_ecalonly/251022-251562-Prompt-pfgEcal-noLaserProblem.json copied into json.txt
config.Data.lumiMask = "json.txt"


config.General.workArea     = 'crab_projects_17July_fromRaw'


