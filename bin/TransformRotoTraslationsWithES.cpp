///===================================
///==== c++ -o TransformRotoTraslationsWithES.exe TransformRotoTraslationsWithES.cpp `root-config --cflags --glibs` -lMinuit `clhep-config --libs`
///===================================

#include "TString.h"
#include "TF1.h"
#include "TH1.h"
#include "TH2.h"
#include "TFile.h"
#include "TTree.h"
#include "TChain.h"
#include "TProfile.h"
#include "TCanvas.h"
#include "TGraphErrors.h"
#include "TEntryList.h"
#include "TMinuit.h"
#include "TF2.h"

#include "Math/Minimizer.h"
#include "Math/Factory.h"
#include "Math/Functor.h"

#include "DataFormats/Math/interface/deltaPhi.h"

//==== parameter include ====
#include "FWCore/Utilities/interface/Exception.h"
#include "FWCore/PythonParameterSet/interface/MakeParameterSets.h"
#include "FWCore/ParameterSet/interface/ProcessDesc.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"


//---- std include ----
#include <string>
#include <map>
#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <fstream> 

///==== CLHEP ====
#include "CLHEP/Vector/EulerAngles.h"
#include "CLHEP/Vector/Rotation.h"
#include "CLHEP/Vector/ThreeVector.h"
#include "CLHEP/Geometry/Transform3D.h"





