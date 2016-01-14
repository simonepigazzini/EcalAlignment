########
# 25 ns
########
#        CRAB task name          DAS name                                                                                                              
samples['25ns_DYJetsToEE']   = ['/DYToEE_NNPDF30_13TeV-powheg-pythia8/emanuele-DYToEE_NNPDF30_13TeV-powheg-pythia8-RunIIWinter15GS-magnetOffBS0T_74X_mcRun2_0T_v0-AODSIM-v1-03888ead68ccddea312078ca118418d3/USER',  ['outputFile=treeECALAlignment.root']]


########
# Alternative global configuration
########

config.JobType.maxMemoryMB = 2500    # 2.5 GB
config.JobType.psetName = '../Dump_MC_cfg.py'
config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/MC14Jan2016'

config.General.workArea     = 'crab_projects_14Jan'

# private sample that was published on phys03
config.Data.inputDBS='phys03'