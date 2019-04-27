#include "../test/plot/tools/TDRStyle.cc"

#include "../test/plot/tools/Functions.h"

#include "../test/plot/tools/CMS_lumi.C"


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
#include "FWCore/Utilities/interface/Exception.h"
#include "FWCore/PythonParameterSet/interface/MakePyBind11ParameterSets.h"
#include "FWCore/ParameterSet/interface/ProcessDesc.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/ParameterSetReader/interface/ParameterSetReader.h"





void drawSingleModule(TChain* InFile, TChain* InFileComparison , TString nameOutputDir, TString commonCut = "1", int iEB=-100, int iEE=-100, int isMC=1, int specialRegions = 0, int specialZeroTesla = 0, TChain* InFileAlternative = 0, int onlyRMS = 0){
  
 //---- for data
 TString tempCut;
 if (specialZeroTesla == 0) tempCut = Form ("%s && (electrons_classification==0 && ETSC>20 && ((abs(eta)<=1.5 && (eleTrkIso+eleEcalIso+eleHcalIsoD1+eleHcalIsoD2)/pT<0.07 && abs(SigmaIEtaIEta)<0.01) || (abs(eta)>=1.5 && (eleTrkIso+eleEcalIso+eleHcalIsoD1+eleHcalIsoD2)/pT<0.06 && abs(SigmaIEtaIEta)<0.03)) )", commonCut.Data());
 else                       tempCut = Form ("%s && (electrons_classification==0 && ETSC>20 && HoE<0.3 && eleEcalIso<15)", commonCut.Data());

 
 
 if (isMC == 0) {
  commonCut = tempCut;
 }
 
 //---- correct cut
 TString CompleteCut;
 
 if (iEB != -100) {
  CompleteCut = Form("(%s) * (iDetEB == %d)", commonCut.Data(), iEB);
 }
 if (iEE != -100) {
  CompleteCut = Form("(%s) * (iDetEE == %d)", commonCut.Data(), iEE);
 }
 
 if (specialRegions != 0) {
  if (specialRegions == 1) { CompleteCut = Form("(%s) * (etaSC>0 && etaSC<1.479 )", commonCut.Data()); } //---- EB+
  if (specialRegions == 2) { CompleteCut = Form("(%s) * (etaSC<0 && etaSC>-1.479)", commonCut.Data()); } //---- EB-
  if (specialRegions == 3) { CompleteCut = Form("(%s) * (etaSC>1.5 )", commonCut.Data()); } //---- EE+
  if (specialRegions == 4) { CompleteCut = Form("(%s) * (etaSC<-1.5)", commonCut.Data()); } //---- EE-
  if (specialRegions == 5) { CompleteCut = Form("(%s) * (abs(etaSC)<1.5)", commonCut.Data()); } //---- EB
  if (specialRegions == 6) { CompleteCut = Form("(%s) * (abs(etaSC)>1.5)", commonCut.Data()); } //---- EE
 }
 
 //---- ---- ---- 
 

 TH1F* DPhiMC;
 if      (specialZeroTesla == 0) DPhiMC = new TH1F("DPhiMC"     ," MC"  ,200,-0.02,0.02);
 else if (specialZeroTesla == 2) DPhiMC = new TH1F("DPhiMC"     ," MC"  ,100,-0.02,0.02);
 else                            DPhiMC = new TH1F("DPhiMC"     ," MC"  ,150,-0.025,0.025);
 
 TH1F* DPhiMC_ep;
 if (specialZeroTesla == 2) DPhiMC_ep  = new TH1F("DPhiMC_ep",  " MC"  ,50,-0.02,0.02);
 else                       DPhiMC_ep  = new TH1F("DPhiMC_ep",  " MC"  ,200,-0.02,0.02);
 TH1F* DPhiMC_em;
 if (specialZeroTesla == 2) DPhiMC_em  = new TH1F("DPhiMC_em",  " MC"  ,50,-0.02,0.02);
 else                       DPhiMC_em  = new TH1F("DPhiMC_em",  " MC"  ,200,-0.02,0.02);
  
 TH1F* DEtaMC;
 if      (specialZeroTesla == 0) DEtaMC = new TH1F("DEtaMC"     ," MC"  ,150,-0.025,0.025);
 else if (specialZeroTesla == 2) DEtaMC = new TH1F("DEtaMC"     ," MC"  ,60,-0.010,0.010);
 else                            DEtaMC = new TH1F("DEtaMC"     ," MC"  ,150,-0.025,0.025);
 
 TH1F* DPhiMC_ref;
 if      (specialZeroTesla == 0) DPhiMC_ref = new TH1F("DPhiMC_ref"     ," MC"  ,200,-0.02,0.02);
 else if (specialZeroTesla == 2) DPhiMC_ref = new TH1F("DPhiMC_ref"     ," MC"  ,100,-0.02,0.02);
 else                            DPhiMC_ref = new TH1F("DPhiMC_ref"     ," MC"  ,150,-0.025,0.025);
 
 TH1F* DPhiMC_ref_ep;
 if (specialZeroTesla == 2) DPhiMC_ref_ep  = new TH1F("DPhiMC_ref_ep",  " MC"  ,50,-0.02,0.02);
 else                       DPhiMC_ref_ep  = new TH1F("DPhiMC_ref_ep",  " MC"  ,100,-0.02,0.02);
 TH1F* DPhiMC_ref_em;
 if (specialZeroTesla == 2) DPhiMC_ref_em  = new TH1F("DPhiMC_ref_em",  " MC"  ,50,-0.02,0.02);
 else                       DPhiMC_ref_em  = new TH1F("DPhiMC_ref_em",  " MC"  ,100,-0.02,0.02);
 
 TH1F* DEtaMC_ref;
 if      (specialZeroTesla == 0) DEtaMC_ref = new TH1F("DEtaMC_ref"     ," MC"  ,150,-0.025,0.025);
 else if (specialZeroTesla == 2) DEtaMC_ref = new TH1F("DEtaMC_ref"     ," MC"  ,60,-0.010,0.010);
 else                            DEtaMC_ref = new TH1F("DEtaMC_ref"     ," MC"  ,150,-0.025,0.025);
 

 TH1F* DPhiMC_alt;
 if      (specialZeroTesla == 0) DPhiMC_alt = new TH1F("DPhiMC_alt"     ," MC"  ,200,-0.02,0.02);
 else if (specialZeroTesla == 2) DPhiMC_alt = new TH1F("DPhiMC_alt"     ," MC"  ,100,-0.02,0.02);
 else                            DPhiMC_alt = new TH1F("DPhiMC_alt"     ," MC"  ,150,-0.025,0.025);
 
 TH1F* DPhiMC_alt_ep;
 if (specialZeroTesla == 2) DPhiMC_alt_ep  = new TH1F("DPhiMC_alt_ep",  " MC"  ,50,-0.02,0.02);
 else                       DPhiMC_alt_ep  = new TH1F("DPhiMC_alt_ep",  " MC"  ,200,-0.02,0.02);
 TH1F* DPhiMC_alt_em;
 if (specialZeroTesla == 2) DPhiMC_alt_em  = new TH1F("DPhiMC_alt_em",  " MC"  ,50,-0.02,0.02);
 else                       DPhiMC_alt_em  = new TH1F("DPhiMC_alt_em",  " MC"  ,200,-0.02,0.02);
 
 TH1F* DEtaMC_alt;
 if      (specialZeroTesla == 0) DEtaMC_alt = new TH1F("DEtaMC_alt"     ," MC"  ,150,-0.025,0.025);
 else if (specialZeroTesla == 2) DEtaMC_alt = new TH1F("DEtaMC_alt"     ," MC"  ,60,-0.010,0.010);
 else                            DEtaMC_alt = new TH1F("DEtaMC_alt"     ," MC"  ,150,-0.025,0.025);
 
 
 ///---- text info (begin) ----
 TLatex*  tinfoDPhi    = new TLatex(0.2,0.8,"");
 TLatex*  tinfoDEta    = new TLatex(0.2,0.8,"");
 TLatex*  tinfoDPhi_ep = new TLatex(0.2,0.8,"");
 TLatex*  tinfoDPhi_em = new TLatex(0.2,0.8,"");

 TLatex*  tinfoDPhi_ref    = new TLatex(0.2,0.7,"");
 TLatex*  tinfoDEta_ref    = new TLatex(0.2,0.7,"");
 TLatex*  tinfoDPhi_ref_ep = new TLatex(0.2,0.7,"");
 TLatex*  tinfoDPhi_ref_em = new TLatex(0.2,0.7,"");

 TLatex*  tinfoDPhi_alt    = new TLatex(0.2,0.7,"");
 TLatex*  tinfoDEta_alt    = new TLatex(0.2,0.7,"");
 TLatex*  tinfoDPhi_alt_ep = new TLatex(0.2,0.7,"");
 TLatex*  tinfoDPhi_alt_em = new TLatex(0.2,0.7,"");
 ///---- text info (end) ----
 
 
 float ScaleAxis = 1.5;
 
 createHisto(tinfoDPhi, DPhiMC, InFile, "deltaPhiSuperClusterAtVtx", "#Delta#phi",CompleteCut.Data(), 0, onlyRMS);
 createHisto(tinfoDEta, DEtaMC, InFile, "deltaEtaSuperClusterAtVtx", "#Delta#eta",CompleteCut.Data(), 0, onlyRMS);
 
 createHisto(tinfoDPhi_ref, DPhiMC_ref, InFileComparison, "deltaPhiSuperClusterAtVtx", "#Delta#phi",CompleteCut.Data(), 1, onlyRMS);
 createHisto(tinfoDEta_ref, DEtaMC_ref, InFileComparison, "deltaEtaSuperClusterAtVtx", "#Delta#eta",CompleteCut.Data(), 1, onlyRMS);
 
 TString CompleteCut_ep = Form ("(%s) && (eleCharge>0)",CompleteCut.Data());
 TString CompleteCut_em = Form ("(%s) && (eleCharge<0)",CompleteCut.Data());
 
 createHisto(tinfoDPhi_ep, DPhiMC_ep, InFile, "deltaPhiSuperClusterAtVtx", "#Delta#phi",CompleteCut_ep.Data(), 0, onlyRMS);
 createHisto(tinfoDPhi_em, DPhiMC_em, InFile, "deltaPhiSuperClusterAtVtx", "#Delta#phi",CompleteCut_em.Data(), 0, onlyRMS);
  
 createHisto(tinfoDPhi_ref_ep, DPhiMC_ref_ep, InFileComparison, "deltaPhiSuperClusterAtVtx", "#Delta#phi",CompleteCut_ep.Data(), 1, onlyRMS);
 createHisto(tinfoDPhi_ref_em, DPhiMC_ref_em, InFileComparison, "deltaPhiSuperClusterAtVtx", "#Delta#phi",CompleteCut_em.Data(), 1, onlyRMS);
  
 float min_legend = 0.62;
 
 if (InFileAlternative != 0) {
//    ScaleAxis = 2.5;
//    min_legend = 0.65;

   if (onlyRMS == 0) {
     ScaleAxis = 3.7;
     min_legend = 0.54;  
   }
   else {
//      ScaleAxis = 1.78;
     ScaleAxis = 1.40;
     min_legend = 0.39;    
   }
   
   createHisto(tinfoDPhi_alt, DPhiMC_alt, InFileAlternative, "deltaPhiSuperClusterAtVtx", "#Delta#phi",CompleteCut.Data(), 2, onlyRMS);
   createHisto(tinfoDEta_alt, DEtaMC_alt, InFileAlternative, "deltaEtaSuperClusterAtVtx", "#Delta#eta",CompleteCut.Data(), 2, onlyRMS);
 
   createHisto(tinfoDPhi_alt_ep, DPhiMC_alt_ep, InFileAlternative, "deltaPhiSuperClusterAtVtx", "#Delta#phi",CompleteCut_ep.Data(), 2, onlyRMS);
   createHisto(tinfoDPhi_alt_em, DPhiMC_alt_em, InFileAlternative, "deltaPhiSuperClusterAtVtx", "#Delta#phi",CompleteCut_em.Data(), 2, onlyRMS);
 }
 
 ///---- legend (begin) ----
//  TLegend* legend = new TLegend(0.62,min_legend,0.88,min_legend+(0.83-0.65));
//  TLegend* legend = new TLegend(0.62,min_legend,0.88,0.89);

 TLegend* legend = new TLegend(0.62,min_legend,0.87,min_legend + (0.89 - 0.54 - 0.05));
 
 legend->AddEntry(DEtaMC_ref,"MC","f");
 
 if (isMC) {
  legend->AddEntry(DEtaMC,"MC","f");
 }
 else {
  legend->AddEntry(DEtaMC,"#splitline{DATA}{after alignment}","p"); 
 }
 legend->SetFillColor(kWhite);
 legend->SetLineColor(kWhite);
 
 if (InFileAlternative != 0) {
   legend->AddEntry(DEtaMC_alt,"#splitline{DATA}{before alignment}","p");
 }
 
 ///---- legend (end) ----
 
 
 ///---- text (begin) ----
//  TLatex *tEB = new TLatex(0.2,0.7,"#splitline{EB}{#splitline{CMS 2011}{L= 4.98 fb^{-1}}}");
//  TLatex *tEE = new TLatex(0.2,0.7,"#splitline{EE}{#splitline{CMS 2011}{L= 4.98 fb^{-1}}}");
//  tEB->SetNDC(true);
//  tEE->SetNDC(true);
 ///---- text (end) ----
 
 TString toDoShell;
//  toDoShell = Form("rm -r %s ;",nameOutputDir.Data());
//  system(toDoShell.Data());
//  toDoShell = Form("mkdir %s ;",nameOutputDir.Data());
//  system(toDoShell.Data());
//  toDoShell = Form("mkdir %s/images ;",nameOutputDir.Data());
//  system(toDoShell.Data());
//  toDoShell = Form("cp index.php %s/ ;",nameOutputDir.Data());
//  system(toDoShell.Data());
//  toDoShell = Form("cp index.php %s/images ;",nameOutputDir.Data());
//  system(toDoShell.Data());
//  
 
 
 //---- output txt file
 std::ofstream myfile;
 TString nameResults;
 if (isMC) {
  nameResults = Form ("%s/MC.txt", nameOutputDir.Data()); 
 }
 else {
  nameResults = Form ("%s/DATA.txt", nameOutputDir.Data());   
 }
 myfile.open(nameResults.Data(),std::ios::out | std::ios::app); 
 myfile << iEB << " " << iEE << " ";
 
 
 TCanvas* cDPhi = new TCanvas("cDphi","cDphi",700,700);
 DPhiMC->Draw("PE");
 DPhiMC->GetYaxis()->SetRangeUser( 0, ScaleAxis *  DPhiMC->GetMaximum() );
 float integral = DPhiMC->Integral();
 DPhiMC_ref->Scale(integral / DPhiMC_ref->Integral());
 DPhiMC_ref->Draw("histo same");
 DPhiMC->Draw("PE same");
 if (InFileAlternative != 0) { DPhiMC_alt->Scale(integral / DPhiMC_alt->Integral());  DPhiMC_alt->Draw("PE same");  tinfoDPhi_alt->Draw(); }
 tinfoDPhi_ref->Draw();
 tinfoDPhi->Draw();
 legend->Draw();
 // writing the lumi information and the CMS "logo"
 CMS_lumi( cDPhi, 4, 10 );
//  cDPhi->SetGrid();
 gPad->Update();
//  gPad->SetGrid();
 toDoShell = Form("%s/images/cDphi_%d_%d_%d.png",nameOutputDir.Data(), iEB, iEE, specialRegions);
 gPad->SaveAs(toDoShell.Data());
 toDoShell = Form("%s/images/cDphi_%d_%d_%d.pdf",nameOutputDir.Data(), iEB, iEE, specialRegions);
 gPad->SaveAs(toDoShell.Data());
 toDoShell = Form("%s/images/cDphi_%d_%d_%d.C",nameOutputDir.Data(), iEB, iEE, specialRegions);
 gPad->SaveAs(toDoShell.Data());
 myfile << DPhiMC->GetMean() << " " << DPhiMC->GetRMS() << " " << DPhiMC->GetEntries() << "      ";

 
 
 
 
 TCanvas* cDPhi_ep = new TCanvas("cDPhi_ep","cDPhi_ep",700,700);
 DPhiMC_ep->Draw("PE");
 DPhiMC_ep->GetYaxis()->SetRangeUser( 0, ScaleAxis *  DPhiMC_ep->GetMaximum() );
 integral = DPhiMC_ep->Integral();
 DPhiMC_ref_ep->Scale(integral / DPhiMC_ref_ep->Integral());
 DPhiMC_ref_ep->Draw("histo same");
 DPhiMC_ep->Draw("PE same");
 if (InFileAlternative != 0) { DPhiMC_alt_ep->Scale(integral / DPhiMC_alt_ep->Integral());  DPhiMC_alt_ep->Draw("PE same"); tinfoDPhi_alt_ep->Draw();  }
 tinfoDPhi_ref_ep->Draw();
 tinfoDPhi_ep->Draw();
 legend->Draw();
 CMS_lumi( cDPhi_ep, 4, 10 );
//  gPad->SetGrid();
 toDoShell = Form("%s/images/cDPhi_ep_%d_%d_%d.png",nameOutputDir.Data(), iEB, iEE, specialRegions);
 gPad->SaveAs(toDoShell.Data());
 toDoShell = Form("%s/images/cDPhi_ep_%d_%d_%d.pdf",nameOutputDir.Data(), iEB, iEE, specialRegions);
 gPad->SaveAs(toDoShell.Data());
 toDoShell = Form("%s/images/cDPhi_ep_%d_%d_%d.C",nameOutputDir.Data(), iEB, iEE, specialRegions);
 gPad->SaveAs(toDoShell.Data());
 myfile << DPhiMC_ep->GetMean() << " " << DPhiMC_ep->GetRMS() << " " << DPhiMC_ep->GetEntries() << "      ";
 
 TCanvas* cDPhi_em = new TCanvas("cDPhi_em","cDPhi_em",700,700);
 DPhiMC_em->Draw("PE");
 DPhiMC_em->GetYaxis()->SetRangeUser( 0, ScaleAxis *  DPhiMC_em->GetMaximum() );
 integral = DPhiMC_em->Integral();
 DPhiMC_ref_em->Scale(integral / DPhiMC_ref_em->Integral());
 DPhiMC_ref_em->Draw("histo same");
 DPhiMC_em->Draw("PE same");
 if (InFileAlternative != 0) { DPhiMC_alt_em->Scale(integral / DPhiMC_alt_em->Integral()); DPhiMC_alt_em->Draw("PE same");  tinfoDPhi_alt_em->Draw();  }
 tinfoDPhi_ref_em->Draw();
 tinfoDPhi_em->Draw();
 legend->Draw();
 CMS_lumi( cDPhi_em, 4, 10 );
//  gPad->SetGrid();
 toDoShell = Form("%s/images/cDPhi_em_%d_%d_%d.png",nameOutputDir.Data(), iEB, iEE, specialRegions);
 gPad->SaveAs(toDoShell.Data());
 toDoShell = Form("%s/images/cDPhi_em_%d_%d_%d.pdf",nameOutputDir.Data(), iEB, iEE, specialRegions);
 gPad->SaveAs(toDoShell.Data());
 toDoShell = Form("%s/images/cDPhi_em_%d_%d_%d.C",nameOutputDir.Data(), iEB, iEE, specialRegions);
 gPad->SaveAs(toDoShell.Data());
 myfile << DPhiMC_em->GetMean() << " " << DPhiMC_em->GetRMS() << " " << DPhiMC_em->GetEntries() << "      ";
 
 
 
 
 
 
 
 
 TCanvas* cDEta = new TCanvas("cDeta","cDeta",700,700);
 DEtaMC->Draw("PE");
 DEtaMC->GetYaxis()->SetRangeUser( 0, ScaleAxis *  DEtaMC->GetMaximum() );
 integral = DEtaMC->Integral();
 DEtaMC_ref->Scale(integral / DEtaMC_ref->Integral());
 DEtaMC_ref->Draw("histo same");
 DEtaMC->Draw("PE same");
 if (InFileAlternative != 0) {  DEtaMC_alt->Scale(integral / DEtaMC_alt->Integral()); DEtaMC_alt->Draw("PE same");  tinfoDEta_alt->Draw(); }
 tinfoDEta_ref->Draw();
 tinfoDEta->Draw();
 legend->Draw();
//  cDEta->SetGrid();
 gPad->Update();
 CMS_lumi( cDEta, 4, 10 );
 toDoShell = Form("%s/images/cDEta_%d_%d_%d.png",nameOutputDir.Data(), iEB, iEE, specialRegions);
 gPad->SaveAs(toDoShell.Data());
 toDoShell = Form("%s/images/cDEta_%d_%d_%d.pdf",nameOutputDir.Data(), iEB, iEE, specialRegions);
 gPad->SaveAs(toDoShell.Data());
 toDoShell = Form("%s/images/cDEta_%d_%d_%d.C",nameOutputDir.Data(), iEB, iEE, specialRegions);
 gPad->SaveAs(toDoShell.Data());
 myfile << DEtaMC->GetMean() << " " << DEtaMC->GetRMS() << " " << DEtaMC->GetEntries() << "      ";
 
 
 
 //---------------------------------
 //---- now without the numbers ----
 
 ScaleAxis = 1.2 * (1./ScaleAxis);
 
 min_legend = 0.65 + 0.05;
 TLegend* legendNoNumber = new TLegend(0.62 - 0.02,min_legend,0.88,min_legend+(0.83-0.65));

 legendNoNumber->AddEntry(DEtaMC_ref,"MC","f");

 if (isMC) {
   legendNoNumber->AddEntry(DEtaMC,"MC","f");
 }
 else {
   legendNoNumber->AddEntry(DEtaMC,"DATA","p"); 
 }
 legendNoNumber->SetFillColor(kWhite);
 
 if (InFileAlternative != 0) {
   legendNoNumber->AddEntry(DEtaMC_alt,"DATA old","p");
 }
 
 legendNoNumber->SetLineColor(kWhite);
 
 
 cDPhi->cd();
 DPhiMC->Draw("PE");
 DPhiMC->GetYaxis()->SetRangeUser( 0, ScaleAxis *  DPhiMC->GetMaximum() );
 DPhiMC_ref->Draw("histo same");
 DPhiMC->Draw("PE same");
 if (InFileAlternative != 0) { DPhiMC_alt->Draw("PE same"); }
 legendNoNumber->Draw();
//  gPad->SetGrid();
 toDoShell = Form("%s/images/noNumbers_cDphi_%d_%d_%d.png",nameOutputDir.Data(), iEB, iEE, specialRegions);
 gPad->SaveAs(toDoShell.Data());
 toDoShell = Form("%s/images/noNumbers_cDphi_%d_%d_%d.pdf",nameOutputDir.Data(), iEB, iEE, specialRegions);
 gPad->SaveAs(toDoShell.Data());
 toDoShell = Form("%s/images/noNumbers_cDphi_%d_%d_%d.C",nameOutputDir.Data(), iEB, iEE, specialRegions);
 gPad->SaveAs(toDoShell.Data());
 CMS_lumi( cDPhi, 4, 10 );
//  cDPhi->SetGrid(); 
 gPad->Update();
 
 
 cDPhi_ep->cd();
 DPhiMC_ep->Draw("PE");
 DPhiMC_ep->GetYaxis()->SetRangeUser( 0, ScaleAxis *  DPhiMC_ep->GetMaximum() );
 DPhiMC_ref_ep->Draw("histo same");
 DPhiMC_ep->Draw("PE same");
 if (InFileAlternative != 0) { DPhiMC_alt_ep->Draw("PE same"); }
 legendNoNumber->Draw();
 CMS_lumi( cDPhi_ep, 4, 10 );
//  gPad->SetGrid();
 toDoShell = Form("%s/images/noNumbers_cDPhi_ep_%d_%d_%d.png",nameOutputDir.Data(), iEB, iEE, specialRegions);
 gPad->SaveAs(toDoShell.Data());
 toDoShell = Form("%s/images/noNumbers_cDPhi_ep_%d_%d_%d.pdf",nameOutputDir.Data(), iEB, iEE, specialRegions);
 gPad->SaveAs(toDoShell.Data());
 toDoShell = Form("%s/images/noNumbers_cDPhi_ep_%d_%d_%d.C",nameOutputDir.Data(), iEB, iEE, specialRegions);
 gPad->SaveAs(toDoShell.Data());

 
 cDPhi_em->cd();
 DPhiMC_em->Draw("PE");
 DPhiMC_em->GetYaxis()->SetRangeUser( 0, ScaleAxis *  DPhiMC_em->GetMaximum() );
 DPhiMC_ref_em->Draw("histo same");
 DPhiMC_em->Draw("PE same");
 if (InFileAlternative != 0) { DPhiMC_alt_em->Draw("PE same"); }
 legendNoNumber->Draw();
 CMS_lumi( cDPhi_em, 4, 10 );
//  gPad->SetGrid();
 toDoShell = Form("%s/images/noNumbers_cDPhi_em_%d_%d_%d.png",nameOutputDir.Data(), iEB, iEE, specialRegions);
 gPad->SaveAs(toDoShell.Data());
 toDoShell = Form("%s/images/noNumbers_cDPhi_em_%d_%d_%d.pdf",nameOutputDir.Data(), iEB, iEE, specialRegions);
 gPad->SaveAs(toDoShell.Data());
 toDoShell = Form("%s/images/noNumbers_cDPhi_em_%d_%d_%d.C",nameOutputDir.Data(), iEB, iEE, specialRegions);
 gPad->SaveAs(toDoShell.Data());
 
 
 cDEta->cd();
//  DEtaMC->GetXaxis()->SetRangeUser( -0.010, 0.010 );
 DEtaMC->Draw("PE");
 DEtaMC->GetYaxis()->SetRangeUser( 0, ScaleAxis *  DEtaMC->GetMaximum() );
 DEtaMC_ref->Draw("histo same");
 DEtaMC->Draw("PE same");
 if (InFileAlternative != 0) { DEtaMC_alt->Draw("PE same"); }
 legendNoNumber->Draw();
//  cDEta->SetGrid();
 gPad->Update();
 CMS_lumi( cDEta, 4, 10 );
 toDoShell = Form("%s/images/noNumbers_cDEta_%d_%d_%d.png",nameOutputDir.Data(), iEB, iEE, specialRegions);
 gPad->SaveAs(toDoShell.Data());
 toDoShell = Form("%s/images/noNumbers_cDEta_%d_%d_%d.pdf",nameOutputDir.Data(), iEB, iEE, specialRegions);
 gPad->SaveAs(toDoShell.Data());
 toDoShell = Form("%s/images/noNumbers_cDEta_%d_%d_%d.C",nameOutputDir.Data(), iEB, iEE, specialRegions);
 gPad->SaveAs(toDoShell.Data());
 
 
 
 
 
 
 
 
 
 
 
 
 myfile << std::endl;
 myfile.close(); 
 //--- output text file (end)
 
 
 //---- cleaning not to have memory leak
 delete DPhiMC;
 delete DPhiMC_ep; 
 delete DPhiMC_em; 
 delete DEtaMC;    
  
 delete DPhiMC_ref;
 delete DPhiMC_ref_ep; 
 delete DPhiMC_ref_em; 
 delete DEtaMC_ref;    
 
 delete cDPhi;
 delete cDPhi_em;
 delete cDPhi_ep;
 delete cDEta;
 
//  delete tEB;
//  delete tEE;
 
}


