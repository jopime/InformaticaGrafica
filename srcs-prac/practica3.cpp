#include "practica3.hpp"
float grado = 0;
float pos=0;
static Ventana *miVentana=NULL;

void P3_Inicializar( int argc, char *argv[] ){
  miVentana= new Ventana(3);
}

 void P3_DibujarObjetos( unsigned modo )
 {
   cerr<<endl<<"modo "<<modo<<endl  ;
       miVentana->visualizar(modo);
 }
 bool P3_FGE_PulsarTeclaNormal( unsigned char tecla )
 {
    bool redisp=true;
    switch (toupper(tecla))
    {
       case 'G':
          grado=grado+10;
           miVentana->Mov(grado);
           break ;
       case 'T':
          pos=pos+0.1;
           miVentana->Tras(pos);
           break ;
       default:
          redisp = false ;
          break ;
    }
    return redisp;
  }
