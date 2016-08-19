//---------------------------------------------------
//---- plotting tool 2D: extract time dependence ----
//---------------------------------------------------

#include "TDRStyle.cc"

void plotVsTime(std::string nameInFileTxt) {
  
  
  std::string buffer;
  std::string temp_string;
  float temp_float;
  long temp_long;
  int num = 0;
  
  TMultiGraph *mg = new TMultiGraph();
  
  TGraphErrors* gr_Deta[4];
  
  TCanvas* all_cc = new TCanvas ("all_cc", "", 800, 600);
  all_cc->Divide(2,2);
  
  int colors[4] = {2, 3, 4, 6};
  
//   for (int iDet = 3; iDet>=0; iDet--) {
  for (int iDet = 0; iDet<4; iDet++) {
    
    all_cc->cd(iDet+1);
    
    std::string complete_nameInFileTxt = nameInFileTxt + "_" + std::to_string(iDet) + ".txt";
    
    std::ifstream file (complete_nameInFileTxt.c_str()); 
    
    if(!file.is_open()) {
      std::cerr << "** ERROR: Can't open '" <<complete_nameInFileTxt << "' for input" << std::endl;
      return;
    }
    
    long long_time_0 [1000];
    float time_0 [1000];
    float error_time_0 [1000];
    float value_0[1000];
    float error_0[1000];
    std::string Week_0[1000];
    std::string Month_0[1000];
    std::string Day_0[1000];
    std::string Time_0[1000];
    std::string Year_0[1000];
    
    num = 0;
    while(!file.eof()) {
      getline(file,buffer);
      //     std::cout << "buffer = " << buffer << std::endl;
      if (buffer != "" && buffer.at(0) != '#') { ///---> save from empty line at the end!
        std::stringstream line( buffer );      
        //       line >> temp_string; 
        //       std::cout << temp_string << " ";
        //       std::cout << std::endl;
        //       buffer =     1463.02  1463.01  1463.02     Thu May 12 03:17:28 2016  1463015848  1463.02     -0.00344362  0.000187843
        
        
        line >> temp_string;                                                                  /*   std::cout << " " << temp_string;  */
        line >> temp_float;   error_time_0[num] =  temp_float;                                /*   std::cout << " " << temp_float;   */
        line >> temp_float;   error_time_0[num] = (temp_float - error_time_0[num]) / 2.;      /*   std::cout << " " << temp_float;   */
        line >> temp_string;  Week_0 [num] = temp_string ;                                    /*   std::cout << " " << temp_string;  */    
        line >> temp_string;  Month_0[num] = temp_string ;                                    /*   std::cout << " " << temp_string;  */    
        line >> temp_string;  Day_0  [num] = temp_string ;                                    /*   std::cout << " " << temp_string;  */    
        line >> temp_string;  Time_0 [num] = temp_string ;                                    /*   std::cout << " " << temp_string;  */    
        line >> temp_string;  Year_0 [num] = temp_string ;                                    /*   std::cout << " " << temp_string;  */    
        
        //       TDatime T0(Year_0 [num], Month_0[num], Day_0[num], 00,00,00);
        //       time_0[num] = T0.Convert();
        
        line >> temp_long;
        long_time_0[num] = temp_long;
        
        line >> temp_float;
        
        line >> value_0[num];
        line >> error_0[num];
        
        //       std::cout  << " ------ " << time_0[num] << "   " <<  value_0[num] << "   " << error_time_0[num] << "   " << error_0[num] << "   " << std::endl;    
        num++;
        
      } 
    }
    
    
    gr_Deta[iDet] = new TGraphErrors();
    for (int i=0; i<num; i++) {
      //     std::cout << " -- " << long_time_0[i] << std::endl;
      gr_Deta[iDet]->SetPoint(i, long_time_0[i], value_0[i]);
      gr_Deta[iDet]->SetPointError(i, error_time_0[i], error_0[i]);
    }
    
    //   (num, long_time_0, value_0, error_time_0, error_0);
    gr_Deta[iDet]->SetMarkerColor(colors[iDet]);
    gr_Deta[iDet]->SetFillStyle(0);
    gr_Deta[iDet]->SetLineColor(colors[iDet]);
    gr_Deta[iDet]->SetLineWidth(2);
    gr_Deta[iDet]->SetMarkerStyle(20+iDet);
    
    gr_Deta[iDet]->Draw("AP");
    
    gStyle->SetTimeOffset(time_0[num]);
    
    gr_Deta[iDet]->GetXaxis()->SetTitle("time");
    gr_Deta[iDet]->GetYaxis()->SetTitle("#Delta#eta");
    
    gr_Deta[iDet]->GetXaxis()->SetTimeDisplay(1);
    gr_Deta[iDet]->GetXaxis()->SetLabelSize(0.03);
    gr_Deta[iDet]->GetXaxis()->SetTimeFormat("%Y\/%m\/%d");
//     gr_Deta[iDet]->GetXaxis()->SetTimeFormat("#splitline{%Y}{%d\/%m}");
    
    
    gPad->SetGrid();
  
    mg->Add(gr_Deta[iDet]); 
  
    if (iDet == 0) gr_Deta[iDet]->SetTitle("EE-"); 
    if (iDet == 1) gr_Deta[iDet]->SetTitle("EB-"); 
    if (iDet == 2) gr_Deta[iDet]->SetTitle("EB+"); 
    if (iDet == 3) gr_Deta[iDet]->SetTitle("EE+"); 
    
  }

  
  TCanvas* cc = new TCanvas ("cc", "", 1200, 600);
  
  gStyle->SetPadRightMargin(0.50);
  
  mg->Draw("AP");
  gPad->SetGrid();

  mg->GetXaxis()->SetTitle("time");
  mg->GetYaxis()->SetTitle("#Delta#eta");
  
  mg->GetXaxis()->SetTimeDisplay(1);
  mg->GetXaxis()->SetLabelSize(0.03);
  mg->GetXaxis()->SetTimeFormat("%Y\/%m\/%d");
  mg->GetXaxis()->SetLabelOffset(0.015);
  mg->GetXaxis()->SetTimeFormat("#splitline{%Y}{%d\/%m}");
  
  TLegend* leg = cc->BuildLegend();
  leg->SetX1(0.90);
  leg->SetX2(0.99);
  leg->SetY1(0.80);
  leg->SetY2(0.20);
  
  leg->Draw();
  
  
  
}





