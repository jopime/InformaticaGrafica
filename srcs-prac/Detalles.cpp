#include "Detalles.hpp"

Detalles::Detalles(){
  cambiarColor(2);
  agregar(new MallaPLY("/Users/jopime/GitHub/InformaticaGrafica/plys/Logo.ply"));
  agregar(MAT_Rotacion(0,1,0,0));
  agregar(MAT_Traslacion(0,0,0));
  agregar(new MallaPLY("/Users/jopime/GitHub/InformaticaGrafica/plys/Arma.ply"));
}

void Detalles::Girar(float k){
  *entradas[1].matriz= MAT_Rotacion(-k,0,1,0);
  *entradas[2].matriz= MAT_Traslacion(-1,0,0);

}
