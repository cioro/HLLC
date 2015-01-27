#include<vector>
#include"mesh.hpp"
#include<fstream>
#include<cmath>
#include<iostream> 
#include<string>
#include<sstream>

W_state::W_state() : u(0) {}

W_state::W_state(double u) : u(u) {}

void W_state::print()const
{
  std::cout << " State u = " << u << "\n";
}

Mesh::Mesh(int ncells, double x_min, double x_max, W_state (*f)(double x), void (*b1)(Mesh &m), void (*b2)(Mesh &m), int nGhost) : ncells(ncells), x_min(x_min),x_max(x_max), time(0), boundary1(b1), boundary2(b2), nGhost(nGhost)
 { 
   dx = (x_max-x_min)/(double)ncells;
   
   data.resize(ncells + 2*nGhost);
   data2.resize(ncells + 2*nGhost);
   axis.resize(ncells + 2*nGhost);
   
   std::vector<W_state>::iterator itdata = data.begin()+nGhost;
   std::vector<W_state>::iterator itdata2= data2.begin()+nGhost;
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

   std::vector<W_state>::const_iterator itdata = data.begin()+nGhost;
   std::vector<W_state>::const_iterator itdata2= data2.begin()+nGhost;
   std::vector<double>::const_iterator itaxis= axis.begin()+nGhost;
  
   for (int i = nGhost; i<(ncells+nGhost); i++){
     std::cout << *itaxis << "\t";
     (*itdata).print();
     itaxis++;
     itdata++;
   }

}

void Mesh::save(std::string filename, W_state (*exact)(double x), double speed)const
{
  std::stringstream ss;
  ss << filename << time;
  std::string tmppath = ss.str();
  

  FILE * outfile = fopen(tmppath.c_str(),"w");
  std::vector<W_state>::const_iterator itdata= data.begin()+nGhost;
  std::vector<double>::const_iterator itaxis= axis.begin()+nGhost;
  for(int i=1; i<ncells+nGhost; i++)
    {
      fprintf(outfile, "%.4f \t %.4f \t %.4f \n", *itaxis, (*itdata).u, exact(*itaxis -speed*time).u);
      itaxis++;
      itdata++;
  }
  fclose(outfile);
}


