# Auto generated configuration file
# using:
# Revision: 1.19
# Source: /local/reps/CMSSW/CMSSW/Configuration/Applications/python/ConfigBuilder.py,v
# with command line options: step1 --filein dbs:/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/RunIIAutumn18DR-2016GT_102X_mc2017_realistic_UL_v1-v1/AODSIM --fileout file:EGM-RunIIWinter19PFCalibMiniAOD-00005.root --mc --eventcontent MINIAODSIM --runUnscheduled --datatier MINIAODSIM --conditions 106X_mc2017_realistic_v3 --step PAT --nThreads 8 --geometry DB:Extended --era Run2_2017
import FWCore.ParameterSet.Config as cms

process = cms.Process('EcalAlignment')

# manage input variables
from FWCore.ParameterSet.VarParsing import VarParsing
options = VarParsing ('analysis')
# add a list of strings for events to process
options.parseArguments()


from Configuration.StandardSequences.Eras import eras

process = cms.Process('PAT',eras.Run2_2017)

# import of standard configurations
process.load('Configuration.StandardSequences.Services_cff')
process.load('SimGeneral.HepPDTESSource.pythiapdt_cfi')
process.load('FWCore.MessageService.MessageLogger_cfi')
process.load('Configuration.EventContent.EventContent_cff')
process.load('SimGeneral.MixingModule.mixNoPU_cfi')
process.load('Configuration.StandardSequences.GeometryRecoDB_cff')
process.load('Configuration.StandardSequences.MagneticField_cff')
process.load('PhysicsTools.PatAlgos.slimming.metFilterPaths_cff')
process.load('Configuration.StandardSequences.PATMC_cff')
process.load('Configuration.StandardSequences.EndOfProcess_cff')
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')

process.configurationMetadata = cms.untracked.PSet(
    version = cms.untracked.string('$Revision: 1.1 $'),
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
    fileNames = cms.untracked.vstring (options.inputFiles),
    #fileNames = cms.untracked.vstring('file:/tmp/amassiro/2EB0D0B7-C275-E111-8CFB-001A64789E04.root')
  )


