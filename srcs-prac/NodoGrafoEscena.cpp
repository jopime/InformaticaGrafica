#include "NodoGrafoEscena.hpp"


void NodoGrafoEscena::visualizar (unsigned cv){
  glMatrixMode( GL_MODELVIEW ); // operaremos sobre la modelview
  glPushMatrix() ; // guarda modelview actual
// recorrer todas las entradas del array que hay en el nodo:
  Material * materialInicial=materialActual;
  for( unsigned i = 0 ; i < entradas.size() ; i++ ){
    if( entradas[i].tipoE == 0 ){ // si la entrada es sub-objeto:

      entradas[i].objeto->visualizar(cv);
    }
    else if(entradas[i].tipoE == 2){
      if(materialActual!=entradas[i].material){
        materialActual=entradas[i].material;
        entradas[i].material->activar() ;
      }
    }
    else{
      glMultMatrixf( *(entradas[i].matriz) ); // componerla
    }
  }
  if ( materialInicial != materialActual )  // si ha cambiado el material durante la vis. de este nodo:
   {
       materialActual = materialInicial ;    // restaurar el original en 'cv'
       if ( materialActual != NULL )               // si el original no era NULL
          materialActual->activar() ;              //    reactivarlo
   }

  glMatrixMode( GL_MODELVIEW ); // operaremos sobre la modelview
  glPopMatrix();
}

void NodoGrafoEscena::agregar( Objeto3D * objeto ){
  entradas.push_back(EntradaNGE(objeto));
}
void NodoGrafoEscena::agregar( Material * material ){
  entradas.push_back(EntradaNGE(material));
}
void NodoGrafoEscena::agregar( const Matriz4f & pMatriz ){
  entradas.push_back(EntradaNGE(pMatriz));
}
