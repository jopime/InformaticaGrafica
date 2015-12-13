#include "BrazoIzquierdo.hpp"
#include "manoIzquierda.hpp"

BrazoIzquierdo::BrazoIzquierdo(){
  cambiarColor(1);
  agregar (MAT_Traslacion(0,1.5,0));
  agregar (MAT_Rotacion(0,1,0,0));
  agregar(new MallaPLY("/Users/jopime/GitHub/InformaticaGrafica/plys/brazoIzquierdo.ply"));
  agregar (new ManoIzquierda());

}

void BrazoIzquierdo::Girar(float k){
  *entradas[1].matriz= MAT_Rotacion(k,1,0,0);
}
void BrazoIzquierdo::Tirar(float k){
    ((ManoIzquierda *)(entradas[3].objeto))->Tirar(k);
}
void BrazoIzquierdo::Agrandar(int k){
    ((ManoIzquierda *)(entradas[3].objeto))->Agrandar(k);
}
