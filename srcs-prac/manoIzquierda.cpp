#include "manoIzquierda.hpp"

ManoIzquierda::ManoIzquierda(){
  cambiarColor(0);

  agregar(new Arma());
  agregar(new MallaPLY("/Users/jopime/GitHub/InformaticaGrafica/plys/manoIzquierda.ply"));
}

void ManoIzquierda::Tirar(float k){
  ((Arma *)(entradas[0].objeto))->Girar(k);
}
void ManoIzquierda::Agrandar(int k){
  ((Arma *)(entradas[0].objeto))->Agrandar(k);
}
