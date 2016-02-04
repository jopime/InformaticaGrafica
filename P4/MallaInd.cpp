#include "MallaInd.hpp"

MallaInd::MallaInd (){
  nombre_obj="Malla";
}
void MallaInd::visualizar (unsigned modo_vis){

  switch (modo_vis) {
    case 0:
      glPolygonMode(GL_FRONT_AND_BACK,GL_POINT);
      glEnableClientState( GL_VERTEX_ARRAY ); // habilitar array de vertices
      glVertexPointer( 3, GL_FLOAT, 0, &stlVertices[0]); // estable direccion y estructuras
      glDrawElements(GL_TRIANGLES,stlCaras.size()*3,GL_UNSIGNED_INT,&stlCaras[0]);     //Visualiza primitivas
      break;
    case 1:
      glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
      glEnableClientState( GL_VERTEX_ARRAY ); // habilitar array de vertices
      glVertexPointer( 3, GL_FLOAT, 0, &stlVertices[0]); // estable direccion y estructuras
      glDrawElements(GL_TRIANGLES,stlCaras.size()*3,GL_UNSIGNED_INT,&stlCaras[0]);     //Visualiza primitivas
      glDisableClientState( GL_VERTEX_ARRAY );
      break;
    case 2:
      glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
      glEnableClientState( GL_VERTEX_ARRAY ); // habilitar array de vertices
      glVertexPointer( 3, GL_FLOAT, 0, &stlVertices[0]); // estable direccion y estructuras
      glDrawElements(GL_TRIANGLES,stlCaras.size()*3,GL_UNSIGNED_INT,&stlCaras[0]);     //Visualiza primitivas
      glDisableClientState( GL_VERTEX_ARRAY );
      break;
    case 3:
      glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
      glEnableClientState( GL_VERTEX_ARRAY ); // habilitar array de vertices
      glVertexPointer( 3, GL_FLOAT, 0, &stlVertices[0]); // estable direccion y estructuras
      for(int i=0;i<stlCaras.size();i++){
          glColor3f(0.7,0.7,0.7*(i%2));    //Color Negro/AMARILLO
          glDrawElements(GL_TRIANGLES,3,GL_UNSIGNED_INT,&stlCaras[i]);  //Visualiza primitivas
        }
        glDisableClientState( GL_VERTEX_ARRAY );
      break;
    case 4: //revisar
      glEnable(GL_LIGHTING);
      glShadeModel(GL_FLAT); //caras es como solido

      if(normalVertices.size() != 0)
    		glEnableClientState( GL_NORMAL_ARRAY );

    	glEnableClientState( GL_VERTEX_ARRAY ); // habilitar array de vertices
    	if(stlTextura.size() != 0)
    		glEnableClientState( GL_TEXTURE_COORD_ARRAY );
    	if(normalVertices.size() != 0)
    			glNormalPointer(GL_FLOAT, 0, &normalVertices[0]);

    	if(stlTextura.size() != 0)
    		glTexCoordPointer( 2, GL_FLOAT, 0, &stlTextura[0] );

      glVertexPointer( 3, GL_FLOAT, 0, &stlVertices[0]); // estable direccion y estructuras
      //glColor3f(0.2,0,0.8);    //Color amarillo claro
      glDrawElements(GL_TRIANGLES,stlCaras.size()*3,GL_UNSIGNED_INT,&stlCaras[0]);
      if(stlTextura.size() != 0)
      		glDisableClientState( GL_TEXTURE_COORD_ARRAY );
    	if(normalVertices.size() != 0)
      		glDisableClientState( GL_NORMAL_ARRAY );
      	glDisableClientState( GL_VERTEX_ARRAY );
        break;
      case 5: //revisar
        glEnable(GL_LIGHTING);
        glShadeModel(GL_SMOOTH); //caras es como solido

        if(normalVertices.size() != 0)
          glEnableClientState( GL_NORMAL_ARRAY );
        glEnableClientState( GL_VERTEX_ARRAY ); // habilitar array de vertices
        if(stlTextura.size() != 0)
          glEnableClientState( GL_TEXTURE_COORD_ARRAY );

        if(normalVertices.size() != 0)
            glNormalPointer(GL_FLOAT, 0, &normalVertices[0]);

        if(stlTextura.size() != 0)
          glTexCoordPointer( 2, GL_FLOAT, 0, &stlTextura[0] );

        glVertexPointer( 3, GL_FLOAT, 0, &stlVertices[0]); // estable direccion y estructuras
        //glColor3f(0.2,0,0.8);    //Color amarillo claro
        glDrawElements(GL_TRIANGLES,stlCaras.size()*3,GL_UNSIGNED_INT,&stlCaras[0]);
        if(stlTextura.size() != 0)
            glDisableClientState( GL_TEXTURE_COORD_ARRAY );
        if(normalVertices.size() != 0)
            glDisableClientState( GL_NORMAL_ARRAY );
          glDisableClientState( GL_VERTEX_ARRAY );
          break;
      default:
      cerr<<" opcion de visualizacion Incorrecta"<<endl;
      break;
  }

}


    void MallaInd::calcularNormales(){
  Tupla3f p,q,r;
                                      //Calculo las normales a las caras
  for(int i=0;i<stlCaras.size();i++){
    p=stlVertices[stlCaras[i](1)]-stlVertices[stlCaras[i](0)];
    q=stlVertices[stlCaras[i](2)]-stlVertices[stlCaras[i](1)];
    r=Tupla3f(p(1)*q(2)-p(2)*q(1),p(2)*q(0)-p(0)*q(2),p(0)*q(1)-p(1)*q(0));
    if(r[0]!=0&&r[1]!=0&&r[2]!=0)
      normalCaras.push_back(r.normalized());
    else
      normalCaras.push_back(Tupla3f(p(1)*q(2)-p(2)*q(1),p(2)*q(0)-p(0)*q(2),p(0)*q(1)-p(1)*q(0)));
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
    normalVertices[stlCaras[i][0]]=normalVertices[stlCaras[i][0]]+normalCaras[i];
    normalVertices[stlCaras[i][1]]=normalVertices[stlCaras[i][1]]+normalCaras[i];
    normalVertices[stlCaras[i][2]]=normalVertices[stlCaras[i][2]]+normalCaras[i];
  }
  for(int i=0;i<normalVertices.size();i++){
    if(normalVertices[i][0]!=0&&normalVertices[i][1]!=0&&normalVertices[i][2]!=0)
      normalVertices[i]=normalVertices[i].normalized();
    else
      normalVertices[i]=normalVertices[i];// caso degenerados
    cerr<<"normalV "<<i<<": "<<normalVertices[i]<<endl;
  }
}
