#ifndef DETALLES
#define DETALLES_HPP
#include "aux.hpp"
#include "NodoGrafoEscena.hpp"

class Detalles : public NodoGrafoEscena {
  public:
    Detalles();
    void Girar(float k);
  };

#endif
