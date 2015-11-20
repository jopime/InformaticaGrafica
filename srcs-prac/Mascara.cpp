#include "Mascara.hpp"

Mascara::Mascara(){
  cambiarColor(0);
  agregar (MAT_Rotacion(0,0,1,0));
  agregar(new MallaPLY("/Users/jopime/GitHub/InformaticaGrafica/plys/Mascara.ply"));
}

void Mascara::Girar(float k){
  *entradas[0].matriz= MAT_Rotacion(k,0,1,0);
}
