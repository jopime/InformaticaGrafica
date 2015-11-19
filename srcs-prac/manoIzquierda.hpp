#ifndef MANOIZQUIERDA_HPP
#define MANOIZQUIERDA_HPP
#include "aux.hpp"
#include "NodoGrafoEscena.hpp"

class ManoIzquierda : public NodoGrafoEscena {
  public:
    ManoIzquierda();
    void Girar(float k);
  };

#endif
