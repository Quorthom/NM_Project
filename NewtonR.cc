#include <iostream>
#include <cmath>
//#include "Newton.h"

using namespace std;

int main(){
  float x=1;
  float funcion=pow(x,3)-x-1;
  float fprima=3*(pow(x,2))-1;
  float IT=1;
  float NR=0;
  int Raiz=1;
  int i=0;

  do{
    x=IT;
    funcion=pow(x,3)-x-1;
    fprima=3*(pow(x,2))-1;

    NR= IT - ((funcion)/(fprima));
    cout << "NR"<<i<<" "<< NR<< " IT: "<<IT<<endl;
    if(NR==IT || NR/IT<0.001)Raiz=0;
    IT=NR;
    i++;
  }while(Raiz);

  return 0;
}
