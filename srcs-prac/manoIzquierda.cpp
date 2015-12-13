#include "manoIzquierda.hpp"

ManoIzquierda::ManoIzquierda(){
  cambiarColor(0);
  agregar(new MallaPLY("/Users/jopime/GitHub/InformaticaGrafica/plys/manoIzquierda.ply"));
  agregar(new Arma());
}
