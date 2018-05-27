#ifndef _FUNCTION_H_
#define _FUNCTION_H_

#include<cmath>
#include<vector>

class Function {
private:
  std::vector<double> x;
  std::vector<double> a;

  int order;

public:
  //constructor
  Function();
  Function(int o, std::vector<double> data);
  Function(std::vector<double> data);

  //mutators
  double eval(double n);

  //accessors

  //destructor
  ~Function();


};

#endif
