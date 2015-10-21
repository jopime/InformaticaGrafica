#ifndef MALLABARRIDO_HPP
  #define MALLABARRIDO_HPP
  #include "MallaInd.hpp"
  #include "file_ply_stl.hpp"
  // clase mallas indexadas obtenidas de un archivo PLY
  class MallaBarrido : public MallaInd
  {
     public:
        // constructor
        // se debe especificar el nombre completo del archivo a leer
        //Se indica el vector (x,y,z) por el cual se traslada el contorno cerrado
        MallaBarrido(const char * nombre_arch ,float x,float y, float z, unsigned ntraslaciones) ;
  } ;
#endif
