#include "TH1F.h"
#include "TH2F.h"
#include "TTree.h"
#include "TFile.h"
#include "TChain.h"

#include "TLegend.h"
#include "TCanvas.h"

#include <iostream>
#include <fstream>

//==== parameter include ====
/*#include "FWCore/Utilities/interface/Exception.h"
#include "FWCore/PythonParameterSet/interface/MakePyBind11ParameterSets.h"
#include "FWCore/ParameterSet/interface/ProcessDesc.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/ParameterSetReader/interface/ParameterSetReader.h"
*/

using namespace std;

int main(){

	//------------- data -----------
	//TFile* fout = new TFile("test");
	TFile* f = TFile::Open("/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amkrishn/ECAL_Alignment_2018UL_test/WithCutBasedID/EGamma/crab_DATA2018UL_withCutBasedID/211213_125955/0000/treeECALAlignment_withCutBasedID_full.root");
	TFile* f_MC = TFile::Open("/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amkrishn/ECAL_Alignment_2018UL_test/MC_new/DYJetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/crab_MC_2018_new/211215_135807/0000/treeECALAlignment_MC_new.root");

	TTree *t = (TTree*)f->Get("ntupleEcalAlignment/myTree");
	TTree *t_MC = (TTree*)f_MC->Get("ntupleEcalAlignment/myTree");

	Double_t        mll, mllMC;
  	Double_t        pT, pTMC;
  	Int_t           electrons_classification, electrons_classificationMC;
  	Double_t        eta, etaMC;
  	Int_t           electrons_basicClustersSize, electrons_basicClustersSizeMC;
  	Double_t        etaSC, etaSCMC;
 	//Double_t        deltaPhiSuperClusterAtVtx;
  	Double_t        SigmaIEtaIEta, SigmaIEtaIEtaMC;
  	Double_t        eleTrkIso, eleTrkIsoMC;
  	Double_t        eleHcalIsoD1, eleHcalIsoD1MC;
  	Double_t        eleHcalIsoD2, eleHcalIsoD2MC;
  	Double_t        eleEcalIso, eleEcalIsoMC;
  	Double_t        ETSC, ETSCMC;
  	Double_t		ESC, ESCMC;
  	Int_t			EGMcutBasedElectronIDloose, EGMcutBasedElectronIDlooseMC;
  	Int_t			EGMcutBasedElectronIDmedium, EGMcutBasedElectronIDmediumMC;
  	Int_t			EGMcutBasedElectronIDtight, EGMcutBasedElectronIDtightMC;

	t->SetBranchAddress("mll",&mll);
 	t->SetBranchAddress("pT",&pT);
	t->SetBranchAddress("electrons_classification",&electrons_classification);
  	t->SetBranchAddress("eta",&eta);
	t->SetBranchAddress("electrons_basicClustersSize",&electrons_basicClustersSize);
 	t->SetBranchAddress("etaSC",&etaSC);
  	t->SetBranchAddress("ESC",&ESC);
  	t->SetBranchAddress("SigmaIEtaIEta",&SigmaIEtaIEta);
  	t->SetBranchAddress("eleTrkIso",&eleTrkIso);
  	t->SetBranchAddress("eleHcalIsoD1",&eleHcalIsoD1);
  	t->SetBranchAddress("eleHcalIsoD2",&eleHcalIsoD2);
  	t->SetBranchAddress("eleEcalIso",&eleEcalIso);
  	t->SetBranchAddress("ETSC",&ETSC);
  	t->SetBranchAddress("EGMcutBasedElectronIDloose", &EGMcutBasedElectronIDloose);
  	t->SetBranchAddress("EGMcutBasedElectronIDmedium", &EGMcutBasedElectronIDmedium);
  	t->SetBranchAddress("EGMcutBasedElectronIDtight", &EGMcutBasedElectronIDtight);


  	t_MC->SetBranchAddress("mll",&mllMC);
 	t_MC->SetBranchAddress("pT",&pTMC);
	t_MC->SetBranchAddress("electrons_classification",&electrons_classificationMC);
  	t_MC->SetBranchAddress("eta",&etaMC);
	t_MC->SetBranchAddress("electrons_basicClustersSize",&electrons_basicClustersSizeMC);
 	t_MC->SetBranchAddress("etaSC",&etaSCMC);
  	t_MC->SetBranchAddress("ESC",&ESCMC);
  	t_MC->SetBranchAddress("SigmaIEtaIEta",&SigmaIEtaIEtaMC);
  	t_MC->SetBranchAddress("eleTrkIso",&eleTrkIsoMC);
  	t_MC->SetBranchAddress("eleHcalIsoD1",&eleHcalIsoD1MC);
  	t_MC->SetBranchAddress("eleHcalIsoD2",&eleHcalIsoD2MC);
  	t_MC->SetBranchAddress("eleEcalIso",&eleEcalIsoMC);
  	t_MC->SetBranchAddress("ETSC",&ETSCMC);
  	t_MC->SetBranchAddress("EGMcutBasedElectronIDloose", &EGMcutBasedElectronIDlooseMC);
  	t_MC->SetBranchAddress("EGMcutBasedElectronIDmedium", &EGMcutBasedElectronIDmediumMC);
  	t_MC->SetBranchAddress("EGMcutBasedElectronIDtight", &EGMcutBasedElectronIDtightMC);

  	vector<string> specialRegion{"EB+", "EB-", "EE+", "EE-"};
  	//vector<string> cuts{"loose","medium","tight"};
  	//for(auto cut: cuts){

  		//}
  	for(auto region: specialRegion){

  		TH1D *Zmass = new TH1D("Zmass","Zmass; mll (GeV); entries", 100, 85, 95);
		TH1D *ee_pT = new TH1D("ee_pT","pT; pT (GeV); entries", 240, 0, 120);
		TH1D *ee_Eta = new TH1D("ee_Eta","eta; #eta; entries", 60, -3, 3);
		TH1D *ETSC_data = new TH1D("ETSC_data","ETSC_data; ETSC (GeV); entries", 240, 0, 120);
		TH1D *eClusterSize_data = new TH1D("eClusterSize_data","data;electrons_basicClustersSize ; entries", 12, 0, 12);
		TH1D *ESC_data = new TH1D("ESC_data","ESC_data; ESC (GeV); entries", 600, 0, 500);
		//else TH1D *ESC_data = new TH1D("ESC_data","ESC_data; ESC (GeV); entries", 600, 0, 200);
		
		TH1D *etaSC_data = new TH1D("etaSC_data","data; #eta_{SC}; entries", 60, -3, 3);
	
		long nentries = t->GetEntries();
		for (int jentry = 0; jentry < nentries; jentry++){

			t->GetEntry(jentry);
			if (electrons_classification != 0) continue;
			if (ETSC < 20) continue;
			//if (((abs(eta)<=1.5 && (eleTrkIso+eleEcalIso+eleHcalIsoD1+eleHcalIsoD2)/pT>0.07 && abs(SigmaIEtaIEta)>0.01) || (abs(eta)>=1.5 && (eleTrkIso+eleEcalIso+eleHcalIsoD1+eleHcalIsoD2)/pT>0.06 && abs(SigmaIEtaIEta)>0.03))) continue;
			if(EGMcutBasedElectronIDloose != 1) continue;
			if (mll<85 || mll>95) continue;
			if (pT < 20) continue;
			//if (etaSC < -1.479 || etaSC > 1.479) continue;  //------- EB
			//if (etaSC > -1.5 || etaSC < 1.5) continue;  //------ EE

			if(region == "EB+"){ if (etaSC < 0 || etaSC > 1.5) continue;  };
			if(region == "EB-"){ if (etaSC > 0 || etaSC < -1.5) continue; };
			if(region == "EE+"){ if (etaSC < 1.5) continue; };
			if(region == "EE-"){ if (etaSC > -1.5) continue; };

			Zmass->Fill(mll);
			ee_pT->Fill(pT);
			ee_Eta->Fill(eta);
			ETSC_data->Fill(ETSC);
			eClusterSize_data->Fill(electrons_basicClustersSize);
			ESC_data->Fill(ESC);
			etaSC_data->Fill(etaSC);
		} 

	// ------ MC ---------
	

		TH1D *Zmass_MC = new TH1D("ZmassMC","Zmass MC; mll (GeV); entries", 100, 85, 95);
		TH1D *ee_pT_MC = new TH1D("pT_MC","pT_MC; pT (GeV); entries", 240, 0, 120);
		TH1D *ee_Eta_MC = new TH1D("Eta_MC","MC; #eta; entries", 60, -3, 3);
		TH1D *ETSC_MC = new TH1D("ETSC_MC","ETSC_MC; #ETSC MC (GeV); entries", 240, 0, 120);
		TH1D *eClusterSize_MC = new TH1D("eClusterSize_MC","MC; electrons_basicClustersSize; entries", 12, 0, 12);
		TH1D *ESC_MC = new TH1D("ESC_MC","ESC_MC; ESC (GeV); entries", 600, 0, 600);
		TH1D *etaSC_MC = new TH1D("etaSC_MC","MC; #eta_{SC}; entries", 60, -3, 3);


		long entries = t_MC->GetEntries();
		for (int jentry = 0; jentry < entries; jentry++){

			t_MC->GetEntry(jentry);
			if (electrons_classificationMC != 0) continue;
			if (ETSCMC < 20) continue;
			//if (((abs(etaMC)<=1.5 && (eleTrkIsoMC+eleEcalIsoMC+eleHcalIsoD1MC+eleHcalIsoD2MC)/pTMC>0.07 && abs(SigmaIEtaIEtaMC)>0.01) || (abs(etaMC)>=1.5 && (eleTrkIsoMC+eleEcalIsoMC+eleHcalIsoD1MC+eleHcalIsoD2MC)/pTMC>0.06 && abs(SigmaIEtaIEtaMC)>0.03))) continue;
			if(EGMcutBasedElectronIDlooseMC != 1) continue;
			if (mllMC<85 || mllMC>95) continue;
			if (pTMC < 20) continue;
			//if (etaSC < -1.479 || etaSC > 1.479) continue;  //------ EB
			//if (etaSC > -1.5 || etaSC < 1.5) continue;  //------ EE
			if(region == "EB+"){ if (etaSCMC < 0 || etaSCMC > 1.5) continue;  };
			if(region == "EB-"){ if (etaSCMC > 0 || etaSCMC < -1.5) continue; };
			if(region == "EE+"){ if (etaSCMC < 1.5) continue; };
			if(region == "EE-"){ if (etaSCMC > -1.5) continue; };

			Zmass_MC->Fill(mllMC);
			ee_pT_MC->Fill(pTMC);
			ee_Eta_MC->Fill(etaMC);
			ETSC_MC->Fill(ETSCMC);
			eClusterSize_MC->Fill(electrons_basicClustersSizeMC);
			ESC_MC->Fill(ESCMC);
			etaSC_MC->Fill(etaSCMC);

		} 



	TCanvas* c = new TCanvas();
	c->cd();
	Zmass_MC->Scale(Zmass->Integral()/Zmass_MC->Integral());
	Zmass_MC->SetLineColor(kRed);
	Zmass_MC->Draw();
	Zmass->Draw("E same");
	c->BuildLegend(.1,.15,.1,.15);
	c->SaveAs(Form("/eos/user/a/amkrishn/www/EcalAlignment/test/%snew/loose/Zmass.png",region.c_str()));
	c->SaveAs(Form("/eos/user/a/amkrishn/www/EcalAlignment/test/%snew/loose/Zmass.pdf",region.c_str()));

	c->Clear();
	c->cd();
	ee_Eta->Draw("E");
	ee_Eta_MC->Scale(ee_Eta->Integral()/ee_Eta_MC->Integral());
	ee_Eta_MC->SetLineColor(kRed);
	ee_Eta_MC->Draw("same");
	c->BuildLegend(.1,.15,.1,.15);
	c->SaveAs(Form("/eos/user/a/amkrishn/www/EcalAlignment/test/%snew/loose/Eta.png",region.c_str()));
	c->SaveAs(Form("/eos/user/a/amkrishn/www/EcalAlignment/test/%snew/loose/Eta.pdf",region.c_str()));
	c->Clear();
	c->cd();
	ee_pT->Draw("E");
	ee_pT_MC->Scale(ee_pT->Integral()/ee_pT_MC->Integral());
	ee_pT_MC->SetLineColor(kRed);
	ee_pT_MC->Draw("same");
	c->BuildLegend(.1,.15,.1,.15);
	c->SaveAs(Form("/eos/user/a/amkrishn/www/EcalAlignment/test/%snew/loose/pT.png",region.c_str()));
	c->SaveAs(Form("/eos/user/a/amkrishn/www/EcalAlignment/test/%snew/loose/pT.pdf",region.c_str()));

	c->Clear();
	c->cd();
	ETSC_data->Draw("E");
	ETSC_MC->Scale(ETSC_data->Integral()/ETSC_MC->Integral());
	ETSC_MC->SetLineColor(kRed);
	ETSC_MC->Draw("same");
	c->BuildLegend(.1,.15,.1,.15);
	c->SaveAs(Form("/eos/user/a/amkrishn/www/EcalAlignment/test/%snew/loose/ETSC.png",region.c_str()));
	c->SaveAs(Form("/eos/user/a/amkrishn/www/EcalAlignment/test/%snew/loose/ETSC.pdf",region.c_str()));

	c->Clear();
	c->cd();
	eClusterSize_data->Draw("E");
	eClusterSize_MC->Scale(eClusterSize_data->Integral()/eClusterSize_MC->Integral());
	eClusterSize_MC->SetLineColor(kRed);
	eClusterSize_MC->Draw("same");
	c->BuildLegend(.1,.15,.1,.15);
	c->SaveAs(Form("/eos/user/a/amkrishn/www/EcalAlignment/test/%snew/loose/electrons_basicClustersSize.png",region.c_str()));
	c->SaveAs(Form("/eos/user/a/amkrishn/www/EcalAlignment/test/%snew/loose/electrons_basicClustersSize.pdf",region.c_str()));

	c->Clear();
	c->cd();
	etaSC_data->Draw("E");
	etaSC_MC->Scale(etaSC_data->Integral()/etaSC_MC->Integral());
	etaSC_MC->SetLineColor(kRed);
	etaSC_MC->Draw("same");
	c->BuildLegend(.1,.15,.1,.15);
	c->SaveAs(Form("/eos/user/a/amkrishn/www/EcalAlignment/test/%snew/loose/etaSC.png",region.c_str()));
	c->SaveAs(Form("/eos/user/a/amkrishn/www/EcalAlignment/test/%snew/loose/etaSC.pdf",region.c_str()));

	c->Clear();
	c->cd();
	ESC_data->Draw("E");
	ESC_MC->Scale(ESC_data->Integral()/ESC_MC->Integral());
	ESC_MC->SetLineColor(kRed);
	ESC_MC->Draw("same");
	c->BuildLegend(.1,.15,.1,.15);
	c->SaveAs(Form("/eos/user/a/amkrishn/www/EcalAlignment/test/%snew/loose/E_SC.png",region.c_str()));
	c->SaveAs(Form("/eos/user/a/amkrishn/www/EcalAlignment/test/%snew/loose/E_SC.pdf",region.c_str()));

	delete c; 
	delete Zmass;
	delete ee_pT;
	delete ee_Eta;
	delete Zmass_MC;
	delete ee_pT_MC, ee_Eta_MC, ETSC_MC, ETSC_data, eClusterSize_MC, eClusterSize_data, ESC_MC, ESC_data, etaSC_MC, etaSC_data;


	}

	return 0;

}
