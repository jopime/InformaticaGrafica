#include "BrazoDerecho.hpp"
#include "manoDerecha.hpp"

BrazoDerecho::BrazoDerecho(){
  cambiarColor(1);
  agregar (new ManoDerecha());
  agregar (MAT_Traslacion(0,1.5,0));
  agregar (MAT_Rotacion(0,1,0,0));
  agregar(new MallaPLY("/Users/jopime/GitHub/InformaticaGrafica/plys/brazoDerecho.ply"));

}

void BrazoDerecho::Girar(float k){
  *entradas[2].matriz= MAT_Rotacion(k,1,0,0);
  ((ManoDerecha *)(entradas[0].objeto))->Girar(k);

}
