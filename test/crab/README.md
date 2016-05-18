crab
====

See details in:

    https://twiki.cern.ch/twiki/bin/view/CMSPublic/WorkBookCRAB3Tutorial#CRAB_configuration_parameters
    https://twiki.cern.ch/twiki/bin/view/CMSPublic/CRAB3ConfigurationFile

check if I have writing permissions:

    source /cvmfs/cms.cern.ch/crab3/crab.sh
    crab checkwrite --site=T2_CH_CERN
    crab checkwrite --site=T2_CH_CERN  --lfn=/store/user/amassiro/ECAL/
    crab checkwrite --site=T2_CH_CERN  --lfn=/store/group/dpg_ecal/alca_ecalcalib/amassiro/

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
    /eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/DATA29Jul2015AODRAWAllData   ---> max memory 2.5GB --> good!
    
    
    RunC PromptReco
    hadd /tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/DATA29Aug2015AODAllData/SingleElectron/crab_SingleElectron/150827_143017/treeECALAlignment.root   /tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/DATA29Aug2015AODAllData/SingleElectron/crab_SingleElectron/150827_143017/0000/treeECALAlignment_*.root
    
    
    RunB myReReco
    hadd /tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/DATA29Aug2015AODRAWAllData/SingleElectron/crab_SingleElectron/150827_134335/treeECALAlignment.root    /tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/DATA29Aug2015AODRAWAllData/SingleElectron/crab_SingleElectron/150827_134335/0000/treeECALAlignment_*.root
    hadd /tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/DATA29Aug2015AODRAWAllData/SingleElectron/crab_SingleElectron/150826_214823/treeECALAlignment.root    /tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/DATA29Aug2015AODRAWAllData/SingleElectron/crab_SingleElectron/150826_214823/000?/treeECALAlignment_*.root
    
    
    hadd /tmp/amassiro/treeECALAlignment.root \
        /tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/DATA29Aug2015AODAllData/SingleElectron/crab_SingleElectron/150827_143017/treeECALAlignment.root    \
        /tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/DATA29Aug2015AODRAWAllData/SingleElectron/crab_SingleElectron/150826_214823/treeECALAlignment.root  
    
    
    RunC myReReco
    hadd /tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/DATA31Aug2015AODRAWAllDataRunC/SingleElectron/crab_SingleElectron/150903_113327/treeECALAlignment.root /tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/DATA31Aug2015AODRAWAllDataRunC/SingleElectron/crab_SingleElectron/150903_113327/0000/tree*.root
    
    
    
    ls -alrth /tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/DATA04Sep2015AODRAWAllDataRunC
    ls -alrth /tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/DATA04Sep2015AODRAWAllDataRunB
    
    hadd /tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/DATA04Sep2015AODRAWAllDataRunC/SingleElectron/crab_SingleElectron/150904_093122/treeNew04Sep.root      /tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/DATA04Sep2015AODRAWAllDataRunC/SingleElectron/crab_SingleElectron/150904_093122/0000/tree*.root
    hadd /tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/DATA04Sep2015AODRAWAllDataRunB/SingleElectron/crab_SingleElectron/150904_092708/treeNew04SepRunB.root  /tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/DATA04Sep2015AODRAWAllDataRunB/SingleElectron/crab_SingleElectron/150904_092708/000*/tree*.root
    

    hadd /tmp/amassiro/newData04Sep.root \
        /tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/DATA04Sep2015AODRAWAllDataRunC/SingleElectron/crab_SingleElectron/150904_093122/treeNew04Sep.root     \
        /tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/DATA04Sep2015AODRAWAllDataRunB/SingleElectron/crab_SingleElectron/150904_092708/treeNew04SepRunB.root 
    
    
    ls -alrth /tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/DATA05Sep2015AODRAWAllDataRunClastTrk
    ls -alrth /tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/DATA05Sep2015AODRAWAllDataRunBlastTrk
    
    hadd /tmp/amassiro/newData05SepLastTrk.root  \
      /tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/DATA05Sep2015AODRAWAllDataRunClastTrk/SingleElectron/crab_SingleElectron/150905_170323/0000/tre*.root  \
      /tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/DATA05Sep2015AODRAWAllDataRunBlastTrk/SingleElectron/crab_SingleElectron/150905_170304/*/tre*.root
    
    
    
    TFile *_file0 = TFile::Open("/tmp/amassiro/dataOld.root")
    TFile *_file1 = TFile::Open("/tmp/amassiro/newData05SepLastTrk.root")
    TTree* t0 = (TTree*) _file0->Get("ntupleEcalAlignment/myTree")
    TTree* t1 = (TTree*) _file1->Get("ntupleEcalAlignment/myTree")
    TH1F es0 ("es0","before", 100, 0, 100)
    TH1F es1 ("es1","after", 100, 0, 100)
    t0->Draw("eleES >> es0")
    t1->Draw("eleES >> es1")
    es0.DrawNormalized()
    es1.SetLineColor(kRed)
    es1.DrawNormalized("same")


    hadd /tmp/amassiro/runDraw.root   /tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/DATA12Oct2015AODAllDataRunDRAW/SingleElectron/crab_SingleElectron/151012_160046/*/tr*
    
    
    hadd /tmp/amassiro/runDnewnew.root /tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/DATA_23Oct2015_RunD_RAW_myTag/SingleElectron/crab_SingleElectronV4/151023_210315/000*/tr*.root
    cp /tmp/amassiro/runDnewnew.root      /tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/DATA_23Oct2015_RunD_RAW_myTag/SingleElectron/crab_SingleElectronV4/151023_210315/
    cp    /tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/DATA_23Oct2015_RunD_RAW_myTag/SingleElectron/crab_SingleElectronV4/151023_210315/runDnewnew.root  /tmp/amassiro/runDnewnew.root   
    
    hadd /tmp/amassiro/runDnewnewClose.root    /tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/DATA_23Oct2015_RunD_RAW_myTag/SingleElectron/crab_SingleElectron/151023_210245/000*/tr*.root
    cp   /tmp/amassiro/runDnewnewClose.root    /tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/DATA_23Oct2015_RunD_RAW_myTag/SingleElectron/crab_SingleElectron/151023_210245/
    

    hadd /tmp/amassiro/runDnewTrk2015.root      /tmp/amassiro/eos/cms/store/user/amassiro/ECAL/Alignment/DATA_16Nov2015_RunD_RAW_newTrk_myTag/SingleElectron/crab_SingleElectronV4/151117_112354/000*/tr*.root
    hadd /tmp/amassiro/runDnewTrk2015_V0.root   /tmp/amassiro/eos/cms/store/user/amassiro/ECAL/Alignment/DATA_16Nov2015_RunD_RAW_newTrk_myTag/SingleElectron/crab_SingleElectron/151117_112328/000*/tr*.root
    
    
    hadd /tmp/amassiro/data_0T.root  /tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/DATA_07Jan2016_RunD_RAW_Trk_0Tesla/DoubleEG_0T/crab_DoubleEG/160111_094920/0000/tr*.root
    scp amassiro@cmsneu.cern.ch:/media/data/amassiro/ECALalignment/2016/Jan14/data_0T.root /tmp/amassiro/
    
    
    
    
