#include "Toro.hpp"
Toro::Toro(){
  nombre_obj="Toro";
  int n=100;
  int m=100;
  num_verts=m*n;
  num_caras=n*m*2;

  nostlVertices = new Tupla3f[num_verts];
  nostlCaras = new Tupla3i[num_caras];

  for (int i=0;i<m;i++){   //Numero de circunferencias
    for(int j=0;j<n;j++){  //Numero de puntos por circu
        nostlVertices[n*i+j]=Tupla3f(cos(2*i*M_PI/m)*(2.5+cos(2*j*M_PI/n)),
      sin(2*i*M_PI/m)*(2.5+cos(2*j*M_PI/n)),sin(2*j*M_PI/n));
    }
}
  for(int j=0;j<m-1;j++){
    for (int i=0;i<n-1;i++){
      nostlCaras[i+j*n*2]=Tupla3i(i+j*n,i+1+j*n,n+i+j*n);
      nostlCaras[i+n-1+j*n*2]=Tupla3i(n+i+j*n,n+i+1+j*n,i+1+j*n);
    }
      nostlCaras[2*(n-1)+j*n*2]=Tupla3i(n-1+j*n,0+j*n,2*n-1+j*n);
      nostlCaras[2*n-1+j*n*2]=Tupla3i(2*n-1+j*n,n+j*n,0+j*n);
    }
    for(int i=0;i<n-1;i++){
      nostlCaras[num_caras-1-i]=Tupla3i(i,i+1,(m-1)*n+i);
      nostlCaras[num_caras-1-i-n]=Tupla3i((m-1)*n+i,i+1,(m-1)*n+i+1);
    }
    nostlCaras[num_caras-n-1]=Tupla3i(0,n-1,num_verts-1);
    nostlCaras[num_caras-1]=Tupla3i(num_verts-1,0,2);
}
