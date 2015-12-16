#include "FUENTELUZ.hpp"


void FuenteLuz::activar(int i){
  colores.push_back(Tupla4f(1,0,0,0));
  colores.push_back(Tupla4f(0,1,0,0));
  colores.push_back(Tupla4f(0,0,1,1));
  switch (i) {
    case 0:
      glEnable(GL_LIGHT0);
      break;
    case 1:
      glEnable(GL_LIGHT1);
      break;
    case 2:
      glEnable(GL_LIGHT2);
      break;
    case 3:
      glEnable(GL_LIGHT3);
      break;
    case 4:
      glEnable(GL_LIGHT4);
      break;
    case 5:
      glEnable(GL_LIGHT5);
      break;
    case 6:
      glEnable(GL_LIGHT6);
      break;
    case 7:
      glEnable(GL_LIGHT7);
      break;
    default:
      cerr<<endl<<"no activacion de luz por parametro erroneo"<<endl;

  }
}
