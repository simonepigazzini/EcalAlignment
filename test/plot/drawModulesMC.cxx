#include "TDRStyle.cc"

void createHisto(TLatex* tinfo, TH1F* hmc, TTree* tmc, char* variable, char* title, char* cut) {

 TString toDraw;
 TString tcut;

//  tcut = Form("(%s) * weight_PU",cut);
 tcut = Form("(%s)",cut);
 toDraw = Form("%s >> %s",variable,hmc->GetName());
 tmc   -> Draw(toDraw.Data(),tcut.Data(),"goff");

 hmc -> GetXaxis()->SetTitle(title);
 hmc -> GetYaxis()->SetTitle("Number of events");

 hmc->SetMarkerColor(kBlue);
 hmc->SetLineColor(kBlue);
 hmc->SetLineWidth(2);
 hmc->SetFillColor(kBlue);
 hmc->SetFillStyle(3002);

 TString  sinfo = Form ("#splitline{<%s>_{MC} = %.2f #times 10^{-3}}{#sigma_{MC} = %.2f #times 10^{-3}}",title,hmc->GetMean()*1000,hmc->GetRMS()*1000);
 tinfo -> SetText(0.2,0.85,sinfo);
 tinfo -> SetTextSize(0.040);
 tinfo -> SetNDC(true); 
}


void createHisto2D(TH2F* hmc, TTree* tmc, char* variableY, char* variableX, char* title, char* cut) {

 TString toDraw;
 TString tcut;

 //  tcut = Form("(%s) * weight_PU",cut);
 tcut = Form("(%s)",cut);
 toDraw = Form("%s:%s >> %s",variableY, variableX, hmc->GetName());
 tmc   -> Draw(toDraw.Data(),tcut.Data(),"goff");

 hmc -> GetXaxis()->SetTitle(variableX);
 hmc -> GetYaxis()->SetTitle(variableY);

 hmc->SetMarkerColor(kRed);
 hmc->SetLineColor(kRed);
 hmc->SetLineWidth(2);
 hmc->SetFillColor(kRed);
 hmc->SetFillStyle(3002);

}


