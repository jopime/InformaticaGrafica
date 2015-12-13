#include "Ventana.hpp"

Ventana::Ventana(int n){
    cambiarColor(0);

    agregar (MAT_Escalado(1,1,1));
    agregar (MAT_Traslacion(0,0,0));
    agregar (new MallaPLY("/Users/jopime/GitHub/InformaticaGrafica/plys/cuerpo.ply"));
    agregar(new Detalles());
    agregar (new Cabeza());
    agregar (new BrazoIzquierdo());
    agregar (new BrazoDerecho());
    agregar (new PiernaIzquierda());
    agregar (new PiernaDerecha());
}
void Ventana::Desplazarse(float k){
  *entradas[1].matriz= MAT_Traslacion(0,0,k/8);
}
void Ventana::Girar(int k){
  ((Cabeza *)(entradas[4].objeto))->Girar(k);
  ((BrazoIzquierdo *)(entradas[5].objeto))->Girar(k);
  ((BrazoDerecho *)(entradas[6].objeto))->Girar(-k);
  ((PiernaIzquierda *)(entradas[7].objeto))->Girar(-k);
  ((PiernaDerecha *)(entradas[8].objeto))->Girar(k);
}
void Ventana::Agrandar(int k){
  *entradas[0].matriz= MAT_Escalado(1,k,k);
  //((BrazoIzquierdo *)(entradas[4].objeto))->Agrandar(k);
}

/*
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
*/
