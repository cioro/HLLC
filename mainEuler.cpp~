#include "mesh.hpp"
#include <vector>
#include <cstdio>
#include <fstream>
#include <cmath>
#include <string>

double PI = std::atan(1.0) * 4.0;

 W_state initial_f(double x)
{
   double u = sin(2*PI*x);
   return W_state(u);
}

  //Boundary condition function
void b1(Mesh &m)
{
//Do I set the first cell to the last in ncells or the ghost cell?
  m.data[0]= m.data[m.ncells];
 
}

void b2(Mesh &m)
{
  m.data[m.ncells+m.nGhost]=m.data[m.nGhost];
}

W_state exact(double y)//note here y = x-a*t when used;
{
  double u = sin(2*PI*y);
  return W_state(u);
}

int main()
{

  //Declare parameters of the problem
  int ncells = 100;
  double x_min = -1.0;
  double x_max = 1.0;
  int nGhost = 1;
  double speed = 0.5;
  
  std::string filename = "solution.dat";
  
  Mesh m(ncells,x_min,x_max,initial_f, b1, b2, nGhost);
  m.print();
  m.save(filename,exact,speed);

  return 0;

}

  
  


