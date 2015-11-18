#ifndef VENTANA_HPP
#define VENTANA_HPP
#include "aux.hpp"
#include "Cabeza.hpp"
#include "BrazoIzquierdo.hpp"
#include "BrazoDerecho.hpp"
#include "PiernaDerecha.hpp"
#include "PiernaIzquierda.hpp"


#include "NodoGrafoEscena.hpp"

class Ventana : public NodoGrafoEscena {
  public:
    Ventana(int n);
    void Mov(float k);
    void Tras(float k);
  };

#endif
