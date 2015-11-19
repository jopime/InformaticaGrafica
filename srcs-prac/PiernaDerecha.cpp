#include "PiernaDerecha.hpp"

PiernaDerecha::PiernaDerecha(){
  cambiarColor(1);
  agregar (MAT_Traslacion(0,0.7,0));
  agregar (MAT_Rotacion(0,1,0,0));
  agregar(new MallaPLY("/Users/jopime/GitHub/InformaticaGrafica/plys/piernaDerecha.ply"));
}

void PiernaDerecha::Girar(float k){
  *entradas[1].matriz= MAT_Rotacion(-k,1,0,0);
}
