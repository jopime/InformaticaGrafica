#ifndef MATERIALESTANDAR_HPP
  #define MATERIALESTANDAR_HPP
  #include <iostream>
  #include <string>
  #include "tuplasg.hpp"
#include "textura.hpp"
#include "material.hpp"
  using namespace std ;

  class MaterialEstandar  : public Material
  {
    public:
     Textura * text=NULL ;        // puntero a la textura (NULL si no hay)
     Tupla4f   color[4] ;    // colores: 0=emisión, 1=ambiental, 2=difuso, 3=especular
     float     exponente ;   // exponente para la componente pseudo-especular

     virtual void activar(  );// activa material en el cauce fijo
                              //   si tiene textura: activa uso de la textura 'text'
                              //   si no tiene textura: desactiva uso de texturas
    bool hayTextura();
  } ;

#endif
