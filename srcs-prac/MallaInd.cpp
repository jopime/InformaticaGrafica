#include "MallaInd.hpp"

MallaInd::MallaInd (){
  nombre_obj="Malla";
}
void MallaInd::visualizar (unsigned modo_vis){
  glEnableClientState( GL_VERTEX_ARRAY ); // habilitar array de vértices
  glVertexPointer( 3, GL_FLOAT, 0, &stlVertices[0]); // estable direccion y estructuras
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
      case 4: //revisar
        glShadeModel(GL_FLAT); //caras es como solido
          glBegin(GL_TRIANGLES);
              glColor3f(1.0f, 0.0f, 0.0f);  // activamos el color rojo
              glVertex3f(-1.0f, 0.0f, 0.0f);
              glColor3f(0.0f, 1.0f, 0.0f);  // activamos el color verde
              glVertex3f(1.0f, 0.0f, 0.0f);
              glColor3f(0.0f, 0.0f, 1.0f);  // activamos el color azul
              glVertex3f(0.0f, 1.0f, 0.0f);
          glEnd();
      case 5: //revisar
        glShadeModel(GL_SMOOTH); //vertices suave
          glBegin(GL_TRIANGLES);
                glColor3f(1.0f, 0.0f, 0.0f);  // activamos el color rojo
                glVertex3f(-1.0f, 0.0f, 0.0f);
                glColor3f(0.0f,1.0f, 0.0f);  // activamos el color verde
                glVertex3f(1.0f,0.0f, 0.0f);
                glColor3f(0.0f, 0.0f, 1.0f);  // activamos el color azul
                glVertex3f(0.0f, 1.0f, 0.0f);
          glEnd();
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

  void MallaInd::calcularNormales(){
    Tupla3f p,q;
                                        //Calculo las normales a las caras
    for(int i=0;i<stlCaras.size();i++){
      p=stlVertices[stlCaras[i](1)]-stlVertices[stlCaras[i](0)];
      q=stlVertices[stlCaras[i](2)]-stlVertices[stlCaras[i](0)];
      normalCaras.push_back(Tupla3f(p(1)*q(2)-p(2)*q(1),p(2)*q(0)-p(0)*q(2),p(0)*q(1)-p(1)*q(0)).normalized());
      cerr<<"normalC "<<i<<": "<<normalCaras[i]<<endl;
    }
    for(int i=0;i<stlVertices.size();i++){  //creo normalVertices de tamaño numVertices inicializado a cero
      normalVertices.push_back(Tupla3f(0,0,0));
    }
    /******
    * Si la cara i-esima contiene al vertice [i](0|1|1), le sumo su normal de cara
    * a las normales de cara que ya contenia por ser caras adyacentes a ese vertice
    * inicialmente ninguna luego era 0, por ultimo se normaliza cada componente del vector
    * normalVertices
    ******/
    for (int i=0;i<stlCaras.size();i++){
      normalVertices[stlCaras[i](0)]=normalVertices[stlCaras[i](0)]+normalCaras[stlCaras[i](0)];
      normalVertices[stlCaras[i](1)]=normalVertices[stlCaras[i](1)]+normalCaras[stlCaras[i](1)];
      normalVertices[stlCaras[i](2)]=normalVertices[stlCaras[i](2)]+normalCaras[stlCaras[i](2)];
    }
    for(int i=0;i<normalVertices.size();i++){
      normalVertices[i]=normalVertices[i].normalized();
      cerr<<"normalV "<<i<<": "<<normalVertices[i]<<endl;
    }
  }
