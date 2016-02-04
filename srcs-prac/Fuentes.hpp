#include "FuenteLuz.hpp"
#include "ColeccionFl.hpp"

#ifndef FUENTES_HPP
#define FUENTES_HPP

class FuenteDireccional : public FuenteLuz
{
  public:
    FuenteDireccional( float alpha_inicial, float beta_inicial ) ;
    void variarAngulo( unsigned angulo, float incremento ) ;  // angulo=0 --> variar alpha, angulo=1 --> variar beta
};
class FuentePosicional : public FuenteLuz
{
  public:
    FuentePosicional( const Tupla3f & posicion ) ;
};
class ColeccionFuentesP4 : public ColeccionFL
{
  public:
    ColeccionFuentesP4() ;
};

#endif
