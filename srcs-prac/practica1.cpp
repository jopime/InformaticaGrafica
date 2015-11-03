// *********************************************************************
// **
// ** Informática Gráfica, curso 2015-16
// ** Práctica 1  (implementación)
// **
// *********************************************************************

#include "aux.hpp"
#include "tuplasg.hpp"   // Tupla3f
#include "practica1.hpp"
#include "Toro.hpp"
#include "Tetraedro.hpp"
#include "Cono.hpp"
#include "Cilindro.hpp"
#include "Cubo.hpp"


#include <iostream>
using namespace std;

unsigned objeto_activo = 0 ; // objeto activo: cubo (0), tetraedro (1), otros....

// ---------------------------------------------------------------------
// declaraciones de estructuras de datos....
Toro *mitoro;
Cubo *micubo;
Tetraedro *mitetraedro;
Cono *micono;
Cilindro *micilindro;

// ---------------------------------------------------------------------
// Función para implementar en la práctica 1 para inicialización.
// Se llama una vez al inicio, cuando ya se ha creado la ventana e
// incializado OpenGL.

void P1_Inicializar( int argc, char *argv[] )
{
  micono= new Cono(60);
  micubo= new Cubo();
  mitetraedro=new Tetraedro();
  micilindro= new Cilindro(60);
  mitoro= new Toro();
  //mitoro->presentacion();
  //mitetraedro->presentacion();
  //micono->presentacion();
  //micilindro->presentacion();
  //micubo->presentacion();
}

// ---------------------------------------------------------------------
// Función invocada al pulsar una tecla con la práctica 1 activa:
// (si la tecla no se procesa en el 'main').
//
//  - devuelve 'true' si la tecla se usa en esta práctica para cambiar
//    entre el toro, el tetraedro u otros objetos (cambia el valor de
//    'objeto_activo').
//  - devuelve 'false' si la tecla no se usa en esta práctica (no ha
//    cambiado nada)

bool P1_FGE_PulsarTeclaNormal( unsigned char tecla )
{
   bool redisp=true;
   switch (toupper(tecla))
   {
      case 'O':
          objeto_activo=(objeto_activo+1)%5;
          break ;
      default:
         redisp = false ;
         break ;
   }
   return redisp;
 }


// ---------------------------------------------------------------------
// Función a implementar en la práctica 1  para dibujar los objetos
// modo: 0 - puntos, 1 - alambre, 2 - sólido, 3 - sólido ajedrez , >=4 otros....

void P1_DibujarObjetos( unsigned modo )
{
  cerr<<endl<<"modo "<<modo<<"  objeto_activo: "<<objeto_activo<<endl  ;
    if (objeto_activo==0){
      micubo->visualizar(modo);
    }
    else if(objeto_activo==1){
      mitetraedro->visualizar(modo);
    }

    else if (objeto_activo==2){
      micilindro->visualizar(modo);
      }

    else if (objeto_activo==3){
      micono->visualizar(modo);
    }

    else if (objeto_activo==4){
      mitoro->visualizar(modo);
    }

    else{
      cerr<<endl<<"ERROR AL SELECCIONAR objeto_activo"<<endl;
    }
}
