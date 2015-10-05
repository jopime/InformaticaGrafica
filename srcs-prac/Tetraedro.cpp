#include "Tetraedro.hpp"
Tetraedro::Tetraedro(){
  nombre_obj="Tetraedro";
  num_verts=4;
  num_caras=3;
Tupla3f a(0.866,0,-0.5),c(0,1.4142,0),d(0,0,1),g(-0.866,0,-0.5);

  nostlVertices = new Tupla3f[num_verts];
  nostlVertices[0]=a;  nostlVertices[1]=c; nostlVertices[2]=d; nostlVertices[3]=g;

  nostlCaras = new Tupla3i[num_caras];

  Tupla3i t1(0,1,2), t2(2,3,1),t3(1,3,0);

  nostlCaras[0]=t1;nostlCaras[1]=t2;nostlCaras[2]=t3;

}
