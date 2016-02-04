#include "Tuplasg.hpp"
#include "aux.hpp"

#ifndef FUENTELUZ_HPP
#define FUENTELUZ_HPP

class FuenteLuz
{
 public:
   Tupla4f  posvec ;       // posición (si w=1) o vector (w=0)
   Tupla4f  colores[3] ;   // colores: 0=ambiental, 1=difuso, 2=especular.
   float    lng,lat;      // ángulos de rotación (fuente direccional modificable interactivamente)

   void activar( int i ) ; // activa la fuente de luz (con número GL_LIGHT0+i)
} ;

#endif
