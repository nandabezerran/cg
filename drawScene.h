#include "./luz.h"

void drawScene(void)
{
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
   glLoadIdentity();
      
   /* ------------------------------------ TRANSFORMAÇÕES -------------------------------------- */
   glTranslatef(0.0 + transX, -50.0, -15.0 + transZ);
   glScalef(16.0, 20.0, 1.0); 
   
   /* ------------------------------------ DEFINIÇÃO DO OBSERVADOR ------------------------------------ */

   gluLookAt( 0.33 * cos(angleBeta) * cos(angleAlpha), 0.33 * sin(angleBeta), 0.33 * cos(angleBeta) * sin(angleAlpha), 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);


   /* -------------------------------------- LUZES------------------------------------------ */

   iluminacao();
   
   // Habilita a luz de número 0 - Direcional
   if(show_direcional){
      glEnable(GL_LIGHT0);
   }
   else{
      glDisable(GL_LIGHT0);
   }
   
   //Habilita a luz de número 1 - Pontual   
   if(show_pontual){

      glEnable(GL_LIGHT1);
   }
   else{
      glDisable(GL_LIGHT1);
   }

   //Habilita a luz de número 2 - SpotLight
   if(show_spot){
      glEnable(GL_LIGHT2);
   }
   else{
      glDisable(GL_LIGHT2);
   }


   /* --------------------------------------OBJETOS------------------------------------------ */


   if(show_sofas){

   /* ------------------------------------------------------------
                  DESENHO SOFA     
   --------------------------------------------------------------*/
   
   glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, sofa_matAmbAndDif);
   glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, sofa_matSpec);
   glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, sofa_matShine);
   
   glVertexPointer(3, GL_FLOAT, 0, sofa_vertices);
   glNormalPointer(GL_FLOAT, 0, sofa_normais);
   glDrawElements(GL_TRIANGLES, sofa_num_faces * 3, GL_UNSIGNED_INT, sofa_faces);

   /* ------------------------------------------------------------
                  DESENHO POLTRONA   
   --------------------------------------------------------------*/

   glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, poltrona_matAmbAndDif);
   glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, poltrona_matSpec);
   glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, poltrona_matShine);
   
   glVertexPointer(3, GL_FLOAT, 0, poltrona_vertices);
   glNormalPointer(GL_FLOAT, 0, poltrona_normais);
   glDrawElements(GL_TRIANGLES, poltrona_num_faces * 3, GL_UNSIGNED_INT, poltrona_faces);

   }

   if(show_almofadas){

   /* ------------------------------------------------------------
                  DESENHO ALMOFADAS SOFA    
   --------------------------------------------------------------*/

   glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, almofadas_sofa_matAmbAndDif);
   glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, almofadas_sofa_matSpec);
   glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, almofadas_sofa_matShine);
   
   glVertexPointer(3, GL_FLOAT, 0, almofadas_sofa_vertices);
   glNormalPointer(GL_FLOAT, 0, almofadas_sofa_normais);
   glDrawElements(GL_TRIANGLES, almofadas_sofa_num_faces * 3, GL_UNSIGNED_INT, almofadas_sofa_faces);

   /* ------------------------------------------------------------
                  DESENHO ALMOFADAS POLTRONA   
   --------------------------------------------------------------*/
   
   glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, almofadas_poltrona_matAmbAndDif);
   glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, almofadas_poltrona_matSpec);
   glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, almofadas_poltrona_matShine);
   
   glVertexPointer(3, GL_FLOAT, 0, almofadas_poltrona_vertices);
   glNormalPointer(GL_FLOAT, 0, almofadas_poltrona_normais);
   glDrawElements(GL_TRIANGLES, almofadas_poltrona_num_faces * 3, GL_UNSIGNED_INT, almofadas_poltrona_faces);

   }

   if(show_travesseiros){
   /* ------------------------------------------------------------
                  DESENHO TRAVESSEIRO 1  
   --------------------------------------------------------------*/
   
   glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, travesseiro1_matAmbAndDif);
   glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, travesseiro1_matSpec);
   glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, travesseiro1_matShine);
   
   glVertexPointer(3, GL_FLOAT, 0, travesseiro1_vertices);
   glNormalPointer(GL_FLOAT, 0, travesseiro1_normais);
   glDrawElements(GL_TRIANGLES, travesseiro1_num_faces * 3, GL_UNSIGNED_INT, travesseiro1_faces);

   /* ------------------------------------------------------------
                  DESENHO TRAVESSEIRO 2  
   --------------------------------------------------------------*/
   
   glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, travesseiro2_matAmbAndDif);
   glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, travesseiro2_matSpec);
   glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, travesseiro2_matShine);
   
   glVertexPointer(3, GL_FLOAT, 0, travesseiro2_vertices);
   glNormalPointer(GL_FLOAT, 0, travesseiro2_normais);
   glDrawElements(GL_TRIANGLES, travesseiro2_num_faces * 3, GL_UNSIGNED_INT, travesseiro2_faces);

   /* ------------------------------------------------------------
                  DESENHO TRAVESSEIRO 3  
   --------------------------------------------------------------*/
   
   glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, travesseiro3_matAmbAndDif);
   glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, travesseiro3_matSpec);
   glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, travesseiro3_matShine);
   
   glVertexPointer(3, GL_FLOAT, 0, travesseiro3_vertices);
   glNormalPointer(GL_FLOAT, 0, travesseiro3_normais);
   glDrawElements(GL_TRIANGLES, travesseiro3_num_faces * 3, GL_UNSIGNED_INT, travesseiro3_faces);

   /* ------------------------------------------------------------
                  DESENHO TRAVESSEIRO 4  
   --------------------------------------------------------------*/
   
   glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, travesseiro4_matAmbAndDif);
   glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, travesseiro4_matSpec);
   glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, travesseiro4_matShine);
   
   glVertexPointer(3, GL_FLOAT, 0, travesseiro4_vertices);
   glNormalPointer(GL_FLOAT, 0, travesseiro4_normais);
   glDrawElements(GL_TRIANGLES, travesseiro4_num_faces * 3, GL_UNSIGNED_INT, travesseiro4_faces);

   }

   if(show_mesas){

   /* ------------------------------------------------------------
                  DESENHO MESAS   
   --------------------------------------------------------------*/
   
   glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, mesas_matAmbAndDif);
   glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mesas_matSpec);
   glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mesas_matShine);
   
   glVertexPointer(3, GL_FLOAT, 0, mesas_vertices);
   glNormalPointer(GL_FLOAT, 0, mesas_normais);
   glDrawElements(GL_TRIANGLES, mesas_num_faces * 3, GL_UNSIGNED_INT, mesas_faces);

   }

   if(show_abajur){

   /* ------------------------------------------------------------
                  DESENHO ABAJUR   
   --------------------------------------------------------------*/
   
   glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, abajur_matAmbAndDif);
   glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, abajur_matSpec);
   glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, abajur_matShine);
   
   glVertexPointer(3, GL_FLOAT, 0, abajur_vertices);
   glNormalPointer(GL_FLOAT, 0, abajur_normais);
   glDrawElements(GL_TRIANGLES, abajur_num_faces * 3, GL_UNSIGNED_INT, abajur_faces);

   }

   if(show_suporte){

   /* ------------------------------------------------------------
                  DESENHO ABAJUR SUPORTE   
   --------------------------------------------------------------*/
   
   glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, abajur_suporte_matAmbAndDif);
   glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, abajur_suporte_matSpec);
   glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, abajur_suporte_matShine);
   
   glVertexPointer(3, GL_FLOAT, 0, abajur_suporte_vertices);
   glNormalPointer(GL_FLOAT, 0, abajur_suporte_normais);
   glDrawElements(GL_TRIANGLES, abajur_suporte_num_faces * 3, GL_UNSIGNED_INT, abajur_suporte_faces);

   }

   if(show_armario){

   /* ------------------------------------------------------------
                  DESENHO ARMARIO   
   --------------------------------------------------------------*/
   
   glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, armario_matAmbAndDif);
   glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, armario_matSpec);
   glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, armario_matShine);
   
   glVertexPointer(3, GL_FLOAT, 0, armario_vertices);
   glNormalPointer(GL_FLOAT, 0, armario_normais);
   glDrawElements(GL_TRIANGLES, armario_num_faces * 3, GL_UNSIGNED_INT, armario_faces);

   }

   if(show_gavetas){

   /* ------------------------------------------------------------
                  DESENHO ARMARIO GAVETAS   
   --------------------------------------------------------------*/
   
   glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, armario_gavetas_matAmbAndDif);
   glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, armario_gavetas_matSpec);
   glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, armario_gavetas_matShine);
   
   glVertexPointer(3, GL_FLOAT, 0, armario_gavetas_vertices);
   glNormalPointer(GL_FLOAT, 0, armario_gavetas_normais);
   glDrawElements(GL_TRIANGLES, armario_gavetas_num_faces * 3, GL_UNSIGNED_INT, armario_gavetas_faces);

   /* ------------------------------------------------------------
                  DESENHO ARMARIO PUXADORES   
   --------------------------------------------------------------*/
   
   glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, armario_puxadores_matAmbAndDif);
   glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, armario_puxadores_matSpec);
   glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, armario_puxadores_matShine);
   
   glVertexPointer(3, GL_FLOAT, 0, armario_puxadores_vertices);
   glNormalPointer(GL_FLOAT, 0, armario_puxadores_normais);
   glDrawElements(GL_TRIANGLES, armario_puxadores_num_faces * 3, GL_UNSIGNED_INT, armario_puxadores_faces);

   }

   if(show_arvore){

   /* ------------------------------------------------------------
                  DESENHO ARVORE   
   --------------------------------------------------------------*/
   
   glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, arvore_matAmbAndDif);
   glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, arvore_matSpec);
   glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, arvore_matShine);
   
   glVertexPointer(3, GL_FLOAT, 0, arvore_vertices);
   glNormalPointer(GL_FLOAT, 0, arvore_normais);
   glDrawElements(GL_TRIANGLES, arvore_num_faces * 3, GL_UNSIGNED_INT, arvore_faces);

   /* ------------------------------------------------------------
                  DESENHO ARVORE ENFEITE
   --------------------------------------------------------------*/
   
   glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, arvore_enfeites_matAmbAndDif);
   glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, arvore_enfeites_matSpec);
   glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, arvore_enfeites_matShine);
   
   glVertexPointer(3, GL_FLOAT, 0, arvore_enfeites_vertices);
   glNormalPointer(GL_FLOAT, 0, arvore_enfeites_normais);
   glDrawElements(GL_TRIANGLES, arvore_enfeites_num_faces * 3, GL_UNSIGNED_INT, arvore_enfeites_faces);

   /* ------------------------------------------------------------
                  DESENHO ARVORE TRONCO   
   --------------------------------------------------------------*/
   
   glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, arvore_tronco_matAmbAndDif);
   glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, arvore_tronco_matSpec);
   glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, arvore_tronco_matShine);
   
   glVertexPointer(3, GL_FLOAT, 0, arvore_tronco_vertices);
   glNormalPointer(GL_FLOAT, 0, arvore_tronco_normais);
   glDrawElements(GL_TRIANGLES, arvore_tronco_num_faces * 3, GL_UNSIGNED_INT, arvore_tronco_faces);

   }

   if(show_vaso){

   /* ------------------------------------------------------------
                  DESENHO ARVORE VASO   
   --------------------------------------------------------------*/
   
   glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, arvore_vaso_matAmbAndDif);
   glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, arvore_vaso_matSpec);
   glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, arvore_vaso_matShine);
   
   glVertexPointer(3, GL_FLOAT, 0, arvore_vaso_vertices);
   glNormalPointer(GL_FLOAT, 0, arvore_vaso_normais);
   glDrawElements(GL_TRIANGLES, arvore_vaso_num_faces * 3, GL_UNSIGNED_INT, arvore_vaso_faces);

   }

   if(show_estantes){

   /* ------------------------------------------------------------
                  DESENHO ESTANTES  
   --------------------------------------------------------------*/
   
   glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, estantes_matAmbAndDif);
   glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, estantes_matSpec);
   glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, estantes_matShine);
   
   glVertexPointer(3, GL_FLOAT, 0, estantes_vertices);
   glNormalPointer(GL_FLOAT, 0, estantes_normais);
   glDrawElements(GL_TRIANGLES, estantes_num_faces * 3, GL_UNSIGNED_INT, estantes_faces);

   }

   if(show_livros){

   /* ------------------------------------------------------------
                  DESENHO LIVRO 1  
   --------------------------------------------------------------*/
   
   glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, livro1_matAmbAndDif);
   glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, livro1_matSpec);
   glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, livro1_matShine);
   
   glVertexPointer(3, GL_FLOAT, 0, livro1_vertices);
   glNormalPointer(GL_FLOAT, 0, livro1_normais);
   glDrawElements(GL_TRIANGLES, livro1_num_faces * 3, GL_UNSIGNED_INT, livro1_faces);

   /* ------------------------------------------------------------
                  DESENHO LIVRO 2  
   --------------------------------------------------------------*/
   
   glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, livro2_matAmbAndDif);
   glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, livro2_matSpec);
   glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, livro2_matShine);
   
   glVertexPointer(3, GL_FLOAT, 0, livro2_vertices);
   glNormalPointer(GL_FLOAT, 0, livro2_normais);
   glDrawElements(GL_TRIANGLES, livro2_num_faces * 3, GL_UNSIGNED_INT, livro2_faces);

   /* ------------------------------------------------------------
                  DESENHO LIVRO 3  
   --------------------------------------------------------------*/
   
   glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, livro3_matAmbAndDif);
   glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, livro3_matSpec);
   glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, livro3_matShine);
   
   glVertexPointer(3, GL_FLOAT, 0, livro3_vertices);
   glNormalPointer(GL_FLOAT, 0, livro3_normais);
   glDrawElements(GL_TRIANGLES, livro3_num_faces * 3, GL_UNSIGNED_INT, livro3_faces);

   /* ------------------------------------------------------------
                  DESENHO FOLHAS  
   --------------------------------------------------------------*/
   
   glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, folhas_matAmbAndDif);
   glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, folhas_matSpec);
   glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, folhas_matShine);
   
   glVertexPointer(3, GL_FLOAT, 0, folhas_vertices);
   glNormalPointer(GL_FLOAT, 0, folhas_normais);
   glDrawElements(GL_TRIANGLES, folhas_num_faces * 3, GL_UNSIGNED_INT, folhas_faces);

   }

   if(show_relogio){

   /* ------------------------------------------------------------
                  DESENHO RELOGIO  
   --------------------------------------------------------------*/
   
   glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, relogio_matAmbAndDif);
   glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, relogio_matSpec);
   glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, relogio_matShine);
   
   glVertexPointer(3, GL_FLOAT, 0, relogio_vertices);
   glNormalPointer(GL_FLOAT, 0, relogio_normais);
   glDrawElements(GL_TRIANGLES, relogio_num_faces * 3, GL_UNSIGNED_INT, relogio_faces);

   /* ------------------------------------------------------------
                  DESENHO RELOGIO FUNDO  
   --------------------------------------------------------------*/
   
   glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, relogio_fundo_matAmbAndDif);
   glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, relogio_fundo_matSpec);
   glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, relogio_fundo_matShine);
   
   glVertexPointer(3, GL_FLOAT, 0, relogio_fundo_vertices);
   glNormalPointer(GL_FLOAT, 0, relogio_fundo_normais);
   glDrawElements(GL_TRIANGLES, relogio_fundo_num_faces * 3, GL_UNSIGNED_INT, relogio_fundo_faces);

   }

   if(show_quadros){

   /* ------------------------------------------------------------
                  DESENHO QUADROS 1 
   --------------------------------------------------------------*/
   
   glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, quadros1_matAmbAndDif);
   glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, quadros1_matSpec);
   glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, quadros1_matShine);
   
   glVertexPointer(3, GL_FLOAT, 0, quadros1_vertices);
   glNormalPointer(GL_FLOAT, 0, quadros1_normais);
   glDrawElements(GL_TRIANGLES, quadros1_num_faces * 3, GL_UNSIGNED_INT, quadros1_faces);

   /* ------------------------------------------------------------
                  DESENHO QUADROS 2 
   --------------------------------------------------------------*/
   
   glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, quadros2_matAmbAndDif);
   glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, quadros2_matSpec);
   glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, quadros2_matShine);
   
   glVertexPointer(3, GL_FLOAT, 0, quadros2_vertices);
   glNormalPointer(GL_FLOAT, 0, quadros2_normais);
   glDrawElements(GL_TRIANGLES, quadros2_num_faces * 3, GL_UNSIGNED_INT, quadros2_faces);

   }

   if(show_molduras){

   /* ------------------------------------------------------------
                  DESENHO QUADROS FUNDOS 
   --------------------------------------------------------------*/
   
   glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, quadros_fundos_matAmbAndDif);
   glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, quadros_fundos_matSpec);
   glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, quadros_fundos_matShine);
   
   glVertexPointer(3, GL_FLOAT, 0, quadros_fundos_vertices);
   glNormalPointer(GL_FLOAT, 0, quadros_fundos_normais);
   glDrawElements(GL_TRIANGLES, quadros_fundos_num_faces * 3, GL_UNSIGNED_INT, quadros_fundos_faces);


   /* ------------------------------------------------------------
                  DESENHO QUADROS MOLDURAS 
   --------------------------------------------------------------*/
   
   glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, quadros_molduras_matAmbAndDif);
   glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, quadros_molduras_matSpec);
   glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, quadros_molduras_matShine);
   
   glVertexPointer(3, GL_FLOAT, 0, quadros_molduras_vertices);
   glNormalPointer(GL_FLOAT, 0, quadros_molduras_normais);
   glDrawElements(GL_TRIANGLES, quadros_molduras_num_faces * 3, GL_UNSIGNED_INT, quadros_molduras_faces);

   }

   if(show_piso){

   /* ------------------------------------------------------------
                  DESENHO PISO     
   --------------------------------------------------------------*/

   glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, piso_matAmbAndDif);
   glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, piso_matSpec);
   glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, piso_matShine);
   
   glNormalPointer(GL_FLOAT, 0, piso_normais);
   glVertexPointer(3, GL_FLOAT, 0,  piso_vertices);
   glDrawElements(GL_TRIANGLES, piso_num_faces * 3, GL_UNSIGNED_INT, piso_faces);

   }

   if(show_paredes){

   /* ------------------------------------------------------------
                  DESENHO PAREDES     
   --------------------------------------------------------------*/

   glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, paredes_matAmbAndDif);
   glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, paredes_matSpec);
   glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, paredes_matShine);
   
   glNormalPointer(GL_FLOAT, 0, paredes_normais);
   glVertexPointer(3, GL_FLOAT, 0,  paredes_vertices);
   glDrawElements(GL_TRIANGLES, paredes_num_faces * 3, GL_UNSIGNED_INT, paredes_faces);

   }

   /* ---------------------------------------------------------------------- */
   
   /*
   glColor3f(1.0, 1.0, 1.0);
   glPointSize(20);
   glBegin(GL_POINTS);
   glVertex3f(2.980465, 1.5, -4.55);
   glEnd();
   */

   
   glutSwapBuffers();
}