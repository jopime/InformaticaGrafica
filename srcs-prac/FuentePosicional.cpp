#include "FUENTEPOSICIONAL.hpp"

FuentePosicional::FuentePosicional(const Tupla3f & posicion){
  posvec=Tupla4f(posicion[0],posicion[1],posicion[2],1); //luz posicional w=1;
  colores[0]= Tupla4f(0.3,0.3,0.3,1.0);
  colores[1]= Tupla4f(0.3,0.3,0.3,1.0);
  colores[2]= Tupla4f(0.3,0.3,0.3,1.0);
}
