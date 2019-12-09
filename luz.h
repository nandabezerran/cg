void iluminacao(void)
{

/* Declaração das luzes */

   GLfloat luzAmbiente[4]={0.2, 0.2, 0.2, 1.0};          // "ambiente"
   GLfloat luzDifusa[4]={0.7, 0.7, 0.7, 1.0};            // "cor" 
   GLfloat luzEspecular[4]={1.0, 1.0, 1.0, 1.0};     // "brilho" 
  
   // Capacidade de brilho do material
   GLfloat especularidade[4]={1.0,1.0,1.0,1.0}; 
   GLint especMaterial = 60;
 
   // Define a refletância do material 
   glMaterialfv(GL_FRONT,GL_SPECULAR, especularidade);

   // Define a concentração do brilho
   glMateriali(GL_FRONT,GL_SHININESS,especMaterial);
 
   // Ativa o uso da luz ambiente 
   glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);
 
   // Define os parâmetros da luz de número 0 - Direcional
   GLfloat posicaoLuz[4]={5.0, 4.0, 5.0, 0.0};
   
   GLfloat luz1Ambiente[4] = {0.0,0.0,0.0,0.0};

   if(intensidade_luz1 == 1){
       luz1Ambiente[0] = 1.0;
       luz1Ambiente[1] = 1.0;
       luz1Ambiente[2] = 1.0;
       luz1Ambiente[3] = 1.0;
   }else if(intensidade_luz1 == 2){
       luz1Ambiente[0] = 0.5;
       luz1Ambiente[1] = 0.5;
       luz1Ambiente[2] = 0.5;
       luz1Ambiente[3] = 1.0;
   }else{
       luz1Ambiente[0] = 0.2;
       luz1Ambiente[1] = 0.2;
       luz1Ambiente[2] = 0.2;
       luz1Ambiente[3] = 1.0;
   }
   glLightfv(GL_LIGHT0, GL_AMBIENT, luz1Ambiente); 
   glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa );
   glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular );
   glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz );   

   // Define os parâmetros da luz de número 1 - Spotlight
   float spot_luz1 = 20;
   GLfloat luzAmbiente_luz1[4]={1, 1, 1, 1.0};
   GLfloat posicao_luz1 [] = {-3.0, 3.5, -3.0, 1};
   GLfloat direcao_luz1 [] = {0.0,-1.0,0.0};

   glLightfv(GL_LIGHT1, GL_AMBIENT, luzAmbiente_luz1);
   glLightfv(GL_LIGHT1, GL_DIFFUSE, luzDifusa );
   glLightfv(GL_LIGHT1, GL_SPECULAR, luzEspecular );
   glLightf (GL_LIGHT1, GL_SPOT_CUTOFF, spot_luz1);
   glLightfv(GL_LIGHT1, GL_POSITION, posicao_luz1);
   glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, direcao_luz1);

   // Define os parâmetros da luz de número 2 - Pontual
   GLfloat posicao_luz2[4]={2.980465, 1.5, -4.55, 1.0};
   GLfloat luzAmbiente_luz2[4]={0.2, 0.2, 0.2, 1.0};
   glLightfv(GL_LIGHT2, GL_AMBIENT, luzAmbiente_luz2); 
   glLightfv(GL_LIGHT2, GL_DIFFUSE, luzDifusa );
   glLightfv(GL_LIGHT2, GL_SPECULAR, luzEspecular );
   glLightfv(GL_LIGHT2, GL_POSITION, posicao_luz2 );   
   
}