#include "MaterialEstandar.hpp"
#include "Textura.hpp"

#ifndef MATP4_HPP
#define MATP4_HPP

class MaterialMadera : public MaterialEstandar{
public:
  MaterialMadera();
};

class MaterialBlanco : public MaterialEstandar{
public:
  MaterialBlanco();
};
class MaterialNegro : public MaterialEstandar{
public:
  MaterialNegro();
};
class MaterialLataPcuerpo : public MaterialEstandar{
public:
  MaterialLataPcuerpo();
};
class MaterialTapasLata : public MaterialEstandar
{
  public:
    MaterialTapasLata() ;
};
#endif;
