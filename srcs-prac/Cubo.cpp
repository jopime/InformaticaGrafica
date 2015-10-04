#include "Cubo.hpp"
Cubo::Cubo(){
  nombre_obj="Cubo";
  num_verts=36;

Tupla3f a(-1,1,1),b(1,1,1),c(-1,-1,1),d(1,-1,1),
        e(-1,1,-1),f(1,1,-1),g(-1,-1,-1),h(1,-1,-1);

  nostl = new Tupla3f[num_verts];
  nostl[0]=a;  nostl[1]=b; nostl[2]=c;
  nostl[3]=c;  nostl[4]=d; nostl[5]=b;

  nostl[6]=b;  nostl[7]=f;  nostl[8]=d;
  nostl[9]=d;  nostl[10]=h; nostl[11]=f;

  nostl[12]=f; nostl[13]=e; nostl[14]=h;
  nostl[15]=h; nostl[16]=g; nostl[17]=e;

  nostl[18]=e; nostl[19]=f; nostl[20]=b;
  nostl[21]=b; nostl[22]=a; nostl[23]=e;

  nostl[24]=e; nostl[25]=g; nostl[26]=a;
  nostl[27]=a; nostl[28]=c; nostl[29]=g;

  nostl[30]=g; nostl[31]=h; nostl[32]=c;
  nostl[33]=c; nostl[34]=d; nostl[35]=h;

  //INTENTO CON VECTOR DE LA STL
  Tupla3f v1(1,-1,-1),v2(1,1,-1),v3(-1,1,-1),v4(-1,-1,-1),
          v5(1,-1,-1) ,v6(1,1,-1),v7(1,1,1),v8(1,-1,1),
          //Lado Trasero
          v9(1,-1,1),v10(1,1,1),v11(-1,1,1),v12(-1,-1,1),
          // LADO IZQUIERDO
           v13(-1,-1,1) ,v14(-1,1,1) ,v15(-1,1,-1),v16(-1,-1,-1) ,
           // LADO INFERIOR
            v17 (1,-1,-1) ,v18(1,-1,1) ,v19(-1,-1,1),v20(-1,-1,-1),
          // LADO SUPERIOR
          v21(-1,1,-1),v22(1,1,1),v23(1,1,-1) ,v24(-1,1,1);
  verticesC.push_back(v1);
  verticesC.push_back(v2);
  verticesC.push_back(v3);
  verticesC.push_back(v4);
  verticesC.push_back(v5);
  verticesC.push_back(v6);
  verticesC.push_back(v7);
  verticesC.push_back(v8);
  verticesC.push_back(v9);
  verticesC.push_back(v10);
  verticesC.push_back(v11);
  verticesC.push_back(v12);
  verticesC.push_back(v13);
  verticesC.push_back(v14);
  verticesC.push_back(v15);
  verticesC.push_back(v16);
  verticesC.push_back(v17);
  verticesC.push_back(v18);
  verticesC.push_back(v19);
  verticesC.push_back(v20);
  verticesC.push_back(v21);
  verticesC.push_back(v22);
  verticesC.push_back(v23);
  verticesC.push_back(v24);
}
