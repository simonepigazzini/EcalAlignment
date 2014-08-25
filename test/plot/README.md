Plot tools
====

    r99t drawModules.cxx\(\"/tmp/amassiro/treeECALAlignment.root\",\"25Aug2014\",\"2015MC\"\)
    r99t drawModules.cxx\(\"/tmp/amassiro/treeECALAlignment.root\",\"25Aug2014\",\"2015MC\",\"electrons_classification==0&&ETSC>20\"\)


General draw:

    r99t Draw.cxx\(\"/tmp/amassiro/treeECALAlignment.root\",\"ETSC\",100,0,200,\"E_{T}\",\"1\"\)
    r99t Draw.cxx\(\"/tmp/amassiro/treeECALAlignment.root\",\"ETSC\",100,0,200,\"E_{T}\",\"ETSC\>20\"\)

    r99t Draw.cxx\(\"/tmp/amassiro/treeECALAlignment.root\",\"electrons_classification\",10,0,10,\"id\",\"1\"\)
    r99t Draw.cxx\(\"/tmp/amassiro/treeECALAlignment.root\",\"electrons_classification\",10,0,10,\"id\",\"ETSC\>20\"\)

    r99t Draw.cxx\(\"/tmp/amassiro/treeECALAlignment.root\",\"deltaEtaSuperClusterAtVtx\",100,-0.01,0.01,\"#Delta#eta\",\"ETSC\>20\"\)
    r99t Draw.cxx\(\"/tmp/amassiro/treeECALAlignment.root\",\"deltaEtaSuperClusterAtVtx\",100,-0.01,0.01,\"#Delta#eta\",\"electrons_classification\=\=0\&\&ETSC\>20\"\)
