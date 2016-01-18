#include "TEXTURA.hpp"

  void Textura::Activar(){
    glEnable(GL_TEXTURE_2D);
  }

Textura::Textura(string archivoJPG)
{
  img=new jpg::Imagen(archivoJPG);
}
