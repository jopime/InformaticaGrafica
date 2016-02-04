#include "manoDerecha.hpp"

ManoDerecha::ManoDerecha(){
  cambiarColor(0);
  agregar(new MallaPLY("./manoDerecha.ply"));
}
