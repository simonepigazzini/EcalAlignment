import os
from WMCore.Configuration import Configuration
config = Configuration()

pyCfgParams = ['inputFiles=FAKEINPUT', 'outputFile=treeECALAlignment.root']

config.section_('General')
config.General.transferOutputs = True
config.General.requestName = 'MCtest_13Feb2015'

config.section_('JobType')
config.JobType.psetName = '../Dump_MC_cfg.py'
config.JobType.pluginName = 'Analysis'
config.JobType.outputFiles = ['treeECALAlignment.root']

# to fix cmssw releases
config.JobType.allowNonProductionCMSSW = True

config.section_('Data')    
config.Data.unitsPerJob = 10   # since files based, 10 files per job
config.Data.inputDBS = 'https://cmsweb.cern.ch/dbs/prod/global/DBSReader/'
config.Data.splitting = 'FileBased'    #'LumiBased'
config.Data.outLFN = '/store/user/amassiro/ECAL/Alignment/test13Mar2015'

config.section_('Site')
config.Site.storageSite = 'T2_CH_CERN'



if __name__ == '__main__':

    from CRABAPI.RawCommand import crabCommand

    # Make sure you set this parameter (here or above in the config it does not matter)
    config.General.workArea = 'crab_projects_13Mar'

    def submit(config):
        res = crabCommand('submit', config = config)

    #########    From now on that's what users should modify: this is the a-la-CRAB2 configuration part.
   

    # samples to be analysed
                   
    config.General.requestName = 'DYll'
    config.Data.inputDataset = '/DYToEE_M-50_Tune4C_13TeV-pythia8/Phys14DR-PU40bx25_tsg_castor_PHYS14_25_V1-v2/AODSIM'
    config.JobType.pyCfgParams = list(pyCfgParams)
    #config.JobType.pyCfgParams.extend(['label=DYll'])
    submit(config)
    #print " pyCfgParams = ", pyCfgParams
    #print " config.JobType.pyCfgParams = ", config.JobType.pyCfgParams
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    