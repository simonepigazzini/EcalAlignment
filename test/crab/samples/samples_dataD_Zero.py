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


config.JobType.psetName = '../Dump_DATA_cfg.py'
config.JobType.maxMemoryMB = 2500    # 2.5 GB

config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/DATA_08Dec2015_RunD_0Tesla'
config.Data.lumiMask = "/afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions15/13TeV/Cert_246908-260627_13TeV_PromptReco_Collisions15_ZeroTesla_25ns_JSON.txt"
config.General.workArea     = 'crab_projects_08Dec2015_RunD_0Tesla'
config.Data.allowNonValidInputDataset = True

# hadd /tmp/amassiro/ECAL0Tesla.root /tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/DATA_08Dec2015_RunD_0Tesla/DoubleEG_0T/crab_DoubleEG/151214_125637/0000/tr*.root










