#include "COLECCIONFUENTESP4.hpp"

ColeccionFuentesP4::ColeccionFuentesP4(){
  fuentes.push_back(FuentePosicional(Tupla3f(1,1,0)));
  fuentes.push_back(FuenteDireccional(0,0));

  activar();
}
