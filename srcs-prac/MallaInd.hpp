#ifndef MALLAIND_HPP
  #define MALLAIND_HPP
#include "Objeto3D.hpp"
#include "aux.hpp"
#include <vector>
#include "tuplasg.hpp"

   // .....
   class MallaInd : public Objeto3D
   {
      // protected:
    public:
            // declarar aquí tablas de vértices y caras
            std::vector<Tupla3f> verticesC;
            int num_verts;
            Tupla3f *nostl=NULL;

        // ....
  //     public:
         MallaInd ();
         void visualizar( unsigned modo_vis ) ;   //borrado el parametro "virtual"
         void presentacion();
   } ;
#endif
