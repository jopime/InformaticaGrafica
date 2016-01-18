#include "MaterialPeonNegro.hpp"

MaterialPeonNegro::MaterialPeonNegro()
{
  this=new MaterialEstandar(Tupla4f(0.0, 0.0, 0.0, 1.0),Tupla4f(0.02, 0.02, 0.02, 1.0),Tupla4f(0.0, 0.0, 0.0, 1.0),Tupla4f(1.0, 1.0, 1.0, 1.0),3.0);
}
