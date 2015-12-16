#ifndef FUENTEDIRECCIONAL_HPP
  #define FUENTEDIRECCIONAL_HPP
  #include <iostream>
  #include <string>
  #include <vector>
  #include "FUENTELUZ.hpp"


  class FuenteDireccional : public FuenteLuz
  {
    public:
      FuenteDireccional( float alpha_inicial, float beta_inicial ) ;
      void variarAngulo( unsigned angulo, float incremento ) ;  // angulo=0 --> variar alpha, angulo=1 --> variar beta
  };
#endif
