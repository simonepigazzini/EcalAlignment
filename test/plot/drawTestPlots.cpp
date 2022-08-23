#include "TH1F.h"
#include "TH2F.h"
#include "TTree.h"
#include "TFile.h"
#include "TChain.h"

#include "TLegend.h"
#include "TCanvas.h"

#include <iostream>
#include <fstream>

#include <TROOT.h>
#include <TStyle.h>

using namespace std;


void buildLegend(TH1D* h_data, TH1D* h_MC, TCanvas *c1){
	TLegend* legend = new TLegend(0.8,0.6,0.90,0.7);
	legend->AddEntry(h_MC,"MC","f");
	legend->AddEntry(h_data,"data","PE");
	legend->SetBorderSize(0);
	c1->cd();
	legend->Draw();

}

int main(){

  gStyle->SetMarkerStyle(20);
  gStyle->SetMarkerSize(0.5);
  gStyle->SetMarkerColor(kRed);
  gROOT->ForceStyle();

	//TFile* fout = new TFile("test");
	//TFile* f = TFile::Open("/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amkrishn/ECALalignment2022run3Commisioning/data/2022C/EGamma/crab_EcalAlignment_RERECO_2022C_new/220808_232015/0000/treeECALAlignment_run3_v1.root");
	TFile* f = TFile::Open("/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amkrishn/ECALalignment2022run3Commisioning/data/automationOutputHadd/treeECALAlignment_run3Commissioning_2022C.root");   
        TFile* f_MC = TFile::Open("/eos/cms/store/group/dpg_ecal/alca_ecalcalib/amkrishn/ECALalignment2022run3Commisioning/MC/DYJetsToLL_M-50_TuneCP5_13p6TeV-madgraphMLM-pythia8/crab_MC_2022_Run3commisioning/220705_182016/0000/treeECALAlignment_MC2022.root");
	
	string plotDir = "/eos/user/a/amkrishn/www/EcalAlignment/MC2022_run3Commisioning/data_mc_comparison/";

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

  		TH1D *Zmass = new TH1D("Zmass","; mll (GeV); entries", 80, 82, 98);
		TH1D *ee_pT = new TH1D("ee_pT","; pT (GeV); entries", 100, 0, 100);
		TH1D *ee_Eta = new TH1D("ee_Eta","; #eta; entries", 60, -3, 3);
		TH1D *ETSC_data = new TH1D("ETSC_data","; E_{T} (SC) (GeV); entries", 100, 0, 100);
		TH1D *eClusterSize_data = new TH1D("eClusterSize_data",";electrons_basicClustersSize ; entries", 12, 0, 12);
		TH1D *ESC_data = new TH1D("ESC_data","; E (SC) (GeV); entries", 125, 0, 500);
		//else TH1D *ESC_data = new TH1D("ESC_data","ESC_data; ESC (GeV); entries", 600, 0, 200);
		
		TH1D *etaSC_data = new TH1D("etaSC_data","data; #eta_{SC}; entries", 60, -3, 3);
	
		long nentries = t->GetEntries();
		for (int jentry = 0; jentry < nentries; jentry++){

			t->GetEntry(jentry);
			if (electrons_classification != 0) continue;
			if (ETSC < 20) continue;
			//if (((abs(eta)<=1.5 && (eleTrkIso+eleEcalIso+eleHcalIsoD1+eleHcalIsoD2)/pT>0.07 && abs(SigmaIEtaIEta)>0.01) || (abs(eta)>=1.5 && (eleTrkIso+eleEcalIso+eleHcalIsoD1+eleHcalIsoD2)/pT>0.06 && abs(SigmaIEtaIEta)>0.03))) continue;
			if(EGMcutBasedElectronIDloose != 1) continue;
			if ((region == "EB+"|| region == "EB-") && (mll<85 || mll>96)) continue;
			if ((region == "EE+"|| region == "EE-") && (mll<83 || mll>97)) continue;
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
	

		TH1D *Zmass_MC = new TH1D("ZmassMC","; mll (GeV); entries", 80, 82, 98);
		TH1D *ee_pT_MC = new TH1D("pT_MC","; pT (GeV); entries", 100, 0, 100);
		TH1D *ee_Eta_MC = new TH1D("Eta_MC","; #eta; entries", 60, -3, 3);
		TH1D *ETSC_MC = new TH1D("ETSC_MC","; E_{T} (SC)(GeV); entries", 100, 0, 100);
		TH1D *eClusterSize_MC = new TH1D("eClusterSize_MC","; electrons_basicClustersSize; entries", 12, 0, 12);
		TH1D *ESC_MC = new TH1D("ESC_MC","; E (SC) (GeV); entries", 125, 0, 500);
		TH1D *etaSC_MC = new TH1D("etaSC_MC","; #eta_{SC}; entries", 60, -3, 3);


		long entries = t_MC->GetEntries();
		for (int jentry = 0; jentry < entries; jentry++){

			t_MC->GetEntry(jentry);
			if (electrons_classificationMC != 0) continue;
			if (ETSCMC < 20) continue;
			//if (((abs(etaMC)<=1.5 && (eleTrkIsoMC+eleEcalIsoMC+eleHcalIsoD1MC+eleHcalIsoD2MC)/pTMC>0.07 && abs(SigmaIEtaIEtaMC)>0.01) || (abs(etaMC)>=1.5 && (eleTrkIsoMC+eleEcalIsoMC+eleHcalIsoD1MC+eleHcalIsoD2MC)/pTMC>0.06 && abs(SigmaIEtaIEtaMC)>0.03))) continue;
			if(EGMcutBasedElectronIDlooseMC != 1) continue;
			if ((region == "EB+"|| region == "EB-") && (mllMC<85 || mllMC>96)) continue;
                        if ((region == "EE+"|| region == "EE-") && (mllMC<83 || mllMC>97)) continue;
			//if (mllMC<85 || mllMC>95) continue;
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
	Zmass_MC->Draw("HIST");
	Zmass->SetLineColor(kRed);
	Zmass->Draw("PE same");
	//c->BuildLegend(.1,.12,.1,.12);
	buildLegend(Zmass, Zmass_MC, c);
	c->SaveAs(Form("%s/Zmass_%s.png",plotDir.c_str(),region.c_str()));
	c->SaveAs(Form("%s/Zmass_%s.pdf",plotDir.c_str(),region.c_str()));

	c->Clear();
	c->cd();
	ee_Eta_MC->Draw("HIST");
	ee_Eta_MC->Scale(ee_Eta->Integral()/ee_Eta_MC->Integral());
	ee_Eta->SetLineColor(kRed);
	ee_Eta->Draw("PE same");
	//c->BuildLegend(.1,.12,.1,.12);
	buildLegend(ee_Eta, ee_Eta_MC, c);
	c->SaveAs(Form("%s/Eta_%s.png",plotDir.c_str(),region.c_str()));
	c->SaveAs(Form("%s/Eta_%s.pdf",plotDir.c_str(),region.c_str()));

	c->Clear();
	c->cd();
	ee_pT_MC->Scale(ee_pT->Integral()/ee_pT_MC->Integral());
	ee_pT_MC->Draw("HIST");
	ee_pT->SetLineColor(kRed);
	ee_pT->Draw("PE same");
	//c->BuildLegend(.1,.12,.1,.12);
	buildLegend(ee_pT, ee_pT_MC, c);
	c->SaveAs(Form("%s/pT_%s.png",plotDir.c_str(),region.c_str()));
	c->SaveAs(Form("%s/pT_%s.pdf",plotDir.c_str(),region.c_str()));

	c->Clear();
	c->cd();
	ETSC_MC->Scale(ETSC_data->Integral()/ETSC_MC->Integral());
	ETSC_MC->Draw("HIST");
	ETSC_data->SetLineColor(kRed);
	ETSC_data->Draw("PE same");
	//c->BuildLegend(.1,.12,.1,.12);
	buildLegend(ETSC_data, ETSC_MC, c);
	c->SaveAs(Form("%s/ETSC_%s.png",plotDir.c_str(),region.c_str()));
	c->SaveAs(Form("%s/ETSC_%s.pdf",plotDir.c_str(),region.c_str()));

	c->Clear();
	c->cd();
	eClusterSize_MC->Scale(eClusterSize_data->Integral()/eClusterSize_MC->Integral());
	eClusterSize_MC->Draw("HIST");
	eClusterSize_data->SetLineColor(kRed);
	eClusterSize_data->Draw("PE same");
	//c->BuildLegend(.1,.12,.1,.12);
	buildLegend(eClusterSize_data, eClusterSize_MC, c);
	c->SaveAs(Form("%s/electrons_basicClustersSize_%s.png",plotDir.c_str(),region.c_str()));
	c->SaveAs(Form("%s/electrons_basicClustersSize_%s.pdf",plotDir.c_str(),region.c_str()));

	c->Clear();
	c->cd();
	etaSC_MC->Scale(etaSC_data->Integral()/etaSC_MC->Integral());
	etaSC_MC->Draw("HIST");
	etaSC_data->SetLineColor(kRed);
	etaSC_data->Draw("PE same");
	//c->BuildLegend(.1,.12,.1,.12);
	buildLegend(etaSC_data, etaSC_MC, c);
	c->SaveAs(Form("%s/etaSC_%s.png",plotDir.c_str(),region.c_str()));
	c->SaveAs(Form("%s/etaSC_%s.pdf",plotDir.c_str(),region.c_str()));

	c->Clear();
	c->cd();
	ESC_MC->Scale(ESC_data->Integral()/ESC_MC->Integral());
	ESC_MC->Draw("HIST");
	ESC_data->SetLineColor(kRed);
	ESC_data->Draw("PE same");
	//c->BuildLegend(.1,.12,.1,.12);
	buildLegend(ESC_data, ESC_MC, c);
	c->SaveAs(Form("%s/E_SC_%s.png",plotDir.c_str(),region.c_str()));
	c->SaveAs(Form("%s/E_SC_%s.pdf",plotDir.c_str(),region.c_str()));

	delete c; 
	delete Zmass;
	delete ee_pT;
	delete ee_Eta;
	delete Zmass_MC;
	delete ee_pT_MC, ee_Eta_MC, ETSC_MC, ETSC_data, eClusterSize_MC, eClusterSize_data, ESC_MC, ESC_data, etaSC_MC, etaSC_data;


	}

	return 0;

}
