#include "Cono.hpp"
Cono::Cono(unsigned n){
  //DEFINIDO PARA N>1
  nombre_obj="Cono";


  stlVertices.push_back(Tupla3f(0,2,0));  //Vertice punta cono pos 0
  stlVertices.push_back(Tupla3f(0,0,0));  //vertice centro base pos 1
  for (int i=2;i<n+2;i++){
    stlVertices.push_back(Tupla3f(cos(2*i*M_PI/n),0,sin(2*i*M_PI/n)));
  } // mete circunferencia base de n puntos

//meto indices de caras
  stlCaras.push_back(Tupla3i(n+1,0,2)); // cierre caras laterales
  for (int i=1;i<n;i++){
    stlCaras.push_back(Tupla3i(i+1,0,i+2)); // meto caras laterales
  }

  stlCaras.push_back(Tupla3i(n+1,1,2)); // cierre tapa inferior
  for (int i=1;i<n;i++){
    stlCaras.push_back(Tupla3i(i+1,1,i+2)); // caras tapa inferior
  }

}
