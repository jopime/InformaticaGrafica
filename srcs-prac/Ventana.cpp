#include "Ventana.hpp"

Ventana::Ventana(int n){

    agregar (MAT_Traslacion(0,0,0));
    agregar (new MallaPLY("/Users/jopime/GitHub/InformaticaGrafica/plys/cuerpoColor.ply"));
    agregar (new MallaPLY("/Users/jopime/GitHub/InformaticaGrafica/plys/Logo.ply"));
    agregar (new Cabeza());
    agregar (new BrazoIzquierdo());
    agregar (new BrazoDerecho());
    agregar (new PiernaIzquierda());
    agregar (new PiernaDerecha());
    agregar(new MallaPLY("/Users/jopime/GitHub/InformaticaGrafica/plys/Arma.ply"));


    cerr<<endl<<"LLEGUE"<<endl;

}
void Ventana::Mov(float k){
  ((Cabeza *)(entradas[3].objeto))->Girar(k);
  ((BrazoIzquierdo *)(entradas[4].objeto))->Girar(k);
  ((BrazoDerecho *)(entradas[5].objeto))->Girar(k);

}
void Ventana::Tras(float k){
  *entradas[0].matriz= MAT_Traslacion(k,2,0);
  Mov(k*10);
}
