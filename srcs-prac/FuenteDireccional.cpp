#include "FUENTEDIRECCIONAL.hpp"

FuenteDireccional::FuenteDireccional(float alpha_inicial, float beta_inicial){
  posvec=Tupla4f(alpha_inicial,beta_inicial,1,0); //luz direccional w=0 z=1  REVISAR;
  colores[0]= Tupla4f(0.3,0.3,0.3,1.0);
  colores[1]= Tupla4f(0.3,0.3,0.3,1.0);
  colores[2]= Tupla4f(0.3,0.3,0.3,1.0);
}
void FuenteDireccional::variarAngulo( unsigned angulo, float incremento ){
  if(angulo==0)
    posvec=posvec+Tupla4f(incremento,0,0,0);
  else
    posvec=posvec-Tupla4f(incremento,0,0,0);
}

/*
void FuenteDireccional::variarAngulo( unsigned angulo, float incremento ){
  const float ejeZ[4] = { 0.0, 0.0, 1.0, 0.0 } ;

  switch (angulo) {
    case 0:
      longi=longi+incremento;
      while (longi>360){
        longi=longi-360;
      }
      while (longi<0){
        longi=360-longi;
      }
      glMatrixMode( GL_MODELVIEW ) ;
      glPushMatrix() ;
      glRotatef( longi, 0.0, 1.0, 0.0 ) ; // (2) rotación β grados en torno al eje X-
      glLightfv( GL_LIGHT1, GL_POSITION, ejeZ );
      glPopMatrix();
    break;
    case 1:
      lati=lati+incremento;
      while (lati>360){
        lati=lati-360;
      }
      while (lati<0){
        lati=360-lati;
      }
      glMatrixMode( GL_MODELVIEW ) ;
      glPushMatrix() ;
      glRotatef( lati, -1.0, 0.0, 0.0 ) ; // (1) hacer li := (0, 0, 1) (paralela eje Z+)
      glLightfv( GL_LIGHT1, GL_POSITION, ejeZ );
      glPopMatrix();
    break;
    default:
      cerr<<"angulo elegido incorrecto"<<endl;
      break;
  }
}
*/
