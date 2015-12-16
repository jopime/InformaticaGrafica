#include "FUENTEDIRECCIONAL.hpp"

FuenteDireccional::FuenteDireccional(float alpha_inicial, float beta_inicial){
  posvec=Tupla4f(alpha_inicial,beta_inicial,1,0); //luz direccional w=0 z=1  REVISAR;
  longi=alpha_inicial;
  lati=beta_inicial;
}

void FuenteDireccional::variarAngulo( unsigned angulo, float incremento ){
  switch (angulo) {
    case 0:
      longi=longi+incremento;
      while (longi>360){
        longi=longi-360;
      }
      while (longi<0){
        longi=360-longi;
      }
    break;
    case 1:
      lati=lati+incremento;
      while (lati>360){
        lati=lati-360;
      }
      while (lati<0){
        lati=360-lati;
      }
    break;
    default:
      cerr<<"angulo elegido incorrecto"<<endl;
      break;
  }
}
