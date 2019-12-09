void iluminacao(void){

  /* Declaração das luzes */
  GLfloat luzAmbiente[4]={0.2, 0.2, 0.2, 1.0};         // "ambiente"
  GLfloat luzDifusa[4]={0.7, 0.7, 0.7, 1.0};          // "cor" 
  GLfloat luzEspecular[4]={1.0, 1.0, 1.0, 1.0};      // "brilho" 
  
  // Capacidade de brilho do material
  GLfloat especularidade[4]={1.0,1.0,1.0,1.0}; 
  GLint especMaterial = 60;
 
  // Define a refletância do material 
  glMaterialfv(GL_FRONT,GL_SPECULAR, especularidade);

  // Define a concentração do brilho
  glMateriali(GL_FRONT,GL_SHININESS,especMaterial);
 
  // Ativa o uso da luz ambiente 
  glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);
 
  // ------------------------------------------------------------------DIRECIONAL------------------------------------------------------------------
  
  //--------Intensidade--------

  GLfloat direcionalAmbiente[4] = {0.0,0.0,0.0,0.0};

  if(intensidade_direcional == 1){
    direcionalAmbiente[0] = 0.2;
    direcionalAmbiente[1] = 0.2;
    direcionalAmbiente[2] = 0.2;
    direcionalAmbiente[3] = 1.0;
  }
  
  else if(intensidade_direcional == 2){
    direcionalAmbiente[0] = 0.5;
    direcionalAmbiente[1] = 0.5;
    direcionalAmbiente[2] = 0.5;
    direcionalAmbiente[3] = 1.0;
  }
  
  else{
    direcionalAmbiente[0] = 1.0;
    direcionalAmbiente[1] = 1.0;
    direcionalAmbiente[2] = 1.0;
    direcionalAmbiente[3] = 1.0; 
  }


  //--------Posicao--------

  GLfloat direcionalPosicao[4]={5.0, 4.0, 5.0, 0.0};






  //--------Atribuicao--------

  glLightfv(GL_LIGHT0, GL_AMBIENT, direcionalAmbiente); 
  glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa );
  glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular );

  glLightfv(GL_LIGHT0, GL_POSITION, direcionalPosicao );  



  // ------------------------------------------------------------------SPOT------------------------------------------------------------------


  //--------Intensidade--------

  GLfloat spotAmbiente[4] = {0.0,0.0,0.0,0.0}; 

  if(intensidade_spot == 1){
    spotAmbiente[0] = 0.2;
    spotAmbiente[1] = 0.2;
    spotAmbiente[2] = 0.2;
    spotAmbiente[3] = 1.0;
  }
  
  else if(intensidade_spot == 2){
    spotAmbiente[0] = 0.5;
    spotAmbiente[1] = 0.5;
    spotAmbiente[2] = 0.5;
    spotAmbiente[3] = 1.0;
  }
  
  else{
    spotAmbiente[0] = 1.0;
    spotAmbiente[1] = 1.0;
    spotAmbiente[2] = 1.0;
    spotAmbiente[3] = 1.0; 
  }


  //--------Posicao--------

  GLfloat spotPosicao [] = {-3.0, 3.5, -3.0, 1};


  //--------Direcao--------

  GLfloat spotDirecao [] = {0.0,-1.0,0.0};


  //--------Angulo--------

  float spotAngulo = 20;



  //--------Atribuicao--------

  glLightfv(GL_LIGHT1, GL_AMBIENT, spotAmbiente);
  glLightfv(GL_LIGHT1, GL_DIFFUSE, luzDifusa );
  glLightfv(GL_LIGHT1, GL_SPECULAR, luzEspecular );

  glLightfv(GL_LIGHT1, GL_POSITION, spotPosicao);
  glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, spotDirecao);
  glLightf (GL_LIGHT1, GL_SPOT_CUTOFF, spotAngulo);


  // ------------------------------------------------------------------PONTUAL------------------------------------------------------------------

  //--------Intensidade--------

  GLfloat pontualAmbiente[4]={0.2, 0.2, 0.2, 1.0};

  if(intensidade_pontual == 1){
    pontualAmbiente[0] = 0.2;
    pontualAmbiente[1] = 0.2;
    pontualAmbiente[2] = 0.2;
    pontualAmbiente[3] = 1.0;
  }
  
  else if(intensidade_pontual == 2){
    pontualAmbiente[0] = 0.5;
    pontualAmbiente[1] = 0.5;
    pontualAmbiente[2] = 0.5;
    pontualAmbiente[3] = 1.0;
  }
  
  else{
    pontualAmbiente[0] = 1.0;
    pontualAmbiente[1] = 1.0;
    pontualAmbiente[2] = 1.0;
    pontualAmbiente[3] = 1.0; 
  }


  //--------Posicao--------

  GLfloat pontualPosicao[4]={2.980465, 1.5, -4.55, 1.0};



  //--------Atribuicao--------

  glLightfv(GL_LIGHT2, GL_AMBIENT, pontualAmbiente); 
  glLightfv(GL_LIGHT2, GL_DIFFUSE, luzDifusa );
  glLightfv(GL_LIGHT2, GL_SPECULAR, luzEspecular );

  glLightfv(GL_LIGHT2, GL_POSITION, pontualPosicao );
  
}