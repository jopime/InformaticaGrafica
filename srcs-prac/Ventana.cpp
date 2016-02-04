#include "Ventana.hpp"

Ventana::Ventana(int n){
    cambiarColor(0);
    agregar(new MaterialMadera());

    agregar (MAT_Escalado(1,1,1));
    agregar (MAT_Traslacion(0,0,0));
    agregar (new MallaPLY("./cuerpo.ply"));
    agregar(new Detalles());
    agregar(new MaterialNegro());
    agregar (new Cabeza());
    agregar(new MaterialMadera());
    agregar (new BrazoIzquierdo());
    agregar (new BrazoDerecho());
    agregar (new PiernaIzquierda());
    agregar (new PiernaDerecha());
}
Ventana::Ventana(){

  agregar(new MaterialBlanco());
  agregar (new MallaRevol("./peon.ply",100,false));

agregar (MAT_Traslacion(2,0,0));
agregar(new MaterialMadera());
agregar (new MallaRevol("./peon.ply",100));

agregar (MAT_Traslacion(2,0,0));
agregar(new MaterialNegro());
agregar (new MallaRevol("./peon.ply",100,false));

agregar (MAT_Traslacion(-8,1,0));
agregar (MAT_Escalado(5,5,5));

agregar(new MaterialLataPcuerpo());
agregar (new MallaRevol("./lata-pcue.ply",100));

agregar(new MaterialTapasLata());

agregar (new MallaRevol("./lata-pinf.ply",100));
agregar (MAT_Traslacion(0,0.02,0));

agregar (new MallaRevol("./lata-psup.ply",100));

}
void Ventana::Desplazarse(float k){
  *entradas[2].matriz= MAT_Traslacion(0,0,k/8);
}
void Ventana::Girar(int k){
  ((Cabeza *)(entradas[6].objeto))->Girar(k);
  ((BrazoIzquierdo *)(entradas[8].objeto))->Girar(k);
  ((BrazoDerecho *)(entradas[9].objeto))->Girar(-k);
  ((PiernaIzquierda *)(entradas[10].objeto))->Girar(-k);
  ((PiernaDerecha *)(entradas[11].objeto))->Girar(k);
}
void Ventana::Agrandar(float k){
  *entradas[1].matriz= MAT_Escalado(1,k,k);
}
