#include "practica2.hpp"

unsigned objetito = 0 ; // objetito activo: cubo (0), tetraedro (1), otros....
static MallaPLY *miPLY=NULL;
static MallaRevol *miRevol=NULL;
//static MallaRevol *miRev=NULL;

void P2_Inicializar( int argc, char *argv[] ){
if(argc!=3){
 cout<<"numero de argumentos incorrecto agregar ruta PLY"<<endl;
 exit(1);
}

  miPLY= new MallaPLY(argv[1]);
  miRevol=new MallaRevol(argv[2],6);
  miRevol->presentacion();
}

bool P2_FGE_PulsarTeclaNormal( unsigned char tecla )
{
   bool redisp=true;
   switch (toupper(tecla))
   {
      case 'Z':
          objetito=0;
          break ;
      case 'X':
          objetito=1;
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
