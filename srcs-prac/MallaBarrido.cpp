#include "MallaBarrido.hpp"

   MallaBarrido::MallaBarrido(const char * nombre_arch ,float x,float y,float z, unsigned ntraslaciones){


   std::vector<float> vertices_ply ; // coordenadas de vértices
   ply::read_vertices( nombre_arch, vertices_ply);
   int tam = vertices_ply.size();
   int n=tam/3;

   for (int j=0;j<=ntraslaciones;j++){
     for (int i=0;i<tam;i=i+3){
       stlVertices.push_back(Tupla3f(vertices_ply[i]+x*j/ntraslaciones,
         vertices_ply[i+1]+y*j/ntraslaciones,vertices_ply[i+2]+z*j/ntraslaciones));
     }
   }

   for(int j=0;j<ntraslaciones;j++){
     for(int i=0;i<n-1;i++){
      stlCaras.push_back(Tupla3i(i+n*j,i+1+n*j,i+n*(j+1)));
      stlCaras.push_back(Tupla3i(i+n*(j+1),i+1+n*(j+1),i+1+n*j));
     }
     stlCaras.push_back(Tupla3i(j*n+n-1,j*n,j*n+n));
     stlCaras.push_back(Tupla3i(j*n+n,n-1+n*(j+1),j*n+n-1));
  }


}
