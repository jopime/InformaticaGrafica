#include "Cono.hpp"
Cono::Cono(unsigned n){
  //DEFINIDO PARA N>1
  nombre_obj="Cono";
  num_verts=n+2;
  num_caras=2*n;
  nostlVertices = new Tupla3f[num_verts];
  nostlCaras = new Tupla3i[num_caras];

  nostlVertices[0]=Tupla3f(0,2,0);  //Vertice punta cono
  nostlVertices[1]=Tupla3f(0,0,0);  //vertice centro base
  for (int i=2;i<num_verts;i++){
    nostlVertices[i]=Tupla3f(cos(2*i*M_PI/n),0,sin(2*i*M_PI/n));
  }
  nostlCaras[0]=Tupla3i(n+1,0,2);
  nostlCaras[n]=Tupla3i(n+1,1,2);

  for (int i=1;i<n;i++){
    nostlCaras[i]=Tupla3i(i+1,0,i+2);
    nostlCaras[i+n]=Tupla3i(i+1,1,i+2);
  }

}
