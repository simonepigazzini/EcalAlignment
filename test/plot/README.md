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
    
    
    
Plot all modules:

    python plotAlignmentModules.py
    
    r99t drawComparison.cxx\(\"2015MC/MC.txt\",\"2015DataOldTrk/DATA.txt\",\"2015DataNewTrk/DATA.txt\"\)
    
    

Draw alignment coefficients:

    /afs/cern.ch/work/a/amassiro/ECALAlignment/CMSSW_7_3_3/src/EcalValidation/EcalAlignment/test
    

Get Luminosity:
    
    cp -r /afs/cern.ch/user/m/marlow/public/lcr2 ./
    python lcr2/lcr2.py -i json.txt

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
    
    
    
    
Draw:

    r99t drawModules.cxx\(\"/tmp/amassiro/treeECALAlignment.root\",\"25Aug2014\",\"2015MC\"\)
    r99t drawModules.cxx\(\"/tmp/amassiro/treeECALAlignment.root\",\"25Aug2014\",\"2015MC\",\"electrons_classification\=\=0\&\&ETSC\>20\"\)


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

General draw 2D:

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
    