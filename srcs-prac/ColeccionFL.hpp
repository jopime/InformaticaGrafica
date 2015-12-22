#ifndef COLECCIONFL_HPP
  #define COLECCIONFL_HPP
  #include <iostream>
  #include <string>
  #include <vector>
  #include "FUENTELUZ.hpp"

  using namespace std ;
  class ColeccionFL
  {
    public:
     std::vector<FuenteLuz> fuentes ;  // vector de fuentes de luz
     void activar() ;                  // activa todas las fuentes de luz en el cauce fijo
                                         //   (antes de eso activa iluminación y la configura)
  } ;

  #endif
