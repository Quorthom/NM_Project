#include<iostream>
#include<cmath>
#include"biseccion_shida.h"
#include"function.h"
#include"biseccion.h"

int main (){
  int it, mit;
  it = 0;
  mit = 100;

  double data [] = {-12, -13, 0, 1};
  std::vector<double> v (data, data + sizeof(data) / sizeof(double) ) ;

  Function f(4, v);

  parametros p;

  biseccion b(2, 5, 100, 0.125);
  b.ShowBiseccion(p, f);

  /*p.xi() = 2;
  p.xs() = 5;
  p.getxm();
  double h = p.xm();
  std::cout << h << std::endl;*/


  /*while (it < mit){
    p.getxm();
    p.fxm() = f.eval( p.xm() );
    std::cout <<"fxm= "<< p.fxm()  << std::endl;
    if ( fabs( p.fxm() ) < 0.125 ) break;

    p.fxi() = f.eval( p.xi() );
    std::cout <<"fxi = "<< p.fxi() << std::endl;
    p.fxs() = f.eval( p.xs() );
    std::cout <<"fxs = "<< p.fxs() << std::endl;

    if ( p.fxi() * p.fxs() > 0 ) break;

    if( p.fxm() * p.fxs() < 0 ){
      p.xi() = p.xm();
      p.fxi() = p.fxm();
    }
    else{
      p.xs() = p.xm();
      p.fxs() = p.fxm();
    }

    std::cout << std::endl;

    it += 1;
  }
*/
  /*if(p.biseccion(p, f, 2, 5)){
    std::cout << "el res = " << p.xm() << std::endl;
    std::cout << "it = " << it << std::endl;
  }
  */
  std::cout <<"xm = "<< p.xm() << std::endl;


  return 0;
}
/*std::cout << "The contents of fifth are:";
for (std::vector<double>::iterator it = v.begin(); it != v.end(); ++it)
  std::cout << ' ' << *it;
std::cout << '\n';*/
