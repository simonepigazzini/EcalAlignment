# Auto generated configuration file
# using: 
# Revision: 1.222.2.6 
# Source: /cvs_server/repositories/CMSSW/CMSSW/Configuration/PyReleaseValidation/python/ConfigBuilder.py,v 
# with command line options: step2 -s RAW2DIGI,L1Reco,RECO --data --datatier RECO --eventcontent RECO --conditions GR10_P_V11::All --scenario pp --no_exec --magField AutoFromDBCurrent --process reRECO --customise Configuration/GlobalRuns/reco_TLR_38X.py --cust_function customisePPData --filein=outSkim_1_1_GlC.root
import FWCore.ParameterSet.Config as cms

process = cms.Process('EcalAlignment')

# import of standard configurations
process.load('Configuration.StandardSequences.Services_cff')
process.load('SimGeneral.HepPDTESSource.pythiapdt_cfi')
process.load('FWCore.MessageService.MessageLogger_cfi')
process.load('Configuration.StandardSequences.GeometryDB_cff')
process.load('Configuration.StandardSequences.MagneticField_AutoFromDBCurrent_cff')
process.load('Configuration.StandardSequences.RawToDigi_Data_cff')
process.load('Configuration.StandardSequences.L1Reco_cff')
process.load('Configuration.StandardSequences.Reconstruction_cff')
process.load('Configuration.StandardSequences.EndOfProcess_cff')
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')
process.load('Configuration.EventContent.EventContent_cff')

process.configurationMetadata = cms.untracked.PSet(
    version = cms.untracked.string('$Revision: 1.7 $'),
    annotation = cms.untracked.string('step2 nevts:1'),
    name = cms.untracked.string('PyReleaseValidation')
)
process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(100)
)
process.options = cms.untracked.PSet(

)
# Input source
process.source = cms.Source("PoolSource",
fileNames = cms.untracked.vstring(
        #'file:/data2/amassiro/CMSSWRoot/SingleElectron_Run2011A-WElectron-PromptSkim-v4_RAW-RECO/9220C129-B886-E011-AA20-002481E94B4E.root'
        'file:/data2/amassiro/CMSSWRoot/DATA2012/DoubleElectron_Run2012B-ZElectron-13Jul2012-v1_RAW-RECO/FEE043A5-93D4-E111-84DC-0030486790C0.root'  # it works! mica troppo ...
    )
  )
process.source.inputCommands = cms.untracked.vstring( "drop *_*_*_RECO","drop *_MEtoEDMConverter_*_*", "keep FEDRawDataCollection_*_*_*")

# Output definition


process.RECOoutput = cms.OutputModule("PoolOutputModule",
    splitLevel = cms.untracked.int32(0),
    outputCommands = process.RECOEventContent.outputCommands,
    fileName = cms.untracked.string('outSkim_V3.root'),
    dataset = cms.untracked.PSet(
        filterName = cms.untracked.string(''),
        dataTier = cms.untracked.string('RECO')
    )
)

process.out = cms.OutputModule("PoolOutputModule",
  outputCommands = cms.untracked.vstring(
        #'keep *',
       'drop *'
       #'keep *_gsfElectrons_*_*'
       #'keep *_*_*_EcalAlignmentBIS'
       #'drop *_gsfElectron_*_*',
       #'drop *_gsfElectronCores_*_*'
        ),
  fileName = cms.untracked.string("outCMSSW.root")
)

  
# Additional output definition

# Other statements
#process.GlobalTag.globaltag = 'GR_R_38X_V13::All'
#process.GlobalTag.globaltag = 'GR_P_V20::All'
#process.GlobalTag.globaltag = 'GR_R_42_V18::All'
#process.GlobalTag.globaltag = 'GR_R_44_V1::All'
process.GlobalTag.globaltag = 'GR_P_V42_AN2::All'


# http://cms-conddb.cern.ch/gtlist/?GlobalTag=GR_R_39X_V5
  
process.GlobalTag.toGet = cms.VPSet(
      #cms.PSet(record = cms.string("EcalIntercalibConstantsRcd"),
             #tag = cms.string("EcalIntercalibConstants_Bon_V20100803"),
             #connect = cms.untracked.string("frontier://FrontierProd/CMS_COND_31X_ECAL")
             #),
    #cms.PSet(record = cms.string("EcalADCToGeVConstantRcd"),
             #tag = cms.string("EcalADCToGeVConstant_Bon_V20100803"),
             #connect = cms.untracked.string("frontier://FrontierProd/CMS_COND_31X_ECAL")
             #),
    #cms.PSet(record = cms.string("EBAlignmentRcd"),
             #tag = cms.string("EBAlignment_measured_v05_offline"),
             #connect = cms.untracked.string("sqlite_file:EBAlign_2011.db")   #### New ####
             #),
    #cms.PSet(record = cms.string("EEAlignmentRcd"),
             #tag = cms.string("EEAlignment_measured_v05_offline"),
             #connect = cms.untracked.string("sqlite_file:EEAlign_2011.db")  #### New ####
             #)
   #cms.PSet(record = cms.string("ESAlignmentRcd"),
             #tag = cms.string("ESAlignment_measured_v01_offline"),
             #connect = cms.untracked.string("frontier://FrontierProd/CMS_COND_31X_PRESHOWER")
             #),
    #cms.PSet(record = cms.string("EcalLaserAlphasRcd"),
             #tag = cms.string("EcalLaserAlphas_test_prompt"),
             #connect = cms.untracked.string("frontier://FrontierProd/CMS_COND_31X_ECAL")
             #),
    #cms.PSet(record = cms.string("EcalLaserAPDPNRatiosRcd"),
             #tag = cms.string("EcalLaserAPDPNRatios_v0_online"),
             #connect = cms.untracked.string("frontier://FrontierPrep/CMS_COND_ECAL")
             #),
    #cms.PSet(record = cms.string("GlobalPositionRcd"),
             #tag = cms.string("GlobalAlignment_v2_offline"),
             #connect = cms.untracked.string("frontier://FrontierProd/CMS_COND_31X_ALIGNMENT")
             #),
    cms.PSet(record = cms.string("TrackerAlignmentRcd"),
             tag = cms.string("TrackerAlignment_GR10_v5_offline"),
             connect = cms.untracked.string("frontier://FrontierProd/CMS_COND_31X_ALIGNMENT")
             )
    #cms.PSet(record = cms.string("TrackerAlignmentErrorRcd"),
             #tag = cms.string("TrackerAlignmentErrors_GR10_v2_offline"),
             #connect = cms.untracked.string("frontier://FrontierProd/CMS_COND_31X_ALIGNMENT")
             #)
    )



