#include "Cubo.hpp"
Cubo::Cubo(){
  nombre_obj="Cubo";

Tupla3f a(-1,1,1),b(1,1,1),c(-1,-1,1),d(1,-1,1),
        e(-1,1,-1),f(1,1,-1),g(-1,-1,-1),h(1,-1,-1);

  stlVertices.push_back(a); stlVertices.push_back(b); stlVertices.push_back(c); stlVertices.push_back(d);
  stlVertices.push_back(e); stlVertices.push_back(f); stlVertices.push_back(g); stlVertices.push_back(h);

Tupla3i t1(0,1,2), t2(2,3,1),t3(1,5,3),t4(3,7,5),
        t5(5,4,7),t6(7,6,4),t7(4,5,1),t8(1,0,4),
        t9(6,7,2),t10(2,3,7),t11(4,6,0),t12(0,2,6);
  stlCaras.push_back(t1);stlCaras.push_back(t2);stlCaras.push_back(t3),stlCaras.push_back(t4),
  stlCaras.push_back(t5),stlCaras.push_back(t6),stlCaras.push_back(t7),stlCaras.push_back(t8),
  stlCaras.push_back(t9),stlCaras.push_back(t10),stlCaras.push_back(t11),stlCaras.push_back(t12);
}
