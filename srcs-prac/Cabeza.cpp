#include "Cabeza.hpp"

Cabeza::Cabeza(){
  cambiarColor(4);
  agregar (MAT_Rotacion(0,0,1,0));
  agregar(new MallaPLY("/Users/jopime/GitHub/InformaticaGrafica/plys/cabezaBatman.ply"));
  agregar(new Mascara());

}

void Cabeza::Girar(float k){
  *entradas[0].matriz= MAT_Rotacion(k,0,1,0);
}
