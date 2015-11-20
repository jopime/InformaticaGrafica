#ifndef CABEZA_HPP
#define CABEZA_HPP
#include "aux.hpp"
#include "NodoGrafoEscena.hpp"
#include "Mascara.hpp"

class Cabeza : public NodoGrafoEscena {
  public:
    Cabeza();
    void Girar(float k);
  };

#endif
