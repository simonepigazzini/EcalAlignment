import os
from WMCore.Configuration import Configuration
config = Configuration()

#pyCfgParams = ['inputFiles=FAKEINPUT', 'outputFile=treeECALAlignment.root']
pyCfgParams = ['inputFiles=FAKEINPUT']

config.section_('General')
config.General.transferLogs = True
# config.General.workArea     = 'crab_projects_6July'  # Make sure you set this parameter
config.General.workArea     = 'crab_projects_ECAL_LegacyConditions_WithTracker_Conditions2'  # Make sure you set this parameter

config.section_('JobType')
# config.JobType.psetName = '../Dump_MC_cfg.py'
config.JobType.psetName = '../reco_RAW2DIGI_RECO2019_TrackerConditions_Conditions2.py'
config.JobType.pluginName = 'Analysis'
config.JobType.outputFiles = ['treeECALAlignment.root']
config.JobType.maxJobRuntimeMin = 2700
config.JobType.allowUndistributedCMSSW = True


config.section_('Data')
config.Data.inputDBS      = 'global'
config.Data.splitting     = 'FileBased'
config.Data.unitsPerJob   = 10   # since files based, 10 files per job
config.Data.outLFNDirBase = '/store/group/dpg_ecal/alca_ecalcalib/twamorka/UltraLegacy_WithTrackerConditions_Conditions2'


config.section_('Site')
config.Site.storageSite = 'T2_CH_CERN'


from multiprocessing import Process

import sys

if __name__ == '__main__':

    from CRABAPI.RawCommand import crabCommand

    def submit(config):
        print " to do: ",config
        res = crabCommand('submit', config = config)

    ######### From now on this is what users should modify. It is the a-la-CRAB2 configuration part.


    print sys.argv
    if len(sys.argv) <= 1 :
       print "no arguments?"
       print "Usage to submit:     python multicrab.py samples_file.py"
       print "Usage to get status: python multicrab.py folder (status)"
       print "Usage to resubmit:   python multicrab.py folder resubmit"
       exit()


    samples = {}
    SamplesFile = sys.argv[1]
    print " SamplesFile = ", SamplesFile

    additionalConfiguration = ''
    if len(sys.argv) == 4 :
      additionalConfiguration = sys.argv[3]
    print " additionalConfiguration = ", additionalConfiguration

    # submit
    if os.path.exists(SamplesFile) and not os.path.isdir(SamplesFile) :
       handle = open(SamplesFile,'r')
       exec(handle)
       handle.close()

       # samples to be analysed

       for key, value in samples.iteritems():
           print key, ' -> ', value

           config.General.requestName = key
           config.Data.inputDataset = value[0]
           config.JobType.pyCfgParams = list(pyCfgParams)
           config.JobType.pyCfgParams.extend(value[1])

           p = Process(target=submit, args=(config,))
           p.start()
           p.join()
           #submit(config)
           # see https://twiki.cern.ch/twiki/bin/view/CMSPublic/CRAB3FAQ#Multiple_submission_fails_with_a

    # status and resubmit
    else :
       if len(sys.argv) >= 3 :
          if sys.argv[2] == 'report' :
           os.system("ls " + SamplesFile + " | awk '{print \" crab report "   + SamplesFile + "/\"$1" + "\" " + additionalConfiguration + "\"}' | /bin/sh")
          if sys.argv[2] == 'status' :
           os.system("ls " + SamplesFile + " | awk '{print \" crab status "   + SamplesFile + "/\"$1" + "\" " + additionalConfiguration + "\"}' | /bin/sh")
          if sys.argv[2] == 'resubmit' :
           os.system("ls " + SamplesFile + " | awk '{print \" crab resubmit " + SamplesFile + "/\"$1" + "\" " + additionalConfiguration + "\"}' | /bin/sh")
          if sys.argv[2] == 'dry' :
           os.system("ls " + SamplesFile + " | awk '{print \" crab " + additionalConfiguration + " "   + SamplesFile + "/\"$1" + "\" " + "\"}' ")
       else :
          os.system("ls " + SamplesFile + " | awk '{print \" crab status " + SamplesFile + "/\"$1}' | /bin/sh")
