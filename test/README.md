Examples
====


Test file with perfect ideal MC geometry:

    scp amassiro@cmsneu.cern.ch:/data/amassiro/CMSSWRoot/Spring14/AODSIM/DYEE_DESIGN_ALIGNMENT/001DC3E2-0C22-E411-975E-002590DB924E.root /tmp/amassiro/


run:

    cmsRun Dump_MC_cfg.py     inputFiles=file:/tmp/amassiro/001DC3E2-0C22-E411-975E-002590DB924E.root    outputFile=/tmp/amassiro/treeECALAlignment.root