void drawModulesMC(TString nameInFileRoot, TString nameOutputDir, TString nameDATA, TString commonCut = "1"){
 TDRStyle();

 gStyle->SetTitleYOffset(1.1);
 gStyle->cd();


 TFile *fileMC   = TFile::Open(nameInFileRoot.Data());

 TTree* trMC   = (TTree*) fileMC  -> Get("ntupleEcalAlignment/myTree");


 ///---- all ----
 TH1F* DPhiMC   = new TH1F("DPhiMC",  " MC"  ,200,-0.04,0.04);
 TH1F* DEtaMC   = new TH1F("DEtaMC"  ," MC"  ,200,-0.02,0.02);

 ///---- text info (begin) ----
 TLatex*  tinfoDPhi = new TLatex(0.2,0.8,"");
 TLatex*  tinfoDEta = new TLatex(0.2,0.8,"");
 ///---- text info (end) ----

 createHisto(tinfoDPhi, DPhiMC, trMC, "deltaPhiSuperClusterAtVtx", "#Delta#phi",commonCut.Data());
 createHisto(tinfoDEta, DEtaMC, trMC, "deltaEtaSuperClusterAtVtx", "#Delta#eta",commonCut.Data());

 ///---- legend (begin) ----
 TLegend* legend = new TLegend(0.62,0.72,0.88,0.93);
 legend->AddEntry(DEtaMC,"MC","f");
 legend->SetFillColor(kWhite);
 ///---- legend (end) ----
 
 
 ///---- text (begin) ----
 TLatex *tEB = new TLatex(0.2,0.7,"#splitline{EB}{#splitline{CMS 2011}{L= 4.98 fb^{-1}}}");
 TLatex *tEE = new TLatex(0.2,0.7,"#splitline{EE}{#splitline{CMS 2011}{L= 4.98 fb^{-1}}}");
 tEB->SetNDC(true);
 tEE->SetNDC(true);
 ///---- text (end) ----

 TCanvas* cDPhi = new TCanvas("cDphi","cDphi",700,700);
 DPhiMC->Draw("PE");
 tinfoDPhi->Draw();


 TString toDoShell;
 toDoShell = Form("rm -r %s ;",nameOutputDir.Data());
 system(toDoShell.Data());
 toDoShell = Form("mkdir %s ;",nameOutputDir.Data());
 system(toDoShell.Data());
 toDoShell = Form("mkdir %s/images ;",nameOutputDir.Data());
 system(toDoShell.Data());

 legend->Draw();
 cDPhi->SetGrid(); gPad->Update();

 TCanvas* cDEta = new TCanvas("cDeta","cDeta",700,700);
 DEtaMC->Draw("PE");
 tinfoDEta->Draw();

 legend->Draw();
 cDEta->SetGrid(); gPad->Update();   

 
 ///---- 2D plot ----
 TH2F* DPhiMCvsEta   = new TH2F("DPhiMCvsEta",  "MC"  , 40,-3,3,  200,-0.04,0.04);
 TH2F* DEtaMCvsEta   = new TH2F("DEtaMCvsEta"  ,"MC"  , 40,-3,3,  200,-0.04,0.04);
 createHisto2D(DPhiMCvsEta, trMC, "deltaPhiSuperClusterAtVtx", "etaSC", "#Delta#phi vs #eta_{SC}",commonCut.Data());
 createHisto2D(DEtaMCvsEta, trMC, "deltaEtaSuperClusterAtVtx", "etaSC", "#Delta#eta vs #eta_{SC}",commonCut.Data());

 TProfile* DPhiMCvsEta_tx = (TProfile*) DPhiMCvsEta->ProfileX();
 TProfile* DEtaMCvsEta_tx = (TProfile*) DEtaMCvsEta->ProfileX();

 TCanvas* cDPhivsEta = new TCanvas("cDphivsEta","cDphivsEta",700,700);
 DPhiMCvsEta->Draw("colz");
 DPhiMCvsEta_tx->Draw("same");

 TCanvas* cDEtavsEta = new TCanvas("cDetavsEta","cDetavsEta",700,700);
 DEtaMCvsEta->Draw("colz");
 DEtaMCvsEta_tx->Draw("same");


 
 ///---- 2D plot dphi in EB ----
 
 TString commonCut_EB = Form ("(%s) && (iDetEE < -10)",commonCut.Data());
 
 TH2F* DPhiMCvsPhi_EB   = new TH2F("DPhiMCvsPhi_EB",  "MC"  , 36,-3.15,3.15,  200,-0.04,0.04);
 TH2F* DEtaMCvsPhi_EB   = new TH2F("DEtaMCvsPhi_EB"  ,"MC"  , 36,-3.15,3.15,  200,-0.04,0.04);
 createHisto2D(DPhiMCvsPhi_EB, trMC, "deltaPhiSuperClusterAtVtx", "phiSC", "#Delta#phi vs #phi_{SC}",commonCut_EB.Data());
 createHisto2D(DEtaMCvsPhi_EB, trMC, "deltaEtaSuperClusterAtVtx", "phiSC", "#Delta#eta vs #phi_{SC}",commonCut_EB.Data());
 
 TProfile* DPhiMCvsPhi_EB_tx = (TProfile*) DPhiMCvsPhi_EB->ProfileX();
 TProfile* DEtaMCvsPhi_EB_tx = (TProfile*) DEtaMCvsPhi_EB->ProfileX();
 
 TCanvas* cDPhivsPhi_EB = new TCanvas("cDphivsPhi_EB","cDphivsPhi_EB",700,700);
 DPhiMCvsPhi_EB->Draw("colz");
 DPhiMCvsPhi_EB_tx->Draw("same");
 
 TCanvas* cDEtavsPhi_EB = new TCanvas("cDetavsPhi_EB","cDetavsPhi_EB",700,700);
 DEtaMCvsPhi_EB->Draw("colz");
 DEtaMCvsPhi_EB_tx->Draw("same");
 
 
 ///---- 2D plot dphi in EE ----
 
 TString commonCut_EE = Form ("(%s) && (iDetEE < -10)",commonCut.Data());
 
 TH2F* DPhiMCvsPhi_EE   = new TH2F("DPhiMCvsPhi_EE",  "MC"  , 36,-3.15,3.15,  200,-0.04,0.04);
 TH2F* DEtaMCvsPhi_EE   = new TH2F("DEtaMCvsPhi_EE"  ,"MC"  , 36,-3.15,3.15,  200,-0.04,0.04);
 createHisto2D(DPhiMCvsPhi_EE, trMC, "deltaPhiSuperClusterAtVtx", "phiSC", "#Delta#phi vs #phi_{SC}",commonCut_EE.Data());
 createHisto2D(DEtaMCvsPhi_EE, trMC, "deltaEtaSuperClusterAtVtx", "phiSC", "#Delta#eta vs #phi_{SC}",commonCut_EE.Data());
 
 TProfile* DPhiMCvsPhi_EE_tx = (TProfile*) DPhiMCvsPhi_EE->ProfileX();
 TProfile* DEtaMCvsPhi_EE_tx = (TProfile*) DEtaMCvsPhi_EE->ProfileX();
 
 TCanvas* cDPhivsPhi_EE = new TCanvas("cDphivsPhi_EE","cDphivsPhi_EE",700,700);
 DPhiMCvsPhi_EE->Draw("colz");
 DPhiMCvsPhi_EE_tx->Draw("same");
 
 TCanvas* cDEtavsPhi_EE = new TCanvas("cDetavsPhi_EE","cDetavsPhi_EE",700,700);
 DEtaMCvsPhi_EE->Draw("colz");
 DEtaMCvsPhi_EE_tx->Draw("same");
 
 
 

//  
//  ///---- EB ----
//  TH1F* DPhiDATAEB = new TH1F("DPhiDATAEB"," Data",500,-0.04,0.04);
//  TH1F* DPhiNoAlignmentEB   = new TH1F("DPhiNoAlignmentEB",  "No Alignment"  ,500,-0.04,0.04);
//  TH1F* DPhiMCEB   = new TH1F("DPhiMCEB",  " MC"  ,500,-0.04,0.04);
//  
//  TH1F* DEtaDATAEB = new TH1F("DEtaDATAEB"," Data",500,-0.02,0.02);
//  TH1F* DEtaNoAlignmentEB   = new TH1F("DEtaNoAlignmentEB"  ,"No Alignment"  ,500,-0.02,0.02);
//  TH1F* DEtaMCEB   = new TH1F("DEtaMCEB"  ," MC"  ,500,-0.02,0.02);
//  
//  createHisto(tinfoDPhi,DPhiDATAEB, DPhiNoAlignmentEB, DPhiMCEB, trDATA, trNoAlignment, trMC, "deltaPhiSuperClusterAtVtx", "#Delta#phi","abs(eta)<1.5");
//  createHisto(tinfoDEta,DEtaDATAEB, DEtaNoAlignmentEB, DEtaMCEB, trDATA, trNoAlignment, trMC, "deltaEtaSuperClusterAtVtx", "#Delta#eta","abs(eta)<1.5");
//  
//  
//  
//  TCanvas* cDPhiEB = new TCanvas("cDphiEB2011","cDphiEB2011",700,700);
//  DPhiDATAEB->Draw("PE");
//  DPhiNoAlignmentEB->Draw("PsameE");
//  DPhiMCEB->Draw("same");
//  tEB->Draw();
//  tinfoDPhi->Draw();
//  
//  legend->Draw();
//  cDPhiEB->SetGrid(); gPad->Update();   
//  cDPhiEB->Print("images/cDPhiEB.gif");
//  cDPhiEB->Print("images/cDPhiEB.pdf");
//  cDPhiEB->Print("images/cDPhiEB.png");
//  cDPhiEB->Print("images/cDPhiEB.C"); gSystem->Sleep(1);
//  cDPhiEB->SetLogy(); gPad->Update();
//  cDPhiEB->Print("images/cDPhiEB_logy.gif");
//  cDPhiEB->Print("images/cDPhiEB_logy.pdf");
//  cDPhiEB->Print("images/cDPhiEB_logy.png");
//  cDPhiEB->Print("images/cDPhiEB_logy.C"); gSystem->Sleep(1);
//  
//  
//  TCanvas* cDEtaEB = new TCanvas("cDeta2011EB","cDeta2011EB",700,700);
//  DEtaDATAEB->Draw("PE");
//  DEtaNoAlignmentEB->Draw("PsameE");
//  DEtaMCEB->Draw("same");
//  tEB->Draw();
//  tinfoDEta->Draw();
//  
//  legend->Draw();
//  cDEtaEB->SetGrid(); gPad->Update();   
//  cDEtaEB->Print("images/cDEtaEB.gif");
//  cDEtaEB->Print("images/cDEtaEB.pdf");
//  cDEtaEB->Print("images/cDEtaEB.png");
//  cDEtaEB->Print("images/cDEtaEB.C"); gSystem->Sleep(1);
//  cDEtaEB->SetLogy(); gPad->Update();
//  cDEtaEB->Print("images/cDEtaEB_logy.gif");
//  cDEtaEB->Print("images/cDEtaEB_logy.pdf");
//  cDEtaEB->Print("images/cDEtaEB_logy.png");
//  cDEtaEB->Print("images/cDEtaEB_logy.C"); gSystem->Sleep(1);
//  
//  
//  
//  ///---- EB+ ----
//  TH1F* DPhiDATAEBplus = new TH1F("DPhiDATAEBplus"," Data",500,-0.04,0.04);
//  TH1F* DPhiNoAlignmentEBplus   = new TH1F("DPhiNoAlignmentEBplus",  "No Alignment"  ,500,-0.04,0.04);
//  TH1F* DPhiMCEBplus   = new TH1F("DPhiMCEBplus",  " MC"  ,500,-0.04,0.04);
//  
//  TH1F* DEtaDATAEBplus = new TH1F("DEtaDATAEBplus"," Data",500,-0.02,0.02);
//  TH1F* DEtaNoAlignmentEBplus   = new TH1F("DEtaNoAlignmentEBplus"  ,"No Alignment"  ,500,-0.02,0.02);
//  TH1F* DEtaMCEBplus   = new TH1F("DEtaMCEBplus"  ," MC"  ,500,-0.02,0.02);
//  
//  createHisto(tinfoDPhi,DPhiDATAEBplus, DPhiNoAlignmentEBplus, DPhiMCEBplus, trDATA, trNoAlignment, trMC, "deltaPhiSuperClusterAtVtx", "#Delta#phi","eta>0 && eta<1.5");
//  createHisto(tinfoDEta,DEtaDATAEBplus, DEtaNoAlignmentEBplus, DEtaMCEBplus, trDATA, trNoAlignment, trMC, "deltaEtaSuperClusterAtVtx", "#Delta#eta","eta>0 && eta<1.5");
//  
//  
//  
//  TCanvas* cDPhiEBplus = new TCanvas("cDphiEBplus2011","cDphiEBplus2011",700,700);
//  DPhiDATAEBplus->Draw("PE");
//  DPhiNoAlignmentEBplus->Draw("PsameE");
//  DPhiMCEBplus->Draw("same");
//  tEB->Draw();
//  tinfoDPhi->Draw();
//  
//  legend->Draw();
//  cDPhiEBplus->SetGrid(); gPad->Update();   
//  cDPhiEBplus->Print("images/cDPhiEBplus.gif");
//  cDPhiEBplus->Print("images/cDPhiEBplus.pdf");
//  cDPhiEBplus->Print("images/cDPhiEBplus.png");
//  cDPhiEBplus->Print("images/cDPhiEBplus.C"); gSystem->Sleep(1);
//  cDPhiEBplus->SetLogy(); gPad->Update();
//  cDPhiEBplus->Print("images/cDPhiEBplus_logy.gif");
//  cDPhiEBplus->Print("images/cDPhiEBplus_logy.pdf");
//  cDPhiEBplus->Print("images/cDPhiEBplus_logy.png");
//  cDPhiEBplus->Print("images/cDPhiEBplus_logy.C"); gSystem->Sleep(1);
//  
//  
//  TCanvas* cDEtaEBplus = new TCanvas("cDeta2011EBplus","cDeta2011EBplus",700,700);
//  DEtaDATAEBplus->Draw("PE");
//  DEtaNoAlignmentEBplus->Draw("PsameE");
//  DEtaMCEBplus->Draw("same");
//  tEB->Draw();
//  tinfoDEta->Draw();
//  
//  legend->Draw();
//  cDEtaEBplus->SetGrid(); gPad->Update();   
//  cDEtaEBplus->Print("images/cDEtaEBplus.gif");
//  cDEtaEBplus->Print("images/cDEtaEBplus.pdf");
//  cDEtaEBplus->Print("images/cDEtaEBplus.png");
//  cDEtaEBplus->Print("images/cDEtaEBplus.C"); gSystem->Sleep(1);
//  cDEtaEBplus->SetLogy(); gPad->Update();
//  cDEtaEBplus->Print("images/cDEtaEBplus_logy.gif");
//  cDEtaEBplus->Print("images/cDEtaEBplus_logy.pdf");
//  cDEtaEBplus->Print("images/cDEtaEBplus_logy.png");
//  cDEtaEBplus->Print("images/cDEtaEBplus_logy.C"); gSystem->Sleep(1);
//  
//  
//  
//  ///---- EB- ---- 
//  TH1F* DPhiDATAEBminus = new TH1F("DPhiDATAEBminus"," Data",500,-0.04,0.04);
//  TH1F* DPhiNoAlignmentEBminus   = new TH1F("DPhiNoAlignmentEBminus",  "No Alignment"  ,500,-0.04,0.04);
//  TH1F* DPhiMCEBminus   = new TH1F("DPhiMCEBminus",  " MC"  ,500,-0.04,0.04);
//  
//  TH1F* DEtaDATAEBminus = new TH1F("DEtaDATAEBminus"," Data",500,-0.02,0.02);
//  TH1F* DEtaNoAlignmentEBminus   = new TH1F("DEtaNoAlignmentEBminus"  ,"No Alignment"  ,500,-0.02,0.02);
//  TH1F* DEtaMCEBminus   = new TH1F("DEtaMCEBminus"  ," MC"  ,500,-0.02,0.02);
//  
//  createHisto(tinfoDPhi,DPhiDATAEBminus, DPhiNoAlignmentEBminus, DPhiMCEBminus, trDATA, trNoAlignment, trMC, "deltaPhiSuperClusterAtVtx", "#Delta#phi","eta<0 && eta>-1.5");
//  createHisto(tinfoDEta,DEtaDATAEBminus, DEtaNoAlignmentEBminus, DEtaMCEBminus, trDATA, trNoAlignment, trMC, "deltaEtaSuperClusterAtVtx", "#Delta#eta","eta<0 && eta>-1.5");
//  
//  
//  
//  TCanvas* cDPhiEBminus = new TCanvas("cDphiEBminus2011","cDphiEBminus2011",700,700);
//  DPhiDATAEBminus->Draw("PE");
//  DPhiNoAlignmentEBminus->Draw("PsameE");
//  DPhiMCEBminus->Draw("same");
//  tEB->Draw();
//  tinfoDPhi->Draw();
//  
//  legend->Draw();
//  cDPhiEBminus->SetGrid(); gPad->Update();   
//  cDPhiEBminus->Print("images/cDPhiEBminus.gif");
//  cDPhiEBminus->Print("images/cDPhiEBminus.pdf");
//  cDPhiEBminus->Print("images/cDPhiEBminus.png");
//  cDPhiEBminus->Print("images/cDPhiEBminus.C"); gSystem->Sleep(1);
//  cDPhiEBminus->SetLogy(); gPad->Update();
//  cDPhiEBminus->Print("images/cDPhiEBminus_logy.gif");
//  cDPhiEBminus->Print("images/cDPhiEBminus_logy.pdf");
//  cDPhiEBminus->Print("images/cDPhiEBminus_logy.png");
//  cDPhiEBminus->Print("images/cDPhiEBminus_logy.C"); gSystem->Sleep(1);
//  
//  
//  TCanvas* cDEtaEBminus = new TCanvas("cDeta2011EBminus","cDeta2011EBminus",700,700);
//  DEtaDATAEBminus->Draw("PE");
//  DEtaNoAlignmentEBminus->Draw("PsameE");
//  DEtaMCEBminus->Draw("same");
//  tEB->Draw();
//  tinfoDEta->Draw();
//  
//  legend->Draw();
//  cDEtaEBminus->SetGrid(); gPad->Update();   
//  cDEtaEBminus->Print("images/cDEtaEBminus.gif");
//  cDEtaEBminus->Print("images/cDEtaEBminus.pdf");
//  cDEtaEBminus->Print("images/cDEtaEBminus.png");
//  cDEtaEBminus->Print("images/cDEtaEBminus.C"); gSystem->Sleep(1);
//  cDEtaEBminus->SetLogy(); gPad->Update();
//  cDEtaEBminus->Print("images/cDEtaEBminus_logy.gif");
//  cDEtaEBminus->Print("images/cDEtaEBminus_logy.pdf");
//  cDEtaEBminus->Print("images/cDEtaEBminus_logy.png");
//  cDEtaEBminus->Print("images/cDEtaEBminus_logy.C"); gSystem->Sleep(1);
//  
//  
//  
//  
//  
//  ///---- EE ----
//  TH1F* DPhiDATAEE = new TH1F("DPhiDATAEE"," Data",500,-0.04,0.04);
//  TH1F* DPhiNoAlignmentEE   = new TH1F("DPhiNoAlignmentEE",  "No Alignment"  ,500,-0.04,0.04);
//  TH1F* DPhiMCEE   = new TH1F("DPhiMCEE",  " MC"  ,500,-0.04,0.04);
//  
//  TH1F* DEtaDATAEE = new TH1F("DEtaDATAEE"," Data",500,-0.02,0.02);
//  TH1F* DEtaNoAlignmentEE   = new TH1F("DEtaNoAlignmentEE"  ,"No Alignment"  ,500,-0.02,0.02);
//  TH1F* DEtaMCEE   = new TH1F("DEtaMCEE"  ," MC"  ,500,-0.02,0.02);
//  
//  createHisto(tinfoDPhi,DPhiDATAEE, DPhiNoAlignmentEE, DPhiMCEE, trDATA, trNoAlignment, trMC, "deltaPhiSuperClusterAtVtx", "#Delta#phi","abs(eta)>1.5");
//  createHisto(tinfoDEta,DEtaDATAEE, DEtaNoAlignmentEE, DEtaMCEE, trDATA, trNoAlignment, trMC, "deltaEtaSuperClusterAtVtx", "#Delta#eta","abs(eta)>1.5");
//  
//  
//  
//  TCanvas* cDPhiEE = new TCanvas("cDphiEE2011","cDphiEE2011",700,700);
//  DPhiDATAEE->Draw("PE");
//  DPhiNoAlignmentEE->Draw("PsameE");
//  DPhiMCEE->Draw("same");
//  tEE->Draw();
//  tinfoDPhi->Draw();
//  
//  legend->Draw();
//  cDPhiEE->SetGrid(); gPad->Update();   
//  cDPhiEE->Print("images/cDPhiEE.gif");
//  cDPhiEE->Print("images/cDPhiEE.pdf");
//  cDPhiEE->Print("images/cDPhiEE.png");
//  cDPhiEE->Print("images/cDPhiEE.C"); gSystem->Sleep(1);
//  cDPhiEE->SetLogy(); gPad->Update();
//  cDPhiEE->Print("images/cDPhiEE_logy.gif");
//  cDPhiEE->Print("images/cDPhiEE_logy.pdf");
//  cDPhiEE->Print("images/cDPhiEE_logy.png");
//  cDPhiEE->Print("images/cDPhiEE_logy.C"); gSystem->Sleep(1);
//  
//  
//  TCanvas* cDEtaEE = new TCanvas("cDeta2011EE","cDeta2011EE",700,700);
//  DEtaDATAEE->Draw("PE");
//  DEtaNoAlignmentEE->Draw("PsameE");
//  DEtaMCEE->Draw("same");
//  tEE->Draw();
//  tinfoDEta->Draw();
//  
//  legend->Draw();
//  cDEtaEE->SetGrid(); gPad->Update();   
//  cDEtaEE->Print("images/cDEtaEE.gif");
//  cDEtaEE->Print("images/cDEtaEE.pdf");
//  cDEtaEE->Print("images/cDEtaEE.png");
//  cDEtaEE->Print("images/cDEtaEE.C"); gSystem->Sleep(1);
//  cDEtaEE->SetLogy(); gPad->Update();
//  cDEtaEE->Print("images/cDEtaEE_logy.gif");
//  cDEtaEE->Print("images/cDEtaEE_logy.pdf");
//  cDEtaEE->Print("images/cDEtaEE_logy.png");
//  cDEtaEE->Print("images/cDEtaEE_logy.C"); gSystem->Sleep(1);
//  
//  
//  
//  ///---- EE+ ----
//  TH1F* DPhiDATAEEplus = new TH1F("DPhiDATAEEplus"," Data",500,-0.04,0.04);
//  TH1F* DPhiNoAlignmentEEplus   = new TH1F("DPhiNoAlignmentEEplus",  "No Alignment"  ,500,-0.04,0.04);
//  TH1F* DPhiMCEEplus   = new TH1F("DPhiMCEEplus",  " MC"  ,500,-0.04,0.04);
//  
//  TH1F* DEtaDATAEEplus = new TH1F("DEtaDATAEEplus"," Data",500,-0.02,0.02);
//  TH1F* DEtaNoAlignmentEEplus   = new TH1F("DEtaNoAlignmentEEplus"  ,"No Alignment"  ,500,-0.02,0.02);
//  TH1F* DEtaMCEEplus   = new TH1F("DEtaMCEEplus"  ," MC"  ,500,-0.02,0.02);
//  
//  createHisto(tinfoDPhi,DPhiDATAEEplus, DPhiNoAlignmentEEplus, DPhiMCEEplus, trDATA, trNoAlignment, trMC, "deltaPhiSuperClusterAtVtx", "#Delta#phi","eta>0 && eta>1.5");
//  createHisto(tinfoDEta,DEtaDATAEEplus, DEtaNoAlignmentEEplus, DEtaMCEEplus, trDATA, trNoAlignment, trMC, "deltaEtaSuperClusterAtVtx", "#Delta#eta","eta>0 && eta>1.5");
//  
//  
//  
//  TCanvas* cDPhiEEplus = new TCanvas("cDphiEEplus2011","cDphiEEplus2011",700,700);
//  DPhiDATAEEplus->Draw("PE");
//  DPhiNoAlignmentEEplus->Draw("PsameE");
//  DPhiMCEEplus->Draw("same");
//  tEE->Draw();
//  tinfoDPhi->Draw();
//  
//  legend->Draw();
//  cDPhiEEplus->SetGrid(); gPad->Update();   
//  cDPhiEEplus->Print("images/cDPhiEEplus.gif");
//  cDPhiEEplus->Print("images/cDPhiEEplus.pdf");
//  cDPhiEEplus->Print("images/cDPhiEEplus.png");
//  cDPhiEEplus->Print("images/cDPhiEEplus.C"); gSystem->Sleep(1);
//  cDPhiEEplus->SetLogy(); gPad->Update();
//  cDPhiEEplus->Print("images/cDPhiEEplus_logy.gif");
//  cDPhiEEplus->Print("images/cDPhiEEplus_logy.pdf");
//  cDPhiEEplus->Print("images/cDPhiEEplus_logy.png");
//  cDPhiEEplus->Print("images/cDPhiEEplus_logy.C"); gSystem->Sleep(1);
//  
//  
//  TCanvas* cDEtaEEplus = new TCanvas("cDeta2011EEplus","cDeta2011EEplus",700,700);
//  DEtaDATAEEplus->Draw("PE");
//  DEtaNoAlignmentEEplus->Draw("PsameE");
//  DEtaMCEEplus->Draw("same");
//  tEE->Draw();
//  tinfoDEta->Draw();
//  
//  legend->Draw();
//  cDEtaEEplus->SetGrid(); gPad->Update();   
//  cDEtaEEplus->Print("images/cDEtaEEplus.gif");
//  cDEtaEEplus->Print("images/cDEtaEEplus.pdf");
//  cDEtaEEplus->Print("images/cDEtaEEplus.png");
//  cDEtaEEplus->Print("images/cDEtaEEplus.C"); gSystem->Sleep(1);
//  cDEtaEEplus->SetLogy(); gPad->Update();
//  cDEtaEEplus->Print("images/cDEtaEEplus_logy.gif");
//  cDEtaEEplus->Print("images/cDEtaEEplus_logy.pdf");
//  cDEtaEEplus->Print("images/cDEtaEEplus_logy.png");
//  cDEtaEEplus->Print("images/cDEtaEEplus_logy.C"); gSystem->Sleep(1);
//  
//  
//  
//  
//  ///---- EE- ---- 
//  TH1F* DPhiDATAEEminus = new TH1F("DPhiDATAEEminus"," Data",500,-0.04,0.04);
//  TH1F* DPhiNoAlignmentEEminus   = new TH1F("DPhiNoAlignmentEEminus",  "No Alignment"  ,500,-0.04,0.04);
//  TH1F* DPhiMCEEminus   = new TH1F("DPhiMCEEminus",  " MC"  ,500,-0.04,0.04);
//  
//  TH1F* DEtaDATAEEminus = new TH1F("DEtaDATAEEminus"," Data",500,-0.02,0.02);
//  TH1F* DEtaNoAlignmentEEminus   = new TH1F("DEtaNoAlignmentEEminus"  ,"No Alignment"  ,500,-0.02,0.02);
//  TH1F* DEtaMCEEminus   = new TH1F("DEtaMCEEminus"  ," MC"  ,500,-0.02,0.02);
//  
//  createHisto(tinfoDPhi,DPhiDATAEEminus, DPhiNoAlignmentEEminus, DPhiMCEEminus, trDATA, trNoAlignment, trMC, "deltaPhiSuperClusterAtVtx", "#Delta#phi","eta<0 && eta<-1.5");
//  createHisto(tinfoDEta,DEtaDATAEEminus, DEtaNoAlignmentEEminus, DEtaMCEEminus, trDATA, trNoAlignment, trMC, "deltaEtaSuperClusterAtVtx", "#Delta#eta","eta<0 && eta<-1.5");
//  
//  
//  
//  TCanvas* cDPhiEEminus = new TCanvas("cDphiEEminus2011","cDphiEEminus2011",700,700);
//  DPhiDATAEEminus->Draw("PE");
//  DPhiNoAlignmentEEminus->Draw("PsameE");
//  DPhiMCEEminus->Draw("same");
//  tEE->Draw();
//  tinfoDPhi->Draw();
//  
//  legend->Draw();
//  cDPhiEEminus->SetGrid(); gPad->Update();   
//  cDPhiEEminus->Print("images/cDPhiEEminus.gif");
//  cDPhiEEminus->Print("images/cDPhiEEminus.pdf");
//  cDPhiEEminus->Print("images/cDPhiEEminus.png");
//  cDPhiEEminus->Print("images/cDPhiEEminus.C"); gSystem->Sleep(1);
//  cDPhiEEminus->SetLogy(); gPad->Update();
//  cDPhiEEminus->Print("images/cDPhiEEminus_logy.gif");
//  cDPhiEEminus->Print("images/cDPhiEEminus_logy.pdf");
//  cDPhiEEminus->Print("images/cDPhiEEminus_logy.png");
//  cDPhiEEminus->Print("images/cDPhiEEminus_logy.C"); gSystem->Sleep(1);
//  
//  
//  TCanvas* cDEtaEEminus = new TCanvas("cDeta2011EEminus","cDeta2011EEminus",700,700);
//  DEtaDATAEEminus->Draw("PE");
//  DEtaNoAlignmentEEminus->Draw("PsameE");
//  DEtaMCEEminus->Draw("same");
//  tEE->Draw();
//  tinfoDEta->Draw();
//  
//  legend->Draw();
//  cDEtaEEminus->SetGrid(); gPad->Update();   
//  cDEtaEEminus->Print("images/cDEtaEEminus.gif");
//  cDEtaEEminus->Print("images/cDEtaEEminus.pdf");
//  cDEtaEEminus->Print("images/cDEtaEEminus.png");
//  cDEtaEEminus->Print("images/cDEtaEEminus.C"); gSystem->Sleep(1);
//  cDEtaEEminus->SetLogy(); gPad->Update();
//  cDEtaEEminus->Print("images/cDEtaEEminus_logy.gif");
//  cDEtaEEminus->Print("images/cDEtaEEminus_logy.pdf");
//  cDEtaEEminus->Print("images/cDEtaEEminus_logy.png");
//  cDEtaEEminus->Print("images/cDEtaEEminus_logy.C"); gSystem->Sleep(1);
//  
//  
//  
//  
//  
//  ///---- electron ----
//  
//  
//  ///---- EB _eminus ----
//  TH1F* DPhiDATAEB_eminus_eminus = new TH1F("DPhiDATAEB_eminus"," Data",500,-0.04,0.04);
//  TH1F* DPhiNoAlignmentEB_eminus_eminus   = new TH1F("DPhiNoAlignmentEB_eminus",  "No Alignment"  ,500,-0.04,0.04);
//  TH1F* DPhiMCEB_eminus   = new TH1F("DPhiMCEB_eminus",  " MC"  ,500,-0.04,0.04);
//  
//  TH1F* DEtaDATAEB_eminus = new TH1F("DEtaDATAEB_eminus"," Data",500,-0.02,0.02);
//  TH1F* DEtaNoAlignmentEB_eminus   = new TH1F("DEtaNoAlignmentEB_eminus"  ,"No Alignment"  ,500,-0.02,0.02);
//  TH1F* DEtaMCEB_eminus   = new TH1F("DEtaMCEB_eminus"  ," MC"  ,500,-0.02,0.02);
//  
//  createHisto(tinfoDPhi,DPhiDATAEB_eminus, DPhiNoAlignmentEB_eminus, DPhiMCEB_eminus, trDATA, trNoAlignment, trMC, "deltaPhiSuperClusterAtVtx", "#Delta#phi","abs(eta)<1.5 && eleCharge<0");
//  createHisto(tinfoDEta,DEtaDATAEB_eminus, DEtaNoAlignmentEB_eminus, DEtaMCEB_eminus, trDATA, trNoAlignment, trMC, "deltaEtaSuperClusterAtVtx", "#Delta#eta","abs(eta)<1.5 && eleCharge<0");
//  
//  
//  
//  TCanvas* cDPhiEB_eminus = new TCanvas("cDphiEB_eminus2011","cDphiEB_eminus2011",700,700);
//  DPhiDATAEB_eminus->Draw("PE");
//  DPhiNoAlignmentEB_eminus->Draw("PsameE");
//  DPhiMCEB_eminus->Draw("same");
//  tEB->Draw();
//  tinfoDPhi->Draw();
//  
//  legend->Draw();
//  cDPhiEB_eminus->SetGrid(); gPad->Update();   
//  cDPhiEB_eminus->Print("images/cDPhiEB_eminus.gif");
//  cDPhiEB_eminus->Print("images/cDPhiEB_eminus.pdf");
//  cDPhiEB_eminus->Print("images/cDPhiEB_eminus.png");
//  cDPhiEB_eminus->Print("images/cDPhiEB_eminus.C"); gSystem->Sleep(1);
//  cDPhiEB_eminus->SetLogy(); gPad->Update();
//  cDPhiEB_eminus->Print("images/cDPhiEB_eminus_logy.gif");
//  cDPhiEB_eminus->Print("images/cDPhiEB_eminus_logy.pdf");
//  cDPhiEB_eminus->Print("images/cDPhiEB_eminus_logy.png");
//  cDPhiEB_eminus->Print("images/cDPhiEB_eminus_logy.C"); gSystem->Sleep(1);
//  
//  
//  TCanvas* cDEtaEB_eminus = new TCanvas("cDeta2011EB_eminus","cDeta2011EB_eminus",700,700);
//  DEtaDATAEB_eminus->Draw("PE");
//  DEtaNoAlignmentEB_eminus->Draw("PsameE");
//  DEtaMCEB_eminus->Draw("same");
//  tEB->Draw();
//  tinfoDEta->Draw();
//  
//  legend->Draw();
//  cDEtaEB_eminus->SetGrid(); gPad->Update();   
//  cDEtaEB_eminus->Print("images/cDEtaEB_eminus.gif");
//  cDEtaEB_eminus->Print("images/cDEtaEB_eminus.pdf");
//  cDEtaEB_eminus->Print("images/cDEtaEB_eminus.png");
//  cDEtaEB_eminus->Print("images/cDEtaEB_eminus.C"); gSystem->Sleep(1);
//  cDEtaEB_eminus->SetLogy(); gPad->Update();
//  cDEtaEB_eminus->Print("images/cDEtaEB_eminus_logy.gif");
//  cDEtaEB_eminus->Print("images/cDEtaEB_eminus_logy.pdf");
//  cDEtaEB_eminus->Print("images/cDEtaEB_eminus_logy.png");
//  cDEtaEB_eminus->Print("images/cDEtaEB_eminus_logy.C"); gSystem->Sleep(1);
//  
//  
//  
//  ///---- EB+ ----
//  TH1F* DPhiDATAEBplus_eminus = new TH1F("DPhiDATAEBplus_eminus"," Data",500,-0.04,0.04);
//  TH1F* DPhiNoAlignmentEBplus_eminus   = new TH1F("DPhiNoAlignmentEBplus_eminus",  "No Alignment"  ,500,-0.04,0.04);
//  TH1F* DPhiMCEBplus_eminus   = new TH1F("DPhiMCEBplus_eminus",  " MC"  ,500,-0.04,0.04);
//  
//  TH1F* DEtaDATAEBplus_eminus = new TH1F("DEtaDATAEBplus_eminus"," Data",500,-0.02,0.02);
//  TH1F* DEtaNoAlignmentEBplus_eminus   = new TH1F("DEtaNoAlignmentEBplus_eminus"  ,"No Alignment"  ,500,-0.02,0.02);
//  TH1F* DEtaMCEBplus_eminus   = new TH1F("DEtaMCEBplus_eminus"  ," MC"  ,500,-0.02,0.02);
//  
//  createHisto(tinfoDPhi,DPhiDATAEBplus_eminus, DPhiNoAlignmentEBplus_eminus, DPhiMCEBplus_eminus, trDATA, trNoAlignment, trMC, "deltaPhiSuperClusterAtVtx", "#Delta#phi","eta>0 && eta<1.5 && eleCharge<0");
//  createHisto(tinfoDEta,DEtaDATAEBplus_eminus, DEtaNoAlignmentEBplus_eminus, DEtaMCEBplus_eminus, trDATA, trNoAlignment, trMC, "deltaEtaSuperClusterAtVtx", "#Delta#eta","eta>0 && eta<1.5 && eleCharge<0");
//  
//  
//  
//  TCanvas* cDPhiEBplus_eminus = new TCanvas("cDphiEBplus_eminus2011","cDphiEBplus_eminus2011",700,700);
//  DPhiDATAEBplus_eminus->Draw("PE");
//  DPhiNoAlignmentEBplus_eminus->Draw("PsameE");
//  DPhiMCEBplus_eminus->Draw("same");
//  tEB->Draw();
//  tinfoDPhi->Draw();
//  
//  legend->Draw();
//  cDPhiEBplus_eminus->SetGrid(); gPad->Update();   
//  cDPhiEBplus_eminus->Print("images/cDPhiEBplus_eminus.gif");
//  cDPhiEBplus_eminus->Print("images/cDPhiEBplus_eminus.pdf");
//  cDPhiEBplus_eminus->Print("images/cDPhiEBplus_eminus.png");
//  cDPhiEBplus_eminus->Print("images/cDPhiEBplus_eminus.C"); gSystem->Sleep(1);
//  cDPhiEBplus_eminus->SetLogy(); gPad->Update();
//  cDPhiEBplus_eminus->Print("images/cDPhiEBplus_eminus_logy.gif");
//  cDPhiEBplus_eminus->Print("images/cDPhiEBplus_eminus_logy.pdf");
//  cDPhiEBplus_eminus->Print("images/cDPhiEBplus_eminus_logy.png");
//  cDPhiEBplus_eminus->Print("images/cDPhiEBplus_eminus_logy.C"); gSystem->Sleep(1);
//  
//  
//  TCanvas* cDEtaEBplus_eminus = new TCanvas("cDeta2011EBplus_eminus","cDeta2011EBplus_eminus",700,700);
//  DEtaDATAEBplus_eminus->Draw("PE");
//  DEtaNoAlignmentEBplus_eminus->Draw("PsameE");
//  DEtaMCEBplus_eminus->Draw("same");
//  tEB->Draw();
//  tinfoDEta->Draw();
//  
//  legend->Draw();
//  cDEtaEBplus_eminus->SetGrid(); gPad->Update();   
//  cDEtaEBplus_eminus->Print("images/cDEtaEBplus_eminus.gif");
//  cDEtaEBplus_eminus->Print("images/cDEtaEBplus_eminus.pdf");
//  cDEtaEBplus_eminus->Print("images/cDEtaEBplus_eminus.png");
//  cDEtaEBplus_eminus->Print("images/cDEtaEBplus_eminus.C"); gSystem->Sleep(1);
//  cDEtaEBplus_eminus->SetLogy(); gPad->Update();
//  cDEtaEBplus_eminus->Print("images/cDEtaEBplus_eminus_logy.gif");
//  cDEtaEBplus_eminus->Print("images/cDEtaEBplus_eminus_logy.pdf");
//  cDEtaEBplus_eminus->Print("images/cDEtaEBplus_eminus_logy.png");
//  cDEtaEBplus_eminus->Print("images/cDEtaEBplus_eminus_logy.C"); gSystem->Sleep(1);
//  
//  
//  
//  
//  ///---- EB- ---- 
//  TH1F* DPhiDATAEBminus_eminus = new TH1F("DPhiDATAEBminus_eminus"," Data",500,-0.04,0.04);
//  TH1F* DPhiNoAlignmentEBminus_eminus   = new TH1F("DPhiNoAlignmentEBminus_eminus",  "No Alignment"  ,500,-0.04,0.04);
//  TH1F* DPhiMCEBminus_eminus   = new TH1F("DPhiMCEBminus_eminus",  " MC"  ,500,-0.04,0.04);
//  
//  TH1F* DEtaDATAEBminus_eminus = new TH1F("DEtaDATAEBminus_eminus"," Data",500,-0.02,0.02);
//  TH1F* DEtaNoAlignmentEBminus_eminus   = new TH1F("DEtaNoAlignmentEBminus_eminus"  ,"No Alignment"  ,500,-0.02,0.02);
//  TH1F* DEtaMCEBminus_eminus   = new TH1F("DEtaMCEBminus_eminus"  ," MC"  ,500,-0.02,0.02);
//  
//  createHisto(tinfoDPhi,DPhiDATAEBminus_eminus, DPhiNoAlignmentEBminus_eminus, DPhiMCEBminus_eminus, trDATA, trNoAlignment, trMC, "deltaPhiSuperClusterAtVtx", "#Delta#phi","eta<0 && eta>-1.5 && eleCharge<0");
//  createHisto(tinfoDEta,DEtaDATAEBminus_eminus, DEtaNoAlignmentEBminus_eminus, DEtaMCEBminus_eminus, trDATA, trNoAlignment, trMC, "deltaEtaSuperClusterAtVtx", "#Delta#eta","eta<0 && eta>-1.5 && eleCharge<0");
//  
//  
//  
//  TCanvas* cDPhiEBminus_eminus = new TCanvas("cDphiEBminus_eminus2011","cDphiEBminus_eminus2011",700,700);
//  DPhiDATAEBminus_eminus->Draw("PE");
//  DPhiNoAlignmentEBminus_eminus->Draw("PsameE");
//  DPhiMCEBminus_eminus->Draw("same");
//  tEB->Draw();
//  tinfoDPhi->Draw();
//  
//  legend->Draw();
//  cDPhiEBminus_eminus->SetGrid(); gPad->Update();   
//  cDPhiEBminus_eminus->Print("images/cDPhiEBminus_eminus.gif");
//  cDPhiEBminus_eminus->Print("images/cDPhiEBminus_eminus.pdf");
//  cDPhiEBminus_eminus->Print("images/cDPhiEBminus_eminus.png");
//  cDPhiEBminus_eminus->Print("images/cDPhiEBminus_eminus.C"); gSystem->Sleep(1);
//  cDPhiEBminus_eminus->SetLogy(); gPad->Update();
//  cDPhiEBminus_eminus->Print("images/cDPhiEBminus_eminus_logy.gif");
//  cDPhiEBminus_eminus->Print("images/cDPhiEBminus_eminus_logy.pdf");
//  cDPhiEBminus_eminus->Print("images/cDPhiEBminus_eminus_logy.png");
//  cDPhiEBminus_eminus->Print("images/cDPhiEBminus_eminus_logy.C"); gSystem->Sleep(1);
//  
//  
//  TCanvas* cDEtaEBminus_eminus = new TCanvas("cDeta2011EBminus_eminus","cDeta2011EBminus_eminus",700,700);
//  DEtaDATAEBminus_eminus->Draw("PE");
//  DEtaNoAlignmentEBminus_eminus->Draw("PsameE");
//  DEtaMCEBminus_eminus->Draw("same");
//  tEB->Draw();
//  tinfoDEta->Draw();
//  
//  legend->Draw();
//  cDEtaEBminus_eminus->SetGrid(); gPad->Update();   
//  cDEtaEBminus_eminus->Print("images/cDEtaEBminus_eminus.gif");
//  cDEtaEBminus_eminus->Print("images/cDEtaEBminus_eminus.pdf");
//  cDEtaEBminus_eminus->Print("images/cDEtaEBminus_eminus.png");
//  cDEtaEBminus_eminus->Print("images/cDEtaEBminus_eminus.C"); gSystem->Sleep(1);
//  cDEtaEBminus_eminus->SetLogy(); gPad->Update();
//  cDEtaEBminus_eminus->Print("images/cDEtaEBminus_eminus_logy.gif");
//  cDEtaEBminus_eminus->Print("images/cDEtaEBminus_eminus_logy.pdf");
//  cDEtaEBminus_eminus->Print("images/cDEtaEBminus_eminus_logy.png");
//  cDEtaEBminus_eminus->Print("images/cDEtaEBminus_eminus_logy.C"); gSystem->Sleep(1);
//  
//  
//  
//  
//  
//  ///---- EE_eminus ----
//  TH1F* DPhiDATAEE_eminus = new TH1F("DPhiDATAEE_eminus"," Data",500,-0.04,0.04);
//  TH1F* DPhiNoAlignmentEE_eminus   = new TH1F("DPhiNoAlignmentEE_eminus",  "No Alignment"  ,500,-0.04,0.04);
//  TH1F* DPhiMCEE_eminus   = new TH1F("DPhiMCEE_eminus",  " MC"  ,500,-0.04,0.04);
//  
//  TH1F* DEtaDATAEE_eminus = new TH1F("DEtaDATAEE_eminus"," Data",500,-0.02,0.02);
//  TH1F* DEtaNoAlignmentEE_eminus   = new TH1F("DEtaNoAlignmentEE_eminus"  ,"No Alignment"  ,500,-0.02,0.02);
//  TH1F* DEtaMCEE_eminus   = new TH1F("DEtaMCEE_eminus"  ," MC"  ,500,-0.02,0.02);
//  
//  createHisto(tinfoDPhi,DPhiDATAEE_eminus, DPhiNoAlignmentEE_eminus, DPhiMCEE_eminus, trDATA, trNoAlignment, trMC, "deltaPhiSuperClusterAtVtx", "#Delta#phi","abs(eta)>1.5 && eleCharge<0");
//  createHisto(tinfoDEta,DEtaDATAEE_eminus, DEtaNoAlignmentEE_eminus, DEtaMCEE_eminus, trDATA, trNoAlignment, trMC, "deltaEtaSuperClusterAtVtx", "#Delta#eta","abs(eta)>1.5 && eleCharge<0");
//  
//  
//  
//  TCanvas* cDPhiEE_eminus = new TCanvas("cDphiEE_eminus2011","cDphiEE_eminus2011",700,700);
//  DPhiDATAEE_eminus->Draw("PE");
//  DPhiNoAlignmentEE_eminus->Draw("PsameE");
//  DPhiMCEE_eminus->Draw("same");
//  tEE->Draw();
//  tinfoDPhi->Draw();
//  
//  legend->Draw();
//  cDPhiEE_eminus->SetGrid(); gPad->Update();   
//  cDPhiEE_eminus->Print("images/cDPhiEE_eminus.gif");
//  cDPhiEE_eminus->Print("images/cDPhiEE_eminus.pdf");
//  cDPhiEE_eminus->Print("images/cDPhiEE_eminus.png");
//  cDPhiEE_eminus->Print("images/cDPhiEE_eminus.C"); gSystem->Sleep(1);
//  cDPhiEE_eminus->SetLogy(); gPad->Update();
//  cDPhiEE_eminus->Print("images/cDPhiEE_eminus_logy.gif");
//  cDPhiEE_eminus->Print("images/cDPhiEE_eminus_logy.pdf");
//  cDPhiEE_eminus->Print("images/cDPhiEE_eminus_logy.png");
//  cDPhiEE_eminus->Print("images/cDPhiEE_eminus_logy.C"); gSystem->Sleep(1);
//  
//  
//  TCanvas* cDEtaEE_eminus = new TCanvas("cDeta2011EE_eminus","cDeta2011EE_eminus",700,700);
//  DEtaDATAEE_eminus->Draw("PE");
//  DEtaNoAlignmentEE_eminus->Draw("PsameE");
//  DEtaMCEE_eminus->Draw("same");
//  tEE->Draw();
//  tinfoDEta->Draw();
//  
//  legend->Draw();
//  cDEtaEE_eminus->SetGrid(); gPad->Update();   
//  cDEtaEE_eminus->Print("images/cDEtaEE_eminus.gif");
//  cDEtaEE_eminus->Print("images/cDEtaEE_eminus.pdf");
//  cDEtaEE_eminus->Print("images/cDEtaEE_eminus.png");
//  cDEtaEE_eminus->Print("images/cDEtaEE_eminus.C"); gSystem->Sleep(1);
//  cDEtaEE_eminus->SetLogy(); gPad->Update();
//  cDEtaEE_eminus->Print("images/cDEtaEE_eminus_logy.gif");
//  cDEtaEE_eminus->Print("images/cDEtaEE_eminus_logy.pdf");
//  cDEtaEE_eminus->Print("images/cDEtaEE_eminus_logy.png");
//  cDEtaEE_eminus->Print("images/cDEtaEE_eminus_logy.C"); gSystem->Sleep(1);
//  
//  
//  
//  ///---- EE+ ----
//  TH1F* DPhiDATAEEplus_eminus = new TH1F("DPhiDATAEEplus_eminus"," Data",500,-0.04,0.04);
//  TH1F* DPhiNoAlignmentEEplus_eminus   = new TH1F("DPhiNoAlignmentEEplus_eminus",  "No Alignment"  ,500,-0.04,0.04);
//  TH1F* DPhiMCEEplus_eminus   = new TH1F("DPhiMCEEplus_eminus",  " MC"  ,500,-0.04,0.04);
//  
//  TH1F* DEtaDATAEEplus_eminus = new TH1F("DEtaDATAEEplus_eminus"," Data",500,-0.02,0.02);
//  TH1F* DEtaNoAlignmentEEplus_eminus   = new TH1F("DEtaNoAlignmentEEplus_eminus"  ,"No Alignment"  ,500,-0.02,0.02);
//  TH1F* DEtaMCEEplus_eminus   = new TH1F("DEtaMCEEplus_eminus"  ," MC"  ,500,-0.02,0.02);
//  
//  createHisto(tinfoDPhi,DPhiDATAEEplus_eminus, DPhiNoAlignmentEEplus_eminus, DPhiMCEEplus_eminus, trDATA, trNoAlignment, trMC, "deltaPhiSuperClusterAtVtx", "#Delta#phi","eta>0 && eta>1.5 && eleCharge<0");
//  createHisto(tinfoDEta,DEtaDATAEEplus_eminus, DEtaNoAlignmentEEplus_eminus, DEtaMCEEplus_eminus, trDATA, trNoAlignment, trMC, "deltaEtaSuperClusterAtVtx", "#Delta#eta","eta>0 && eta>1.5 && eleCharge<0");
//  
//  
//  
//  TCanvas* cDPhiEEplus_eminus = new TCanvas("cDphiEEplus_eminus2011","cDphiEEplus_eminus2011",700,700);
//  DPhiDATAEEplus_eminus->Draw("PE");
//  DPhiNoAlignmentEEplus_eminus->Draw("PsameE");
//  DPhiMCEEplus_eminus->Draw("same");
//  tEE->Draw();
//  tinfoDPhi->Draw();
//  
//  legend->Draw();
//  cDPhiEEplus_eminus->SetGrid(); gPad->Update();   
//  cDPhiEEplus_eminus->Print("images/cDPhiEEplus_eminus.gif");
//  cDPhiEEplus_eminus->Print("images/cDPhiEEplus_eminus.pdf");
//  cDPhiEEplus_eminus->Print("images/cDPhiEEplus_eminus.png");
//  cDPhiEEplus_eminus->Print("images/cDPhiEEplus_eminus.C"); gSystem->Sleep(1);
//  cDPhiEEplus_eminus->SetLogy(); gPad->Update();
//  cDPhiEEplus_eminus->Print("images/cDPhiEEplus_eminus_logy.gif");
//  cDPhiEEplus_eminus->Print("images/cDPhiEEplus_eminus_logy.pdf");
//  cDPhiEEplus_eminus->Print("images/cDPhiEEplus_eminus_logy.png");
//  cDPhiEEplus_eminus->Print("images/cDPhiEEplus_eminus_logy.C"); gSystem->Sleep(1);
//  
//  
//  TCanvas* cDEtaEEplus_eminus = new TCanvas("cDeta2011EEplus_eminus","cDeta2011EEplus_eminus",700,700);
//  DEtaDATAEEplus_eminus->Draw("PE");
//  DEtaNoAlignmentEEplus_eminus->Draw("PsameE");
//  DEtaMCEEplus_eminus->Draw("same");
//  tEE->Draw();
//  tinfoDEta->Draw();
//  
//  legend->Draw();
//  cDEtaEEplus_eminus->SetGrid(); gPad->Update();   
//  cDEtaEEplus_eminus->Print("images/cDEtaEEplus_eminus.gif");
//  cDEtaEEplus_eminus->Print("images/cDEtaEEplus_eminus.pdf");
//  cDEtaEEplus_eminus->Print("images/cDEtaEEplus_eminus.png");
//  cDEtaEEplus_eminus->Print("images/cDEtaEEplus_eminus.C"); gSystem->Sleep(1);
//  cDEtaEEplus_eminus->SetLogy(); gPad->Update();
//  cDEtaEEplus_eminus->Print("images/cDEtaEEplus_eminus_logy.gif");
//  cDEtaEEplus_eminus->Print("images/cDEtaEEplus_eminus_logy.pdf");
//  cDEtaEEplus_eminus->Print("images/cDEtaEEplus_eminus_logy.png");
//  cDEtaEEplus_eminus->Print("images/cDEtaEEplus_eminus_logy.C"); gSystem->Sleep(1);
//  
//  
//  
//  
//  ///---- EE- ---- 
//  TH1F* DPhiDATAEEminus_eminus = new TH1F("DPhiDATAEEminus_eminus"," Data",500,-0.04,0.04);
//  TH1F* DPhiNoAlignmentEEminus_eminus   = new TH1F("DPhiNoAlignmentEEminus_eminus",  "No Alignment"  ,500,-0.04,0.04);
//  TH1F* DPhiMCEEminus_eminus   = new TH1F("DPhiMCEEminus_eminus",  " MC"  ,500,-0.04,0.04);
//  
//  TH1F* DEtaDATAEEminus_eminus = new TH1F("DEtaDATAEEminus_eminus"," Data",500,-0.02,0.02);
//  TH1F* DEtaNoAlignmentEEminus_eminus   = new TH1F("DEtaNoAlignmentEEminus_eminus"  ,"No Alignment"  ,500,-0.02,0.02);
//  TH1F* DEtaMCEEminus_eminus   = new TH1F("DEtaMCEEminus_eminus"  ," MC"  ,500,-0.02,0.02);
//  
//  createHisto(tinfoDPhi,DPhiDATAEEminus_eminus, DPhiNoAlignmentEEminus_eminus, DPhiMCEEminus_eminus, trDATA, trNoAlignment, trMC, "deltaPhiSuperClusterAtVtx", "#Delta#phi","eta<0 && eta<-1.5 && eleCharge<0");
//  createHisto(tinfoDEta,DEtaDATAEEminus_eminus, DEtaNoAlignmentEEminus_eminus, DEtaMCEEminus_eminus, trDATA, trNoAlignment, trMC, "deltaEtaSuperClusterAtVtx", "#Delta#eta","eta<0 && eta<-1.5 && eleCharge<0");
//  
//  
//  
//  TCanvas* cDPhiEEminus_eminus = new TCanvas("cDphiEEminus_eminus2011","cDphiEEminus_eminus2011",700,700);
//  DPhiDATAEEminus_eminus->Draw("PE");
//  DPhiNoAlignmentEEminus_eminus->Draw("PsameE");
//  DPhiMCEEminus_eminus->Draw("same");
//  tEE->Draw();
//  tinfoDPhi->Draw();
//  
//  legend->Draw();
//  cDPhiEEminus_eminus->SetGrid(); gPad->Update();   
//  cDPhiEEminus_eminus->Print("images/cDPhiEEminus_eminus.gif");
//  cDPhiEEminus_eminus->Print("images/cDPhiEEminus_eminus.pdf");
//  cDPhiEEminus_eminus->Print("images/cDPhiEEminus_eminus.png");
//  cDPhiEEminus_eminus->Print("images/cDPhiEEminus_eminus.C"); gSystem->Sleep(1);
//  cDPhiEEminus_eminus->SetLogy(); gPad->Update();
//  cDPhiEEminus_eminus->Print("images/cDPhiEEminus_eminus_logy.gif");
//  cDPhiEEminus_eminus->Print("images/cDPhiEEminus_eminus_logy.pdf");
//  cDPhiEEminus_eminus->Print("images/cDPhiEEminus_eminus_logy.png");
//  cDPhiEEminus_eminus->Print("images/cDPhiEEminus_eminus_logy.C"); gSystem->Sleep(1);
//  
//  
//  TCanvas* cDEtaEEminus_eminus = new TCanvas("cDeta2011EEminus_eminus","cDeta2011EEminus_eminus",700,700);
//  DEtaDATAEEminus_eminus->Draw("PE");
//  DEtaNoAlignmentEEminus_eminus->Draw("PsameE");
//  DEtaMCEEminus_eminus->Draw("same");
//  tEE->Draw();
//  tinfoDEta->Draw();
//  
//  legend->Draw();
//  cDEtaEEminus_eminus->SetGrid(); gPad->Update();   
//  cDEtaEEminus_eminus->Print("images/cDEtaEEminus_eminus.gif");
//  cDEtaEEminus_eminus->Print("images/cDEtaEEminus_eminus.pdf");
//  cDEtaEEminus_eminus->Print("images/cDEtaEEminus_eminus.png");
//  cDEtaEEminus_eminus->Print("images/cDEtaEEminus_eminus.C"); gSystem->Sleep(1);
//  cDEtaEEminus_eminus->SetLogy(); gPad->Update();
//  cDEtaEEminus_eminus->Print("images/cDEtaEEminus_eminus_logy.gif");
//  cDEtaEEminus_eminus->Print("images/cDEtaEEminus_eminus_logy.pdf");
//  cDEtaEEminus_eminus->Print("images/cDEtaEEminus_eminus_logy.png");
//  cDEtaEEminus_eminus->Print("images/cDEtaEEminus_eminus_logy.C"); gSystem->Sleep(1);
//  
//  
//  
//  
//  
//  
//  
//  
//  
//  
//  
//  
//  ///---- positron ----
//  
//  
//  ///---- EB _eplus ----
//  TH1F* DPhiDATAEB_eplus_eplus = new TH1F("DPhiDATAEB_eplus"," Data",500,-0.04,0.04);
//  TH1F* DPhiNoAlignmentEB_eplus_eplus   = new TH1F("DPhiNoAlignmentEB_eplus",  "No Alignment"  ,500,-0.04,0.04);
//  TH1F* DPhiMCEB_eplus   = new TH1F("DPhiMCEB_eplus",  " MC"  ,500,-0.04,0.04);
//  
//  TH1F* DEtaDATAEB_eplus = new TH1F("DEtaDATAEB_eplus"," Data",500,-0.02,0.02);
//  TH1F* DEtaNoAlignmentEB_eplus   = new TH1F("DEtaNoAlignmentEB_eplus"  ,"No Alignment"  ,500,-0.02,0.02);
//  TH1F* DEtaMCEB_eplus   = new TH1F("DEtaMCEB_eplus"  ," MC"  ,500,-0.02,0.02);
//  
//  createHisto(tinfoDPhi,DPhiDATAEB_eplus, DPhiNoAlignmentEB_eplus, DPhiMCEB_eplus, trDATA, trNoAlignment, trMC, "deltaPhiSuperClusterAtVtx", "#Delta#phi","abs(eta)<1.5 && eleCharge>0");
//  createHisto(tinfoDEta,DEtaDATAEB_eplus, DEtaNoAlignmentEB_eplus, DEtaMCEB_eplus, trDATA, trNoAlignment, trMC, "deltaEtaSuperClusterAtVtx", "#Delta#eta","abs(eta)<1.5 && eleCharge>0");
//  
//  
//  
//  TCanvas* cDPhiEB_eplus = new TCanvas("cDphiEB_eplus2011","cDphiEB_eplus2011",700,700);
//  DPhiDATAEB_eplus->Draw("PE");
//  DPhiNoAlignmentEB_eplus->Draw("PsameE");
//  DPhiMCEB_eplus->Draw("same");
//  tEB->Draw();
//  tinfoDPhi->Draw();
//  
//  legend->Draw();
//  cDPhiEB_eplus->SetGrid(); gPad->Update();   
//  cDPhiEB_eplus->Print("images/cDPhiEB_eplus.gif");
//  cDPhiEB_eplus->Print("images/cDPhiEB_eplus.pdf");
//  cDPhiEB_eplus->Print("images/cDPhiEB_eplus.png");
//  cDPhiEB_eplus->Print("images/cDPhiEB_eplus.C"); gSystem->Sleep(1);
//  cDPhiEB_eplus->SetLogy(); gPad->Update();
//  cDPhiEB_eplus->Print("images/cDPhiEB_eplus_logy.gif");
//  cDPhiEB_eplus->Print("images/cDPhiEB_eplus_logy.pdf");
//  cDPhiEB_eplus->Print("images/cDPhiEB_eplus_logy.png");
//  cDPhiEB_eplus->Print("images/cDPhiEB_eplus_logy.C"); gSystem->Sleep(1);
//  
//  
//  TCanvas* cDEtaEB_eplus = new TCanvas("cDeta2011EB_eplus","cDeta2011EB_eplus",700,700);
//  DEtaDATAEB_eplus->Draw("PE");
//  DEtaNoAlignmentEB_eplus->Draw("PsameE");
//  DEtaMCEB_eplus->Draw("same");
//  tEB->Draw();
//  tinfoDEta->Draw();
//  
//  legend->Draw();
//  cDEtaEB_eplus->SetGrid(); gPad->Update();   
//  cDEtaEB_eplus->Print("images/cDEtaEB_eplus.gif");
//  cDEtaEB_eplus->Print("images/cDEtaEB_eplus.pdf");
//  cDEtaEB_eplus->Print("images/cDEtaEB_eplus.png");
//  cDEtaEB_eplus->Print("images/cDEtaEB_eplus.C"); gSystem->Sleep(1);
//  cDEtaEB_eplus->SetLogy(); gPad->Update();
//  cDEtaEB_eplus->Print("images/cDEtaEB_eplus_logy.gif");
//  cDEtaEB_eplus->Print("images/cDEtaEB_eplus_logy.pdf");
//  cDEtaEB_eplus->Print("images/cDEtaEB_eplus_logy.png");
//  cDEtaEB_eplus->Print("images/cDEtaEB_eplus_logy.C"); gSystem->Sleep(1);
//  
//  
//  
//  ///---- EB+ ----
//  TH1F* DPhiDATAEBplus_eplus = new TH1F("DPhiDATAEBplus_eplus"," Data",500,-0.04,0.04);
//  TH1F* DPhiNoAlignmentEBplus_eplus   = new TH1F("DPhiNoAlignmentEBplus_eplus",  "No Alignment"  ,500,-0.04,0.04);
//  TH1F* DPhiMCEBplus_eplus   = new TH1F("DPhiMCEBplus_eplus",  " MC"  ,500,-0.04,0.04);
//  
//  TH1F* DEtaDATAEBplus_eplus = new TH1F("DEtaDATAEBplus_eplus"," Data",500,-0.02,0.02);
//  TH1F* DEtaNoAlignmentEBplus_eplus   = new TH1F("DEtaNoAlignmentEBplus_eplus"  ,"No Alignment"  ,500,-0.02,0.02);
//  TH1F* DEtaMCEBplus_eplus   = new TH1F("DEtaMCEBplus_eplus"  ," MC"  ,500,-0.02,0.02);
//  
//  createHisto(tinfoDPhi,DPhiDATAEBplus_eplus, DPhiNoAlignmentEBplus_eplus, DPhiMCEBplus_eplus, trDATA, trNoAlignment, trMC, "deltaPhiSuperClusterAtVtx", "#Delta#phi","eta>0 && eta<1.5 && eleCharge>0");
//  createHisto(tinfoDEta,DEtaDATAEBplus_eplus, DEtaNoAlignmentEBplus_eplus, DEtaMCEBplus_eplus, trDATA, trNoAlignment, trMC, "deltaEtaSuperClusterAtVtx", "#Delta#eta","eta>0 && eta<1.5 && eleCharge>0");
//  
//  
//  
//  TCanvas* cDPhiEBplus_eplus = new TCanvas("cDphiEBplus_eplus2011","cDphiEBplus_eplus2011",700,700);
//  DPhiDATAEBplus_eplus->Draw("PE");
//  DPhiNoAlignmentEBplus_eplus->Draw("PsameE");
//  DPhiMCEBplus_eplus->Draw("same");
//  tEB->Draw();
//  tinfoDPhi->Draw();
//  
//  legend->Draw();
//  cDPhiEBplus_eplus->SetGrid(); gPad->Update();   
//  cDPhiEBplus_eplus->Print("images/cDPhiEBplus_eplus.gif");
//  cDPhiEBplus_eplus->Print("images/cDPhiEBplus_eplus.pdf");
//  cDPhiEBplus_eplus->Print("images/cDPhiEBplus_eplus.png");
//  cDPhiEBplus_eplus->Print("images/cDPhiEBplus_eplus.C"); gSystem->Sleep(1);
//  cDPhiEBplus_eplus->SetLogy(); gPad->Update();
//  cDPhiEBplus_eplus->Print("images/cDPhiEBplus_eplus_logy.gif");
//  cDPhiEBplus_eplus->Print("images/cDPhiEBplus_eplus_logy.pdf");
//  cDPhiEBplus_eplus->Print("images/cDPhiEBplus_eplus_logy.png");
//  cDPhiEBplus_eplus->Print("images/cDPhiEBplus_eplus_logy.C"); gSystem->Sleep(1);
//  
//  
//  TCanvas* cDEtaEBplus_eplus = new TCanvas("cDeta2011EBplus_eplus","cDeta2011EBplus_eplus",700,700);
//  DEtaDATAEBplus_eplus->Draw("PE");
//  DEtaNoAlignmentEBplus_eplus->Draw("PsameE");
//  DEtaMCEBplus_eplus->Draw("same");
//  tEB->Draw();
//  tinfoDEta->Draw();
//  
//  legend->Draw();
//  cDEtaEBplus_eplus->SetGrid(); gPad->Update();   
//  cDEtaEBplus_eplus->Print("images/cDEtaEBplus_eplus.gif");
//  cDEtaEBplus_eplus->Print("images/cDEtaEBplus_eplus.pdf");
//  cDEtaEBplus_eplus->Print("images/cDEtaEBplus_eplus.png");
//  cDEtaEBplus_eplus->Print("images/cDEtaEBplus_eplus.C"); gSystem->Sleep(1);
//  cDEtaEBplus_eplus->SetLogy(); gPad->Update();
//  cDEtaEBplus_eplus->Print("images/cDEtaEBplus_eplus_logy.gif");
//  cDEtaEBplus_eplus->Print("images/cDEtaEBplus_eplus_logy.pdf");
//  cDEtaEBplus_eplus->Print("images/cDEtaEBplus_eplus_logy.png");
//  cDEtaEBplus_eplus->Print("images/cDEtaEBplus_eplus_logy.C"); gSystem->Sleep(1);
//  
//  
//  
//  
//  ///---- EB- ---- 
//  TH1F* DPhiDATAEBminus_eplus = new TH1F("DPhiDATAEBminus_eplus"," Data",500,-0.04,0.04);
//  TH1F* DPhiNoAlignmentEBminus_eplus   = new TH1F("DPhiNoAlignmentEBminus_eplus",  "No Alignment"  ,500,-0.04,0.04);
//  TH1F* DPhiMCEBminus_eplus   = new TH1F("DPhiMCEBminus_eplus",  " MC"  ,500,-0.04,0.04);
//  
//  TH1F* DEtaDATAEBminus_eplus = new TH1F("DEtaDATAEBminus_eplus"," Data",500,-0.02,0.02);
//  TH1F* DEtaNoAlignmentEBminus_eplus   = new TH1F("DEtaNoAlignmentEBminus_eplus"  ,"No Alignment"  ,500,-0.02,0.02);
//  TH1F* DEtaMCEBminus_eplus   = new TH1F("DEtaMCEBminus_eplus"  ," MC"  ,500,-0.02,0.02);
//  
//  createHisto(tinfoDPhi,DPhiDATAEBminus_eplus, DPhiNoAlignmentEBminus_eplus, DPhiMCEBminus_eplus, trDATA, trNoAlignment, trMC, "deltaPhiSuperClusterAtVtx", "#Delta#phi","eta<0 && eta>-1.5 && eleCharge>0");
//  createHisto(tinfoDEta,DEtaDATAEBminus_eplus, DEtaNoAlignmentEBminus_eplus, DEtaMCEBminus_eplus, trDATA, trNoAlignment, trMC, "deltaEtaSuperClusterAtVtx", "#Delta#eta","eta<0 && eta>-1.5 && eleCharge>0");
//  
//  
//  
//  TCanvas* cDPhiEBminus_eplus = new TCanvas("cDphiEBminus_eplus2011","cDphiEBminus_eplus2011",700,700);
//  DPhiDATAEBminus_eplus->Draw("PE");
//  DPhiNoAlignmentEBminus_eplus->Draw("PsameE");
//  DPhiMCEBminus_eplus->Draw("same");
//  tEB->Draw();
//  tinfoDPhi->Draw();
//  
//  legend->Draw();
//  cDPhiEBminus_eplus->SetGrid(); gPad->Update();   
//  cDPhiEBminus_eplus->Print("images/cDPhiEBminus_eplus.gif");
//  cDPhiEBminus_eplus->Print("images/cDPhiEBminus_eplus.pdf");
//  cDPhiEBminus_eplus->Print("images/cDPhiEBminus_eplus.png");
//  cDPhiEBminus_eplus->Print("images/cDPhiEBminus_eplus.C"); gSystem->Sleep(1);
//  cDPhiEBminus_eplus->SetLogy(); gPad->Update();
//  cDPhiEBminus_eplus->Print("images/cDPhiEBminus_eplus_logy.gif");
//  cDPhiEBminus_eplus->Print("images/cDPhiEBminus_eplus_logy.pdf");
//  cDPhiEBminus_eplus->Print("images/cDPhiEBminus_eplus_logy.png");
//  cDPhiEBminus_eplus->Print("images/cDPhiEBminus_eplus_logy.C"); gSystem->Sleep(1);
//  
//  
//  TCanvas* cDEtaEBminus_eplus = new TCanvas("cDeta2011EBminus_eplus","cDeta2011EBminus_eplus",700,700);
//  DEtaDATAEBminus_eplus->Draw("PE");
//  DEtaNoAlignmentEBminus_eplus->Draw("PsameE");
//  DEtaMCEBminus_eplus->Draw("same");
//  tEB->Draw();
//  tinfoDEta->Draw();
//  
//  legend->Draw();
//  cDEtaEBminus_eplus->SetGrid(); gPad->Update();   
//  cDEtaEBminus_eplus->Print("images/cDEtaEBminus_eplus.gif");
//  cDEtaEBminus_eplus->Print("images/cDEtaEBminus_eplus.pdf");
//  cDEtaEBminus_eplus->Print("images/cDEtaEBminus_eplus.png");
//  cDEtaEBminus_eplus->Print("images/cDEtaEBminus_eplus.C"); gSystem->Sleep(1);
//  cDEtaEBminus_eplus->SetLogy(); gPad->Update();
//  cDEtaEBminus_eplus->Print("images/cDEtaEBminus_eplus_logy.gif");
//  cDEtaEBminus_eplus->Print("images/cDEtaEBminus_eplus_logy.pdf");
//  cDEtaEBminus_eplus->Print("images/cDEtaEBminus_eplus_logy.png");
//  cDEtaEBminus_eplus->Print("images/cDEtaEBminus_eplus_logy.C"); gSystem->Sleep(1);
//  
//  
//  
//  
//  
//  ///---- EE_eplus ----
//  TH1F* DPhiDATAEE_eplus = new TH1F("DPhiDATAEE_eplus"," Data",500,-0.04,0.04);
//  TH1F* DPhiNoAlignmentEE_eplus   = new TH1F("DPhiNoAlignmentEE_eplus",  "No Alignment"  ,500,-0.04,0.04);
//  TH1F* DPhiMCEE_eplus   = new TH1F("DPhiMCEE_eplus",  " MC"  ,500,-0.04,0.04);
//  
//  TH1F* DEtaDATAEE_eplus = new TH1F("DEtaDATAEE_eplus"," Data",500,-0.02,0.02);
//  TH1F* DEtaNoAlignmentEE_eplus   = new TH1F("DEtaNoAlignmentEE_eplus"  ,"No Alignment"  ,500,-0.02,0.02);
//  TH1F* DEtaMCEE_eplus   = new TH1F("DEtaMCEE_eplus"  ," MC"  ,500,-0.02,0.02);
//  
//  createHisto(tinfoDPhi,DPhiDATAEE_eplus, DPhiNoAlignmentEE_eplus, DPhiMCEE_eplus, trDATA, trNoAlignment, trMC, "deltaPhiSuperClusterAtVtx", "#Delta#phi","abs(eta)>1.5 && eleCharge>0");
//  createHisto(tinfoDEta,DEtaDATAEE_eplus, DEtaNoAlignmentEE_eplus, DEtaMCEE_eplus, trDATA, trNoAlignment, trMC, "deltaEtaSuperClusterAtVtx", "#Delta#eta","abs(eta)>1.5 && eleCharge>0");
//  
//  
//  
//  TCanvas* cDPhiEE_eplus = new TCanvas("cDphiEE_eplus2011","cDphiEE_eplus2011",700,700);
//  DPhiDATAEE_eplus->Draw("PE");
//  DPhiNoAlignmentEE_eplus->Draw("PsameE");
//  DPhiMCEE_eplus->Draw("same");
//  tEE->Draw();
//  tinfoDPhi->Draw();
//  
//  legend->Draw();
//  cDPhiEE_eplus->SetGrid(); gPad->Update();   
//  cDPhiEE_eplus->Print("images/cDPhiEE_eplus.gif");
//  cDPhiEE_eplus->Print("images/cDPhiEE_eplus.pdf");
//  cDPhiEE_eplus->Print("images/cDPhiEE_eplus.png");
//  cDPhiEE_eplus->Print("images/cDPhiEE_eplus.C"); gSystem->Sleep(1);
//  cDPhiEE_eplus->SetLogy(); gPad->Update();
//  cDPhiEE_eplus->Print("images/cDPhiEE_eplus_logy.gif");
//  cDPhiEE_eplus->Print("images/cDPhiEE_eplus_logy.pdf");
//  cDPhiEE_eplus->Print("images/cDPhiEE_eplus_logy.png");
//  cDPhiEE_eplus->Print("images/cDPhiEE_eplus_logy.C"); gSystem->Sleep(1);
//  
//  
//  TCanvas* cDEtaEE_eplus = new TCanvas("cDeta2011EE_eplus","cDeta2011EE_eplus",700,700);
//  DEtaDATAEE_eplus->Draw("PE");
//  DEtaNoAlignmentEE_eplus->Draw("PsameE");
//  DEtaMCEE_eplus->Draw("same");
//  tEE->Draw();
//  tinfoDEta->Draw();
//  
//  legend->Draw();
//  cDEtaEE_eplus->SetGrid(); gPad->Update();   
//  cDEtaEE_eplus->Print("images/cDEtaEE_eplus.gif");
//  cDEtaEE_eplus->Print("images/cDEtaEE_eplus.pdf");
//  cDEtaEE_eplus->Print("images/cDEtaEE_eplus.png");
//  cDEtaEE_eplus->Print("images/cDEtaEE_eplus.C"); gSystem->Sleep(1);
//  cDEtaEE_eplus->SetLogy(); gPad->Update();
//  cDEtaEE_eplus->Print("images/cDEtaEE_eplus_logy.gif");
//  cDEtaEE_eplus->Print("images/cDEtaEE_eplus_logy.pdf");
//  cDEtaEE_eplus->Print("images/cDEtaEE_eplus_logy.png");
//  cDEtaEE_eplus->Print("images/cDEtaEE_eplus_logy.C"); gSystem->Sleep(1);
//  
//  
//  
//  ///---- EE+ ----
//  TH1F* DPhiDATAEEplus_eplus = new TH1F("DPhiDATAEEplus_eplus"," Data",500,-0.04,0.04);
//  TH1F* DPhiNoAlignmentEEplus_eplus   = new TH1F("DPhiNoAlignmentEEplus_eplus",  "No Alignment"  ,500,-0.04,0.04);
//  TH1F* DPhiMCEEplus_eplus   = new TH1F("DPhiMCEEplus_eplus",  " MC"  ,500,-0.04,0.04);
//  
//  TH1F* DEtaDATAEEplus_eplus = new TH1F("DEtaDATAEEplus_eplus"," Data",500,-0.02,0.02);
//  TH1F* DEtaNoAlignmentEEplus_eplus   = new TH1F("DEtaNoAlignmentEEplus_eplus"  ,"No Alignment"  ,500,-0.02,0.02);
//  TH1F* DEtaMCEEplus_eplus   = new TH1F("DEtaMCEEplus_eplus"  ," MC"  ,500,-0.02,0.02);
//  
//  createHisto(tinfoDPhi,DPhiDATAEEplus_eplus, DPhiNoAlignmentEEplus_eplus, DPhiMCEEplus_eplus, trDATA, trNoAlignment, trMC, "deltaPhiSuperClusterAtVtx", "#Delta#phi","eta>0 && eta>1.5 && eleCharge>0");
//  createHisto(tinfoDEta,DEtaDATAEEplus_eplus, DEtaNoAlignmentEEplus_eplus, DEtaMCEEplus_eplus, trDATA, trNoAlignment, trMC, "deltaEtaSuperClusterAtVtx", "#Delta#eta","eta>0 && eta>1.5 && eleCharge>0");
//  
//  
//  
//  TCanvas* cDPhiEEplus_eplus = new TCanvas("cDphiEEplus_eplus2011","cDphiEEplus_eplus2011",700,700);
//  DPhiDATAEEplus_eplus->Draw("PE");
//  DPhiNoAlignmentEEplus_eplus->Draw("PsameE");
//  DPhiMCEEplus_eplus->Draw("same");
//  tEE->Draw();
//  tinfoDPhi->Draw();
//  
//  legend->Draw();
//  cDPhiEEplus_eplus->SetGrid(); gPad->Update();   
//  cDPhiEEplus_eplus->Print("images/cDPhiEEplus_eplus.gif");
//  cDPhiEEplus_eplus->Print("images/cDPhiEEplus_eplus.pdf");
//  cDPhiEEplus_eplus->Print("images/cDPhiEEplus_eplus.png");
//  cDPhiEEplus_eplus->Print("images/cDPhiEEplus_eplus.C"); gSystem->Sleep(1);
//  cDPhiEEplus_eplus->SetLogy(); gPad->Update();
//  cDPhiEEplus_eplus->Print("images/cDPhiEEplus_eplus_logy.gif");
//  cDPhiEEplus_eplus->Print("images/cDPhiEEplus_eplus_logy.pdf");
//  cDPhiEEplus_eplus->Print("images/cDPhiEEplus_eplus_logy.png");
//  cDPhiEEplus_eplus->Print("images/cDPhiEEplus_eplus_logy.C"); gSystem->Sleep(1);
//  
//  
//  TCanvas* cDEtaEEplus_eplus = new TCanvas("cDeta2011EEplus_eplus","cDeta2011EEplus_eplus",700,700);
//  DEtaDATAEEplus_eplus->Draw("PE");
//  DEtaNoAlignmentEEplus_eplus->Draw("PsameE");
//  DEtaMCEEplus_eplus->Draw("same");
//  tEE->Draw();
//  tinfoDEta->Draw();
//  
//  legend->Draw();
//  cDEtaEEplus_eplus->SetGrid(); gPad->Update();   
//  cDEtaEEplus_eplus->Print("images/cDEtaEEplus_eplus.gif");
//  cDEtaEEplus_eplus->Print("images/cDEtaEEplus_eplus.pdf");
//  cDEtaEEplus_eplus->Print("images/cDEtaEEplus_eplus.png");
//  cDEtaEEplus_eplus->Print("images/cDEtaEEplus_eplus.C"); gSystem->Sleep(1);
//  cDEtaEEplus_eplus->SetLogy(); gPad->Update();
//  cDEtaEEplus_eplus->Print("images/cDEtaEEplus_eplus_logy.gif");
//  cDEtaEEplus_eplus->Print("images/cDEtaEEplus_eplus_logy.pdf");
//  cDEtaEEplus_eplus->Print("images/cDEtaEEplus_eplus_logy.png");
//  cDEtaEEplus_eplus->Print("images/cDEtaEEplus_eplus_logy.C"); gSystem->Sleep(1);
//  
//  
//  
//  
//  ///---- EE- ---- 
//  TH1F* DPhiDATAEEminus_eplus = new TH1F("DPhiDATAEEminus_eplus"," Data",500,-0.04,0.04);
//  TH1F* DPhiNoAlignmentEEminus_eplus   = new TH1F("DPhiNoAlignmentEEminus_eplus",  "No Alignment"  ,500,-0.04,0.04);
//  TH1F* DPhiMCEEminus_eplus   = new TH1F("DPhiMCEEminus_eplus",  " MC"  ,500,-0.04,0.04);
//  
//  TH1F* DEtaDATAEEminus_eplus = new TH1F("DEtaDATAEEminus_eplus"," Data",500,-0.02,0.02);
//  TH1F* DEtaNoAlignmentEEminus_eplus   = new TH1F("DEtaNoAlignmentEEminus_eplus"  ,"No Alignment"  ,500,-0.02,0.02);
//  TH1F* DEtaMCEEminus_eplus   = new TH1F("DEtaMCEEminus_eplus"  ," MC"  ,500,-0.02,0.02);
//  
//  createHisto(tinfoDPhi,DPhiDATAEEminus_eplus, DPhiNoAlignmentEEminus_eplus, DPhiMCEEminus_eplus, trDATA, trNoAlignment, trMC, "deltaPhiSuperClusterAtVtx", "#Delta#phi","eta<0 && eta<-1.5 && eleCharge>0");
//  createHisto(tinfoDEta,DEtaDATAEEminus_eplus, DEtaNoAlignmentEEminus_eplus, DEtaMCEEminus_eplus, trDATA, trNoAlignment, trMC, "deltaEtaSuperClusterAtVtx", "#Delta#eta","eta<0 && eta<-1.5 && eleCharge>0");
//  
//  
//  
//  TCanvas* cDPhiEEminus_eplus = new TCanvas("cDphiEEminus_eplus2011","cDphiEEminus_eplus2011",700,700);
//  DPhiDATAEEminus_eplus->Draw("PE");
//  DPhiNoAlignmentEEminus_eplus->Draw("PsameE");
//  DPhiMCEEminus_eplus->Draw("same");
//  tEE->Draw();
//  tinfoDPhi->Draw();
//  
//  legend->Draw();
//  cDPhiEEminus_eplus->SetGrid(); gPad->Update();   
//  cDPhiEEminus_eplus->Print("images/cDPhiEEminus_eplus.gif");
//  cDPhiEEminus_eplus->Print("images/cDPhiEEminus_eplus.pdf");
//  cDPhiEEminus_eplus->Print("images/cDPhiEEminus_eplus.png");
//  cDPhiEEminus_eplus->Print("images/cDPhiEEminus_eplus.C"); gSystem->Sleep(1);
//  cDPhiEEminus_eplus->SetLogy(); gPad->Update();
//  cDPhiEEminus_eplus->Print("images/cDPhiEEminus_eplus_logy.gif");
//  cDPhiEEminus_eplus->Print("images/cDPhiEEminus_eplus_logy.pdf");
//  cDPhiEEminus_eplus->Print("images/cDPhiEEminus_eplus_logy.png");
//  cDPhiEEminus_eplus->Print("images/cDPhiEEminus_eplus_logy.C"); gSystem->Sleep(1);
//  
//  
//  TCanvas* cDEtaEEminus_eplus = new TCanvas("cDeta2011EEminus_eplus","cDeta2011EEminus_eplus",700,700);
//  DEtaDATAEEminus_eplus->Draw("PE");
//  DEtaNoAlignmentEEminus_eplus->Draw("PsameE");
//  DEtaMCEEminus_eplus->Draw("same");
//  tEE->Draw();
//  tinfoDEta->Draw();
//  
//  legend->Draw();
//  cDEtaEEminus_eplus->SetGrid(); gPad->Update();   
//  cDEtaEEminus_eplus->Print("images/cDEtaEEminus_eplus.gif");
//  cDEtaEEminus_eplus->Print("images/cDEtaEEminus_eplus.pdf");
//  cDEtaEEminus_eplus->Print("images/cDEtaEEminus_eplus.png");
//  cDEtaEEminus_eplus->Print("images/cDEtaEEminus_eplus.C"); gSystem->Sleep(1);
//  cDEtaEEminus_eplus->SetLogy(); gPad->Update();
//  cDEtaEEminus_eplus->Print("images/cDEtaEEminus_eplus_logy.gif");
//  cDEtaEEminus_eplus->Print("images/cDEtaEEminus_eplus_logy.pdf");
//  cDEtaEEminus_eplus->Print("images/cDEtaEEminus_eplus_logy.png");
//  cDEtaEEminus_eplus->Print("images/cDEtaEEminus_eplus_logy.C"); gSystem->Sleep(1);
//  
//  
//  
//  
//  
//  
//  
//  ///---- eta distribution ----
//  TH1F* EtaDATA = new TH1F("EtaDATA","#eta Data",100,-5.0,5.0);
//  TH1F* EtaNoAlignment   = new TH1F("EtaNoAlignment",  "#etaNo Alignment"  ,100,-5.0,5.0);
//  TH1F* EtaMC = new TH1F("EtaMC","#eta MC",100,-5.0,5.0);
//  
//  createHisto(tinfoDEta,EtaDATA, EtaNoAlignment, EtaMC, trDATA, trNoAlignment, trMC, "etaSC", "#eta_{SC}","1"); 
//  
//  TCanvas* cEta = new TCanvas("cEta","cEta",700,700);
//  EtaDATA -> Draw("PE");
//  EtaNoAlignment   -> Draw("PsameE");
//  EtaMC -> Draw("same");
//  
//  legend->Draw();
//  cEta->SetGrid(); gPad->Update();   
//  //  cEta->Print("cEta.gif");
//  //  cEta->Print("cEta.pdf");
//  //  cEta->Print("cEta.png");
//  //  cEta->Print("images/cEta.C"); gSystem->Sleep(1);
//  
//  
//  
//  
//  
//  std::cout << " Differences " << std::endl;
//  
//  //  std::cout << " DPhi V7 = " << DPhiV7->GetMean() << " +/- " << DPhiV7->GetRMS() / sqrt(DPhiV7->GetEntries()) << std::endl;
//  //  std::cout << " DPhi V8 = " << DPhiV8->GetMean() << " +/- " << DPhiV8->GetRMS() / sqrt(DPhiV8->GetEntries()) << std::endl;
//  //  
//  //  std::cout << " DEta V7 = " << DEtaV7->GetMean() << " +/- " << DEtaV7->GetRMS() / sqrt(DEtaV7->GetEntries()) << std::endl;
//  //  std::cout << " DEta V8 = " << DEtaV8->GetMean() << " +/- " << DEtaV8->GetRMS() / sqrt(DEtaV8->GetEntries()) << std::endl;
 
 
//  gApplication->Terminate(0);
 
}