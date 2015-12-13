#include "practica3.hpp"

static Ventana *miVentana=NULL;
static int p3_grado_libertad_activo=0;
static float cantidadG0=0; //cantidad para traslaciones
static int cantidadG1=0;   //cantidad para giros
static float cantidadG2=1; //cantidad para escalados
static int nG=3;
static bool restaAngulo=false,restaDistancia=false;

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
     case '<':
      switch (p3_grado_libertad_activo) {
        case 0:
          cantidadG0=cantidadG0-0.5;
          if (cantidadG0<-100){
            cerr<<"Maximo pulsa <"<<endl;
            cantidadG0=cantidadG0+0.5;
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
          break;
        case 2:
          cantidadG2--;
          break;
      }
      break;
    case '>':
      switch (p3_grado_libertad_activo) {
        case 0:
          cantidadG0=cantidadG0+0.5;
          if (cantidadG0>100){
            cerr<<"Maximo pulsa <"<<endl;
            cantidadG0=cantidadG0-0.5;
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
          break;
         case 2:
          cantidadG2++;
          break;
        }
        break;
      case 'G':
        p3_grado_libertad_activo++;
        p3_grado_libertad_activo=p3_grado_libertad_activo++%nG;
        break;
      default:
        redisp = false ;
        break ;
   }
   if(redisp){
     switch (p3_grado_libertad_activo) {
       case 0:
        cerr<<"Traslacion GradoLibertad: "<<p3_grado_libertad_activo<<" Valor: "<<cantidadG0;
        miVentana->Desplazarse(cantidadG0);
        break;
      case 1:
        cerr<<"Rotacion GradoLibertad: "<<p3_grado_libertad_activo<<" Valor: "<<cantidadG1;
        miVentana->Girar(cantidadG1);
        break;
      case 2:
        cerr<<"Escalado GradoLibertad: "<<p3_grado_libertad_activo<<" Valor: "<<cantidadG2;
        miVentana->Agrandar(cantidadG2);
        break;
      }
   }
   return redisp;
 }
 void P3_Animacion(){

   if (cantidadG0>50||cantidadG0<-50){
    restaDistancia=!restaDistancia;}
   if (restaDistancia){cantidadG0=cantidadG0-0.1;}
   else {cantidadG0=cantidadG0+0.1;}

   if (cantidadG1>40||cantidadG1<-40)
    restaAngulo=!restaAngulo;
   if (restaAngulo){cantidadG1=cantidadG1-2;}
   else {cantidadG1=cantidadG1+2;}
   miVentana->Desplazarse(cantidadG0);
   miVentana->Girar(cantidadG1);
 }
