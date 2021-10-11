
void createHisto (TLatex* tinfo, TH1F* hmc, TTree* tmc, const char* variable, const char* title, const char* cut, int col = 0) {
 
 TString toDraw;
 TString tcut;
 
 //  tcut = Form("(%s) * weight_PU",cut);
 tcut = Form("(%s)",cut);
 toDraw = Form("%s >> %s",variable,hmc->GetName());
 tmc   -> Draw(toDraw.Data(),tcut.Data(),"goff");
 
 hmc -> GetXaxis()->SetTitle(title);
 hmc -> GetYaxis()->SetTitle("Number of events");
 
 if (col == 0) {
  hmc->SetMarkerColor(kBlue);
  hmc->SetLineColor(kBlack);
  hmc->SetLineWidth(2);
  hmc->SetFillColor(kBlue);
  hmc->SetFillStyle(3002);
 }
 else {
  hmc->SetMarkerColor(kRed);
  hmc->SetLineColor(kRed);
  hmc->SetLineWidth(2);
  hmc->SetFillColor(kRed);
  hmc->SetFillStyle(3002); 
 }
 
 TString  sinfo;
 if (col == 0) sinfo = Form ("#splitline{<%s>_{DATA} = %.2f #times 10^{-3}}{#sigma_{DATA} = %.2f #times 10^{-3}}",title,hmc->GetMean()*1000,hmc->GetRMS()*1000);
 else          sinfo = Form ("#splitline{<%s>_{MC} = %.2f #times 10^{-3}}{#sigma_{MC} = %.2f #times 10^{-3}}",title,hmc->GetMean()*1000,hmc->GetRMS()*1000);
 if (col == 0) tinfo -> SetText(0.2,0.85,sinfo);
 else          tinfo -> SetText(0.2,0.60,sinfo);
 tinfo -> SetTextSize(0.035);  //0.040
 tinfo -> SetNDC(true); 
}


void createHisto2D (TH2F* hmc, TTree* tmc, const char* variableY, const char* variableX, const char* title, const char* cut, const char* titleY = "", const char* titleX = "") {
 
 TString toDraw;
 TString tcut;
 
 //  tcut = Form("(%s) * weight_PU",cut);
 tcut = Form("(%s)",cut);
 toDraw = Form("%s:%s >> %s",variableY, variableX, hmc->GetName());
 tmc   -> Draw(toDraw.Data(),tcut.Data(),"goff");
 
 hmc -> GetXaxis()->SetTitle(variableX);
 hmc -> GetYaxis()->SetTitle(variableY);
 
 
 if (titleX != "") hmc -> GetXaxis()->SetTitle(titleX);
 if (titleY != "") hmc -> GetYaxis()->SetTitle(titleY);
 
 hmc->SetMarkerColor(kRed);
 hmc->SetLineColor(kRed);
 hmc->SetLineWidth(2);
 hmc->SetFillColor(kRed);
 hmc->SetFillStyle(3002);
 
}
