#include "manoIzquierda.hpp"

ManoIzquierda::ManoIzquierda(){
  cambiarColor(0);
  agregar(new MallaPLY("./manoIzquierda.ply"));
  agregar(new Arma());
}
