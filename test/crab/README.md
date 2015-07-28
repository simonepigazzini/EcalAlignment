crab
====

See details in:

    https://twiki.cern.ch/twiki/bin/view/CMSPublic/WorkBookCRAB3Tutorial#CRAB_configuration_parameters
    https://twiki.cern.ch/twiki/bin/view/CMSPublic/CRAB3ConfigurationFile

check if I have writing permissions:

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
    /eos/cms/store/user/amassiro/ECAL/Alignment/test13Mar2015/
    /eos/cms/store/user/amassiro/ECAL/Alignment/test06Jul2015/
    /eos/cms/store/user/amassiro/ECAL/Alignment/data09Jul2015/
    
    /eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/MC14Jul2015
    /eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/DATA14Jul2015
    /eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/DATA21Jul2015AODRAW/   --> crab crashed
    /eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/DATA22Jul2015AODRAW/
    /eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/DATA23Jul2015AODRAWmyTag/
    /eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/DATA24Jul2015AODRAWmyTag/
    /eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/DATA24Jul2015AODRAWAllData
    /eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/DATA27Jul2015AODRAWAllData
    /eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/DATA28Jul2015AODRAWAllData   ---> max memory 4GB
    
    
Multicrab
====

    python multicrab.py   samples/samples_spring15.py
    python multicrab.py   samples/samples_dataB.py
    python multicrab.py   samples/samples_dataB_RAW.py

    
    crab status folder_name

    python multicrab.py  folder_name

    python multicrab.py crab_projects_6July
    python multicrab.py crab_projects_13July
    python multicrab.py crab_projects_15July
    python multicrab.py crab_projects_16July_fromRaw
    python multicrab.py crab_projects_22July_fromRaw status
    python multicrab.py crab_projects_22July_fromRaw resubmit

    python multicrab.py crab_projects_22July_oldTrkAlign     status
    python multicrab.py crab_projects_23July_fromRaw_myTag   status
    python multicrab.py crab_projects_24July_fromRaw_myTag   status
    python multicrab.py crab_projects_24July_fromRaw_myTag_allData   status
    python multicrab.py crab_projects_24July_fromRaw_allData         status
    python multicrab.py crab_projects_27July_fromRaw_allData         status
    python multicrab.py crab_projects_28July_fromRaw_allData         status
    
    python multicrab.py crab_projects_27July_fromRaw_allData         resubmit     --maxjobruntime=2600
    python multicrab.py crab_projects_24July_fromRaw_allData         resubmit     --maxjobruntime=2600

    
    
    
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
    



