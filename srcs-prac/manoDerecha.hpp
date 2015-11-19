#ifndef MANODERECHA_HPP
#define MANODERECHA_HPP
#include "aux.hpp"
#include "NodoGrafoEscena.hpp"

class ManoDerecha : public NodoGrafoEscena {
  public:
    ManoDerecha();
    void Girar(float k);
  };

#endif
