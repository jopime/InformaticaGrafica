#include "Toro.hpp"
Toro::Toro(){
  nombre_obj="Toro";
  int n=100;    // numero de puntos por circunferencia
  int m=100;  //numero de anillos

  for (int i=0;i<m;i++){   //Numero de circunferencias
    for(int j=0;j<n;j++){  //Numero de puntos por circu
        stlVertices.push_back(Tupla3f(cos(2*i*M_PI/m)*(2.5+cos(2*j*M_PI/n)),
      sin(2*i*M_PI/m)*(2.5+cos(2*j*M_PI/n)),sin(2*j*M_PI/n)));
    }
}
// Insercion de indices de caras

  for(int j=0;j<m-1;j++){                                   // Cada iteracion es un anillo
    for (int i=0;i<n-1;i++){
      stlCaras.push_back(Tupla3i(i+j*n,i+1+j*n,n+i+j*n)); //media dentadura inferior sin cerrar
    }
      stlCaras.push_back(Tupla3i(n-1+j*n,0+j*n,2*n-1+j*n)); // cierre dentadura inferior

    for (int i=0;i<n-1;i++){
        stlCaras.push_back(Tupla3i(n+i+j*n,n+i+1+j*n,i+1+j*n)); //media dentadura superior sin cerrar
      }
      stlCaras.push_back(Tupla3i(2*n-1+j*n,n+j*n,0+j*n));       // cierre dentadura inferior
    }

//  ULTIMO ANILLO

    for(int i=0;i<n-1;i++){
      stlCaras.push_back(Tupla3i((m-1)*n+i,i+1,(m-1)*n+i+1));   //dentadura inferior sin cerrar
    }
    stlCaras.push_back(Tupla3i(0,n-1,stlVertices.size()-1));    //cierre dentadura inferior
    for(int i=0;i<n-1;i++){
      stlCaras.push_back(Tupla3i(i,i+1,(m-1)*n+i));             // dentadura superior sin cerrar
    }
    stlCaras.push_back(Tupla3i(stlVertices.size()-1,0,2));      // cierre dentadura superior

}