# # Input source
# process.source = cms.Source("PoolSource",
#     fileNames = cms.untracked.vstring(
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/70000/C1C4A4CE-0E1B-7944-A5DD-DB9903661F67.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/70000/D1123547-A0BC-8242-9740-029AA8ECD2B8.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/70000/071E4282-D98C-6A4E-8582-F577BD9056D2.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/70000/44BCC5F5-09CA-C84C-AF0C-783DBCD9B228.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/70000/B7B76CF6-17A3-054D-BF6D-86EE6A04F406.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/70000/F73724D7-02C4-8448-B8C5-30064BAE6784.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/70000/351B4D79-AF84-6A42-8F5A-959CD153734F.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/70000/E62C8D0E-2D32-6042-B8ED-DEAA3BF64918.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/110000/520D1155-F403-BE45-88AE-51708720F8EF.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/110000/8BD75B2A-5B47-F94C-9595-E2DE07B93587.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/110000/ED97D9B8-D43E-2144-9A38-936EC0D0CB1A.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/110000/C6C01729-0449-4B4C-98F6-95F12699D5A7.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/110000/500242FD-A210-2E4B-BBFC-38FF43A009EE.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/110000/28AB26F3-46F3-EF41-A848-215389AEDDDD.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/110000/B3811EAD-0086-9B45-94E0-5651E31FAFB2.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/110000/B31AC289-6D6A-B043-B717-90D485A41B2C.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/110000/F4616579-6F11-2447-8B9F-B3D6CD6C4B50.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/110000/25E68213-6B11-7443-9568-F3EE13111EC1.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/110000/315AFBEB-EA3D-ED4E-BEA2-FAE39C18726D.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/110000/447D2253-3C87-D942-8C89-AA2DFB48CDB7.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/110000/3CF80F80-7649-D341-8310-36BBFCD7310D.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/110000/454B5168-D90D-D84F-AE3B-16B8DBB948D9.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/110000/6A39FE52-8A33-3D40-A2FF-CA2539BF84CB.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/110000/0DDB65C3-21D9-C84F-B480-D3079AA94FE4.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/110000/6206F24A-8A68-FB4B-873C-8F34309A7066.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/110000/B89F196D-5052-C34D-829E-678234D8E0C8.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/110000/10678C8C-C53E-0F44-ADDF-4C083CEBFB0F.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/110000/31420B53-2C41-964C-A9FB-ED2243075F99.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/110000/5E313D1A-68D1-E443-B035-B4E7E945FB93.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/110000/3E9C1FA4-0C22-D141-B346-BD3480D7B966.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/110000/28C1F242-2AC4-1540-85BD-EA1264AB3345.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/110000/6D7E0FA2-1691-1C4F-95AD-F785062B7789.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/110000/A7A8C688-C14A-F54C-9E0E-7E7FC1E86F1B.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/110000/DCD1C963-7932-5A4E-A121-59305CFF576A.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/110000/681AA656-BC05-0F48-AF4E-DF38986F40FC.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/110000/AE14BA4C-9516-1D45-A899-3EC0A50BD1A2.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/110000/CB4098AC-C8D2-D74C-94E4-C88FE038FB4D.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/110000/6EC4F8B1-D104-F04D-9D97-6862BF8B6668.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/110000/9F40176B-6FEA-634F-8882-1FFF6BDEFE1D.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/110000/9A4C4082-3132-934F-8C6C-2AECA501E817.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/110000/D73B4324-1DE6-A147-8176-208B274A39DA.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/110000/5706964B-BFF5-CD4F-908F-E7C72412AF61.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/110000/9E1491F1-CFAA-CA4E-B4FF-8DD37705DBCC.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/110000/F7F1A2B8-D102-D74E-A144-191EB3743C9A.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/110000/8DD3E3B2-3C67-0F44-B180-550F4AB7E7CC.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/110000/08E5DFBC-FFA6-FC43-B72B-48D38220B05E.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/110000/43E7A434-5FD0-CE46-BE21-97687061958D.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/70000/1C7EF8EE-EF18-B246-AAA6-698DA80A2F2E.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/70000/75F8208A-1B06-0A48-9262-806149717418.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/70000/5478CD9C-9871-A943-87D9-2BE3908BD338.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/70000/285B65AC-D756-ED43-8006-1FEE137E5204.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/70000/2D090FE7-014A-0C46-852E-BD4A636BF032.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/70000/30365C97-F4BB-5940-AE79-1E883EB87E5D.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/70000/A2A4FFBA-F630-5A40-9524-EDB2188F5003.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/70000/90B8ABCA-3086-7F44-9121-6B20948264A5.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/70000/DFFA951A-1C1F-824C-82C2-D177CE1D85F6.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/70000/80B04DC7-35A5-EC42-A37D-492526E602BC.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/70000/2159027B-30B1-1241-817C-99F5143D8F41.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/70000/2F2B878E-3E9B-8042-A7EC-15DF67B6D034.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/70000/F461FD12-D21D-6C4A-B49D-966D8340B712.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/70000/7269A063-29F4-6143-A9F8-99CE5E344404.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/70000/AA4ABE65-DC05-784F-A942-D12C5273A1B8.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/70000/76FCC976-270F-F043-91A7-DDAD910635DE.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/70000/CE6F5F10-31A6-AB45-994E-BDD282E46DFD.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/70000/EA63EA27-E882-5D41-AB88-A9DFFDF320EC.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/70000/11346ABE-C793-AD40-813F-22192460CF0A.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/70000/A1B2DEFA-69B9-EA4B-8DAC-5EB59056B41C.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/70000/AAD225EE-E569-7C4D-B90C-4A2CBF575489.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/70000/BF1C5E21-A52C-814D-B641-91016D9C919F.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/70000/12579267-4968-A54D-AAB6-5EE65A6EEF83.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/70000/FE1CD504-9945-3148-A2D3-246E725ACE33.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/70000/1334E641-BF69-0E4F-8BE8-7BFC7CB74D76.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/270000/194C7A66-14E4-6143-92D9-3537FD3833FC.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/270000/EE800ACD-F150-0648-B2E1-612D59D562A9.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/270000/1B2ADBD9-194D-6449-8F32-5E11CD08FDA2.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/270000/0A755B8D-994B-594C-A633-A43ED35A3E7C.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/270000/3F75D769-CDB3-1841-92A1-F97E28DD04A7.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/270000/3A33CC0D-799F-3145-B972-9954B0E9CD87.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/270000/54650A21-E7A0-144A-8F50-D46A074574AC.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/270000/F2A4C3F0-740A-7546-B17E-1EF9D93236BD.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/270000/F24E3927-C8EB-E84D-8A4C-E406E7018E38.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/270000/EAF079D8-14B8-A04E-BCA8-0539FB90BBE7.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/270000/FC1D59AF-089A-0D41-94F2-2D0FC1020A94.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/270000/CEF450A2-E827-F245-9E58-2248F7274BF3.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/270000/88DA3B10-298A-6244-8952-5C0EED4F1695.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/270000/FB8A2BCF-40B1-4E42-9947-460BDBBFB0FC.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/270000/F80D549D-943B-1A49-8720-39B6840ECCB8.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/270000/DDEB9F62-EEBF-D141-8662-7AE8129E260A.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/270000/16F79ECB-241E-0B48-BE92-73E25EE2A9B6.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/270000/152D65F0-A031-134A-B97E-4E0D8D5D3335.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/270000/051AB600-765C-0249-815B-CD2C48C4DC55.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/270000/FAFBA216-D7D8-424D-87D6-18FCBEA84429.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/270000/23609533-F1DF-1B4A-9865-C2E9E5B76E4E.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/270000/AA1A18FF-9EAB-FC47-9C58-8BBF4E2ACEF6.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/270000/D68C197B-6ECC-A04F-874D-B0955583355E.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/270000/226D75E3-8C82-D64C-A387-BCFE13FC113D.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/270000/5A2220DF-FE01-3B46-AFFA-BD6DF7940986.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/270000/8F635912-827E-E54C-9831-CC7A6FF79484.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/270000/926E80BF-4567-CF4F-A158-2ED713131E0C.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/120000/8E58208D-DDE2-734A-9717-9D2890ADDE67.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/70000/45083D96-BC77-4C4F-AFB7-70AAD84433B7.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/70000/4961E7CB-74CB-6344-A79A-D25CBD1249F8.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/70000/1539E521-2161-7648-92A7-C4A9753CB41C.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/70000/4C1FCEF4-A54D-7648-B146-AE05F9D27CFD.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/70000/1CED1704-3126-6040-AE8E-2D47F97EB83E.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/70000/D414B1AF-3925-214A-B0E8-AB22AAD82466.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/70000/BD305B09-C4DF-8F4D-8B83-4ED46B97697B.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/70000/B78D9E57-4FCD-1A4E-98BE-B782850A0197.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/70000/F80D9341-6777-1042-9B23-76D28F94452A.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/70000/CDC54EC9-ACDD-1A40-997B-697F4294041B.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/70000/89259F8E-47F3-C64A-AD37-84D2473F12A7.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/70000/8C7A10AA-6026-7D4D-801D-42430E650E52.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/70000/1BE0E681-BE55-5F43-947A-CFE487C0BC9A.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/70000/D219BACE-6E6B-5040-89CA-E714C64D81B1.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/70000/3E2C09B4-36CB-EC44-9FBB-3C45E5F2842F.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/70000/A4FF111C-238F-2647-95E2-F994272DE1C8.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/70000/60D3C2F5-54C8-8646-8242-DC8A9ABC7DE5.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/70000/AF0095F8-0B0F-2049-B4F0-1B6056FA13C3.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/70000/BDAC5CAD-CBD1-EF4F-BB9D-0592A333CE2F.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/70000/DBAE5872-7658-D945-94FA-6A1AE72AA810.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/70000/A48F036D-E16C-2444-8AEC-91ABB2BA1D67.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/70000/2AE1E7C8-56A2-4749-8B71-809600C76B46.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/70000/3EDEA750-DEBD-8B4F-9E3F-0134D145BC40.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/70000/3B81C5BE-264F-7F46-906D-1B989D5C5CF5.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/70000/4BF690E3-6F05-A042-8BE9-486443069914.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/70000/9201A72A-A4A7-6A40-894B-C5006FBE548C.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/70000/176BD870-3024-8B46-A810-E403B92BEE2A.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/70000/9ECF47C4-0928-714E-9ED2-622E728AE72A.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/70000/AF5781DA-2087-D743-8E2C-F8CBD10F02A1.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/70000/FDE0590B-6DB6-A44F-89A0-421DBD61C61B.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/70000/86AC0A6B-EE20-1740-BA5C-721199C9BDAA.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/70000/E893E3C4-6AAA-B54E-87A1-712C244AEC95.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/70000/32DC7C8E-5540-C441-AD4D-3254A46FA1C2.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/70000/6E826339-2882-7F48-8B21-700E3DC48D49.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/70000/80369CBC-F1D4-494F-A32E-43A7186E6DA5.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/110000/92747422-628D-3D4C-A083-95FBE5BBF6B1.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/110000/41411D71-934F-AD4D-8CF3-1809DAAB8A15.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/110000/D2C60BE4-517B-1A4F-9571-638F77E34C0A.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/110000/BF97218A-9D0B-834D-895A-6E4CA26427EE.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/110000/59282153-7CBF-C343-A7DE-1CFD2D471605.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/110000/DB28564A-FE52-2049-80CB-8F5804EC475B.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/110000/6A9CB6E1-1F20-ED49-B96F-79F9553AA46D.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/110000/BC2A3999-8182-3A4B-A685-7EFDC0CDC136.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/110000/BD7F2A18-20D2-4748-840D-C8A8B9CD3EE5.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/110000/CF9E1BF8-A9C5-2B48-9933-E2FE9E6443DE.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/110000/CF251A47-F9B5-6E4F-9D72-11C143A30F2C.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/110000/C5E22A2B-E410-A449-8924-818DA6DEF12D.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/110000/CB7A2BBB-DF38-CD47-917E-CFD3955918D0.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/110000/8FB9B782-E25E-3049-9F3E-354B1287A52E.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/110000/ED2787CF-0EF2-4B47-A0AA-57D3A3471402.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/110000/E2904A10-3E56-BA47-B38E-35129F07F791.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/110000/EA635A60-5692-674E-84B4-1DD0FA2158EA.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/110000/148CFBE0-E76B-9A4D-9D2D-713424B6642A.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/110000/4ACE500A-5F7A-C045-9776-E761E6305F52.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/110000/7A6029BA-EC03-6347-B47C-B7F71D970625.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/110000/C1083E66-7004-DF48-BAFF-E551C91140F1.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/110000/E621CC2F-8E82-BE4F-81ED-B7FAD80CACB7.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/110000/61E19C93-FE77-B64E-906A-2E1F7E9FB9A0.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/110000/84211E37-9C62-374E-A7BC-35002EFF30E5.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/110000/DE65CD75-A101-454F-B272-9AB3A687D20E.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/110000/6DE031B0-4096-174C-8C1B-CD33C4F337CA.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/110000/63C1B6BF-730B-F247-A091-7929FE852968.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/110000/7F6D37DB-DD28-B64E-B0C0-49BB7FD43C4B.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/110000/E26C5480-A53A-2D45-BC57-4063143E5512.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/110000/1EFA2B19-C4BD-BB48-B715-6C5DD73B09F4.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/110000/F931A311-60E2-9244-AFCF-1764FAC07C8F.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/110000/0B155E2C-39A1-E54E-8B51-AEEF33346F08.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/110000/DCEC1DEE-5C7F-684D-83DC-711476D87BBA.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/110000/C1D83443-3973-AE4A-A334-5E80C9076D94.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/110000/4BA97E76-1434-1743-8095-B1E1D024114B.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/110000/E22E276E-3194-C644-9092-C2C62E2043D2.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/110000/CC225E19-931A-D04A-B647-2C38260B513F.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/110000/5D9CA7C6-8210-734A-84E9-C24C310B5343.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/110000/1D6FA463-14D8-0C45-B3E0-CA164F58FACC.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/70000/822B1600-D263-1F43-8DFB-0B1EABA37990.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/70000/B5388B2B-6D13-0B4E-ADF0-63EE36FB94E1.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/70000/34E83054-D726-AD42-A47B-5325496918E1.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/70000/ECE9F106-F502-484D-8F50-64DCE2196D03.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/70000/561DBD62-95E3-FC4E-8EF1-7F83A789EEE6.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/70000/0BB67917-E8D7-BC47-A517-D4D381F54497.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/70000/D7AF7B9E-7A20-9445-94B9-C71186882F66.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/70000/6B4D0DF6-09E1-6946-879F-D654070406B4.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/70000/0681EF09-FB1A-064F-8335-8DC2AEADAF8B.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/70000/2A6ADCD7-A7CF-AB41-BA3A-ABA5D54AB1E0.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/70000/61BCC4AA-BC5A-0140-9F85-DD6DDA9029EA.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/70000/83D27FC2-81B1-1D44-B34A-BE8832BF49BF.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/70000/C6691948-E80F-A04E-B2F7-FCEEEB8A542F.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/70000/91DD494A-BE03-EB48-BBA7-B1B1787E2D1C.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/70000/D752E653-B868-EF4B-93F1-994D79489AE8.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/70000/AA328934-7E90-0F47-9777-E61DF14E0416.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/70000/816B064F-03CD-0949-82C1-D19D01FEF0D2.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/70000/51B947BE-1636-CB46-A6B0-2DFD7800867F.root',
#         '/store/mc/RunIIAutumn18DR/DYJetsToEE_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/AODSIM/2016GT_102X_mc2017_realistic_UL_v1-v1/70000/E9A61392-BAF1-1E41-A827-FAF11030FF7F.root'
#     ),
#     secondaryFileNames = cms.untracked.vstring()
# )

