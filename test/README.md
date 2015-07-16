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
    
    cmsRun reco_RAW2DIGI_RECO_AOD.py  \
        inputFiles=file:/tmp/amassiro/0612FA2F-C025-E511-AA96-02163E014770.root  \
        outputFile=treeAlignDataFromRAW.root

        
    
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

e.g.

    subtract two tags
    CombineRotoTraslations   myEEAlignment_2011.txt   myEEAlignment_2012.txt    myEEAlignment_2011_2012_difference.txt
    CombineRotoTraslations   myEBAlignment_2011.txt   myEBAlignment_2012.txt    myEBAlignment_2011_2012_difference.txt






    
    