#include "MallaInd.hpp"

MallaInd::MallaInd (){
  nombre_obj="Malla";
}
void MallaInd::visualizar (unsigned modo_vis){

  switch (modo_vis) {
    case 0:
      glEnableClientState( GL_VERTEX_ARRAY ); // habilitar array de vértices
      glVertexPointer( 3, GL_FLOAT, 0, &verticesC); // estable direccion y estructuras
      glColor3f(0.0,1.0,0.0);    //Color Verde
      glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
      glDrawArrays(GL_TRIANGLES,0,verticesC.size());     //Visualiza primitivas
      glDisableClientState(GL_VERTEX_ARRAY);// Deshabilitar array de vértices
      break;
    case 1:
    glEnableClientState( GL_VERTEX_ARRAY ); // habilitar array de vértices
    glVertexPointer( 3, GL_FLOAT, 0, &verticesC); // estable direccion y estructuras
    glColor3f(0.0,1.0,0.0);    //Color Verde
    //glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
    glDrawArrays(GL_LINE_LOOP,0,verticesC.size()*3);     //Visualiza primitivas
    glDisableClientState(GL_VERTEX_ARRAY);// Deshabilitar array de vértices
    break;



    case 2:         //uso de array MODO ALAMBRE
    glEnableClientState( GL_VERTEX_ARRAY ); // habilitar array de vértices
    glVertexPointer( 3, GL_FLOAT, 0, nostl); // estable direccion y estructuras
    glColor3f(0.0,1.0,0.0);    //Color Verde
    glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
    glDrawArrays(GL_TRIANGLES,0,num_verts);     //Visualiza primitivas
    glDisableClientState(GL_VERTEX_ARRAY);// Deshabilitar array de vértices
    break;
    case 3:         //uso de array MODO PUNTOS
    glEnableClientState( GL_VERTEX_ARRAY ); // habilitar array de vértices
    glVertexPointer( 3, GL_FLOAT, 0, nostl); // estable direccion y estructuras
    glColor3f(0.0,1.0,0.0);    //Color Verde
    glPolygonMode(GL_FRONT_AND_BACK,GL_POINT);
    glDrawArrays(GL_TRIANGLES,0,num_verts);     //Visualiza primitivas
    glDisableClientState(GL_VERTEX_ARRAY);// Deshabilitar array de vértices
    break;
    case 4:         //uso de array MODO SOLIDO
    glEnableClientState( GL_VERTEX_ARRAY ); // habilitar array de vértices
    glVertexPointer( 3, GL_FLOAT, 0, nostl); // estable direccion y estructuras
    glColor3f(0.0,1.0,0.0);    //Color Verde
    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    glDrawArrays(GL_TRIANGLES,0,num_verts);     //Visualiza primitivas
    glDisableClientState(GL_VERTEX_ARRAY);// Deshabilitar array de vértices
    break;
    default:
      cerr<<" opcion de visualizacion Incorrecta"<<endl;
      break;
  }
}

  void MallaInd::presentacion (){
      cout <<"Soy "<<nombre()<<endl;
      for(int i=0;i<verticesC.size();i=i+3){
        cout<<" V[][][]:"<<verticesC[i]<<verticesC[i+1]<<verticesC[i+2]<<endl;
      }
    }
