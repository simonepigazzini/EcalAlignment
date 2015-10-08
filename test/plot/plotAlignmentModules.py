import os

print "Check all SM and Dee alignment"

#####
# mc

#for x in range(0, 36):
  ##toexec = "root -b -q drawSingleModule.cxx\(\\\"/tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/MC14Jul2015/WJetsToLNu_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/crab_50ns_WJetsToLNu/150714_075454/0000/treeECALAlignment_*.root\\\",\\\"2015MC\\\",\\\"mc_weight*electrons_classification\=\=0\&\&ETSC\>30\&\&met\>30\\\"," + str(x) + ",-100\)"
  #toexec = "root -b -q drawSingleModule.cxx\(\\\"/tmp/amassiro/wjets.root\\\",\\\"2015MC\\\",\\\"mc_weight*electrons_classification\=\=0\&\&ETSC\>30\&\&met\>30\\\"," + str(x) + ",-100\)"
  #print "toexec = ", toexec
  #os.system (toexec)
  
#for x in range(0, 4):
  ##toexec = "root -b -q drawSingleModule.cxx\(\\\"/tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/MC14Jul2015/WJetsToLNu_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/crab_50ns_WJetsToLNu/150714_075454/0000/treeECALAlignment_*.root\\\",\\\"2015MC\\\",\\\"mc_weight*electrons_classification\=\=0\&\&ETSC\>30\&\&met\>30\\\",-100," + str(x) + "\)"
  #toexec = "root -b -q drawSingleModule.cxx\(\\\"/tmp/amassiro/wjets.root\\\",\\\"2015MC\\\",\\\"mc_weight*electrons_classification\=\=0\&\&ETSC\>30\&\&met\>30\\\",-100," + str(x) + "\)"
  #print "toexec = ", toexec
  #os.system (toexec)

#######  
# data

#for x in range(0, 36):
  ##toexec = "root -b -q drawSingleModule.cxx\(\\\"/tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/DATA14Jul2015/SingleElectron/crab_SingleElectron/150715_154047/treeECALAlignment_DATA_oldTrkAlign.root\\\",\\\"2015DataOldTrk\\\",\\\"electrons_classification\=\=0\&\&ETSC\>30\&\&met\>30\\\"," + str(x) + ",-100,0\)"
  #toexec = "root -b -q drawSingleModule.cxx\(\\\"/tmp/amassiro/data.root\\\",\\\"2015DataOldTrk\\\",\\\"electrons_classification\=\=0\&\&ETSC\>30\\\"," + str(x) + ",-100,0\)"
  #print "toexec = ", toexec
  #os.system (toexec)
  
#for x in range(0, 4):
  ##toexec = "root -b -q drawSingleModule.cxx\(\\\"/tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/DATA14Jul2015/SingleElectron/crab_SingleElectron/150715_154047/treeECALAlignment_DATA_oldTrkAlign.root\\\",\\\"2015DataOldTrk\\\",\\\"electrons_classification\=\=0\&\&ETSC\>30\&\&met\>30\\\",-100," + str(x) + ",0\)"
  #toexec = "root -b -q drawSingleModule.cxx\(\\\"/tmp/amassiro/data.root\\\",\\\"2015DataOldTrk\\\",\\\"electrons_classification\=\=0\&\&ETSC\>30\\\",-100," + str(x) + ",0\)"
  #print "toexec = ", toexec
  #os.system (toexec)



########  
## data2

#for x in range(0, 36):
  ##toexec = "root -b -q drawSingleModule.cxx\(\\\"/tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/DATA22Jul2015AODRAW/SingleElectron/crab_SingleElectron/150721_164215/000?/treeECALAlignment_*.root\\\",\\\"2015DataNewTrk\\\",\\\"electrons_classification\=\=0\&\&ETSC\>30\&\&met\>30\\\"," + str(x) + ",-100,0\)"
  #toexec = "root -b -q drawSingleModule.cxx\(\\\"/tmp/amassiro/dataNewTrk.root\\\",\\\"2015DataNewTrk\\\",\\\"electrons_classification\=\=0\&\&ETSC\>30\\\"," + str(x) + ",-100,0\)"
  #print "toexec = ", toexec
  #os.system (toexec)
  
#for x in range(0, 4):
  ##toexec = "root -b -q drawSingleModule.cxx\(\\\"/tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/DATA22Jul2015AODRAW/SingleElectron/crab_SingleElectron/150721_164215/000?/treeECALAlignment_*.root\\\",\\\"2015DataNewTrk\\\",\\\"electrons_classification\=\=0\&\&ETSC\>30\&\&met\>30\\\",-100," + str(x) + ",0\)"
  #toexec = "root -b -q drawSingleModule.cxx\(\\\"/tmp/amassiro/dataNewTrk.root\\\",\\\"2015DataNewTrk\\\",\\\"electrons_classification\=\=0\&\&ETSC\>30\\\",-100," + str(x) + ",0\)"
  #print "toexec = ", toexec
  #os.system (toexec)



   #hadd /tmp/amassiro/tree_MC.root /tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/MC14Jul2015/WJetsToLNu_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/crab_50ns_WJetsToLNu/150714_075454/0000/treeECALAlignment_*.root

