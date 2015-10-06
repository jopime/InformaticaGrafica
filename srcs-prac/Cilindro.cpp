#include "Cilindro.hpp"
Cilindro::Cilindro(unsigned n){
  //DEFINIDO PARA N>3
  nombre_obj="Cilindro";
  num_verts=n*2;
  num_caras=2*n;
  nostlVertices = new Tupla3f[num_verts];
  nostlCaras = new Tupla3i[num_caras];

  for (int i=0;i<n;i++){
    nostlVertices[i]=Tupla3f(cos(2*i*M_PI/n),-1,sin(2*i*M_PI/n));
    nostlVertices[i+n]=Tupla3f(cos(2*i*M_PI/n),1,sin(2*i*M_PI/n));
  }
  for (int i=0;i<n-1;i++){
    nostlCaras[i]=Tupla3i(i,n+i,i+1);
    nostlCaras[i+n]=Tupla3i(i+1,n+i,n+1+i);
  }
  nostlCaras[n-1]=Tupla3i(n-1,num_caras-1,0);
  nostlCaras[2*n-1]=Tupla3i(0,n,num_caras-1);

}
