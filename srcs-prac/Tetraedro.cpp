#include "Tetraedro.hpp"
Tetraedro::Tetraedro(){
  nombre_obj="Tetraedro";
  num_verts=12;

Tupla3f a(0,2,0),c(-1,-1,1),d(1,-1,1),g(-1,-1,-1),h(1,-1,-1);

  nostl = new Tupla3f[num_verts];
  nostl[0]=c;  nostl[1]=d; nostl[2]=a;
  nostl[3]=a;  nostl[4]=c; nostl[5]=g;
  nostl[6]=g;  nostl[7]=h;  nostl[8]=a;
  nostl[9]=a;  nostl[10]=h; nostl[11]=d;
}
