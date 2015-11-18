#include "Cara.hpp"
Cara::Cara(){
  agregar (MAT_Traslacion(0,-0.5,1));
  agregar (MAT_Escalado(0.2,0.1,0.1));
  agregar (new Cubo());
}
