#include "../test/plot/tools/TDRStyle.cc"

#include "../test/plot/tools/Functions.h"

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
#include "FWCore/PythonParameterSet/interface/MakeParameterSets.h"
#include "FWCore/ParameterSet/interface/ProcessDesc.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"



void drawSingleModule(TChain* InFile, TChain* InFileComparison , TString nameOutputDir, TString commonCut = "1", int iEB=-100, int iEE=-100, int isMC=1, int specialRegions = 0, int specialZeroTesla = 0){
  
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
 }
 
 //---- ---- ---- 
 

 TH1F* DPhiMC;
 if (specialZeroTesla == 0) DPhiMC = new TH1F("DPhiMC"     ," MC"  ,200,-0.02,0.02);
 else                       DPhiMC = new TH1F("DPhiMC"     ," MC"  ,150,-0.025,0.025);
 TH1F* DPhiMC_ep  = new TH1F("DPhiMC_ep",  " MC"  ,200,-0.02,0.02);
 TH1F* DPhiMC_em  = new TH1F("DPhiMC_em",  " MC"  ,200,-0.02,0.02);
 TH1F* DEtaMC;
 if (specialZeroTesla == 0) DEtaMC = new TH1F("DEtaMC"     ," MC"  ,150,-0.025,0.025);
 else                       DEtaMC = new TH1F("DEtaMC"     ," MC"  ,150,-0.025,0.025);
 
 TH1F* DPhiMC_ref;
 if (specialZeroTesla == 0) DPhiMC_ref = new TH1F("DPhiMC_ref"     ," MC"  ,200,-0.02,0.02);
 else                       DPhiMC_ref = new TH1F("DPhiMC_ref"     ," MC"  ,150,-0.025,0.025);
 TH1F* DPhiMC_ref_ep  = new TH1F("DPhiMC_ref_ep",  " MC"  ,200,-0.02,0.02);
 TH1F* DPhiMC_ref_em  = new TH1F("DPhiMC_ref_em",  " MC"  ,200,-0.02,0.02);
 TH1F* DEtaMC_ref;
 if (specialZeroTesla == 0) DEtaMC_ref = new TH1F("DEtaMC_ref"     ," MC"  ,150,-0.025,0.025);
 else                       DEtaMC_ref = new TH1F("DEtaMC_ref"     ," MC"  ,150,-0.025,0.025);
 
 
 ///---- text info (begin) ----
 TLatex*  tinfoDPhi    = new TLatex(0.2,0.8,"");
 TLatex*  tinfoDEta    = new TLatex(0.2,0.8,"");
 TLatex*  tinfoDPhi_ep = new TLatex(0.2,0.8,"");
 TLatex*  tinfoDPhi_em = new TLatex(0.2,0.8,"");

 TLatex*  tinfoDPhi_ref    = new TLatex(0.2,0.6,"");
 TLatex*  tinfoDEta_ref    = new TLatex(0.2,0.6,"");
 TLatex*  tinfoDPhi_ref_ep = new TLatex(0.2,0.6,"");
 TLatex*  tinfoDPhi_ref_em = new TLatex(0.2,0.6,"");
 ///---- text info (end) ----
 
 createHisto(tinfoDPhi, DPhiMC, InFile, "deltaPhiSuperClusterAtVtx", "#Delta#phi",CompleteCut.Data());
 createHisto(tinfoDEta, DEtaMC, InFile, "deltaEtaSuperClusterAtVtx", "#Delta#eta",CompleteCut.Data());
 
 TString CompleteCut_ep = Form ("(%s) && (eleCharge>0)",CompleteCut.Data());
 TString CompleteCut_em = Form ("(%s) && (eleCharge<0)",CompleteCut.Data());
 
 createHisto(tinfoDPhi_ep, DPhiMC_ep, InFile, "deltaPhiSuperClusterAtVtx", "#Delta#phi",CompleteCut_ep.Data());
 createHisto(tinfoDPhi_em, DPhiMC_em, InFile, "deltaPhiSuperClusterAtVtx", "#Delta#phi",CompleteCut_em.Data());
 
 createHisto(tinfoDPhi_ref, DPhiMC_ref, InFileComparison, "deltaPhiSuperClusterAtVtx", "#Delta#phi",CompleteCut.Data(), 1);
 createHisto(tinfoDEta_ref, DEtaMC_ref, InFileComparison, "deltaEtaSuperClusterAtVtx", "#Delta#eta",CompleteCut.Data(), 1);
 
 createHisto(tinfoDPhi_ref_ep, DPhiMC_ref_ep, InFileComparison, "deltaPhiSuperClusterAtVtx", "#Delta#phi",CompleteCut_ep.Data(), 1);
 createHisto(tinfoDPhi_ref_em, DPhiMC_ref_em, InFileComparison, "deltaPhiSuperClusterAtVtx", "#Delta#phi",CompleteCut_em.Data(), 1);
  
 ///---- legend (begin) ----
 TLegend* legend = new TLegend(0.62,0.72,0.88,0.93);
 if (isMC) {
  legend->AddEntry(DEtaMC,"MC","f");
 }
 else {
  legend->AddEntry(DEtaMC,"DATA","f"); 
 }
 legend->SetFillColor(kWhite);

 legend->AddEntry(DEtaMC_ref,"MC","f");
 
 
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
 float integral = DPhiMC->Integral();
 DPhiMC_ref->Scale(integral / DPhiMC_ref->Integral());
 DPhiMC_ref->Draw("same");
 DPhiMC->Draw("PE same");
 tinfoDPhi_ref->Draw();
 tinfoDPhi->Draw();
 gPad->SetGrid();
 toDoShell = Form("%s/images/cDphi_%d_%d_%d.png",nameOutputDir.Data(), iEB, iEE, specialRegions);
 gPad->SaveAs(toDoShell.Data());
 myfile << DPhiMC->GetMean() << " " << DPhiMC->GetRMS() << " " << DPhiMC->GetEntries() << "      ";

 
 
 
 
 TCanvas* cDPhi_ep = new TCanvas("cDPhi_ep","cDPhi_ep",700,700);
 DPhiMC_ep->Draw("PE");
 integral = DPhiMC_ep->Integral();
 DPhiMC_ref_ep->Scale(integral / DPhiMC_ref_ep->Integral());
 DPhiMC_ref_ep->Draw("same");
 DPhiMC_ep->Draw("PE same");
 tinfoDPhi_ref_ep->Draw();
 tinfoDPhi_ep->Draw();
 gPad->SetGrid();
 toDoShell = Form("%s/images/cDPhi_ep_%d_%d_%d.png",nameOutputDir.Data(), iEB, iEE, specialRegions);
 gPad->SaveAs(toDoShell.Data());
 myfile << DPhiMC_ep->GetMean() << " " << DPhiMC_ep->GetRMS() << " " << DPhiMC_ep->GetEntries() << "      ";
 
 TCanvas* cDPhi_em = new TCanvas("cDPhi_em","cDPhi_em",700,700);
 DPhiMC_em->Draw("PE");
 integral = DPhiMC_em->Integral();
 DPhiMC_ref_em->Scale(integral / DPhiMC_ref_em->Integral());
 DPhiMC_ref_em->Draw("same");
 DPhiMC_em->Draw("PE same");
 tinfoDPhi_ref_em->Draw();
 tinfoDPhi_em->Draw();
 gPad->SetGrid();
 toDoShell = Form("%s/images/cDPhi_em_%d_%d_%d.png",nameOutputDir.Data(), iEB, iEE, specialRegions);
 gPad->SaveAs(toDoShell.Data());
 myfile << DPhiMC_em->GetMean() << " " << DPhiMC_em->GetRMS() << " " << DPhiMC_em->GetEntries() << "      ";
 
 
 
 legend->Draw();
 cDPhi->SetGrid(); gPad->Update();
 
 TCanvas* cDEta = new TCanvas("cDeta","cDeta",700,700);
 DEtaMC->Draw("PE");
 integral = DEtaMC->Integral();
 DEtaMC_ref->Scale(integral / DEtaMC_ref->Integral());
 DEtaMC_ref->Draw("same");
 DEtaMC->Draw("PE same");
 tinfoDEta_ref->Draw();
 tinfoDEta->Draw();
 legend->Draw();
 cDEta->SetGrid(); gPad->Update();
 toDoShell = Form("%s/images/cDEta_%d_%d_%d.png",nameOutputDir.Data(), iEB, iEE, specialRegions);
 gPad->SaveAs(toDoShell.Data());
 myfile << DEtaMC->GetMean() << " " << DEtaMC->GetRMS() << " " << DEtaMC->GetEntries() << "      ";
 
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
 
 delete tEB;
 delete tEE;
 
}


