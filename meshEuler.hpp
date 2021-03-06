#ifndef MESH_H
#define MESH_H

#include <cstdio>
#include <vector>
#include <string>
#include "Euler.hpp"

class Mesh{
public:
  //Pointer to Euler class
  Euler * ptr_euler;
  
  //Parameters
  std::vector<double> axis;
  int ncells;

  double x_min;
  double x_max;
  double dx;
  double time;
  
  //Boundary functions
  Euler::W_state (*boundary1)(Mesh& m);
  Euler::W_state (*boundary2)(Mesh& m);
  int nGhost;

   //Data
  std::vector<Euler::U_state> data;
  std::vector<Euler::U_state> data2;

  //Constructor
  Mesh(int ncells, double x_min, double x_max, Euler::U_state (*f)(double x),Euler::W_state (*b1)(Mesh &m), Euler::W_state (*b2)(Mesh &m), int nGhost);
  ~Mesh();
  //print to screen and print to file
  void print()const;
  void save(std::string name, Euler::U_state (*exact)(double x), double speed)const;
 
  //Apply BCs
  void applyBC();
  
  //Calculate dt 

  //Mesh update
};
//HLLC method

//TVD WAF
#endif
