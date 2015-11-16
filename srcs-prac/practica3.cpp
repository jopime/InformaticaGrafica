#include "practica3.hpp"

static Ventana *miVentana=NULL;

void P3_Inicializar( int argc, char *argv[] ){
  miVentana= new Ventana(5);
}

 void P3_DibujarObjetos( unsigned modo )
 {
   cerr<<endl<<"modo "<<modo<<endl  ;
       miVentana->visualizar(modo);
 }
