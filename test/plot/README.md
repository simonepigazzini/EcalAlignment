Plot tools
====

Get reference using MC trees:

    void drawModules(TString nameInFileRoot, TString nameOutputDir, TString nameDATA, TString commonCut = "1")
    r99t drawModulesMC.cxx\(\"root://eoscms.cern.ch//store/user/amassiro/ECAL/Alignment/test13Mar2015/DYToEE_M-50_Tune4C_13TeV-pythia8/crab_DYll/150315_215425/0000/treeECALAlignment_1.root\",\"25Aug2014\",\"2015MC\"\)
    r99t drawModulesMC.cxx\(\"root://eoscms.cern.ch//store/user/amassiro/ECAL/Alignment/test13Mar2015/DYToEE_M-50_Tune4C_13TeV-pythia8/crab_DYll/150315_215425/0000/treeECALAlignment_1.root\",\"25Aug2014\",\"2015MC\",\"electrons_classification\=\=0\&\&ETSC\>20\"\)

    r99t drawModulesMC.cxx\(\"root://eoscms.cern.ch//store/user/amassiro/ECAL/Alignment/test13Mar2015/DYToEE_M-50_Tune4C_13TeV-pythia8/crab_DYll/150315_215425/0000/treeECALAlignment_*.root\",\"25Aug2014\",\"2015MC\",\"electrons_classification\=\=0\&\&ETSC\>20\"\)
    

Draw alignment coefficients:

    /afs/cern.ch/work/a/amassiro/ECALAlignment/CMSSW_7_3_3/src/EcalValidation/EcalAlignment/test
    

Draw:

    r99t drawModules.cxx\(\"/tmp/amassiro/treeECALAlignment.root\",\"25Aug2014\",\"2015MC\"\)
    r99t drawModules.cxx\(\"/tmp/amassiro/treeECALAlignment.root\",\"25Aug2014\",\"2015MC\",\"electrons_classification\=\=0\&\&ETSC\>20\"\)


General draw:

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
    