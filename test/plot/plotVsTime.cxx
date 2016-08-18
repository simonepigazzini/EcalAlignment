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
  
  
  nameInFileTxt = nameInFileTxt + "_" + std::to_string(0) + ".txt";
  
  std::ifstream file (nameInFileTxt.c_str()); 
  
   if(!file.is_open()) {
     std::cerr << "** ERROR: Can't open '" <<nameInFileTxt << "' for input" << std::endl;
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
      
      
      line >> temp_string;   std::cout << " " << temp_string;
      line >> temp_float;   error_time_0[num] =  temp_float;                             std::cout << " " << temp_float;
      line >> temp_float;   error_time_0[num] = (temp_float - error_time_0[num]) / 2.;         std::cout << " " << temp_float;
      line >> temp_string;   std::cout << " " << temp_string;     Week_0 [num] = temp_string ;
      line >> temp_string;   std::cout << " " << temp_string;     Month_0[num] = temp_string ;
      line >> temp_string;   std::cout << " " << temp_string;     Day_0  [num] = temp_string ;
      line >> temp_string;   std::cout << " " << temp_string;     Time_0 [num] = temp_string ;
      line >> temp_string;   std::cout << " " << temp_string;     Year_0 [num] = temp_string ;
      
//       TDatime T0(Year_0 [num], Month_0[num], Day_0[num], 00,00,00);
//       time_0[num] = T0.Convert();
      
      line >> temp_long;
      long_time_0[num] = temp_long;

      line >> temp_float;
      
      line >> value_0[num];
      line >> error_0[num];
      
      std::cout  << " ------ " << time_0[num] << "   " <<  value_0[num] << "   " << error_time_0[num] << "   " << error_0[num] << "   " << std::endl;    
      num++;
      
    } 
  }
  

  TGraphErrors* gr_0 = new TGraphErrors();
  for (int i=0; i<num; i++) {
    std::cout << " -- " << long_time_0[i] << std::endl;
    gr_0->SetPoint(i, long_time_0[i], value_0[i]);
    gr_0->SetPointError(i, error_time_0[i], error_0[i]);
  }
  
//   (num, long_time_0, value_0, error_time_0, error_0);
  gr_0->SetMarkerColor(4);
  gr_0->SetLineColor(4);
  gr_0->SetMarkerStyle(21);
  gr_0->Draw("ALP");
  
 
  gStyle->SetTimeOffset(time_0[num]);
    
  gr_0->GetXaxis()->SetTimeDisplay(1);
  gr_0->GetXaxis()->SetLabelSize(0.03);
  gr_0->GetXaxis()->SetTimeFormat("%Y\/%m\/%d");
  
  
}


