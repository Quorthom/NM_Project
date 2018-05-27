#ifndef _PARAMETERS_H_
#define _PARAMETERS_H_
#include <iostream>
#include <cmath>
#include "function.h"

class parametros {
private:
  //variables
  double m_xi;
  double m_xs;
  double m_xm;
  double m_xf;
  std::vector<double> m_xr;

  //funciones
  double m_fxi;
  double m_fxs;
  double m_fxm;
  double m_fxf;
  std::vector<double> m_fxr;

public:
  //constructor
  parametros();

  //accessors
  const double& xi() const;
  const double& xs() const;
  const double& xm() const;
  const double& xf() const;
  const double& xr() const;

  const double& fxi() const;
  const double& fxs() const;
  const double& fxm() const;
  const double& fxf() const;
  const double& fxr() const;

  //mutators
  double& xi();
  double& xs();
  double& xm();
  double& xf();
  double& xr();

  double& fxi();
  double& fxs();
  double& fxm();
  double& fxf();
  double& fxr();

  void getxm();

  void getxf();

  void getxr();



  //destructor
  ~parametros() { };
};

#endif
