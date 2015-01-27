#ifndef MESH_H
#define MESH_H

#include <cstdio>
#include <vector>
#include <string>

struct W_state{
  double u;
  void print()const;
  W_state();
  W_state(double u);
};


class Mesh{
public:
  
  //Parameters
  std::vector<double> axis;
  int ncells;
  double x_min;
  double x_max;
  double dx;
  double time;
  
  //Boundary functions
  void (*boundary1)(Mesh& m);
  void (*boundary2)(Mesh& m);
  int nGhost;

   //Data
  std::vector<W_state> data;
  std::vector<W_state> data2;

  Mesh(int ncells, double x_min, double x_max, W_state (*f)(double x),void (*b1)(Mesh &m), void (*b2)(Mesh &m), int nGhost);
  ~Mesh();
  void print()const;
  void save(std::string name, W_state (*exact)(double x), double speed)const;
 

};

  //Functions to update the states using the advection equation
  void upwind(Mesh &m, double speed, double dt);
  void Lax_Friedrichs(Mesh &m, double speed, double dt);
  void Lax_Wendroff(Mesh &m, double speed, double dt);

#endif
