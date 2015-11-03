#include "practica2.hpp"

unsigned objetito = 1 ; // objetito activo: cubo (0), tetraedro (1), otros....
static MallaPLY *miPLY=NULL;
static MallaRevol *miRevol=NULL;
static MallaBarrido *miBarrido=NULL;

void P2_Inicializar( int argc, char *argv[] ){
if(argc!=9){
 cout<<"numero de argumentos incorrecto agrego ruta PLY"<<endl;
 miPLY= new MallaPLY("/Users/jopime/GitHub/InformaticaGrafica/plys/dragon.ply");
 miRevol= new MallaRevol("/Users/jopime/GitHub/InformaticaGrafica/plys/peon.ply",4);
 miBarrido=new MallaBarrido("/Users/jopime/GitHub/InformaticaGrafica/plys/revol.ply",2,2,2,13);
 miBarrido->presentacion();

}
else{
  miPLY= new MallaPLY(argv[1]);
  miRevol=new MallaRevol(argv[2],atoi(argv[3]));
  miBarrido=new MallaBarrido(argv[4],atoi(argv[5]),atoi(argv[6]),atoi(argv[7]),atoi(argv[8]));
  }
}

bool P2_FGE_PulsarTeclaNormal( unsigned char tecla )
{
   bool redisp=true;
   switch (toupper(tecla))
   {
      case 'O':
          objetito=(objetito+1)%3;
          break ;
      default:
         redisp = false ;
         break ;
   }
   return redisp;
 }
 void P2_DibujarObjetos( unsigned modo )
 {
   cerr<<endl<<"modo "<<modo<<"  objetito: "<<objetito<<endl  ;
     if (objetito==0){
       miPLY->visualizar(modo);
     }
     else if (objetito==1){
       miRevol->visualizar(modo);
     }
     else if (objetito==2){
       miBarrido->visualizar(modo);
     }
     else{
       cerr<<endl<<"ERROR AL SELECCIONAR objetito"<<endl;
     }
 }
