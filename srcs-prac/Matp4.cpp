#include "Matp4.hpp"

MaterialBlanco::MaterialBlanco(){
  text=NULL;
  color[0]=Tupla4f(0.9,0.9,0.9,1.0);
  color[1]=Tupla4f(0.0,0.0,0.0,1.0);
  color[2]=Tupla4f(0.0,0.0,0.0,1.0);
  color[3]=Tupla4f(0.0,0.0,0.0,1.0);
  exponente=1;
}
MaterialMadera::MaterialMadera(){
  text = new Textura("../imgs/text-madera.jpg");
  color[0]=Tupla4f(0.5,0.5,0.5,1.0);
  color[1]=Tupla4f(0,0,0,1.0);
  color[2]=Tupla4f(0.2,0.1,0.1,1.0);
  color[3]=Tupla4f(1.0,1.0,1.0,1.0);
  exponente=70;
}
