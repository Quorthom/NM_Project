#ifndef RIDDER_H_
#define RIDDER_H_

class Ridder {
public:
  ridder();
  ridder(double iteraciones, double error);

  bool doridder(parametros &p, Function f);
  bool showridder(parametros &p, Function f);

  ~ridder(){ };

private:
  int N_iter;
  int Nmax_iter;
  double err;
};

#endif
