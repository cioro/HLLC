#include<vector>
#include"meshEuler.hpp"
#include<fstream>
#include<cmath>
#include<iostream> 
#include<string>
#include<sstream>
#include"Euler.hpp"

Mesh::Mesh(int ncells, double x_min, double x_max, Euler::U_state (*f)(double x), Euler::W_state (*b1)(Mesh &m), Euler::W_state (*b2)(Mesh &m), int nGhost) : ncells(ncells), x_min(x_min),x_max(x_max), time(0), boundary1(b1), boundary2(b2), nGhost(nGhost)
 { 
   dx = (x_max-x_min)/(double)ncells;
   
   data.resize(ncells + 2*nGhost);
   data2.resize(ncells + 2*nGhost);
   axis.resize(ncells + 2*nGhost);
   
   std::vector<Euler::U_state>::iterator itdata = data.begin()+nGhost;
   std::vector<Euler::U_state>::iterator itdata2= data2.begin()+nGhost;
   std::vector<double>::iterator itaxis= axis.begin()+nGhost;
   
   for(int i = 0; i<ncells; i++){
     (*itaxis) = x_min + i*dx;
     (*itdata) = f(*itaxis);
     itaxis++;
     itdata++;
    
     }
  
 }

Mesh::~Mesh()
{
  /* delete data;
  delete axis;
  delete data2;*/
}

void Mesh::print()const
{
  
  std::vector<Euler::U_state>::const_iterator itdata = data.begin()+nGhost;
  std::vector<Euler::U_state>::const_iterator itdata2= data2.begin()+nGhost;
   std::vector<double>::const_iterator itaxis= axis.begin()+nGhost;
  
   for (int i = nGhost; i<(ncells+nGhost); i++){
     std::cout << *itaxis << "\t";
     (*itdata).print();
     itaxis++;
     itdata++;
   }
  
}

void Mesh::save(std::string filename, Euler::U_state (*exact)(double x), double speed)const
{
  
  std::stringstream ss;
  ss << filename << time;
  std::string tmppath = ss.str();
  

  FILE * outfile = fopen(tmppath.c_str(),"w");
  std::vector<Euler::U_state>::const_iterator itdata= data.begin()+nGhost;
  std::vector<double>::const_iterator itaxis= axis.begin()+nGhost;
  for(int i=1; i<ncells+nGhost; i++)
    {
      fprintf(outfile, "%.4f \t %.4f \t %.4f \t %.4f \t %.4f \t %.4f \t %.4f \n", *itaxis, (*itdata).rho,(*itdata).momentum,(*itdata).energy, exact(*itaxis -speed*time).rho,exact(*itaxis -speed*time).momentum,exact(*itaxis -speed*time).energy );
      itaxis++;
      itdata++;
  }
  fclose(outfile);
  
}


void Mesh::applyBC(){
  
  Euler::W_state w_Left_End = ptr_euler -> PfromC(data[0]);
  Euler::W_state w_BC_Left = boundary1(*this);
  data[0]= ptr_euler -> CfromP(w_BC_Left);

  Euler::W_state w_Right_End = ptr_euler -> PfromC(data[ncells+nGhost]);
  Euler::W_state w_BC_Right = boundary2(*this);
  data[0]= ptr_euler -> CfromP(w_BC_Right);
  
}