process.options = cms.untracked.PSet(

)

# Production Info
process.configurationMetadata = cms.untracked.PSet(
    annotation = cms.untracked.string('step1 nevts:1'),
    name = cms.untracked.string('Applications'),
    version = cms.untracked.string('$Revision: 1.19 $')
)

# Output definition

process.MINIAODSIMoutput = cms.OutputModule("PoolOutputModule",
    compressionAlgorithm = cms.untracked.string('LZMA'),
    compressionLevel = cms.untracked.int32(4),
    dataset = cms.untracked.PSet(
        dataTier = cms.untracked.string('MINIAODSIM'),
        filterName = cms.untracked.string('')
    ),
    dropMetaData = cms.untracked.string('ALL'),
    eventAutoFlushCompressedSize = cms.untracked.int32(-900),
    fastCloning = cms.untracked.bool(False),
    fileName = cms.untracked.string('file:EGM-RunIIWinter19PFCalibMiniAOD-00005.root'),
    outputCommands = process.MINIAODSIMEventContent.outputCommands,
    overrideBranchesSplitLevel = cms.untracked.VPSet(
        cms.untracked.PSet(
            branch = cms.untracked.string('patPackedCandidates_packedPFCandidates__*'),
            splitLevel = cms.untracked.int32(99)
        ),
        cms.untracked.PSet(
            branch = cms.untracked.string('recoGenParticles_prunedGenParticles__*'),
            splitLevel = cms.untracked.int32(99)
        ),
        cms.untracked.PSet(
            branch = cms.untracked.string('patTriggerObjectStandAlones_slimmedPatTrigger__*'),
            splitLevel = cms.untracked.int32(99)
        ),
        cms.untracked.PSet(
            branch = cms.untracked.string('patPackedGenParticles_packedGenParticles__*'),
            splitLevel = cms.untracked.int32(99)
        ),
        cms.untracked.PSet(
            branch = cms.untracked.string('patJets_slimmedJets__*'),
            splitLevel = cms.untracked.int32(99)
        ),
        cms.untracked.PSet(
            branch = cms.untracked.string('recoVertexs_offlineSlimmedPrimaryVertices__*'),
            splitLevel = cms.untracked.int32(99)
        ),
        cms.untracked.PSet(
            branch = cms.untracked.string('recoCaloClusters_reducedEgamma_reducedESClusters_*'),
            splitLevel = cms.untracked.int32(99)
        ),
        cms.untracked.PSet(
            branch = cms.untracked.string('EcalRecHitsSorted_reducedEgamma_reducedEBRecHits_*'),
            splitLevel = cms.untracked.int32(99)
        ),
        cms.untracked.PSet(
            branch = cms.untracked.string('EcalRecHitsSorted_reducedEgamma_reducedEERecHits_*'),
            splitLevel = cms.untracked.int32(99)
        ),
        cms.untracked.PSet(
            branch = cms.untracked.string('recoGenJets_slimmedGenJets__*'),
            splitLevel = cms.untracked.int32(99)
        ),
        cms.untracked.PSet(
            branch = cms.untracked.string('patJets_slimmedJetsPuppi__*'),
            splitLevel = cms.untracked.int32(99)
        ),
        cms.untracked.PSet(
            branch = cms.untracked.string('EcalRecHitsSorted_reducedEgamma_reducedESRecHits_*'),
            splitLevel = cms.untracked.int32(99)
        )
    ),
    overrideInputFileSplitLevels = cms.untracked.bool(True),
    splitLevel = cms.untracked.int32(0)
)

