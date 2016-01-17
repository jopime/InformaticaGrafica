#ifndef TEXTURA_HPP
  #define TEXTURA_HPP
  #include <iostream>
  #include <string>
  #include "aux.hpp"

  #include "jpg_imagen.hpp"

  using namespace std ;

class Textura
{
  public:
   GLuint        id_text ;    // identificador OpenGL de la textura
   jpg::Imagen * img ;        // puntero a imagen con los texels
   unsigned      mgct ;       // modo de gen. cc.tt. (0 = desactivado, 1 = objeto, 2 = camara)
   float         cs[4],ct[4]; // coeficientes para generación de coords. de textura

   bool Activar();          // activa textura en el cauce fijo de OpenGL
   Textura(string archivoJPG, unsigned modo_generacion_coordenadas_textura, float cs[4], float ct[4]) ; // crea un textura a partir de un archivo
};

#endif
