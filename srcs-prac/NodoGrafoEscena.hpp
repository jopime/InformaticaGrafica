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
    #include "MallaPly.hpp"
    #include "MallaRevol.hpp"
    #include "Material.hpp"

    #include "MaterialEstandar.hpp"


  class NodoGrafoEscena : public Objeto3D {
    protected:

     //Entrada del nodo del Grafo de Escena
     struct EntradaNGE{
      unsigned char tipoE ;
      // 0=objeto, 1=transformacion, 2=material Abstracto
      union{
        Objeto3D * objeto ; // ptr. a un objeto (propietario)
        Matriz4f * matriz ; // ptr. a matriz 4x4 transf. (prop.)
        Material * material; // ptr. a material Abstracto
      };
      // constructores (uno por tipo)
        EntradaNGE( Objeto3D * pObjeto ){
            tipoE=0;
            objeto=pObjeto;

        } // (copia solo puntero)

        EntradaNGE( Material * pMaterial ){
            tipoE=2;
            material=pMaterial;

        } // (copia solo puntero)

        EntradaNGE( const Matriz4f & pMatriz ){
          tipoE=1;
          matriz=new Matriz4f(pMatriz);
        }; // (crea copia)

        EntradaNGE( EntradaNGE * pEntrada){
          tipoE=pEntrada->tipoE;
          if (tipoE==1){
            matriz=pEntrada->matriz;}
          else if(tipoE==0){
            objeto=pEntrada->objeto;}
          else {
            material=pEntrada->material;}
        };
      };
      std::vector<EntradaNGE> entradas ; // vector de entradas
      Material * materialActual=NULL;
      int color;
    public:
                                                  // visualiza usando OpenGL
      virtual void visualizar( unsigned cv ) ;
                                                  // añadir una entrada (al final).
      void agregar( Objeto3D * objeto );          // objeto3D
      void agregar( Material * material );          // Material
      void agregar( const Matriz4f & pMatriz );    //Matriz
      void agregar( EntradaNGE * entrada ){
          entradas.push_back(EntradaNGE(entrada));
      };       // Generica
      void cambiarColor(int n){color=n;
        //  cerr<<"color Cambiado a "<<color;
      };
};

#endif
