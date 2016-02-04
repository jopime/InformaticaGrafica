#ifndef PIERNADERECHA_HPP
#define PIERNADERECHA_HPP
#include "aux.hpp"
#include "NodoGrafoEscena.hpp"

class PiernaDerecha : public NodoGrafoEscena {
  public:
    PiernaDerecha();
    void Girar(float k);
  };

#endif
