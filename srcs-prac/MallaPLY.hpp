#ifndef MALLAPLY_HPP
  #define MALLAPLY_HPP
  #include "MallaInd.hpp"
  #include "file_ply_stl.hpp"
  // clase mallas indexadas obtenidas de un archivo PLY
  class MallaPLY : public MallaInd
  {
     public:
        // constructor
        // se debe especificar el nombre completo del archivo a leer
        MallaPLY(const char * nombre_arch ) ;
  } ;
#endif