Multicrab
====

    voms-proxy-init --voms cms

    python multicrab.py   samples/samples_spring15.py
    python multicrab.py   samples/samples_dataB.py
    python multicrab.py   samples/samples_dataB_RAW.py
    python multicrab.py   samples/samples_dataC_RAW.py
    python multicrab.py   samples/samples_dataC.py
    python multicrab.py   samples/samples_dataB_ElectronStream_RAW.py
    python multicrab.py   samples/samples_dataD.py
    python multicrab.py   samples/samples_dataD_RAW.py
    python multicrab.py   samples/samples_dataD_Zero.py
    python multicrab.py   samples/samples_dataD_Zero_RAW.py
    python multicrab.py   samples/samples_ZeroTesla.py
    
    python multicrab.py   samples/samples_spring16.py

    python multicrab.py   samples/samples_data2016.py

    
    
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
    
    python multicrab.py crab_projects_28July_fromRaw_allData         resubmit     --maxjobruntime=2600
    python multicrab.py crab_projects_27July_fromRaw_allData         resubmit     --maxjobruntime=2600
    python multicrab.py crab_projects_24July_fromRaw_allData         resubmit     --maxjobruntime=2600 

    python multicrab.py crab_projects_29July_fromRaw_allData         status

    python multicrab.py  crab_projects_31July_fromRaw_myTag_allData  status
    
    python multicrab.py  crab_projects_29Aug_fromRaw_allDataB  status
    python multicrab.py  crab_projects_29Aug_fromRaw_allDataC  status
    python multicrab.py  crab_projects_27Aug_PromptTrkAlign    status
    
    
    python multicrab.py  crab_projects_31Aug_fromRaw_newECAL_allData_RunB    status
    python multicrab.py  crab_projects_31Aug_fromRaw_newECAL_allData_RunC    status
    
    python multicrab.py  crab_projects_04Sep_fromRaw_newECAL_allData_RunB    status
    python multicrab.py  crab_projects_04Sep_fromRaw_newECAL_allData_RunC    status
 
    python multicrab.py  crab_projects_05Sep_fromRaw_newECAL_allData_RunB    status
    python multicrab.py  crab_projects_05Sep_fromRaw_newECAL_allData_RunC    status

    python multicrab.py  crab_projects_05Sep_fromRaw_newECAL_lastTrk_allData_RunB    status
    python multicrab.py  crab_projects_05Sep_fromRaw_newECAL_lastTrk_allData_RunC    status

    python multicrab.py  crab_projects_15Sep_PromptTrkAlign_RunB    status
    python multicrab.py  crab_projects_15Sep_PromptTrkAlign_RunC    status

    python multicrab.py  crab_projects_05Oct_PromptTrkAlign_RunD    status
    
    python multicrab.py  crab_projects_12Oct_PromptTrkAlign_RunD_RAW    status
    python multicrab.py  crab_projects_13Oct_PromptTrkAlign_RunD_RAW    status
    python multicrab.py  crab_projects_13Oct_PromptTrkAlign_RunD_RAW    report

    python multicrab.py  crab_projects_14Oct_PromptTrkAlign_RunD_RAW_myTag    status

    python multicrab.py  crab_projects_23Oct_PromptTrkAlign_RunD_RAW_myTag    status

    python multicrab.py  crab_projects_27Oct_PromptTrkAlign_RunD_RAW_myTag    status
    
    python multicrab.py  crab_projects_15Nov_NewTrkAlign_RunD_RAW_myTag       status
    
    python multicrab.py  crab_projects_16Nov_NewTrkAlign_RunD_RAW_myTag       status

    python multicrab.py  crab_projects_16Nov_NewTrkAlign_RunD_RAW_myTag       dry     status
    
    python multicrab.py  crab_projects_08Dec2015_RunD_0Tesla        status
    
    python multicrab.py  crab_projects_15Dec        status
    
    python multicrab.py  crab_projects_07Jan2016_RunD_RAW_0Tesla        status
    
    python multicrab.py  crab_projects_07May        status
    
    python multicrab.py  crab_projects_May17ZeroAlignmentEEEB        status
    python multicrab.py  crab_projects_May17TeslaFrom2015AlignmentEEEB        status
    
    python multicrab.py  crab_projects_May18ZeroAlignmentEEEB        status
    python multicrab.py  crab_projects_May18TeslaFrom2015AlignmentEEEB        status
    
    
    
    
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
    



