#include "BrazoDerecho.hpp"

BrazoDerecho::BrazoDerecho(){
  agregar (MAT_Rotacion(0,1,4,0));
  agregar(new MallaPLY("/Users/jopime/GitHub/InformaticaGrafica/plys/brazoDerecho.ply"));
}

void BrazoDerecho::Girar(float k){
  *entradas[0].matriz= MAT_Rotacion(k,1,4,0);
}
