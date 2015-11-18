#include "PiernaIzquierda.hpp"

PiernaIzquierda::PiernaIzquierda(){
  agregar (MAT_Rotacion(0,1,4,0));
  agregar(new MallaPLY("/Users/jopime/GitHub/InformaticaGrafica/plys/piernaIzquierda.ply"));
}

void PiernaIzquierda::Girar(float k){
  *entradas[0].matriz= MAT_Rotacion(k,1,4,0);
}