from CondCore.DBCommon.CondDBSetup_cfi import *
process.trackerBows = cms.ESSource(
   "PoolDBESSource",
   CondDBSetup,
   connect = cms.string('frontier://FrontierProd/CMS_COND_310X_ALIGN'),
   toGet = cms.VPSet(cms.PSet(
           record = cms.string('TrackerSurfaceDeformationRcd'),
           tag = cms.string('TrackerSurfaceDeformations_v1_offline')
           ))
   )
process.es_prefer_Bows = cms.ESPrefer("PoolDBESSource", "trackerBows")




#process.poolDBESSource2 = cms.ESSource("PoolDBESSource",
   #BlobStreamerName = cms.untracked.string('TBufferBlobStreamingService'),
   #DBParameters = cms.PSet(
        #messageLevel = cms.untracked.int32(2),
        #authenticationPath = cms.untracked.string('/path/to/authentication') ),
    #timetype = cms.untracked.string('runnumber'),
    #connect = cms.string('frontier://PromptProd/CMS_COND_31X_STRIP'),
    #toGet = cms.VPSet(cms.PSet(
        #record = cms.string('SiStripConfObjectRcd'),
        #tag = cms.string('SiStripShiftAndCrosstalk_GR10_v2_offline') )))
#process.es_prefer_BP = cms.ESPrefer('PoolDBESSource','poolDBESSource2')

  
#process.poolDBESSource1 = cms.ESSource("PoolDBESSource",
   #BlobStreamerName = cms.untracked.string('TBufferBlobStreamingService'),
   #DBParameters = cms.PSet(
        #messageLevel = cms.untracked.int32(2),
        #authenticationPath = cms.untracked.string('/path/to/authentication') ),
    #timetype = cms.untracked.string('runnumber'),
    #connect = cms.string('frontier://PromptProd/CMS_COND_31X_STRIP'),
    #toGet = cms.VPSet(cms.PSet(
        #record = cms.string('SiStripLorentzAngleRcd'),
        #tag = cms.string('SiStripLorentzAngle_GR10_v2_offline') )))
#process.es_prefer_LA = cms.ESPrefer('PoolDBESSource','poolDBESSource1')
    
    

# Path and EndPath definitions
process.raw2digi_step = cms.Path(process.RawToDigi)
process.L1Reco_step = cms.Path(process.L1Reco)
process.reconstruction_step = cms.Path(process.reconstruction)
process.endjob_step = cms.Path(process.endOfProcess)
#process.RECOoutput_step = cms.EndPath(process.RECOoutput)

# Schedule definition
#process.schedule = cms.Schedule(process.raw2digi_step,process.L1Reco_step,process.reconstruction_step,process.endjob_step,process.RECOoutput_step)

  
    
      
        
          
            

################################################################################
################################################################################
################################################################################
################## create ntuple for ECAL alignment purposes ###################

#--------------------------
# Define PAT sequence
#--------------------------


#--------------------------
# AllPassFilter
#--------------------------


#process.AllEvents                      = cms.EDProducer("EventCountProducer")
process.load("EcalValidation.EcalAlignment.AllPassFilter_cfi")
#--------------------------
# Counter1: All read events
process.AllEvents = process.AllPassFilter.clone()

process.FilterL1FilterEvents           = cms.EDProducer("EventCountProducer")
process.FilterGoodVertexFilterEvents   = cms.EDProducer("EventCountProducer")
process.FilterNoScrapingFilterEvents   = cms.EDProducer("EventCountProducer")
process.FilterElectronFilterEvents     = cms.EDProducer("EventCountProducer")
process.FilterReRECOEvents             = cms.EDProducer("EventCountProducer")
process.FilterPatDefaultSequenceEvents = cms.EDProducer("EventCountProducer")




#--------------------------
# paths
#--------------------------

process.schedule = cms.Schedule(
   process.raw2digi_step,        # | -> reconstruction
   process.L1Reco_step,          # | -> reconstruction
   process.reconstruction_step,  # | -> reconstruction
#AM   process.endjob_step,          # | -> reconstruction
   #process.RECOoutput_step,      # | -> reconstruction
#AM   process.pEcalAlignment        # | -> selections and ntuple
)



################## create ntuple for ECAL alignment purposes ################### 
################################################################################
################################################################################
################################################################################
   