#for x in range(0, 36):
  ##toexec = "root -b -q drawSingleModule.cxx\(\\\"/tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/DATA31Aug2015AODRAWAllDataRunC/SingleElectron/crab_SingleElectron/150903_113327/treeECALAlignment.root\\\",\\\"2015DataNewTrk\\\",\\\"electrons_classification\=\=0\&\&ETSC\>30\&\&met\>30\\\"," + str(x) + ",-100,0\)"
  #toexec = "root -b -q drawSingleModule.cxx\(\\\"/tmp/amassiro/dataNew.root\\\",\\\"2015DataNew\\\",\\\"electrons_classification\=\=0\&\&ETSC\>30\\\"," + str(x) + ",-100,0,\\\"/tmp/amassiro/tree_MC.root\\\"\)"
  #print "toexec = ", toexec
  #os.system (toexec)
  
#for x in range(0, 4):
  ##toexec = "root -b -q drawSingleModule.cxx\(\\\"/tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/DATA31Aug2015AODRAWAllDataRunC/SingleElectron/crab_SingleElectron/150903_113327/treeECALAlignment.root\\\",\\\"2015DataNewTrk\\\",\\\"electrons_classification\=\=0\&\&ETSC\>30\&\&met\>30\\\",-100," + str(x) + ",0\)"
  #toexec = "root -b -q drawSingleModule.cxx\(\\\"/tmp/amassiro/dataNew.root\\\",\\\"2015DataNew\\\",\\\"electrons_classification\=\=0\&\&ETSC\>30\\\",-100," + str(x) + ",0,\\\"/tmp/amassiro/tree_MC.root\\\"\)"
  #print "toexec = ", toexec
  #os.system (toexec)


#for x in range(0, 36):
  #toexec = "root -b -q drawSingleModule.cxx\(\\\"/tmp/amassiro/newData04Sep.root\\\",\\\"2015DataNew04Sep\\\",\\\"electrons_classification\=\=0\&\&ETSC\>30\\\"," + str(x) + ",-100,0,\\\"/tmp/amassiro/tree_MC.root\\\"\)"
  #print "toexec = ", toexec
  #os.system (toexec)
  
#for x in range(0, 4):
  #toexec = "root -b -q drawSingleModule.cxx\(\\\"/tmp/amassiro/newData04Sep.root\\\",\\\"2015DataNew04Sep\\\",\\\"electrons_classification\=\=0\&\&ETSC\>30\\\",-100," + str(x) + ",0,\\\"/tmp/amassiro/tree_MC.root\\\"\)"
  #print "toexec = ", toexec
  #os.system (toexec)


#for x in range(0, 36):
  #toexec = "root -b -q drawSingleModule.cxx\(\\\"/tmp/amassiro/newData05SepLastTrk.root\\\",\\\"2015DataNew05SepLastTrk\\\",\\\"electrons_classification\=\=0\&\&ETSC\>30\\\"," + str(x) + ",-100,0,\\\"/tmp/amassiro/tree_MC.root\\\"\)"
  #print "toexec = ", toexec
  #os.system (toexec)
  
#for x in range(0, 4):
  #toexec = "root -b -q drawSingleModule.cxx\(\\\"/tmp/amassiro/newData05SepLastTrk.root\\\",\\\"2015DataNew05SepLastTrk\\\",\\\"electrons_classification\=\=0\&\&ETSC\>30\\\",-100," + str(x) + ",0,\\\"/tmp/amassiro/tree_MC.root\\\"\)"
  #print "toexec = ", toexec
  #os.system (toexec)



#for x in range(0, 36):
  #toexec = "root -b -q drawSingleModule.cxx\(\\\"/tmp/amassiro/tree_Run.root\\\",\\\"2015DataNew14SepLastTrk\\\",\\\"electrons_classification\=\=0\&\&ETSC\>30\\\"," + str(x) + ",-100,0,\\\"/tmp/amassiro/tree_MC.root\\\"\)"
  #print "toexec = ", toexec
  #os.system (toexec)
  
