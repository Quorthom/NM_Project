#include <cmath>
#include <vector>
#include <iostream>

double eval(double n, std::vector<double> data){
  std::vector<double> x (data.size(), 1);
  for (int i = 0; i < data.size(); i++) {
    x[i] = pow(n, i);
  }
  double fx = 0;
  for (int i = 0; i < data.size(); i++) {
    fx += data[i]*x[i];
  }
  return fx;
}

bool falsa_posicion(double xi, double xs,double err, std::vector<double> data, double& root){
  double xf, fxi, fxs, fxf = 0;
  int it, M_it;
  it = 0;
  M_it = 100;

  while (it < M_it){
    //evalua el polinomio para xi
    fxi = eval(xi, data);

    //evalua el polinomio para xs
    fxs = eval(xs, data);

    std::cout << "xi= "<<xi<< std::endl;
    xf = xs - ( ( fxs * ( xs - xi ) ) / ( fxs - fxi ) );
    std::cout << "xf= "<<xf<< std::endl;
    std::cout << "xs= "<<xs<< std::endl;

    std::cout << "fxi= "<<fxi<< std::endl;
    fxf = eval(xf, data);
    std::cout << "fxf= "<<fxf<< std::endl;
    std::cout << "fxs= "<<fxs<< std::endl;

    //checking
    if ( fabs( fxf ) < err ) {
      root = xf;
      return true;
    }
    if ( fxi * fxs > 0 ) return false;

    if( fxf * fxs < 0 ){
      xi = xf;
      fxi = 0;
      fxf = 0;
      fxs = 0;
    }
    else{
      xs = xf;
      fxs = 0;
      fxf = 0;
      fxs = 0;
    }
    it += 1;
    std::cout << "**********fin de it: "<<it<< std::endl;
  }
 return false;
}

int main( ) {

  double xi, xs, err;
  xi = 2;
  xs = 5;
  err = 0.125;
  double root;

  double a [] = {-12, -13, 0, 1};
  std::vector<double> data (a, a + sizeof(a) / sizeof(double) ) ;

  if(falsa_posicion(xi, xs, err, data, root)){
    std::cout << "la raiz de la funcion es: " << root << "." << std::endl;
    std::cout << "con un error menor a : " << err << "." << std::endl;
  }
  else{
    std::cout << "**error** "<< std::endl;
  }
  return 0;
}
