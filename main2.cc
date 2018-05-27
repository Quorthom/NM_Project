#include<iostream>
#include<cmath>
#include"parameters.h"
#include"function.h"
#include"biseccion.h"
#include"false_position.h"

int main () {
  int it, mit;
  it = 0;
  mit = 100;

  double data [] = {-12, -13, 0, 1};
  std::vector<double> v (data, data + sizeof(data) / sizeof(double) ) ;

  Function f(v);

  parametros p;

  p.xi() = 2;
  p.xs() = 5;
/*prueba de biseccion
  biseccion b(100, 0.125);
  b.ShowBiseccion(p, f);
  b.DoBiseccion(p, f);
  b.displayR(p);*/

  False_Position fp(100, 0.125);
  fp.ShowFalse_Position(p, f);


  return 0;
}
