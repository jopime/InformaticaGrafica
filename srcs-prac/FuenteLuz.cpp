#include "FUENTELUZ.hpp"


void FuenteLuz::activar(int i){
  colores.push_back(Tupla4f(1,0,0,1));
  colores.push_back(Tupla4f(0,1,0,1));
  colores.push_back(Tupla4f(0,0,1,1));
  switch (i) {
    case 0:
      glEnable(GL_LIGHT0);
      glLightfv( GL_LIGHT0, GL_AMBIENT, colores[0] ) ;
      glLightfv( GL_LIGHT0, GL_DIFFUSE, colores[1] ) ;
      glLightfv( GL_LIGHT0, GL_SPECULAR, colores[2] ) ;
      if(posvec(3)){
        const GLfloat posf[4] = {posvec(0),posvec(1),posvec(2)};
        glLightfv( GL_LIGHT0, GL_POSITION, posf ) ;
      }
      else{
        const GLfloat dirf[4] = {posvec(0),posvec(1),posvec(2)};
        glLightfv( GL_LIGHT0, GL_POSITION, dirf ) ;
      }

      break;
    case 1:
      glEnable(GL_LIGHT1);
      glLightfv( GL_LIGHT1, GL_AMBIENT, colores[0] ) ;
      glLightfv( GL_LIGHT1, GL_DIFFUSE, colores[1] ) ;
      glLightfv( GL_LIGHT1, GL_SPECULAR, colores[2] ) ;
      if(posvec(3)){
        const GLfloat posf[4] = {posvec(0),posvec(1),posvec(2)};
        glLightfv( GL_LIGHT1, GL_POSITION, posf ) ;
      }
      else{
        const GLfloat dirf[4] = {posvec(0),posvec(1),posvec(2)};
        glLightfv( GL_LIGHT1, GL_POSITION, dirf ) ;
      }
      break;
    case 2:
      glEnable(GL_LIGHT2);
      glLightfv( GL_LIGHT2, GL_AMBIENT, colores[0] ) ;
      glLightfv( GL_LIGHT2, GL_DIFFUSE, colores[1] ) ;
      glLightfv( GL_LIGHT2, GL_SPECULAR, colores[2] ) ;
      if(posvec(3)){
        const GLfloat posf[4] = {posvec(0),posvec(1),posvec(2)};
        glLightfv( GL_LIGHT2, GL_POSITION, posf ) ;
      }
      else{
        const GLfloat dirf[4] = {posvec(0),posvec(1),posvec(2)};
        glLightfv( GL_LIGHT2, GL_POSITION, dirf ) ;
      }      break;
    case 3:
      glEnable(GL_LIGHT3);
      glLightfv( GL_LIGHT3, GL_AMBIENT, colores[0] ) ;
      glLightfv( GL_LIGHT3, GL_DIFFUSE, colores[1] ) ;
      glLightfv( GL_LIGHT3, GL_SPECULAR, colores[2] ) ;
      if(posvec(3)){
        const GLfloat posf[4] = {posvec(0),posvec(1),posvec(2)};
        glLightfv( GL_LIGHT3, GL_POSITION, posf ) ;
      }
      else{
        const GLfloat dirf[4] = {posvec(0),posvec(1),posvec(2)};
        glLightfv( GL_LIGHT3, GL_POSITION, dirf ) ;
      }      break;
    case 4:
      glEnable(GL_LIGHT4);
      glLightfv( GL_LIGHT4, GL_AMBIENT, colores[0] ) ;
      glLightfv( GL_LIGHT4, GL_DIFFUSE, colores[1] ) ;
      glLightfv( GL_LIGHT4, GL_SPECULAR, colores[2] ) ;
      if(posvec(3)){
        const GLfloat posf[4] = {posvec(0),posvec(1),posvec(2)};
        glLightfv( GL_LIGHT4, GL_POSITION, posf ) ;
      }
      else{
        const GLfloat dirf[4] = {posvec(0),posvec(1),posvec(2)};
        glLightfv( GL_LIGHT4, GL_POSITION, dirf ) ;
      }      break;
    case 5:
      glEnable(GL_LIGHT5);
      glLightfv( GL_LIGHT5, GL_AMBIENT, colores[0] ) ;
      glLightfv( GL_LIGHT5, GL_DIFFUSE, colores[1] ) ;
      glLightfv( GL_LIGHT5, GL_SPECULAR, colores[2] ) ;
      if(posvec(3)){
        const GLfloat posf[4] = {posvec(0),posvec(1),posvec(2)};
        glLightfv( GL_LIGHT5, GL_POSITION, posf ) ;
      }
      else{
        const GLfloat dirf[4] = {posvec(0),posvec(1),posvec(2)};
        glLightfv( GL_LIGHT5, GL_POSITION, dirf ) ;
      }      break;
    case 6:
      glEnable(GL_LIGHT6);
      glLightfv( GL_LIGHT6, GL_AMBIENT, colores[0] ) ;
      glLightfv( GL_LIGHT6, GL_DIFFUSE, colores[1] ) ;
      glLightfv( GL_LIGHT6, GL_SPECULAR, colores[2] ) ;
      if(posvec(3)){
        const GLfloat posf[4] = {posvec(0),posvec(1),posvec(2)};
        glLightfv( GL_LIGHT6, GL_POSITION, posf ) ;
      }
      else{
        const GLfloat dirf[4] = {posvec(0),posvec(1),posvec(2)};
        glLightfv( GL_LIGHT6, GL_POSITION, dirf ) ;
      }      break;
    case 7:
      glEnable(GL_LIGHT7);
      glLightfv( GL_LIGHT7, GL_AMBIENT, colores[0] ) ;
      glLightfv( GL_LIGHT7, GL_DIFFUSE, colores[1] ) ;
      glLightfv( GL_LIGHT7, GL_SPECULAR, colores[2] ) ;
      if(posvec(3)){
        const GLfloat posf[4] = {posvec(0),posvec(1),posvec(2)};
        glLightfv( GL_LIGHT7, GL_POSITION, posf ) ;
      }
      else{
        const GLfloat dirf[4] = {posvec(0),posvec(1),posvec(2)};
        glLightfv( GL_LIGHT7, GL_POSITION, dirf ) ;
      }      break;
    default:
      cerr<<endl<<"no activacion de luz por parametro erroneo"<<endl;

  }
}
