void drawScene(void)
{
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
   glLoadIdentity();

   glEnable(GL_LIGHT0);
      

   /* ------------------------------------ TRANSFORMAÇÕES -------------------------------------- */
   glTranslatef(0.0, 0.0, -10.0); //  0.0 0.0 0.0
   glTranslatef(0.0 + transX , -50.0, 0.0 + transZ );
   glScalef(20.0, 20.0, 1.0); 
   

   /* ------------------------------------ DEFINIÇÃO DO OBSERVADOR ------------------------------------ */

   gluLookAt( 0.33 * cos(angleBeta) * cos(angleAlpha), 0.33 * sin(angleBeta), 0.33 * cos(angleBeta) * sin(angleAlpha), 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);


   /* --------------------------------------    OBJETOS:  ------------------------------------------ */

   /* ------------------------------------------------------------
                  DESENHO PAREDES     
   --------------------------------------------------------------*/

   glPushMatrix();
   glTranslatef(0.0, 0.0, 0.0);

   glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, paredes_matAmbAndDif);
   glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, paredes_matSpec);
   glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, paredes_matShine);
   
   glNormalPointer(GL_FLOAT, 0, paredes_normais);
   glVertexPointer(3, GL_FLOAT, 0,  paredes_vertices);
   glDrawElements(GL_TRIANGLES, paredes_num_faces * 3, GL_UNSIGNED_INT, paredes_faces);
   glPopMatrix();

   /* ------------------------------------------------------------
                  DESENHO PISO     
   --------------------------------------------------------------*/

   glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, piso_matAmbAndDif);
   glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, piso_matSpec);
   glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, piso_matShine);
   
   glNormalPointer(GL_FLOAT, 0, piso_normais);
   glVertexPointer(3, GL_FLOAT, 0,  piso_vertices);
   glDrawElements(GL_TRIANGLES, piso_num_faces * 3, GL_UNSIGNED_INT, piso_faces);

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
                  DESENHO ALMOFADAS SOFA    
   --------------------------------------------------------------*/

   glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, almofadas_sofa_matAmbAndDif);
   glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, almofadas_sofa_matSpec);
   glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, almofadas_sofa_matShine);
   
   glVertexPointer(3, GL_FLOAT, 0, almofadas_sofa_vertices);
   glNormalPointer(GL_FLOAT, 0, almofadas_sofa_normais);
   glDrawElements(GL_TRIANGLES, almofadas_sofa_num_faces * 3, GL_UNSIGNED_INT, almofadas_sofa_faces);

   /* ------------------------------------------------------------
                  DESENHO POLTRONA   
   --------------------------------------------------------------*/

   glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, poltrona_matAmbAndDif);
   glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, poltrona_matSpec);
   glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, poltrona_matShine);
   
   glVertexPointer(3, GL_FLOAT, 0, poltrona_vertices);
   glNormalPointer(GL_FLOAT, 0, poltrona_normais);
   glDrawElements(GL_TRIANGLES, poltrona_num_faces * 3, GL_UNSIGNED_INT, poltrona_faces);

   /* ------------------------------------------------------------
                  DESENHO ALMOFADAS POLTRONA   
   --------------------------------------------------------------*/
   
   glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, almofadas_poltrona_matAmbAndDif);
   glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, almofadas_poltrona_matSpec);
   glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, almofadas_poltrona_matShine);
   
   glVertexPointer(3, GL_FLOAT, 0, almofadas_poltrona_vertices);
   glNormalPointer(GL_FLOAT, 0, almofadas_poltrona_normais);
   glDrawElements(GL_TRIANGLES, almofadas_poltrona_num_faces * 3, GL_UNSIGNED_INT, almofadas_poltrona_faces);

   /* ------------------------------------------------------------
                  DESENHO MESAS   
   --------------------------------------------------------------*/
   
   glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, mesas_matAmbAndDif);
   glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mesas_matSpec);
   glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mesas_matShine);
   
   glVertexPointer(3, GL_FLOAT, 0, mesas_vertices);
   glNormalPointer(GL_FLOAT, 0, mesas_normais);
   glDrawElements(GL_TRIANGLES, mesas_num_faces * 3, GL_UNSIGNED_INT, mesas_faces);

   /* ------------------------------------------------------------
                  DESENHO ABAJUR   
   --------------------------------------------------------------*/
   
   glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, abajur_matAmbAndDif);
   glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, abajur_matSpec);
   glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, abajur_matShine);
   
   glVertexPointer(3, GL_FLOAT, 0, abajur_vertices);
   glNormalPointer(GL_FLOAT, 0, abajur_normais);
   glDrawElements(GL_TRIANGLES, abajur_num_faces * 3, GL_UNSIGNED_INT, abajur_faces);

   /* ------------------------------------------------------------
                  DESENHO ABAJUR SUPORTE   
   --------------------------------------------------------------*/
   
   glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, abajur_suporte_matAmbAndDif);
   glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, abajur_suporte_matSpec);
   glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, abajur_suporte_matShine);
   
   glVertexPointer(3, GL_FLOAT, 0, abajur_suporte_vertices);
   glNormalPointer(GL_FLOAT, 0, abajur_suporte_normais);
   glDrawElements(GL_TRIANGLES, abajur_suporte_num_faces * 3, GL_UNSIGNED_INT, abajur_suporte_faces);

   /* ------------------------------------------------------------
                  DESENHO ARMARIO   
   --------------------------------------------------------------*/
   
   glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, armario_matAmbAndDif);
   glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, armario_matSpec);
   glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, armario_matShine);
   
   glVertexPointer(3, GL_FLOAT, 0, armario_vertices);
   glNormalPointer(GL_FLOAT, 0, armario_normais);
   glDrawElements(GL_TRIANGLES, armario_num_faces * 3, GL_UNSIGNED_INT, armario_faces);

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

   /* ---------------------------------------------------------------------- */

   glFlush();
   glutSwapBuffers();
}