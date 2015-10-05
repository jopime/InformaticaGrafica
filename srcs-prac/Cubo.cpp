#include "Cubo.hpp"
Cubo::Cubo(){
  nombre_obj="Cubo";
  num_verts=8;
  num_caras=12;
Tupla3f a(-1,1,1),b(1,1,1),c(-1,-1,1),d(1,-1,1),
        e(-1,1,-1),f(1,1,-1),g(-1,-1,-1),h(1,-1,-1);

  nostlVertices = new Tupla3f[num_verts];
  nostlCaras = new Tupla3i[num_caras];


  nostlVertices[0]=a; nostlVertices[1]=b; nostlVertices[2]=c; nostlVertices[3]=d;
  nostlVertices[4]=e; nostlVertices[5]=f; nostlVertices[6]=g; nostlVertices[7]=h;

Tupla3i t1(0,1,2), t2(2,3,1),t3(1,5,3),t4(3,7,5),
        t5(5,4,7),t6(7,6,4),t7(4,5,1),t8(1,0,4),
        t9(6,7,2),t10(2,3,7),t11(4,6,0),t12(0,2,6);
  nostlCaras[0]=t1;nostlCaras[1]=t2;nostlCaras[2]=t3,nostlCaras[3]=t4,
  nostlCaras[4]=t5,nostlCaras[5]=t6,nostlCaras[7]=t8,nostlCaras[8]=t9,
  nostlCaras[9]=t10,nostlCaras[10]=t11,nostlCaras[11]=t12;
}
