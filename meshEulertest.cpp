#include"meshEuler.hpp"
#include"Euler.hpp"
#include<vector>
#include<fstream>
#include<iostream>

//Reflective boundary function
Euler::W_state Refl_Left_Bound(Mesh &m){
 
  Euler::W_state w_left_end = Mesh::ptr_euler-> PfromC(m.data[0]);
  
  Euler::W_state w_result;
  
  w_result.rho =   w_left_end.rho;
  w_result.u   = - w_left_end.u;
  w_result.P   =   w_left_end.P;

  return w_result;
}

//Transmissive boundary function

//Initial condition function

//Exact riemann solver function

int main(){

  //Initialise mesh with reflective BC

  //Print mesh to file

  //Apply BC() function

  //Print nGhost cells to check reflective BC

  //Initialise mesh with transmissive BC

  //Apply BC()
  
  //Print nGhost cells to check reflective BC

  //Calculate dt

  //Print dt



}
