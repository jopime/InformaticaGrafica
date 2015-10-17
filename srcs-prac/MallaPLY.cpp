#include "MallaPLY.hpp"

   MallaPLY::MallaPLY(const char * nombre_arch ){


   std::vector<float> vertices_ply ; // coordenadas de vértices
   std::vector<int>   caras_ply ;    // índices de vértices de triángulos
   ply::read( nombre_arch, vertices_ply, caras_ply );

   num_verts=vertices_ply.size()/3;
   num_caras=caras_ply.size()/3;
   nostlVertices = new Tupla3f[num_verts];
   nostlCaras = new Tupla3i[num_caras];

   for (int i=0;i<num_verts*3;i=i+3){
     nostlVertices[i/3]=Tupla3f(vertices_ply[i],vertices_ply[i+1],vertices_ply[i+2]);
   }
   for (int i=0;i<num_caras*3;i=i+3){
     nostlCaras[i/3]=Tupla3i(caras_ply[i],caras_ply[i+1],caras_ply[i+2]);
   }
 }
