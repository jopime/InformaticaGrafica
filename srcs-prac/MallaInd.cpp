#include "MallaInd.hpp"

MallaInd::MallaInd (){
  nombre_obj="Malla";
}
void MallaInd::visualizar (unsigned modo_vis){

  switch (modo_vis) {
    case 0:
      glEnableClientState( GL_VERTEX_ARRAY ); // habilitar array de vértices
      glVertexPointer( 3, GL_FLOAT, 0, nostlVertices); // estable direccion y estructuras
      glColor3f(0.0,1.0,0.0);    //Color Verde
      glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
      glDrawElements(GL_TRIANGLES,num_caras*3,GL_UNSIGNED_INT,nostlCaras);     //Visualiza primitivas
      glDisableClientState(GL_VERTEX_ARRAY);// Deshabilitar array de vértices
      break;
    case 1:
      glEnableClientState( GL_VERTEX_ARRAY ); // habilitar array de vértices
      glVertexPointer( 3, GL_FLOAT, 0, nostlVertices); // estable direccion y estructuras
      glColor3f(0.0,1.0,0.0);    //Color Verde
      glPolygonMode(GL_FRONT_AND_BACK,GL_POINT);
      glDrawElements(GL_TRIANGLES,num_caras*3,GL_UNSIGNED_INT,nostlCaras);     //Visualiza primitivas
      glDisableClientState(GL_VERTEX_ARRAY);// Deshabilitar array de vértices
      break;
    case 2:
      glEnableClientState( GL_VERTEX_ARRAY ); // habilitar array de vértices
      glVertexPointer( 3, GL_FLOAT, 0, nostlVertices); // estable direccion y estructuras
      glColor3f(0.0,1.0,0.0);    //Color Verde
      glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
      glDrawElements(GL_TRIANGLES,num_caras*3,GL_UNSIGNED_INT,nostlCaras);     //Visualiza primitivas
      glDisableClientState(GL_VERTEX_ARRAY);// Deshabilitar array de vértices
      break;
    case 3:
      glEnableClientState( GL_VERTEX_ARRAY ); // habilitar array de vértices
      glVertexPointer( 3, GL_FLOAT, 0, nostlVertices); // estable direccion y estructuras
      glColor3f(0.0,1.0,0.0);    //Color Verde
      glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
      for(int i=0;i<num_caras;i++){
          glColor3f(1.0,1.0,(i%2));    //Color BLANCO/AMARILLO
          glDrawElements(GL_TRIANGLES,3,GL_UNSIGNED_INT,&nostlCaras[i]);  //Visualiza primitivas
    }
      glDisableClientState(GL_VERTEX_ARRAY);// Deshabilitar array de vértices
      break;
    default:
      cerr<<" opcion de visualizacion Incorrecta"<<endl;
      break;
  }
}

  void MallaInd::presentacion (){
      cout <<"Soy "<<nombre()<<endl;
      for(int i=0;i<num_verts;i++){
        cout<<" V[]:"<<nostlVertices[i]<<" ";
      }
        cout<<endl;
      for(int i=0;i<num_caras;i++){
        cout<<" A[]:"<<nostlCaras[i]<<" ";
      }
      cout<<endl;
    }
