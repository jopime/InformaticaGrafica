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
#include <iostream>
using namespace std;
// ---------------------------------------------------------------------
// declaraciones de estructuras de datos....
  const int num_vertsT=12, num_verts=24;

  GLfloat verticesT[num_vertsT*3]=
    {
      -1,-1,1,
      -1,-1,-1,
      1,-1,0,

      0,1,0,
      -1,-1,-1,
      1,-1,0,

      0,1,0,
      -1,-1,1,
      1,-1,0,

      0,1,0,
      -1,-1,1,
      -1,-1,-1,
     };
     GLfloat verticesC[num_verts*3]=
       {
//Lado Frontal
        1, - 1, - 1,
        1,   1, - 1,
       - 1,   1, - 1,
       - 1, - 1, - 1,
// LADO DERECHO
        1, - 1, - 1 ,
        1,   1, - 1 ,
        1,   1,   1 ,
        1, - 1,   1 ,
//Lado Trasero
         1, - 1,  1,
         1,   1,  1,
        - 1,   1,  1,
        - 1, - 1,  1,

// LADO IZQUIERDO
 - 1, - 1,   1 ,
 - 1,   1,   1 ,
 - 1,   1, - 1 ,
 - 1, - 1, - 1 ,

 // LADO INFERIOR
    1, - 1, - 1 ,
    1, - 1,   1 ,
  - 1, - 1,   1 ,
  - 1, - 1, - 1 ,

// LADO SUPERIOR
- 1,   1, - 1 ,
   1,   1,   1 ,
   1,   1, - 1 ,
 - 1,   1,   1 ,

       };
       Cubo micubo;
// ---------------------------------------------------------------------
// Función para implementar en la práctica 1 para inicialización.
// Se llama una vez al inicio, cuando ya se ha creado la ventana e
// incializado OpenGL.

void P1_Inicializar( int argc, char *argv[] )
{
  micubo.presentacion();
// vertices[0,0,1]={2};
}

// ---------------------------------------------------------------------
// Función a implementar en la práctica 1  para dibujar los objetos
// modo: 0 - puntos, 1 - alambre, 2 - sólido, 3 - sólido ajedrez

void P1_DibujarObjetos( unsigned modo )
{
  micubo.visualizar(4);
}
