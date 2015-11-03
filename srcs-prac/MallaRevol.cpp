/*
/ Matriz de rotacion |cos @   0  -sin @ |
/ Respecto al eje Y  |0       1  0      |
/                    |sin @   0  cos @  |
/
/
*/
#include "MallaRevol.hpp"

   MallaRevol::MallaRevol(const char * nombre_arch , unsigned nperfiles){


     std::vector<float> vertices_ply ; // coordenadas de vértices
     ply::read_vertices( nombre_arch, vertices_ply );
     int tam = vertices_ply.size();
     int n=tam/3;

     for (int j=0;j<nperfiles;j++){
       for (int i=0;i<tam;i=i+3){
         stlVertices.push_back(Tupla3f(vertices_ply[i]*cos(2*M_PI*j/nperfiles),
         vertices_ply[i+1],vertices_ply[i]*sin(2*M_PI*j/nperfiles)));
       }
     }
     stlVertices.push_back(Tupla3f(0,vertices_ply[1],0));//primer Y(mas alto)
     stlVertices.push_back(Tupla3f(0,vertices_ply[tam-2],0)); //Ultimo Y(mas bajo)

// Inserccion de indices de cara

     for(int i=0;i<nperfiles-1;i++){
      stlCaras.push_back(Tupla3i(i*n,n*nperfiles,(i+1)*n));   // base inferior sin cerrar
     }
     stlCaras.push_back(Tupla3i(0,n*nperfiles,n*(nperfiles-1)));  //cierre base inferior

    for(int j=0;j<nperfiles-1;j++){
      for(int i=0;i<n-1;i++){
       stlCaras.push_back(Tupla3i(i+n*j,i+1+n*j,i+n*(j+1)));      // caras laterales sin la ultima (cierre)
       stlCaras.push_back(Tupla3i(i+n*(j+1),i+1+n*(j+1),i+1+n*j));
      }
   }

   for(int i=0;i<n-1;i++){
    stlCaras.push_back(Tupla3i(i+n*(nperfiles-1),i+1+n*(nperfiles-1),i));
    stlCaras.push_back(Tupla3i(i,i+1,i+1+n*(nperfiles-1)));               //Cierre de la ultima cara lateral
  }

  for (int i=0;i<nperfiles-1;i++){
    stlCaras.push_back(Tupla3i(n-1+i*n,n*nperfiles+1,(n-1)+(i+1)*n)); // base superior sin cerrar
  }
  stlCaras.push_back(Tupla3i(n-1+(nperfiles-1)*n,n*nperfiles+1,(n-1)));

}
