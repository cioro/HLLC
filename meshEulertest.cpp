#include"meshEuler.hpp"
#include"Euler.hpp"
#include<vector>
#include<fstream>
#include<iostream>
#include<assert.h>

//Reflective boundary function
Euler::W_state Refl_Left_Bound(Mesh &m){
 
  Euler::W_state w_left_end = m.ptr_euler-> PfromC(m.data[0]);
  
  Euler::W_state w_result;
  
  w_result.rho =   w_left_end.rho;
  w_result.u   = - w_left_end.u;
  w_result.P   =   w_left_end.P;

  return w_result;
}

Euler::W_state Refl_Right_Bound(Mesh &m){
 
  Euler::W_state w_right_end = m.ptr_euler-> PfromC(m.data[m.ncells]);
  
  Euler::W_state w_result;
  
  w_result.rho =   w_right_end.rho;
  w_result.u   = - w_right_end.u;
  w_result.P   =   w_right_end.P;

  return w_result;
}

//Transmissive boundary function
Euler::W_state Trans_Left_Bound(Mesh &m){
 
  Euler::W_state w_left_end = m.ptr_euler-> PfromC(m.data[0]);
  
  Euler::W_state w_result;
  
  w_result.rho =  w_left_end.rho;
  w_result.u   =  w_left_end.u;
  w_result.P   =  w_left_end.P;

  return w_result;
}


Euler::W_state Trans_Right_Bound(Mesh &m){
 
  Euler::W_state w_right_end = m.ptr_euler-> PfromC(m.data[m.ncells]);
  
  Euler::W_state w_result;
  
  w_result.rho =   w_right_end.rho;
  w_result.u   =   w_right_end.u;
  w_result.P   =   w_right_end.P;

  return w_result;
}
//Initial condition function

Euler::U_state initial(double x){

  double x_0 = 0.2;
  //Should do this assert(x_0 < x_max && x_0 > x_min); to avoid errors
  //but I would have to add to more args to the fcn.

  if (x<x_0){
    
    Euler::U_state uL(1.0,0.75,1.0);
    return uL;
  }
  if (x>x_0){
    Euler::U_state uR(0.125,0.0,0.1);
    return uR;
  }
  else{
    std::cout<<"Something went wrong inside inital function in main.cpp"<<std::endl;
    Euler::U_state u;
    return u;
  }
}


//Exact riemann solver function

Euler::U_state Exact_solver(double x){

  Euler::U_state u_empty;

  return u_empty;
}


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