//---------------
// ---- Main ----

int main(int argc, char** argv) {
  
  std::string fileName (argv[1]) ;
  std::shared_ptr<edm::ParameterSet> parameterSet = edm::readConfig(fileName) ;
  
  
  edm::ParameterSet subPSetInput = parameterSet->getParameter<edm::ParameterSet> ("ConfigurationToDraw") ;
  std::string nameInFileRoot   = subPSetInput.getParameter<std::string> ("nameInFileRoot") ;
  std::string nameInFileRootComparison   = subPSetInput.getParameter<std::string> ("nameInFileRootComparison") ;
  std::string commonCut = subPSetInput.getParameter<std::string> ("commonCut") ;
  
  std::string nameOutputDir = subPSetInput.getParameter<std::string> ("nameOutputDir") ;
  
  //---- special setup
  int specialZeroTesla = subPSetInput.getUntrackedParameter<int> ("specialZeroTesla") ;
  
  
  
  std::cout << " nameInFileRoot =           " << nameInFileRoot << std::endl;
  std::cout << " nameInFileRootComparison = " << nameInFileRootComparison << std::endl;
  std::cout << " commonCut =                " << commonCut << std::endl;
  std::cout << " nameOutputDir =            " << nameOutputDir << std::endl;
  std::cout << " specialZeroTesla =         " << specialZeroTesla << std::endl;
  
  
  TChain* InFile   = new TChain("ntupleEcalAlignment/myTree");
  InFile->Add(nameInFileRoot.c_str());
  
  TChain* InFileComparison   = new TChain("ntupleEcalAlignment/myTree");
  InFileComparison->Add(nameInFileRootComparison.c_str());
  
  
  //---- prepare style
  TDRStyle();
  
  gStyle->SetTitleYOffset(1.1);
  gStyle->cd();
  
  
  //---- filter the big trees
  
  InFile->SetEntryList(0); 
  InFile->Draw(">> myList",commonCut.c_str(),"entrylist");
  TEntryList *myList = (TEntryList*) gDirectory->Get("myList");
  InFile->SetEntryList(myList); 
  
  InFileComparison->SetEntryList(0); 
  InFileComparison->Draw(">> myListMC",commonCut.c_str(),"entrylist");
  TEntryList *myListMC = (TEntryList*) gDirectory->Get("myListMC");
  InFileComparison->SetEntryList(myListMC); 
  
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
  
  
  
  //---- EE
  for (int iEE = 0; iEE <4; iEE++) {
    drawSingleModule(InFile, InFileComparison, nameOutputDir, commonCut, -100, iEE, 0, 0, 0);
  }
    
  //---- EB
  for (int iEB = 0; iEB <36; iEB++) {
    drawSingleModule(InFile, InFileComparison, nameOutputDir, commonCut, iEB, -100, 0, 0, 0);
  }

  //---- summary regions
  for (int iSpecial = 0; iSpecial <4; iSpecial++) {
    drawSingleModule(InFile, InFileComparison, nameOutputDir, commonCut, -100, -100, 0, iSpecial+1, 0);
  }
  
}


