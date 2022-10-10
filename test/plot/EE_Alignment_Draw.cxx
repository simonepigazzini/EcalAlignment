void set_gr_range(TGraphErrors* gMC, TGraphErrors* gDATA){
 float mxMC = TMath::MaxElement(gMC->GetN(),gMC->GetY());
 float mxDATA = TMath::MaxElement(gDATA->GetN(),gDATA->GetY());
 float mnMC = TMath::MinElement(gMC->GetN(),gMC->GetY());
 float mnDATA = TMath::MinElement(gDATA->GetN(),gDATA->GetY());
 gMC->SetMaximum(std::max(mxMC,mxDATA) + 0.005);
 gMC->SetMinimum(std::min(mnMC, mnDATA) - 0.005);
}



void EE_Alignment_Draw(std::string nameFile, std::string nameFileComparison="../data/myEEAlignment_default.txt", int withError = 0) {
 
 double Z = 3.205;

 
 
 ///===========================================================================
 std::string buffer;
 
 //==== kRed
 std::cout << std::endl << " Reference File: " << nameFileComparison << std::endl;
 
 double DX_SM_Mean[4];
 double DX_SM_RMS[4];
 double DY_SM_Mean[4];
 double DY_SM_RMS[4];
 double DZ_SM_Mean[4];
 double DZ_SM_RMS[4];
 
 double DTHETAe_SM_Mean[4];
 double DTHETAe_SM_RMS[4];
 double DPSIe_SM_Mean[4];
 double DPSIe_SM_RMS[4];
 double DPHIe_SM_Mean[4];
 double DPHIe_SM_RMS[4];

 std::ifstream file (nameFileComparison.c_str()); 

 if (!file.is_open()){
  std::cout << "noooo" << std::endl;
 }
 int iSM_After = 0;
 while(!file.eof()){
  getline(file,buffer);
//   std::cout << "buffer = " << buffer; // << std::endl;
  if (buffer != ""){ ///---> save from empty line at the end!
   std::stringstream line( buffer );       
   line >> DPHIe_SM_Mean[iSM_After]; std::cout << " " << DPHIe_SM_Mean[iSM_After];
   line >> DTHETAe_SM_Mean[iSM_After];   std::cout << " " << DTHETAe_SM_Mean[iSM_After];
   line >> DPSIe_SM_Mean[iSM_After];   std::cout << " " << DPSIe_SM_Mean[iSM_After];
   line >> DX_SM_Mean[iSM_After];      std::cout << " " << DX_SM_Mean[iSM_After];
   line >> DY_SM_Mean[iSM_After];      std::cout << " " << DY_SM_Mean[iSM_After];
   line >> DZ_SM_Mean[iSM_After];      std::cout << " " << DZ_SM_Mean[iSM_After];
   std::cout << std::endl;
   iSM_After++;
  }
 }
 
 
 ///===========================================================================

//==== kBlue

std::cout << std::endl << " New File: " << nameFile << std::endl;

 std::ifstream fileEle (nameFile.c_str()); 
  
 double DX_SM_Mean_After[4];
 double DX_SM_RMS_After[4];
 double DY_SM_Mean_After[4];
 double DY_SM_RMS_After[4];
 double DZ_SM_Mean_After[4];
 double DZ_SM_RMS_After[4];
 
 
 double DTHETAe_SM_Mean_After[4];
 double DTHETAe_SM_RMS_After[4];
 double DPSIe_SM_Mean_After[4];
 double DPSIe_SM_RMS_After[4];
 double DPHIe_SM_Mean_After[4];
 double DPHIe_SM_RMS_After[4];
 
 for (int i=0; i<4; i++) {
  DX_SM_RMS[i] = 0;
  DY_SM_RMS[i] = 0;
  DZ_SM_RMS[i] = 0;
  DX_SM_RMS_After[i] = 0;
  DY_SM_RMS_After[i] = 0;
  DZ_SM_RMS_After[i] = 0;

  DTHETAe_SM_RMS[i] = 0;
  DPSIe_SM_RMS[i] = 0;
  DPHIe_SM_RMS[i] = 0;
  DTHETAe_SM_RMS_After[i] = 0;
  DPSIe_SM_RMS_After[i] = 0;
  DPHIe_SM_RMS_After[i] = 0;

 }
 
 double iSM_SM_Ele[4];
 double iSM_SM_Ele_RMS[38];
    
 if (!fileEle.is_open()){
  std::cout << "noooo" << std::endl;
 }
 iSM_After = 0;
 while(!fileEle.eof()){
  getline(fileEle,buffer);
//   std::cout << "buffer = " << buffer; // << std::endl;
  if (buffer != ""){ ///---> save from empty line at the end!
   std::stringstream line( buffer );       
   iSM_SM_Ele[iSM_After] = iSM_After;
   iSM_SM_Ele_RMS[iSM_After] = 0;

   line >> DPHIe_SM_Mean_After[iSM_After]; std::cout << " " << DPHIe_SM_Mean_After[iSM_After];
   line >> DTHETAe_SM_Mean_After[iSM_After];   std::cout << " " << DTHETAe_SM_Mean_After[iSM_After];
   line >> DPSIe_SM_Mean_After[iSM_After];   std::cout << " " << DPSIe_SM_Mean_After[iSM_After];
   line >> DX_SM_Mean_After[iSM_After];      std::cout << " " << DX_SM_Mean_After[iSM_After];
   line >> DY_SM_Mean_After[iSM_After];      std::cout << " " << DY_SM_Mean_After[iSM_After];
   line >> DZ_SM_Mean_After[iSM_After];      std::cout << " " << DZ_SM_Mean_After[iSM_After];

   if (withError) {
    line >> DPHIe_SM_RMS_After[iSM_After]; std::cout << " " << DPHIe_SM_RMS_After[iSM_After];
    line >> DTHETAe_SM_RMS_After[iSM_After];   std::cout << " " << DTHETAe_SM_RMS_After[iSM_After];
    line >> DPSIe_SM_RMS_After[iSM_After];   std::cout << " " << DPSIe_SM_RMS_After[iSM_After];
    line >> DX_SM_RMS_After[iSM_After];      std::cout << " " << DX_SM_RMS_After[iSM_After];
    line >> DY_SM_RMS_After[iSM_After];      std::cout << " " << DY_SM_RMS_After[iSM_After];
    line >> DZ_SM_RMS_After[iSM_After];      std::cout << " " << DZ_SM_RMS_After[iSM_After];
   }
   std::cout << std::endl;
   
   iSM_After++;
  }
 }
  
  ///===========================================================================
  ///===========================================================================


  /*
 TCanvas* cSM_DX_DY_DZ_Scatter = new TCanvas ("cSM_DX_DY_DZ_Scatter","cSM_DX_DY_DZ_Scatter",1000,800);
 cSM_DX_DY_DZ_Scatter->Divide(2,3);
  
 TF1* line1 = new TF1("line1","x",-2,2);
 line1->SetLineColor(kGreen);

  ///===================================
 cSM_DX_DY_DZ_Scatter->cd(1);
 TGraphErrors* grDZ_EEMinus_Scatter = new TGraphErrors(2,DZ_SM_Mean_After+2,DZ_SM_Mean+2,DZ_SM_RMS_After+2,DZ_SM_RMS+2);
 grDZ_EEMinus_Scatter->SetTitle("EE- #DeltaZ #DeltaZ");
 grDZ_EEMinus_Scatter->SetMarkerColor(kRed);
 grDZ_EEMinus_Scatter->SetLineColor(kRed);
 grDZ_EEMinus_Scatter->SetMarkerStyle(20);
 grDZ_EEMinus_Scatter->SetMarkerSize(1);
 grDZ_EEMinus_Scatter->SetLineWidth(1);
 grDZ_EEMinus_Scatter->GetXaxis()->SetTitle("#DeltaZ After");
 grDZ_EEMinus_Scatter->GetYaxis()->SetTitle("#DeltaZ Before");
 grDZ_EEMinus_Scatter->Draw("AP");
 line1->Draw("same");
 gPad->SetGrid();
  
 cSM_DX_DY_DZ_Scatter->cd(2);
 TGraphErrors* grDZ_EEPlus_Scatter = new TGraphErrors(2,DZ_SM_Mean_After,DZ_SM_Mean,DZ_SM_RMS_After,DZ_SM_RMS);
 grDZ_EEPlus_Scatter->SetTitle("EE+ #DeltaZ #DeltaZ");
 grDZ_EEPlus_Scatter->SetMarkerColor(kRed);
 grDZ_EEPlus_Scatter->SetLineColor(kRed);
 grDZ_EEPlus_Scatter->SetMarkerStyle(20);
 grDZ_EEPlus_Scatter->SetMarkerSize(1);
 grDZ_EEPlus_Scatter->SetLineWidth(1);
 grDZ_EEPlus_Scatter->GetXaxis()->SetTitle("#DeltaZ After");
 grDZ_EEPlus_Scatter->GetYaxis()->SetTitle("#DeltaZ Before");
 grDZ_EEPlus_Scatter->Draw("AP");
 line1->Draw("same");
 gPad->SetGrid();
  
  ///===================================
 cSM_DX_DY_DZ_Scatter->cd(3);
 TGraphErrors* grDY_EEMinus_Scatter = new TGraphErrors(2,DY_SM_Mean_After+2,DY_SM_Mean+2,DY_SM_RMS_After+2,DY_SM_RMS+2);
 grDY_EEMinus_Scatter->SetTitle("EE- #DeltaY #DeltaY");
 grDY_EEMinus_Scatter->SetMarkerColor(kRed);
 grDY_EEMinus_Scatter->SetLineColor(kRed);
 grDY_EEMinus_Scatter->SetMarkerStyle(20);
 grDY_EEMinus_Scatter->SetMarkerSize(1);
 grDY_EEMinus_Scatter->SetLineWidth(1);
 grDY_EEMinus_Scatter->GetXaxis()->SetTitle("#DeltaY After");
 grDY_EEMinus_Scatter->GetYaxis()->SetTitle("#DeltaY Before");
 grDY_EEMinus_Scatter->Draw("AP");
 line1->Draw("same");
 gPad->SetGrid();
  
 cSM_DX_DY_DZ_Scatter->cd(4);
 TGraphErrors* grDY_EEPlus_Scatter = new TGraphErrors(2,DY_SM_Mean_After,DY_SM_Mean,DY_SM_RMS_After,DY_SM_RMS);
 grDY_EEPlus_Scatter->SetTitle("EE+ #DeltaY #DeltaY");
 grDY_EEPlus_Scatter->SetMarkerColor(kRed);
 grDY_EEPlus_Scatter->SetLineColor(kRed);
 grDY_EEPlus_Scatter->SetMarkerStyle(20);
 grDY_EEPlus_Scatter->SetMarkerSize(1);
 grDY_EEPlus_Scatter->SetLineWidth(1);
 grDY_EEPlus_Scatter->GetXaxis()->SetTitle("#DeltaY After");
 grDY_EEPlus_Scatter->GetYaxis()->SetTitle("#DeltaY Before");
 grDY_EEPlus_Scatter->Draw("AP");
 line1->Draw("same");
 gPad->SetGrid();
  
  ///===================================
 cSM_DX_DY_DZ_Scatter->cd(5);
 TGraphErrors* grDX_EEMinus_Scatter = new TGraphErrors(2,DX_SM_Mean_After+2,DX_SM_Mean+2,DX_SM_RMS_After+2,DX_SM_RMS+2);
 grDX_EEMinus_Scatter->SetTitle("EE- #DeltaX #DeltaX");
 grDX_EEMinus_Scatter->SetMarkerColor(kRed);
 grDX_EEMinus_Scatter->SetLineColor(kRed);
 grDX_EEMinus_Scatter->SetMarkerStyle(20);
 grDX_EEMinus_Scatter->SetMarkerSize(1);
 grDX_EEMinus_Scatter->SetLineWidth(1);
 grDX_EEMinus_Scatter->GetXaxis()->SetTitle("#DeltaX After");
 grDX_EEMinus_Scatter->GetYaxis()->SetTitle("#DeltaX Before");
 grDX_EEMinus_Scatter->Draw("AP");
 line1->Draw("same");
 gPad->SetGrid();
  
 cSM_DX_DY_DZ_Scatter->cd(6);
 TGraphErrors* grDX_EEPlus_Scatter = new TGraphErrors(2,DX_SM_Mean_After,DX_SM_Mean,DX_SM_RMS_After,DX_SM_RMS);
 grDX_EEPlus_Scatter->SetTitle("EE+ #DeltaX #DeltaX");
 grDX_EEPlus_Scatter->SetMarkerColor(kRed);
 grDX_EEPlus_Scatter->SetLineColor(kRed);
 grDX_EEPlus_Scatter->SetMarkerStyle(20);
 grDX_EEPlus_Scatter->SetMarkerSize(1);
 grDX_EEPlus_Scatter->SetLineWidth(1);
 grDX_EEPlus_Scatter->GetXaxis()->SetTitle("#DeltaX After");
 grDX_EEPlus_Scatter->GetYaxis()->SetTitle("#DeltaX Before");
 grDX_EEPlus_Scatter->Draw("AP");
 line1->Draw("same");
 gPad->SetGrid();
  
  
  */
  ///===========================================================================
  ///===========================================================================
  ///===========================================================================
 TCanvas* cSM_DX_DY_DZ = new TCanvas ("cSM_DX_DY_DZ","cSM_DX_DY_DZ",800,800);
 cSM_DX_DY_DZ->Divide(2,3);
  
  
  ///===================================
 cSM_DX_DY_DZ->cd(1);
 TGraphErrors* grDZ_EEMinus_Ele = new TGraphErrors(2,iSM_SM_Ele+2,DZ_SM_Mean+2,iSM_SM_Ele_RMS+2,DZ_SM_RMS+2);
 grDZ_EEMinus_Ele->SetTitle("EE- #DeltaZ");
 grDZ_EEMinus_Ele->SetMarkerColor(kRed);
 grDZ_EEMinus_Ele->SetLineColor(kRed);
 grDZ_EEMinus_Ele->SetMarkerStyle(20);
 grDZ_EEMinus_Ele->SetMarkerSize(1);
 grDZ_EEMinus_Ele->SetLineWidth(1);
 grDZ_EEMinus_Ele->GetXaxis()->SetTitle("iDee");
 grDZ_EEMinus_Ele->GetYaxis()->SetTitle("#DeltaZ (cm)");
 //grDZ_EEMinus_Ele->Draw("AP");
 gPad->SetGrid();
  
 TGraphErrors* grDZ_EEMinus_After = new TGraphErrors(2,iSM_SM_Ele+2,DZ_SM_Mean_After+2,iSM_SM_Ele_RMS,DZ_SM_RMS_After+2);
 grDZ_EEMinus_After->SetMarkerColor(kBlue);
 grDZ_EEMinus_After->SetLineColor(kBlue);
 grDZ_EEMinus_After->SetMarkerStyle(21);
 grDZ_EEMinus_After->SetMarkerSize(1);
 grDZ_EEMinus_After->SetLineWidth(1);
 grDZ_EEMinus_After->GetXaxis()->SetTitle("iDee");
 grDZ_EEMinus_After->GetYaxis()->SetTitle("#DeltaZ (cm)");
 //grDZ_EEMinus_After->Draw("P");
 gPad->SetGrid();

 double maxMC = TMath::MaxElement(grDZ_EEMinus_Ele->GetN(),grDZ_EEMinus_Ele->GetY());
 double maxDATA = TMath::MaxElement(grDZ_EEMinus_After->GetN(),grDZ_EEMinus_After->GetY());
 double minMC = TMath::MinElement(grDZ_EEMinus_Ele->GetN(),grDZ_EEMinus_Ele->GetY());
 double minDATA = TMath::MinElement(grDZ_EEMinus_After->GetN(),grDZ_EEMinus_After->GetY());
 grDZ_EEMinus_Ele->SetMaximum(std::max(maxMC,maxDATA) + 0.02);
 grDZ_EEMinus_Ele->SetMinimum(std::min(minMC, minDATA) - 0.02);
 grDZ_EEMinus_Ele->Draw("AP");
 grDZ_EEMinus_After->Draw("P");
  
  
 cSM_DX_DY_DZ->cd(2);
 TGraphErrors* grDZ_EEPlus_Ele = new TGraphErrors(2,iSM_SM_Ele,DZ_SM_Mean,iSM_SM_Ele_RMS,DZ_SM_RMS);
 grDZ_EEPlus_Ele->SetTitle("EE+ #DeltaZ");
 grDZ_EEPlus_Ele->SetMarkerColor(kRed);
 grDZ_EEPlus_Ele->SetLineColor(kRed);
 grDZ_EEPlus_Ele->SetMarkerStyle(20);
 grDZ_EEPlus_Ele->SetMarkerSize(1);
 grDZ_EEPlus_Ele->SetLineWidth(1);
 grDZ_EEPlus_Ele->GetXaxis()->SetTitle("iDee");
 grDZ_EEPlus_Ele->GetYaxis()->SetTitle("#DeltaZ (cm)");
 //grDZ_EEPlus_Ele->Draw("AP");
 gPad->SetGrid();
  
 TGraphErrors* grDZ_EEPlus_After = new TGraphErrors(2,iSM_SM_Ele,DZ_SM_Mean_After,iSM_SM_Ele_RMS,DZ_SM_RMS_After);
 grDZ_EEPlus_After->SetMarkerColor(kBlue);
 grDZ_EEPlus_After->SetLineColor(kBlue);
 grDZ_EEPlus_After->SetMarkerStyle(21);
 grDZ_EEPlus_After->SetMarkerSize(1);
 grDZ_EEPlus_After->SetLineWidth(1);
 grDZ_EEPlus_After->GetXaxis()->SetTitle("iDee");
 grDZ_EEPlus_After->GetYaxis()->SetTitle("#DeltaZ (cm)");
 //grDZ_EEPlus_After->Draw("P");
 gPad->SetGrid();
  
 maxMC = TMath::MaxElement(grDZ_EEPlus_Ele->GetN(),grDZ_EEPlus_Ele->GetY());
 maxDATA = TMath::MaxElement(grDZ_EEPlus_After->GetN(),grDZ_EEPlus_After->GetY());
 minMC = TMath::MinElement(grDZ_EEPlus_Ele->GetN(),grDZ_EEPlus_Ele->GetY());
 minDATA = TMath::MinElement(grDZ_EEPlus_After->GetN(),grDZ_EEPlus_After->GetY());
 grDZ_EEPlus_Ele->SetMaximum(std::max(maxMC,maxDATA) + 0.02);
 grDZ_EEPlus_Ele->SetMinimum(std::min(minMC, minDATA) - 0.02);
 grDZ_EEPlus_Ele->Draw("AP");
 grDZ_EEPlus_After->Draw("P");

  ///===================================
 cSM_DX_DY_DZ->cd(3);
 TGraphErrors* grDY_EEMinus_Ele = new TGraphErrors(2,iSM_SM_Ele+2,DY_SM_Mean+2,iSM_SM_Ele_RMS+2,DY_SM_RMS+2);
 grDY_EEMinus_Ele->SetTitle("EE- #DeltaY");
 grDY_EEMinus_Ele->SetMarkerColor(kRed);
 grDY_EEMinus_Ele->SetLineColor(kRed);
 grDY_EEMinus_Ele->SetMarkerStyle(20);
 grDY_EEMinus_Ele->SetMarkerSize(1);
 grDY_EEMinus_Ele->SetLineWidth(1);
 grDY_EEMinus_Ele->GetXaxis()->SetTitle("iDee");
 grDY_EEMinus_Ele->GetYaxis()->SetTitle("#DeltaY (cm)");
 //grDY_EEMinus_Ele->Draw("AP");
 gPad->SetGrid();
  
 TGraphErrors* grDY_EEMinus_After = new TGraphErrors(2,iSM_SM_Ele+2,DY_SM_Mean_After+2,iSM_SM_Ele_RMS+2,DY_SM_RMS_After+2);
 grDY_EEMinus_After->SetMarkerColor(kBlue);
 grDY_EEMinus_After->SetLineColor(kBlue);
 grDY_EEMinus_After->SetMarkerStyle(21);
 grDY_EEMinus_After->SetMarkerSize(1);
 grDY_EEMinus_After->SetLineWidth(1);
 grDY_EEMinus_After->GetXaxis()->SetTitle("iDee");
 grDY_EEMinus_After->GetYaxis()->SetTitle("#DeltaY (cm)");
 //grDY_EEMinus_After->Draw("P");
 gPad->SetGrid();
  
 maxMC = TMath::MaxElement(grDY_EEMinus_Ele->GetN(),grDY_EEMinus_Ele->GetY());
 maxDATA = TMath::MaxElement(grDY_EEMinus_After->GetN(),grDY_EEMinus_After->GetY());
 minMC = TMath::MinElement(grDY_EEMinus_Ele->GetN(),grDY_EEMinus_Ele->GetY());
 minDATA = TMath::MinElement(grDY_EEMinus_After->GetN(),grDY_EEMinus_After->GetY());
 grDY_EEMinus_Ele->SetMaximum(std::max(maxMC,maxDATA) + 0.02);
 grDY_EEMinus_Ele->SetMinimum(std::min(minMC, minDATA) - 0.02);
 grDY_EEMinus_Ele->Draw("AP");
 grDY_EEMinus_After->Draw("P");
  
 cSM_DX_DY_DZ->cd(4);
 TGraphErrors* grDY_EEPlus_Ele = new TGraphErrors(2,iSM_SM_Ele,DY_SM_Mean,iSM_SM_Ele_RMS,DY_SM_RMS);
 grDY_EEPlus_Ele->SetTitle("EE+ #DeltaY");
 grDY_EEPlus_Ele->SetMarkerColor(kRed);
 grDY_EEPlus_Ele->SetLineColor(kRed);
 grDY_EEPlus_Ele->SetMarkerStyle(20);
 grDY_EEPlus_Ele->SetMarkerSize(1);
 grDY_EEPlus_Ele->SetLineWidth(1);
 grDY_EEPlus_Ele->GetXaxis()->SetTitle("iDee");
 grDY_EEPlus_Ele->GetYaxis()->SetTitle("#DeltaY (cm)");
 //grDY_EEPlus_Ele->Draw("AP");
 gPad->SetGrid();
  
 TGraphErrors* grDY_EEPlus_After = new TGraphErrors(2,iSM_SM_Ele,DY_SM_Mean_After,iSM_SM_Ele_RMS,DY_SM_RMS_After);
 grDY_EEPlus_After->SetMarkerColor(kBlue);
 grDY_EEPlus_After->SetLineColor(kBlue);
 grDY_EEPlus_After->SetMarkerStyle(21);
 grDY_EEPlus_After->SetMarkerSize(1);
 grDY_EEPlus_After->SetLineWidth(1);
 grDY_EEPlus_After->GetXaxis()->SetTitle("iDee");
 grDY_EEPlus_After->GetYaxis()->SetTitle("#DeltaY (cm)");
 //grDY_EEPlus_After->Draw("P");
 gPad->SetGrid();

 maxMC = TMath::MaxElement(grDY_EEPlus_Ele->GetN(),grDY_EEPlus_Ele->GetY());
 maxDATA = TMath::MaxElement(grDY_EEPlus_After->GetN(),grDY_EEPlus_After->GetY());
 minMC = TMath::MinElement(grDY_EEPlus_Ele->GetN(),grDY_EEPlus_Ele->GetY());
 minDATA = TMath::MinElement(grDY_EEPlus_After->GetN(),grDY_EEPlus_After->GetY());
 grDY_EEPlus_Ele->SetMaximum(std::max(maxMC,maxDATA) + 0.02);
 grDY_EEPlus_Ele->SetMinimum(std::min(minMC, minDATA) - 0.02);
 grDY_EEPlus_Ele->Draw("AP");
 grDY_EEPlus_After->Draw("P");
  
  ///===================================
 cSM_DX_DY_DZ->cd(5);
 TGraphErrors* grDX_EEMinus_Ele = new TGraphErrors(2,iSM_SM_Ele+2,DX_SM_Mean+2,iSM_SM_Ele_RMS+2,DX_SM_RMS+2);
 grDX_EEMinus_Ele->SetTitle("EE- #DeltaX");
 grDX_EEMinus_Ele->SetMarkerColor(kRed);
 grDX_EEMinus_Ele->SetLineColor(kRed);
 grDX_EEMinus_Ele->SetMarkerStyle(20);
 grDX_EEMinus_Ele->SetMarkerSize(1);
 grDX_EEMinus_Ele->SetLineWidth(1);
 grDX_EEMinus_Ele->GetXaxis()->SetTitle("iDee");
 grDX_EEMinus_Ele->GetYaxis()->SetTitle("#DeltaX (cm)");
 //grDX_EEMinus_Ele->Draw("AP");
 gPad->SetGrid();
  
 TGraphErrors* grDX_EEMinus_After = new TGraphErrors(2,iSM_SM_Ele+2,DX_SM_Mean_After+2,iSM_SM_Ele_RMS+2,DX_SM_RMS_After+2);
 grDX_EEMinus_After->SetMarkerColor(kBlue);
 grDX_EEMinus_After->SetLineColor(kBlue);
 grDX_EEMinus_After->SetMarkerStyle(21);
 grDX_EEMinus_After->SetMarkerSize(1);
 grDX_EEMinus_After->SetLineWidth(1);
 grDX_EEMinus_After->GetXaxis()->SetTitle("iDee");
 grDX_EEMinus_After->GetYaxis()->SetTitle("#DeltaX (cm)");
 //grDX_EEMinus_After->Draw("P");
 gPad->SetGrid();
  
 maxMC = TMath::MaxElement(grDX_EEMinus_Ele->GetN(),grDX_EEMinus_Ele->GetY());
 maxDATA = TMath::MaxElement(grDX_EEMinus_After->GetN(),grDX_EEMinus_After->GetY());
 minMC = TMath::MinElement(grDX_EEMinus_Ele->GetN(),grDX_EEMinus_Ele->GetY());
 minDATA = TMath::MinElement(grDX_EEMinus_After->GetN(),grDX_EEMinus_After->GetY());
 grDX_EEMinus_Ele->SetMaximum(std::max(maxMC,maxDATA) + 0.02);
 grDX_EEMinus_Ele->SetMinimum(std::min(minMC, minDATA) - 0.02);
 grDX_EEMinus_Ele->Draw("AP");
 grDX_EEMinus_After->Draw("P");

 cSM_DX_DY_DZ->cd(6);
 TGraphErrors* grDX_EEPlus_Ele = new TGraphErrors(2,iSM_SM_Ele,DX_SM_Mean,iSM_SM_Ele_RMS,DX_SM_RMS);
 grDX_EEPlus_Ele->SetTitle("EE+ #DeltaX");
 grDX_EEPlus_Ele->SetMarkerColor(kRed);
 grDX_EEPlus_Ele->SetLineColor(kRed);
 grDX_EEPlus_Ele->SetMarkerStyle(20);
 grDX_EEPlus_Ele->SetMarkerSize(1);
 grDX_EEPlus_Ele->SetLineWidth(1);
 grDX_EEPlus_Ele->GetXaxis()->SetTitle("iDee");
 grDX_EEPlus_Ele->GetYaxis()->SetTitle("#DeltaX (cm)");
 //grDX_EEPlus_Ele->Draw("AP");
 gPad->SetGrid();
  
 TGraphErrors* grDX_EEPlus_After = new TGraphErrors(2,iSM_SM_Ele,DX_SM_Mean_After,iSM_SM_Ele_RMS,DX_SM_RMS_After);
 grDX_EEPlus_After->SetMarkerColor(kBlue);
 grDX_EEPlus_After->SetLineColor(kBlue);
 grDX_EEPlus_After->SetMarkerStyle(21);
 grDX_EEPlus_After->SetMarkerSize(1);
 grDX_EEPlus_After->SetLineWidth(1);
 grDX_EEPlus_After->GetXaxis()->SetTitle("iDee");
 grDX_EEPlus_After->GetYaxis()->SetTitle("#DeltaX (cm)");
 //grDX_EEPlus_After->Draw("P");
 gPad->SetGrid();
  
 maxMC = TMath::MaxElement(grDX_EEPlus_Ele->GetN(),grDX_EEPlus_Ele->GetY());
 maxDATA = TMath::MaxElement(grDX_EEPlus_After->GetN(),grDX_EEPlus_After->GetY());
 minMC = TMath::MinElement(grDX_EEPlus_Ele->GetN(),grDX_EEPlus_Ele->GetY());
 minDATA = TMath::MinElement(grDX_EEPlus_After->GetN(),grDX_EEPlus_After->GetY());
 grDX_EEPlus_Ele->SetMaximum(std::max(maxMC,maxDATA) + 0.02);
 grDX_EEPlus_Ele->SetMinimum(std::min(minMC, minDATA) - 0.02);
 grDX_EEPlus_Ele->Draw("AP");
 grDX_EEPlus_After->Draw("P");
  
  
  
  ///===========================================================================
  ///===========================================================================
  ///===========================================================================


 TCanvas* cSM_DTHETAe_DPSIe_DPHIe = new TCanvas ("cSM_DTHETAe_DPSIe_DPHIe","cSM_DTHETAe_DPSIe_DPHIe",800,800);
 cSM_DTHETAe_DPSIe_DPHIe->Divide(2,3);
  
  
  ///===================================
 cSM_DTHETAe_DPSIe_DPHIe->cd(1);
 TGraphErrors* grDPHIe_EEMinus_Ele = new TGraphErrors(2,iSM_SM_Ele+2,DPHIe_SM_Mean+2,iSM_SM_Ele_RMS+2,DPHIe_SM_RMS+2);
 grDPHIe_EEMinus_Ele->SetTitle("EE- #Delta#phi Euler");
 grDPHIe_EEMinus_Ele->SetMarkerColor(kRed);
 grDPHIe_EEMinus_Ele->SetLineColor(kRed);
 grDPHIe_EEMinus_Ele->SetMarkerStyle(20);
 grDPHIe_EEMinus_Ele->SetMarkerSize(1);
 grDPHIe_EEMinus_Ele->SetLineWidth(1);
 grDPHIe_EEMinus_Ele->GetXaxis()->SetTitle("iDee");
 grDPHIe_EEMinus_Ele->GetYaxis()->SetTitle("#Delta#phi Euler ");
 //grDPHIe_EEMinus_Ele->Draw("AP");
 gPad->SetGrid();
  
 TGraphErrors* grDPHIe_EEMinus_After = new TGraphErrors(2,iSM_SM_Ele+2,DPHIe_SM_Mean_After+2,iSM_SM_Ele_RMS,DPHIe_SM_RMS_After+2);
 grDPHIe_EEMinus_After->SetMarkerColor(kBlue);
 grDPHIe_EEMinus_After->SetLineColor(kBlue);
 grDPHIe_EEMinus_After->SetMarkerStyle(21);
 grDPHIe_EEMinus_After->SetMarkerSize(1);
 grDPHIe_EEMinus_After->SetLineWidth(1);
 grDPHIe_EEMinus_After->GetXaxis()->SetTitle("iDee");
 grDPHIe_EEMinus_After->GetYaxis()->SetTitle("#Delta#phi Euler ");
 //grDPHIe_EEMinus_After->Draw("P");
 gPad->SetGrid();
  
 set_gr_range(grDPHIe_EEMinus_Ele, grDPHIe_EEMinus_After);
 grDPHIe_EEMinus_Ele->Draw("AP");
 grDPHIe_EEMinus_After->Draw("P");


 cSM_DTHETAe_DPSIe_DPHIe->cd(2);
 TGraphErrors* grDPHIe_EEPlus_Ele = new TGraphErrors(2,iSM_SM_Ele,DPHIe_SM_Mean,iSM_SM_Ele_RMS,DPHIe_SM_RMS);
 grDPHIe_EEPlus_Ele->SetTitle("EE+ #Delta#phi Euler");
 grDPHIe_EEPlus_Ele->SetMarkerColor(kRed);
 grDPHIe_EEPlus_Ele->SetLineColor(kRed);
 grDPHIe_EEPlus_Ele->SetMarkerStyle(20);
 grDPHIe_EEPlus_Ele->SetMarkerSize(1);
 grDPHIe_EEPlus_Ele->SetLineWidth(1);
 grDPHIe_EEPlus_Ele->GetXaxis()->SetTitle("iDee");
 grDPHIe_EEPlus_Ele->GetYaxis()->SetTitle("#Delta#phi Euler ");
 //grDPHIe_EEPlus_Ele->Draw("AP");
 gPad->SetGrid();
  
 TGraphErrors* grDPHIe_EEPlus_After = new TGraphErrors(2,iSM_SM_Ele,DPHIe_SM_Mean_After,iSM_SM_Ele_RMS,DPHIe_SM_RMS_After);
 grDPHIe_EEPlus_After->SetMarkerColor(kBlue);
 grDPHIe_EEPlus_After->SetLineColor(kBlue);
 grDPHIe_EEPlus_After->SetMarkerStyle(21);
 grDPHIe_EEPlus_After->SetMarkerSize(1);
 grDPHIe_EEPlus_After->SetLineWidth(1);
 grDPHIe_EEPlus_After->GetXaxis()->SetTitle("iDee");
 grDPHIe_EEPlus_After->GetYaxis()->SetTitle("#Delta#phi Euler ");
 //grDPHIe_EEPlus_After->Draw("P");
 gPad->SetGrid();
  
 set_gr_range(grDPHIe_EEPlus_Ele, grDPHIe_EEPlus_After);
 grDPHIe_EEPlus_Ele->Draw("AP");
 grDPHIe_EEPlus_After->Draw("P");

  ///===================================
 cSM_DTHETAe_DPSIe_DPHIe->cd(3);
 TGraphErrors* grDPSIe_EEMinus_Ele = new TGraphErrors(2,iSM_SM_Ele+2,DPSIe_SM_Mean+2,iSM_SM_Ele_RMS+2,DPSIe_SM_RMS+2);
 grDPSIe_EEMinus_Ele->SetTitle("EE- #Delta#psi Euler");
 grDPSIe_EEMinus_Ele->SetMarkerColor(kRed);
 grDPSIe_EEMinus_Ele->SetLineColor(kRed);
 grDPSIe_EEMinus_Ele->SetMarkerStyle(20);
 grDPSIe_EEMinus_Ele->SetMarkerSize(1);
 grDPSIe_EEMinus_Ele->SetLineWidth(1);
 grDPSIe_EEMinus_Ele->GetXaxis()->SetTitle("iDee");
 grDPSIe_EEMinus_Ele->GetYaxis()->SetTitle("#Delta#psi Euler ");
 //grDPSIe_EEMinus_Ele->Draw("AP");
 gPad->SetGrid();
  
 TGraphErrors* grDPSIe_EEMinus_After = new TGraphErrors(2,iSM_SM_Ele+2,DPSIe_SM_Mean_After+2,iSM_SM_Ele_RMS+2,DPSIe_SM_RMS_After+2);
 grDPSIe_EEMinus_After->SetMarkerColor(kBlue);
 grDPSIe_EEMinus_After->SetLineColor(kBlue);
 grDPSIe_EEMinus_After->SetMarkerStyle(21);
 grDPSIe_EEMinus_After->SetMarkerSize(1);
 grDPSIe_EEMinus_After->SetLineWidth(1);
 grDPSIe_EEMinus_After->GetXaxis()->SetTitle("iDee");
 grDPSIe_EEMinus_After->GetYaxis()->SetTitle("#Delta#psi Euler ");
 //grDPSIe_EEMinus_After->Draw("P");
 gPad->SetGrid();
  
 set_gr_range(grDPSIe_EEMinus_Ele, grDPSIe_EEMinus_After);
 grDPSIe_EEMinus_Ele->Draw("AP");
 grDPSIe_EEMinus_After->Draw("P"); 

 cSM_DTHETAe_DPSIe_DPHIe->cd(4);
 TGraphErrors* grDPSIe_EEPlus_Ele = new TGraphErrors(2,iSM_SM_Ele,DPSIe_SM_Mean,iSM_SM_Ele_RMS,DPSIe_SM_RMS);
 grDPSIe_EEPlus_Ele->SetTitle("EE+ #Delta#psi Euler");
 grDPSIe_EEPlus_Ele->SetMarkerColor(kRed);
 grDPSIe_EEPlus_Ele->SetLineColor(kRed);
 grDPSIe_EEPlus_Ele->SetMarkerStyle(20);
 grDPSIe_EEPlus_Ele->SetMarkerSize(1);
 grDPSIe_EEPlus_Ele->SetLineWidth(1);
 grDPSIe_EEPlus_Ele->GetXaxis()->SetTitle("iDee");
 grDPSIe_EEPlus_Ele->GetYaxis()->SetTitle("#Delta#psi Euler ");
 grDPSIe_EEPlus_Ele->Draw("AP");
 gPad->SetGrid();
  
 TGraphErrors* grDPSIe_EEPlus_After = new TGraphErrors(2,iSM_SM_Ele,DPSIe_SM_Mean_After,iSM_SM_Ele_RMS,DPSIe_SM_RMS_After);
 grDPSIe_EEPlus_After->SetMarkerColor(kBlue);
 grDPSIe_EEPlus_After->SetLineColor(kBlue);
 grDPSIe_EEPlus_After->SetMarkerStyle(21);
 grDPSIe_EEPlus_After->SetMarkerSize(1);
 grDPSIe_EEPlus_After->SetLineWidth(1);
 grDPSIe_EEPlus_After->GetXaxis()->SetTitle("iDee");
 grDPSIe_EEPlus_After->GetYaxis()->SetTitle("#Delta#psi Euler ");
 grDPSIe_EEPlus_After->Draw("P");
 gPad->SetGrid();

 set_gr_range(grDPSIe_EEPlus_Ele, grDPSIe_EEPlus_After);
 grDPSIe_EEPlus_Ele->Draw("AP");
 grDPSIe_EEPlus_After->Draw("P"); 
  
  ///===================================
 cSM_DTHETAe_DPSIe_DPHIe->cd(5);
 TGraphErrors* grDTHETAe_EEMinus_Ele = new TGraphErrors(2,iSM_SM_Ele+2,DTHETAe_SM_Mean+2,iSM_SM_Ele_RMS+2,DTHETAe_SM_RMS+2);
 grDTHETAe_EEMinus_Ele->SetTitle("EE- #Delta#theta Euler");
 grDTHETAe_EEMinus_Ele->SetMarkerColor(kRed);
 grDTHETAe_EEMinus_Ele->SetLineColor(kRed);
 grDTHETAe_EEMinus_Ele->SetMarkerStyle(20);
 grDTHETAe_EEMinus_Ele->SetMarkerSize(1);
 grDTHETAe_EEMinus_Ele->SetLineWidth(1);
 grDTHETAe_EEMinus_Ele->GetXaxis()->SetTitle("iDee");
 grDTHETAe_EEMinus_Ele->GetYaxis()->SetTitle("#Delta#theta Euler ");
 grDTHETAe_EEMinus_Ele->Draw("AP");
 gPad->SetGrid();
  
 TGraphErrors* grDTHETAe_EEMinus_After = new TGraphErrors(2,iSM_SM_Ele+2,DTHETAe_SM_Mean_After+2,iSM_SM_Ele_RMS+2,DTHETAe_SM_RMS_After+2);
 grDTHETAe_EEMinus_After->SetMarkerColor(kBlue);
 grDTHETAe_EEMinus_After->SetLineColor(kBlue);
 grDTHETAe_EEMinus_After->SetMarkerStyle(21);
 grDTHETAe_EEMinus_After->SetMarkerSize(1);
 grDTHETAe_EEMinus_After->SetLineWidth(1);
 grDTHETAe_EEMinus_After->GetXaxis()->SetTitle("iDee");
 grDTHETAe_EEMinus_After->GetYaxis()->SetTitle("#Delta#theta Euler ");
 grDTHETAe_EEMinus_After->Draw("P");
 gPad->SetGrid();
  
  
 cSM_DTHETAe_DPSIe_DPHIe->cd(6);
 TGraphErrors* grDTHETAe_EEPlus_Ele = new TGraphErrors(2,iSM_SM_Ele,DTHETAe_SM_Mean,iSM_SM_Ele_RMS,DTHETAe_SM_RMS);
 grDTHETAe_EEPlus_Ele->SetTitle("EE+ #Delta#theta Euler");
 grDTHETAe_EEPlus_Ele->SetMarkerColor(kRed);
 grDTHETAe_EEPlus_Ele->SetLineColor(kRed);
 grDTHETAe_EEPlus_Ele->SetMarkerStyle(20);
 grDTHETAe_EEPlus_Ele->SetMarkerSize(1);
 grDTHETAe_EEPlus_Ele->SetLineWidth(1);
 grDTHETAe_EEPlus_Ele->GetXaxis()->SetTitle("iDee");
 grDTHETAe_EEPlus_Ele->GetYaxis()->SetTitle("#Delta#theta Euler ");
 grDTHETAe_EEPlus_Ele->Draw("AP");
 gPad->SetGrid();
  
 TGraphErrors* grDTHETAe_EEPlus_After = new TGraphErrors(2,iSM_SM_Ele,DTHETAe_SM_Mean_After,iSM_SM_Ele_RMS,DTHETAe_SM_RMS_After);
 grDTHETAe_EEPlus_After->SetMarkerColor(kBlue);
 grDTHETAe_EEPlus_After->SetLineColor(kBlue);
 grDTHETAe_EEPlus_After->SetMarkerStyle(21);
 grDTHETAe_EEPlus_After->SetMarkerSize(1);
 grDTHETAe_EEPlus_After->SetLineWidth(1);
 grDTHETAe_EEPlus_After->GetXaxis()->SetTitle("iDee");
 grDTHETAe_EEPlus_After->GetYaxis()->SetTitle("#Delta#theta Euler ");
 grDTHETAe_EEPlus_After->Draw("P");
 gPad->SetGrid();
  
  
 ///===========================================================================
 ///===========================================================================
 ///===========================================================================
 /*
 TCanvas* cDifference = new TCanvas ("cDifference","cDifference",900,700);
 cDifference->Divide(3,2);
  
 TH1F *hDX = new TH1F("hDX","#DeltaX",100,-1,1);
 for (int i = 0; i<4; i++) hDX->Fill(DX_SM_Mean_After[i] - DX_SM_Mean[i]);

 TH1F *hDY = new TH1F("hDY","#DeltaY",100,-1,1);
 for (int i = 0; i<4; i++) hDY->Fill(DY_SM_Mean_After[i] - DY_SM_Mean[i]);

 TH1F *hDZ = new TH1F("hDZ","#DeltaZ",100,-1,1);
 for (int i = 0; i<4; i++) hDZ->Fill(DZ_SM_Mean_After[i] - DZ_SM_Mean[i]);
 
 cDifference->cd(1);
 hDX->SetLineColor(kRed);
 hDX->SetFillColor(kRed);
 hDX->SetFillStyle(3002);
 hDX->GetXaxis()->SetTitle("cm");
 hDX->Draw();
 gPad->SetGrid();
 
 cDifference->cd(2);
 hDY->SetLineColor(kRed);
 hDY->SetFillColor(kRed);
 hDY->SetFillStyle(3002);
 hDY->GetXaxis()->SetTitle("cm");
 hDY->Draw();
 gPad->SetGrid();
 
 cDifference->cd(3);
 hDZ->SetLineColor(kRed);
 hDZ->SetFillColor(kRed);
 hDZ->SetFillStyle(3002);
 hDZ->GetXaxis()->SetTitle("cm");
 hDZ->Draw();
 gPad->SetGrid();  
 
 
 
 
 
 TH1F *hDTHETAe = new TH1F("hDTHETAe","#Delta#Theta",100,-0.01,0.01);
 for (int i = 0; i<4; i++) hDTHETAe->Fill(DTHETAe_SM_Mean_After[i] - DTHETAe_SM_Mean[i]);
 
 TH1F *hDPSIe = new TH1F("hDPSIe","#Delta#Psi",100,-0.01,0.01);
 for (int i = 0; i<4; i++) hDPSIe->Fill(DPSIe_SM_Mean_After[i] - DPSIe_SM_Mean[i]);
 
 TH1F *hDPHIe = new TH1F("hDPHIe","#Delta#Phi",100,-0.01,0.01);
 for (int i = 0; i<4; i++) hDPHIe->Fill(DPHIe_SM_Mean_After[i] - DPHIe_SM_Mean[i]);
 
 cDifference->cd(4);
 hDTHETAe->SetLineColor(kRed);
 hDTHETAe->SetFillColor(kRed);
 hDTHETAe->SetFillStyle(3002);
 hDTHETAe->GetXaxis()->SetTitle("");
 hDTHETAe->Draw();
 gPad->SetGrid();
 
 cDifference->cd(5);
 hDPSIe->SetLineColor(kRed);
 hDPSIe->SetFillColor(kRed);
 hDPSIe->SetFillStyle(3002);
 hDPSIe->GetXaxis()->SetTitle("");
 hDPSIe->Draw();
 gPad->SetGrid();
 
 cDifference->cd(6);
 hDPHIe->SetLineColor(kRed);
 hDPHIe->SetFillColor(kRed);
 hDPHIe->SetFillStyle(3002);
 hDPHIe->GetXaxis()->SetTitle("");
 hDPHIe->Draw();
 gPad->SetGrid();  
  
 
 TFile* fileOutput = new TFile ("testEE.root","UPDATE");
 if (fileOutput->Get("hDX")) {
  std::cout << " add new distribution ..." << std::endl;
  TH1F *hDXtemp = (TH1F*) fileOutput->Get("hDX");
  hDXtemp->Add(hDX);
  TH1F *hDYtemp = (TH1F*) fileOutput->Get("hDY");
  hDYtemp->Add(hDY);
  TH1F *hDZtemp = (TH1F*) fileOutput->Get("hDZ");
  hDZtemp->Add(hDZ);
  
  hDXtemp->Write();
  hDYtemp->Write();
  hDZtemp->Write();
 } 
 else {
  hDX->Write();
  hDY->Write();
  hDZ->Write();
 }
 */
}


