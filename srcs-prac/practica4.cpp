#include "practica4.hpp"

unsigned objetito4 = 1 ; // objetito activo: cubo (0), tetraedro (1), otros....
int a=0;
static Ventana *miVentana4=NULL;
ColeccionFL * fuentes=NULL;
FuenteDireccional* fuente3=NULL;

void P4_Inicializar( int argc, char *argv[] ){
  fuentes=new ColeccionFL;
  glEnable(GL_RESCALE_NORMAL);
  FuenteLuz* fuente1=new FuentePosicional(Tupla3f(-10,10,10));
  FuenteLuz* fuente2=new FuentePosicional(Tupla3f(-10,4,10));
  fuente3=new FuenteDireccional(1,1);
  miVentana4= new Ventana();
  fuentes->fuentes.push_back(fuente3);
  fuentes->activar();

}

bool P4_FGE_PulsarTeclaNormal( unsigned char tecla )
{
   bool redisp=true;
   switch (toupper(tecla))
   {
      case 'O':
          break ;
      case 'G':
          break ;
      case '<':
          break ;
      case '>':
          break ;
      default:
         redisp = false ;
         break ;
   }
   return redisp;
 }
 void P4_DibujarObjetos( unsigned modo )
 {
   cerr<<endl<<"modo "<<modo<<"  objetito4: "<<objetito4<<endl  ;
   miVentana4->visualizar(modo);
 }