int main(int argc, char** argv)
{

 std::cout << "                                                                                                                                                                   " << std::endl;
 std::cout << "                                                                                                                                                                   " << std::endl;
 std::cout << "          " << std::endl;           
 std::cout << "          " << std::endl;
 std::cout << "          " << std::endl;
 std::cout << "          " << std::endl;
 std::cout << "                                                                                                                                                                   " << std::endl;
 std::cout << "                                                                                                                                                                   " << std::endl;
 
 if (argc < 3) {
  std::cout << " Error: Code usage: " << std::endl;
  std::cout << "     TransformRotoTraslationsWithES  InputPositionsFileES  OutputPositionsFileEE " << std::endl;
  return false;
 }

 std::string InputPositionsFileES  (argv[1]) ;
 std::string OutputPositionsFileEE (argv[2]) ;
 
 std::cout << " InputPositionsFileES  = " << argv[1] << std::endl;
 std::cout << " OutputPositionsFileEE = " << argv[2] << std::endl;


 std::ifstream* fileInES;
 fileInES = new std::ifstream(InputPositionsFileES.c_str());
 if(!fileInES->is_open()){
  return false;
 }
 
 
 std::string buffer;
 
 
 double EE_plus_fromES_DX;                 double EE_minus_fromES_DX;
 double EE_plus_fromES_DY;                 double EE_minus_fromES_DY;
 double EE_plus_fromES_DZ;                 double EE_minus_fromES_DZ;
 double EE_plus_fromES_DPHI;               double EE_minus_fromES_DPHI;
 double EE_plus_fromES_DTHETA;             double EE_minus_fromES_DTHETA;
 double EE_plus_fromES_DPSI;               double EE_minus_fromES_DPSI;
 
 int number_line = 0; 
 while(!fileInES->eof()){
  getline(*fileInES,buffer);
  std::stringstream lineAddition( buffer );
  
  if (number_line == 0) {
   lineAddition >> EE_minus_fromES_DX;
   lineAddition >> EE_minus_fromES_DY;
   lineAddition >> EE_minus_fromES_DZ;
   lineAddition >> EE_minus_fromES_DPHI;
   lineAddition >> EE_minus_fromES_DTHETA;
   lineAddition >> EE_minus_fromES_DPSI;
  }
  else if (number_line == 1) {
   lineAddition >> EE_plus_fromES_DX;
   lineAddition >> EE_plus_fromES_DY;
   lineAddition >> EE_plus_fromES_DZ;
   lineAddition >> EE_plus_fromES_DPHI;
   lineAddition >> EE_plus_fromES_DTHETA;
   lineAddition >> EE_plus_fromES_DPSI;
  }
  
  number_line++; 
 }
 
 //---- transform ES rototranslations into EE rototranslations;
 
 double Z = 3.205;
 
 
 std::ofstream outFile;
 outFile.open (OutputPositionsFileEE.c_str());

 number_line = 0; 
 for (int iDee=0; iDee<4; iDee++) {
    
  int sign = -1; // EE- or EE+
  double DPHI;
  double DTHETA;
  double DPSI;
 
  double DX;
  double DY;
  double DZ;

  if (number_line == 0 || number_line == 1) { 
   sign = -1;
   DPHI   = EE_minus_fromES_DPHI /1000.;
   DTHETA = EE_minus_fromES_DTHETA /1000.;
   DPSI   = EE_minus_fromES_DPSI /1000.;
   DX = EE_minus_fromES_DX /100.;
   DY = EE_minus_fromES_DY /100.;
   DZ = EE_minus_fromES_DZ /100.;
  }
  else {
   sign = -1;
   DPHI   = EE_plus_fromES_DPHI /1000.;
   DTHETA = EE_plus_fromES_DTHETA /1000.;
   DPSI   = EE_plus_fromES_DPSI /1000.;
   DX = EE_plus_fromES_DX /100.;
   DY = EE_plus_fromES_DY /100.;
   DZ = EE_plus_fromES_DZ /100.;
  }
  
  
  CLHEP::Hep3Vector translationEEtoO(0,0, - Z * sign);
  CLHEP::Hep3Vector translationOtoEE(DX,DY,   Z * sign + DZ);
  CLHEP::HepEulerAngles euler(DPHI, DTHETA, DPSI);
  CLHEP::HepRotation rotation(euler);
  
  if (number_line == 0 ) {
   std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
   std::cout << " DPHI, DTHETA, DPSI = " << DPHI << " , " << DTHETA << " , " << DPSI << std::endl;
   std::cout << "EE- = " << std::endl;
   std::cout << rotation << std::endl;
  }
  if (number_line == 2 ) {
   std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
   std::cout << " DPHI, DTHETA, DPSI = " << DPHI << " , " << DTHETA << " , " << DPSI << std::endl;
   std::cout << "EE+ = " << std::endl;
   std::cout << rotation << std::endl;
  }
  
  HepGeom::Translate3D transformEEtoO  ( translationEEtoO );
  HepGeom::Rotate3D    transformRotate ( rotation );
  HepGeom::Translate3D transformOtoEE  ( translationOtoEE );
  
  HepGeom::Transform3D Combination = transformOtoEE * transformRotate * transformEEtoO;
  CLHEP::Hep3Vector translation_Combination = Combination.getTranslation();
  CLHEP::HepRotation rotation_Combination   = Combination.getRotation();
  
  
  
  outFile << " "   ;
  outFile << std::setfill(' ') << std::setw(10) << std::setprecision(5) << rotation_Combination.getPhi() << " "          ;
  outFile << std::setfill(' ') << std::setw(10) << std::setprecision(5) << rotation_Combination.getTheta() << " "        ;
  outFile << std::setfill(' ') << std::setw(10) << std::setprecision(5) << rotation_Combination.getPsi() << " "          ;
  outFile << std::setfill(' ') << std::setw(10) << std::setprecision(5) << 100 * translation_Combination.getX() << " "   ;
  outFile << std::setfill(' ') << std::setw(10) << std::setprecision(5) << 100 * translation_Combination.getY() << " "   ;
  outFile << std::setfill(' ') << std::setw(10) << std::setprecision(5) << 100 * translation_Combination.getZ() << " "   ;
  outFile << std::endl;
 
  number_line++; 
  
 }

   
//  iDee = 0, 1  --> EE-
//  iDee = 2, 3  --> EE+

 
//   CLHEP::Hep3Vector translation(inputDX,inputDY,inputDZ);
//   CLHEP::HepEulerAngles euler(inputDPHIe, inputDTHETAe, inputDPSIe);
//   CLHEP::HepRotation rotation(euler);
//   HepGeom::Transform3D transform( rotation, translation );
//  
//   CLHEP::Hep3Vector translation_addition(inputDX_addition,inputDY_addition,inputDZ_addition);
//   CLHEP::HepEulerAngles euler_addition(inputDPHIe_addition, inputDTHETAe_addition, inputDPSIe_addition);
//   CLHEP::HepRotation rotation_addition(euler_addition);
//   HepGeom::Transform3D transform_addition( rotation_addition, translation_addition );
//  
//   HepGeom::Transform3D Combination = transform_addition * transform;
//   CLHEP::Hep3Vector translation_Combination = Combination.getTranslation();
//   CLHEP::HepRotation rotation_Combination = Combination.getRotation();
// 
//   
//   std::cout << "  ==> " << rotation_Combination.getPhi() << " " << rotation_Combination.getTheta() << " " << rotation_Combination.getPsi() ;
//   std::cout << " " << 100 * translation_Combination.getX() << " " << 100 * translation_Combination.getY() << " " << 100 * translation_Combination.getZ() << std::endl;
//   
  
 outFile.close(); 
 
 std::cout << std::endl << " --- end --- " << std::endl << std::endl;
}



