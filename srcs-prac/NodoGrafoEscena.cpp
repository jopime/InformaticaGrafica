#include "NodoGrafoEscena.hpp"


void NodoGrafoEscena::visualizar (unsigned cv){
  glMatrixMode( GL_MODELVIEW ); // operaremos sobre la modelview
  glPushMatrix() ; // guarda modelview actual
// recorrer todas las entradas del array que hay en el nodo:
  Material * materialInicial=materialActual;
  for( unsigned i = 0 ; i < entradas.size() ; i++ ){
    if( entradas[i].tipoE == 0 ){ // si la entrada es sub-objeto:
      switch (color) {
        case 0:
          //cerr<<"pinto Negro"<<endl;
          glColor3f( 0.0, 0.0, 0.0 );
          break;
        case 1:
          //cerr<<"pinto Gris"<<endl;
          glColor3f( 0.7, 0.7, 0.7);
          break;
        case 2:
        //cerr<<"pinto Amarillo"<<endl;
          glColor3f( 1.0, 1.0, 0.0 );
          break;
        case 3:
          //cerr<<"pinto CASO 3"<<endl;
          glColor3f( 0.0, 1.0, 0.0 );
          break;
        case 4:
          //cerr<<"pinto CASO 4"<<endl;
          glColor3f( 1, 0.8, 0.4 );
          break;
        default :
      //  cerr<<"pinto NOSEE"<<endl;

          break;
      }
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
