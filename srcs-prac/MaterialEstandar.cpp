#include "MATERIALESTANDAR.hpp"



void MaterialEstandar::activar(){

    glMaterialfv( GL_FRONT_AND_BACK, GL_EMISSION,  this->color[0] );
    glMaterialfv( GL_FRONT_AND_BACK, GL_AMBIENT,   this->color[1] );
    glMaterialfv( GL_FRONT_AND_BACK, GL_DIFFUSE,   this->color[2] );
    glMaterialfv( GL_FRONT_AND_BACK, GL_SPECULAR,  this->color[3] );
    glMaterialf( GL_FRONT_AND_BACK, GL_SHININESS, exponente ) ;

    if( text!=NULL ){
        glTexImage2D(GL_TEXTURE_2D,0,3,text->img->tamX(),text->img->tamY(),0,GL_RGB,GL_UNSIGNED_BYTE,text->img->leerPixels());
        glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
        glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
        /*
        glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
        glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
*/
        text->Activar();
        glDisable(GL_COLOR_MATERIAL);
    }
    else{
        glDisable( GL_TEXTURE_2D );
    }

}

bool MaterialEstandar::hayTextura(){
    return this->text != NULL;
}
