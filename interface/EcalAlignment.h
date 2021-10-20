// -*- C++ -*-
//
// Package:    EcalAlignment
// Class:      EcalAlignment
// 
/**\class EcalAlignment EcalAlignment.h EcalValidation/EcalAlignment/interface/EcalAlignment.h

 Description: [one line class summary]

 Implementation:
     [Notes on implementation]
 */
//
// Original Author:  Andrea Massironi
//         Created:  Mon Oct 25 09:35:13 CEST 2010
// $Id: EcalAlignment.h,v 1.8 2012/11/05 13:03:50 amassiro Exp $
//
//

#ifndef EcalAlignment_h
#define EcalAlignment_h

// system include files
#include <memory>

#include <fstream> 

#include "SimDataFormats/PileupSummaryInfo/interface/PileupSummaryInfo.h" 
#include "RecoEcal/EgammaCoreTools/interface/EcalTools.h"

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/Framework/interface/ESHandle.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"

#include "TH1.h"
#include "TTree.h"
#include "TMath.h"

#include "FWCore/ServiceRegistry/interface/Service.h"
#include "CommonTools/UtilAlgos/interface/TFileService.h"

#include "DataFormats/PatCandidates/interface/MET.h"
#include "DataFormats/PatCandidates/interface/Electron.h"


#include "Geometry/EcalAlgo/interface/EcalBarrelGeometry.h"
#include "Geometry/EcalAlgo/interface/EcalEndcapGeometry.h"

#include "Geometry/CaloTopology/interface/CaloTopology.h"
#include "Geometry/Records/interface/CaloTopologyRecord.h"
#include "CondFormats/DataRecord/interface/EcalChannelStatusRcd.h"
#include "CondFormats/EcalObjects/interface/EcalChannelStatus.h"
#include "DataFormats/EcalRecHit/interface/EcalRecHitCollections.h"

#include "RecoEcal/EgammaCoreTools/interface/EcalClusterTools.h"
#include "RecoLocalCalo/EcalRecAlgos/interface/EcalSeverityLevelAlgo.h"

#include "DataFormats/Math/interface/LorentzVector.h"
#include "DataFormats/Math/interface/deltaPhi.h"

#include "DataFormats/VertexReco/interface/Vertex.h"
#include "DataFormats/VertexReco/interface/VertexFwd.h"


//---- to get weights
#include "SimDataFormats/GeneratorProducts/interface/GenEventInfoProduct.h"

//---- LorentzVector
#include "DataFormats/Candidate/interface/Candidate.h"


//
// class declaration
//

class EcalAlignment : public edm::EDAnalyzer {
 public:
  explicit EcalAlignment(const edm::ParameterSet&);
  ~EcalAlignment();


 private:
  virtual void beginJob() ;
  virtual void analyze(const edm::Event&, const edm::EventSetup&);
  virtual void endJob() ;

      // ----------member data ---------------------------
      
  std::vector<std::string> eleId_names_;
  edm::InputTag recHitCollection_EB_;
  edm::InputTag recHitCollection_EE_;
  edm::InputTag EleTag_;
  edm::InputTag CALOMetTag_;
  edm::InputTag TrackTag_;
  edm::InputTag vtxTag_;
  edm::InputTag puTag_;
  
  edm::InputTag genEvtInfoTag_;
  
  edm::EDGetTokenT<std::vector<pat::MET> > pfMetHT_;
  edm::EDGetTokenT<std::vector<PileupSummaryInfo> > puSummaryT_ ;
  edm::EDGetTokenT<GenEventInfoProduct> GenInfoT_ ;
  edm::EDGetTokenT<reco::VertexCollection> vtxHT_;
  edm::EDGetTokenT<EcalRecHitCollection> Token_recHitCollection_EB_;
  edm::EDGetTokenT<EcalRecHitCollection> Token_recHitCollection_EE_;
  edm::EDGetTokenT<std::vector<pat::Electron> > Token_EleTag_;
  
  
  
  
  bool isMC_;

  bool debug_;



  TH1F* m_totalEvents;
  TH1F* m_passedEvents;
  TH1F* m_filterEfficiency;


  TTree* myTree_;

  int numPUMC_;

  int time_ ;

  int BX_;
  int lumiId_;
  int runId_;
  int eventId_;
  int eventNaiveId_;

  double deltaEtaSuperClusterAtVtx_;
  double deltaEtaSeedClusterAtCalo_;
  double deltaEtaEleClusterAtCalo_;
  double deltaPhiEleClusterAtCalo_;
  double deltaPhiSuperClusterAtVtx_;
  double deltaPhiSeedClusterAtCalo_;
  int mishits_;
  int nAmbiguousGsfTracks_;

  int electrons_classification_;
  int electrons_basicClustersSize_;
       
  double dist_;
  double dcot_;

  double HoE_;
  double SigmaIEtaIEta_;
  double eleTrkIso_;
  double eleEcalIso_;
  double eleHcalIsoD1_;
  double eleHcalIsoD2_;
  
  double elePFphotonIso_;
  double elePFneutralHadronIso_;
  
  unsigned int eleMisHits_;
  double met_;
  double sumEt_;
  double eta_;
  double phi_;
  double pT_;
  double ET_;
  double MT_;
  double mll_;
  double EoP_;
  double eleFBrem_;
  double eleES_;
  double E2x2_;
  double E3x3_;
  double E5x5_;
  double ESC_;
  double ETSC_;
  double Sigma_Phi_;
  double Sigma_Eta_;
  double pIn_;
  double pOut_;
  double pAtCalo_;
  double p_;
  double E9oE25_;
  double DeltaEtaIn_;
  double DeltaPhiIn_;
  double etaSC_;
  double phiSC_;
  int nGoodElectrons_;
  int iSM_;
  int iSC_;
  double dphiMETEle_;
  double eleCharge_;
  double eleSwissCross_;
  int seedSeverityLevel_;
  int* eleId_;
  int iDetEB_;
  int iDetEE_;

  int nvtx_;
  double xvtx_;
  double yvtx_;
  double zvtx_;

  //---- MC information ----
  double mc_pt_;
  double mc_eta_;
  double mc_phi_;
  
  double _mc_weight;

};


#endif