# Additional output definition

# Other statements
from Configuration.AlCa.GlobalTag import GlobalTag
process.GlobalTag = GlobalTag(process.GlobalTag, '106X_mc2017_realistic_v3', '')


process.AllEvents                      = cms.EDProducer("EventCountProducer")
process.FilterL1FilterEvents           = cms.EDProducer("EventCountProducer")
process.FilterGoodVertexFilterEvents   = cms.EDProducer("EventCountProducer")
process.FilterNoScrapingFilterEvents   = cms.EDProducer("EventCountProducer")
process.FilterElectronFilterEvents     = cms.EDProducer("EventCountProducer")
process.FilterReRECOEvents             = cms.EDProducer("EventCountProducer")
process.FilterPatDefaultSequenceEvents = cms.EDProducer("EventCountProducer")

process.ntupleEcalAlignment = cms.EDAnalyzer(
    'EcalAlignment',
    recHitCollection_EB = cms.InputTag("reducedEgamma","reducedEBRecHits"),    #   "reducedEcalRecHitsEB"),
    recHitCollection_EE = cms.InputTag("reducedEgamma","reducedEERecHits"),     #   "reducedEcalRecHitsEE"),
#    recHitCollection_EB = cms.InputTag("ecalRecHit","EcalRecHitsEB"),
#    recHitCollection_EE = cms.InputTag("ecalRecHit","EcalRecHitsEE"),
    EleTag              = cms.InputTag("slimmedElectrons"),  # "patElectrons"
    TrackTag            = cms.InputTag("generalTracks"),
    CALOMetTag          = cms.InputTag("slimmedMETs"),      # "patMETs"
    vtxTag              = cms.InputTag("goodPrimaryVertices"),
    isMC                = cms.untracked.bool(True),
    genEvtInfoTag       = cms.untracked.InputTag("generator"),
    puLabel             = cms.untracked.InputTag("slimmedAddPileupInfo"),
    )