#for x in range(0, 4):
  #toexec = "root -b -q drawSingleModule.cxx\(\\\"/tmp/amassiro/tree_Run.root\\\",\\\"2015DataNew14SepLastTrk\\\",\\\"electrons_classification\=\=0\&\&ETSC\>30\\\",-100," + str(x) + ",0,\\\"/tmp/amassiro/tree_MC.root\\\"\)"
  #print "toexec = ", toexec
  #os.system (toexec)



#for x in range(0, 36):
  #toexec = "root -b -q drawSingleModule.cxx\(\\\"/tmp/amassiro/runC.root\\\",\\\"2015DataNew22SepLastTrkRunC\\\",\\\"electrons_classification\=\=0\&\&ETSC\>30\\\"," + str(x) + ",-100,0,\\\"/tmp/amassiro/tree_MC.root\\\"\)"
  #print "toexec = ", toexec
  #os.system (toexec)
  
#for x in range(0, 4):
  #toexec = "root -b -q drawSingleModule.cxx\(\\\"/tmp/amassiro/runC.root\\\",\\\"2015DataNew22SepLastTrkRunC\\\",\\\"electrons_classification\=\=0\&\&ETSC\>30\\\",-100," + str(x) + ",0,\\\"/tmp/amassiro/tree_MC.root\\\"\)"
  #print "toexec = ", toexec
  #os.system (toexec)



#for x in range(0, 36):
  #toexec = "root -b -q drawSingleModule.cxx\(\\\"/tmp/amassiro/runB.root\\\",\\\"2015DataNew22SepLastTrkRunB\\\",\\\"electrons_classification\=\=0\&\&ETSC\>30\\\"," + str(x) + ",-100,0,\\\"/tmp/amassiro/tree_MC.root\\\"\)"
  #print "toexec = ", toexec
  #os.system (toexec)
  
#for x in range(0, 4):
  #toexec = "root -b -q drawSingleModule.cxx\(\\\"/tmp/amassiro/runB.root\\\",\\\"2015DataNew22SepLastTrkRunB\\\",\\\"electrons_classification\=\=0\&\&ETSC\>30\\\",-100," + str(x) + ",0,\\\"/tmp/amassiro/tree_MC.root\\\"\)"
  #print "toexec = ", toexec
  #os.system (toexec)




for x in range(0, 36):
  toexec = "root -b -q drawSingleModule.cxx\(\\\"/tmp/amassiro/runD.root\\\",\\\"2015DataNew22SepLastTrkRunD\\\",\\\"electrons_classification\=\=0\&\&ETSC\>30\\\"," + str(x) + ",-100,0,\\\"/tmp/amassiro/tree_MC.root\\\"\)"
  print "toexec = ", toexec
  os.system (toexec)
  
for x in range(0, 4):
  toexec = "root -b -q drawSingleModule.cxx\(\\\"/tmp/amassiro/runD.root\\\",\\\"2015DataNew22SepLastTrkRunD\\\",\\\"electrons_classification\=\=0\&\&ETSC\>30\\\",-100," + str(x) + ",0,\\\"/tmp/amassiro/tree_MC.root\\\"\)"
  print "toexec = ", toexec
  os.system (toexec)





#for x in range(0, 36):
  ##toexec = "root -b -q drawSingleModule.cxx\(\\\"/tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/DATA14Jul2015/SingleElectron/crab_SingleElectron/150715_154047/treeECALAlignment_DATA_oldTrkAlign.root\\\",\\\"2015DataOldTrk\\\",\\\"electrons_classification\=\=0\&\&ETSC\>30\&\&met\>30\\\"," + str(x) + ",-100,0\)"
  #toexec = "root -b -q drawSingleModule.cxx\(\\\"/tmp/amassiro/dataOld.root\\\",\\\"2015DataOld\\\",\\\"electrons_classification\=\=0\&\&ETSC\>30\\\"," + str(x) + ",-100,0,\\\"/tmp/amassiro/tree_MC.root\\\"\)"
  #print "toexec = ", toexec
  #os.system (toexec)
  
#for x in range(0, 4):
  ##toexec = "root -b -q drawSingleModule.cxx\(\\\"/tmp/amassiro/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amassiro/ECALAlignment/DATA14Jul2015/SingleElectron/crab_SingleElectron/150715_154047/treeECALAlignment_DATA_oldTrkAlign.root\\\",\\\"2015DataOldTrk\\\",\\\"electrons_classification\=\=0\&\&ETSC\>30\&\&met\>30\\\",-100," + str(x) + ",0\)"
  #toexec = "root -b -q drawSingleModule.cxx\(\\\"/tmp/amassiro/dataOld.root\\\",\\\"2015DataOld\\\",\\\"electrons_classification\=\=0\&\&ETSC\>30\\\",-100," + str(x) + ",0,\\\"/tmp/amassiro/tree_MC.root\\\"\)"
  #print "toexec = ", toexec
  #os.system (toexec)

