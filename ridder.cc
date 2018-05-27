#include "ridder.h"
ridder(){
  N_iter    = 0;
  Nmax_iter = 0;
  err       = 0;
}

ridder(double iteraciones, double error){
  N_iter    = 0           ;
  Nmax_iter = iteraciones ;
  err       = error       ;
}

bool doridder(parametros &p, Function f){
  while( N_iter < Nmax_iter ){
    p.fxi() = f.eval( p.xi() );
    p.fxs() = f.eval( p.xs() );

    p.getxm();
    p.fxm() = f.eval( p.xm() );

    p.getxr();

    p.fxr()

    //checking
    if ( abs(p.xr[0]) < abs(p.xr[1]) )

  }
}
bool showridder(parametros &p, Function f);