process.TFileService = cms.Service(
    "TFileService",
    #fileName = cms.string("EcalAlignment.root")
    fileName = cms.string(options.outputFile)
    )


#--------------------------
# filters
#--------------------------

# filter on PhysDeclared bit
process.skimming = cms.EDFilter(
    "PhysDecl",
    applyfilter = cms.untracked.bool(True),
    debugOn = cms.untracked.bool(False),
    HLTriggerResults = cms.InputTag("TriggerResults","","HLT")
    )

# filter on bit = and (40 || 41) and !(bit36 || bit37 || bit38 || bit39)
process.load('L1TriggerConfig.L1GtConfigProducers.L1GtTriggerMaskTechTrigConfig_cff')
process.load('HLTrigger/HLTfilters/hltLevel1GTSeed_cfi')
process.hltLevel1GTSeed.L1TechTriggerSeeding = cms.bool(True)
process.hltLevel1GTSeed.L1SeedsLogicalExpression = cms.string('0 AND (40 OR 41) AND NOT (36 OR 37 OR 38 OR 39)')

VERTEX_SEL=("!isFake && ndof > 4 && abs(z) <= 24 && position.Rho <= 2")

process.goodPrimaryVertices = cms.EDFilter("VertexSelector",
  src = cms.InputTag("offlineSlimmedPrimaryVertices"),     # "offlinePrimaryVertices"
  cut = cms.string(VERTEX_SEL),
  filter = cms.bool(True),
)

