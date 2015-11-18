#include "BrazoIzquierdo.hpp"

BrazoIzquierdo::BrazoIzquierdo(){
  agregar (MAT_Rotacion(0,1,0,0));
  agregar(new MallaPLY("/Users/jopime/GitHub/InformaticaGrafica/plys/brazoIzquierdo.ply"));
}

void BrazoIzquierdo::Girar(float k){
  *entradas[0].matriz= MAT_Rotacion(k,1,0,0);
}
