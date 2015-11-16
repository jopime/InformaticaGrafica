#include "Ventana.hpp"

Ventana::Ventana(int n){
  int j=n;
  agregar (new Cubo());
  glPushMatrix();
    agregar (MAT_Traslacion(0,3,0));
    agregar (MAT_Escalado(1,1,0.2));
    agregar (new Cubo());
  glPopMatrix();
  agregar (MAT_Traslacion(-20,j,0));
  cerr<<endl<<"LLEGUE"<<endl;
  if(j!=2)
  agregar (new Ventana(2));
}