//---------------
// ---- Main ----

int main(int argc, char** argv) {
  
  std::string fileName (argv[1]) ;
//  std::shared_ptr<edm::ParameterSet> parameterSet = edm::readConfig(fileName) ;
  
 std::unique_ptr<edm::ParameterSet> parameterSet = edm::readConfig(fileName) ;
  
  edm::ParameterSet subPSetInput = parameterSet->getParameter<edm::ParameterSet> ("ConfigurationToDraw") ;
  std::string nameInFileRoot   = subPSetInput.getParameter<std::string> ("nameInFileRoot") ;
  std::string nameInFileRootComparison   = subPSetInput.getParameter<std::string> ("nameInFileRootComparison") ;
  std::string commonCut = subPSetInput.getParameter<std::string> ("commonCut") ;
  std::string nameOutputDir = subPSetInput.getParameter<std::string> ("nameOutputDir") ;
  
  std::string treeName = subPSetInput.getUntrackedParameter<std::string> ("treeName","ntupleEcalAlignment/myTree") ;
  
  //---- special setup
  int specialZeroTesla = subPSetInput.getUntrackedParameter<int> ("specialZeroTesla", 0) ;
  int onlyRMS = subPSetInput.getUntrackedParameter<int> ("onlyRMS", 0) ;
  
  //---- if you want to compare 2 sets of data
  std::string nameInFileRootAlternative = subPSetInput.getUntrackedParameter<std::string> ("nameInFileRootAlternative", "NONE") ;
  
  
  
  
  
  std::cout << " treeName =                 " << treeName << std::endl;  
  std::cout << " nameInFileRoot =           " << nameInFileRoot << std::endl;
  std::cout << " nameInFileRootComparison = " << nameInFileRootComparison << std::endl;
  std::cout << " commonCut =                " << commonCut << std::endl;
  std::cout << " nameOutputDir =            " << nameOutputDir << std::endl;
  std::cout << " specialZeroTesla =         " << specialZeroTesla << std::endl;
  std::cout << " onlyRMS =                  " << onlyRMS << std::endl;
  
  
  if (nameInFileRootAlternative != "NONE")   std::cout << " nameInFileRootAlternative = " << nameInFileRootAlternative << std::endl;
  
  TChain* InFile   = new TChain(treeName.c_str());
  InFile->Add(nameInFileRoot.c_str());
  
  TChain* InFileComparison   = new TChain(treeName.c_str());
  InFileComparison->Add(nameInFileRootComparison.c_str());
  
  
  TChain* InFileAlternative   = new TChain(treeName.c_str());
  if (nameInFileRootAlternative != "NONE") InFileAlternative->Add(nameInFileRootAlternative.c_str());
  
  
  //---- prepare style
  TDRStyle();
  
  gStyle->SetTitleYOffset(1.1);
  gStyle->cd();
  
  
  //---- filter the big trees
  
  //---- for data
  TString tempCut_data;
  if (specialZeroTesla == 0) tempCut_data = Form ("%s && (electrons_classification==0 && ETSC>20 && ((abs(eta)<=1.5 && (eleTrkIso+eleEcalIso+eleHcalIsoD1+eleHcalIsoD2)/pT<0.07 && abs(SigmaIEtaIEta)<0.01) || (abs(eta)>=1.5 && (eleTrkIso+eleEcalIso+eleHcalIsoD1+eleHcalIsoD2)/pT<0.06 && abs(SigmaIEtaIEta)<0.03)) )", commonCut.c_str());
  else                       tempCut_data = Form ("%s && (electrons_classification==0 && ETSC>20 && HoE<0.3 && eleEcalIso<15)", commonCut.c_str());
  
  
  InFile->SetEntryList(0); 
  InFile->Draw(">> myList",tempCut_data.Data(),"entrylist");
  TEntryList *myList = (TEntryList*) gDirectory->Get("myList");
  InFile->SetEntryList(myList); 
  
  InFileComparison->SetEntryList(0); 
  InFileComparison->Draw(">> myListMC",commonCut.c_str(),"entrylist");
  TEntryList *myListMC = (TEntryList*) gDirectory->Get("myListMC");
  InFileComparison->SetEntryList(myListMC); 
  
  
  if (nameInFileRootAlternative != "NONE") {
    InFileAlternative->SetEntryList(0); 
    InFileAlternative->Draw(">> myListAlternative",tempCut_data.Data(),"entrylist");
    TEntryList *myListAlternative = (TEntryList*) gDirectory->Get("myListAlternative");
    InFileAlternative->SetEntryList(myListAlternative); 
  }
  
  
  //---- create directories
  TString toDoShell;
  toDoShell = Form("mkdir %s ;",nameOutputDir.c_str());
  system(toDoShell.Data());
  toDoShell = Form("mkdir %s/images ;",nameOutputDir.c_str());
  system(toDoShell.Data());
  toDoShell = Form("cp index.php %s/ ;",nameOutputDir.c_str());
  system(toDoShell.Data());
  toDoShell = Form("cp index.php %s/images ;",nameOutputDir.c_str());
  system(toDoShell.Data());
  

  std::cout << " first the special regions ..." << std::endl;
  
  //---- summary regions
  for (int iSpecial = 0; iSpecial <6; iSpecial++) {
    if (nameInFileRootAlternative != "NONE") {
      drawSingleModule(InFile, InFileComparison, nameOutputDir, commonCut, -100, -100, 0, iSpecial+1, specialZeroTesla, InFileAlternative, onlyRMS);
    }
    else {
      drawSingleModule(InFile, InFileComparison, nameOutputDir, commonCut, -100, -100, 0, iSpecial+1, specialZeroTesla, 0, onlyRMS);      
    }
  }
  
  std::cout << " then the EndCap ..." << std::endl;
  //---- EE
  for (int iEE = 0; iEE <4; iEE++) {
    if (nameInFileRootAlternative != "NONE") {
      drawSingleModule(InFile, InFileComparison, nameOutputDir, commonCut, -100, iEE, 0, 0, specialZeroTesla, InFileAlternative);
    }
    else {
      drawSingleModule(InFile, InFileComparison, nameOutputDir, commonCut, -100, iEE, 0, 0, specialZeroTesla, 0, onlyRMS);
    }
  }

  std::cout << " and now the Barrel ..." << std::endl;
  //---- EB
  for (int iEB = 0; iEB <36; iEB++) {
    if (nameInFileRootAlternative != "NONE") {
      drawSingleModule(InFile, InFileComparison, nameOutputDir, commonCut, iEB, -100, 0, 0, specialZeroTesla, InFileAlternative, onlyRMS);
    }
    else {
      drawSingleModule(InFile, InFileComparison, nameOutputDir, commonCut, iEB, -100, 0, 0, specialZeroTesla, 0, onlyRMS);
    }
  }

  std::cout << " Done." << std::endl;
  
}


