#include "TDRStyle.cc"

#include "Functions.h"

#include <iostream>
#include <fstream>
#include <sstream>


void drawComparison(TString nameMCTxt, TString nameDataTxt, TString nameData2Txt = ""){


 TDRStyle();
 
 gStyle->SetTitleYOffset(1.1);
 gStyle->cd();
 
 //TString nameDataTxt = "/eos/user/a/amkrishn/www/EcalAlignment/MC2022_run3Commisioning/validation_plots/with_rotationEE/DATA.txt";
 //TString nameMCTxt = "/eos/user/a/amkrishn/www/EcalAlignment/MC2022_run3Commisioning/validation_plots/with_correct_MCbias/test/MC.txt";
 //TString nameData2Txt = "";

 std::ifstream fileData  (nameDataTxt.Data()); 
 std::ifstream fileData2 (nameData2Txt.Data()); 
 std::ifstream fileMC    (nameMCTxt.Data()); 
 
 double Deta_SM_Mean[36];                          double Deta_SM_Mean_DATA[36];                   double Deta_SM_Mean_DATA2[36];
 double Dphi_SM_Mean[36];                          double Dphi_SM_Mean_DATA[36];                   double Dphi_SM_Mean_DATA2[36];
 double DphiEm_SM_Mean[36];                        double DphiEm_SM_Mean_DATA[36];                 double DphiEm_SM_Mean_DATA2[36];
 double DphiEp_SM_Mean[36];                        double DphiEp_SM_Mean_DATA[36];                 double DphiEp_SM_Mean_DATA2[36]; 
 
 double Deta_SM_RMS[36];                           double Deta_SM_RMS_DATA[36];                    double Deta_SM_RMS_DATA2[36];
 double Dphi_SM_RMS[36];                           double Dphi_SM_RMS_DATA[36];                    double Dphi_SM_RMS_DATA2[36];
 double DphiEm_SM_RMS[36];                         double DphiEm_SM_RMS_DATA[36];                  double DphiEm_SM_RMS_DATA2[36];
 double DphiEp_SM_RMS[36];                         double DphiEp_SM_RMS_DATA[36];                  double DphiEp_SM_RMS_DATA2[36];
 
 double Deta_SM_Entries[36];                       double Deta_SM_Entries_DATA[36];                double Deta_SM_Entries_DATA2[36];
 double Dphi_SM_Entries[36];                       double Dphi_SM_Entries_DATA[36];                double Dphi_SM_Entries_DATA2[36];
 double DphiEm_SM_Entries[36];                     double DphiEm_SM_Entries_DATA[36];              double DphiEm_SM_Entries_DATA2[36];
 double DphiEp_SM_Entries[36];                     double DphiEp_SM_Entries_DATA[36];              double DphiEp_SM_Entries_DATA2[36]; 
 
 
 double Deta_DEE_Mean[4];                          double Deta_DEE_Mean_DATA[4];                   double Deta_DEE_Mean_DATA2[4];
 double Dphi_DEE_Mean[4];                          double Dphi_DEE_Mean_DATA[4];                   double Dphi_DEE_Mean_DATA2[4];
 double DphiEm_DEE_Mean[4];                        double DphiEm_DEE_Mean_DATA[4];                 double DphiEm_DEE_Mean_DATA2[4];
 double DphiEp_DEE_Mean[4];                        double DphiEp_DEE_Mean_DATA[4];                 double DphiEp_DEE_Mean_DATA2[4]; 
 
 double Deta_DEE_RMS[4];                           double Deta_DEE_RMS_DATA[4];                    double Deta_DEE_RMS_DATA2[4];
 double Dphi_DEE_RMS[4];                           double Dphi_DEE_RMS_DATA[4];                    double Dphi_DEE_RMS_DATA2[4];
 double DphiEm_DEE_RMS[4];                         double DphiEm_DEE_RMS_DATA[4];                  double DphiEm_DEE_RMS_DATA2[4];
 double DphiEp_DEE_RMS[4];                         double DphiEp_DEE_RMS_DATA[4];                  double DphiEp_DEE_RMS_DATA2[4];
 
 double Deta_DEE_Entries[4];                       double Deta_DEE_Entries_DATA[4];                double Deta_DEE_Entries_DATA2[4];
 double Dphi_DEE_Entries[4];                       double Dphi_DEE_Entries_DATA[4];                double Dphi_DEE_Entries_DATA2[4];
 double DphiEm_DEE_Entries[4];                     double DphiEm_DEE_Entries_DATA[4];              double DphiEm_DEE_Entries_DATA2[4];
 double DphiEp_DEE_Entries[4];                     double DphiEp_DEE_Entries_DATA[4];              double DphiEp_DEE_Entries_DATA2[4]; 
 
 
 std::string buffer;
 int numSM;
 int numDEE;
  
 bool isData2 = true;
 
 if(!fileData.is_open()) {
  std::cerr << "** ERROR: Can't open '" << nameDataTxt.Data() << "' for input" << std::endl;
 }
 if(!fileData2.is_open()) {
  std::cerr << "** ERROR: Can't open '" << nameData2Txt.Data() << "' for input" << std::endl;
  isData2 = false;
 }
 if(!fileMC.is_open()) {
  std::cerr << "** ERROR: Can't open '" << nameMCTxt.Data() << "' for input" << std::endl;
 }
 
 while (!fileMC.eof()) {
  getline(fileMC,buffer);
//   std::cout << "buffer = " << buffer << std::endl;
  if (buffer != ""){ ///---> save from empty line at the end!
   std::stringstream line( buffer );      
   line >> numSM; 
   std::cout << numSM << " ";
   line >> numDEE; 
   std::cout << numDEE << " "<<std::endl;

   if (numSM!=-100) {
    line >> Dphi_SM_Mean[numSM];    std::cout << " " << Dphi_SM_Mean[numSM];
    line >> Dphi_SM_RMS[numSM];     std::cout << " " << Dphi_SM_RMS[numSM];
    line >> Dphi_SM_Entries[numSM]; std::cout << " " << Dphi_SM_Entries[numSM];
   
    std::cout<<std::endl;

    line >> DphiEp_SM_Mean[numSM];    std::cout << " " << DphiEp_SM_Mean[numSM];
    line >> DphiEp_SM_RMS[numSM];     std::cout << " " << DphiEp_SM_RMS[numSM];
    line >> DphiEp_SM_Entries[numSM]; std::cout << " " << DphiEp_SM_Entries[numSM];
    
  std::cout<<std::endl;

    line >> DphiEm_SM_Mean[numSM];    std::cout << " " << DphiEm_SM_Mean[numSM];
    line >> DphiEm_SM_RMS[numSM];     std::cout << " " << DphiEm_SM_RMS[numSM];
    line >> DphiEm_SM_Entries[numSM]; std::cout << " " << DphiEm_SM_Entries[numSM];

   std::cout<<std::endl;

    line >> Deta_SM_Mean[numSM];    std::cout << " " << Deta_SM_Mean[numSM];
    line >> Deta_SM_RMS[numSM];     std::cout << " " << Deta_SM_RMS[numSM];
    line >> Deta_SM_Entries[numSM]; std::cout << " " << Deta_SM_Entries[numSM];
    std::cout<<std::endl;
   }
   if (numDEE!=-100) {
    line >> Dphi_DEE_Mean[numDEE];    std::cout << " " << Dphi_DEE_Mean[numDEE];
    line >> Dphi_DEE_RMS[numDEE];     std::cout << " " << Dphi_DEE_RMS[numDEE];
    line >> Dphi_DEE_Entries[numDEE]; std::cout << " " << Dphi_DEE_Entries[numDEE];
    
    std::cout<<std::endl;

    line >> DphiEp_DEE_Mean[numDEE];    std::cout << " " << DphiEp_DEE_Mean[numDEE];
    line >> DphiEp_DEE_RMS[numDEE];     std::cout << " " << DphiEp_DEE_RMS[numDEE];
    line >> DphiEp_DEE_Entries[numDEE]; std::cout << " " << DphiEp_DEE_Entries[numDEE];
    
    std::cout<<std::endl;

    line >> DphiEm_DEE_Mean[numDEE];    std::cout << " " << DphiEm_DEE_Mean[numDEE];
    line >> DphiEm_DEE_RMS[numDEE];     std::cout << " " << DphiEm_DEE_RMS[numDEE];
    line >> DphiEm_DEE_Entries[numDEE]; std::cout << " " << DphiEm_DEE_Entries[numDEE];

    std::cout<<std::endl;

    line >> Deta_DEE_Mean[numDEE];    std::cout << " " << Deta_DEE_Mean[numDEE];
    line >> Deta_DEE_RMS[numDEE];     std::cout << " " << Deta_DEE_RMS[numDEE];
    line >> Deta_DEE_Entries[numDEE]; std::cout << " " << Deta_DEE_Entries[numDEE];
    
    std::cout<<std::endl;
   }
  } 
  
 }

 
 
 while (!fileData.eof()) {
  getline(fileData,buffer);
  //   std::cout << "buffer = " << buffer << std::endl;
  if (buffer != ""){ ///---> save from empty line at the end!
   std::stringstream line( buffer );      
   line >> numSM; 
   std::cout << numSM << " ";
   line >> numDEE; 
   std::cout << numDEE << " "<<std::endl;
   
   if (numSM!=-100) {
    line >> Dphi_SM_Mean_DATA[numSM];    std::cout << " " << Dphi_SM_Mean_DATA[numSM];
    line >> Dphi_SM_RMS_DATA[numSM];     std::cout << " " << Dphi_SM_RMS_DATA[numSM];
    line >> Dphi_SM_Entries_DATA[numSM]; std::cout << " " << Dphi_SM_Entries_DATA[numSM];

    std::cout<<std::endl;
    
    line >> DphiEp_SM_Mean_DATA[numSM];    std::cout << " " << DphiEp_SM_Mean_DATA[numSM];
    line >> DphiEp_SM_RMS_DATA[numSM];     std::cout << " " << DphiEp_SM_RMS_DATA[numSM];
    line >> DphiEp_SM_Entries_DATA[numSM]; std::cout << " " << DphiEp_SM_Entries_DATA[numSM];

    std::cout<<std::endl;
    
    line >> DphiEm_SM_Mean_DATA[numSM];    std::cout << " " << DphiEm_SM_Mean_DATA[numSM];
    line >> DphiEm_SM_RMS_DATA[numSM];     std::cout << " " << DphiEm_SM_RMS_DATA[numSM];
    line >> DphiEm_SM_Entries_DATA[numSM]; std::cout << " " << DphiEm_SM_Entries_DATA[numSM];

    std::cout<<std::endl;
    
    line >> Deta_SM_Mean_DATA[numSM];    std::cout << " " << Deta_SM_Mean_DATA[numSM];
    line >> Deta_SM_RMS_DATA[numSM];     std::cout << " " << Deta_SM_RMS_DATA[numSM];
    line >> Deta_SM_Entries_DATA[numSM]; std::cout << " " << Deta_SM_Entries_DATA[numSM];

    std::cout<<std::endl;
    
   }
   if (numDEE!=-100) {
    line >> Dphi_DEE_Mean_DATA[numDEE];    std::cout << " " << Dphi_DEE_Mean_DATA[numDEE];
    line >> Dphi_DEE_RMS_DATA[numDEE];     std::cout << " " << Dphi_DEE_RMS_DATA[numDEE];
    line >> Dphi_DEE_Entries_DATA[numDEE]; std::cout << " " << Dphi_DEE_Entries_DATA[numDEE];

    std::cout<<std::endl;
    
    line >> DphiEp_DEE_Mean_DATA[numDEE];    std::cout << " " << DphiEp_DEE_Mean_DATA[numDEE];
    line >> DphiEp_DEE_RMS_DATA[numDEE];     std::cout << " " << DphiEp_DEE_RMS_DATA[numDEE];
    line >> DphiEp_DEE_Entries_DATA[numDEE]; std::cout << " " << DphiEp_DEE_Entries_DATA[numDEE];

    std::cout<<std::endl;
    
    line >> DphiEm_DEE_Mean_DATA[numDEE];    std::cout << " " << DphiEm_DEE_Mean_DATA[numDEE];
    line >> DphiEm_DEE_RMS_DATA[numDEE];     std::cout << " " << DphiEm_DEE_RMS_DATA[numDEE];
    line >> DphiEm_DEE_Entries_DATA[numDEE]; std::cout << " " << DphiEm_DEE_Entries_DATA[numDEE];

    std::cout<<std::endl;
    
    line >> Deta_DEE_Mean_DATA[numDEE];    std::cout << " " << Deta_DEE_Mean_DATA[numDEE];
    line >> Deta_DEE_RMS_DATA[numDEE];     std::cout << " " << Deta_DEE_RMS_DATA[numDEE];
    line >> Deta_DEE_Entries_DATA[numDEE]; std::cout << " " << Deta_DEE_Entries_DATA[numDEE];

    std::cout<<std::endl;
    
   }
  } 
  
 }
 
 
 
 
 
 
 while ( isData2 && !fileData2.eof()) {
  getline(fileData2,buffer);
  //   std::cout << "buffer = " << buffer << std::endl;
  if (buffer != ""){ ///---> save from empty line at the end!
   std::stringstream line( buffer );      
   line >> numSM; 
   std::cout << numSM << " " ;
   line >> numDEE; 
   std::cout << numDEE << " "<<std::endl;
   
   if (numSM!=-100) {
    line >> Dphi_SM_Mean_DATA2[numSM];    std::cout << " " << Dphi_SM_Mean_DATA2[numSM];
    line >> Dphi_SM_RMS_DATA2[numSM];     std::cout << " " << Dphi_SM_RMS_DATA2[numSM];
    line >> Dphi_SM_Entries_DATA2[numSM]; std::cout << " " << Dphi_SM_Entries_DATA2[numSM];
    
    std::cout<<std::endl;

    line >> DphiEp_SM_Mean_DATA2[numSM];    std::cout << " " << DphiEp_SM_Mean_DATA2[numSM];
    line >> DphiEp_SM_RMS_DATA2[numSM];     std::cout << " " << DphiEp_SM_RMS_DATA2[numSM];
    line >> DphiEp_SM_Entries_DATA2[numSM]; std::cout << " " << DphiEp_SM_Entries_DATA2[numSM];
    
    line >> DphiEm_SM_Mean_DATA2[numSM];    std::cout << " " << DphiEm_SM_Mean_DATA2[numSM];
    line >> DphiEm_SM_RMS_DATA2[numSM];     std::cout << " " << DphiEm_SM_RMS_DATA2[numSM];
    line >> DphiEm_SM_Entries_DATA2[numSM]; std::cout << " " << DphiEm_SM_Entries_DATA2[numSM];
    
    line >> Deta_SM_Mean_DATA2[numSM];    std::cout << " " << Deta_SM_Mean_DATA2[numSM];
    line >> Deta_SM_RMS_DATA2[numSM];     std::cout << " " << Deta_SM_RMS_DATA2[numSM];
    line >> Deta_SM_Entries_DATA2[numSM]; std::cout << " " << Deta_SM_Entries_DATA2[numSM];
    
   }
   else {
    line >> Dphi_DEE_Mean_DATA2[numDEE];    std::cout << " " << Dphi_DEE_Mean_DATA2[numDEE];
    line >> Dphi_DEE_RMS_DATA2[numDEE];     std::cout << " " << Dphi_DEE_RMS_DATA2[numDEE];
    line >> Dphi_DEE_Entries_DATA2[numDEE]; std::cout << " " << Dphi_DEE_Entries_DATA2[numDEE];
    
    line >> DphiEp_DEE_Mean_DATA2[numDEE];    std::cout << " " << DphiEp_DEE_Mean_DATA2[numDEE];
    line >> DphiEp_DEE_RMS_DATA2[numDEE];     std::cout << " " << DphiEp_DEE_RMS_DATA2[numDEE];
    line >> DphiEp_DEE_Entries_DATA2[numDEE]; std::cout << " " << DphiEp_DEE_Entries_DATA2[numDEE];
    
    line >> DphiEm_DEE_Mean_DATA2[numDEE];    std::cout << " " << DphiEm_DEE_Mean_DATA2[numDEE];
    line >> DphiEm_DEE_RMS_DATA2[numDEE];     std::cout << " " << DphiEm_DEE_RMS_DATA2[numDEE];
    line >> DphiEm_DEE_Entries_DATA2[numDEE]; std::cout << " " << DphiEm_DEE_Entries_DATA2[numDEE];
    
    line >> Deta_DEE_Mean_DATA2[numDEE];    std::cout << " " << Deta_DEE_Mean_DATA2[numDEE];
    line >> Deta_DEE_RMS_DATA2[numDEE];     std::cout << " " << Deta_DEE_RMS_DATA2[numDEE];
    line >> Deta_DEE_Entries_DATA2[numDEE]; std::cout << " " << Deta_DEE_Entries_DATA2[numDEE];
    
   }
  } 
  
 }
 
 
 //---- plot

 std::string outDir = "/eos/user/a/amkrishn/www/EcalAlignment/MC2022_run3Commisioning/validation_plots/deta_dphi_per_partition/";

 TLegend *legend = new TLegend(0.8,0.8,0.90,0.9);
 legend->SetBorderSize(0);

 double SM[36];
 double DEE[4];
 double Zero[36];
 for (int i=0; i<36; i++) {
  SM[i] = i;
  Zero[i] = 0;
 }
 for (int i=0; i<4; i++) {
  DEE[i] = i;
 }
 
 for (int i=0; i<36; i++) {
  Dphi_SM_RMS[i] = Dphi_SM_RMS[i] / sqrt (Dphi_SM_Entries[i]);
  DphiEm_SM_RMS[i] = DphiEm_SM_RMS[i] / sqrt (DphiEm_SM_Entries[i]);
  DphiEp_SM_RMS[i] = DphiEp_SM_RMS[i] / sqrt (DphiEp_SM_Entries[i]);
  Deta_SM_RMS[i] = Deta_SM_RMS[i] / sqrt (Deta_SM_Entries[i]);
 }
 
 for (int i=0; i<36; i++) {
  Dphi_SM_RMS_DATA[i] = Dphi_SM_RMS_DATA[i] / sqrt (Dphi_SM_Entries_DATA[i]);
  DphiEm_SM_RMS_DATA[i] = DphiEm_SM_RMS_DATA[i] / sqrt (DphiEm_SM_Entries_DATA[i]);
  DphiEp_SM_RMS_DATA[i] = DphiEp_SM_RMS_DATA[i] / sqrt (DphiEp_SM_Entries_DATA[i]);
  Deta_SM_RMS_DATA[i] = Deta_SM_RMS_DATA[i] / sqrt (Deta_SM_Entries_DATA[i]);

  if (isData2) {
   Dphi_SM_RMS_DATA2[i] = Dphi_SM_RMS_DATA2[i] / sqrt (Dphi_SM_Entries_DATA2[i]);
   DphiEm_SM_RMS_DATA2[i] = DphiEm_SM_RMS_DATA2[i] / sqrt (DphiEm_SM_Entries_DATA2[i]);
   DphiEp_SM_RMS_DATA2[i] = DphiEp_SM_RMS_DATA2[i] / sqrt (DphiEp_SM_Entries_DATA2[i]);
   Deta_SM_RMS_DATA2[i] = Deta_SM_RMS_DATA2[i] / sqrt (Deta_SM_Entries_DATA2[i]);
  }
 }
 
 
 for (int i=0; i<4; i++) {
  Dphi_DEE_RMS[i] = Dphi_DEE_RMS[i] / sqrt (Dphi_DEE_Entries[i]);
  DphiEm_DEE_RMS[i] = DphiEm_DEE_RMS[i] / sqrt (DphiEm_DEE_Entries[i]);
  DphiEp_DEE_RMS[i] = DphiEp_DEE_RMS[i] / sqrt (DphiEp_DEE_Entries[i]);
  Deta_DEE_RMS[i] = Deta_DEE_RMS[i] / sqrt (Deta_DEE_Entries[i]);

  Dphi_DEE_RMS_DATA[i] = Dphi_DEE_RMS_DATA[i] / sqrt (Dphi_DEE_Entries_DATA[i]);
  DphiEm_DEE_RMS_DATA[i] = DphiEm_DEE_RMS_DATA[i] / sqrt (DphiEm_DEE_Entries_DATA[i]);
  DphiEp_DEE_RMS_DATA[i] = DphiEp_DEE_RMS_DATA[i] / sqrt (DphiEp_DEE_Entries_DATA[i]);
  Deta_DEE_RMS_DATA[i] = Deta_DEE_RMS_DATA[i] / sqrt (Deta_DEE_Entries_DATA[i]);

 }
 

 //---- delta phi
 
 //TCanvas* cSM_Dphi = new TCanvas ("cSM_Dphi","cSM_Dphi",900,900);
 //cSM_Dphi->Divide(1,3);
 TCanvas* cSM_Dphi = new TCanvas();
 cSM_Dphi->cd();
 TGraphErrors* gr_SM_Dphi = new TGraphErrors(36,SM,Dphi_SM_Mean,Zero,Dphi_SM_RMS);
 gr_SM_Dphi->SetTitle("#Delta#phi");
 gr_SM_Dphi->SetMarkerColor(kRed);
 gr_SM_Dphi->SetLineColor(kRed);
 gr_SM_Dphi->SetMarkerStyle(20);
 gr_SM_Dphi->SetMarkerSize(1);
 gr_SM_Dphi->SetLineWidth(1);
 gr_SM_Dphi->GetYaxis()->SetTitle("#Delta#phi");
 gr_SM_Dphi->GetXaxis()->SetTitle("iSM");

 TGraphErrors* gr_SM_Dphi_DATA = new TGraphErrors(36,SM,Dphi_SM_Mean_DATA,Zero,Dphi_SM_RMS_DATA);
 gr_SM_Dphi_DATA->SetTitle("#Delta#phi");
 gr_SM_Dphi_DATA->SetMarkerColor(kBlue);
 gr_SM_Dphi_DATA->SetLineColor(kBlue);
 gr_SM_Dphi_DATA->SetMarkerStyle(21);
 gr_SM_Dphi_DATA->SetMarkerSize(1);
 gr_SM_Dphi_DATA->SetLineWidth(1);
 gr_SM_Dphi_DATA->GetYaxis()->SetTitle("#Delta#phi");

 /* std::cout<<std::endl<<"TEST"<<std::endl;
  float maxMC = TMath::MaxElement(gr_SM_Dphi->GetN(),gr_SM_Dphi->GetY());
  float minMC = TMath::MinElement(gr_SM_Dphi->GetN(),gr_SM_Dphi->GetY());
  std::cout<<TMath::MaxElement(gr_SM_Dphi->GetN(),gr_SM_Dphi->GetY())<< "   " << TMath::MinElement(gr_SM_Dphi->GetN(),gr_SM_Dphi->GetY())<<std::endl;
 std::cout<<std::max(gr_SM_Dphi->GetMaximum(), gr_SM_Dphi_DATA->GetMaximum())<<std::endl;
 std::cout<<std::max(gr_SM_Dphi->GetMaximum(), gr_SM_Dphi_DATA->GetMaximum()) + 0.4e-3 <<std::endl;
 std::cout<<std::min(gr_SM_Dphi->GetMaximum(), gr_SM_Dphi_DATA->GetMaximum())<<std::endl;
 std::cout<<std::min(gr_SM_Dphi->GetMaximum(), gr_SM_Dphi_DATA->GetMaximum()) - 0.4e-3 <<std::endl;  */
 
//to fix the range of the plots
 double maxMC = TMath::MaxElement(gr_SM_Dphi->GetN(),gr_SM_Dphi->GetY());
 double maxDATA = TMath::MaxElement(gr_SM_Dphi_DATA->GetN(),gr_SM_Dphi_DATA->GetY());
 double minMC = TMath::MinElement(gr_SM_Dphi->GetN(),gr_SM_Dphi->GetY());
 double minDATA = TMath::MinElement(gr_SM_Dphi_DATA->GetN(),gr_SM_Dphi_DATA->GetY());
 gr_SM_Dphi->SetMaximum(std::max(maxMC, maxDATA) + 0.4e-3);
 gr_SM_Dphi->SetMinimum(std::min(minMC, minDATA) - 0.4e-3);
 gr_SM_Dphi->Draw("AP");
 gr_SM_Dphi_DATA->Draw("P");

 legend->AddEntry(gr_SM_Dphi,"MC","PE");
 legend->AddEntry(gr_SM_Dphi_DATA,"data","PE");
 legend->Draw();
 
 if (isData2) {
  TGraphErrors* gr_SM_Dphi_DATA2 = new TGraphErrors(36,SM,Dphi_SM_Mean_DATA2,Zero,Dphi_SM_RMS_DATA2);
  gr_SM_Dphi_DATA2->SetTitle("#Delta#phi");
  gr_SM_Dphi_DATA2->SetMarkerColor(kGreen);
  gr_SM_Dphi_DATA2->SetLineColor(kGreen);
  gr_SM_Dphi_DATA2->SetMarkerStyle(21);
  gr_SM_Dphi_DATA2->SetMarkerSize(1);
  gr_SM_Dphi_DATA2->SetLineWidth(1);
  gr_SM_Dphi_DATA2->GetYaxis()->SetTitle("#Delta#phi");
  gr_SM_Dphi_DATA2->Draw("P");
 }
 
 gPad->SetGrid();

 cSM_Dphi->Print(Form("%s/SM_deltaPhi.png",outDir.c_str()));
 cSM_Dphi->Print(Form("%s/SM_deltaPhi.pdf",outDir.c_str()));

  //TCanvas* cSM_Dphi2 = new TCanvas ("cSM_Dphi2","cSM_Dphi2",900,900);
  TCanvas* cSM_Dphi2 = new TCanvas();
  cSM_Dphi2->cd();
 //cSM_Dphi->cd(2);
 TGraphErrors* gr_SM_DphiEp = new TGraphErrors(36,SM,DphiEp_SM_Mean,Zero,DphiEp_SM_RMS);
 gr_SM_DphiEp->SetTitle("#Delta#phiEp");
 gr_SM_DphiEp->SetMarkerColor(kRed);
 gr_SM_DphiEp->SetLineColor(kRed);
 gr_SM_DphiEp->SetMarkerStyle(20);
 gr_SM_DphiEp->SetMarkerSize(1);
 gr_SM_DphiEp->SetLineWidth(1);
 //gr_SM_DphiEp->SetMinimum(-0.2e-3);
 gr_SM_DphiEp->GetYaxis()->SetTitle("#Delta#phi e^{+}");
 gr_SM_DphiEp->GetXaxis()->SetTitle("iSM");
 //gr_SM_DphiEp->Draw("AP");
 
 TGraphErrors* gr_SM_DphiEp_DATA = new TGraphErrors(36,SM,DphiEp_SM_Mean_DATA,Zero,DphiEp_SM_RMS_DATA);
 gr_SM_DphiEp_DATA->SetTitle("#Delta#phiEp");
 gr_SM_DphiEp_DATA->SetMarkerColor(kBlue);
 gr_SM_DphiEp_DATA->SetLineColor(kBlue);
 gr_SM_DphiEp_DATA->SetMarkerStyle(21);
 gr_SM_DphiEp_DATA->SetMarkerSize(1);
 gr_SM_DphiEp_DATA->SetLineWidth(1);
 gr_SM_DphiEp_DATA->GetYaxis()->SetTitle("#Delta#phi e^{+}");
 //gr_SM_DphiEp_DATA->Draw("P");

 maxMC = TMath::MaxElement(gr_SM_DphiEp->GetN(),gr_SM_DphiEp->GetY());
 maxDATA = TMath::MaxElement(gr_SM_DphiEp_DATA->GetN(),gr_SM_DphiEp_DATA->GetY());
 minMC = TMath::MinElement(gr_SM_DphiEp->GetN(),gr_SM_DphiEp->GetY());
 minDATA = TMath::MinElement(gr_SM_DphiEp_DATA->GetN(),gr_SM_DphiEp_DATA->GetY());
 gr_SM_DphiEp->SetMaximum(std::max(maxMC, maxDATA) + 0.4e-3);
 gr_SM_DphiEp->SetMinimum(std::min(minMC, minDATA) - 0.4e-3);
 gr_SM_DphiEp->Draw("AP");
 gr_SM_DphiEp_DATA->Draw("P");

 legend->Draw();
 
 if (isData2) {
  TGraphErrors* gr_SM_DphiEp_DATA2 = new TGraphErrors(36,SM,DphiEp_SM_Mean_DATA2,Zero,DphiEp_SM_RMS_DATA2);
  gr_SM_DphiEp_DATA2->SetTitle("#Delta#phiEp");
  gr_SM_DphiEp_DATA2->SetMarkerColor(kGreen);
  gr_SM_DphiEp_DATA2->SetLineColor(kGreen);
  gr_SM_DphiEp_DATA2->SetMarkerStyle(21);
  gr_SM_DphiEp_DATA2->SetMarkerSize(1);
  gr_SM_DphiEp_DATA2->SetLineWidth(1);
  gr_SM_DphiEp_DATA2->GetYaxis()->SetTitle("#Delta#phi e^{+}");
  gr_SM_DphiEp_DATA2->Draw("P");
 }
 
 gPad->SetGrid();

 cSM_Dphi2->Print(Form("%s/SM_deltaPhi_ep.png",outDir.c_str()));
 cSM_Dphi2->Print(Form("%s/SM_deltaPhi_ep.pdf",outDir.c_str()));

 
 //TCanvas* cSM_Dphi3 = new TCanvas ("cSM_Dphi3","cSM_Dphi3",900,900);
 TCanvas* cSM_Dphi3 = new TCanvas();
  cSM_Dphi3->cd();
 //cSM_Dphi->cd(3);
 TGraphErrors* gr_SM_DphiEm = new TGraphErrors(36,SM,DphiEm_SM_Mean,Zero,DphiEm_SM_RMS);
 gr_SM_DphiEm->SetTitle("#Delta#phiEm");
 gr_SM_DphiEm->SetMarkerColor(kRed);
 gr_SM_DphiEm->SetLineColor(kRed);
 gr_SM_DphiEm->SetMarkerStyle(20);
 gr_SM_DphiEm->SetMarkerSize(1);
 gr_SM_DphiEm->SetLineWidth(1);
 //gr_SM_DphiEm->SetMaximum(0.2e-3);
 gr_SM_DphiEm->GetYaxis()->SetTitle("#Delta#phi e^{-}");
 gr_SM_DphiEm->GetXaxis()->SetTitle("iSM");
 //gr_SM_DphiEm->Draw("AP");
 
 TGraphErrors* gr_SM_DphiEm_DATA = new TGraphErrors(36,SM,DphiEm_SM_Mean_DATA,Zero,DphiEm_SM_RMS_DATA);
 gr_SM_DphiEm_DATA->SetTitle("#Delta#phiEm");
 gr_SM_DphiEm_DATA->SetMarkerColor(kBlue);
 gr_SM_DphiEm_DATA->SetLineColor(kBlue);
 gr_SM_DphiEm_DATA->SetMarkerStyle(21);
 gr_SM_DphiEm_DATA->SetMarkerSize(1);
 gr_SM_DphiEm_DATA->SetLineWidth(1);
 gr_SM_DphiEm_DATA->GetYaxis()->SetTitle("#Delta#phi e^{-}");
 //gr_SM_DphiEm_DATA->Draw("P");

 
 maxMC = TMath::MaxElement(gr_SM_DphiEm->GetN(),gr_SM_DphiEm->GetY());
 maxDATA = TMath::MaxElement(gr_SM_DphiEm_DATA->GetN(),gr_SM_DphiEm_DATA->GetY());
 minMC = TMath::MinElement(gr_SM_DphiEm->GetN(),gr_SM_DphiEm->GetY());
 minDATA = TMath::MinElement(gr_SM_DphiEm_DATA->GetN(),gr_SM_DphiEm_DATA->GetY());
 gr_SM_DphiEm->SetMaximum(std::max(maxMC, maxDATA) + 0.4e-3);
 gr_SM_DphiEm->SetMinimum(std::min(minMC, minDATA) - 0.4e-3);
 gr_SM_DphiEm->Draw("AP");
 gr_SM_DphiEm_DATA->Draw("P");

 legend->Draw();
 
 if (isData2) {
  TGraphErrors* gr_SM_DphiEm_DATA2 = new TGraphErrors(36,SM,DphiEm_SM_Mean_DATA2,Zero,DphiEm_SM_RMS_DATA2);
  gr_SM_DphiEm_DATA2->SetTitle("#Delta#phiEm");
  gr_SM_DphiEm_DATA2->SetMarkerColor(kGreen);
  gr_SM_DphiEm_DATA2->SetLineColor(kGreen);
  gr_SM_DphiEm_DATA2->SetMarkerStyle(21);
  gr_SM_DphiEm_DATA2->SetMarkerSize(1);
  gr_SM_DphiEm_DATA2->SetLineWidth(1);
  gr_SM_DphiEm_DATA2->GetYaxis()->SetTitle("#Delta#phi e^{-}");
  gr_SM_DphiEm_DATA2->Draw("P");
 }
 
 gPad->SetGrid();
 
 cSM_Dphi3->Print(Form("%s/SM_deltaPhi_em.png",outDir.c_str()));
 cSM_Dphi3->Print(Form("%s/SM_deltaPhi_em.pdf",outDir.c_str()));

 
 //TCanvas* cDEE_Dphi = new TCanvas ("cDEE_Dphi","cDEE_Dphi",900,900);
 //cDEE_Dphi->Divide(1,3);
 TCanvas* cDEE_Dphi = new TCanvas();
 cDEE_Dphi->cd();
 TGraphErrors* gr_DEE_Dphi = new TGraphErrors(4,DEE,Dphi_DEE_Mean,Zero,Dphi_DEE_RMS);
 gr_DEE_Dphi->SetTitle("#Delta#phi");
 gr_DEE_Dphi->SetMarkerColor(kRed);
 gr_DEE_Dphi->SetLineColor(kRed);
 gr_DEE_Dphi->SetMarkerStyle(20);
 gr_DEE_Dphi->SetMarkerSize(1);
 gr_DEE_Dphi->SetLineWidth(1);
 //gr_DEE_Dphi->SetMaximum(0.6e-3);
 //gr_DEE_Dphi->SetMinimum(-0.6e-3);
 gr_DEE_Dphi->GetYaxis()->SetTitle("#Delta#phi");
 gr_DEE_Dphi->GetXaxis()->SetTitle("iDEE");
 //gr_DEE_Dphi->Draw("AP");
 
 TGraphErrors* gr_DEE_Dphi_DATA = new TGraphErrors(4,DEE,Dphi_DEE_Mean_DATA,Zero,Dphi_DEE_RMS_DATA);
 gr_DEE_Dphi_DATA->SetTitle("#Delta#phi");
 gr_DEE_Dphi_DATA->SetMarkerColor(kBlue);
 gr_DEE_Dphi_DATA->SetLineColor(kBlue);
 gr_DEE_Dphi_DATA->SetMarkerStyle(21);
 gr_DEE_Dphi_DATA->SetMarkerSize(1);
 gr_DEE_Dphi_DATA->SetLineWidth(1);
 gr_DEE_Dphi_DATA->GetYaxis()->SetTitle("#Delta#phi");
 //gr_DEE_Dphi_DATA->Draw("P");

 
 maxMC = TMath::MaxElement(gr_DEE_Dphi->GetN(),gr_DEE_Dphi->GetY());
 maxDATA = TMath::MaxElement(gr_DEE_Dphi_DATA->GetN(),gr_DEE_Dphi_DATA->GetY());
 minMC = TMath::MinElement(gr_DEE_Dphi->GetN(),gr_DEE_Dphi->GetY());
 minDATA = TMath::MinElement(gr_DEE_Dphi_DATA->GetN(),gr_DEE_Dphi_DATA->GetY());
 gr_DEE_Dphi->SetMaximum(std::max(maxMC, maxDATA) + 0.4e-3);
 gr_DEE_Dphi->SetMinimum(std::min(minMC, minDATA) - 0.4e-3);
 gr_DEE_Dphi->Draw("AP");
 gr_DEE_Dphi_DATA->Draw("P");
 legend->Draw();
 
 if (isData2) {
  TGraphErrors* gr_DEE_Dphi_DATA2 = new TGraphErrors(4,DEE,Dphi_DEE_Mean_DATA2,Zero,Dphi_DEE_RMS_DATA2);
  gr_DEE_Dphi_DATA2->SetTitle("#Delta#phi");
  gr_DEE_Dphi_DATA2->SetMarkerColor(kGreen);
  gr_DEE_Dphi_DATA2->SetLineColor(kGreen);
  gr_DEE_Dphi_DATA2->SetMarkerStyle(21);
  gr_DEE_Dphi_DATA2->SetMarkerSize(1);
  gr_DEE_Dphi_DATA2->SetLineWidth(1);
  gr_DEE_Dphi_DATA2->GetYaxis()->SetTitle("#Delta#phi");
  gr_DEE_Dphi_DATA2->Draw("P");
 }
 
 gPad->SetGrid();
 
 cDEE_Dphi->Print(Form("%s/DEE_deltaPhi.png",outDir.c_str()));
 cDEE_Dphi->Print(Form("%s/DEE_deltaPhi.pdf",outDir.c_str()));

 //TCanvas* cDEE_Dphi2 = new TCanvas ("cDEE_Dphi2","cDEE_Dphi2",900,900);
 TCanvas* cDEE_Dphi2 = new TCanvas();
 cDEE_Dphi2->cd();
 TGraphErrors* gr_DEE_DphiEp = new TGraphErrors(4,DEE,DphiEp_DEE_Mean,Zero,DphiEp_DEE_RMS);
 gr_DEE_DphiEp->SetTitle("#Delta#phiEp");
 gr_DEE_DphiEp->SetMarkerColor(kRed);
 gr_DEE_DphiEp->SetLineColor(kRed);
 gr_DEE_DphiEp->SetMarkerStyle(20);
 gr_DEE_DphiEp->SetMarkerSize(1);
 gr_DEE_DphiEp->SetLineWidth(1);
 gr_DEE_DphiEp->SetMaximum(0.6e-3);
 gr_DEE_DphiEp->SetMinimum(-0.6e-3);
 gr_DEE_DphiEp->GetYaxis()->SetTitle("#Delta#phi e^{+}");
 gr_DEE_DphiEp->GetXaxis()->SetTitle("iDEE");
 gr_DEE_DphiEp->Draw("AP");
 
 TGraphErrors* gr_DEE_DphiEp_DATA = new TGraphErrors(4,DEE,DphiEp_DEE_Mean_DATA,Zero,DphiEp_DEE_RMS_DATA);
 gr_DEE_DphiEp_DATA->SetTitle("#Delta#phiEp");
 gr_DEE_DphiEp_DATA->SetMarkerColor(kBlue);
 gr_DEE_DphiEp_DATA->SetLineColor(kBlue);
 gr_DEE_DphiEp_DATA->SetMarkerStyle(21);
 gr_DEE_DphiEp_DATA->SetMarkerSize(1);
 gr_DEE_DphiEp_DATA->SetLineWidth(1);
 gr_DEE_DphiEp_DATA->GetYaxis()->SetTitle("#Delta#phi e^{+}");
 gr_DEE_DphiEp_DATA->Draw("P");

 maxMC = TMath::MaxElement(gr_DEE_DphiEp->GetN(),gr_DEE_DphiEp->GetY());
 maxDATA = TMath::MaxElement(gr_DEE_DphiEp_DATA->GetN(),gr_DEE_DphiEp_DATA->GetY());
 minMC = TMath::MinElement(gr_DEE_DphiEp->GetN(),gr_DEE_DphiEp->GetY());
 minDATA = TMath::MinElement(gr_DEE_DphiEp_DATA->GetN(),gr_DEE_DphiEp_DATA->GetY());
 gr_DEE_DphiEp->SetMaximum(std::max(maxMC, maxDATA) + 0.4e-3);
 gr_DEE_DphiEp->SetMinimum(std::min(minMC, minDATA) - 0.4e-3);
 gr_DEE_DphiEp->Draw("AP");
 gr_DEE_DphiEp_DATA->Draw("P");
 legend->Draw();
 
 if (isData2) {
  TGraphErrors* gr_DEE_DphiEp_DATA2 = new TGraphErrors(4,DEE,DphiEp_DEE_Mean_DATA2,Zero,DphiEp_DEE_RMS_DATA2);
  gr_DEE_DphiEp_DATA2->SetTitle("#Delta#phiEp");
  gr_DEE_DphiEp_DATA2->SetMarkerColor(kGreen);
  gr_DEE_DphiEp_DATA2->SetLineColor(kGreen);
  gr_DEE_DphiEp_DATA2->SetMarkerStyle(21);
  gr_DEE_DphiEp_DATA2->SetMarkerSize(1);
  gr_DEE_DphiEp_DATA2->SetLineWidth(1);
  gr_DEE_DphiEp_DATA2->GetYaxis()->SetTitle("#Delta#phi e^{+}");
  gr_DEE_DphiEp_DATA2->Draw("P");
 }
 
 gPad->SetGrid();

 cDEE_Dphi2->Print(Form("%s/DEE_deltaPhi_ep.png",outDir.c_str()));
 cDEE_Dphi2->Print(Form("%s/DEE_deltaPhi_ep.pdf",outDir.c_str()));

 //TCanvas* cDEE_Dphi3 = new TCanvas ("cDEE_Dphi3","cDEE_Dphi3",900,900);
 TCanvas* cDEE_Dphi3 = new TCanvas();
 cDEE_Dphi3->cd();
 TGraphErrors* gr_DEE_DphiEm = new TGraphErrors(4,DEE,DphiEm_DEE_Mean,Zero,DphiEm_DEE_RMS);
 gr_DEE_DphiEm->SetTitle("#Delta#phiEm");
 gr_DEE_DphiEm->SetMarkerColor(kRed);
 gr_DEE_DphiEm->SetLineColor(kRed);
 gr_DEE_DphiEm->SetMarkerStyle(20);
 gr_DEE_DphiEm->SetMarkerSize(1);
 gr_DEE_DphiEm->SetLineWidth(1);
 //gr_DEE_DphiEm->SetMaximum(0.6e-3);
 //gr_DEE_DphiEm->SetMinimum(-0.6e-3);
 gr_DEE_DphiEm->GetYaxis()->SetTitle("#Delta#phi e^{-}");
 gr_DEE_DphiEm->GetXaxis()->SetTitle("iDEE");
 //gr_DEE_DphiEm->Draw("AP");
 
 TGraphErrors* gr_DEE_DphiEm_DATA = new TGraphErrors(4,DEE,DphiEm_DEE_Mean_DATA,Zero,DphiEm_DEE_RMS_DATA);
 gr_DEE_DphiEm_DATA->SetTitle("#Delta#phiEm");
 gr_DEE_DphiEm_DATA->SetMarkerColor(kBlue);
 gr_DEE_DphiEm_DATA->SetLineColor(kBlue);
 gr_DEE_DphiEm_DATA->SetMarkerStyle(21);
 gr_DEE_DphiEm_DATA->SetMarkerSize(1);
 gr_DEE_DphiEm_DATA->SetLineWidth(1);
 gr_DEE_DphiEm_DATA->GetYaxis()->SetTitle("#Delta#phi e^{-}");
 //gr_DEE_DphiEm_DATA->Draw("P");

 maxMC = TMath::MaxElement(gr_DEE_DphiEm->GetN(),gr_DEE_DphiEm->GetY());
 maxDATA = TMath::MaxElement(gr_DEE_DphiEm_DATA->GetN(),gr_DEE_DphiEm_DATA->GetY());
 minMC = TMath::MinElement(gr_DEE_DphiEm->GetN(),gr_DEE_DphiEm->GetY());
 minDATA = TMath::MinElement(gr_DEE_DphiEm_DATA->GetN(),gr_DEE_DphiEm_DATA->GetY());
 gr_DEE_DphiEm->SetMaximum(std::max(maxMC,maxDATA) + 0.4e-3);
 gr_DEE_DphiEm->SetMinimum(std::min(minMC, minDATA) - 0.4e-3);
 gr_DEE_DphiEm->Draw("AP");
 gr_DEE_DphiEm_DATA->Draw("P");
 legend->Draw();
 
 if (isData2) {
  TGraphErrors* gr_DEE_DphiEm_DATA2 = new TGraphErrors(4,DEE,DphiEm_DEE_Mean_DATA2,Zero,DphiEm_DEE_RMS_DATA2);
  gr_DEE_DphiEm_DATA2->SetTitle("#Delta#phiEm");
  gr_DEE_DphiEm_DATA2->SetMarkerColor(kGreen);
  gr_DEE_DphiEm_DATA2->SetLineColor(kGreen);
  gr_DEE_DphiEm_DATA2->SetMarkerStyle(21);
  gr_DEE_DphiEm_DATA2->SetMarkerSize(1);
  gr_DEE_DphiEm_DATA2->SetLineWidth(1);
  gr_DEE_DphiEm_DATA2->GetYaxis()->SetTitle("#Delta#phi e^{-}");
  gr_DEE_DphiEm_DATA2->Draw("P");
 }
 
 gPad->SetGrid();
 
 cDEE_Dphi3->Print(Form("%s/DEE_deltaPhi_em.png",outDir.c_str()));
 cDEE_Dphi3->Print(Form("%s/DEE_deltaPhi_em.pdf",outDir.c_str()));
 
 
 //---- delta eta
 
 //TCanvas* cSM_Deta = new TCanvas ("cSM_Deta","cSM_Deta",900,300);
 TCanvas* cSM_Deta = new TCanvas();
 TGraphErrors* gr_SM_Deta = new TGraphErrors(36,SM,Deta_SM_Mean,Zero,Deta_SM_RMS);
 gr_SM_Deta->SetTitle("#Delta#eta");
 gr_SM_Deta->SetMarkerColor(kRed);
 gr_SM_Deta->SetLineColor(kRed);
 gr_SM_Deta->SetMarkerStyle(20);
 gr_SM_Deta->SetMarkerSize(1);
 gr_SM_Deta->SetLineWidth(1);
 //gr_SM_Deta->SetMaximum(0.6e-3);
 //gr_SM_Dphi->SetMinimum(-0.6e-3);
 gr_SM_Deta->GetYaxis()->SetTitle("#Delta#eta");
 gr_SM_Deta->GetXaxis()->SetTitle("iSM");
 //gr_SM_Deta->Draw("AP");
 
 TGraphErrors* gr_SM_Deta_DATA = new TGraphErrors(36,SM,Deta_SM_Mean_DATA,Zero,Deta_SM_RMS_DATA);
 gr_SM_Deta_DATA->SetTitle("#Delta#eta");
 gr_SM_Deta_DATA->SetMarkerColor(kBlue);
 gr_SM_Deta_DATA->SetLineColor(kBlue);
 gr_SM_Deta_DATA->SetMarkerStyle(21);
 gr_SM_Deta_DATA->SetMarkerSize(1);
 gr_SM_Deta_DATA->SetLineWidth(1);
 gr_SM_Deta_DATA->GetYaxis()->SetTitle("#Delta#eta");
 //gr_SM_Deta_DATA->Draw("P");


 maxMC = TMath::MaxElement(gr_SM_Deta->GetN(),gr_SM_Deta->GetY());
 maxDATA = TMath::MaxElement(gr_SM_Deta_DATA->GetN(),gr_SM_Deta_DATA->GetY());
 minMC = TMath::MinElement(gr_SM_Deta->GetN(),gr_SM_Deta->GetY());
 minDATA = TMath::MinElement(gr_SM_Deta_DATA->GetN(),gr_SM_Deta_DATA->GetY());
 gr_SM_Deta->SetMaximum(std::max(maxMC, maxDATA) + 0.4e-3);
 gr_SM_Deta->SetMinimum(std::min(minMC, minDATA) - 0.4e-3);
 gr_SM_Deta->Draw("AP");
 gr_SM_Deta_DATA->Draw("P");
 legend->Draw();
 
 if (isData2) { 
  TGraphErrors* gr_SM_Deta_DATA2 = new TGraphErrors(36,SM,Deta_SM_Mean_DATA2,Zero,Deta_SM_RMS_DATA2);
  gr_SM_Deta_DATA2->SetTitle("#Delta#eta");
  gr_SM_Deta_DATA2->SetMarkerColor(kGreen);
  gr_SM_Deta_DATA2->SetLineColor(kGreen);
  gr_SM_Deta_DATA2->SetMarkerStyle(21);
  gr_SM_Deta_DATA2->SetMarkerSize(1);
  gr_SM_Deta_DATA2->SetLineWidth(1);
  gr_SM_Deta_DATA2->GetYaxis()->SetTitle("#Delta#eta");
  gr_SM_Deta_DATA2->Draw("P");
 }
 
 gPad->SetGrid();
 
 cSM_Deta->Print(Form("%s/SM_deltaEta.png",outDir.c_str()));
 cSM_Deta->Print(Form("%s/SM_deltaEta.pdf",outDir.c_str()));
 
 //TCanvas* cDEE_Deta = new TCanvas ("cDEE_Deta","cDEE_Deta",900,300);
 TCanvas* cDEE_Deta = new TCanvas();
 TGraphErrors* gr_DEE_Deta = new TGraphErrors(4,DEE,Deta_DEE_Mean,Zero,Deta_DEE_RMS);
 gr_DEE_Deta->SetTitle("#Delta#eta");
 gr_DEE_Deta->SetMarkerColor(kRed);
 gr_DEE_Deta->SetLineColor(kRed);
 gr_DEE_Deta->SetMarkerStyle(20);
 gr_DEE_Deta->SetMarkerSize(1);
 gr_DEE_Deta->SetLineWidth(1);
 //gr_DEE_Deta->SetMaximum(0.8e-3);
 //gr_DEE_Deta->SetMinimum(-0.8e-3);
 gr_DEE_Deta->GetYaxis()->SetTitle("#Delta#eta");
 gr_DEE_Deta->GetXaxis()->SetTitle("iDEE");
 //gr_DEE_Deta->Draw("AP");
 
 TGraphErrors* gr_DEE_Deta_DATA = new TGraphErrors(4,DEE,Deta_DEE_Mean_DATA,Zero,Deta_DEE_RMS_DATA);
 gr_DEE_Deta_DATA->SetTitle("#Delta#eta");
 gr_DEE_Deta_DATA->SetMarkerColor(kBlue);
 gr_DEE_Deta_DATA->SetLineColor(kBlue);
 gr_DEE_Deta_DATA->SetMarkerStyle(21);
 gr_DEE_Deta_DATA->SetMarkerSize(1);
 gr_DEE_Deta_DATA->SetLineWidth(1);
 gr_DEE_Deta_DATA->GetYaxis()->SetTitle("#Delta#eta");
 //gr_DEE_Deta_DATA->Draw("P");

 maxMC = TMath::MaxElement(gr_DEE_Deta->GetN(),gr_DEE_Deta->GetY());
 maxDATA = TMath::MaxElement(gr_DEE_Deta_DATA->GetN(),gr_DEE_Deta_DATA->GetY());
 minMC = TMath::MinElement(gr_DEE_Deta->GetN(),gr_DEE_Deta->GetY());
 minDATA = TMath::MinElement(gr_DEE_Deta_DATA->GetN(),gr_DEE_Deta_DATA->GetY());
 gr_DEE_Deta->SetMaximum(std::max(maxMC, maxDATA) + 0.4e-3);
 gr_DEE_Deta->SetMinimum(std::min(minMC, minDATA) - 0.4e-3);
 gr_DEE_Deta->Draw("AP");
 gr_DEE_Deta_DATA->Draw("P");
 legend->Draw();
 
 if (isData2) {
  TGraphErrors* gr_DEE_Deta_DATA2 = new TGraphErrors(4,DEE,Deta_DEE_Mean_DATA2,Zero,Deta_DEE_RMS_DATA2);
  gr_DEE_Deta_DATA2->SetTitle("#Delta#eta");
  gr_DEE_Deta_DATA2->SetMarkerColor(kGreen);
  gr_DEE_Deta_DATA2->SetLineColor(kGreen);
  gr_DEE_Deta_DATA2->SetMarkerStyle(21);
  gr_DEE_Deta_DATA2->SetMarkerSize(1);
  gr_DEE_Deta_DATA2->SetLineWidth(1);
  gr_DEE_Deta_DATA2->GetYaxis()->SetTitle("#Delta#eta");
  gr_DEE_Deta_DATA2->Draw("P");
 }
 
 gPad->SetGrid();

 cDEE_Deta->Print(Form("%s/DEE_deltaEta.png",outDir.c_str()));
 cDEE_Deta->Print(Form("%s/DEE_deltaEta.pdf",outDir.c_str()));


}