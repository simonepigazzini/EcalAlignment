//---------------------------------------------------
//---- plotting tool 2D: extract time dependence ----
//---------------------------------------------------

#include "TDRStyle.cc"

void MeasureTimeMassArbitraryDistribution(std::string nameInFileRoot, 
                                          std::string nameForFileOutput,
                                          std::string var = "etaSC", int NBIN = 1000, float MIN = 0, float MAX = 1000
                                          ) {
  
  std::string var_Y = var;
  int NBIN_Y = NBIN;
  float MIN_Y = MIN;
  float MAX_Y = MAX;
  std::string varHR_Y = var;
  
  std::string var_X = "time/1000000.";
  int NBIN_X = 2000;
  float MIN_X = 1466500000;
  float MAX_X = 1508000000;
  std::string varHR_X = "time";
  std::string globalCut = "mll>60 && mll<130 && ETSC>35";
  
  
  TDRStyle();
  gStyle->SetTitleYOffset(1.1);
  gStyle->cd();
  
  if (varHR_X == "") {
    varHR_X = var_X;
  }
  if (varHR_Y == "") {
    varHR_Y = var_Y;
  }
  gStyle->SetOptStat(0);
  TFile* f_Sig;
  //  TTree* t_Sig;
  TH2F* h_Sig;
  std::string vNameSig = nameInFileRoot;
  
  TString name;
  //  f_Sig = new TFile (vNameSig.c_str());
  //  t_Sig = (TTree*) f_Sig -> Get ("ntupleEcalAlignment/myTree");
  
  TChain* t_Sig = new TChain ("ntupleEcalAlignment/myTree");
  t_Sig -> Add (vNameSig.c_str());
  
  
  //---- setup reasonable time range
  MIN_X = t_Sig->GetMinimum("time") / 1000000.;
  MAX_X = t_Sig->GetMaximum("time") / 1000000.;
  
  //  NBIN_X = (MAX_X - MIN_X) / 3.6; //---- 1 hour, in musec units
  NBIN_X = (MAX_X - MIN_X) * (1/1.)*1000/3.6; //---- ~1 hour
  
  std::cout << " MIN_X  = " << MIN_X << std::endl;
  std::cout << " MAX_X  = " << MAX_X << std::endl;
  std::cout << " NBIN_X = " << NBIN_X << std::endl;
  std::cout << " MAX_X - MIN_X = " << MAX_X - MIN_X << std::endl;
  
  
  
  name = Form ("hSig");
  h_Sig = new TH2F(name.Data(),"",NBIN_X,MIN_X,MAX_X,NBIN_Y,MIN_Y,MAX_Y);
  
  TString weight = Form ("1");
  TString toDraw;
  toDraw = Form ("%s:%s >> hSig",var_Y.c_str(),var_X.c_str());
  weight = Form ("(%s)",globalCut.c_str());
  t_Sig->Draw(toDraw.Data(),weight.Data(),"goff");
  
  //---- estetica
  h_Sig->SetMarkerColor (kRed);
  h_Sig->SetLineColor (kRed);
  h_Sig->SetLineWidth(3);
  h_Sig->SetLineStyle(1);
  h_Sig->GetXaxis()->SetTitle(varHR_X.c_str());
  h_Sig->GetYaxis()->SetTitle(varHR_Y.c_str());
  
  TH2F* sum_h_Sig  = new TH2F("sum_h_Sig","",NBIN_X,MIN_X,MAX_X,NBIN_Y,MIN_Y,MAX_Y);
  sum_h_Sig->Add(h_Sig);
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
  
  
  TCanvas* cc2D_x = new TCanvas("cc2D_x","cc2D_x",700,700);
  cc2D_x->SetGrid();
  sum_h_Sig_tx->Draw("PE");
  
  name = Form ("time_%s__%s_time.root", nameForFileOutput.c_str(), varHR_Y.c_str()); 
//   name = Form ("time_time_%d.root", where);
  TFile outputFile(name.Data(), "recreate");
  sum_h_Sig->Write();
  sum_h_Sig_tx->Write();
  
  
  
  std::ofstream myfile;
  name = Form ("time_%s__%s_time.txt", nameForFileOutput.c_str(), varHR_Y.c_str());
  myfile.open (name.Data());
  myfile << "# from" << nameInFileRoot << "\n";
  myfile << "# time multiplied by 1000000 \n";
  
  for (int i=1; i<(sum_h_Sig_tx->GetNbinsX()+1) ; i++) {
    if (sum_h_Sig_tx->GetBinContent(i) != 0) {
//       myfile << " [" << i << "] =" << sum_h_Sig_tx->GetBinContent(i) << " +/- " << sum_h_Sig_tx->GetBinError(i) << std::endl;    
      myfile << "  " << sum_h_Sig_tx->GetBinCenter(i) <<  "  " << sum_h_Sig_tx->GetBinLowEdge(i) <<  "  " << sum_h_Sig_tx->GetBinLowEdge(i+1); 
      time_t myTime = sum_h_Sig_tx->GetBinCenter(i)*1000000;
      std::string timestring = ctime (&myTime);
      timestring = timestring.substr(0, timestring.size()-1);
      myfile << "     " << timestring << "  " << (long) myTime;
      
      myfile << "  " << sum_h_Sig_tx->GetBinCenter(i);
      myfile << "     " << sum_h_Sig_tx->GetBinContent(i) << "  " << sum_h_Sig_tx->GetBinError(i) << std::endl;       
    }
  }
  
  myfile.close();
  
  
}


