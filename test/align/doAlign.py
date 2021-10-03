import os
import argparse
parser = argparse.ArgumentParser()
parser.add_argument('-o', '--outputName', dest='outputName', required=True, type=str)
parser.add_argument('-r', '--region', dest='region', required=True, type=str)

args = parser.parse_args()

if (args.region=="EB"):

    for iSM in range(0,36):
        os.system("EB_Alignment_RotoTraslation_singleSM     align/AlignEB_Zee_cfg.py  " +str(iSM))
        os.system("mv myEBAlignment_"+str(iSM)+".txt myEBAlignment_"+str(args.outputName)+"_"+str(iSM)+".txt")

    os.system("cat myEBAlignment_"+str(args.outputName)+"_*.txt >& myEBAlignment_"+str(args.outputName)+"_Combined.txt")

elif (args.region=="EE"):

    for iDee in range(0,4):
        os.system("EE_Alignment_RotoTraslation_singleSM     align/AlignEE_Zee_cfg.py  " +str(iDee))
        os.system("mv myEEAlignment_"+str(iDee)+".txt myEEAlignment_"+str(args.outputName)+"_"+str(iDee)+".txt")

    os.system("cat myEEAlignment_"+str(args.outputName)+"_*.txt >& myEEAlignment_"+str(args.outputName)+"_Combined.txt")

elif (args.region=="All"):

    for iSM in range(0,36):
        os.system("EB_Alignment_RotoTraslation_singleSM     align/AlignEB_Zee_cfg.py  " +str(iSM))
        os.system("mv myEBAlignment_"+str(iSM)+".txt myEBAlignment_"+str(args.outputName)+"_"+str(iSM)+".txt")

    os.system("cat myEBAlignment_"+str(args.outputName)+"_*.txt >& myEBAlignment_"+str(args.outputName)+"_Combined.txt")

    for iDee in range(0,4):
        os.system("EE_Alignment_RotoTraslation_singleSM     align/AlignEE_Zee_cfg.py  " +str(iDee))
        os.system("mv myEEAlignment_"+str(iDee)+".txt myEEAlignment_"+str(args.outputName)+"_"+str(iDee)+".txt")

    os.system("cat myEEAlignment_"+str(args.outputName)+"_*.txt >& myEEAlignment_"+str(args.outputName)+"_Combined.txt")
