#include "Arma.hpp"

Arma::Arma(){
  cambiarColor(2);
  agregar (MAT_Traslacion(0,-0.5,0));
  agregar (MAT_Escalado(1,1,1));
  agregar (MAT_Rotacion(0,0,1,1));
  agregar(new MallaPLY("/Users/jopime/GitHub/InformaticaGrafica/plys/Arma.ply"));

}

void Arma::Girar(float k){
  *entradas[0].matriz= MAT_Traslacion(k/100,0,0);
  *entradas[1].matriz= MAT_Escalado(1/k,1/k,1/k);
  *entradas[2].matriz= MAT_Rotacion(k,0,1,1);
}
void Arma::Agrandar(int k){
  *entradas[1].matriz= MAT_Escalado(k,k,k);
}
