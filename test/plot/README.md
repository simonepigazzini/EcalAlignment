Plot tools
====

Get reference using MC trees:

    void drawModules(TString nameInFileRoot, TString nameOutputDir, TString nameDATA, TString commonCut = "1")
    r99t drawModulesMC.cxx\(\"root://eoscms.cern.ch//store/user/amassiro/ECAL/Alignment/test13Mar2015/DYToEE_M-50_Tune4C_13TeV-pythia8/crab_DYll/150315_215425/0000/treeECALAlignment_1.root\",\"25Aug2014\",\"2015MC\"\)
    r99t drawModulesMC.cxx\(\"root://eoscms.cern.ch//store/user/amassiro/ECAL/Alignment/test13Mar2015/DYToEE_M-50_Tune4C_13TeV-pythia8/crab_DYll/150315_215425/0000/treeECALAlignment_1.root\",\"25Aug2014\",\"2015MC\",\"electrons_classification\=\=0\&\&ETSC\>20\"\)

    r99t drawModulesMC.cxx\(\"root://eoscms.cern.ch//store/user/amassiro/ECAL/Alignment/test13Mar2015/DYToEE_M-50_Tune4C_13TeV-pythia8/crab_DYll/150315_215425/0000/treeECALAlignment_*.root\",\"25Aug2014\",\"2015MC\",\"electrons_classification\=\=0\&\&ETSC\>20\"\)
    
    cd /tmp/amassiro/
    eosmount eos eos
    cd -
    r99t drawModulesMC.cxx\(\"/tmp/amassiro/eos/cms/store/user/amassiro/ECAL/Alignment/test06Jul2015/WJetsToLNu_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/crab_50ns_WJetsToLNu/150708_201650/0000/treeECALAlignment_*.root\",\"2015MC\",\"mc_weight*electrons_classification\=\=0\&\&ETSC\>20\"\)
    r99t drawModulesMC.cxx\(\"/tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/MC14Jul2015/WJetsToLNu_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/crab_50ns_WJetsToLNu/150714_075454/0000/treeECALAlignment_*.root\",\"2015MCall\",\"mc_weight*electrons_classification\=\=0\&\&ETSC\>20\"\)
    r99t drawModulesMC.cxx\(\"/tmp/amassiro/wjets.root\",\"2015MCall\",\"mc_weight*electrons_classification\=\=0\&\&ETSC\>20\"\)
    
    
    /tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/DATA22Jul2015_oldTrkAlign/SingleElectron/crab_SingleElectron/150722_131032/0000/
    r99t drawModules.cxx\(\"/tmp/amassiro/data.root\",\"2015DataOldTrkAll\",\"electrons_classification\=\=0\&\&ETSC\>20\"\)
    r99t drawModules.cxx\(\"/tmp/amassiro/data.root\",\"2015DataOldTrkAll\",\"electrons_classification\=\=0\&\&ETSC\>30\"\)
    r99t drawModules.cxx\(\"/tmp/amassiro/data.root\",\"2015DataOldTrkAll\",\"ETSC\>30\"\)
      
    r99t drawModules.cxx\(\"/tmp/amassiro/dataNewTrk.root\",\"2015DataNewTrkAll\",\"ETSC\>30\"\)
      
    
    /tmp/amassiro//eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/DATA23Jul2015AODRAWmyTag/SingleElectron/crab_SingleElectron/150723_185304/000?/tr*.root
    r99t drawModules.cxx\(\"/tmp/amassiro/data_my_tag.root\",\"2015DataNewTrkNewECALAll\",\"ETSC\>30\"\)
    
    /tmp/amassiro//eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/DATA24Jul2015AODRAWmyTag/SingleElectron/crab_SingleElectron/150724_090616/000?/tr*.root
    r99t drawModules.cxx\(\"/tmp/amassiro/newEcalTag.root\",\"2015DataNewTrkNewECALAll\",\"ETSC\>30\"\)
    
    /tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/DATA29Jul2015AODRAWAllData/SingleElectron/crab_SingleElectron/150728_162006/treeECALnewTrkOldEcal.root
    r99t drawModules.cxx\(\"/tmp/amassiro/treeECALnewTrkOldEcal.root\",\"2015DataNewTrkOldECALAll\",\"ETSC\>30\"\)
    
    
    /tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/DATA31Aug2015AODRAWAllDataRunB/SingleElectron/crab_SingleElectron/150831_145837/treeECALAlignment.root
    r99t drawModules.cxx\(\"/tmp/amassiro/treeECALAlignment.root\",\"2015DataNewTrkNewECALSep2015\",\"ETSC\>30\"\)
    r99t drawModules.cxx\(\"/tmp/amassiro/treeECALAlignment.root\",\"2015DataNewTrkNewECALSep2015\",\"ETSC\>20\"\)
    
    
    RunC myReReco
    hadd /tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/DATA31Aug2015AODRAWAllDataRunC/SingleElectron/crab_SingleElectron/150903_113327/treeECALAlignment.root /tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/DATA31Aug2015AODRAWAllDataRunC/SingleElectron/crab_SingleElectron/150903_113327/0000/tree*.root

    cp /tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/DATA31Aug2015AODRAWAllDataRunC/SingleElectron/crab_SingleElectron/150903_113327/treeECALAlignment.root   /tmp/amassiro/tree_RunC.root
    r99t drawModules.cxx\(\"/tmp/amassiro/tree_RunC.root\",\"2015CDataNewTrkNewECALSep2015\",\"ETSC\>30\"\)
    cp /tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/DATA31Aug2015AODRAWAllDataRunB/SingleElectron/crab_SingleElectron/150831_145837/treeECALAlignment.root   /tmp/amassiro/tree_RunB.root   
    hadd /tmp/amassiro/tree_Run.root /tmp/amassiro/tree_RunC.root /tmp/amassiro/tree_RunB.root
    r99t drawModules.cxx\(\"/tmp/amassiro/tree_Run.root\",\"2015DataNewTrkNewECALSep2015\",\"ETSC\>30\"\)
    
    
    hadd /tmp/amassiro/RunCalone.root    /tmp/amassiro/eos/cms//store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/DATA07Sep2015AODRAWAllDataRunClastTrk/SingleElectron/crab_SingleElectron/150909_123538/0000/tr*.root
    
    hadd /tmp/amassiro/tree_Run.root    /tmp/amassiro/RunCalone.root  /tmp/amassiro/tree_RunB.root
    
    r99t drawModules.cxx\(\"/tmp/amassiro/tree_Run.root\",\"2015DataNewTrkNewECALSep2015_MioTest\",\"ETSC\>30\"\)
    r99t drawModules.cxx\(\"/tmp/amassiro/RunCalone.root\",\"2015DataNewTrkNewECALSep2015_MioTest\",\"ETSC\>30\"\)
    
 
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
    gPad->BuildLegend()
 
 
 
    hadd /tmp/amassiro/runC.root  /tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/DATA15Sep2015AODAllDataRunC/SingleElectron/crab_SingleElectron/150921_151702/0000/tr*.root
    hadd /tmp/amassiro/runB.root  /tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/DATA15Sep2015AODAllDataRunB/SingleElectron/crab_SingleElectron/150921_113742/0000/tr*.root
    
 
    hadd /tmp/amassiro/runD.root /tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/DATA05Oct2015AODAllDataRunD/SingleElectron/crab_SingleElectron/151005_072553/0000/treeECALAlignment_*.root

    hadd /tmp/amassiro/runD.root /tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/DATA12Oct2015AODAllDataRunDRAW/SingleElectron/crab_SingleElectron/151012_160046/000*/tr*.root 
 
    hadd /tmp/amassiro/runDnew.root  /tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/DATA_14Oct2015_RunD_RAW_myTag/SingleElectron/crab_SingleElectron/151014_135228/000*/tr*.root
    /tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/DATA_14Oct2015_RunD_RAW_myTag/SingleElectron/crab_SingleElectron/151014_135228/runDnew.root
 

    hadd /tmp/amassiro/runDnew28Oct.root     /tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/DATA_27Oct2015_RunD_RAW_myTag/SingleElectron/crab_SingleElectron/151027_225555/000*/tr*.root
    cp /tmp/amassiro/runDnew28Oct.root       /tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/DATA_27Oct2015_RunD_RAW_myTag/SingleElectron/crab_SingleElectron/151027_225555
 
 
    hadd /tmp/amassiro/runDnew28OctV4.root   /tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/DATA_27Oct2015_RunD_RAW_myTag/SingleElectron/crab_SingleElectronV4/151027_225612/000*/tr*.root
 

Cleaning:

    ls /tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/2016/ | awk '{print "rm /tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/2016/"$1"/*/*/*/*/reco*.root"}'
    
    
Test:

    hadd /tmp/amassiro/MC.root /tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/MC15Dec2015/DYToEE_NNPDF30_13TeV-powheg-pythia8/crab_25ns_DYJetsToEE/151215_105021/0000/treeECALAlignment_*.root
    r99t /tmp/amassiro/MC.root 
    myTree = (TTree*) _file0->Get("ntupleEcalAlignment/myTree");
    myTree->Draw("DeltaEtaIn:nvtx","(electrons_classification==0 && ETSC>30) && mll<95 && mll>85  && HoE<0.3 && eleEcalIso<15 && (abs(DeltaEtaIn)<(25e-3)) && (abs(DeltaPhiIn)<(10e-3))","colz")
    myTree->Draw("DeltaPhiIn:nvtx","(electrons_classification==0 && ETSC>30) && mll<95 && mll>85  && HoE<0.3 && eleEcalIso<15 && (abs(DeltaEtaIn)<(25e-3)) && (abs(DeltaPhiIn)<(10e-3))","colz")

    myTree = (TTree*) _file0->Get("ntupleEcalAlignment/myTree");
    TH2F histoDeta("histoDeta","Deta",40,0,40,100,-0.005, 0.005);
    // myTree->Draw("DeltaEtaIn:nvtx >> histoDeta","(electrons_classification==0 && ETSC>30) && mll<95 && mll>85  && HoE<0.3 && eleEcalIso<15 && (abs(DeltaEtaIn)<(25e-3)) && (abs(DeltaPhiIn)<(10e-3))","colz");
    myTree->Draw("DeltaEtaIn:nvtx >> histoDeta","(electrons_classification==0 && ETSC>30) && mll<95 && mll>85  && HoE<0.3 && eleEcalIso<15 && (abs(DeltaEtaIn)<(25e-3)) && (abs(DeltaPhiIn)<(10e-3)) && (etaSC>0.0 && etaSC<1.5)","colz");
    // myTree->Draw("DeltaEtaIn:nvtx >> histoDeta","(electrons_classification==0 && ETSC>30) && mll<95 && mll>85  && HoE<0.3 && eleEcalIso<15 && (abs(DeltaEtaIn)<(25e-3)) && (abs(DeltaPhiIn)<(10e-3)) && (etaSC>1.5)","colz");
    histoDeta.Draw("colz");
    TProfile* sum_h_Sig_tx = (TProfile*) histoDeta.ProfileX();
    sum_h_Sig_tx->SetMarkerSize (1.5);
    sum_h_Sig_tx->SetMarkerStyle (22);
    sum_h_Sig_tx->SetMarkerColor (kRed);
    sum_h_Sig_tx->SetLineColor (kRed);
    sum_h_Sig_tx->SetLineWidth(3);
    sum_h_Sig_tx->SetLineStyle(1);
    
    histoDeta.GetYaxis()->SetRangeUser(-0.001, 0.001);
    histoDeta.GetXaxis()->SetTitle("number vertices");
    histoDeta.GetYaxis()->SetTitle("#Delta #eta");
    sum_h_Sig_tx->Draw("P same");
     

    histoDeta.GetYaxis()->SetRangeUser(-0.0005, 0.0005);
    sum_h_Sig_tx->Draw("P same");

    
    
    myTree = (TTree*) _file0->Get("ntupleEcalAlignment/myTree");
    TH2F histoDphi("histoDphi","Dphi",40,0,40,100,-0.005, 0.005);
    // myTree->Draw("DeltaPhiIn:nvtx >> histoDphi","eleCharge > 0 && (electrons_classification==0 && ETSC>30) && mll<95 && mll>85  && HoE<0.3 && eleEcalIso<15 && (abs(DeltaEtaIn)<(25e-3)) && (abs(DeltaPhiIn)<(10e-3))","colz");
    myTree->Draw("DeltaPhiIn:nvtx >> histoDphi","eleCharge > 0 && (electrons_classification==0 && ETSC>30) && mll<95 && mll>85  && HoE<0.3 && eleEcalIso<15 && (abs(DeltaEtaIn)<(25e-3)) && (abs(DeltaPhiIn)<(10e-3)) && (etaSC>0.0 && etaSC<1.5)","colz");
    // myTree->Draw("DeltaPhiIn:nvtx >> histoDphi","eleCharge > 0 && (electrons_classification==0 && ETSC>30) && mll<95 && mll>85  && HoE<0.3 && eleEcalIso<15 && (abs(DeltaEtaIn)<(25e-3)) && (abs(DeltaPhiIn)<(10e-3)) && (etaSC>1.5)","colz");
    histoDphi.Draw("colz");
    TProfile* sum_h_Sig_tx = (TProfile*) histoDphi.ProfileX();
    sum_h_Sig_tx->SetMarkerSize (1.5);
    sum_h_Sig_tx->SetMarkerStyle (22);
    sum_h_Sig_tx->SetMarkerColor (kRed);
    sum_h_Sig_tx->SetLineColor (kRed);
    sum_h_Sig_tx->SetLineWidth(3);
    sum_h_Sig_tx->SetLineStyle(1);
    
    histoDphi.GetYaxis()->SetRangeUser(0.000, 0.002);
    histoDphi.GetXaxis()->SetTitle("number vertices");
    histoDphi.GetYaxis()->SetTitle("#Delta #varphi");
    sum_h_Sig_tx->Draw("P same");
     

     
    TH2F histoDphi("histoDphi","Dphi",40,0,40,100,-0.001, 0.001);
    myTree->Draw("DeltaPhiIn:nvtx >> histoDphi","(electrons_classification==0 && ETSC>30) && mll<95 && mll>85  && HoE<0.3 && eleEcalIso<15 && (abs(DeltaEtaIn)<(25e-3)) && (abs(DeltaPhiIn)<(10e-3))","colz");

    
    
    TFile *f1 = new TFile("/tmp/amassiro/MC.root");
    TTree *ntuple = (TTree*) f1->Get("ntupleEcalAlignment/myTree");
    TFile *f2 = new TFile("/tmp/amassiro/small.root","recreate");
    TTree *small = ntuple->CopyTree("(electrons_classification==0 && ETSC>30) && mll<95 && mll>85  && HoE<0.3 && eleEcalIso<15 && (abs(DeltaEtaIn)<(25e-3)) && (abs(DeltaPhiIn)<(10e-3))");
    small->Write();
    
    
    
 
Compare data with reference MC:
    
    hadd /tmp/amassiro/treeECALAlignment.root \
       /tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/DATA29Aug2015AODAllData/SingleElectron/crab_SingleElectron/150827_143017/treeECALAlignment.root    \
       /tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/DATA29Aug2015AODRAWAllData/SingleElectron/crab_SingleElectron/150826_214823/treeECALAlignment.root  

    r99t drawModules.cxx\(\"/tmp/amassiro/treeECALAlignment.root\",\"2015Data\",\"electrons_classification\=\=0\&\&ETSC\>30\"\)

    
    
    
    hadd \
      /tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/DATA31Aug2015AODRAWAllDataRunB/SingleElectron/crab_SingleElectron/150831_145837/treeECALAlignment.root \
      /tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/DATA31Aug2015AODRAWAllDataRunB/SingleElectron/crab_SingleElectron/150831_145837/0000/treeECALAlign*.root
    
    
    
    
Plot all modules:

    
    python plotAlignmentModules.py
    python plotAlignmentModulesBis.py
    
    r99t drawComparison.cxx\(\"2015MC/MC.txt\",\"2015DataOldTrk/DATA.txt\",\"2015DataNewTrk/DATA.txt\"\)
    
    
    drawSingleModule  configurationPlot_cfg.py
    

Draw alignment coefficients:

    /afs/cern.ch/work/a/amassiro/ECALAlignment/CMSSW_7_3_3/src/EcalValidation/EcalAlignment/test
    

Get Luminosity:
    
    cp -r /afs/cern.ch/user/m/marlow/public/lcr2 ./
    python lcr2/lcr2.py -i json.txt
    
    
    export PATH=$HOME/.local/bin:/nfshome0/lumipro/brilconda/bin:$PATH
    brilcalc lumi -i json.txt
    

Draw coefficients comparison:

    r99t EB_Alignment_Draw.cxx\(\"../myEBAlignment_2015_MCtest_6k.txt\"\)
    r99t EE_Alignment_Draw.cxx\(\"../myEEAlignment_2015_MCtest_4k.txt\"\)

    r99t EB_Alignment_Draw.cxx\(\"../myEBAlignment_2015_MCtest_6k.txt\"\)
    r99t EB_Alignment_Draw.cxx\(\"../myEBAlignment_2015_MCtest_6k_bis.txt\"\)
    
    r99t EE_Alignment_Draw.cxx\(\"../myEEAlignment_2015_MCtest_4k.txt\"\)
    r99t EE_Alignment_Draw.cxx\(\"../myEEAlignment_2015_MCtest_4k_bis.txt\"\)

    r99t EB_Alignment_Draw.cxx\(\"../myEBAlignment_2015_MCtest_13k.txt\"\)

    r99t EB_Alignment_Draw.cxx\(\"../myEBAlignment_2015_MCtest_3k.txt\"\)
    r99t EB_Alignment_Draw.cxx\(\"../myEBAlignment_2015_MCtest_3k_bis.txt\"\)
            
    r99t EE_Alignment_Draw.cxx\(\"../myEEAlignment_2015_NewTrkAlign.txt.bis\"\)
    
    
    
    r99t EE_Alignment_Draw.cxx\(\"../myEEAlignment_2015.txt\",\"../data/myEEAlignment_2015_startup.txt\"\)
    r99t EB_Alignment_Draw.cxx\(\"../myEBAlignment_2015.txt\",\"../data/myEBAlignment_2015_startup.txt\"\)

    r99t EE_Alignment_Draw.cxx\(\"/afs/cern.ch/user/a/amassiro/public/ECAL_Alignment/2015/14Oct/myEEAlignment_2015.txt\",\"/afs/cern.ch/user/a/amassiro/public/ECAL_Alignment/2015/05Sep/myEEAlignment_2015.txt\"\)
    r99t EB_Alignment_Draw.cxx\(\"/afs/cern.ch/user/a/amassiro/public/ECAL_Alignment/2015/14Oct/myEBAlignment_2015.txt\",\"/afs/cern.ch/user/a/amassiro/public/ECAL_Alignment/2015/05Sep/myEBAlignment_2015.txt\"\)

    r99t EB_Alignment_Draw.cxx\(\"/afs/cern.ch/user/a/amassiro/public/ECAL_Alignment/2015/29Oct/myEBAlignment_2015_combined_27Oct.txt\",\"/afs/cern.ch/user/a/amassiro/public/ECAL_Alignment/2015/05Sep/myEBAlignment_2015.txt\"\)

    r99t EB_Alignment_Draw.cxx\(\"../myEBAlignment_2015_0Tesla_combined.txt\",\"../myEBAlignment_2015_combined_27Oct.txt\"\)

    r99t EB_Alignment_Draw.cxx\(\"../myEBAlignment_2016_NewTrkAlign_newPix_24May2016.txt\",\"../myEBAlignment_2015_combined_27Oct.txt\"\)

    r99t EB_Alignment_Draw.cxx\(\"../myEBAlignment_2016_NewTrkAlign_newPix_30May2016.txt\",\"../myEBAlignment_2016_NewTrkAlign_newPix_24May2016.txt\"\)
    r99t EB_Alignment_Draw.cxx\(\"../myEBAlignment_2016_NewTrkAlign_newPix_30May2016.txt\",\"../myEBAlignment_2015_combined_27Oct.txt\"\)

    r99t EB_Alignment_Draw.cxx\(\"../myEBAlignment_2017_combined.txt\",\"/afs/cern.ch/user/a/amassiro/public/ECAL_Alignment/2016/Jun01/myEBAlignment_2016.txt\"\)
    r99t EE_Alignment_Draw.cxx\(\"../myEEAlignment_2017_combined.txt\",\"/afs/cern.ch/user/a/amassiro/public/ECAL_Alignment/2016/Jun01/myEEAlignment_2016.txt\"\)

    
    
    
Draw:

    r99t drawModules.cxx\(\"/tmp/amassiro/treeECALAlignment.root\",\"25Aug2014\")
    r99t drawModules.cxx\(\"/tmp/amassiro/treeECALAlignment.root\",\"25Aug2014\",\"electrons_classification\=\=0\&\&ETSC\>20\"\)

    r99t drawModules.cxx\(\"/tmp/amassiro/treeECALAlignment.root\",\"14Oct2015\",\"1\"\)
    r99t drawModules.cxx\(\"runD.root\",\"14Oct2015\",\"1\"\)
    
    r99t drawModules.cxx\(\"/tmp/amassiro/runDnew.root\",\"23Oct2015\",\"1\"\)
    
    
General draw:

    r99t Draw.cxx\(\"/tmp/amassiro/eos/cms/store/user/amassiro/ECAL/Alignment/test06Jul2015/WJetsToLNu_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/crab_50ns_WJetsToLNu/150708_201650/0000/treeECALAlignment_1.root\",\"ETSC\",100,0,200,\"E_{T}\",\"1\"\)
    r99t Draw.cxx\(\"/tmp/amassiro/eos/cms/store/user/amassiro/ECAL/Alignment/test06Jul2015/WJetsToLNu_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/crab_50ns_WJetsToLNu/150708_201650/0000/treeECALAlignment_1.root\",\"iDetEB\",36,0,36,\"iDetEB\",\"1\"\)
    
    r99t Draw.cxx\(\"/tmp/amassiro/treeECALAlignment.root\",\"ETSC\",100,0,200,\"E_{T}\",\"1\"\)
    r99t Draw.cxx\(\"/tmp/amassiro/treeECALAlignment.root\",\"ETSC\",100,0,200,\"E_{T}\",\"ETSC\>20\"\)

    r99t Draw.cxx\(\"/tmp/amassiro/treeECALAlignment.root\",\"electrons_classification\",10,0,10,\"id\",\"1\"\)
    r99t Draw.cxx\(\"/tmp/amassiro/treeECALAlignment.root\",\"electrons_classification\",10,0,10,\"id\",\"ETSC\>20\"\)

    r99t Draw.cxx\(\"/tmp/amassiro/treeECALAlignment.root\",\"deltaEtaSuperClusterAtVtx\",100,-0.01,0.01,\"#Delta#eta\",\"ETSC\>20\"\)
    r99t Draw.cxx\(\"/tmp/amassiro/treeECALAlignment.root\",\"deltaEtaSuperClusterAtVtx\",100,-0.01,0.01,\"#Delta#eta\",\"electrons_classification\=\=0\&\&ETSC\>20\"\)

    r99t Draw.cxx\(\"treeECALAlignment_all_ideal_MC.root\",\"deltaEtaSuperClusterAtVtx\",100,-0.01,0.01,\"#Delta#eta\",\"electrons_classification\=\=0\&\&ETSC\>20\"\)
    r99t Draw.cxx\(\"treeECALAlignment_all_MC_standard.root\",\"deltaEtaSuperClusterAtVtx\",100,-0.01,0.01,\"#Delta#eta\",\"electrons_classification\=\=0\&\&ETSC\>20\"\)

    electrons_classification==0 && ETSC>30 && mll<95 && mll>85
    
    /tmp/amassiro/data_0T.root
    r99t Draw.cxx\(\"/tmp/amassiro/data_0T.root\",\"deltaEtaSuperClusterAtVtx\",100,-0.01,0.01,\"#Delta#eta\",\"electrons_classification\=\=0\&\&ETSC\>30\&\&mll\<95\&\&mll\>85\",\"data\ 0\ Tesla\"\)
    r99t Draw.cxx\(\"/tmp/amassiro/data_0T.root\",\"deltaEtaSuperClusterAtVtx\",100,-0.01,0.01,\"#Delta#eta\",\"electrons_classification\=\=0\&\&ETSC\>30\&\&mll\<95\&\&mll\>85\",\"data\ 0\ Tesla\"\)
    r99t Draw.cxx\(\"/tmp/amassiro/data_0T.root\",\"mll\",100,0,200,\"m_{ll}\",\"electrons_classification\=\=0\&\&ETSC\>30\",\"data\ 0\ Tesla\"\)
    r99t Draw.cxx\(\"/tmp/amassiro/data_0T.root\",\"etaSC\",100,-3,3,\"#eta_{electron}\",\"electrons_classification\=\=0\&\&ETSC\>30\",\"data\ 0\ Tesla\"\)
    r99t Draw.cxx\(\"/tmp/amassiro/data_0T.root\",\"mll\",100,0,200,\"m_{ll}\",\"electrons_classification\=\=0\&\&ETSC\>30\&\&etaSC\>1.5\",\"data\ 0\ Tesla\"\)
    r99t Draw.cxx\(\"/tmp/amassiro/data_0T.root\",\"mll\",100,0,200,\"m_{ll}\",\"electrons_classification\=\=0\&\&ETSC\>30\&\&etaSC\<-1.5\",\"data\ 0\ Tesla\"\)
    r99t Draw.cxx\(\"/tmp/amassiro/data_0T.root\",\"deltaEtaSuperClusterAtVtx\",100,-1,1,\"#Delta#eta\",\"electrons_classification\=\=0\&\&ETSC\>30\&\&etaSC\<-1.5\",\"data\ 0\ Tesla\"\)
    r99t Draw.cxx\(\"/tmp/amassiro/data_0T.root\",\"deltaEtaSuperClusterAtVtx\",100,-1,1,\"#Delta#eta\",\"electrons_classification\=\=0\&\&ETSC\>30\&\&etaSC\>1.5\",\"data\ 0\ Tesla\"\)
     
    r99t Draw.cxx\(\"/tmp/amassiro/data_0T.root\",\"mll\",100,0,200,\"m_{ll}\",\"electrons_classification\=\=0\&\&ETSC\>30\&\&HoE\<0.3\&\&eleEcalIso\<15\&\&etaSC\>1.5\",\"data\ 0\ Tesla\"\)
    r99t Draw.cxx\(\"/tmp/amassiro/data_0T.root\",\"mll\",100,0,200,\"m_{ll}\",\"electrons_classification\=\=0\&\&ETSC\>30\&\&HoE\<0.3\&\&eleEcalIso\<15\&\&etaSC\<-1.5\",\"data\ 0\ Tesla\"\)
    r99t Draw.cxx\(\"/tmp/amassiro/data_0T.root\",\"mll\",100,0,200,\"m_{ll}\",\"electrons_classification\=\=0\&\&ETSC\>30\&\&HoE\<0.3\&\&eleEcalIso\<15\&\&etaSC\>-1.5\&\&etaSC\<1.5\",\"data\ 0\ Tesla\"\)
      
    r99t Draw.cxx\(\"/tmp/amassiro/data_0T.root\",\"etaSC\",100,-3,3,\"#eta\",\"electrons_classification\=\=0\&\&ETSC\>30\&\&HoE\<0.3\&\&eleEcalIso\<15\",\"data\ 0\ Tesla\",\"ETSC\"\)
    r99t Draw.cxx\(\"/tmp/amassiro/data_38T.root\",\"etaSC\",100,-3,3,\"#eta\",\"electrons_classification\=\=0\&\&ETSC\>30\&\&HoE\<0.3\&\&eleEcalIso\<15\",\"data\ 3.8\ Tesla\",\"ETSC\"\)
    r99t Draw.cxx\(\"/tmp/amassiro/data_0T.root\",\"etaSC\",100,-3,3,\"#eta\",\"electrons_classification\=\=0\&\&ETSC\>30\&\&HoE\<0.3\&\&eleEcalIso\<15\",\"data\ 0\ Tesla\",\"1\"\)
    r99t Draw.cxx\(\"/tmp/amassiro/data_38T.root\",\"etaSC\",100,-3,3,\"#eta\",\"electrons_classification\=\=0\&\&ETSC\>30\&\&HoE\<0.3\&\&eleEcalIso\<15\",\"data\ 3.8\ Tesla\",\"1\"\)
    
    
     
    /tmp/amassiro/mc_0Tesla.root
    scp amassiro@cmsneu.cern.ch:/media/data/amassiro/ECALalignment/2016/Jan14/*.root /tmp/amassiro/
    r99t Draw.cxx\(\"/tmp/amassiro/mc_0Tesla.root\",\"deltaEtaSuperClusterAtVtx\",100,-0.01,0.01,\"#Delta#eta\",\"electrons_classification\=\=0\&\&ETSC\>30\&\&mll\<95\&\&mll\>85\",\"mc\ 0\ Tesla\"\)
    r99t Draw.cxx\(\"/tmp/amassiro/mc_0Tesla.root\",\"deltaEtaSuperClusterAtVtx\",100,-0.01,0.01,\"#Delta#eta\",\"electrons_classification\=\=0\&\&ETSC\>30\&\&mll\<95\&\&mll\>85\",\"mc\ 0\ Tesla\"\)
    r99t Draw.cxx\(\"/tmp/amassiro/mc_0Tesla.root\",\"mll\",100,0,200,\"m_{ll}\",\"electrons_classification\=\=0\&\&ETSC\>30\",\"mc\ 0\ Tesla\"\)
    r99t Draw.cxx\(\"/tmp/amassiro/mc_0Tesla.root\",\"etaSC\",100,-3,3,\"#eta_{electron}\",\"electrons_classification\=\=0\&\&ETSC\>30\",\"mc\ 0\ Tesla\"\)
    r99t Draw.cxx\(\"/tmp/amassiro/mc_0Tesla.root\",\"ETSC\",100,0,400,\"E_{T}\",\"electrons_classification\=\=0\&\&ETSC\>10\",\"mc\ 0\ Tesla\"\)
    
    r99t Draw.cxx\(\"/tmp/amassiro/mc_0Tesla.root\",\"mll\",100,0,200,\"m_{ll}\",\"electrons_classification\=\=0\&\&ETSC\>30\&\&HoE\<0.3\&\&eleEcalIso\<15\&\&etaSC\>1.5\",\"MC\ 0\ Tesla\"\)
    r99t Draw.cxx\(\"/tmp/amassiro/mc_0Tesla.root\",\"mll\",100,0,200,\"m_{ll}\",\"electrons_classification\=\=0\&\&ETSC\>30\&\&HoE\<0.3\&\&eleEcalIso\<15\&\&etaSC\<-1.5\",\"MC\ 0\ Tesla\"\)
    
    
    hadd /tmp/amassiro/ecal_fromLastYear.root /tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/2016/May18TeslaFrom2015AlignmentEEEB_bis/SingleElectron/crab_SingleElectron/160518_213655/0000/treeECALAlignment_*.root
    r99t Draw.cxx\(\"/tmp/amassiro/ecal_fromLastYear.root\",\"deltaEtaSuperClusterAtVtx\",100,-0.04,0.04,\"#Delta#eta\",\"electrons_classification\=\=0\&\&ETSC\>30\&\&abs\\\(etaSC\\\)\>1.5\",\"data\ EE\"\)
    r99t Draw.cxx\(\"/tmp/amassiro/ecal_fromLastYear.root\",\"deltaEtaSuperClusterAtVtx\",100,-0.04,0.04,\"#Delta#eta\",\"electrons_classification\=\=0\&\&ETSC\>30\&\&abs\\\(etaSC\\\)\<1.5\",\"data\ EB\"\)

    r99t Draw.cxx\(\"/tmp/amassiro/ecal_fromLastYear.root\",\"deltaEtaSuperClusterAtVtx\",100,-0.04,0.04,\"#Delta#eta\",\"mll\>80\&\&mll\<100\&\&ETSC\>20\&\&abs\\\(etaSC\\\)\>1.5\",\"data\ EE\"\)
    r99t Draw.cxx\(\"/tmp/amassiro/ecal_fromLastYear.root\",\"deltaEtaSuperClusterAtVtx\",100,-0.04,0.04,\"#Delta#eta\",\"mll\>80\&\&mll\<100\&\&ETSC\>20\&\&abs\\\(etaSC\\\)\<1.5\",\"data\ EB\"\)

    
    
    
General draw 2D:

    r99t Draw2D.cxx\(\"/tmp/amassiro/data_0T.root\",\"ETSC\",200,30,200,\"ET\",\"etaSC\",1000,-3,3,\"#eta\",\"electrons_classification\=\=0\&\&ETSC\>30\&\&HoE\<0.3\&\&eleEcalIso\<15\"\)
    r99t Draw2D.cxx\(\"/tmp/amassiro/data_38T.root\",\"ETSC\",200,30,200,\"ET\",\"etaSC\",1000,-3,3,\"#eta\",\"electrons_classification\=\=0\&\&ETSC\>30\&\&HoE\<0.3\&\&eleEcalIso\<15\"\)
    
    r99t Draw2D.cxx\(\"/tmp/amassiro/data_0T.root\",\"ETSC\",200,30,200,\"ET\",\"etaSC\",200,-0.5,0.5,\"#eta\",\"electrons_classification\=\=0\&\&ETSC\>30\&\&HoE\<0.3\&\&eleEcalIso\<15\"\)
    r99t Draw2D.cxx\(\"/tmp/amassiro/data_38T.root\",\"ETSC\",200,30,200,\"ET\",\"etaSC\",200,-0.5,0.5,\"#eta\",\"electrons_classification\=\=0\&\&ETSC\>30\&\&HoE\<0.3\&\&eleEcalIso\<15\"\)

    r99t Draw2D.cxx\(\"/tmp/amassiro/data_0T.root\",\"ETSC\",200,30,200,\"ET\",\"etaSC\",1000,-0.1,0.1,\"#eta\",\"electrons_classification\=\=0\&\&ETSC\>30\&\&HoE\<0.3\&\&eleEcalIso\<15\"\)
    r99t Draw2D.cxx\(\"/tmp/amassiro/data_38T.root\",\"ETSC\",200,30,200,\"ET\",\"etaSC\",1000,-0.1,0.1,\"#eta\",\"electrons_classification\=\=0\&\&ETSC\>30\&\&HoE\<0.3\&\&eleEcalIso\<15\"\)

    
    
    r99t Draw2D.cxx\(\"/tmp/amassiro/treeECALAlignment.root\",\"deltaEtaSuperClusterAtVtx\",50,-0.01,0.01,\"#Delta#eta\",\"etaSC\",10,-3,3,\"#eta_{SC}\",\"electrons_classification\=\=0\&\&ETSC\>30\"\)
    r99t Draw2D.cxx\(\"/tmp/amassiro/treeECALAlignment.root\",\"deltaEtaSuperClusterAtVtx\",50,-0.01,0.01,\"#Delta#eta\",\"etaSC\",10,-3,3,\"#eta_{SC}\",\"ETSC\>20\"\)
    r99t Draw2D.cxx\(\"/tmp/amassiro/treeECALAlignment.root\",\"deltaEtaSuperClusterAtVtx\",50,-0.01,0.01,\"#Delta#eta\",\"etaSC\",10,-3,3,\"#eta_{SC}\",\"ETSC\<20\"\)
    r99t Draw2D.cxx\(\"/tmp/amassiro/treeECALAlignment.root\",\"deltaEtaSuperClusterAtVtx\",50,-0.01,0.01,\"#Delta#eta\",\"etaSC\",10,-3,3,\"#eta_{SC}\",\"1\"\)


    r99t Draw2D.cxx\(\"treeECALAlignment_all_ideal_MC.root\",\"deltaEtaSuperClusterAtVtx\",50,-0.01,0.01,\"#Delta#eta\",\"etaSC\",10,-3,3,\"#eta_{SC}\",\"ETSC\>20\"\)
    r99t Draw2D.cxx\(\"treeECALAlignment_all_MC_standard.root\",\"deltaEtaSuperClusterAtVtx\",50,-0.01,0.01,\"#Delta#eta\",\"etaSC\",10,-3,3,\"#eta_{SC}\",\"ETSC\>20\"\)

    r99t Draw2D.cxx\(\"treeECALAlignment_all_ideal_MC.root\",\"deltaEtaSuperClusterAtVtx\",50,-0.01,0.01,\"#Delta#eta\",\"etaSC\",10,-3,3,\"#eta_{SC}\",\"electrons_classification\=\=0\&\&ETSC\>20\"\)
    r99t Draw2D.cxx\(\"treeECALAlignment_all_MC_standard.root\",\"deltaEtaSuperClusterAtVtx\",50,-0.01,0.01,\"#Delta#eta\",\"etaSC\",10,-3,3,\"#eta_{SC}\",\"electrons_classification\=\=0\&\&ETSC\>20\"\)
    
    
    r99t Draw2D.cxx\(\"treeECALAlignment_ideal.root\",\"deltaEtaSuperClusterAtVtx\",100,-0.02,0.02,\"#Delta#eta\",\"etaSC\",12,-3,3,\"#eta_{SC}\",\"electrons_classification\=\=0\&\&ETSC\>20\"\)
    r99t Draw2D.cxx\(\"treeECALAlignment_MC_standard.root\",\"deltaEtaSuperClusterAtVtx\",200,-0.02,0.02,\"#Delta#eta\",\"etaSC\",12,-3,3,\"#eta_{SC}\",\"electrons_classification\=\=0\&\&ETSC\>20\"\)
    
    
    r99t Draw2D.cxx\(\"treeECALAlignment_ideal.root\",\"deltaPhiSuperClusterAtVtx\",100,-0.08,0.08,\"#Delta#phi\",\"etaSC\",12,-3,3,\"#eta_{SC}\",\"electrons_classification\=\=0\&\&ETSC\>20\"\)
    r99t Draw2D.cxx\(\"treeECALAlignment_MC_standard.root\",\"deltaPhiSuperClusterAtVtx\",200,-0.08,0.08,\"#Delta#phi\",\"etaSC\",12,-3,3,\"#eta_{SC}\",\"electrons_classification\=\=0\&\&ETSC\>20\"\)
    
    r99t Draw2D.cxx\(\"treeECALAlignment_ideal.root\",\"deltaPhiSuperClusterAtVtx\",100,-0.08,0.08,\"#Delta#phi\",\"etaSC\",12,-3,3,\"#eta_{SC}\",\"eleCharge\>0\&\&electrons_classification\=\=0\&\&ETSC\>20\"\)
    r99t Draw2D.cxx\(\"treeECALAlignment_MC_standard.root\",\"deltaPhiSuperClusterAtVtx\",200,-0.08,0.08,\"#Delta#phi\",\"etaSC\",12,-3,3,\"#eta_{SC}\",\"eleCharge\>0\&\&electrons_classification\=\=0\&\&ETSC\>20\"\)
    
    r99t Draw2D.cxx\(\"treeECALAlignment_ideal.root\",\"deltaPhiSuperClusterAtVtx\",100,-0.08,0.08,\"#Delta#phi\",\"etaSC\",12,-3,3,\"#eta_{SC}\",\"eleCharge\<0\&\&electrons_classification\=\=0\&\&ETSC\>20\"\)
    r99t Draw2D.cxx\(\"treeECALAlignment_MC_standard.root\",\"deltaPhiSuperClusterAtVtx\",200,-0.08,0.08,\"#Delta#phi\",\"etaSC\",12,-3,3,\"#eta_{SC}\",\"eleCharge\<0\&\&electrons_classification\=\=0\&\&ETSC\>20\"\)
    
    
    
    r99t Draw2D.cxx\(\"/tmp/amassiro/ECALalignDATA_runC.root\",\"deltaEtaSuperClusterAtVtx\",200,-0.02,0.02,\"#Delta#eta\",\"time\",2000,1466500000,1468000000,\"time\",\"mll\>80\&\&mll\<100\&\&ETSC\>20\&\&abs\\\(etaSC\\\)\>1.5\"\)
    
    r99t Draw2D.cxx\(\"/tmp/amassiro/ECALalignDATA_runC.root\",\"deltaEtaSuperClusterAtVtx\",200,-0.02,0.02,\"#Delta#eta\",\"time\",2000,1466500000,1468000000,\"time\",\"mll\>80\&\&mll\<100\&\&ETSC\>20\&\&abs\\\(etaSC\\\)\<1.5\"\)
    
    
    
    
     TTree* tree = (TTree*)  _file0 -> Get ("ntupleEcalAlignment/myTree");

    tree->Draw("deltaEtaSuperClusterAtVtx:runId","electrons_classification==0 && ETSC>30 && mll<95 && mll>85", "colz")
    
    
    r99t MeasureTime.cxx\(\"/tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/2016/Aug11AlignmentEEEB_dump/DoubleEG/crab_DoubleElectron2016B/160815_103126/0000/treeECALAlignment_644.root\"\)
    
    r99t -q  MeasureTime.cxx\(\"/tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/2016/Aug11AlignmentEEEB_dump/DoubleEG/crab_DoubleElectron2016B/160815_103126/0000/treeECALAlignment_*.root\",0\)
    r99t -q MeasureTime.cxx\(\"/tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/2016/Aug11AlignmentEEEB_dump/DoubleEG/crab_DoubleElectron2016B/160815_103126/0000/treeECALAlignment_*.root\",1\)
    r99t -q MeasureTime.cxx\(\"/tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/2016/Aug11AlignmentEEEB_dump/DoubleEG/crab_DoubleElectron2016B/160815_103126/0000/treeECALAlignment_*.root\",2\)
    r99t -q MeasureTime.cxx\(\"/tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/2016/Aug11AlignmentEEEB_dump/DoubleEG/crab_DoubleElectron2016B/160815_103126/0000/treeECALAlignment_*.root\",3\)
    

    
    
    
    
    
    
    r99t -q  MeasureTime.cxx\(\"/tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/2016/Aug11AlignmentEEEB_dump/DoubleEG/crab_DoubleElectron2016B/160815_103126/0000/treeECALAlignment_*.root\",0,\"B0\"\)
    r99t -q MeasureTime.cxx\(\"/tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/2016/Aug11AlignmentEEEB_dump/DoubleEG/crab_DoubleElectron2016B/160815_103126/0000/treeECALAlignment_*.root\",1,\"B0\"\)
    r99t -q MeasureTime.cxx\(\"/tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/2016/Aug11AlignmentEEEB_dump/DoubleEG/crab_DoubleElectron2016B/160815_103126/0000/treeECALAlignment_*.root\",2,\"B0\"\)
    r99t -q MeasureTime.cxx\(\"/tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/2016/Aug11AlignmentEEEB_dump/DoubleEG/crab_DoubleElectron2016B/160815_103126/0000/treeECALAlignment_*.root\",3,\"B0\"\)
    
    
    r99t -q  MeasureTime.cxx\(\"/tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/2016/Aug11AlignmentEEEB_dump/DoubleEG/crab_DoubleElectron2016B/160815_103126/0001/treeECALAlignment_*.root\",0,\"B1\"\)
    r99t -q MeasureTime.cxx\(\"/tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/2016/Aug11AlignmentEEEB_dump/DoubleEG/crab_DoubleElectron2016B/160815_103126/0001/treeECALAlignment_*.root\",1,\"B1\"\)
    r99t -q MeasureTime.cxx\(\"/tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/2016/Aug11AlignmentEEEB_dump/DoubleEG/crab_DoubleElectron2016B/160815_103126/0001/treeECALAlignment_*.root\",2,\"B1\"\)
    r99t -q MeasureTime.cxx\(\"/tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/2016/Aug11AlignmentEEEB_dump/DoubleEG/crab_DoubleElectron2016B/160815_103126/0001/treeECALAlignment_*.root\",3,\"B1\"\)
    
    
    r99t -q  MeasureTime.cxx\(\"/tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/2016/Aug11AlignmentEEEB_dump/DoubleEG/crab_DoubleElectron2016B/160815_103126/0002/treeECALAlignment_*.root\",0,\"B2\"\)
    r99t -q MeasureTime.cxx\(\"/tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/2016/Aug11AlignmentEEEB_dump/DoubleEG/crab_DoubleElectron2016B/160815_103126/0002/treeECALAlignment_*.root\",1,\"B2\"\)
    r99t -q MeasureTime.cxx\(\"/tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/2016/Aug11AlignmentEEEB_dump/DoubleEG/crab_DoubleElectron2016B/160815_103126/0002/treeECALAlignment_*.root\",2,\"B2\"\)
    r99t -q MeasureTime.cxx\(\"/tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/2016/Aug11AlignmentEEEB_dump/DoubleEG/crab_DoubleElectron2016B/160815_103126/0002/treeECALAlignment_*.root\",3,\"B2\"\)
    
    
    r99t -q  MeasureTime.cxx\(\"/tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/2016/Aug11AlignmentEEEB_dump/DoubleEG/crab_DoubleElectron2016B/160815_103126/0000/treeECALAlignment_*.root\",0,\"B3\"\)
    r99t -q MeasureTime.cxx\(\"/tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/2016/Aug11AlignmentEEEB_dump/DoubleEG/crab_DoubleElectron2016B/160815_103126/0000/treeECALAlignment_*.root\",1,\"B3\"\)
    r99t -q MeasureTime.cxx\(\"/tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/2016/Aug11AlignmentEEEB_dump/DoubleEG/crab_DoubleElectron2016B/160815_103126/0000/treeECALAlignment_*.root\",2,\"B3\"\)
    r99t -q MeasureTime.cxx\(\"/tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/2016/Aug11AlignmentEEEB_dump/DoubleEG/crab_DoubleElectron2016B/160815_103126/0000/treeECALAlignment_*.root\",3,\"B3\"\)
    
    
    r99t -q  MeasureTime.cxx\(\"/tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/2016/Aug11AlignmentEEEB_dump/DoubleEG/crab_DoubleElectron2016B/160815_103126/0004/treeECALAlignment_*.root\",0,\"B4\"\)
    r99t -q MeasureTime.cxx\(\"/tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/2016/Aug11AlignmentEEEB_dump/DoubleEG/crab_DoubleElectron2016B/160815_103126/0004/treeECALAlignment_*.root\",1,\"B4\"\)
    r99t -q MeasureTime.cxx\(\"/tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/2016/Aug11AlignmentEEEB_dump/DoubleEG/crab_DoubleElectron2016B/160815_103126/0004/treeECALAlignment_*.root\",2,\"B4\"\)
    r99t -q MeasureTime.cxx\(\"/tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/2016/Aug11AlignmentEEEB_dump/DoubleEG/crab_DoubleElectron2016B/160815_103126/0004/treeECALAlignment_*.root\",3,\"B4\"\)
    
    
    r99t -q  MeasureTime.cxx\(\"/tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/2016/Aug11AlignmentEEEB_dump/DoubleEG/crab_DoubleElectron2016B/160815_103126/0005/treeECALAlignment_*.root\",0,\"B5\"\)
    r99t -q MeasureTime.cxx\(\"/tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/2016/Aug11AlignmentEEEB_dump/DoubleEG/crab_DoubleElectron2016B/160815_103126/0005/treeECALAlignment_*.root\",1,\"B5\"\)
    r99t -q MeasureTime.cxx\(\"/tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/2016/Aug11AlignmentEEEB_dump/DoubleEG/crab_DoubleElectron2016B/160815_103126/0005/treeECALAlignment_*.root\",2,\"B5\"\)
    r99t -q MeasureTime.cxx\(\"/tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/2016/Aug11AlignmentEEEB_dump/DoubleEG/crab_DoubleElectron2016B/160815_103126/0005/treeECALAlignment_*.root\",3,\"B5\"\)
    
    
    
    
    

    r99t -q  MeasureTime.cxx\(\"/tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/2016/Aug11AlignmentEEEB_dump/DoubleEG/crab_DoubleElectron2016C/160815_103118/0000/treeECALAlignment_*.root\",0,\"C0\"\)
    r99t -q MeasureTime.cxx\(\"/tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/2016/Aug11AlignmentEEEB_dump/DoubleEG/crab_DoubleElectron2016C/160815_103118/0000/treeECALAlignment_*.root\",1,\"C0\"\)
    r99t -q MeasureTime.cxx\(\"/tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/2016/Aug11AlignmentEEEB_dump/DoubleEG/crab_DoubleElectron2016C/160815_103118/0000/treeECALAlignment_*.root\",2,\"C0\"\)
    r99t -q MeasureTime.cxx\(\"/tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/2016/Aug11AlignmentEEEB_dump/DoubleEG/crab_DoubleElectron2016C/160815_103118/0000/treeECALAlignment_*.root\",3,\"C0\"\)

    r99t -q  MeasureTime.cxx\(\"/tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/2016/Aug11AlignmentEEEB_dump/DoubleEG/crab_DoubleElectron2016C/160815_103118/0001/treeECALAlignment_*.root\",0,\"C1\"\)
    r99t -q MeasureTime.cxx\(\"/tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/2016/Aug11AlignmentEEEB_dump/DoubleEG/crab_DoubleElectron2016C/160815_103118/0001/treeECALAlignment_*.root\",1,\"C1\"\)
    r99t -q MeasureTime.cxx\(\"/tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/2016/Aug11AlignmentEEEB_dump/DoubleEG/crab_DoubleElectron2016C/160815_103118/0001/treeECALAlignment_*.root\",2,\"C1\"\)
    r99t -q MeasureTime.cxx\(\"/tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/2016/Aug11AlignmentEEEB_dump/DoubleEG/crab_DoubleElectron2016C/160815_103118/0001/treeECALAlignment_*.root\",3,\"C1\"\)

    
    r99t -q  MeasureTime.cxx\(\"/tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/2016/Aug11AlignmentEEEB_dump/DoubleEG/crab_DoubleElectron2016D/160815_103133/0000/treeECALAlignment_*.root\",0,\"D0\"\)
    r99t -q MeasureTime.cxx\(\"/tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/2016/Aug11AlignmentEEEB_dump/DoubleEG/crab_DoubleElectron2016D/160815_103133/0000/treeECALAlignment_*.root\",1,\"D0\"\)
    r99t -q MeasureTime.cxx\(\"/tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/2016/Aug11AlignmentEEEB_dump/DoubleEG/crab_DoubleElectron2016D/160815_103133/0000/treeECALAlignment_*.root\",2,\"D0\"\)
    r99t -q MeasureTime.cxx\(\"/tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/2016/Aug11AlignmentEEEB_dump/DoubleEG/crab_DoubleElectron2016D/160815_103133/0000/treeECALAlignment_*.root\",3,\"D0\"\)
 
    r99t -q  MeasureTime.cxx\(\"/tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/2016/Aug11AlignmentEEEB_dump/DoubleEG/crab_DoubleElectron2016D/160815_103133/0001/treeECALAlignment_*.root\",0,\"D1\"\)
    r99t -q MeasureTime.cxx\(\"/tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/2016/Aug11AlignmentEEEB_dump/DoubleEG/crab_DoubleElectron2016D/160815_103133/0001/treeECALAlignment_*.root\",1,\"D1\"\)
    r99t -q MeasureTime.cxx\(\"/tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/2016/Aug11AlignmentEEEB_dump/DoubleEG/crab_DoubleElectron2016D/160815_103133/0001/treeECALAlignment_*.root\",2,\"D1\"\)
    r99t -q MeasureTime.cxx\(\"/tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/2016/Aug11AlignmentEEEB_dump/DoubleEG/crab_DoubleElectron2016D/160815_103133/0001/treeECALAlignment_*.root\",3,\"D1\"\)

    r99t -q  MeasureTime.cxx\(\"/tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/2016/Aug11AlignmentEEEB_dump/DoubleEG/crab_DoubleElectron2016D/160815_103133/0002/treeECALAlignment_*.root\",0,\"D2\"\)
<!--     r99t -q MeasureTime.cxx\(\"/tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/2016/Aug11AlignmentEEEB_dump/DoubleEG/crab_DoubleElectron2016D/160815_103133/0002/treeECALAlignment_*.root\",1,\"D2\"\) -->
    r99t -q MeasureTime.cxx\(\"/tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/2016/Aug11AlignmentEEEB_dump/DoubleEG/crab_DoubleElectron2016D/160815_103133/0002/treeECALAlignment_*.root\",2,\"D2\"\)
    r99t -q MeasureTime.cxx\(\"/tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/2016/Aug11AlignmentEEEB_dump/DoubleEG/crab_DoubleElectron2016D/160815_103133/0002/treeECALAlignment_*.root\",3,\"D2\"\)

    
    
    time_time_0_B0.txt
    
    cat time_time_0_??.txt   time_time_0_?.txt >   time_time_0.txt 
    cat time_time_1_??.txt   time_time_1_?.txt >   time_time_1.txt 
    cat time_time_2_??.txt   time_time_2_?.txt >   time_time_2.txt 
    cat time_time_3_??.txt   time_time_3_?.txt >   time_time_3.txt 
 
    r99t plotVsTime.cxx\(\"time_time\"\)
    
    
    cat time_Mass_time_0_*.txt   >   time_Mass_time_0.txt 
    cat time_Mass_time_1_*.txt   >   time_Mass_time_1.txt 
    cat time_Mass_time_2_*.txt   >   time_Mass_time_2.txt 
    cat time_Mass_time_3_*.txt   >   time_Mass_time_3.txt 
 
    
    
    r99t plotVsTimeMass.cxx\(\"time_Mass_time\"\)
    
    
    
    
Plot arbitrary variable

    r99t -q MeasureTimeMassArbitraryDistribution.cxx\(\"/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/noSRatPF/DoubleEG/crab_DoubleElectrin2017B_v1/171010_160831/0000/treeECALAlignment_361.root\",\"myTest\",\"etaSC\",1000,-1,1\)

    r99t -q MeasureTimeMassArbitraryDistribution.cxx\(\"/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/noSRatPF/DoubleEG/crab_DoubleElectrin2017B_v1/171010_160831/0000/treeECALAlignment_*.root\",\"dump_eleEcalIso\",\"eleEcalIso\",1000,0,10\)

    
    
    
    
    
    
    
    
    
    
    
    