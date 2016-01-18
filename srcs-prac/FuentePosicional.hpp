#ifndef FUENTEPOSICIONAL_HPP
  #define FUENTEPOSICIONAL_HPP
  #include <iostream>
  #include <string>
  #include <vector>
  #include "FUENTELUZ.hpp"

  using namespace std ;

class FuentePosicional : public FuenteLuz
{
  public:
    FuentePosicional( const Tupla3f & posicion ) ;
};
#endif
