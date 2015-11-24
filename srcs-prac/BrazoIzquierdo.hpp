#ifndef BRAZOIZQUIERDO_HPP
#define BRAZOIZQUIERDO_HPP
#include "aux.hpp"
#include "NodoGrafoEscena.hpp"

class BrazoIzquierdo : public NodoGrafoEscena {
  public:
    BrazoIzquierdo();
    void Girar(float k);
    void Tirar(float k);
  };

#endif
