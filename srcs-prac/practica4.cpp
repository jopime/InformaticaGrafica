#include "practica4.hpp"

unsigned objetito4 = 1 ; // objetito activo: cubo (0), tetraedro (1), otros....
int a=0;
static MallaPLY *miPLY4=NULL;
static MallaRevol *miRevol4=NULL;

void P4_Inicializar( int argc, char *argv[] ){
if(argc!=9){
 cout<<"numero de argumentos incorrecto agrego ruta PLY"<<endl;
 miPLY4= new MallaPLY("../plys/big_dodge.ply");
 miRevol4= new MallaRevol("../plys/peon.ply",4);
miPLY4->calcularNormales();
}
else{
  miPLY4= new MallaPLY(argv[1]);
  miRevol4=new MallaRevol(argv[2],atoi(argv[3]));
  }
  miRevol4->Imprimir();
}

bool P4_FGE_PulsarTeclaNormal( unsigned char tecla )
{
   bool redisp=true;
   switch (toupper(tecla))
   {
      case 'O':
          objetito4=(objetito4+1)%2;
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
     if (objetito4==0){
       miPLY4->visualizar(modo);
     }
     else if (objetito4==1){
       miRevol4->visualizar(modo);
     }
     else{
       cerr<<endl<<"ERROR AL SELECCIONAR objetito"<<endl;
     }
 }
