crab
====

See details in:

    https://twiki.cern.ch/twiki/bin/view/CMSPublic/WorkBookCRAB3Tutorial#CRAB_configuration_parameters
    https://twiki.cern.ch/twiki/bin/view/CMSPublic/CRAB3ConfigurationFile

check if I have writing permissions:

    source /afs/cern.ch/cms/LCG/LCG-2/UI/cms_ui_env.sh
    source /cvmfs/cms.cern.ch/crab3/crab.sh
    crab checkwrite --site=T2_CH_CERN
    crab checkwrite --site=T2_CH_CERN  --lfn=/store/user/amassiro/ECAL/

run

    crab submit -c crab_Dump_MC.py
    crab status    

run on data

    crab submit -c crab_Dump_DATA.py
    crab status    

details:

    it will save in something like:
    /eos/cms/store/user/amassiro/ECAL/Alignment/test16Jan2015/DYToEE_M-50_Tune4C_13TeV-pythia8/crab_MC/150116_161722/0000/treeECALAlignment_1.root
    /eos/cms/store/user/amassiro/ECAL/Alignment/test21Jan2015/DoubleElectron/crab_DATA/150121_170634/0000
    /eos/cms/store/user/amassiro/ECAL/Alignment/test27Jan2015/DoubleElectron/crab_DATAdoubleEle/150127_100439/
    


Samples
====

    /DYToEE_Tune4C_13TeV-pythia8/Spring14dr-PU_S14_POSTLS170_V6-v1/AODSIM
    /DYJetsToLL_M-50_13TeV-madgraph-pythia8/Spring14dr-PU_S14_POSTLS170_V6-v1/AODSIM
    /DYToEE_M_50_628_EGamma_13TeV/Summer12-PU_S14_DESIGN70_V7-v1/AODSIM
    /DYToEE_M-50_Tune4C_13TeV-pythia8/Phys14DR-PU40bx25_tsg_castor_PHYS14_25_V1-v2/AODSIM
    /DoubleElectron/Run2012D-PromptReco-v1/AOD
    /DoubleElectron/Run2012D-22Jan2013-v1/AOD
    /DoubleElectron/Run2012C-24Aug2012-v1/AOD
    /SingleElectron/Run2012A-PromptReco-v1/AOD
    



