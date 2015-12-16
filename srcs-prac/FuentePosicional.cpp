#include "FUENTEPOSICIONAL.hpp"

FuentePosicional::FuentePosicional(const Tupla3f & posicion){
  posvec=Tupla4f(posicion(0),posicion(1),posicion(2),1); //luz posicional w=1;

}
