#ifndef FUENTELUZ_HPP
  #define FUENTELUZ_HPP
  #include <iostream>
  #include <string>
  #include <vector>
  #include "aux.hpp"
  #include "tuplasg.hpp"

  using namespace std ;


  // ---------------------------------------------------------------------
  // Parámetros que definen una fuente de luz

  class FuenteLuz
  {
   public:
     Tupla4f  posvec ;       // posición (si w=1) o vector (w=0)
     vector<Tupla4f>  colores ;   // colores: 0=ambiental, 1=difuso, 2=especular.
     float    longi,lati;      // ángulos de rotación (fuente direccional modificable interactivamente)

     void activar( int i ) ; // activa la fuente de luz (con número GL_LIGHT0+i)
  } ;
  #endif
