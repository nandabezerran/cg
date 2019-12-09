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

  GLfloat direcionalAmbiente[4];

  if(intensidade_direcional == 0){
    direcionalAmbiente[0] = 0.25;
    direcionalAmbiente[1] = 0.25;
    direcionalAmbiente[2] = 0.25;
    direcionalAmbiente[3] = 1.0;
  }
  
  else if(intensidade_direcional == 1){
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

  GLfloat direcionalPosicao[4];


  if(posicao_direcional == 0){

    direcionalPosicao[0] =  5.0;
    direcionalPosicao[1] =  4.0;
    direcionalPosicao[2] =  5.0;
    direcionalPosicao[3] =  0.0;


  }

  else if(posicao_direcional == 1){
    
    direcionalPosicao[0] = -5.0;
    direcionalPosicao[1] =  4.0;
    direcionalPosicao[2] =  5.0;
    direcionalPosicao[3] =  0.0;

  }

  else{
  
    direcionalPosicao[0] =  5.0;
    direcionalPosicao[1] =  4.0;
    direcionalPosicao[2] = -5.0;
    direcionalPosicao[3] =  0.0;
    
  }


  //--------Atribuicao--------

  glLightfv(GL_LIGHT0, GL_AMBIENT, direcionalAmbiente); 
  glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa );
  glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular );

  glLightfv(GL_LIGHT0, GL_POSITION, direcionalPosicao );  



  // ------------------------------------------------------------------PONTUAL------------------------------------------------------------------

  //--------Intensidade--------

  GLfloat pontualAmbiente[4];

  if(intensidade_pontual == 0){
    pontualAmbiente[0] = 0.2;
    pontualAmbiente[1] = 0.2;
    pontualAmbiente[2] = 0.2;
    pontualAmbiente[3] = 1.0;
  }
  
  else if(intensidade_pontual == 1){
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

  GLfloat pontualPosicao[4];

  if(posicao_pontual == 0){

    pontualPosicao[0] =   2.980465;
    pontualPosicao[1] =   1.5;
    pontualPosicao[2] = -4.55;
    pontualPosicao[3] =   1.0;


  }

  else if(posicao_pontual == 1){
    
    pontualPosicao[0] = -2.980465;
    pontualPosicao[1] =   1.5;
    pontualPosicao[2] = -4.55;
    pontualPosicao[3] =   1.0;

  }

  else{
  
    pontualPosicao[0] =   2.980465;
    pontualPosicao[1] =  -1.5;
    pontualPosicao[2] = -4.55;
    pontualPosicao[3] =   1.0;
    
  }

  //--------Atribuicao--------

  glLightfv(GL_LIGHT1, GL_AMBIENT, pontualAmbiente); 
  glLightfv(GL_LIGHT1, GL_DIFFUSE, luzDifusa );
  glLightfv(GL_LIGHT1, GL_SPECULAR, luzEspecular );

  glLightfv(GL_LIGHT1, GL_POSITION, pontualPosicao );


  // ------------------------------------------------------------------SPOT------------------------------------------------------------------


  //--------Intensidade--------

  GLfloat spotAmbiente[4]; 

  if(intensidade_spot == 0){
    spotAmbiente[0] = 0.25;
    spotAmbiente[1] = 0.25;
    spotAmbiente[2] = 0.25;
    spotAmbiente[3] = 1.0;
  }
  
  else if(intensidade_spot == 1){
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

  GLfloat spotPosicao[4];

  if(posicao_spot == 0){

    spotPosicao[0] = -3.0;
    spotPosicao[1] =  3.5;
    spotPosicao[2] = -3.0;
    spotPosicao[3] =  1.0;

  }

  else if(posicao_spot == 1){
    
    spotPosicao[0] = -2.0;
    spotPosicao[1] =  3.5;
    spotPosicao[2] = -3.0;
    spotPosicao[3] =  1.0;

  }

  else{
  
    spotPosicao[0] = -3.0;
    spotPosicao[1] =  3.5;
    spotPosicao[2] =  3.0;
    spotPosicao[3] =  1.0;
    
  }


  //--------Direcao--------

  GLfloat spotDirecao[3] = {0.0,-1.0,0.0};

  if(direcao_spot == 0){
    spotDirecao[0] = 0.0;
    spotDirecao[1] = -1.0;
    spotDirecao[2] = 0.0;
  }
  else if(direcao_spot == 1){
    spotDirecao[0] = -1.0;
    spotDirecao[1] = 0.0;
    spotDirecao[2] = 0.0;   
  }
  else if(direcao_spot == 2){
    spotDirecao[0] = 0.0;
    spotDirecao[1] = 1.0;
    spotDirecao[2] = 0.0;
  }
  else if(direcao_spot == 3){
    spotDirecao[0] = 1.0;
    spotDirecao[1] = 0.0;
    spotDirecao[2] = 0.0;
  }
  else if(direcao_spot == 4){
    spotDirecao[0] = 0.0;
    spotDirecao[1] = 0.0;
    spotDirecao[2] = 1.0;
  }
  else{
    spotDirecao[0] = 0.0;
    spotDirecao[1] = 0.0;
    spotDirecao[2] = -1.0;
  }


  //--------Angulo--------

  float spotAngulo;

  if(angulo_spot == 0){

    spotAngulo = 20;
  }

  else if(angulo_spot == 1){

    spotAngulo = 30;
  }

  else{

    spotAngulo = 40;
  }


  //--------Atribuicao--------

  glLightfv(GL_LIGHT2, GL_AMBIENT, spotAmbiente);
  glLightfv(GL_LIGHT2, GL_DIFFUSE, luzDifusa );
  glLightfv(GL_LIGHT2, GL_SPECULAR, luzEspecular );

  glLightfv(GL_LIGHT2, GL_POSITION, spotPosicao);
  glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, spotDirecao);
  glLightf (GL_LIGHT2, GL_SPOT_CUTOFF, spotAngulo);

  
}