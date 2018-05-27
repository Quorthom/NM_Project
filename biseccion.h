#ifndef _BISECCION_H_
#define _BISECCION_H_

#include "function.h"
#include "parameters.h"
#include <cmath>
#include <iostream>

class biseccion{
public:
  biseccion();
  biseccion(double iteraciones, double error );

  //metodo
  bool DoBiseccion(parametros &p, Function f);

  //metodomonitoreado
  bool ShowBiseccion(parametros &p, Function f);

  //resultado
  void displayR(parametros p);

  ~biseccion() {  };

private:
  int N_iter;
  int Nmax_iter;
  double err;
};


#endif
