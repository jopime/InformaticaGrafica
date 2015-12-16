#include "MallaPLY.hpp"

  MallaPLY::MallaPLY(const char * nombre_arch ){
    std::vector<float> vertices_ply ; // coordenadas de vértices
    std::vector<int>   caras_ply ;    // índices de vértices de triángulos
    ply::read( nombre_arch, vertices_ply, caras_ply );

    for (int i=0;i<vertices_ply.size();i=i+3){
     stlVertices.push_back(Tupla3f(vertices_ply[i],vertices_ply[i+1],vertices_ply[i+2]));
    }
    for (int i=0;i<caras_ply.size();i=i+3){
     stlCaras.push_back(Tupla3i(caras_ply[i],caras_ply[i+1],caras_ply[i+2]));
    }
  }
