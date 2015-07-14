#include "TDRStyle.cc"

#include "Functions.h"

void drawSingleModule(TString nameInFileRoot, TString nameOutputDir, TString commonCut = "1", int iEB=-100, int iEE=-100 ){
 TDRStyle();
 
 gStyle->SetTitleYOffset(1.1);
 gStyle->cd();
 
 //---- correct cut
 TString CompleteCut;
 
 if (iEB != -100) {
  CompleteCut = Form("(%s) * (iDetEB == %d)", commonCut.Data(), iEB);
 }
 if (iEE != -100) {
  CompleteCut = Form("(%s) * (iDetEE == %d)", commonCut.Data(), iEE);
 }
 //---- ---- ---- 
 
 TChain* trMC   = new TChain("ntupleEcalAlignment/myTree");
 trMC->Add(nameInFileRoot.Data());
 
 std::string FunctionDetaName = "(x>0.0 && x<1.5)   * (-(0.4e-3)) \
 + (x>1.5 && x<2.0)   * (2.45513e-03*(x-1.75)) \
 + (x>2.0)            * ((6.137825e-04)/2.) \
 + (x<0.0 && x>-1.5)  * (0.4e-3) \
 + (x<-1.5 && x>-2.0) * (2.45513e-03*(x+1.75)) \
 + (x<-2.0)           * ((-6.137825e-04)/2.)"; 
 
 TF1* FunctionDeta = new TF1 ("DetaBias",FunctionDetaName.c_str(),-5,5);
 FunctionDeta->SetLineColor(kBlack);
 FunctionDeta->SetLineStyle(2);
 FunctionDeta->SetLineWidth(4);
 
 
 std::string FunctionDphiName_ep = "(x>0.0 && x<1.5)   * (1.46233e-03) \
 + (x>1.5)            * (2.73084e-03) \
 + (x<0.0 && x>-1.5)  * (6.59298e-04) \
 + (x<-1.5)           * (2.57010e-03)";
 
 TF1* FunctionDphi_ep = new TF1 ("DphiBias_ep",FunctionDphiName_ep.c_str(),-5,5);
 FunctionDphi_ep->SetLineColor(kBlack);
 FunctionDphi_ep->SetLineStyle(2);
 FunctionDphi_ep->SetLineWidth(4);
 
 
 
 std::string FunctionDphiName_em = "(x>0.0 && x<1.5)   * (-7.24105e-04) \
 + (x>1.5)            * (-1.992615e-03) \
 + (x<0.0 && x>-1.5)  * (-1.527137e-03) \
 + (x<-1.5)           * (-3.437939e-03)";
 
 TF1* FunctionDphi_em = new TF1 ("DphiBias_em",FunctionDphiName_em.c_str(),-5,5);
 FunctionDphi_em->SetLineColor(kBlack);
 FunctionDphi_em->SetLineStyle(2);
 FunctionDphi_em->SetLineWidth(4);
 
 
 ///---- all ----
 TH1F* DPhiMC     = new TH1F("DPhiMC",     " MC"  ,200,-0.04,0.04);
 TH1F* DPhiMC_ep  = new TH1F("DPhiMC_ep",  " MC"  ,200,-0.04,0.04);
 TH1F* DPhiMC_em  = new TH1F("DPhiMC_em",  " MC"  ,200,-0.04,0.04);
 TH1F* DEtaMC     = new TH1F("DEtaMC"     ," MC"  ,200,-0.02,0.02);
 
 ///---- text info (begin) ----
 TLatex*  tinfoDPhi    = new TLatex(0.2,0.8,"");
 TLatex*  tinfoDEta    = new TLatex(0.2,0.8,"");
 TLatex*  tinfoDPhi_ep = new TLatex(0.2,0.8,"");
 TLatex*  tinfoDPhi_em = new TLatex(0.2,0.8,"");
 ///---- text info (end) ----
 
 createHisto(tinfoDPhi, DPhiMC, trMC, "deltaPhiSuperClusterAtVtx", "#Delta#phi",CompleteCut.Data());
 createHisto(tinfoDEta, DEtaMC, trMC, "deltaEtaSuperClusterAtVtx", "#Delta#eta",CompleteCut.Data());
 
 TString CompleteCut_ep = Form ("(%s) && (eleCharge>0)",CompleteCut.Data());
 TString CompleteCut_em = Form ("(%s) && (eleCharge<0)",CompleteCut.Data());
 
 createHisto(tinfoDPhi_ep, DPhiMC_ep, trMC, "deltaPhiSuperClusterAtVtx", "#Delta#phi",CompleteCut_ep.Data());
 createHisto(tinfoDPhi_em, DPhiMC_em, trMC, "deltaPhiSuperClusterAtVtx", "#Delta#phi",CompleteCut_em.Data());
 
 
 
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
 
 TString toDoShell;
//  toDoShell = Form("rm -r %s ;",nameOutputDir.Data());
//  system(toDoShell.Data());
 toDoShell = Form("mkdir %s ;",nameOutputDir.Data());
 system(toDoShell.Data());
 toDoShell = Form("mkdir %s/images ;",nameOutputDir.Data());
 system(toDoShell.Data());
 toDoShell = Form("cp index.php %s/images ;",nameOutputDir.Data());
 system(toDoShell.Data());
 
 
 TCanvas* cDPhi = new TCanvas("cDphi","cDphi",700,700);
 DPhiMC->Draw("PE");
 tinfoDPhi->Draw();
 gPad->SetGrid();
 toDoShell = Form("%s/images/cDphi_%d_%d.png",nameOutputDir.Data(), iEB, iEE);
 gPad->SaveAs(toDoShell.Data());
 
 TCanvas* cDPhi_ep = new TCanvas("cDPhi_ep","cDPhi_ep",700,700);
 DPhiMC_ep->Draw("PE");
 tinfoDPhi_ep->Draw();
 gPad->SetGrid();
 toDoShell = Form("%s/images/cDPhi_ep_%d_%d.png",nameOutputDir.Data(), iEB, iEE);
 gPad->SaveAs(toDoShell.Data());
 
 TCanvas* cDPhi_em = new TCanvas("cDPhi_em","cDPhi_em",700,700);
 DPhiMC_em->Draw("PE");
 tinfoDPhi_em->Draw();
 gPad->SetGrid();
 toDoShell = Form("%s/images/cDPhi_em_%d_%d.png",nameOutputDir.Data(), iEB, iEE);
 gPad->SaveAs(toDoShell.Data());
 
 
 
 legend->Draw();
 cDPhi->SetGrid(); gPad->Update();
 
 TCanvas* cDEta = new TCanvas("cDeta","cDeta",700,700);
 DEtaMC->Draw("PE");
 tinfoDEta->Draw();
 legend->Draw();
 cDEta->SetGrid(); gPad->Update();   
 toDoShell = Form("%s/images/cDEta_%d_%d.png",nameOutputDir.Data(), iEB, iEE);
 gPad->SaveAs(toDoShell.Data());
 
 
 ///---- 2D plot vs eta ----
 TH2F* DPhiMCvsEta_ep = new TH2F("DPhiMCvsEta_ep",  "MC"  , 40,-3,3,  200,-0.04,0.04);
 TH2F* DPhiMCvsEta_em = new TH2F("DPhiMCvsEta_em",  "MC"  , 40,-3,3,  200,-0.04,0.04);
 TH2F* DPhiMCvsEta    = new TH2F("DPhiMCvsEta",  "MC"  , 80,-3,3,  200,-0.04,0.04);
 TH2F* DEtaMCvsEta    = new TH2F("DEtaMCvsEta"  ,"MC"  , 80,-3,3,  200,-0.04,0.04);
 createHisto2D(DPhiMCvsEta_ep, trMC, "deltaPhiSuperClusterAtVtx", "etaSC", "#Delta#phi vs #eta_{SC}",CompleteCut_ep.Data());
 createHisto2D(DPhiMCvsEta_em, trMC, "deltaPhiSuperClusterAtVtx", "etaSC", "#Delta#phi vs #eta_{SC}",CompleteCut_em.Data());
 createHisto2D(DPhiMCvsEta,    trMC, "deltaPhiSuperClusterAtVtx", "etaSC", "#Delta#phi vs #eta_{SC}",CompleteCut.Data());
 createHisto2D(DEtaMCvsEta,    trMC, "deltaEtaSuperClusterAtVtx", "etaSC", "#Delta#eta vs #eta_{SC}",CompleteCut.Data());
 
 TProfile* DPhiMCvsEta_ep_tx = (TProfile*) DPhiMCvsEta_ep->ProfileX();
 TProfile* DPhiMCvsEta_em_tx = (TProfile*) DPhiMCvsEta_em->ProfileX();
 TProfile* DPhiMCvsEta_tx    = (TProfile*) DPhiMCvsEta->ProfileX();
 TProfile* DEtaMCvsEta_tx    = (TProfile*) DEtaMCvsEta->ProfileX();
 
 TCanvas* cDPhivsEta_ep = new TCanvas("cDphivsEta_ep","cDphivsEta_ep",700,700);
 DPhiMCvsEta_ep->Draw("colz");
 DPhiMCvsEta_ep_tx->Draw("same");
 gPad->SetGrid();
 FunctionDphi_ep->Draw("same");
 toDoShell = Form("%s/images/cDPhivsEta_ep_%d_%d.png",nameOutputDir.Data(), iEB, iEE);
 gPad->SaveAs(toDoShell.Data());
 
 TCanvas* cDPhivsEta_em = new TCanvas("cDphivsEta_em","cDphivsEta_em",700,700);
 DPhiMCvsEta_em->Draw("colz");
 DPhiMCvsEta_em_tx->Draw("same");
 gPad->SetGrid();
 FunctionDphi_em->Draw("same");
 toDoShell = Form("%s/images/cDPhivsEta_em_%d_%d.png",nameOutputDir.Data(), iEB, iEE);
 gPad->SaveAs(toDoShell.Data());
 
 TCanvas* cDPhivsEta = new TCanvas("cDphivsEta","cDphivsEta",700,700);
 DPhiMCvsEta->Draw("colz");
 DPhiMCvsEta_tx->Draw("same");
 gPad->SetGrid();
 toDoShell = Form("%s/images/cDPhivsEta_%d_%d.png",nameOutputDir.Data(), iEB, iEE);
 gPad->SaveAs(toDoShell.Data());
 
 TCanvas* cDEtavsEta = new TCanvas("cDetavsEta","cDetavsEta",700,700);
 DEtaMCvsEta->Draw("colz");
 DEtaMCvsEta_tx->Draw("same");
 gPad->SetGrid();
 FunctionDeta->Draw("same");
 toDoShell = Form("%s/images/cDEtavsEta_%d_%d.png",nameOutputDir.Data(), iEB, iEE);
 gPad->SaveAs(toDoShell.Data());
 
 
 
 ///---- 2D plot dphi/deta in EB ----
 
 TString CompleteCut_EB = Form ("(%s) && (iDetEE < -10)",CompleteCut.Data());
 TString CompleteCut_EB_ep = Form ("(%s) && (iDetEE < -10)",CompleteCut_ep.Data());
 TString CompleteCut_EB_em = Form ("(%s) && (iDetEE < -10)",CompleteCut_em.Data());
 
 TH2F* DPhiMCvsPhi_EB_ep = new TH2F("DPhiMCvsPhi_EB_ep",  "MC"  , 36,-3.15,3.15,  200,-0.04,0.04);
 TH2F* DPhiMCvsPhi_EB_em = new TH2F("DPhiMCvsPhi_EB_em",  "MC"  , 36,-3.15,3.15,  200,-0.04,0.04);
 TH2F* DPhiMCvsPhi_EB    = new TH2F("DPhiMCvsPhi_EB",  "MC"  , 36,-3.15,3.15,  200,-0.04,0.04);
 TH2F* DEtaMCvsPhi_EB    = new TH2F("DEtaMCvsPhi_EB"  ,"MC"  , 36,-3.15,3.15,  200,-0.04,0.04);
 
 createHisto2D(DPhiMCvsPhi_EB_ep, trMC, "deltaPhiSuperClusterAtVtx", "phiSC", "#Delta#phi vs #phi_{SC}",CompleteCut_EB_ep.Data());
 createHisto2D(DPhiMCvsPhi_EB_em, trMC, "deltaPhiSuperClusterAtVtx", "phiSC", "#Delta#phi vs #phi_{SC}",CompleteCut_EB_em.Data());
 createHisto2D(DPhiMCvsPhi_EB, trMC, "deltaPhiSuperClusterAtVtx", "phiSC", "#Delta#phi vs #phi_{SC}",CompleteCut_EB.Data());
 createHisto2D(DEtaMCvsPhi_EB, trMC, "deltaEtaSuperClusterAtVtx", "phiSC", "#Delta#eta vs #phi_{SC}",CompleteCut_EB.Data());
 
 TProfile* DPhiMCvsPhi_EB_tx    = (TProfile*) DPhiMCvsPhi_EB->ProfileX();
 TProfile* DPhiMCvsPhi_EB_ep_tx = (TProfile*) DPhiMCvsPhi_EB_ep->ProfileX();
 TProfile* DPhiMCvsPhi_EB_em_tx = (TProfile*) DPhiMCvsPhi_EB_em->ProfileX();
 TProfile* DEtaMCvsPhi_EB_tx    = (TProfile*) DEtaMCvsPhi_EB->ProfileX();
 
 TCanvas* cDPhivsPhi_EB = new TCanvas("cDphivsPhi_EB","cDphivsPhi_EB",700,700);
 DPhiMCvsPhi_EB->Draw("colz");
 DPhiMCvsPhi_EB_tx->Draw("same");
 gPad->SetGrid();
 toDoShell = Form("%s/images/cDPhivsPhi_EB_%d_%d.png",nameOutputDir.Data(), iEB, iEE);
 gPad->SaveAs(toDoShell.Data());
 
 TCanvas* cDPhivsPhi_EB_ep = new TCanvas("cDphivsPhi_EB_ep","cDphivsPhi_EB_ep",700,700);
 DPhiMCvsPhi_EB_ep->Draw("colz");
 DPhiMCvsPhi_EB_ep_tx->Draw("same");
 gPad->SetGrid();
 toDoShell = Form("%s/images/cDPhivsPhi_EB_ep_%d_%d.png",nameOutputDir.Data(), iEB, iEE);
 gPad->SaveAs(toDoShell.Data());
 
 TCanvas* cDPhivsPhi_EB_em = new TCanvas("cDphivsPhi_EB_em","cDphivsPhi_EB_em",700,700);
 DPhiMCvsPhi_EB_em->Draw("colz");
 DPhiMCvsPhi_EB_em_tx->Draw("same");
 gPad->SetGrid();
 toDoShell = Form("%s/images/cDphivsPhi_EB_em_%d_%d.png",nameOutputDir.Data(), iEB, iEE);
 gPad->SaveAs(toDoShell.Data());
 
 TCanvas* cDEtavsPhi_EB = new TCanvas("cDetavsPhi_EB","cDetavsPhi_EB",700,700);
 DEtaMCvsPhi_EB->Draw("colz");
 DEtaMCvsPhi_EB_tx->Draw("same");
 gPad->SetGrid();
 toDoShell = Form("%s/images/cDetavsPhi_EB_%d_%d.png",nameOutputDir.Data(), iEB, iEE);
 gPad->SaveAs(toDoShell.Data());
 
 
 ///---- 2D plot dphi/deta in EE ----
 
 TString CompleteCut_EE = Form ("(%s) && (iDetEE < -10)",CompleteCut.Data());
 TString CompleteCut_EE_ep = Form ("(%s) && (iDetEE < -10)",CompleteCut_ep.Data());
 TString CompleteCut_EE_em = Form ("(%s) && (iDetEE < -10)",CompleteCut_em.Data());
 
 TH2F* DPhiMCvsPhi_EE_ep = new TH2F("DPhiMCvsPhi_EE_ep",  "MC"  , 36,-3.15,3.15,  200,-0.04,0.04);
 TH2F* DPhiMCvsPhi_EE_em = new TH2F("DPhiMCvsPhi_EE_em",  "MC"  , 36,-3.15,3.15,  200,-0.04,0.04);
 TH2F* DPhiMCvsPhi_EE    = new TH2F("DPhiMCvsPhi_EE",  "MC"  , 36,-3.15,3.15,  200,-0.04,0.04);
 TH2F* DEtaMCvsPhi_EE    = new TH2F("DEtaMCvsPhi_EE"  ,"MC"  , 36,-3.15,3.15,  200,-0.04,0.04);
 
 createHisto2D(DPhiMCvsPhi_EE_ep, trMC, "deltaPhiSuperClusterAtVtx", "phiSC", "#Delta#phi vs #phi_{SC}",CompleteCut_EE_ep.Data());
 createHisto2D(DPhiMCvsPhi_EE_em, trMC, "deltaPhiSuperClusterAtVtx", "phiSC", "#Delta#phi vs #phi_{SC}",CompleteCut_EE_em.Data());
 createHisto2D(DPhiMCvsPhi_EE, trMC, "deltaPhiSuperClusterAtVtx", "phiSC", "#Delta#phi vs #phi_{SC}",CompleteCut_EE.Data());
 createHisto2D(DEtaMCvsPhi_EE, trMC, "deltaEtaSuperClusterAtVtx", "phiSC", "#Delta#eta vs #phi_{SC}",CompleteCut_EE.Data());
 
 TProfile* DPhiMCvsPhi_EE_tx    = (TProfile*) DPhiMCvsPhi_EE->ProfileX();
 TProfile* DPhiMCvsPhi_EE_ep_tx = (TProfile*) DPhiMCvsPhi_EE_ep->ProfileX();
 TProfile* DPhiMCvsPhi_EE_em_tx = (TProfile*) DPhiMCvsPhi_EE_em->ProfileX();
 TProfile* DEtaMCvsPhi_EE_tx    = (TProfile*) DEtaMCvsPhi_EE->ProfileX();
 
 TCanvas* cDPhivsPhi_EE = new TCanvas("cDphivsPhi_EE","cDphivsPhi_EE",700,700);
 DPhiMCvsPhi_EE->Draw("colz");
 DPhiMCvsPhi_EE_tx->Draw("same");
 gPad->SetGrid();
 toDoShell = Form("%s/images/cDPhivsPhi_EE_%d_%d.png",nameOutputDir.Data(), iEB, iEE);
 gPad->SaveAs(toDoShell.Data());
 
 TCanvas* cDPhivsPhi_EE_ep = new TCanvas("cDphivsPhi_EE_ep","cDphivsPhi_EE_ep",700,700);
 DPhiMCvsPhi_EE_ep->Draw("colz");
 DPhiMCvsPhi_EE_ep_tx->Draw("same");
 gPad->SetGrid();
 toDoShell = Form("%s/images/cDphivsPhi_EE_ep_%d_%d.png",nameOutputDir.Data(), iEB, iEE);
 gPad->SaveAs(toDoShell.Data());
 
 TCanvas* cDPhivsPhi_EE_em = new TCanvas("cDphivsPhi_EE_em","cDphivsPhi_EE_em",700,700);
 DPhiMCvsPhi_EE_em->Draw("colz");
 DPhiMCvsPhi_EE_em_tx->Draw("same");
 gPad->SetGrid();
 toDoShell = Form("%s/images/cDphivsPhi_EE_em_%d_%d.png",nameOutputDir.Data(), iEB, iEE);
 gPad->SaveAs(toDoShell.Data());
 
 TCanvas* cDEtavsPhi_EE = new TCanvas("cDetavsPhi_EE","cDetavsPhi_EE",700,700);
 DEtaMCvsPhi_EE->Draw("colz");
 DEtaMCvsPhi_EE_tx->Draw("same");
 gPad->SetGrid();
 toDoShell = Form("%s/images/cDetavsPhi_EE_%d_%d.png",nameOutputDir.Data(), iEB, iEE);
 gPad->SaveAs(toDoShell.Data());
 
 
 
 
}