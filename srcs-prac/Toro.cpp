#include "Toro.hpp"
Toro::Toro(){
  nombre_obj="Toro";
  int n=100;
  int m=100;

  for (int i=0;i<m;i++){   //Numero de circunferencias
    for(int j=0;j<n;j++){  //Numero de puntos por circu
        stlVertices.push_back(Tupla3f(cos(2*i*M_PI/m)*(2.5+cos(2*j*M_PI/n)),
      sin(2*i*M_PI/m)*(2.5+cos(2*j*M_PI/n)),sin(2*j*M_PI/n)));
    }
}
  for(int j=0;j<m-1;j++){
    for (int i=0;i<n-1;i++){
      stlCaras.push_back(Tupla3i(i+j*n,i+1+j*n,n+i+j*n));
    }
      stlCaras.push_back(Tupla3i(n-1+j*n,0+j*n,2*n-1+j*n));
    for (int i=0;i<n-1;i++){
        stlCaras.push_back(Tupla3i(n+i+j*n,n+i+1+j*n,i+1+j*n));
      }
      stlCaras.push_back(Tupla3i(2*n-1+j*n,n+j*n,0+j*n));
    }
    for(int i=0;i<n-1;i++){
      stlCaras.push_back(Tupla3i((m-1)*n+i,i+1,(m-1)*n+i+1));
    }
    stlCaras.push_back(Tupla3i(0,n-1,stlVertices.size()-1));
    for(int i=0;i<n-1;i++){
      stlCaras.push_back(Tupla3i(i,i+1,(m-1)*n+i));
    }
    stlCaras.push_back(Tupla3i(stlVertices.size()-1,0,2));
}
