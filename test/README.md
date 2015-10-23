Examples
====

Test file with perfect ideal MC geometry:

    scp amassiro@cmsneu.cern.ch:/media/data/CMSSWRoot/RunIISpring15DR74//WJetsToLNu_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/AODSIM/006D71A7-73FC-E411-8C41-6CC2173BBE60.root /tmp/amassiro/
    
run:

    cmsRun Dump_MC_cfg.py     inputFiles=file:/tmp/amassiro/006D71A7-73FC-E411-8C41-6CC2173BBE60.root    outputFile=/tmp/amassiro/treeECALAlignment.root

Test file with DATA:

    scp amassiro@cmsneu.cern.ch:/media/data/CMSSWRoot/DATARunII/Run2015B/SingleElectron/PromptReco-v1_AOD/82589B55-5827-E511-AE9F-02163E012704.root /tmp/amassiro/
    scp amassiro@cmsneu.cern.ch:/media/data/CMSSWRoot/DATARunII/Run2015B/DoubleEG/RAW/0612FA2F-C025-E511-AA96-02163E014770.root /tmp/amassiro/
    
run:
    
    cmsRun RAW2RECO_DATA_cfg.py  \
        inputFiles=file:/tmp/amassiro/FEE043A5-93D4-E111-84DC-0030486790C0.root  \
        outputFile=reco_raw.root \
        isMC=False


    cmsRun Dump_DATA_cfg.py  \
        inputFiles=file:/tmp/amassiro/82589B55-5827-E511-AE9F-02163E012704.root  \
        outputFile=treeAlignData.root

    @reco level
    cmsRun Dump_DATA_cfg.py  \
        inputFiles=file:/tmp/amassiro/00617385-B658-E511-A45F-0025905A60F4.root  \
        outputFile=treeAlignData.root

    scp amassiro@cmsneu.cern.ch:/media/data/CMSSWRoot/DATARunII/Run2015B/DoubleEG/RAW/0612FA2F-C025-E511-AA96-02163E014770.root /tmp/amassiro/    
    cmsRun reco_RAW2DIGI_RECO_AOD.py  \
        inputFiles=file:/tmp/amassiro/0612FA2F-C025-E511-AA96-02163E014770.root  \
        outputFile=treeAlignDataFromRAW.root

    cmsRun reco_my_tag_RAW2DIGI_RECO_AOD.py  \
        inputFiles=file:/tmp/amassiro/0612FA2F-C025-E511-AA96-02163E014770.root  \
        outputFile=treeAlignDataFromRAWmyTag.root

        
    @raw level (electron stream)
    scp amassiro@cmsneu.cern.ch:/media/data/CMSSWRoot/DATARunII/Run2015B/ElectronStream/RAW/4C45E949-8A2E-E511-BE26-02163E011DDE.root /tmp/amassiro/
    cmsRun reco_STREAMRAW2DIGI_RECO_AOD.py  \
        inputFiles=file:/tmp/amassiro/4C45E949-8A2E-E511-BE26-02163E011DDE.root  \
        outputFile=treeAlignDataElectronStream.root
        
closure test:

    cmsRun reco_my_tag_RAW2DIGI_RECO_AOD.py  \
        inputFiles=file:/tmp/amassiro/0612FA2F-C025-E511-AA96-02163E014770.root  \
        outputFile=treeAlignDataFromRAWmyTag.root
        
    
Fake GRID
====

to run through GRID in local machine:

    cmsRun Dump_MC_local_GRID_cfg.py     outputFile=/tmp/amassiro/treeECALAlignment_all.root

    cmsRun Dump_MC_local_GRID_cfg_TEMP.py  listFiles=list/myfilelist_DYEE.py   outputFile=/tmp/amassiro/treeECALAlignment_all_MC_standard.root
    cmsRun Dump_MC_local_GRID_cfg_TEMP.py  listFiles=list/myfilelist_DYEE_big.py   outputFile=/tmp/amassiro/treeECALAlignment_all_MC_standard.root

    
See here for the files definition (from DAS, plain dump):

    list/myfilelist.py


    

Alignment
====

Get alignment values out of the trees

    EE_Alignment_RotoTraslation align/AlignEE_Zee_2015_cfg.py
    EB_Alignment_RotoTraslation align/AlignEB_Zee_2015_cfg.py
    


CombineRotoTraslations
====

    CombineRotoTraslations   origin.txt    modification.txt    new.txt
    CombineRotoTraslations   /afs/cern.ch/user/a/amassiro/public/ECAL_Alignment/1Mar2011/myEEAlignment_2010.txt   myEEAlignment_2011.txt    myEEAlignment_2011_combined.txt

    CombineRotoTraslations   /afs/cern.ch/user/a/amassiro/public/ECAL_Alignment/2015/05Sep/myEBAlignment_2015.txt  myEBAlignment_2015_NewTrkAlign_13Oct2015.txt    myEBAlignment_2015_combined.txt
    CombineRotoTraslations   /afs/cern.ch/user/a/amassiro/public/ECAL_Alignment/2015/05Sep/myEEAlignment_2015.txt  myEEAlignment_2015_NewTrkAlign_13Oct2015.txt    myEEAlignment_2015_combined.txt

    CombineRotoTraslations  /afs/cern.ch/user/a/amassiro/public/ECAL_Alignment/2015/14Oct/myEBAlignment_2015.txt   myEBAlignment_2015_NewTrkAlign_23Oct2015.txt    myEBAlignment_2015_combined.txt

    
e.g.

    subtract two tags
    CombineRotoTraslations   myEEAlignment_2011.txt   myEEAlignment_2012.txt    myEEAlignment_2011_2012_difference.txt
    CombineRotoTraslations   myEBAlignment_2011.txt   myEBAlignment_2012.txt    myEBAlignment_2011_2012_difference.txt


Create local sqlite db
====


    cmsRun  copyFileAlignEE_cfg.py
    cmsRun  copyFileAlignEB_cfg.py

    

Check alignment in GT
====

Tag used for alignment:
    
    conddb list 74X_dataRun2_Prompt_v0 |grep EEAlig
    EEAlignmentRcd - EEAlignment_measured_v02_express

Check time when payloads have been prepared:

    conddb list EEAlignment_measured_v02_express

    Since   Insertion Time Payload                                   Object Type ------ -------------------  ---------------------------------------- ----------- 1       2008-01-01 00:00:42 0ea551bf621ce4610d0a86a8fb854c6cfe8b297c  Alignments 164492 2008-01-01 00:00:42  da6ea141a70d5d97eba7f895ff617d19f478ddde Alignments 184519  2008-01-01 00:00:42 049a24d4eca8dc8bfa35092de7ed079d5fda056d  Alignments

Dump last payload:

    conddb dump --type payload --format xml 049a24d4eca8dc8bfa35092de7ed079d5fda056d > dump.xml

    


    
    