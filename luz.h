void iluminacao(void)
{

   /* Declaração das luzes */

   GLfloat luzAmbiente[4]={0.2, 0.2, 0.2, 1.0}; 
   GLfloat luzDifusa[4]={0.7, 0.7, 0.7, 1.0};            // "cor" 
   GLfloat luzEspecular[4]={1.0, 1.0, 1.0, 1.0};     // "brilho" 
   GLfloat posicaoLuz[4]={0.0, 50.0, 50.0, 1.0};

   // Capacidade de brilho do material
   GLfloat especularidade[4]={1.0,1.0,1.0,1.0}; 
   GLint especMaterial = 60;
 
   // Define a refletância do material 
   glMaterialfv(GL_FRONT,GL_SPECULAR, especularidade);
   // Define a concentração do brilho
   glMateriali(GL_FRONT,GL_SHININESS,especMaterial);
 
   // Ativa o uso da luz ambiente 
   glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);
 
   // Define os parâmetros da luz de número 0
   glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente); 
   glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa );
   glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular );
   glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz );   

}