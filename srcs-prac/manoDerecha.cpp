#include "manoDerecha.hpp"

ManoDerecha::ManoDerecha(){
  cambiarColor(0);
  agregar (MAT_Traslacion(0,1.5,0));
  agregar (MAT_Rotacion(0,1,0,0));

  agregar(new MallaPLY("/Users/jopime/GitHub/InformaticaGrafica/plys/manoDerecha.ply"));
}

void ManoDerecha::Girar(float k){
  *entradas[1].matriz= MAT_Rotacion(k,1,0,0);
}
