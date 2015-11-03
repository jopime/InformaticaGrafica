#include "Tetraedro.hpp"
/*
//       c
//      / \
//     /   \
//    /  d  \
//   /   h   \
//  g____|____a
/
*/
Tetraedro::Tetraedro(){
  nombre_obj="Tetraedro";

Tupla3f a(0.866,0,-0.5),c(0,1.4142,0),d(0,0,1),g(-0.866,0,-0.5),h(0,0,0);

  stlVertices.push_back(a);  stlVertices.push_back(c); stlVertices.push_back(d); stlVertices.push_back(g);
  stlVertices.push_back(h);

  Tupla3i t1(0,1,2), t2(2,3,1),t3(1,3,0),
          t4(0,4,2),t5(2,3,4),t6(3,0,4);

  stlCaras.push_back(t1);stlCaras.push_back(t2);stlCaras.push_back(t3);
  stlCaras.push_back(t4);stlCaras.push_back(t5);stlCaras.push_back(t6);

}
