#include"Euler.hpp"
#include<iostream>

int main(){

  double w1 = 1.0  ;
  double w2 = 0.75 ;
  double w3 = 1.0;
  
  double u1 = 1.0;
  double u2 = 1.5;
  double u3 = 2.0;
    

  Euler e;
  Euler::W_state w(w1,w2,w3);
  Euler::U_state u(u1,u2,u3);
  double speed = e.a(w);
 
  w.print();
  u.print();
  std::cout << "This is the speed " << speed << "\n";
  double e_energy = e.int_energy(w);
  std::cout << "The internal energy is " << e_energy   << "\n";
  
  
  Euler::U_state fl; //avoid most vexing parse issue-not write fl() but fl.
  fl = e.flux(u);
  fl.print();

  Euler::U_state u_new;
  u_new = e.CfromP(w);
  u_new.print();
  
  Euler::W_state w_new;
  w_new = e.PfromC(u);
  w_new.print();


}
