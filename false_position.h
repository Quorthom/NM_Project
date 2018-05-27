#ifndef _FALSE_POSITION_H_
#define _FALSE_POSITION_H_

#include "function.h"
#include "parameters.h"
#include <cmath>
#include <iostream>

class False_Position{
public:
  False_Position();
  False_Position(double iteraciones, double error );

  bool DoFalse_Position(parametros &p, Function f);
  bool ShowFalse_Position(parametros &p, Function f);

  ~False_Position() { };

private:
  int N_iter;
  int Nmax_iter;
  double err;
};




#endif