# filter on primary vertex
process.primaryVertexFilter = cms.EDFilter(
    "GoodVertexFilter",
    vertexCollection = cms.InputTag("offlineSlimmedPrimaryVertices"),     # "offlinePrimaryVertices"
    minimumNDOF = cms.uint32(4) ,
    maxAbsZ = cms.double(24),
    maxd0 = cms.double(2)
    )

# FilterOutScraping
process.noscraping = cms.EDFilter(
    "FilterOutScraping",
    applyfilter = cms.untracked.bool(True),
    debugOn = cms.untracked.bool(False),
    numtrack = cms.untracked.uint32(10),
    thresh = cms.untracked.double(0.25)
    )

# select events with at least one gsf electron
process.highetele = cms.EDFilter(
    "PATElectronSelector",   #"GsfElectronSelector",
    src = cms.InputTag("slimmedElectrons"),  # "gedGsfElectrons"
    cut = cms.string("superCluster().get().energy()*sin(theta())> 0 ")
    )

process.highetFilter = cms.EDFilter(
    "CandViewCountFilter",
    src = cms.InputTag("highetele"),
    minNumber = cms.uint32(1)
    )

#--------------------------
# paths
#--------------------------

process.pEcalAlignment = cms.Path(
    process.AllEvents   # |-> counter
#*process.skimming
#*process.FilterL1FilterEvents   # |-> counter
#*process.hltLevel1GTSeed
#*process.FilterGoodVertexFilterEvents   # |-> counter
#*process.primaryVertexFilter
    *process.goodPrimaryVertices
#*process.FilterNoScrapingFilterEvents   # |-> counter
#*process.noscraping
#*process.FilterElectronFilterEvents   # |-> counter
#*process.tagGsfSeq
    *process.highetele
    *process.highetFilter
    *process.FilterReRECOEvents   # |-> counter
    #*process.patDefaultSequence
    *process.FilterPatDefaultSequenceEvents   # |-> counter
    *process.ntupleEcalAlignment
    )

