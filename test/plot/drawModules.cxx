void drawModules(TString nameInFileRoot, TString nameOutputDir, TString nameDATA){
 
 //  int Mean = 0;
 int Mean = 1;
 
 TFile* fileIn = new TFile(nameInFileRoot);
 
 TLine lineVert (35.5,-1,35.5,1);
 lineVert.SetLineColor(kGreen);
 lineVert.SetLineWidth(4);
 lineVert.SetLineStyle(3);
 
 gStyle->SetTitleX(0.2f);
 gStyle->SetTitleW(0.5f);
 
 TString nameHisto;
 TH1F* h;
 TH1F* hMC;
 THStack* hs;
 TCanvas* cJoint = new TCanvas("cJoint","cJoint",1000,1000);
 cJoint->SetLeftMargin(0.10);
 cJoint->SetRightMargin(0.25);
 cJoint->SetTopMargin(0.05);
 cJoint->SetBottomMargin(0.20);
 
 
 
 TString toDoShell;
 toDoShell = Form("rm -r %s ;",nameOutputDir.Data());
 system(toDoShell.Data());
 toDoShell = Form("mkdir %s ;",nameOutputDir.Data());
 system(toDoShell.Data());
 toDoShell = Form("mkdir %s/plot ;",nameOutputDir.Data());
 system(toDoShell.Data());
 
 TString toDoROOT;
 
 double norm;
 
 
 double MC_Dphi_Eplus_EBplus;
 double errMC_Dphi_Eplus_EBplus;
 double MC_Dphi_Eminus_EBplus;
 double errMC_Dphi_Eminus_EBplus;
 double MC_Dphi_EBplus;
 double errMC_Dphi_EBplus; 
 double MC_Deta_EBplus;
 double errMC_Deta_EBplus;
 
 double MC_Dphi_Eplus_EBminus;
 double errMC_Dphi_Eplus_EBminus;
 double MC_Dphi_Eminus_EBminus;
 double errMC_Dphi_Eminus_EBminus;
 double MC_Dphi_EBminus;
 double errMC_Dphi_EBminus; 
 double MC_Deta_EBminus;
 double errMC_Deta_EBminus;
 
 double MC_Dphi_Eplus_EEplus;
 double errMC_Dphi_Eplus_EEplus;
 double MC_Dphi_Eminus_EEplus;
 double errMC_Dphi_Eminus_EEplus;
 double MC_Dphi_EEplus;
 double errMC_Dphi_EEplus; 
 double MC_Deta_EEplus;
 double errMC_Deta_EEplus;
 
 double MC_Dphi_Eplus_EEminus;
 double errMC_Dphi_Eplus_EEminus;
 double MC_Dphi_Eminus_EEminus;
 double errMC_Dphi_Eminus_EEminus;
 double MC_Dphi_EEminus;
 double errMC_Dphi_EEminus; 
 double MC_Deta_EEminus;
 double errMC_Deta_EEminus;
 
 
 
 double DATA_Dphi_Eplus_EBplus;
 double errDATA_Dphi_Eplus_EBplus;
 double DATA_Dphi_Eminus_EBplus;
 double errDATA_Dphi_Eminus_EBplus;
 double DATA_Dphi_EBplus;
 double errDATA_Dphi_EBplus; 
 double DATA_Deta_EBplus;
 double errDATA_Deta_EBplus;
 
 double DATA_Dphi_Eplus_EBminus;
 double errDATA_Dphi_Eplus_EBminus;
 double DATA_Dphi_Eminus_EBminus;
 double errDATA_Dphi_Eminus_EBminus;
 double DATA_Dphi_EBminus;
 double errDATA_Dphi_EBminus; 
 double DATA_Deta_EBminus;
 double errDATA_Deta_EBminus;
 
 double DATA_Dphi_Eplus_EEplus;
 double errDATA_Dphi_Eplus_EEplus;
 double DATA_Dphi_Eminus_EEplus;
 double errDATA_Dphi_Eminus_EEplus;
 double DATA_Dphi_EEplus;
 double errDATA_Dphi_EEplus; 
 double DATA_Deta_EEplus;
 double errDATA_Deta_EEplus;
 
 double DATA_Dphi_Eplus_EEminus;
 double errDATA_Dphi_Eplus_EEminus;
 double DATA_Dphi_Eminus_EEminus;
 double errDATA_Dphi_Eminus_EEminus;
 double DATA_Dphi_EEminus;
 double errDATA_Dphi_EEminus; 
 double DATA_Deta_EEminus;
 double errDATA_Deta_EEminus;
 
 
 std::vector<double> DATA_Dphi;
 std::vector<double> DATA_Dphi_ePlus;
 std::vector<double> DATA_Dphi_eMinus;
 std::vector<double> DATA_Deta;
 std::vector<double> DATA_err_Dphi;
 std::vector<double> DATA_err_Dphi_ePlus;
 std::vector<double> DATA_err_Dphi_eMinus;
 std::vector<double> DATA_err_Deta;
 
 std::vector<double> MC_Dphi;
 std::vector<double> MC_Dphi_ePlus;
 std::vector<double> MC_Dphi_eMinus;
 std::vector<double> MC_Deta;
 std::vector<double> MC_err_Dphi;
 std::vector<double> MC_err_Dphi_ePlus;
 std::vector<double> MC_err_Dphi_eMinus;
 std::vector<double> MC_err_Deta;
 
 TString nameHistoInRootFile;
 ///==== EB ====
 for (int iSM = 0; iSM <36; iSM++) {
  ///~~~~ Dphi ~~~~
  nameHistoInRootFile = Form("Data/%s_%d_1_Tot_temp",nameDATA.Data(),iSM);
  std::cout << " Dphi  nameHistoInRootFile = " << nameHistoInRootFile.Data() << std::endl;
  h = (TH1F*) fileIn->Get(nameHistoInRootFile);
  if (Mean == 1){
   if (iSM<18) {
    nameHistoInRootFile = Form ("Data/W_121_1_Tot_temp");  
   }
   else {
    nameHistoInRootFile = Form ("Data/W_122_1_Tot_temp");  
   }
  } 
  else {
   nameHistoInRootFile = Form("Data/W_%d_1_Tot_temp",iSM);
  }
  std::cout << " Dphi nameHistoInRootFile = " << nameHistoInRootFile.Data() << std::endl;
  hMC = (TH1F*) fileIn->Get(nameHistoInRootFile);
  cJoint->cd();
  h->Draw();
  norm = h->Integral(); hMC->DrawNormalized("HISTsame",norm);
  cJoint->SetGrid();
  TLegend* leg0 = cJoint->BuildLegend(0.8,0.55,0.98,0.75);
  leg0->SetFillColor(kWhite);
  cJoint->SetGrid();   
  toDoROOT = Form("%s/plot/Dphi_EB_%d.png",nameOutputDir.Data(),iSM);
  cJoint->SaveAs(toDoROOT);
  cJoint->SaveAs(toDoROOT);
  DATA_Dphi.push_back(h->GetMean());
  DATA_err_Dphi.push_back(h->GetRMS() /sqrt( h->GetEntries() ));
  MC_Dphi.push_back(hMC->GetMean());
  MC_err_Dphi.push_back(hMC->GetRMS() /sqrt( hMC->GetEntries() ));
  
  ///~~~~ Dphi e+ ~~~~
  nameHistoInRootFile = Form("Data/%s_%d_1_Tot_temp",nameDATA.Data(),iSM+40);
  std::cout << " Dphi e+ nameHistoInRootFile = " << nameHistoInRootFile.Data() << std::endl;
  h = (TH1F*) fileIn->Get(nameHistoInRootFile);
  if (Mean == 1){
   if (iSM<18) {
    nameHistoInRootFile = Form ("Data/W_125_1_Tot_temp");  
   }
   else {
    nameHistoInRootFile = Form ("Data/W_126_1_Tot_temp");  
   }
  } 
  else {
   nameHistoInRootFile = Form("Data/W_%d_1_Tot_temp",iSM+40);
  }
  std::cout << " Dphi e+ nameHistoInRootFile = " << nameHistoInRootFile.Data() << std::endl;
  hMC = (TH1F*) fileIn->Get(nameHistoInRootFile);
  cJoint->cd();
  h->Draw();
  norm = h->Integral(); hMC->DrawNormalized("HISTsame",norm);
  cJoint->SetGrid();
  TLegend* leg = cJoint->BuildLegend(0.8,0.55,0.98,0.75);
  leg->SetFillColor(kWhite);
  cJoint->SetGrid();   
  toDoROOT = Form("%s/plot/Dphi_EB_%d_ePlus.png",nameOutputDir.Data(),iSM);
  cJoint->SaveAs(toDoROOT);
  cJoint->SaveAs(toDoROOT);
  DATA_Dphi_ePlus.push_back(h->GetMean());
  DATA_err_Dphi_ePlus.push_back(h->GetRMS() /sqrt( h->GetEntries() ));
  MC_Dphi_ePlus.push_back(hMC->GetMean());
  MC_err_Dphi_ePlus.push_back(hMC->GetRMS() /sqrt( hMC->GetEntries() ));
  
  ///~~~~ Dphi e- ~~~~
  nameHistoInRootFile = Form("Data/%s_%d_1_Tot_temp",nameDATA.Data(),iSM+80);
  std::cout << " Dphi e+ nameHistoInRootFile = " << nameHistoInRootFile.Data() << std::endl;
  h = (TH1F*) fileIn->Get(nameHistoInRootFile);
  if (Mean == 1){
   if (iSM<18) {
    nameHistoInRootFile = Form ("Data/W_129_1_Tot_temp");  
   }
   else {
    nameHistoInRootFile = Form ("Data/W_130_1_Tot_temp");  
   }
  }
  else {
   nameHistoInRootFile = Form("Data/W_%d_1_Tot_temp",iSM+80);
  }
  hMC = (TH1F*) fileIn->Get(nameHistoInRootFile);
  cJoint->cd();
  h->Draw();
  norm = h->Integral(); hMC->DrawNormalized("HISTsame",norm);
  cJoint->SetGrid();
  TLegend* leg2 = cJoint->BuildLegend(0.8,0.55,0.98,0.75);
  leg2->SetFillColor(kWhite);
  cJoint->SetGrid();   
  toDoROOT = Form("%s/plot/Dphi_EB_%d_eMinus.png",nameOutputDir.Data(),iSM);
  std::cout << " Dphi e- toDoROOT = " << toDoROOT.Data() << std::endl;
  cJoint->SaveAs(toDoROOT);
  DATA_Dphi_eMinus.push_back(h->GetMean());
  DATA_err_Dphi_eMinus.push_back(h->GetRMS() /sqrt( h->GetEntries() ));
  MC_Dphi_eMinus.push_back(hMC->GetMean());
  MC_err_Dphi_eMinus.push_back(hMC->GetRMS() /sqrt( hMC->GetEntries() ));
  
  ///~~~~ Deta ~~~~
  nameHistoInRootFile = Form("Data/%s_%d_0_Tot_temp",nameDATA.Data(),iSM);
  std::cout << " Dphi e+ nameHistoInRootFile = " << nameHistoInRootFile.Data() << std::endl;
  h = (TH1F*) fileIn->Get(nameHistoInRootFile);
  if (Mean == 1){
   if (iSM<18) {
    nameHistoInRootFile = Form ("Data/W_121_0_Tot_temp");  
   }
   else {
    nameHistoInRootFile = Form ("Data/W_122_0_Tot_temp");  
   }
  }
  else {
   nameHistoInRootFile = Form("Data/W_%d_0_Tot_temp",iSM);
  }
  hMC = (TH1F*) fileIn->Get(nameHistoInRootFile);
  cJoint->cd();
  h->Draw();
  norm = h->Integral(); hMC->DrawNormalized("HISTsame",norm);
  cJoint->SetGrid();
  TLegend* leg3 = cJoint->BuildLegend(0.8,0.55,0.98,0.75);
  leg3->SetFillColor(kWhite);
  cJoint->SetGrid();   
  toDoROOT = Form("%s/plot/Deta_EB_%d.png",nameOutputDir.Data(),iSM);
  cJoint->SaveAs(toDoROOT);
  DATA_Deta.push_back(h->GetMean());
  DATA_err_Deta.push_back(h->GetRMS() /sqrt( h->GetEntries() ));
  MC_Deta.push_back(hMC->GetMean());
  MC_err_Deta.push_back(hMC->GetRMS() /sqrt( hMC->GetEntries() ));
  
 }
 
 
 
 
 
 ///==== EE ====
 for (int iSM = 0; iSM <4; iSM++) {
  ///~~~~ Dphi ~~~~
  nameHistoInRootFile = Form("Data/%s_%d_1_Tot_temp",nameDATA.Data(),iSM+36);
  std::cout << " Dphi nameHistoInRootFile = " << nameHistoInRootFile.Data() << std::endl;
  h = (TH1F*) fileIn->Get(nameHistoInRootFile);
  if (Mean == 1){
   if (iSM<2) {
    nameHistoInRootFile = Form ("Data/W_123_1_Tot_temp");  
   }
   else {
    nameHistoInRootFile = Form ("Data/W_120_1_Tot_temp");  
   }
  }
  else {
   nameHistoInRootFile = Form("Data/W_%d_1_Tot_temp",iSM+36);
  }
  hMC = (TH1F*) fileIn->Get(nameHistoInRootFile);
  cJoint->cd();
  h->Draw();
  norm = h->Integral(); hMC->DrawNormalized("HISTsame",norm);
  cJoint->SetGrid();
  TLegend* leg0 = cJoint->BuildLegend(0.8,0.55,0.98,0.75);
  leg0->SetFillColor(kWhite);
  cJoint->SetGrid();   
  toDoROOT = Form("%s/plot/Dphi_EE_%d.png",nameOutputDir.Data(),iSM);
  cJoint->SaveAs(toDoROOT);
  cJoint->SaveAs(toDoROOT);
  DATA_Dphi.push_back(h->GetMean());
  DATA_err_Dphi.push_back(h->GetRMS() /sqrt( h->GetEntries() ));
  MC_Dphi.push_back(hMC->GetMean());
  MC_err_Dphi.push_back(hMC->GetRMS() /sqrt( hMC->GetEntries() ));
  
  
  ///~~~~ Dphi e+ ~~~~
  nameHistoInRootFile = Form("Data/%s_%d_1_Tot_temp",nameDATA.Data(),iSM+40+36);
  std::cout << " Dphi e+ nameHistoInRootFile = " << nameHistoInRootFile.Data() << std::endl;
  h = (TH1F*) fileIn->Get(nameHistoInRootFile);
  if (Mean == 1){
   if (iSM<2) {
    nameHistoInRootFile = Form ("Data/W_127_1_Tot_temp");  
   }
   else {
    nameHistoInRootFile = Form ("Data/W_124_1_Tot_temp");  
   }
  }
  else {
   nameHistoInRootFile = Form("Data/W_%d_1_Tot_temp",iSM+40+36);
  }
  hMC = (TH1F*) fileIn->Get(nameHistoInRootFile);
  cJoint->cd();
  h->Draw();
  norm = h->Integral(); hMC->DrawNormalized("HISTsame",norm);
  cJoint->SetGrid();
  TLegend* leg = cJoint->BuildLegend(0.8,0.55,0.98,0.75);
  leg->SetFillColor(kWhite);
  cJoint->SetGrid();   
  toDoROOT = Form("%s/plot/Dphi_EE_%d_ePlus.png",nameOutputDir.Data(),iSM);
  cJoint->SaveAs(toDoROOT);
  cJoint->SaveAs(toDoROOT);
  DATA_Dphi_ePlus.push_back(h->GetMean());
  DATA_err_Dphi_ePlus.push_back(h->GetRMS() /sqrt( h->GetEntries() ));
  MC_Dphi_ePlus.push_back(hMC->GetMean());
  MC_err_Dphi_ePlus.push_back(hMC->GetRMS() /sqrt( hMC->GetEntries() ));
  
  ///~~~~ Dphi e- ~~~~
  nameHistoInRootFile = Form("Data/%s_%d_1_Tot_temp",nameDATA.Data(),iSM+80+36);
  std::cout << " Dphi e+ nameHistoInRootFile = " << nameHistoInRootFile.Data() << std::endl;
  h = (TH1F*) fileIn->Get(nameHistoInRootFile);
  if (Mean == 1){
   if (iSM<2) {
    nameHistoInRootFile = Form ("Data/W_131_1_Tot_temp");  
   }
   else {
    nameHistoInRootFile = Form ("Data/W_128_1_Tot_temp");  
   }
  }
  else {
   nameHistoInRootFile = Form("Data/W_%d_1_Tot_temp",iSM+80+36);
  }
  hMC = (TH1F*) fileIn->Get(nameHistoInRootFile);
  cJoint->cd();
  h->Draw();
  norm = h->Integral(); hMC->DrawNormalized("HISTsame",norm);
  cJoint->SetGrid();
  TLegend* leg2 = cJoint->BuildLegend(0.8,0.55,0.98,0.75);
  leg2->SetFillColor(kWhite);
  cJoint->SetGrid();   
  toDoROOT = Form("%s/plot/Dphi_EE_%d_eMinus.png",nameOutputDir.Data(),iSM);
  cJoint->SaveAs(toDoROOT);
  DATA_Dphi_eMinus.push_back(h->GetMean());
  DATA_err_Dphi_eMinus.push_back(h->GetRMS() /sqrt( h->GetEntries() ));
  MC_Dphi_eMinus.push_back(hMC->GetMean());
  MC_err_Dphi_eMinus.push_back(hMC->GetRMS() /sqrt( hMC->GetEntries() ));
  
  ///~~~~ Deta ~~~~
  nameHistoInRootFile = Form("Data/%s_%d_0_Tot_temp",nameDATA.Data(),iSM+36);
  std::cout << " Dphi e+ nameHistoInRootFile = " << nameHistoInRootFile.Data() << std::endl;
  h = (TH1F*) fileIn->Get(nameHistoInRootFile);
  if (Mean == 1){
   if (iSM<2) {
    nameHistoInRootFile = Form ("Data/W_123_0_Tot_temp");  
   }
   else {
    nameHistoInRootFile = Form ("Data/W_120_0_Tot_temp");  
   }
  }
  else {
   nameHistoInRootFile = Form("Data/W_%d_0_Tot_temp",iSM+36);
  }
  hMC = (TH1F*) fileIn->Get(nameHistoInRootFile);
  cJoint->cd();
  h->Draw();
  norm = h->Integral(); hMC->DrawNormalized("HISTsame",norm);
  cJoint->SetGrid();
  TLegend* leg3 = cJoint->BuildLegend(0.8,0.55,0.98,0.75);
  leg3->SetFillColor(kWhite);
  cJoint->SetGrid();   
  toDoROOT = Form("%s/plot/Deta_EE_%d.png",nameOutputDir.Data(),iSM);
  cJoint->SaveAs(toDoROOT);
  DATA_Deta.push_back(h->GetMean());
  DATA_err_Deta.push_back(h->GetRMS() /sqrt( h->GetEntries() ));
  MC_Deta.push_back(hMC->GetMean());
  MC_err_Deta.push_back(hMC->GetRMS() /sqrt( hMC->GetEntries() ));
  
 }
 
 
 
 
 
 
 ///===============================
 ///==== Summary plots: EE, EB ====
 
 ///==== EB+ ====
 ///==== e+ ====
 nameHistoInRootFile = Form("Data/%s_125_1_Tot_temp",nameDATA.Data());
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 nameHistoInRootFile = Form ("Data/W_125_1_Tot_temp");  
 hMC = (TH1F*) fileIn->Get(nameHistoInRootFile);
 cJoint->cd();
 h->Draw();
 norm = h->Integral(); hMC->DrawNormalized("HISTsame",norm);
 cJoint->SetGrid();
 TLegend* legEPlusEBplus = cJoint->BuildLegend(0.8,0.55,0.98,0.75);
 legEPlusEBplus->SetFillColor(kWhite);
 cJoint->SetGrid();   
 toDoROOT = Form("%s/plot/DphiEPlusEBplus.png",nameOutputDir.Data());
 cJoint->SaveAs(toDoROOT); 
 DATA_Dphi_Eplus_EBplus    = h->GetMean();
 errDATA_Dphi_Eplus_EBplus = h->GetRMS() /sqrt( h->GetEntries() );
 MC_Dphi_Eplus_EBplus      = hMC->GetMean();
 errMC_Dphi_Eplus_EBplus   = hMC->GetRMS() /sqrt( hMC->GetEntries() );
 
 ///==== e- ====
 nameHistoInRootFile = Form("Data/%s_129_1_Tot_temp",nameDATA.Data());
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 nameHistoInRootFile = Form ("Data/W_129_1_Tot_temp");  
 hMC = (TH1F*) fileIn->Get(nameHistoInRootFile);
 cJoint->cd();
 h->Draw();
 norm = h->Integral(); hMC->DrawNormalized("HISTsame",norm);
 cJoint->SetGrid();
 TLegend* legEMinusEBplus = cJoint->BuildLegend(0.8,0.55,0.98,0.75);
 legEMinusEBplus->SetFillColor(kWhite);
 cJoint->SetGrid();   
 toDoROOT = Form("%s/plot/DphiEMinusEBplus.png",nameOutputDir.Data());
 cJoint->SaveAs(toDoROOT);
 DATA_Dphi_Eminus_EBplus    = h->GetMean();
 errDATA_Dphi_Eminus_EBplus = h->GetRMS() /sqrt( h->GetEntries() );
 MC_Dphi_Eminus_EBplus      = hMC->GetMean();
 errMC_Dphi_Eminus_EBplus   = hMC->GetRMS() /sqrt( hMC->GetEntries() );
 
 ///==== e^{-} + e^{+} ====
 nameHistoInRootFile = Form("Data/%s_121_1_Tot_temp",nameDATA.Data());
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 nameHistoInRootFile = Form ("Data/W_121_1_Tot_temp");  
 hMC = (TH1F*) fileIn->Get(nameHistoInRootFile);
 cJoint->cd();
 h->Draw();
 norm = h->Integral(); hMC->DrawNormalized("HISTsame",norm);
 cJoint->SetGrid();
 TLegend* legEBplus = cJoint->BuildLegend(0.8,0.55,0.98,0.75);
 legEBplus->SetFillColor(kWhite);
 cJoint->SetGrid();   
 toDoROOT = Form("%s/plot/DphiEBplus.png",nameOutputDir.Data());
 cJoint->SaveAs(toDoROOT);
 DATA_Dphi_EBplus    = h->GetMean();
 errDATA_Dphi_EBplus = h->GetRMS() /sqrt( h->GetEntries() );
 MC_Dphi_EBplus      = hMC->GetMean();
 errMC_Dphi_EBplus   = hMC->GetRMS() /sqrt( hMC->GetEntries() );
 
 
 nameHistoInRootFile = Form("Data/%s_121_0_Tot_temp",nameDATA.Data());
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 nameHistoInRootFile = Form ("Data/W_121_0_Tot_temp");  
 hMC = (TH1F*) fileIn->Get(nameHistoInRootFile);
 cJoint->cd();
 h->Draw();
 norm = h->Integral(); hMC->DrawNormalized("HISTsame",norm);
 cJoint->SetGrid();
 TLegend* legEBplus = cJoint->BuildLegend(0.8,0.55,0.98,0.75);
 legEBplus->SetFillColor(kWhite);
 cJoint->SetGrid();   
 toDoROOT = Form("%s/plot/DetaEBplus.png",nameOutputDir.Data());
 cJoint->SaveAs(toDoROOT);
 DATA_Deta_EBplus    = h->GetMean();
 errDATA_Deta_EBplus = h->GetRMS() /sqrt( h->GetEntries() );
 MC_Deta_EBplus      = hMC->GetMean();
 errMC_Deta_EBplus   = hMC->GetRMS() /sqrt( hMC->GetEntries() );
 
 
 
 
 
 ///==== EB- ====
 ///==== e+ ====
 nameHistoInRootFile = Form("Data/%s_126_1_Tot_temp",nameDATA.Data());
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 nameHistoInRootFile = Form ("Data/W_126_1_Tot_temp");  
 hMC = (TH1F*) fileIn->Get(nameHistoInRootFile);
 cJoint->cd();
 h->Draw();
 norm = h->Integral(); hMC->DrawNormalized("HISTsame",norm);
 cJoint->SetGrid();
 TLegend* legEPlusEBminus = cJoint->BuildLegend(0.8,0.55,0.98,0.75);
 legEPlusEBminus->SetFillColor(kWhite);
 cJoint->SetGrid();   
 toDoROOT = Form("%s/plot/DphiEPlusEBminus.png",nameOutputDir.Data());
 cJoint->SaveAs(toDoROOT);
 DATA_Dphi_Eplus_EBminus    = h->GetMean();
 errDATA_Dphi_Eplus_EBminus = h->GetRMS() /sqrt( h->GetEntries() );
 MC_Dphi_Eplus_EBminus      = hMC->GetMean();
 errMC_Dphi_Eplus_EBminus   = hMC->GetRMS() /sqrt( hMC->GetEntries() );
 
 ///==== e- ====
 nameHistoInRootFile = Form("Data/%s_130_1_Tot_temp",nameDATA.Data());
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 nameHistoInRootFile = Form ("Data/W_130_1_Tot_temp");  
 hMC = (TH1F*) fileIn->Get(nameHistoInRootFile);
 cJoint->cd();
 h->Draw();
 norm = h->Integral(); hMC->DrawNormalized("HISTsame",norm);
 cJoint->SetGrid();
 TLegend* legEMinusEBminus = cJoint->BuildLegend(0.8,0.55,0.98,0.75);
 legEMinusEBminus->SetFillColor(kWhite);
 cJoint->SetGrid();   
 toDoROOT = Form("%s/plot/DphiEMinusEBminus.png",nameOutputDir.Data());
 cJoint->SaveAs(toDoROOT);
 DATA_Dphi_Eminus_EBminus    = h->GetMean();
 errDATA_Dphi_Eminus_EBminus = h->GetRMS() /sqrt( h->GetEntries() );
 MC_Dphi_Eminus_EBminus      = hMC->GetMean();
 errMC_Dphi_Eminus_EBminus   = hMC->GetRMS() /sqrt( hMC->GetEntries() );
 
 ///==== e^{-} + e^{+} ====
 nameHistoInRootFile = Form("Data/%s_122_1_Tot_temp",nameDATA.Data());
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 nameHistoInRootFile = Form ("Data/W_122_1_Tot_temp");  
 hMC = (TH1F*) fileIn->Get(nameHistoInRootFile);
 cJoint->cd();
 h->Draw();
 norm = h->Integral(); hMC->DrawNormalized("HISTsame",norm);
 cJoint->SetGrid();
 TLegend* legEBminus = cJoint->BuildLegend(0.8,0.55,0.98,0.75);
 legEBminus->SetFillColor(kWhite);
 cJoint->SetGrid();   
 toDoROOT = Form("%s/plot/DphiEBminus.png",nameOutputDir.Data());
 cJoint->SaveAs(toDoROOT);
 DATA_Dphi_EBminus    = h->GetMean();
 errDATA_Dphi_EBminus = h->GetRMS() /sqrt( h->GetEntries() );
 MC_Dphi_EBminus      = hMC->GetMean();
 errMC_Dphi_EBminus   = hMC->GetRMS() /sqrt( hMC->GetEntries() );
 
 
 nameHistoInRootFile = Form("Data/%s_122_0_Tot_temp",nameDATA.Data());
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 nameHistoInRootFile = Form ("Data/W_122_0_Tot_temp");  
 hMC = (TH1F*) fileIn->Get(nameHistoInRootFile);
 cJoint->cd();
 h->Draw();
 norm = h->Integral(); hMC->DrawNormalized("HISTsame",norm);
 cJoint->SetGrid();
 TLegend* legEBminus = cJoint->BuildLegend(0.8,0.55,0.98,0.75);
 legEBminus->SetFillColor(kWhite);
 cJoint->SetGrid();   
 toDoROOT = Form("%s/plot/DetaEBminus.png",nameOutputDir.Data());
 cJoint->SaveAs(toDoROOT);
 DATA_Deta_EBminus    = h->GetMean();
 errDATA_Deta_EBminus = h->GetRMS() /sqrt( h->GetEntries() );
 MC_Deta_EBminus      = hMC->GetMean();
 errMC_Deta_EBminus   = hMC->GetRMS() /sqrt( hMC->GetEntries() );
 
 
 
 
 
 
 
 ///==== EE+ ====
 ///==== e+ ====
 nameHistoInRootFile = Form("Data/%s_124_1_Tot_temp",nameDATA.Data());
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 nameHistoInRootFile = Form ("Data/W_124_1_Tot_temp");  
 hMC = (TH1F*) fileIn->Get(nameHistoInRootFile);
 cJoint->cd();
 h->Draw();
 norm = h->Integral(); hMC->DrawNormalized("HISTsame",norm);
 cJoint->SetGrid();
 TLegend* legEPlusEEplus = cJoint->BuildLegend(0.8,0.55,0.98,0.75);
 legEPlusEEplus->SetFillColor(kWhite);
 cJoint->SetGrid();   
 toDoROOT = Form("%s/plot/DphiEPlusEEplus.png",nameOutputDir.Data());
 cJoint->SaveAs(toDoROOT);
 DATA_Dphi_Eplus_EEplus    = h->GetMean();
 errDATA_Dphi_Eplus_EEplus = h->GetRMS() /sqrt( h->GetEntries() );
 MC_Dphi_Eplus_EEplus      = hMC->GetMean();
 errMC_Dphi_Eplus_EEplus   = hMC->GetRMS() /sqrt( hMC->GetEntries() );
 
 ///==== e- ====
 nameHistoInRootFile = Form("Data/%s_128_1_Tot_temp",nameDATA.Data());
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 nameHistoInRootFile = Form ("Data/W_128_1_Tot_temp");  
 hMC = (TH1F*) fileIn->Get(nameHistoInRootFile);
 cJoint->cd();
 h->Draw();
 norm = h->Integral(); hMC->DrawNormalized("HISTsame",norm);
 cJoint->SetGrid();
 TLegend* legEMinusEEplus = cJoint->BuildLegend(0.8,0.55,0.98,0.75);
 legEMinusEEplus->SetFillColor(kWhite);
 cJoint->SetGrid();   
 toDoROOT = Form("%s/plot/DphiEMinusEEplus.png",nameOutputDir.Data());
 cJoint->SaveAs(toDoROOT);
 DATA_Dphi_Eminus_EEplus    = h->GetMean();
 errDATA_Dphi_Eminus_EEplus = h->GetRMS() /sqrt( h->GetEntries() );
 MC_Dphi_Eminus_EEplus      = hMC->GetMean();
 errMC_Dphi_Eminus_EEplus   = hMC->GetRMS() /sqrt( hMC->GetEntries() );
 
 ///==== e^{-} + e^{+} ====
 nameHistoInRootFile = Form("Data/%s_120_1_Tot_temp",nameDATA.Data());
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 nameHistoInRootFile = Form ("Data/W_120_1_Tot_temp");  
 hMC = (TH1F*) fileIn->Get(nameHistoInRootFile);
 cJoint->cd();
 h->Draw();
 norm = h->Integral(); hMC->DrawNormalized("HISTsame",norm);
 cJoint->SetGrid();
 TLegend* legEEplus = cJoint->BuildLegend(0.8,0.55,0.98,0.75);
 legEEplus->SetFillColor(kWhite);
 cJoint->SetGrid();   
 toDoROOT = Form("%s/plot/DphiEEplus.png",nameOutputDir.Data());
 cJoint->SaveAs(toDoROOT);
 DATA_Dphi_EEplus    = h->GetMean();
 errDATA_Dphi_EEplus = h->GetRMS() /sqrt( h->GetEntries() );
 MC_Dphi_EEplus      = hMC->GetMean();
 errMC_Dphi_EEplus   = hMC->GetRMS() /sqrt( hMC->GetEntries() );
 
 
 
 nameHistoInRootFile = Form("Data/%s_120_0_Tot_temp",nameDATA.Data());
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 nameHistoInRootFile = Form ("Data/W_120_0_Tot_temp");  
 hMC = (TH1F*) fileIn->Get(nameHistoInRootFile);
 cJoint->cd();
 h->Draw();
 norm = h->Integral(); hMC->DrawNormalized("HISTsame",norm);
 cJoint->SetGrid();
 TLegend* legEEplus = cJoint->BuildLegend(0.8,0.55,0.98,0.75);
 legEEplus->SetFillColor(kWhite);
 cJoint->SetGrid();   
 toDoROOT = Form("%s/plot/DetaEEplus.png",nameOutputDir.Data());
 cJoint->SaveAs(toDoROOT);
 DATA_Deta_EEplus    = h->GetMean();
 errDATA_Deta_EEplus = h->GetRMS() /sqrt( h->GetEntries() );
 MC_Deta_EEplus      = hMC->GetMean();
 errMC_Deta_EEplus   = hMC->GetRMS() /sqrt( hMC->GetEntries() );
 
 
 
 
 
 
 ///==== EE- ====
 ///==== e+ ====
 nameHistoInRootFile = Form("Data/%s_127_1_Tot_temp",nameDATA.Data());
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 nameHistoInRootFile = Form ("Data/W_127_1_Tot_temp");  
 hMC = (TH1F*) fileIn->Get(nameHistoInRootFile);
 cJoint->cd();
 h->Draw();
 norm = h->Integral(); hMC->DrawNormalized("HISTsame",norm);
 cJoint->SetGrid();
 TLegend* legEPlusEEminus = cJoint->BuildLegend(0.8,0.55,0.98,0.75);
 legEPlusEEminus->SetFillColor(kWhite);
 cJoint->SetGrid();   
 toDoROOT = Form("%s/plot/DphiEPlusEEminus.png",nameOutputDir.Data());
 cJoint->SaveAs(toDoROOT);
 DATA_Dphi_Eplus_EEminus    = h->GetMean();
 errDATA_Dphi_Eplus_EEminus = h->GetRMS() /sqrt( h->GetEntries() );
 MC_Dphi_Eplus_EEminus      = hMC->GetMean();
 errMC_Dphi_Eplus_EEminus   = hMC->GetRMS() /sqrt( hMC->GetEntries() );
 
 ///==== e- ====
 nameHistoInRootFile = Form("Data/%s_131_1_Tot_temp",nameDATA.Data());
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 nameHistoInRootFile = Form ("Data/W_131_1_Tot_temp");  
 hMC = (TH1F*) fileIn->Get(nameHistoInRootFile);
 cJoint->cd();
 h->Draw();
 norm = h->Integral(); hMC->DrawNormalized("HISTsame",norm);
 cJoint->SetGrid();
 TLegend* legEMinusEEminus = cJoint->BuildLegend(0.8,0.55,0.98,0.75);
 legEMinusEEminus->SetFillColor(kWhite);
 cJoint->SetGrid();   
 toDoROOT = Form("%s/plot/DphiEMinusEEminus.png",nameOutputDir.Data());
 cJoint->SaveAs(toDoROOT);
 DATA_Dphi_Eminus_EEminus    = h->GetMean();
 errDATA_Dphi_Eminus_EEminus = h->GetRMS() /sqrt( h->GetEntries() );
 MC_Dphi_Eminus_EEminus      = hMC->GetMean();
 errMC_Dphi_Eminus_EEminus   = hMC->GetRMS() /sqrt( hMC->GetEntries() );
 
 ///==== e^{-} + e^{+} ====
 nameHistoInRootFile = Form("Data/%s_123_1_Tot_temp",nameDATA.Data());
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 nameHistoInRootFile = Form ("Data/W_123_1_Tot_temp");  
 hMC = (TH1F*) fileIn->Get(nameHistoInRootFile);
 cJoint->cd();
 h->Draw();
 norm = h->Integral(); hMC->DrawNormalized("HISTsame",norm);
 cJoint->SetGrid();
 TLegend* legEEminus = cJoint->BuildLegend(0.8,0.55,0.98,0.75);
 legEEminus->SetFillColor(kWhite);
 cJoint->SetGrid();   
 toDoROOT = Form("%s/plot/DphiEEminus.png",nameOutputDir.Data());
 cJoint->SaveAs(toDoROOT);
 DATA_Dphi_EEminus    = h->GetMean();
 errDATA_Dphi_EEminus = h->GetRMS() /sqrt( h->GetEntries() );
 MC_Dphi_EEminus      = hMC->GetMean();
 errMC_Dphi_EEminus   = hMC->GetRMS() /sqrt( hMC->GetEntries() );
 
 
 nameHistoInRootFile = Form("Data/%s_123_0_Tot_temp",nameDATA.Data());
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 nameHistoInRootFile = Form ("Data/W_123_0_Tot_temp");  
 hMC = (TH1F*) fileIn->Get(nameHistoInRootFile);
 cJoint->cd();
 h->Draw();
 norm = h->Integral(); hMC->DrawNormalized("HISTsame",norm);
 cJoint->SetGrid();
 TLegend* legEEminus = cJoint->BuildLegend(0.8,0.55,0.98,0.75);
 legEEminus->SetFillColor(kWhite);
 cJoint->SetGrid();   
 toDoROOT = Form("%s/plot/DetaEEminus.png",nameOutputDir.Data());
 cJoint->SaveAs(toDoROOT);
 DATA_Deta_EEminus    = h->GetMean();
 errDATA_Deta_EEminus = h->GetRMS() /sqrt( h->GetEntries() );
 MC_Deta_EEminus      = hMC->GetMean();
 errMC_Deta_EEminus   = hMC->GetRMS() /sqrt( hMC->GetEntries() );
 
 
 
 
 
 
 
 
 ///==== write to html ==== 
 
 TString nameFileHTML = Form("%s/ModulesMiddle.html",nameOutputDir.Data());
 std::ofstream myfile;
 myfile.precision (3) ;
 myfile.unsetf(std::ios::scientific); 
 myfile.open (nameFileHTML.Data());
 
 
 myfile << " <table summary=\"\" border=\"3\" cellpadding=\"14\" > " << std::endl;
 myfile << " <tr> " << std::endl;
 myfile << " <td COLSPAN=\"1\"> " << std::endl;
 myfile << " <b>&Delta;&phi; e+</b> " << std::endl;
 myfile << " </td> " << std::endl;
 myfile << " " << std::endl;  
 myfile << " <td COLSPAN=\"1\"> " << std::endl;
 myfile << "  <center> EB+ </center></br>  " << std::endl;
 myfile << " <center><a href=\"plot/DphiEPlusEBplus.png\" target=\"_blank\"><img src=\"plot/DphiEPlusEBplus.png\" height=\"100\" width=\"100\"></a></center> " << std::endl;
 myfile << "  <font color=\"blue\"><center>  " <<   MC_Dphi_Eplus_EBplus  << " &pm; " <<   errMC_Dphi_Eplus_EBplus   << " </center></font> </br>" << std::endl;
 myfile << "  <font color=\"red\"><center>  "  << DATA_Dphi_Eplus_EBplus  << " &pm; " << errDATA_Dphi_Eplus_EBplus   << " </center></font> </br></br>" << std::endl;  
 myfile << "  <center> EB- </center></br>  " << std::endl;
 myfile << " <center><a href=\"plot/DphiEPlusEBminus.png\" target=\"_blank\"><img src=\"plot/DphiEPlusEBminus.png\" height=\"100\" width=\"100\"></a></center> " << std::endl;
 myfile << "  <font color=\"blue\"><center>  " <<   MC_Dphi_Eplus_EBminus  << " &pm; " <<   errMC_Dphi_Eplus_EBminus   << " </center></font> </br>" << std::endl;
 myfile << "  <font color=\"red\"><center>  "  << DATA_Dphi_Eplus_EBminus  << " &pm; " << errDATA_Dphi_Eplus_EBminus   << " </center></font> </br></br>" << std::endl;  
 myfile << " </td> " << std::endl;
 myfile << " " << std::endl;  
 myfile << " <td COLSPAN=\"1\"> " << std::endl;
 myfile << "  <center> EE+ </center></br>  " << std::endl;
 myfile << " <center><a href=\"plot/DphiEPlusEEplus.png\" target=\"_blank\"><img src=\"plot/DphiEPlusEEplus.png\" height=\"100\" width=\"100\"></a></center> " << std::endl;
 myfile << "  <font color=\"blue\"><center>  " <<   MC_Dphi_Eplus_EEplus  << " &pm; " <<   errMC_Dphi_Eplus_EEplus   << " </center></font> </br>" << std::endl;
 myfile << "  <font color=\"red\"><center>  "  << DATA_Dphi_Eplus_EEplus  << " &pm; " << errDATA_Dphi_Eplus_EEplus   << " </center></font> </br></br>" << std::endl;  
 myfile << "  <center> EE- </center></br>  " << std::endl;
 myfile << " <center><a href=\"plot/DphiEPlusEEminus.png\" target=\"_blank\"><img src=\"plot/DphiEPlusEEminus.png\" height=\"100\" width=\"100\"></a></center> " << std::endl;
 myfile << "  <font color=\"blue\"><center>  " <<   MC_Dphi_Eplus_EEminus  << " &pm; " <<   errMC_Dphi_Eplus_EEminus   << " </center></font> </br>" << std::endl;
 myfile << "  <font color=\"red\"><center>  "  << DATA_Dphi_Eplus_EEminus  << " &pm; " << errDATA_Dphi_Eplus_EEminus   << " </center></font> </br></br>" << std::endl;  
 myfile << " </td> " << std::endl;
 myfile << " " << std::endl;  
 myfile << " " << std::endl;  
 myfile << " <td ROWSPAN=\"2\"> " << std::endl;
 myfile << "  <center> EB+ </center></br>  " << std::endl;
 myfile << " <center><a href=\"plot/DphiEBplus.png\" target=\"_blank\"><img src=\"plot/DphiEBplus.png\" height=\"100\" width=\"100\"></a></center> " << std::endl;
 myfile << "  <font color=\"blue\"><center>  " <<   MC_Dphi_EBplus  << " &pm; " <<   errMC_Dphi_EBplus   << " </center></font> </br>" << std::endl;
 myfile << "  <font color=\"red\"><center>  "  << DATA_Dphi_EBplus  << " &pm; " << errDATA_Dphi_EBplus   << " </center></font> </br></br>" << std::endl;  
 myfile << "  <center> EB- </center></br>  " << std::endl;
 myfile << " <center><a href=\"plot/DphiEBminus.png\" target=\"_blank\"><img src=\"plot/DphiEBminus.png\" height=\"100\" width=\"100\"></a></center> " << std::endl;
 myfile << "  <font color=\"blue\"><center>  " <<   MC_Dphi_EBminus  << " &pm; " <<   errMC_Dphi_EBminus   << " </center></font> </br>" << std::endl;
 myfile << "  <font color=\"red\"><center>  "  << DATA_Dphi_EBminus  << " &pm; " << errDATA_Dphi_EBminus   << " </center></font> </br></br>" << std::endl;  
 myfile << " </td> " << std::endl;
 myfile << " " << std::endl;  
 myfile << " <td ROWSPAN=\"2\"> " << std::endl;
 myfile << "  <center> EE+ </center></br>  " << std::endl;
 myfile << " <center><a href=\"plot/DphiEEplus.png\" target=\"_blank\"><img src=\"plot/DphiEEplus.png\" height=\"100\" width=\"100\"></a></center> " << std::endl;
 myfile << "  <font color=\"blue\"><center>  " <<   MC_Dphi_EEplus  << " &pm; " <<   errMC_Dphi_EEplus   << " </center></font> </br>" << std::endl;
 myfile << "  <font color=\"red\"><center>  "  << DATA_Dphi_EEplus  << " &pm; " << errDATA_Dphi_EEplus   << " </center></font> </br></br>" << std::endl;  
 myfile << "  <center> EE- </center></br>  " << std::endl;
 myfile << " <center><a href=\"plot/DphiEEminus.png\" target=\"_blank\"><img src=\"plot/DphiEEminus.png\" height=\"100\" width=\"100\"></a></center> " << std::endl;
 myfile << "  <font color=\"blue\"><center>  " <<   MC_Dphi_EEminus  << " &pm; " <<   errMC_Dphi_EEminus   << " </center></font> </br>" << std::endl;
 myfile << "  <font color=\"red\"><center>  "  << DATA_Dphi_EEminus  << " &pm; " << errDATA_Dphi_EEminus   << " </center></font> </br></br>" << std::endl;  
 myfile << " </td> " << std::endl;
 myfile << " " << std::endl;  
 myfile << " " << std::endl;  
 myfile << " </tr> " << std::endl;
 myfile << " " << std::endl;  
 myfile << " <tr> " << std::endl;
 myfile << " <td COLSPAN=\"1\"> " << std::endl;
 myfile << " <b>&Delta;&phi; e-</b> " << std::endl;
 myfile << " </td> " << std::endl;
 myfile << " " << std::endl;  
 myfile << " <td COLSPAN=\"1\"> " << std::endl;
 myfile << "  <center> EB+ </center></br>  " << std::endl;
 myfile << " <center><a href=\"plot/DphiEMinusEBplus.png\" target=\"_blank\"><img src=\"plot/DphiEMinusEBplus.png\" height=\"100\" width=\"100\"></a></center> " << std::endl;
 myfile << "  <font color=\"blue\"><center>  " <<   MC_Dphi_Eminus_EBplus  << " &pm; " <<   errMC_Dphi_Eminus_EBplus   << " </center></font> </br>" << std::endl;
 myfile << "  <font color=\"red\"><center>  "  << DATA_Dphi_Eminus_EBplus  << " &pm; " << errDATA_Dphi_Eminus_EBplus   << " </center></font> </br></br>" << std::endl;  
 myfile << "  <center> EB- </center></br>  " << std::endl;
 myfile << " <center><a href=\"plot/DphiEMinusEBminus.png\" target=\"_blank\"><img src=\"plot/DphiEMinusEBminus.png\" height=\"100\" width=\"100\"></a></center> " << std::endl;
 myfile << "  <font color=\"blue\"><center>  " <<   MC_Dphi_Eminus_EBminus  << " &pm; " <<   errMC_Dphi_Eminus_EBminus   << " </center></font> </br>" << std::endl;
 myfile << "  <font color=\"red\"><center>  "  << DATA_Dphi_Eminus_EBminus  << " &pm; " << errDATA_Dphi_Eminus_EBminus   << " </center></font> </br></br>" << std::endl;  
 myfile << " </td> " << std::endl;
 myfile << " " << std::endl;  
 myfile << " " << std::endl;  
 myfile << " <td COLSPAN=\"1\"> " << std::endl;
 myfile << "  <center> EE+ </center></br>  " << std::endl;
 myfile << " <center><a href=\"plot/DphiEMinusEEplus.png\" target=\"_blank\"><img src=\"plot/DphiEMinusEEplus.png\" height=\"100\" width=\"100\"></a></center> " << std::endl;
 myfile << "  <font color=\"blue\"><center>  " <<   MC_Dphi_Eminus_EEplus  << " &pm; " <<   errMC_Dphi_Eminus_EEplus   << " </center></font> </br>" << std::endl;
 myfile << "  <font color=\"red\"><center>  "  << DATA_Dphi_Eminus_EEplus  << " &pm; " << errDATA_Dphi_Eminus_EEplus   << " </center></font> </br></br>" << std::endl;  
 myfile << "  <center> EE- </center></br>  " << std::endl;
 myfile << " <center><a href=\"plot/DphiEMinusEEminus.png\" target=\"_blank\"><img src=\"plot/DphiEMinusEEminus.png\" height=\"100\" width=\"100\"></a></center> " << std::endl;
 myfile << "  <font color=\"blue\"><center>  " <<   MC_Dphi_Eminus_EEminus  << " &pm; " <<   errMC_Dphi_Eminus_EEminus   << " </center></font> </br>" << std::endl;
 myfile << "  <font color=\"red\"><center>  "  << DATA_Dphi_Eminus_EEminus  << " &pm; " << errDATA_Dphi_Eminus_EEminus   << " </center></font> </br></br>" << std::endl;  
 myfile << " </td> " << std::endl;
 myfile << " " << std::endl;  
 myfile << " <tr> " << std::endl;
 myfile << " <td COLSPAN=\"1\"> " << std::endl;
 myfile << " <b>&Delta;&eta;</b> " << std::endl;
 myfile << " </td> " << std::endl;
 myfile << " " << std::endl;  
 myfile << "  <td COLSPAN=\"2\"> " << std::endl;
 myfile << "  <center> EB+ </center></br>  " << std::endl;
 myfile << " <center><a href=\"plot/DetaEBplus.png\" target=\"_blank\"><img src=\"plot/DetaEBplus.png\" height=\"100\" width=\"100\"></a></center> " << std::endl;
 myfile << "  <font color=\"blue\"><center>  " <<   MC_Deta_EBplus  << " &pm; " <<   errMC_Deta_EBplus   << " </center></font> </br>" << std::endl;
 myfile << "  <font color=\"red\"><center>  "  << DATA_Deta_EBplus  << " &pm; " << errDATA_Deta_EBplus   << " </center></font> </br></br>" << std::endl; 
 myfile << "  <center> EB- </center></br>  " << std::endl;
 myfile << " <center><a href=\"plot/DetaEBminus.png\" target=\"_blank\"><img src=\"plot/DetaEBminus.png\" height=\"100\" width=\"100\"></a></center> " << std::endl;
 myfile << "  <font color=\"blue\"><center>  " <<   MC_Deta_EBminus  << " &pm; " <<   errMC_Deta_EBminus   << " </center></font> </br>" << std::endl;
 myfile << "  <font color=\"red\"><center>  "  << DATA_Deta_EBminus  << " &pm; " << errDATA_Deta_EBminus   << " </center></font> </br></br>" << std::endl; 
 myfile << " </td> " << std::endl;
 myfile << " <td COLSPAN=\"2\"> " << std::endl;
 myfile << "  <center> EE+ </center></br>  " << std::endl;
 myfile << " <center><a href=\"plot/DetaEEplus.png\" target=\"_blank\"><img src=\"plot/DetaEEplus.png\" height=\"100\" width=\"100\"></a></center> " << std::endl;
 myfile << "  <font color=\"blue\"><center>  " <<   MC_Deta_EEplus  << " &pm; " <<   errMC_Deta_EEplus   << " </center></font> </br>" << std::endl;
 myfile << "  <font color=\"red\"><center>  "  << DATA_Deta_EEplus  << " &pm; " << errDATA_Deta_EEplus   << " </center></font> </br></br>" << std::endl; 
 myfile << "  <center> EE- </center></br>  " << std::endl;
 myfile << " <center><a href=\"plot/DetaEEminus.png\" target=\"_blank\"><img src=\"plot/DetaEEminus.png\" height=\"100\" width=\"100\"></a></center> " << std::endl;
 myfile << "  <font color=\"blue\"><center>  " <<   MC_Deta_EEminus  << " &pm; " <<   errMC_Deta_EEminus   << " </center></font> </br>" << std::endl;
 myfile << "  <font color=\"red\"><center>  "  << DATA_Deta_EEminus  << " &pm; " << errDATA_Deta_EEminus   << " </center></font> </br></br>" << std::endl; 
 myfile << " </td> " << std::endl;
 myfile << " " << std::endl;  
 myfile << " </tr> " << std::endl;
 myfile << "  " << std::endl;
 myfile << " </table> " << std::endl;
 myfile << " " << std::endl;  
 myfile << " <br><br><br><br> " << std::endl;
 myfile << " " << std::endl;
 
 
 
 
 
 myfile << " <table summary=\"\" border=\"3\" cellpadding=\"14\" > " << std::endl;
 myfile << " " << std::endl;  
 myfile << " <tr> " << std::endl;
 myfile << " <td COLSPAN=\"1\" ROWSPAN=\"3\" > <center> Module </center> </td> " << std::endl;
 myfile << " <td COLSPAN=\"1\" ROWSPAN=\"1\"> <font color=\"black\">  &Delta;&phi; e+ </font></center> </td> " << std::endl;
 myfile << " <td COLSPAN=\"1\" ROWSPAN=\"1\"> <font color=\"black\">  &Delta;&phi; e- </font></center> </td> " << std::endl;
 myfile << " <td COLSPAN=\"1\" ROWSPAN=\"1\"> <font color=\"black\">  &Delta;&eta;    </font></center> </td> " << std::endl;
 myfile << " <td COLSPAN=\"1\" ROWSPAN=\"1\"> <font color=\"black\">  &Delta;&phi;    </font></center> </td> " << std::endl;
 myfile << " </tr> " << std::endl;
 myfile << " " << std::endl; 
 myfile << " <tr> " << std::endl;
 myfile << " <td COLSPAN=\"1\" ROWSPAN=\"1\"> <font color=\"red\">  DATA  </font></center> </td> " << std::endl;
 myfile << " <td COLSPAN=\"1\" ROWSPAN=\"1\"> <font color=\"red\">  DATA  </font></center> </td> " << std::endl;
 myfile << " <td COLSPAN=\"1\" ROWSPAN=\"1\"> <font color=\"red\">  DATA  </font></center> </td> " << std::endl;
 myfile << " <td COLSPAN=\"1\" ROWSPAN=\"1\"> <font color=\"red\">  DATA  </font></center> </td> " << std::endl;
 myfile << " </tr> " << std::endl;
 myfile << " <tr> " << std::endl;
 myfile << " <td COLSPAN=\"1\" ROWSPAN=\"1\"> <font color=\"blue\">  MC  </font></center> </td> " << std::endl;
 myfile << " <td COLSPAN=\"1\" ROWSPAN=\"1\"> <font color=\"blue\">  MC  </font></center> </td> " << std::endl;
 myfile << " <td COLSPAN=\"1\" ROWSPAN=\"1\"> <font color=\"blue\">  MC  </font></center> </td> " << std::endl;
 myfile << " <td COLSPAN=\"1\" ROWSPAN=\"1\"> <font color=\"blue\">  MC  </font></center> </td> " << std::endl;
 myfile << " </tr> " << std::endl;
 
 
 
 
 ///=======================
 ///==== Summary plots ====
 
 
 
 TGraphErrors* grDATA_Dphi = new TGraphErrors();
 grDATA_Dphi->SetTitle("#Delta#phi DATA");
 grDATA_Dphi->SetMarkerColor(kRed);
 grDATA_Dphi->SetLineColor(kRed);
 grDATA_Dphi->SetFillColor(kRed);
 grDATA_Dphi->SetMarkerStyle(20);
 grDATA_Dphi->SetMarkerSize(1);
 grDATA_Dphi->SetLineWidth(1);
 grDATA_Dphi->GetXaxis()->SetTitle("iDet");
 grDATA_Dphi->GetYaxis()->SetTitle("#Delta#phi");
 
 TGraphErrors* grDATA_Dphi_ePlus = new TGraphErrors();
 grDATA_Dphi_ePlus->SetTitle("#Delta#phi e+ DATA");
 grDATA_Dphi_ePlus->SetMarkerColor(kRed);
 grDATA_Dphi_ePlus->SetLineColor(kRed);
 grDATA_Dphi_ePlus->SetFillColor(kRed);
 grDATA_Dphi_ePlus->SetMarkerStyle(20);
 grDATA_Dphi_ePlus->SetMarkerSize(1);
 grDATA_Dphi_ePlus->SetLineWidth(1);
 grDATA_Dphi_ePlus->GetXaxis()->SetTitle("iDet");
 grDATA_Dphi_ePlus->GetYaxis()->SetTitle("#Delta#phi");
 
 TGraphErrors* grDATA_Dphi_eMinus = new TGraphErrors();
 grDATA_Dphi_eMinus->SetTitle("#Delta#phi e- DATA");
 grDATA_Dphi_eMinus->SetMarkerColor(kRed);
 grDATA_Dphi_eMinus->SetLineColor(kRed);
 grDATA_Dphi_eMinus->SetFillColor(kRed);
 grDATA_Dphi_eMinus->SetMarkerStyle(20);
 grDATA_Dphi_eMinus->SetMarkerSize(1);
 grDATA_Dphi_eMinus->SetLineWidth(1);
 grDATA_Dphi_eMinus->GetXaxis()->SetTitle("iDet");
 grDATA_Dphi_eMinus->GetYaxis()->SetTitle("#Delta#phi");
 
 TGraphErrors* grDATA_Deta = new TGraphErrors();
 grDATA_Deta->SetTitle("#Delta#eta DATA");
 grDATA_Deta->SetMarkerColor(kRed);
 grDATA_Deta->SetLineColor(kRed);
 grDATA_Deta->SetFillColor(kRed);
 grDATA_Deta->SetMarkerStyle(20);
 grDATA_Deta->SetMarkerSize(1);
 grDATA_Deta->SetLineWidth(1);
 grDATA_Deta->GetXaxis()->SetTitle("iDet");
 grDATA_Deta->GetYaxis()->SetTitle("#Delta#eta");
 
 TGraphErrors* grMC_Dphi = new TGraphErrors();
 grMC_Dphi->SetTitle("#Delta#phi MC");
 grMC_Dphi->SetMarkerColor(kBlue);
 grMC_Dphi->SetLineColor(kBlue);
 grMC_Dphi->SetFillColor(kBlue);
 grMC_Dphi->SetMarkerStyle(21);
 grMC_Dphi->SetMarkerSize(1);
 grMC_Dphi->SetLineWidth(1);
 grMC_Dphi->GetXaxis()->SetTitle("iDet");
 grMC_Dphi->GetYaxis()->SetTitle("#Delta#phi");
 
 TGraphErrors* grMC_Dphi_ePlus = new TGraphErrors();
 grMC_Dphi_ePlus->SetTitle("#Delta#phi e+ MC");
 grMC_Dphi_ePlus->SetMarkerColor(kBlue);
 grMC_Dphi_ePlus->SetLineColor(kBlue);
 grMC_Dphi_ePlus->SetFillColor(kBlue);
 grMC_Dphi_ePlus->SetMarkerStyle(21);
 grMC_Dphi_ePlus->SetMarkerSize(1);
 grMC_Dphi_ePlus->SetLineWidth(1);
 grMC_Dphi_ePlus->GetXaxis()->SetTitle("iDet");
 grMC_Dphi_ePlus->GetYaxis()->SetTitle("#Delta#phi");
 
 TGraphErrors* grMC_Dphi_eMinus = new TGraphErrors();
 grMC_Dphi_eMinus->SetTitle("#Delta#phi e- MC");
 grMC_Dphi_eMinus->SetMarkerColor(kBlue);
 grMC_Dphi_eMinus->SetLineColor(kBlue);
 grMC_Dphi_eMinus->SetFillColor(kBlue);
 grMC_Dphi_eMinus->SetMarkerStyle(21);
 grMC_Dphi_eMinus->SetMarkerSize(1);
 grMC_Dphi_eMinus->SetLineWidth(1);
 grMC_Dphi_eMinus->GetXaxis()->SetTitle("iDet");
 grMC_Dphi_eMinus->GetYaxis()->SetTitle("#Delta#phi");
 
 TGraphErrors* grMC_Deta = new TGraphErrors();
 grMC_Deta->SetTitle("#Delta#eta MC");
 grMC_Deta->SetMarkerColor(kBlue);
 grMC_Deta->SetLineColor(kBlue);
 grMC_Deta->SetFillColor(kBlue);
 grMC_Deta->SetMarkerStyle(21);
 grMC_Deta->SetMarkerSize(1);
 grMC_Deta->SetLineWidth(1);
 grMC_Deta->GetXaxis()->SetTitle("iDet");
 grMC_Deta->GetYaxis()->SetTitle("#Delta#eta"); 
 
 std::cout << " DATA_Dphi_ePlus.size() = " << DATA_Dphi_ePlus.size() << std::endl;
 for (int iSM = 0; iSM <40; iSM++) { 
  grDATA_Dphi->SetPoint(iSM,iSM,DATA_Dphi.at(iSM));
  grDATA_Dphi->SetPointError(iSM,0,DATA_err_Dphi.at(iSM));
  grDATA_Dphi_ePlus->SetPoint(iSM,iSM,DATA_Dphi_ePlus.at(iSM));
  grDATA_Dphi_ePlus->SetPointError(iSM,0,DATA_err_Dphi_ePlus.at(iSM));
  grDATA_Dphi_eMinus->SetPoint(iSM,iSM,DATA_Dphi_eMinus.at(iSM));
  grDATA_Dphi_eMinus->SetPointError(iSM,0,DATA_err_Dphi_eMinus.at(iSM));
  grDATA_Deta->SetPoint(iSM,iSM,DATA_Deta.at(iSM));
  grDATA_Deta->SetPointError(iSM,0,DATA_err_Deta.at(iSM));
  
  grMC_Dphi->SetPoint(iSM,iSM,MC_Dphi.at(iSM));
  grMC_Dphi->SetPointError(iSM,0,MC_err_Dphi.at(iSM));
  grMC_Dphi_ePlus->SetPoint(iSM,iSM,MC_Dphi_ePlus.at(iSM));
  grMC_Dphi_ePlus->SetPointError(iSM,0,MC_err_Dphi_ePlus.at(iSM));
  grMC_Dphi_eMinus->SetPoint(iSM,iSM,MC_Dphi_eMinus.at(iSM));
  grMC_Dphi_eMinus->SetPointError(iSM,0,MC_err_Dphi_eMinus.at(iSM));
  grMC_Deta->SetPoint(iSM,iSM,MC_Deta.at(iSM));
  grMC_Deta->SetPointError(iSM,0,MC_err_Deta.at(iSM));  
 } 
 
 
 
 TCanvas* cJointMG = new TCanvas("cJointMG","cJointMG",1000,500);
 cJointMG->SetLeftMargin(0.10);
 cJointMG->SetRightMargin(0.25);
 cJointMG->SetTopMargin(0.05);
 cJointMG->SetBottomMargin(0.20);
 
 cJointMG->cd();
 TMultiGraph* mgr_Dphi = new TMultiGraph();
 mgr_Dphi->Add(grDATA_Dphi);
 mgr_Dphi->Add(grMC_Dphi);
 mgr_Dphi->Draw("AP");
 mgr_Dphi->GetXaxis()->SetTitle("iDet");
 mgr_Dphi->GetYaxis()->SetTitle("#Delta#phi");
 cJointMG->SetGrid();
 TLegend* legQ = cJointMG->BuildLegend(0.8,0.55,0.98,0.75);
 legQ->SetFillColor(kWhite);
 lineVert.Draw();
 cJointMG->SetGrid();   
 toDoROOT = Form("%s/plot/Dphi.png",nameOutputDir.Data());
 cJointMG->SaveAs(toDoROOT);
 cJointMG->SaveAs(toDoROOT);
 
 cJointMG->Clear();
 cJointMG->cd();
 TMultiGraph* mgr_Dphi_ePlus = new TMultiGraph();
 mgr_Dphi_ePlus->Add(grDATA_Dphi_ePlus);
 mgr_Dphi_ePlus->Add(grMC_Dphi_ePlus);
 mgr_Dphi_ePlus->Draw("AP");
 mgr_Dphi_ePlus->GetXaxis()->SetTitle("iDet");
 mgr_Dphi_ePlus->GetYaxis()->SetTitle("#Delta#phi");
 cJointMG->SetGrid();
 TLegend* legA = cJointMG->BuildLegend(0.8,0.55,0.98,0.75);
 legA->SetFillColor(kWhite);
 lineVert.Draw();
 cJointMG->SetGrid();   
 toDoROOT = Form("%s/plot/DphiEPlus.png",nameOutputDir.Data());
 cJointMG->SaveAs(toDoROOT);
 cJointMG->SaveAs(toDoROOT);
 
 
 cJointMG->Clear();
 cJointMG->cd();
 TMultiGraph* mgr_Dphi_eMinus = new TMultiGraph();
 mgr_Dphi_eMinus->Add(grDATA_Dphi_eMinus);
 mgr_Dphi_eMinus->Add(grMC_Dphi_eMinus);
 mgr_Dphi_eMinus->Draw("AP");
 mgr_Dphi_eMinus->GetXaxis()->SetTitle("iDet");
 mgr_Dphi_eMinus->GetYaxis()->SetTitle("#Delta#phi");
 cJointMG->SetGrid();
 TLegend* legB = cJointMG->BuildLegend(0.8,0.55,0.98,0.75);
 legB->SetFillColor(kWhite);
 lineVert.Draw();
 cJointMG->SetGrid();   
 toDoROOT = Form("%s/plot/DphiEMinus.png",nameOutputDir.Data());
 cJointMG->SaveAs(toDoROOT);
 
 cJointMG->Clear();
 cJointMG->cd();
 TMultiGraph* mgr_Deta = new TMultiGraph();
 mgr_Deta->Add(grDATA_Deta);
 mgr_Deta->Add(grMC_Deta);
 mgr_Deta->Draw("AP");
 mgr_Deta->GetXaxis()->SetTitle("iDet");
 mgr_Deta->GetYaxis()->SetTitle("#Delta#eta");
 cJointMG->SetGrid();
 TLegend* legC = cJointMG->BuildLegend(0.8,0.55,0.98,0.75);
 legC->SetFillColor(kWhite);
 lineVert.Draw();
 cJointMG->SetGrid();   
 toDoROOT = Form("%s/plot/Deta.png",nameOutputDir.Data());
 cJointMG->SaveAs(toDoROOT);
 
 
 
 
 ///============================
 ///==== to create big HTML ====
 
 
 toDoShell = Form("cp scripts/html/templateModulesBegin.html %s/ModulesBegin.html",nameOutputDir.Data());
 system(toDoShell.Data());
 
 toDoShell = Form("cp scripts/html/templateModulesEnd.html %s/ModulesEnd.html",nameOutputDir.Data());
 system(toDoShell.Data());
 
 //  TString nameFileHTML = Form("%s/ModulesMiddle.html",nameOutputDir.Data());
 //  std::ofstream myfile;
 //  myfile.precision (3) ;
 //  myfile.unsetf(std::ios::scientific); 
 //  myfile.open (nameFileHTML.Data());
 for (int iSM = 0; iSM <36; iSM++) { 
  myfile << "<tr>" << std::endl;
  myfile << "   <td COLSPAN=\"1\" ROWSPAN=\"2\" > <center><a href=\"Module_EB_" << iSM << ".html\" target=\"_blank\"> Module EB " << iSM << " </a></center> </td>" << std::endl;
  myfile << "   <td COLSPAN=\"1\" ROWSPAN=\"1\"> <font color=\"red\">  " << DATA_Dphi_ePlus.at(iSM)  << " &pm; " << DATA_err_Dphi_ePlus.at(iSM)   << " </font></center> </td>" << std::endl;
  myfile << "   <td COLSPAN=\"1\" ROWSPAN=\"1\"> <font color=\"red\">  " << DATA_Dphi_eMinus.at(iSM) << " &pm; " << DATA_err_Dphi_eMinus.at(iSM)  << " </font></center> </td>" << std::endl;
  myfile << "   <td COLSPAN=\"1\" ROWSPAN=\"1\"> <font color=\"red\">  " << DATA_Deta.at(iSM)        << " &pm; " << DATA_err_Deta.at(iSM)         << " </font></center> </td>" << std::endl;
  myfile << "   <td COLSPAN=\"1\" ROWSPAN=\"1\"> <font color=\"red\">  " << DATA_Dphi.at(iSM)        << " &pm; " << DATA_err_Dphi.at(iSM)         << " </font></center> </td>" << std::endl;
  myfile << "</tr>" << std::endl;
  myfile << "<tr>" << std::endl;
  myfile << "   <td COLSPAN=\"1\" ROWSPAN=\"1\"> <font color=\"blue\">  " << MC_Dphi_ePlus.at(iSM)  << " &pm; " << MC_err_Dphi_ePlus.at(iSM)   << " </font></center> </td>" << std::endl;
  myfile << "   <td COLSPAN=\"1\" ROWSPAN=\"1\"> <font color=\"blue\">  " << MC_Dphi_eMinus.at(iSM) << " &pm; " << MC_err_Dphi_eMinus.at(iSM)  << " </font></center> </td>" << std::endl;
  myfile << "   <td COLSPAN=\"1\" ROWSPAN=\"1\"> <font color=\"blue\">  " << MC_Deta.at(iSM)        << " &pm; " << MC_err_Deta.at(iSM)         << " </font></center> </td>" << std::endl;
  myfile << "   <td COLSPAN=\"1\" ROWSPAN=\"1\"> <font color=\"blue\">  " << MC_Dphi.at(iSM)        << " &pm; " << MC_err_Dphi.at(iSM)         << " </font></center> </td>" << std::endl;
  myfile << "</tr>" << std::endl;
 }
 myfile << "<hr>" << std::endl;
 myfile << "<hr>" << std::endl;
 for (int iSM = 0; iSM <4; iSM++) { 
  myfile << "<tr>" << std::endl;
  myfile << "   <td COLSPAN=\"1\" ROWSPAN=\"2\" > <center><a href=\"Module_EE_" << iSM << ".html\" target=\"_blank\"> Module EE " << iSM << " </a></center> </td>" << std::endl;
  myfile << "   <td COLSPAN=\"1\" ROWSPAN=\"1\"> <font color=\"red\">  " << DATA_Dphi_ePlus.at(iSM+36)  << " &pm; " << DATA_err_Dphi_ePlus.at(iSM+36)   << " </font></center> </td>" << std::endl;
  myfile << "   <td COLSPAN=\"1\" ROWSPAN=\"1\"> <font color=\"red\">  " << DATA_Dphi_eMinus.at(iSM+36) << " &pm; " << DATA_err_Dphi_eMinus.at(iSM+36)  << " </font></center> </td>" << std::endl;
  myfile << "   <td COLSPAN=\"1\" ROWSPAN=\"1\"> <font color=\"red\">  " << DATA_Deta.at(iSM+36)        << " &pm; " << DATA_err_Deta.at(iSM+36)         << " </font></center> </td>" << std::endl;
  myfile << "   <td COLSPAN=\"1\" ROWSPAN=\"1\"> <font color=\"red\">  " << DATA_Dphi.at(iSM+36)        << " &pm; " << DATA_err_Dphi.at(iSM+36)         << " </font></center> </td>" << std::endl;
  myfile << "</tr>" << std::endl;
  myfile << "<tr>" << std::endl;
  myfile << "   <td COLSPAN=\"1\" ROWSPAN=\"1\"> <font color=\"blue\">  " << MC_Dphi_ePlus.at(iSM+36)  << " &pm; " << MC_err_Dphi_ePlus.at(iSM+36)   << " </font></center> </td>" << std::endl;
  myfile << "   <td COLSPAN=\"1\" ROWSPAN=\"1\"> <font color=\"blue\">  " << MC_Dphi_eMinus.at(iSM+36) << " &pm; " << MC_err_Dphi_eMinus.at(iSM+36)  << " </font></center> </td>" << std::endl;
  myfile << "   <td COLSPAN=\"1\" ROWSPAN=\"1\"> <font color=\"blue\">  " << MC_Deta.at(iSM+36)        << " &pm; " << MC_err_Deta.at(iSM+36)         << " </font></center> </td>" << std::endl;
  myfile << "   <td COLSPAN=\"1\" ROWSPAN=\"1\"> <font color=\"blue\">  " << MC_Dphi.at(iSM+36)        << " &pm; " << MC_err_Dphi.at(iSM+36)         << " </font></center> </td>" << std::endl;
  myfile << "</tr>" << std::endl;
 } 
 
 
 
 myfile << "  " << std::endl;
 myfile << " </table> " << std::endl;
 myfile << " " << std::endl;  
 myfile << " <br><br><br><br> " << std::endl;
 myfile << " " << std::endl;
 
 
 myfile << " <br><br><br><br> " << std::endl;
 myfile << "<br>" << std::endl;
 myfile << "<hr>" << std::endl;
 myfile << "<hr>" << std::endl;
 myfile << "<br>" << std::endl;
 
 myfile << " <table summary=\"\" border=\"3\" cellpadding=\"14\" > " << std::endl;
 myfile << " <tr> " << std::endl; 
 myfile << " <td COLSPAN=\"1\"> " << std::endl;
 myfile << "  <center> &eta; </center></br>  " << std::endl;
 myfile << "  <center><a href=\"plot/Eta.png\" target=\"_blank\"><img src=\"plot/Eta.png\" height=\"200\" width=\"200\"></a></center> " << std::endl;
 myfile << " <td COLSPAN=\"1\"> " << std::endl;
 myfile << "  <center> &eta; e+ </center></br>  " << std::endl;
 myfile << "  <center><a href=\"plot/EtaEPlus.png\" target=\"_blank\"><img src=\"plot/Eta.png\" height=\"200\" width=\"200\"></a></center> " << std::endl;
 myfile << " <td COLSPAN=\"1\"> " << std::endl;
 myfile << "  <center> &eta; e-</center></br>  " << std::endl;
 myfile << "  <center><a href=\"plot/EtaEMinus.png\" target=\"_blank\"><img src=\"plot/Eta.png\" height=\"200\" width=\"200\"></a></center> " << std::endl;
 myfile << " </td> " << std::endl;
 myfile << " " << std::endl;  
 myfile << " </tr> " << std::endl;
 
 myfile << " <tr> " << std::endl; 
 myfile << " <td COLSPAN=\"1\"> " << std::endl;
 myfile << "  <center> &phi; </center></br>  " << std::endl;
 myfile << "  <center><a href=\"plot/Phi.png\" target=\"_blank\"><img src=\"plot/Phi.png\" height=\"200\" width=\"200\"></a></center> " << std::endl;
 myfile << " <td COLSPAN=\"1\"> " << std::endl;
 myfile << "  <center> &phi; e+ </center></br>  " << std::endl;
 myfile << "  <center><a href=\"plot/PhiEPlus.png\" target=\"_blank\"><img src=\"plot/Phi.png\" height=\"200\" width=\"200\"></a></center> " << std::endl;
 myfile << " <td COLSPAN=\"1\"> " << std::endl;
 myfile << "  <center> &phi; e-</center></br>  " << std::endl;
 myfile << "  <center><a href=\"plot/PhiEMinus.png\" target=\"_blank\"><img src=\"plot/Phi.png\" height=\"200\" width=\"200\"></a></center> " << std::endl;
 myfile << " </td> " << std::endl;
 myfile << " " << std::endl;  
 myfile << " </tr> " << std::endl;
 
 
 
 
 myfile << " <table summary=\"\" border=\"3\" cellpadding=\"14\" > " << std::endl;
 myfile << " <tr> " << std::endl; 
 myfile << " <td COLSPAN=\"1\"> " << std::endl;
 myfile << "  <center> vertex X </center></br>  " << std::endl;
 myfile << "  <center><a href=\"plot/xVtx.png\" target=\"_blank\"><img src=\"plot/xVtx.png\" height=\"200\" width=\"200\"></a></center> " << std::endl;
 myfile << " <td COLSPAN=\"1\"> " << std::endl;
 myfile << "  <center> vertex Y </center></br>  " << std::endl;
 myfile << "  <center><a href=\"plot/yVtx.png\" target=\"_blank\"><img src=\"plot/yVtx.png\" height=\"200\" width=\"200\"></a></center> " << std::endl;
 myfile << " <td COLSPAN=\"1\"> " << std::endl;
 myfile << "  <center> vertex Z </center></br>  " << std::endl;
 myfile << "  <center><a href=\"plot/zVtx.png\" target=\"_blank\"><img src=\"plot/zVtx.png\" height=\"200\" width=\"200\"></a></center> " << std::endl;
 myfile << " </td> " << std::endl;
 myfile << " " << std::endl;  
 myfile << " </tr> " << std::endl;
 
 myfile << " <table summary=\"\" border=\"3\" cellpadding=\"14\" > " << std::endl;
 myfile << " <tr> " << std::endl; 
 myfile << " <td COLSPAN=\"1\"> " << std::endl;
 myfile << "  <center> vertex X </center></br>  " << std::endl;
 myfile << "  <center><a href=\"plot/xVtx_logy.png\" target=\"_blank\"><img src=\"plot/xVtx_logy.png\" height=\"200\" width=\"200\"></a></center> " << std::endl;
 myfile << " <td COLSPAN=\"1\"> " << std::endl;
 myfile << "  <center> vertex Y </center></br>  " << std::endl;
 myfile << "  <center><a href=\"plot/yVtx_logy.png\" target=\"_blank\"><img src=\"plot/yVtx_logy.png\" height=\"200\" width=\"200\"></a></center> " << std::endl;
 myfile << " <td COLSPAN=\"1\"> " << std::endl;
 myfile << "  <center> vertex Z </center></br>  " << std::endl;
 myfile << "  <center><a href=\"plot/zVtx_logy.png\" target=\"_blank\"><img src=\"plot/zVtx_logy.png\" height=\"200\" width=\"200\"></a></center> " << std::endl;
 myfile << " </td> " << std::endl;
 myfile << " " << std::endl;  
 myfile << " </tr> " << std::endl;
 
 myfile << "  </br></br></br>  " << std::endl;
 myfile << "  <center> Number of Vetexes </center></br>  " << std::endl;
 myfile << "  <center><a href=\"plot/Nvtx.png\" target=\"_blank\"><img src=\"plot/Nvtx.png\" height=\"200\" width=\"200\"></a></center> " << std::endl;
 myfile << "  <center><a href=\"plot/Nvtx_logy.png\" target=\"_blank\"><img src=\"plot/Nvtx_logy.png\" height=\"200\" width=\"200\"></a></center> " << std::endl;
 myfile << " " << std::endl;  
 myfile << " " << std::endl;  
 
 
 
 
 
 
 ///===== additional distributions ====
 
 //---- all ----
 TCanvas* cEta = new TCanvas("cEta","cEta",1000,500);
 cEta->SetLeftMargin(0.10);
 cEta->SetRightMargin(0.25);
 cEta->SetTopMargin(0.05);
 cEta->SetBottomMargin(0.20);
 cEta->cd();
 nameHistoInRootFile = Form("Data/%s_134_4_Tot_temp",nameDATA.Data());
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 h->Draw();
 cEta->SetGrid();   
 toDoROOT = Form("%s/plot/Eta.png",nameOutputDir.Data());
 cEta->SaveAs(toDoROOT); 
 
 
 //---- e+ ----
 TCanvas* cEtaEPlusEPlus = new TCanvas("cEtaEPlus","cEtaEPlus",1000,500);
 cEtaEPlus->SetLeftMargin(0.10);
 cEtaEPlus->SetRightMargin(0.25);
 cEtaEPlus->SetTopMargin(0.05);
 cEtaEPlus->SetBottomMargin(0.20);
 cEtaEPlus->cd();
 nameHistoInRootFile = Form("Data/%s_132_4_Tot_temp",nameDATA.Data());
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 h->Draw();
 cEtaEPlus->SetGrid();   
 toDoROOT = Form("%s/plot/EtaEMinus.png",nameOutputDir.Data());
 cEtaEPlus->SaveAs(toDoROOT); 
 
 
 //---- e- ----
 TCanvas* cEtaEMinusEMinus = new TCanvas("cEtaEMinus","cEtaEMinus",1000,500);
 cEtaEMinus->SetLeftMargin(0.10);
 cEtaEMinus->SetRightMargin(0.25);
 cEtaEMinus->SetTopMargin(0.05);
 cEtaEMinus->SetBottomMargin(0.20);
 cEtaEMinus->cd();
 nameHistoInRootFile = Form("Data/%s_133_4_Tot_temp",nameDATA.Data());
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 h->Draw();
 cEtaEMinus->SetGrid();   
 toDoROOT = Form("%s/plot/EtaEPlus.png",nameOutputDir.Data());
 cEtaEMinus->SaveAs(toDoROOT); 
 
 
 
 
 
 //---- all ----
 TCanvas* cPhi = new TCanvas("cPhi","cPhi",1000,500);
 cPhi->SetLeftMargin(0.10);
 cPhi->SetRightMargin(0.25);
 cPhi->SetTopMargin(0.05);
 cPhi->SetBottomMargin(0.20);
 cPhi->cd();
 nameHistoInRootFile = Form("Data/%s_134_8_Tot_temp",nameDATA.Data());
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 h->Draw();
 cPhi->SetGrid();   
 toDoROOT = Form("%s/plot/Phi.png",nameOutputDir.Data());
 cPhi->SaveAs(toDoROOT); 
 
 
 //---- e+ ----
 TCanvas* cPhiEPlusEPlus = new TCanvas("cPhiEPlus","cPhiEPlus",1000,500);
 cPhiEPlus->SetLeftMargin(0.10);
 cPhiEPlus->SetRightMargin(0.25);
 cPhiEPlus->SetTopMargin(0.05);
 cPhiEPlus->SetBottomMargin(0.20);
 cPhiEPlus->cd();
 nameHistoInRootFile = Form("Data/%s_132_8_Tot_temp",nameDATA.Data());
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 h->Draw();
 cPhiEPlus->SetGrid();   
 toDoROOT = Form("%s/plot/PhiEMinus.png",nameOutputDir.Data());
 cPhiEPlus->SaveAs(toDoROOT); 
 
 
 //---- e- ----
 TCanvas* cPhiEMinusEMinus = new TCanvas("cPhiEMinus","cPhiEMinus",1000,500);
 cPhiEMinus->SetLeftMargin(0.10);
 cPhiEMinus->SetRightMargin(0.25);
 cPhiEMinus->SetTopMargin(0.05);
 cPhiEMinus->SetBottomMargin(0.20);
 cPhiEMinus->cd();
 nameHistoInRootFile = Form("Data/%s_133_8_Tot_temp",nameDATA.Data());
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 h->Draw();
 cPhiEMinus->SetGrid();   
 toDoROOT = Form("%s/plot/PhiEPlus.png",nameOutputDir.Data());
 cPhiEMinus->SaveAs(toDoROOT); 
 
 
 
 
 
 
 
 
 TCanvas* cNvtx = new TCanvas("cNvtx","cNvtx",1000,500);
 cNvtx->SetLeftMargin(0.10);
 cNvtx->SetRightMargin(0.25);
 cNvtx->SetTopMargin(0.05);
 cNvtx->SetBottomMargin(0.20);
 cNvtx->cd();
 nameHistoInRootFile = Form("Data/%s_134_12_Tot_temp",nameDATA.Data());
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 h->Draw();
 nameHistoInRootFile = Form("Data/W_134_12_Tot_temp");
 hMC = (TH1F*) fileIn->Get(nameHistoInRootFile);
 norm = h->Integral(); hMC->DrawNormalized("HISTsame",norm);
 hMC->Draw("HISTsame");
 cNvtx->SetGrid();   
 toDoROOT = Form("%s/plot/Nvtx.png",nameOutputDir.Data());
 cNvtx->SaveAs(toDoROOT); 
 cNvtx->SetLogy();   
 toDoROOT = Form("%s/plot/Nvtx_logy.png",nameOutputDir.Data());
 cNvtx->SaveAs(toDoROOT); 
 
 
 TCanvas* cxVtx = new TCanvas("cxVtx","cxVtx",1000,500);
 cxVtx->SetLeftMargin(0.10);
 cxVtx->SetRightMargin(0.25);
 cxVtx->SetTopMargin(0.05);
 cxVtx->SetBottomMargin(0.20);
 cxVtx->cd();
 nameHistoInRootFile = Form("Data/%s_134_9_Tot_temp",nameDATA.Data());
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 h->Draw();
 nameHistoInRootFile = Form("Data/W_134_9_Tot_temp");
 hMC = (TH1F*) fileIn->Get(nameHistoInRootFile);
 norm = h->Integral(); hMC->DrawNormalized("HISTsame",norm);
 hMC->Draw("HISTsame");
 cxVtx->SetGrid();   
 toDoROOT = Form("%s/plot/xVtx.png",nameOutputDir.Data());
 cxVtx->SaveAs(toDoROOT); 
 cxVtx->SetLogy();   
 toDoROOT = Form("%s/plot/xVtx_logy.png",nameOutputDir.Data());
 cxVtx->SaveAs(toDoROOT); 
 
 
 TCanvas* cyVtx = new TCanvas("cyVtx","cyVtx",1000,500);
 cyVtx->SetLeftMargin(0.10);
 cyVtx->SetRightMargin(0.25);
 cyVtx->SetTopMargin(0.05);
 cyVtx->SetBottomMargin(0.20);
 cyVtx->cd();
 nameHistoInRootFile = Form("Data/%s_134_10_Tot_temp",nameDATA.Data());
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 h->Draw();
 nameHistoInRootFile = Form("Data/W_134_10_Tot_temp");
 hMC = (TH1F*) fileIn->Get(nameHistoInRootFile);
 norm = h->Integral(); hMC->DrawNormalized("HISTsame",norm);
 hMC->Draw("HISTsame");
 cyVtx->SetGrid();   
 toDoROOT = Form("%s/plot/yVtx.png",nameOutputDir.Data());
 cyVtx->SaveAs(toDoROOT); 
 cyVtx->SetLogy();   
 toDoROOT = Form("%s/plot/yVtx_logy.png",nameOutputDir.Data());
 cyVtx->SaveAs(toDoROOT); 
 
 
 
 TCanvas* czVtx = new TCanvas("czVtx","czVtx",1000,500);
 czVtx->SetLeftMargin(0.10);
 czVtx->SetRightMargin(0.25);
 czVtx->SetTopMargin(0.05);
 czVtx->SetBottomMargin(0.20);
 czVtx->cd();
 nameHistoInRootFile = Form("Data/%s_134_11_Tot_temp",nameDATA.Data());
 h = (TH1F*) fileIn->Get(nameHistoInRootFile);
 h->Draw();
 nameHistoInRootFile = Form("Data/W_134_11_Tot_temp");
 hMC = (TH1F*) fileIn->Get(nameHistoInRootFile);
 norm = h->Integral(); hMC->DrawNormalized("HISTsame",norm);
 hMC->Draw("HISTsame");
 czVtx->SetGrid();   
 toDoROOT = Form("%s/plot/zVtx.png",nameOutputDir.Data());
 czVtx->SaveAs(toDoROOT); 
 czVtx->SetLogy();   
 toDoROOT = Form("%s/plot/zVtx_logy.png",nameOutputDir.Data());
 czVtx->SaveAs(toDoROOT); 
 
 
 
 
 
 myfile.close(); 
 
 TString totalnameFileHTML = Form("%s/Modules.html",nameOutputDir.Data());
 std::string toCreateHLTML;
 toCreateHLTML.clear();
 toCreateHLTML.insert(toCreateHLTML.size(),"cat scripts/html/templateModulesBegin.html ");
 toCreateHLTML.insert(toCreateHLTML.size(),nameFileHTML.Data());
 toCreateHLTML.insert(toCreateHLTML.size()," scripts/html/templateModulesEnd.html > ");
 toCreateHLTML.insert(toCreateHLTML.size(),totalnameFileHTML.Data());
 toCreateHLTML.insert(toCreateHLTML.size()," ; \n ");
 
 std::cout << std::endl << std::endl << std::endl;
 std::cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ " << std::endl;
 std::cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ " << std::endl;
 std::cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ " << std::endl;
 std::cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ " << std::endl;
 std::cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ " << std::endl;
 std::cout << std::endl << std::endl << std::endl;
 
 //  std::cout << toCreateHLTML << std::endl;
 system(toCreateHLTML.c_str());
 
 std::cout << std::endl << std::endl << std::endl;
 
 
 
 
 
 ///===================================
 ///==== to create many small HTML ====
 
 
 for (int iSM = 0; iSM <36; iSM++) { 
  nameFileHTML = Form("%s/Module_EB_%d_temp.html",nameOutputDir.Data(),iSM);
  std::ofstream myfileCicle;
  myfileCicle.precision (3) ;
  myfileCicle.unsetf(std::ios::scientific); 
  myfileCicle.open (nameFileHTML.Data());
  
  myfileCicle << "<tr> " << std::endl;
  myfileCicle << "<td COLSPAN=\"1\">" << std::endl;
  myfileCicle << "<b>EB module " << iSM << "</b>" << std::endl;
  myfileCicle << "</td>" << std::endl;
  
  myfileCicle << " <td COLSPAN=\"1\">" << std::endl;
  myfileCicle << "<center><font color=\"red\">  " << DATA_Dphi_ePlus.at(iSM)  << " &pm; " << DATA_err_Dphi_ePlus.at(iSM)  << " </font></center>" << std::endl;
  myfileCicle << "<center><font color=\"blue\"> " << MC_Dphi_ePlus.at(iSM)    << " &pm; " << MC_err_Dphi_ePlus.at(iSM)    << " </font></center>" << std::endl;
  myfileCicle << "</td>" << std::endl;
  
  myfileCicle << " <td COLSPAN=\"1\">" << std::endl;
  myfileCicle << "<center><font color=\"red\">  " << DATA_Dphi_eMinus.at(iSM)  << " &pm; " << DATA_err_Dphi_eMinus.at(iSM)  << " </font></center>" << std::endl;
  myfileCicle << "<center><font color=\"blue\"> " << MC_Dphi_eMinus.at(iSM)    << " &pm; " << MC_err_Dphi_eMinus.at(iSM)    << " </font></center>" << std::endl;
  myfileCicle << "</td>" << std::endl;
  
  myfileCicle << " <td COLSPAN=\"2\">" << std::endl;
  myfileCicle << "<center><font color=\"red\">  " << DATA_Deta.at(iSM)  << " &pm; " << DATA_err_Deta.at(iSM)  << " </font></center>" << std::endl;
  myfileCicle << "<center><font color=\"blue\"> " << MC_Deta.at(iSM)    << " &pm; " << MC_err_Deta.at(iSM)    << " </font></center>" << std::endl;
  myfileCicle << "</td>" << std::endl;
  
  myfileCicle << " <td COLSPAN=\"2\">" << std::endl;
  myfileCicle << "<center><font color=\"red\">  " << DATA_Dphi.at(iSM)  << " &pm; " << DATA_err_Dphi.at(iSM)  << " </font></center>" << std::endl;
  myfileCicle << "<center><font color=\"blue\"> " << MC_Dphi.at(iSM)    << " &pm; " << MC_err_Dphi.at(iSM)    << " </font></center>" << std::endl;
  myfileCicle << "</td>" << std::endl;
  
  myfileCicle << "</tr> " << std::endl;
  
  
  myfileCicle << "<tr> " << std::endl;
  myfileCicle << "<td COLSPAN=\"1\">" << std::endl;
  myfileCicle << "<b>EB module " << iSM << "</b>" << std::endl;
  myfileCicle << "</td>" << std::endl;
  
  myfileCicle << " <td COLSPAN=\"1\">" << std::endl;
  myfileCicle << " <center><a href=\"plot/Dphi_EB_" << iSM << "_ePlus.png\" target=\"_blank\"><img src=\"plot/Dphi_EB_" << iSM << "_ePlus.png\" height=\"100\" width=\"100\"></a></center> " << std::endl;
  myfileCicle << "</td>" << std::endl;
  
  myfileCicle << " <td COLSPAN=\"1\">" << std::endl;
  myfileCicle << " <center><a href=\"plot/Dphi_EB_" << iSM << "_eMinus.png\" target=\"_blank\"><img src=\"plot/Dphi_EB_" << iSM << "_eMinus.png\" height=\"100\" width=\"100\"></a></center> " << std::endl;
  myfileCicle << "</td>" << std::endl;
  
  myfileCicle << " <td COLSPAN=\"2\">" << std::endl;
  myfileCicle << " <center><a href=\"plot/Deta_EB_" << iSM << ".png\" target=\"_blank\"><img src=\"plot/Deta_EB_" << iSM << ".png\" height=\"100\" width=\"100\"></a></center> " << std::endl;
  myfileCicle << "</td>" << std::endl;
  
  myfileCicle << " <td COLSPAN=\"2\">" << std::endl;
  myfileCicle << " <center><a href=\"plot/Dphi_EB_" << iSM << ".png\" target=\"_blank\"><img src=\"plot/Dphi_EB_" << iSM << ".png\" height=\"100\" width=\"100\"></a></center> " << std::endl;
  myfileCicle << "</td>" << std::endl;
  
  myfileCicle << "</tr> " << std::endl;
  
  myfileCicle << "</table> " << std::endl;  
  
  myfileCicle << "</center> " << std::endl;  
  myfileCicle << "</body> " << std::endl;  
  myfileCicle << "</html> " << std::endl;  
  
  myfileCicle.close(); 
  
  TString totalnameFileHTML = Form("%s/Module_EB_%d.html",nameOutputDir.Data(),iSM);
  
  std::string toCreateHLTML;
  toCreateHLTML.clear();
  toCreateHLTML.insert(toCreateHLTML.size(),"cat scripts/html/templateOneModuleBegin.html ");
  toCreateHLTML.insert(toCreateHLTML.size(),nameFileHTML.Data());
  toCreateHLTML.insert(toCreateHLTML.size()," > ");
  toCreateHLTML.insert(toCreateHLTML.size(),totalnameFileHTML.Data());
  toCreateHLTML.insert(toCreateHLTML.size()," ; \n ");
  //   std::cout << toCreateHLTML << std::endl;
  system(toCreateHLTML.c_str());
  
 }
 
 
 for (int iSM = 0; iSM <4; iSM++) { 
  nameFileHTML = Form("%s/Module_EE_%d_temp.html",nameOutputDir.Data(),iSM);
  std::ofstream myfileCicle;
  myfileCicle.precision (3) ;
  myfileCicle.unsetf(std::ios::scientific); 
  myfileCicle.open (nameFileHTML.Data());
  
  myfileCicle << "<tr> " << std::endl;
  myfileCicle << "<td COLSPAN=\"1\">" << std::endl;
  myfileCicle << "<b>EE module " << iSM << "</b>" << std::endl;
  myfileCicle << "</td>" << std::endl;
  
  myfileCicle << " <td COLSPAN=\"1\">" << std::endl;
  myfileCicle << "<center><font color=\"red\">  " << DATA_Dphi_ePlus.at(iSM+36)  << " &pm; " << DATA_err_Dphi_ePlus.at(iSM+36)  << " </font></center>" << std::endl;
  myfileCicle << "<center><font color=\"blue\"> " << MC_Dphi_ePlus.at(iSM+36)    << " &pm; " << MC_err_Dphi_ePlus.at(iSM+36)    << " </font></center>" << std::endl;
  myfileCicle << "</td>" << std::endl;
  
  myfileCicle << " <td COLSPAN=\"1\">" << std::endl;
  myfileCicle << "<center><font color=\"red\">  " << DATA_Dphi_eMinus.at(iSM+36)  << " &pm; " << DATA_err_Dphi_eMinus.at(iSM+36)  << " </font></center>" << std::endl;
  myfileCicle << "<center><font color=\"blue\"> " << MC_Dphi_eMinus.at(iSM+36)    << " &pm; " << MC_err_Dphi_eMinus.at(iSM+36)    << " </font></center>" << std::endl;
  myfileCicle << "</td>" << std::endl;
  
  myfileCicle << " <td COLSPAN=\"2\">" << std::endl;
  myfileCicle << "<center><font color=\"red\">  " << DATA_Deta.at(iSM+36)  << " &pm; " << DATA_err_Deta.at(iSM+36)  << " </font></center>" << std::endl;
  myfileCicle << "<center><font color=\"blue\"> " << MC_Deta.at(iSM+36)    << " &pm; " << MC_err_Deta.at(iSM+36)    << " </font></center>" << std::endl;
  myfileCicle << "</td>" << std::endl;
  
  myfileCicle << " <td COLSPAN=\"2\">" << std::endl;
  myfileCicle << "<center><font color=\"red\">  " << DATA_Dphi.at(iSM+36)  << " &pm; " << DATA_err_Dphi.at(iSM+36)  << " </font></center>" << std::endl;
  myfileCicle << "<center><font color=\"blue\"> " << MC_Dphi.at(iSM+36)    << " &pm; " << MC_err_Dphi.at(iSM+36)    << " </font></center>" << std::endl;
  myfileCicle << "</td>" << std::endl;
  
  myfileCicle << "</tr> " << std::endl;
  
  
  myfileCicle << "<tr> " << std::endl;
  myfileCicle << "<td COLSPAN=\"1\">" << std::endl;
  myfileCicle << "<b>EE module " << iSM << "</b>" << std::endl;
  myfileCicle << "</td>" << std::endl;
  
  myfileCicle << " <td COLSPAN=\"1\">" << std::endl;
  myfileCicle << " <center><a href=\"plot/Dphi_EE_" << iSM << "_ePlus.png\" target=\"_blank\"><img src=\"plot/Dphi_EE_" << iSM << "_ePlus.png\" height=\"100\" width=\"100\"></a></center> " << std::endl;
  myfileCicle << "</td>" << std::endl;
  
  myfileCicle << " <td COLSPAN=\"1\">" << std::endl;
  myfileCicle << " <center><a href=\"plot/Dphi_EE_" << iSM << "_eMinus.png\" target=\"_blank\"><img src=\"plot/Dphi_EE_" << iSM << "_eMinus.png\" height=\"100\" width=\"100\"></a></center> " << std::endl;
  myfileCicle << "</td>" << std::endl;
  
  myfileCicle << " <td COLSPAN=\"2\">" << std::endl;
  myfileCicle << " <center><a href=\"plot/Deta_EE_" << iSM << ".png\" target=\"_blank\"><img src=\"plot/Deta_EE_" << iSM << ".png\" height=\"100\" width=\"100\"></a></center> " << std::endl;
  myfileCicle << "</td>" << std::endl;
  
  myfileCicle << " <td COLSPAN=\"2\">" << std::endl;
  myfileCicle << " <center><a href=\"plot/Dphi_EE_" << iSM << ".png\" target=\"_blank\"><img src=\"plot/Dphi_EE_" << iSM << ".png\" height=\"100\" width=\"100\"></a></center> " << std::endl;
  myfileCicle << "</td>" << std::endl;
  
  
  myfileCicle << "</tr> " << std::endl;
  
  myfileCicle << "</table> " << std::endl;  
  
  myfileCicle << "</center> " << std::endl;  
  myfileCicle << "</body> " << std::endl;  
  myfileCicle << "</html> " << std::endl;  
  
  myfileCicle.close(); 
  
  TString totalnameFileHTML = Form("%s/Module_EE_%d.html",nameOutputDir.Data(),iSM);
  std::string toCreateHLTML;
  toCreateHLTML.clear();
  toCreateHLTML.insert(toCreateHLTML.size(),"cat scripts/html/templateOneModuleBegin.html ");
  toCreateHLTML.insert(toCreateHLTML.size(),nameFileHTML.Data());
  toCreateHLTML.insert(toCreateHLTML.size()," > ");
  toCreateHLTML.insert(toCreateHLTML.size(),totalnameFileHTML.Data());
  toCreateHLTML.insert(toCreateHLTML.size()," ; \n ");
  //   std::cout << toCreateHLTML << std::endl;
  system(toCreateHLTML.c_str());
  
 }
 
 
 
 ///==== remove unused ====
 TString toRemove = Form("rm %s/*temp.html",nameOutputDir.Data());
 system(toRemove.Data());
 
 ///==== exit ====
 gApplication->Terminate(0);
 
 
}