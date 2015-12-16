#include "COLECCIONFL.hpp"

void ColeccionFL::activar(){
  glEnable(GL_LIGHTING);
  for (int i=0;i++;i<fuentes.size()){
    fuentes[i]->activar(i);
  }
}
