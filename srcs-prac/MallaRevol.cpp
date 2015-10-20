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
     num_verts=tam/3*nperfiles;
     num_caras=18;
     nostlVertices = new Tupla3f[num_verts];
     nostlCaras = new Tupla3i[num_caras];
     /*
     /  FALTA METER LOS PUNTOS TRAS APLICAR LA ENESIMA PARTE DEL GIRO SOBRE LOS VERTICES
     /
     */

     for (int n=0;n<nperfiles;n++){
       for (int i=0;i<30;i=i+3){
         nostlVertices[n*10+(i/3)]=Tupla3f(vertices_ply[i],
         vertices_ply[i+1],vertices_ply[i]);
       }
     }

     for(int i=0;i<9;i++){
       nostlCaras[i]=Tupla3i(i,tam/3-1+i,i+1);
       nostlCaras[i+9]=Tupla3i(tam/3+i-1,tam/3+i,i+1);
     }
    // nostlCaras[8]=Tupla3i(18,19,9);
}
