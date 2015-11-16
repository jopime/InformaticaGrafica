  #ifndef NODOGRAFOESCENA_HPP
  #define NODOGRAFOESCENA_HPP
    #include "Objeto3D.hpp"
    #include "aux.hpp"
    #include <vector>
    #include <math.h>
    #include "tuplasg.hpp"
    #include "matrices-tr.hpp"
    #include "Cubo.hpp"
    #include "Tetraedro.hpp"
    #include "Cilindro.hpp"
    #include "Cubo.hpp"


  class NodoGrafoEscena : public Objeto3D {
    protected:

     //Entrada del nodo del Grafo de Escena
     struct EntradaNGE{
      unsigned char tipoE ;
      // 0=objeto, 1=transformacion
      union{
        Objeto3D * objeto ; // ptr. a un objeto (propietario)
        Matriz4f * matriz ; // ptr. a matriz 4x4 transf. (prop.)
      };
      // constructores (uno por tipo)
        EntradaNGE( Objeto3D * pObjeto ){
            tipoE=0;
            objeto=pObjeto;

        } // (copia solo puntero)
        EntradaNGE( const Matriz4f & pMatriz ){
          tipoE=1;
          matriz=new Matriz4f(pMatriz);
        }; // (crea copia) ￼ ￼ ￼ ￼ ￼
        EntradaNGE( EntradaNGE * pEntrada){
          tipoE=pEntrada->tipoE;
          if (tipoE==1)
            matriz=pEntrada->matriz;
          else
            objeto=pEntrada->objeto;
        };
      };
      std::vector<EntradaNGE> entradas ; // vector de entradas
    public:
                                                  // visualiza usando OpenGL
      virtual void visualizar( unsigned cv ) ;
                                                  // añadir una entrada (al final).
      void agregar( Objeto3D * objeto );          // objeto3D
      void agregar( const Matriz4f & pMatriz );    //Matriz
      void agregar( EntradaNGE * entrada ){
          entradas.push_back(EntradaNGE(entrada));
      };       // Generica

};

#endif
