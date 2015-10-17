#include "practica2.hpp"

unsigned objetito = 0 ; // objetito activo: cubo (0), tetraedro (1), otros....
MallaPLY *miPLY;


void P2_Inicializar( int argc, char *argv[] ){
if(argc!=2){
 cout<<"numero de argumentos incorrecto agregar ruta PLY"<<endl;
 exit(1);
}

  miPLY= new MallaPLY(argv[1]);
}

bool P2_FGE_PulsarTeclaNormal( unsigned char tecla )
{
   bool redisp=true;
   switch (toupper(tecla))
   {
      case 'Z':

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
     else{
       cerr<<endl<<"ERROR AL SELECCIONAR objetito"<<endl;
     }
 }
