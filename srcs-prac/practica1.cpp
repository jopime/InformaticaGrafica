// *********************************************************************
// **
// ** Informática Gráfica, curso 2015-16
// ** Práctica 1  (implementación)
// **
// *********************************************************************

#include "aux.hpp"
#include "tuplasg.hpp"   // Tupla3f
#include "practica1.hpp"
#include "Cubo.hpp"
#include "Tetraedro.hpp"
#include "Cono.hpp"
#include "Cilindro.hpp"

#include <iostream>
using namespace std;
// ---------------------------------------------------------------------
// declaraciones de estructuras de datos....
unsigned fig=0;
Cubo micubo;
Tetraedro mitetraedro;
Cono micono(60);
Cilindro micilindro(60);
// ---------------------------------------------------------------------
// Función para implementar en la práctica 1 para inicialización.
// Se llama una vez al inicio, cuando ya se ha creado la ventana e
// incializado OpenGL.

void P1_Inicializar( int argc, char *argv[] )
{
  micubo.presentacion();
  mitetraedro.presentacion();
  micono.presentacion();
  micilindro.presentacion();
}

// ---------------------------------------------------------------------
// Función a implementar en la práctica 1  para dibujar los objetos
// modo: 0 - puntos, 1 - alambre, 2 - sólido, 3 - sólido ajedrez
bool P1_Cambiar(int tecla )
{

   bool redisp=true;
   switch (toupper(tecla))
   {
      case 'A':
          fig=0;
          break ;
      case 'S':
          fig=1;
          break ;
      case 'D':
          fig=2;
          break ;
      case 'F':
          fig=3;
          break ;
      default:
         redisp = false ;
         break ;
   }
   return redisp;
}


void P1_DibujarObjetos( unsigned modo )
{
cerr<<endl<<"modo "<<modo<<"  fig: "<<fig<<endl  ;
  if (fig==0){
    micono.visualizar(modo);
  }
  else if(fig==1){
    micilindro.visualizar(modo);
  }
  else if (fig==2){
    micubo.visualizar(modo);
    }
  else if (fig==3){
    mitetraedro.visualizar(modo);
  }
  else{cerr<<endl<<"ERROR AL SELECCIONAR FIGURA"<<endl;}

}
