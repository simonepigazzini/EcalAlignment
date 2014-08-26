//--------------------------
//---- plotting tool 2D ----
//--------------------------

#include "TDRStyle.cc"

void Draw2D(std::string nameInFileRoot, std::string var_Y = "etaSC", int NBIN_Y = 1000, float MIN_Y = 0, float MAX_Y = 1000, std::string varHR_Y = "", std::string var_X = "etaSC", int NBIN_X = 1000, float MIN_X = 0, float MAX_X = 1000, std::string varHR_X = "", std::string globalCut = "1") {
 if (varHR_X == "") {
  varHR_X = var_X;
 }
 if (varHR_Y == "") {
  varHR_Y = var_Y;
 }
 gStyle->SetOptStat(0);
 int nSig = 5;
 TFile* f_Sig[100];
 TTree* t_Sig[100];
 TH2F* h_Sig[100];
 std::vector<std::string> vNameSig;
 std::vector<std::string> vNameSigHR;
 std::vector<double> vXsecSig;
 
 vNameSig.push_back(nameInFileRoot); vNameSigHR.push_back("MC");
 vXsecSig.push_back(1.); //---- pb
 
 nSig = vXsecSig.size();
 TString name;
 for (int iSig = 0; iSig < nSig; iSig++) {
  f_Sig[iSig] = new TFile (vNameSig.at(iSig).c_str());
 }
 
 for (int iSig = 0; iSig < nSig; iSig++) {
  t_Sig[iSig] = (TTree*) f_Sig[iSig] -> Get ("ntupleEcalAlignment/myTree");
 }
 
 for (int iSig = 0; iSig < nSig; iSig++) {
  name = Form ("hSig_%d",iSig);
  h_Sig[iSig] = new TH2F(name.Data(),vNameSigHR.at(iSig).c_str(),NBIN_X,MIN_X,MAX_X,NBIN_Y,MIN_Y,MAX_Y);
 }
 
 TString weight = Form ("1");
 TString toDraw;
 for (int iSig = 0; iSig < nSig; iSig++) {
  toDraw = Form ("%s:%s >> hSig_%d",var_Y.c_str(),var_X.c_str(),iSig);
  weight = Form ("(%s) * %f",globalCut.c_str(),vXsecSig.at(iSig));
  t_Sig[iSig]->Draw(toDraw.Data(),weight.Data(),"goff");
 }

 //---- estetica
 for (int iSig = 0; iSig < nSig; iSig++) {
  h_Sig[iSig]->SetMarkerColor (kRed+iSig);
  h_Sig[iSig]->SetLineColor (kRed+iSig);
  h_Sig[iSig]->SetLineWidth(3);
  h_Sig[iSig]->SetLineStyle(1+iSig);
  h_Sig[iSig]->GetXaxis()->SetTitle(varHR_X.c_str());
  h_Sig[iSig]->GetYaxis()->SetTitle(varHR_Y.c_str());
 }
 
 TH2F* sum_h_Sig  = new TH2F("sum_h_Sig","",NBIN_X,MIN_X,MAX_X,NBIN_Y,MIN_Y,MAX_Y);
 for (int iSig = 0; iSig < nSig; iSig++) {
  sum_h_Sig->Add(h_Sig[iSig]);
 }
 sum_h_Sig->GetXaxis()->SetTitle(varHR_X.c_str());
 sum_h_Sig->GetYaxis()->SetTitle(varHR_Y.c_str());
 
 TProfile* sum_h_Sig_tx = (TProfile*) sum_h_Sig->ProfileX();
 sum_h_Sig_tx->SetMarkerSize (2);
 sum_h_Sig_tx->SetMarkerStyle (22);
 sum_h_Sig_tx->SetMarkerColor (kRed);
 sum_h_Sig_tx->SetLineColor (kRed);
 sum_h_Sig_tx->SetLineWidth(3);
 sum_h_Sig_tx->SetLineStyle(1);
 
 
 TCanvas* cc2D = new TCanvas("cc2D","cc2D",700,700);
 cc2D->SetGrid();
 sum_h_Sig->Draw("colz");
 sum_h_Sig_tx->Draw("EPsame");
  
}


