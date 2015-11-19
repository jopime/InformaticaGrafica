#include "BrazoIzquierdo.hpp"
#include "manoIzquierda.hpp"

BrazoIzquierdo::BrazoIzquierdo(){
  cambiarColor(1);
  agregar (new ManoIzquierda());
  agregar (MAT_Traslacion(0,1.5,0));
  agregar (MAT_Rotacion(0,1,0,0));

  agregar(new MallaPLY("/Users/jopime/GitHub/InformaticaGrafica/plys/brazoIzquierdo.ply"));
}

void BrazoIzquierdo::Girar(float k){
  *entradas[2].matriz= MAT_Rotacion(k,1,0,0);
    ((ManoIzquierda *)(entradas[0].objeto))->Girar(k);
}
