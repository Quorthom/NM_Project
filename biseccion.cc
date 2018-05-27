#include "biseccion.h"

biseccion::biseccion(){
  N_iter    = 0;
  Nmax_iter = 0;
  err       = 0;
}

biseccion::biseccion( double iteraciones, double error ){
  N_iter    = 0           ;
  Nmax_iter = iteraciones ;
  err       = error       ;
}

//metodo
bool biseccion::DoBiseccion(parametros &p, Function f){

  while (N_iter < Nmax_iter){
    p.getxm();

    p.fxi() = f.eval( p.xi() );
    p.fxs() = f.eval( p.xs() );
    p.fxm() = f.eval( p.xm() );

    //checking
    if ( fabs( p.fxm() ) < err ) return true;
    if ( p.fxi() * p.fxs() > 0 ) return false;

    if( p.fxm() * p.fxs() < 0 ){
      p.xi() = p.xm();
      p.fxi() = p.fxm();
    }
    else{
      p.xs() = p.xm();
      p.fxs() = p.fxm();
    }

    N_iter += 1;
  }
  return false;

}

//metodomonitoreado
bool biseccion::ShowBiseccion(parametros &p, Function f){

  while (N_iter < Nmax_iter){
    p.getxm();

    //monitoreo numerico
    std::cout << "xi = " << p.xi()  << std::endl;
    std::cout << "xs = " << p.xs()  << std::endl;
    std::cout << "xm = " << p.xm()  << std::endl;

    p.fxi() = f.eval( p.xi() );
    p.fxs() = f.eval( p.xs() );
    p.fxm() = f.eval( p.xm() );

    std::cout << "fxi = " << p.fxi() << std::endl;
    std::cout << "fxs = " << p.fxs() << std::endl;
    std::cout << "fxm = " << p.fxm()  << std::endl;

    //checking
    if ( fabs( p.fxm() ) < err ) return true;
    if ( p.fxi() * p.fxs() > 0 ) return false;

    if( p.fxm() * p.fxs() < 0 ){
      p.xi() = p.xm();
      p.fxi() = p.fxm();
    }
    else{
      p.xs() = p.xm();
      p.fxs() = p.fxm();
    }

    std::cout << std::endl;

    N_iter += 1;
  }
  return false;
}

//resultado
void biseccion::displayR(parametros p){
  std::cout << "la raiz de la ecuacion es: " << p.xm() << "." << std::endl;
  std::cout << "con un error menor a : " << err << "." << std::endl;
}
