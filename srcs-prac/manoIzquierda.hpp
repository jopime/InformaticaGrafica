#ifndef MANOIZQUIERDA_HPP
#define MANOIZQUIERDA_HPP
#include "aux.hpp"
#include "NodoGrafoEscena.hpp"
#include "Arma.hpp"
class ManoIzquierda : public NodoGrafoEscena {
  public:
    ManoIzquierda();
    void Girar(float k);
    void Tirar(float k);
  };

#endif
