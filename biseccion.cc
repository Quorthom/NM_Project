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

bool biseccion (double xi, double xs,double err, std::vector<double> data, double& root){
  double xm, fxi, fxs, fxm = 0;
  int it, M_it;
  it = 0;
  M_it = 100;

  while (it < M_it){

    std::cout << "xi= "<<xi<< std::endl;
    xm = (xi+xs)/2;
    std::cout << "xm= "<<xm<< std::endl;
    std::cout << "xs= "<<xs<< std::endl;
    //evalua el polinomio para xi
    fxi = eval(xi, data);
    std::cout << "fxi= "<<fxi<< std::endl;
    //evalua el polinomio para xm
    fxm = eval(xm, data);
    std::cout << "fxm= "<<fxm<< std::endl;
    //evalua el polinomio para xs
    fxs = eval(xs, data);
    std::cout << "fxs= "<<fxs<< std::endl;


    //checking
    if ( fabs( fxm ) < err ) {
      root = xm;
      return true;
    }
    if ( fxi * fxs > 0 ) return false;

    if( fxm * fxs < 0 ){
      xi = xm;
      fxi = 0;
      fxm = 0;
      fxs = 0;
    }
    else{
      xs = xm;
      fxs = 0;
      fxm = 0;
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

  if(biseccion(xi, xs, err, data, root)){
    std::cout << "la raiz de la funcion es: " << root << "." << std::endl;
    std::cout << "con un error menor a : " << err << "." << std::endl;
  }
  else{
    std::cout << "**error** "<< std::endl;
  }
  return 0;
}
