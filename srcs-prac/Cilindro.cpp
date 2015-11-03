#include "Cilindro.hpp"
Cilindro::Cilindro(unsigned n){
  //DEFINIDO PARA N>3
  nombre_obj="Cilindro";
//Agrego coordenadas
  for (int i=0;i<n;i++){
    stlVertices.push_back(Tupla3f(cos(2*i*M_PI/n),-1,sin(2*i*M_PI/n)));
  }
    for (int i=0;i<n;i++){
  stlVertices.push_back(Tupla3f(cos(2*i*M_PI/n),1,sin(2*i*M_PI/n)));
}
  stlVertices.push_back(Tupla3f(0,-1,0));
  stlVertices.push_back(Tupla3f(0,1,0));

//Asigno Indices
  for (int i=0;i<n-1;i++){
    stlCaras.push_back(Tupla3i(i,n+i,i+1));
  }
  stlCaras.push_back(Tupla3i(n-1,2*n-1,0));
  for (int i=0;i<n-1;i++){
    stlCaras.push_back(Tupla3i(i,2*n,i+1));
  }
  stlCaras.push_back(Tupla3i(0,n,2*n-1));
  for (int i=0;i<n-1;i++){
    stlCaras.push_back(Tupla3i(i+1,n+i,n+1+i));
  }
  stlCaras.push_back(Tupla3i(n-1,2*n,0));
  for (int i=0;i<n-1;i++){
    stlCaras.push_back(Tupla3i(n+i,2*n+1,n+1+i));
  }
  stlCaras.push_back(Tupla3i(n,2*n-1,2*n+1));

}
