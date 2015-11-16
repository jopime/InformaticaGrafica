#include "NodoGrafoEscena.hpp"


void NodoGrafoEscena::visualizar (unsigned cv){
  glMatrixMode( GL_MODELVIEW ); // operaremos sobre la modelview
  glPushMatrix() ; // guarda modelview actual
// recorrer todas las entradas del array que hay en el nodo:

  for( unsigned i = 0 ; i < entradas.size() ; i++ ){
    if( entradas[i].tipoE == 0 ) // si la entrada es sub-objeto:
      entradas[i].objeto->visualizar(cv);
    else
      glMultMatrixf( *(entradas[i].matriz) ); // componerla
  }
  glMatrixMode( GL_MODELVIEW ); // operaremos sobre la modelview
  glPopMatrix();
}

void NodoGrafoEscena::agregar( Objeto3D * objeto ){
  entradas.push_back(EntradaNGE(objeto));
}
void NodoGrafoEscena::agregar( const Matriz4f & pMatriz ){
  entradas.push_back(EntradaNGE(pMatriz));
}
