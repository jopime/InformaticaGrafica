#include "BrazoDerecho.hpp"
#include "manoDerecha.hpp"

BrazoDerecho::BrazoDerecho(){
  cambiarColor(1);
  agregar (MAT_Traslacion(0,1.5,0));
  agregar (MAT_Rotacion(0,1,0,0));
  agregar(new MallaPLY("./brazoDerecho.ply"));
  agregar (new ManoDerecha());

}

void BrazoDerecho::Girar(float k){
  *entradas[1].matriz= MAT_Rotacion(k,1,0,0);
}
