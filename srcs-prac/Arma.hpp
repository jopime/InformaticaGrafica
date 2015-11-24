#ifndef ARMA
#define ARMA_HPP
#include "aux.hpp"
#include "NodoGrafoEscena.hpp"

class Arma : public NodoGrafoEscena {
  public:
    Arma();
    void Girar(float k);
  };

#endif
