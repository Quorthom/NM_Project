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

bool Ridder(double xi, double xs,double err, std::vector<double> data, double& root){
  double xm, xr, fxi, fxs, fxm, fxr;
  int it, M_it;
  it = 0;
  M_it = 10;
  while (it < M_it){
    std::cout << "xi= "<<xi<< std::endl;
    xm = (xi+xs)/2;
    std::cout << "xm= "<<xm<< std::endl;
    std::cout << "xs= "<<xs<< std::endl;

    fxi = eval(xi, data);
    std::cout << "fxi= "<<fxi<< std::endl;
    fxm = eval(xm, data);
    std::cout << "fxm= "<<fxm<< std::endl;
    fxs = eval(xs, data);
    std::cout << "fxs= "<<fxs<< std::endl;

    //se obtiene xr con matrices
    double a[3];
    a[0] = -( fxi*xm*xs )/( (xi*xm) + (xi*xs) - (xm*xs) - (xi*xi) ) - ( fxm*xi*xs )/( xi*xm - xi*xs + xm*xs - xm*xm ) + ( fxs*xi*xm )/( xi*xm - xi*xs - xm*xs + xs*xs );
    a[1] = ( fxi*(xm+xs) )/( xi*xm + xi*xs - xm*xs - xi*xi ) + ( fxm*(xi+xs) )/( xi*xm - xi*xs + xm*xs - xm*xm ) - ( fxs*(xi+xm) )/( xi*xm - xi*xs - xm*xs + xs*xs );
    a[2] = -(fxi)/( xi*xm + xi*xs - xm*xs - xi*xi ) - (fxm)/( xi*xm - xi*xs + xm*xs - xm*xm ) + (fxs)/( xi*xm - xi*xs - xm*xs + xs*xs );
    std::cout << "a[0]= "<<a[0]<< std::endl;
    std::cout << "a[1]= "<<a[1]<< std::endl;
    std::cout << "a[2]= "<<a[2]<< std::endl;
    double m_xr[2];
    m_xr[0] = ( (-a[1]) + sqrt( (a[1]*a[1]) - (4*a[0]*a[2]) )) / (2*a[2]);
    m_xr[1] = ( (-a[1]) - sqrt( (a[1]*a[1]) - (4*a[0]*a[2]) )) / (2*a[2]);

    std::cout << "xr1= "<<m_xr[0]<< std::endl;
    std::cout << "xr2= "<<m_xr[1]<< std::endl;

    //checking
    double m_fxr[2];
    m_fxr[0] = eval(m_xr[0], data);
    std::cout << "fxr1= "<<m_fxr[0]<< std::endl;
    m_fxr[1] = eval(m_xr[1], data);
    std::cout << "fxr2= "<<m_fxr[1]<< std::endl;

    if( fabs( m_fxr[0] ) < fabs( m_fxr[1] ) ) xr = m_xr[0];
    else xr = m_xr[1];
    std::cout << "xr= "<<xr<< std::endl;

    fxr = eval(xr, data);
    std::cout << "fxr= "<<fxr<< std::endl;

    if ( fabs( fxr ) < err ) {
      root = xr;
      return true;
    }

    if ( fxi * fxs > 0 ) return false;

    if( fabs( fxm ) < fabs( fxr ) ){
      if( fxm * fxs < 0 ){
        xi = xm;
        fxi = 0;
        fxm = 0;
        fxs = 0;
        fxr = 0;
      }
      else{
        xs = xm;
        fxs = 0;
        fxm = 0;
        fxs = 0;
        fxr = 0;
      }
    }
    else{
      if( fxr * fxs < 0 ){
        xi = xr;
        fxi = 0;
        fxm = 0;
        fxs = 0;
        fxr = 0;
      }
      else{
        xs = xr;
        fxs = 0;
        fxm = 0;
        fxs = 0;
        fxr = 0;
      }
    }

    it += 1;
    std::cout << "**********fin de it: "<<it<< std::endl;
  }
  return false;
}

int main (){
  double xi, xs, err;
  xi = 2;
  xs = 5;
  err = 0.125;
  double root;

  double a [] = {-12, -13, 0, 1};
  std::vector<double> data (a, a + sizeof(a) / sizeof(double) ) ;

  if(Ridder(xi, xs, err, data, root)){
    std::cout << "la raiz de la funcion es: " << root << "." << std::endl;
    std::cout << "con un error menor a : " << err << "." << std::endl;
  }
  else{
    std::cout << "**error** "<< std::endl;
  }
  return 0;

}
