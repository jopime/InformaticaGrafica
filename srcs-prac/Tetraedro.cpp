#include "Tetraedro.hpp"
Tetraedro::Tetraedro(){
  nombre_obj="Tetraedro";
  num_verts=5;
  num_caras=6;
Tupla3f a(0.866,0,-0.5),c(0,1.4142,0),d(0,0,1),g(-0.866,0,-0.5),h(0,0,0);

  nostlVertices = new Tupla3f[num_verts];
  nostlVertices[0]=a;  nostlVertices[1]=c; nostlVertices[2]=d; nostlVertices[3]=g;
  nostlVertices[4]=h;

  nostlCaras = new Tupla3i[num_caras];

  Tupla3i t1(0,1,2), t2(2,3,1),t3(1,3,0),
          t4(0,4,2),t5(2,3,4),t6(3,0,4);

  nostlCaras[0]=t1;nostlCaras[1]=t2;nostlCaras[4]=t3;
  nostlCaras[2]=t4;nostlCaras[3]=t5;nostlCaras[5]=t6;

}
