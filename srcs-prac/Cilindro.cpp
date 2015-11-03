#include "Cilindro.hpp"
Cilindro::Cilindro(unsigned n){
  //DEFINIDO PARA N>3; CILINDROS CON N PUNTOS POR BASE ()
  nombre_obj="Cilindro";
//Agrego coordenadas
  for (int i=0;i<n;i++){
    stlVertices.push_back(Tupla3f(cos(2*i*M_PI/n),-1,sin(2*i*M_PI/n)));
  } //METO EN LA POSICION 0,..,N-1 LA CIRCUNFERENCIA INFERIOR
    for (int i=0;i<n;i++){
  stlVertices.push_back(Tupla3f(cos(2*i*M_PI/n),1,sin(2*i*M_PI/n)));
} //METO EN LA POSICION N,..,2N-1 LA CIRCUNFERENCIA SUPERIOR

  stlVertices.push_back(Tupla3f(0,-1,0)); // centro base INFERIOR 2n
  stlVertices.push_back(Tupla3f(0,1,0));  //centro base SUPERIOR pos 2n+1

//Asigno Indices
  for (int i=0;i<n-1;i++){
    stlCaras.push_back(Tupla3i(i,n+i,i+1)); //dentadura inferior sin cerrar
  }

  stlCaras.push_back(Tupla3i(n-1,2*n-1,0)); //ultimo triangulo de la dentadura inferior

  for (int i=0;i<n-1;i++){
    stlCaras.push_back(Tupla3i(i,2*n,i+1)); //tapa inferior sin cierre
  }
  stlCaras.push_back(Tupla3i(0,n,2*n-1)); //primer triangulo lateral hacia arriba

  for (int i=0;i<n-1;i++){
    stlCaras.push_back(Tupla3i(i+1,n+i,n+1+i)); //dentadura superior
  }

  stlCaras.push_back(Tupla3i(n-1,2*n,0)); // cierre tapa inferior

  for (int i=0;i<n-1;i++){
    stlCaras.push_back(Tupla3i(n+i,2*n+1,n+1+i)); // tapa superior
  }
  stlCaras.push_back(Tupla3i(n,2*n-1,2*n+1));   // cierre tapa superior
}
