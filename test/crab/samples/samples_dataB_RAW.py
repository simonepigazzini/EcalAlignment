########
# Data
########

#        CRAB task name          DAS name                                                                                                              
samples['SingleElectron']   = ['/SingleElectron/Run2015B-v1/RAW',  ['outputFile=treeECALAlignment.root']]
samples['DoubleEG']          = ['/DoubleEG/Run2015B-v1/RAW',  ['outputFile=treeECALAlignment.root']]


########
# Alternative global configuration
########

config.JobType.psetName = '../reco_RAW2DIGI_RECO_AOD.py'
config.Data.splitting = 'LumiBased'    # FileBased
config.Data.unitsPerJob   = 10

config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/DATA16Jul2015'
config.Data.lumiMask = "/afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions15/13TeV/Cert_246908-251252_13TeV_PromptReco_Collisions15_JSON.txt"


config.General.workArea     = 'crab_projects_16July_fromRaw'


