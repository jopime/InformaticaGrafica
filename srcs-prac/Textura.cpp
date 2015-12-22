#include "TEXTURA.hpp"


Textura::Textura(string archivoJPG, unsigned mgct, float cs[4], float ct[4])
{
   assert (mgct == 0 || mgct == 1 || mgct == 2);
   this->img = new jpg::Imagen(archivoJPG.c_str());
   this->mgct = mgct;

   for (unsigned i = 0; i < 4; i++)
   {
      this->cs[i] = cs[i];
      this->ct[i] = ct[i];
   }

   glGenTextures(1, &id_text);
   glBindTexture(GL_TEXTURE_2D, id_text);
   // Crear mipmaps de textura
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
   glTexParameteri(GL_TEXTURE_2D, GL_GENERATE_MIPMAP, GL_TRUE);
   glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->tamX(), img->tamY(), 0, GL_RGB, GL_UNSIGNED_BYTE, img->leerPixels());
   // Generar texturas

   //--------------------
   glBindTexture(GL_TEXTURE_2D, 0);
}

bool Textura::Activar()
{
   glBindTexture(GL_TEXTURE_2D, id_text);

   if (mgct == 0)
   {
      glDisable(GL_TEXTURE_GEN_S);
      glDisable(GL_TEXTURE_GEN_T);
      return true;
   }
   else if (mgct == 1)
   {
      glEnable(GL_TEXTURE_GEN_S);
      glEnable(GL_TEXTURE_GEN_T);

      glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
      glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);

      glTexGenfv(GL_S, GL_OBJECT_PLANE, cs);
      glTexGenfv(GL_T, GL_OBJECT_PLANE, ct);

      return false;
   }

   else
   {
      glEnable(GL_TEXTURE_GEN_S);
      glEnable(GL_TEXTURE_GEN_T);

      glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_EYE_LINEAR);
      glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_EYE_LINEAR);

      glTexGenfv(GL_S, GL_EYE_PLANE, cs);
      glTexGenfv(GL_T, GL_EYE_PLANE, ct);

      return false;
   }

}
