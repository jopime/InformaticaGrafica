// *********************************************************************
// **
// ** Informática Gráfica, curso 2015-16
// ** Práctica 1  (implementación)
// **
// *********************************************************************

#include "aux.hpp"
#include "tuplasg.hpp"   // Tupla3f
#include "practica1.hpp"
#include "Cubo.hpp"
#include "Tetraedro.hpp"
#include <iostream>
using namespace std;
// ---------------------------------------------------------------------
// declaraciones de estructuras de datos....

Cubo micubo;
Tetraedro mitetraedro;
// ---------------------------------------------------------------------
// Función para implementar en la práctica 1 para inicialización.
// Se llama una vez al inicio, cuando ya se ha creado la ventana e
// incializado OpenGL.

void P1_Inicializar( int argc, char *argv[] )
{
  micubo.presentacion();
  mitetraedro.presentacion();
}

// ---------------------------------------------------------------------
// Función a implementar en la práctica 1  para dibujar los objetos
// modo: 0 - puntos, 1 - alambre, 2 - sólido, 3 - sólido ajedrez

void P1_DibujarObjetos( unsigned modo )
{
  if (modo>3){
    micubo.visualizar(modo%4);
    }
  else{
    mitetraedro.visualizar(modo);
  }
}