# Path and EndPath definitions
process.Flag_trackingFailureFilter = cms.Path(process.goodVertices+process.trackingFailureFilter)
process.Flag_goodVertices = cms.Path(process.primaryVertexFilter)
process.Flag_CSCTightHaloFilter = cms.Path(process.CSCTightHaloFilter)
process.Flag_trkPOGFilters = cms.Path(process.trkPOGFilters)
process.Flag_HcalStripHaloFilter = cms.Path(process.HcalStripHaloFilter)
process.Flag_trkPOG_logErrorTooManyClusters = cms.Path(~process.logErrorTooManyClusters)
process.Flag_EcalDeadCellTriggerPrimitiveFilter = cms.Path(process.EcalDeadCellTriggerPrimitiveFilter)
process.Flag_ecalLaserCorrFilter = cms.Path(process.ecalLaserCorrFilter)
process.Flag_globalSuperTightHalo2016Filter = cms.Path(process.globalSuperTightHalo2016Filter)
process.Flag_eeBadScFilter = cms.Path(process.eeBadScFilter)
process.Flag_METFilters = cms.Path(process.metFilters)
process.Flag_chargedHadronTrackResolutionFilter = cms.Path(process.chargedHadronTrackResolutionFilter)
process.Flag_globalTightHalo2016Filter = cms.Path(process.globalTightHalo2016Filter)
process.Flag_CSCTightHaloTrkMuUnvetoFilter = cms.Path(process.CSCTightHaloTrkMuUnvetoFilter)
process.Flag_HBHENoiseIsoFilter = cms.Path(process.HBHENoiseFilterResultProducer+process.HBHENoiseIsoFilter)
process.Flag_BadChargedCandidateSummer16Filter = cms.Path(process.BadChargedCandidateSummer16Filter)
process.Flag_hcalLaserEventFilter = cms.Path(process.hcalLaserEventFilter)
process.Flag_BadPFMuonFilter = cms.Path(process.BadPFMuonFilter)
process.Flag_ecalBadCalibFilter = cms.Path(process.ecalBadCalibFilter)
process.Flag_HBHENoiseFilter = cms.Path(process.HBHENoiseFilterResultProducer+process.HBHENoiseFilter)
process.Flag_trkPOG_toomanystripclus53X = cms.Path(~process.toomanystripclus53X)
process.Flag_EcalDeadCellBoundaryEnergyFilter = cms.Path(process.EcalDeadCellBoundaryEnergyFilter)
process.Flag_BadChargedCandidateFilter = cms.Path(process.BadChargedCandidateFilter)
process.Flag_trkPOG_manystripclus53X = cms.Path(~process.manystripclus53X)
process.Flag_BadPFMuonSummer16Filter = cms.Path(process.BadPFMuonSummer16Filter)
process.Flag_muonBadTrackFilter = cms.Path(process.muonBadTrackFilter)
process.Flag_CSCTightHalo2015Filter = cms.Path(process.CSCTightHalo2015Filter)
process.endjob_step = cms.EndPath(process.endOfProcess)
process.MINIAODSIMoutput_step = cms.EndPath(process.MINIAODSIMoutput)

