#include "practica2.hpp"

unsigned objetito = 1 ; // objetito activo: cubo (0), tetraedro (1), otros....
static MallaPLY *miPLY=NULL;
static MallaRevol *miRevol=NULL;

void P2_Inicializar( int argc, char *argv[] ){
if(argc!=4){
 cout<<"numero de argumentos incorrecto agrego ruta PLY"<<endl;
 miPLY= new MallaPLY("/Users/jopime/GitHub/InformaticaGrafica/srcs-prac/plys/beethoven.ply");
 miRevol= new MallaRevol("/Users/jopime/GitHub/InformaticaGrafica/srcs-prac/plys/revol.ply",4);

}
else{
  miPLY= new MallaPLY(argv[1]);
  miRevol=new MallaRevol(argv[2],atoi(argv[3]));
  }
}

bool P2_FGE_PulsarTeclaNormal( unsigned char tecla )
{
   bool redisp=true;
   switch (toupper(tecla))
   {
      case 'Z':
          objetito=0;
          cerr<<"pulsadoZzZZZ"<<endl;
          break ;
      case 'X':
          objetito=1;
          cerr<<"pulsadoXXXxxXX"<<endl;
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
     else{
       cerr<<endl<<"ERROR AL SELECCIONAR objetito"<<endl;
     }
 }
