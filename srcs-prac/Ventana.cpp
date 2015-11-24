#include "Ventana.hpp"

Ventana::Ventana(int n){

    agregar (MAT_Traslacion(0,0,0));
    cambiarColor(0);
    agregar (new MallaPLY("/Users/jopime/GitHub/InformaticaGrafica/plys/cuerpo.ply"));
    agregar(new Detalles());
    agregar (new Cabeza());
    agregar (new BrazoIzquierdo());
    agregar (new BrazoDerecho());
    agregar (new PiernaIzquierda());
    agregar (new PiernaDerecha());

    cerr<<endl<<"LLEGUE"<<endl;

}

void Ventana::Mov(float k){
  ((Cabeza *)(entradas[3].objeto))->Girar(k);
  ((BrazoIzquierdo *)(entradas[4].objeto))->Girar(k);
  ((BrazoDerecho *)(entradas[5].objeto))->Girar(-k);
  ((PiernaIzquierda *)(entradas[6].objeto))->Girar(-k);
  ((PiernaDerecha *)(entradas[7].objeto))->Girar(k);

}
void Ventana::Lanzar(float k){
  ((BrazoIzquierdo *)(entradas[4].objeto))->Tirar(k);
}
void Ventana::Tras(float k,float grado){
  *entradas[0].matriz= MAT_Traslacion(0,0,k/8);
  Mov(grado);
}
