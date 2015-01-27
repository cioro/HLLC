#ifndef EULER_H
#define EULER_H


class Euler{

public:
  //Data members
  double gamma = 1.4;
  
  struct W_state{
    double rho;
    double u;
    double P;
    W_state();
    W_state(double rho, double u, double P);
    void print()const; 
 };
  
  struct U_state{
    double rho;
    double momentum;
    double energy;
    U_state();
    U_state(double rho, double momentum, double energy);
    void print()const;  
};

  //Constructors; 
  Euler();

  //Do not think I need explicit constructors other than the empty one;
 // Euler(W_state& w);
 // Euler(U_state& u);

  //Member functions
  double a();//Calculate speed of sound a=sqrt(gamma*P/rho);
  // double a(U_state& u); //could not find formula to calculate speed of sound from conserved var
  double a(W_state& w);

  double int_energy(W_state& w);
  
  U_state flux(U_state& u);
  
  U_state CfromP(W_state& w);
  W_state PfromC(U_state& u);

  
};

#endif
