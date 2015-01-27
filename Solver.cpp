#include<blitz/array.h>

//euler class
class Euler {
public:
  
  //setter methods
  void set_rho(double);
  void set_u(double);
  
  //accessor methods
  
  //accessor methods for conservative variables


private:
  rho;//density
  u;//speed
  p;//pressure
}


//Initialisaation
//  Domain
//  Mesh size
//  Initial conditions=test to be solved.

//Boundary conditions

//Calculating dt

//Calculate fluxes

//Update solution -->> repeat till timeout

//Timeout -->> Print out

