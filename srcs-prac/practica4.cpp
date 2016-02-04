#include "practica4.hpp"

unsigned objetito4 = 1 ; // objetito activo: cubo (0), tetraedro (1), otros....
int a=0;
static Ventana *miVentana4=NULL;
ColeccionFL * fuentes=NULL;
FuenteDireccional* fuente1=NULL;

void P4_Inicializar( int argc, char *argv[] ){
  fuentes=new ColeccionFL;
  glEnable(GL_RESCALE_NORMAL);
  FuentePosicional* fuente2=new FuentePosicional(Tupla3f(10.0,2.0,3.0));
  fuente1=new FuenteDireccional(0,0);
  miVentana4= new Ventana();
  fuentes->fuentes.push_back(fuente1);
  fuentes->fuentes.push_back(fuente2);
  fuentes->activar();

}

bool P4_FGE_PulsarTeclaNormal( unsigned char tecla )
{

   bool redisp=true;
   switch (toupper(tecla))
   {
       case 'G':
       a=(a+1)%2;
       break;

       case '<':
       fuente1->variarAngulo(a,-10);
       break;

       case '>':
       fuente1->variarAngulo(a,10);
       break;

      default:
         redisp = false ;
         break ;
   }

   return redisp;
 }

 void P4_DibujarObjetos( unsigned modo )
 {
   cerr<<endl<<"modo "<<modo<<"  objetito4: "<<objetito4<<endl  ;
   fuentes->activar();
   miVentana4->visualizar(modo);
 }