# Schedule definition
process.schedule = cms.Schedule(process.Flag_HBHENoiseFilter,process.Flag_HBHENoiseIsoFilter,process.Flag_CSCTightHaloFilter,process.Flag_CSCTightHaloTrkMuUnvetoFilter,process.Flag_CSCTightHalo2015Filter,process.Flag_globalTightHalo2016Filter,process.Flag_globalSuperTightHalo2016Filter,process.Flag_HcalStripHaloFilter,process.Flag_hcalLaserEventFilter,process.Flag_EcalDeadCellTriggerPrimitiveFilter,process.Flag_EcalDeadCellBoundaryEnergyFilter,process.Flag_ecalBadCalibFilter,process.Flag_goodVertices,process.Flag_eeBadScFilter,process.Flag_ecalLaserCorrFilter,process.Flag_trkPOGFilters,process.Flag_chargedHadronTrackResolutionFilter,process.Flag_muonBadTrackFilter,process.Flag_BadChargedCandidateFilter,process.Flag_BadPFMuonFilter,process.Flag_BadChargedCandidateSummer16Filter,process.Flag_BadPFMuonSummer16Filter,process.Flag_trkPOG_manystripclus53X,process.Flag_trkPOG_toomanystripclus53X,process.Flag_trkPOG_logErrorTooManyClusters,process.Flag_METFilters,process.endjob_step,process.MINIAODSIMoutput_step,process.pEcalAlignment)

process.schedule.associate(process.patTask)
from PhysicsTools.PatAlgos.tools.helpers import associatePatAlgosToolsTask
associatePatAlgosToolsTask(process)

#Setup FWK for multithreaded
process.options.numberOfThreads=cms.untracked.uint32(8)
process.options.numberOfStreams=cms.untracked.uint32(0)
process.options.numberOfConcurrentLuminosityBlocks=cms.untracked.uint32(1)

#do not add changes to your config after this point (unless you know what you are doing)
from FWCore.ParameterSet.Utilities import convertToUnscheduled
process=convertToUnscheduled(process)

# customisation of the process.

# Automatic addition of the customisation function from PhysicsTools.PatAlgos.slimming.miniAOD_tools
from PhysicsTools.PatAlgos.slimming.miniAOD_tools import miniAOD_customizeAllMC

#call to customisation function miniAOD_customizeAllMC imported from PhysicsTools.PatAlgos.slimming.miniAOD_tools
process = miniAOD_customizeAllMC(process)

# End of customisation functions

# Customisation from command line

# Add early deletion of temporary data products to reduce peak memory need
from Configuration.StandardSequences.earlyDeleteSettings_cff import customiseEarlyDelete
process = customiseEarlyDelete(process)
# End adding early deletion
