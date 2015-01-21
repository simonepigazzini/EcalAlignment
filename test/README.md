Examples
====

Test file with perfect ideal MC geometry:

    scp amassiro@cmsneu.cern.ch:/data/amassiro/CMSSWRoot/Spring14/AODSIM/DYEE_DESIGN_ALIGNMENT/001DC3E2-0C22-E411-975E-002590DB924E.root /tmp/amassiro/


run:

    cmsRun Dump_MC_cfg.py     inputFiles=file:/tmp/amassiro/001DC3E2-0C22-E411-975E-002590DB924E.root    outputFile=/tmp/amassiro/treeECALAlignment.root

Test file with DATA:

    scp amassiro@cmsneu.cern.ch:/data/amassiro/CMSSWRoot/DATA2012/DoubleElectron_Run2012B-ZElectron-13Jul2012-v1_RAW-RECO/FEE043A5-93D4-E111-84DC-0030486790C0.root /tmp/amassiro/

run:
    
    cmsRun RAW2RECO_DATA_cfg.py  \
        inputFiles=file:/tmp/amassiro/FEE043A5-93D4-E111-84DC-0030486790C0.root  \
        outputFile=reco_raw.root \
        isMC=False


    
Fake GRID
====

to run through GRID in local machine:

    cmsRun Dump_MC_local_GRID_cfg.py     outputFile=/tmp/amassiro/treeECALAlignment_all.root

    cmsRun Dump_MC_local_GRID_cfg_TEMP.py  listFiles=list/myfilelist_DYEE.py   outputFile=/tmp/amassiro/treeECALAlignment_all_MC_standard.root
    cmsRun Dump_MC_local_GRID_cfg_TEMP.py  listFiles=list/myfilelist_DYEE_big.py   outputFile=/tmp/amassiro/treeECALAlignment_all_MC_standard.root

    
See here for the files definition (from DAS, plain dump):

    list/myfilelist.py


    
    
    
    