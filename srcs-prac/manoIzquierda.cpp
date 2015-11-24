#include "manoIzquierda.hpp"

ManoIzquierda::ManoIzquierda(){
  cambiarColor(0);
  agregar (MAT_Traslacion(0,1.5,0));
  agregar (MAT_Rotacion(0,1,0,0));
  agregar(new Arma());


  agregar(new MallaPLY("/Users/jopime/GitHub/InformaticaGrafica/plys/manoIzquierda.ply"));
}

void ManoIzquierda::Girar(float k){
  *entradas[1].matriz= MAT_Rotacion(k,1,0,0);
}
void ManoIzquierda::Tirar(float k){
  ((Arma *)(entradas[2].objeto))->Girar(k);
}
