#include "Arma.hpp"

Arma::Arma(){
  cambiarColor(2);
  agregar (MAT_Traslacion(0,-0.5,0));
  agregar(new MallaPLY("./Arma.ply"));

}
