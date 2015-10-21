#ifndef MALLAIND_HPP
  #define MALLAIND_HPP
  # define M_PI 3.14159265358979323846  /* pi */
#include "Objeto3D.hpp"
#include "aux.hpp"
#include <vector>
#include <math.h>
#include "tuplasg.hpp"

   // .....
   class MallaInd : public Objeto3D
   {
      // protected:
    public:
            // declarar aquí tablas de vértices y caras
            std::vector<Tupla3i> stlCaras;
            std::vector<Tupla3f> stlVertices;


        // ....
  //     public:
         MallaInd ();
         virtual void visualizar( unsigned modo_vis ) ;
         void presentacion();
   } ;
#endif
