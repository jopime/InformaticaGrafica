#ifndef VENTANA_HPP
#define VENTANA_HPP
#include "aux.hpp"
#include "Cabeza.hpp"
#include "BrazoIzquierdo.hpp"
#include "BrazoDerecho.hpp"
#include "PiernaDerecha.hpp"
#include "PiernaIzquierda.hpp"
#include "Detalles.hpp"
#include "Matp4.hpp"
#include "ColeccionFL.hpp"
#include "FuenteDireccional.hpp"
#include "FuentePosicional.hpp"

#include "NodoGrafoEscena.hpp"

class Ventana : public NodoGrafoEscena {
  public:
    Ventana(int n);
    Ventana();
    void Desplazarse(float k);
    void Girar(int k);
    void Agrandar(float k);


    void Mov(float k);
    void Lanzar(float k);
  };

#endif
