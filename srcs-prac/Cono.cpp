#include "Cono.hpp"
Cono::Cono(unsigned n){
  //DEFINIDO PARA N>1
  nombre_obj="Cono";
  num_verts=n+1;
  num_caras=n;
  nostlVertices = new Tupla3f[num_verts];
  nostlCaras = new Tupla3i[num_caras];

  nostlVertices[0]=Tupla3f(0,2,0);
  for (int i=1;i<num_verts;i++){
    nostlVertices[i]=Tupla3f(cos(2*i*M_PI/n),0,sin(2*i*M_PI/n));
  }
  nostlCaras[0]=Tupla3i(num_caras,0,1);
  for (int i=1;i<num_caras;i++){
    nostlCaras[i]=Tupla3i(i,0,i+1);
  }


}
