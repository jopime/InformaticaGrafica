#include "practica3.hpp"

static Ventana *miVentana=NULL;
static int p3_grado_libertad_activo=0;
static float cantidadG0=0; //cantidad para traslaciones
static int cantidadG1=0;   //cantidad para giros
static float cantidadG2=1; //cantidad para escalados
static float velocidadG0=0.1; //cantidad de velocidad para traslaciones en animacion
static int velocidadG1=1;   //cantidad para velocidad giros en animacion
static int nG=3;
static bool restaAngulo=false,restaDistancia=false;
ColeccionFL * fuentesBatman=NULL;


void P3_Inicializar( int argc, char *argv[] )
{
  miVentana= new Ventana(3);
  fuentesBatman=new ColeccionFL;
  glEnable(GL_RESCALE_NORMAL);
  FuentePosicional* fuenteunica=new FuentePosicional(Tupla3f(10.0,0.0,0.0));
  fuentesBatman->fuentes.push_back(fuenteunica);
  fuentesBatman->activar();
}
 void P3_DibujarObjetos( unsigned modo )
 {
      cerr<<endl<<"modo "<<modo<<endl;
       miVentana->visualizar(modo);
 }
 bool P3_FGE_PulsarTeclaNormal( unsigned char tecla )
 {
   bool redisp=true;
   switch (tecla)
   {
     //teclas Profesor
     case '<':
      switch (p3_grado_libertad_activo) {
        case 0:
          cantidadG0=cantidadG0-0.5;
          if (cantidadG0<-100){
            cerr<<"Minimo pulsa >"<<endl;
            cantidadG0=cantidadG0+0.5;
            redisp=false;
            }
          break;
        case 1:
          cantidadG1=cantidadG1-2;
          if (cantidadG1<-80){
            cerr<<"Minimo pulsa >"<<endl;
            cantidadG1=cantidadG1+2;
            redisp=false;
          }
          break;
        case 2:
        cantidadG2=cantidadG2-0.2;
        if (cantidadG2<0.6){
          cerr<<"Minimo pulsa >"<<endl;
          cantidadG2=cantidadG2+0.2;
          redisp=false;
        }
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
          cantidadG2=cantidadG2+0.2;
          if (cantidadG2>2.6){
           cerr<<"Maximo pulsa <"<<endl;
           cantidadG2=cantidadG2-0.2;
           redisp=false;
         }
          break;
         default:
          break;
        }
        break;
    case 'G':
    case 'g':
      p3_grado_libertad_activo++;
      p3_grado_libertad_activo=p3_grado_libertad_activo++%nG;
      break;
    case 'V':
      switch (p3_grado_libertad_activo) {
        case 0:
          velocidadG0=velocidadG0+0.1;
          break;
        case 1:
          velocidadG1=velocidadG1+1;
          break;
        case 2:
          cerr <<"Grado no Animado pulsar G"<<endl;
          break;
        default:
          break;
        }
      break;
    case 'v':
      switch (p3_grado_libertad_activo) {
        case 0:
          velocidadG0=velocidadG0-0.1;
          if (velocidadG0<0.1){
            velocidadG0=0;
            cerr<<"Limite de velocidad inferior alcanzado"<<endl;
            cerr<<"Aumentala con v"<<endl;
          }
          break;
        case 1:
          velocidadG1=velocidadG1-1;
          if (velocidadG1<1){
            velocidadG1=1;
            cerr<<"Limite de velocidad inferior alcanzado"<<endl;
            cerr<<"Aumentala con v"<<endl;
          }
          break;
        case 2:
          cerr <<"Grado no Animado pulsar G"<<endl;
          break;
        default:
          break;
          }
        break;
      case 'c':
      case 'C':
        switch (p3_grado_libertad_activo) {
          case 0:
            velocidadG0=0;
            break;
          case 1:
            velocidadG1=0;
            break;
          case 2:
            cerr <<"Grado no Animado pulsar G"<<endl;
            break;
          default:
            break;
            }
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
   if (restaDistancia){cantidadG0=cantidadG0-velocidadG0;}
   else {cantidadG0=cantidadG0+velocidadG0;}

   if (cantidadG1>40||cantidadG1<-40)
    restaAngulo=!restaAngulo;
   if (restaAngulo){cantidadG1=cantidadG1-velocidadG1;}
   else {cantidadG1=cantidadG1+velocidadG1;}
   cerr<<" Velocidad Grado0: "<<velocidadG0<<" Velocidad Grado 1: "<<velocidadG1<<endl;
   cerr<<" Cantidad Grado0: "<<cantidadG0<<" Cantidad Grado1: "<<cantidadG1<<endl;

   miVentana->Desplazarse(cantidadG0);
   miVentana->Girar(cantidadG1);
 }
