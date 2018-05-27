#include "function.h"

//constructor
Function::Function(){
  order = 0;
}

Function::Function(int o, std::vector<double> data){
  if (o < 0) return;
  order = o;
  x.resize(order);
  a.resize(order);

  if( data.size() != a.size() ) return;
  a = data;
}

Function::Function(std::vector<double> data){
  if ( data.size() == 0 ) return;
  order = data.size();
  x.resize(order);
  a.resize(order);

  a = data;
}

//mutators
double Function::eval(double n){
  for (int i = 0; i < order; i++) {
    x[i] = pow(n, i);
  }

  double fx = 0;
  for (int i = 0; i < order; i++) {
    fx += a[i]*x[i];
  }

  return fx;
}

//accessors

//destructor
Function::~Function(){ };
