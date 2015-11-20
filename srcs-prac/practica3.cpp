#include "practica3.hpp"
float grado = 0;
float pos=0;
float giroB=0;
bool resta=false;
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
       case 'L':
        giroB=giroB+8;
        miVentana->Lanzar(giroB);
        break;
       case 'G':
          if (grado>40 || grado<-40)
            resta=!resta;
          if (resta)
            grado=grado+10;
          else
            grado=grado-10;
           miVentana->Mov(grado);
           break ;
       case 'T':
         if (grado>40 || grado<-40)
           resta=!resta;
         if (resta)
           grado=grado+10;
         else
           grado=grado-10;
          pos=pos+0.1;
           miVentana->Tras(pos,grado);
           break ;
       default:
          redisp = false ;
          break ;
    }
    return redisp;
  }
