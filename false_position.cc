#include "false_position.h"

False_Position::False_Position(){
  N_iter    = 0;
  Nmax_iter = 0;
  err       = 0;
}
False_Position::False_Position(double iteraciones, double error){
  N_iter    = 0           ;
  Nmax_iter = iteraciones ;
  err       = error       ;
}

bool False_Position::DoFalse_Position(parametros &p, Function f){

  while( N_iter < Nmax_iter ){

    p.fxi() = f.eval( p.xi() );
    p.fxs() = f.eval( p.xs() );

    p.getxf();

    p.fxf() = f.eval( p.xf() );


    //checking
    if ( fabs( p.fxf() ) < err ) return true;
    if ( p.fxi() * p.fxs() > 0 ) return false;

    if( p.fxm() * p.fxf() < 0 ){
      p.xi() = p.xf();
      p.fxi() = p.fxf();
    }
    else{
      p.xs() = p.xf();
      p.fxs() = p.fxf();
    }
    N_iter += 1;
  }
  return false;
}

bool False_Position::ShowFalse_Position(parametros &p, Function f){
  while( N_iter < Nmax_iter ){
    std::cout << "*******Iteracion:" << N_iter <<"*******"<< std::endl;

    p.fxi() = f.eval( p.xi() );
    p.fxs() = f.eval( p.xs() );

    p.getxf();

    p.fxf() = f.eval( p.xf() );

    std::cout << "xi = " << p.xi()  << std::endl;
    std::cout << "xs = " << p.xs()  << std::endl;
    std::cout << "xf = " << p.xf()  << std::endl;

    std::cout << "fxi = " << p.fxi()  << std::endl;
    std::cout << "fxs = " << p.fxs()  << std::endl;
    std::cout << "fxf = " << p.fxf()  << std::endl;

    //checking
    if ( fabs( p.fxf() ) < err ) return true;
    if ( p.fxi() * p.fxs() > 0 ) return false;

    if( p.fxf() * p.fxs() < 0 ){
      p.xi() = p.xf();
      p.fxi() = p.fxf();
    }
    else{
      p.xs() = p.xf();
      p.fxs() = p.fxf();
    }
    N_iter += 1;
  }
  return false;
}
