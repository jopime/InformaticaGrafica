#include "practica3.hpp"
float grado = 0;
int num=0;
float pos=0;
float giroB=1;
bool resta=false;


static Ventana *miVentana=NULL;
static int p3_grado_libertad_activo=0;
static float cantidadG0=0; //cantidad para traslaciones
static int cantidadG1=0;   //cantidad para giros
static float cantidadG2=0; //cantidad para escalados

static int nG=3;
bool animacion=false;

void P3_Inicializar( int argc, char *argv[] )
{
  miVentana= new Ventana(3);
}
 void P3_DibujarObjetos( unsigned modo )
 {
      cerr<<endl<<"modo "<<modo<<endl;
       miVentana->visualizar(modo);
 }
 bool P3_FGE_PulsarTeclaNormal( unsigned char tecla )
 {
   bool redisp=true;
   switch (toupper(tecla))
   {
     //teclas Profesor
     case 'G':
      p3_grado_libertad_activo++;
      p3_grado_libertad_activo=p3_grado_libertad_activo++%nG;
      break;
      case '<':
        switch (p3_grado_libertad_activo) {
           case 0:
             cantidadG0=cantidadG0-0.1;
             if (cantidadG0<-100){
               cerr<<"Maximo pulsa <"<<endl;
               cantidadG0=cantidadG0+0.1;
               redisp=false;
             }
             break;
           case 1:
             cantidadG1=cantidadG1-2;
             if (cantidadG1<-80){
               cerr<<"Maximo pulsa <"<<endl;
               cantidadG1=cantidadG1+2;
               redisp=false;
             }
            miVentana->Girar(cantidadG1);
            break;
           case 2:
             //miVentana->Agrandar(cantidadG2);
             break;
        }
          break;
    case '>':
      switch (p3_grado_libertad_activo) {
         case 0:
           cantidadG0=cantidadG0+0.1;
           if (cantidadG0>100){
             cerr<<"Maximo pulsa <"<<endl;
             cantidadG0=cantidadG0-0.1;
             redisp=false;
           }
           break;
         case 1:
          cantidadG1=cantidadG1+2;
          if (cantidadG1>80){
            cerr<<"Maximo pulsa <"<<endl;
            cantidadG1=cantidadG1-2;
            redisp=false;
          }
          miVentana->Girar(cantidadG1);
          break;
         case 2:
           //miVentana->Agrandar(cantidadG2);
           break;
      }
        break;
    case 'D':
        animacion=true;
    default:
       redisp = false ;
       break ;
   }
   if(redisp){
     switch (p3_grado_libertad_activo) {
        case 0:
          cerr<<"GradoLibertad: "<<p3_grado_libertad_activo<<" Valor: "<<cantidadG0;
          miVentana->Desplazarse(cantidadG0);
          break;
        case 1:
        cerr<<"GradoLibertad: "<<p3_grado_libertad_activo<<" Valor: "<<cantidadG1;
         miVentana->Girar(cantidadG1);
         break;
        case 2:
        cerr<<"GradoLibertad: "<<p3_grado_libertad_activo<<" Valor: "<<cantidadG2;

          //miVentana->Agrandar(cantidadG2);
          break;
     }
   }

     if(animacion){
       redisp=true;
       cantidadG0=cantidadG0+0.1;
       cantidadG1=cantidadG1+2;
       miVentana->Desplazarse(cantidadG0);
       miVentana->Girar(2*cantidadG1);


      }
   return redisp;
 }
void P3_Animacion(){

  cantidadG0=cantidadG0+0.1;
  if (cantidadG1>40){
    cantidadG1=cantidadG1-2;
  }
  else{

  }
  miVentana->Desplazarse(cantidadG0);
  miVentana->Girar(2*cantidadG1);
}

 /*
 bool P3_FGE_PulsarTeclaNormal( unsigned char tecla )
 {
    bool redisp=true;
    switch (toupper(tecla))
    {
      //teclas Profesor
      case 'G':
       num++;
     case '<':
     grado=grado-2;
        break;
     case '>':
         grado=grado+2;
         break;
      //mis teclas
     case 'L':
          num=0;
      case 'R':
          num=1;
      case 'T':
          num=2;
       default:
          redisp = false ;
          break ;
    }
    switch (num%4) {
      case 0:
  //      miVentana->Lanzar(giroB);
  //      giroB=giroB+2;
  //      break;
      case 1:
        if (grado>40 || grado<-40)
          resta=!resta;
        if (resta)
          grado=grado+10;
        else
          grado=grado-10;
         miVentana->Mov(grado);
         break ;
      case 2: //T
        if (grado>40 || grado<-40)
          resta=!resta;
        if (resta)
          grado=grado+10;
        else
          grado=grado-10;
         pos=pos+0.1;
          miVentana->Tras(pos,grado);
          break ;

    }
    return redisp;
  }
*/
