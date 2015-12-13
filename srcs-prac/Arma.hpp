#ifndef ARMA
#define ARMA_HPP
#include "aux.hpp"
#include "NodoGrafoEscena.hpp"

class Arma : public NodoGrafoEscena {
  public:
    Arma();
    void Agrandar(int k);
    void Girar(float k);
  };

#endif
