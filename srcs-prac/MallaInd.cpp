#include "MallaInd.hpp"

MallaInd::MallaInd (){
  nombre_obj="Malla";
}
void MallaInd::visualizar (unsigned modo_vis){
  glEnableClientState( GL_VERTEX_ARRAY ); // habilitar array de vértices
  glVertexPointer( 3, GL_FLOAT, 0, &stlVertices[0]); // estable direccion y estructuras
  //glColor3f(0.2,0,0.8);    //Color amarillo claro
  glPointSize(2);

  switch (modo_vis) {
    case 0:
      glPolygonMode(GL_FRONT_AND_BACK,GL_POINT);
      glDrawElements(GL_TRIANGLES,stlCaras.size()*3,GL_UNSIGNED_INT,&stlCaras[0]);     //Visualiza primitivas
      break;
    case 1:
      glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
      glDrawElements(GL_TRIANGLES,stlCaras.size()*3,GL_UNSIGNED_INT,&stlCaras[0]);     //Visualiza primitivas
      break;
    case 2:
      glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
      glDrawElements(GL_TRIANGLES,stlCaras.size()*3,GL_UNSIGNED_INT,&stlCaras[0]);     //Visualiza primitivas
      break;
    case 3:
      glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
      for(int i=0;i<stlCaras.size();i++){
          glColor3f(0.7,0.7,0.7*(i%2));    //Color Negro/AMARILLO
          glDrawElements(GL_TRIANGLES,3,GL_UNSIGNED_INT,&stlCaras[i]);  //Visualiza primitivas
        }
      break;
    default:
      cerr<<" opcion de visualizacion Incorrecta"<<endl;
      break;
  }
  glDisableClientState(GL_VERTEX_ARRAY);// Deshabilitar array de vértices

}

  void MallaInd::presentacion (){
      cout <<"Soy "<<nombre()<<endl;
      for(int i=0;i<stlVertices.size();i++){
        cout<<" V["<<i<<"]:"<<stlVertices[i]<<" ";
      }
        cout<<endl;
      for(int i=0;i<stlCaras.size();i++){
        cout<<" A["<<i<<"]:"<<stlCaras[i]<<" ";
      }
      cout<<endl;
    }
