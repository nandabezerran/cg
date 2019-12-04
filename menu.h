/* Funções do Menu */
void menu_principal(int id)
{
	if (id == 1) exit(0);
}

void menu_objetos(int id)
{
	if (id == 1) exit(0);
}


void sofas(int id)
{
	if (id == 1)
	{

      /*------------Sofa------------*/

		sofa_matAmbAndDif[0] = 0.75164f;
      sofa_matAmbAndDif[1] = 0.60648f;
      sofa_matAmbAndDif[2] = 0.22648f;
      sofa_matAmbAndDif[3] = 1.0f;
   
      sofa_matSpec[0] = 0.628281f;
      sofa_matSpec[1] = 0.555802f;
      sofa_matSpec[2] = 0.366065f;
      sofa_matSpec[3] = 1.0f;

      sofa_matShine[0] = 51.2;

      /*------------Poltrona------------*/

      poltrona_matAmbAndDif[0] = 0.75164f;
      poltrona_matAmbAndDif[1] = 0.60648f;
      poltrona_matAmbAndDif[2] = 0.22648f;
      poltrona_matAmbAndDif[3] = 1.0f;
   
      poltrona_matSpec[0] = 0.628281f;
      poltrona_matSpec[1] = 0.555802f;
      poltrona_matSpec[2] = 0.366065f;
      poltrona_matSpec[3] = 1.0f;

      poltrona_matShine[0] = 51.2;

      glutPostRedisplay();
	}
}

void almofadas_menu(int id)
{
   if (id == 1)
   {
      
      /*------------Almofadas Sofa------------*/

      almofadas_sofa_matAmbAndDif[0] = 0.75164f;
      almofadas_sofa_matAmbAndDif[1] = 0.60648f;
      almofadas_sofa_matAmbAndDif[2] = 0.22648f;
      almofadas_sofa_matAmbAndDif[3] = 1.0f;
   
      almofadas_sofa_matSpec[0] = 0.628281f;
      almofadas_sofa_matSpec[1] = 0.555802f;
      almofadas_sofa_matSpec[2] = 0.366065f;
      almofadas_sofa_matSpec[3] = 1.0f;

      almofadas_sofa_matShine[0] = 51.2;

      /*------------Almofadas Poltrona------------*/

      almofadas_poltrona_matAmbAndDif[0] = 0.75164f;
      almofadas_poltrona_matAmbAndDif[1] = 0.60648f;
      almofadas_poltrona_matAmbAndDif[2] = 0.22648f;
      almofadas_poltrona_matAmbAndDif[3] = 1.0f;
   
      almofadas_poltrona_matSpec[0] = 0.628281f;
      almofadas_poltrona_matSpec[1] = 0.555802f;
      almofadas_poltrona_matSpec[2] = 0.366065f;
      almofadas_poltrona_matSpec[3] = 1.0f;

      almofadas_poltrona_matShine[0] = 51.2;


      glutPostRedisplay();
   }
}

void travesseiros_menu(int id)
{
   if (id == 1)
   {
      /*------------Travesseiro 1------------*/

      travesseiro1_matAmbAndDif[0] = 0.75164f;
      travesseiro1_matAmbAndDif[1] = 0.60648f;
      travesseiro1_matAmbAndDif[2] = 0.22648f;
      travesseiro1_matAmbAndDif[3] = 1.0f;
   
      travesseiro1_matSpec[0] = 0.628281f;
      travesseiro1_matSpec[1] = 0.555802f;
      travesseiro1_matSpec[2] = 0.366065f;
      travesseiro1_matSpec[3] = 1.0f;

      travesseiro1_matShine[0] = 51.2;

      /*------------Travesseiro 2------------*/

      travesseiro2_matAmbAndDif[0] = 0.75164f;
      travesseiro2_matAmbAndDif[1] = 0.60648f;
      travesseiro2_matAmbAndDif[2] = 0.22648f;
      travesseiro2_matAmbAndDif[3] = 1.0f;
   
      travesseiro2_matSpec[0] = 0.628281f;
      travesseiro2_matSpec[1] = 0.555802f;
      travesseiro2_matSpec[2] = 0.366065f;
      travesseiro2_matSpec[3] = 1.0f;

      travesseiro2_matShine[0] = 51.2;

      /*------------Travesseiro 3------------*/

      travesseiro3_matAmbAndDif[0] = 0.75164f;
      travesseiro3_matAmbAndDif[1] = 0.60648f;
      travesseiro3_matAmbAndDif[2] = 0.22648f;
      travesseiro3_matAmbAndDif[3] = 1.0f;
   
      travesseiro3_matSpec[0] = 0.628281f;
      travesseiro3_matSpec[1] = 0.555802f;
      travesseiro3_matSpec[2] = 0.366065f;
      travesseiro3_matSpec[3] = 1.0f;

      travesseiro3_matShine[0] = 51.2;

      /*------------Travesseiro 4------------*/

      travesseiro4_matAmbAndDif[0] = 0.75164f;
      travesseiro4_matAmbAndDif[1] = 0.60648f;
      travesseiro4_matAmbAndDif[2] = 0.22648f;
      travesseiro4_matAmbAndDif[3] = 1.0f;
   
      travesseiro4_matSpec[0] = 0.628281f;
      travesseiro4_matSpec[1] = 0.555802f;
      travesseiro4_matSpec[2] = 0.366065f;
      travesseiro4_matSpec[3] = 1.0f;

      travesseiro4_matShine[0] = 51.2;


      glutPostRedisplay();
   }
}

void mesas_menu(int id)
{
	if (id == 1)
	{
		mesas_matAmbAndDif[0] = 0.75164f;
      mesas_matAmbAndDif[1] = 0.60648f;
      mesas_matAmbAndDif[2] = 0.22648f;
      mesas_matAmbAndDif[3] = 1.0f;
   
      mesas_matSpec[0] = 0.628281f;
      mesas_matSpec[1] = 0.555802f;
      mesas_matSpec[2] = 0.366065f;
      mesas_matSpec[3] = 1.0f;

      mesas_matShine[0] = 51.2;

      glutPostRedisplay();
	}
}

void abajur_menu(int id)
{
	if (id == 1)
	{
		abajur_matAmbAndDif[0] = 0.75164f;
      abajur_matAmbAndDif[1] = 0.60648f;
      abajur_matAmbAndDif[2] = 0.22648f;
      abajur_matAmbAndDif[3] = 1.0f;
   
      abajur_matSpec[0] = 0.628281f;
      abajur_matSpec[1] = 0.555802f;
      abajur_matSpec[2] = 0.366065f;
      abajur_matSpec[3] = 1.0f;

      abajur_matShine[0] = 51.2;

      glutPostRedisplay();
	}
}

void abajur_suporte_menu(int id)
{
	if (id == 1)
	{
		abajur_suporte_matAmbAndDif[0] = 0.75164f;
      abajur_suporte_matAmbAndDif[1] = 0.60648f;
      abajur_suporte_matAmbAndDif[2] = 0.22648f;
      abajur_suporte_matAmbAndDif[3] = 1.0f;
   
      abajur_suporte_matSpec[0] = 0.628281f;
      abajur_suporte_matSpec[1] = 0.555802f;
      abajur_suporte_matSpec[2] = 0.366065f;
      abajur_suporte_matSpec[3] = 1.0f;

      abajur_suporte_matShine[0] = 51.2;

      glutPostRedisplay();
	}
}

void armario_menu(int id)
{
	if (id == 1)
	{

      /*------------Armario------------*/

		armario_matAmbAndDif[0] = 0.75164f;
      armario_matAmbAndDif[1] = 0.60648f;
      armario_matAmbAndDif[2] = 0.22648f;
      armario_matAmbAndDif[3] = 1.0f;
   
      armario_matSpec[0] = 0.628281f;
      armario_matSpec[1] = 0.555802f;
      armario_matSpec[2] = 0.366065f;
      armario_matSpec[3] = 1.0f;

      armario_matShine[0] = 51.2;

      /*------------Armario Puxadores------------*/

      armario_puxadores_matAmbAndDif[0] = 0.75164f;
      armario_puxadores_matAmbAndDif[1] = 0.60648f;
      armario_puxadores_matAmbAndDif[2] = 0.22648f;
      armario_puxadores_matAmbAndDif[3] = 1.0f;
   
      armario_puxadores_matSpec[0] = 0.628281f;
      armario_puxadores_matSpec[1] = 0.555802f;
      armario_puxadores_matSpec[2] = 0.366065f;
      armario_puxadores_matSpec[3] = 1.0f;

      armario_puxadores_matShine[0] = 51.2;

      glutPostRedisplay();
	}
}

void armario_gavetas_menu(int id)
{
	if (id == 1)
	{
		armario_gavetas_matAmbAndDif[0] = 0.75164f;
      armario_gavetas_matAmbAndDif[1] = 0.60648f;
      armario_gavetas_matAmbAndDif[2] = 0.22648f;
      armario_gavetas_matAmbAndDif[3] = 1.0f;
   
      armario_gavetas_matSpec[0] = 0.628281f;
      armario_gavetas_matSpec[1] = 0.555802f;
      armario_gavetas_matSpec[2] = 0.366065f;
      armario_gavetas_matSpec[3] = 1.0f;

      armario_gavetas_matShine[0] = 51.2;

      glutPostRedisplay();
	}
}

void arvore_menu(int id)
{
   if (id == 1)
   {
      arvore_matAmbAndDif[0] = 0.75164f;
      arvore_matAmbAndDif[1] = 0.60648f;
      arvore_matAmbAndDif[2] = 0.22648f;
      arvore_matAmbAndDif[3] = 1.0f;
   
      arvore_matSpec[0] = 0.628281f;
      arvore_matSpec[1] = 0.555802f;
      arvore_matSpec[2] = 0.366065f;
      arvore_matSpec[3] = 1.0f;

      arvore_matShine[0] = 51.2;

      glutPostRedisplay();
   }
}

void arvore_vaso_menu(int id)
{
   if (id == 1)
   {
      arvore_vaso_matAmbAndDif[0] = 0.75164f;
      arvore_vaso_matAmbAndDif[1] = 0.60648f;
      arvore_vaso_matAmbAndDif[2] = 0.22648f;
      arvore_vaso_matAmbAndDif[3] = 1.0f;
   
      arvore_vaso_matSpec[0] = 0.628281f;
      arvore_vaso_matSpec[1] = 0.555802f;
      arvore_vaso_matSpec[2] = 0.366065f;
      arvore_vaso_matSpec[3] = 1.0f;

      arvore_vaso_matShine[0] = 51.2;

      glutPostRedisplay();
   }
}

void estantes_menu(int id)
{
   if (id == 1)
   {
      estantes_matAmbAndDif[0] = 0.75164f;
      estantes_matAmbAndDif[1] = 0.60648f;
      estantes_matAmbAndDif[2] = 0.22648f;
      estantes_matAmbAndDif[3] = 1.0f;
   
      estantes_matSpec[0] = 0.628281f;
      estantes_matSpec[1] = 0.555802f;
      estantes_matSpec[2] = 0.366065f;
      estantes_matSpec[3] = 1.0f;

      estantes_matShine[0] = 51.2;

      glutPostRedisplay();
   }
}

void livros_menu(int id)
{
   if (id == 1)
   {

      /*------------Livro1------------*/

      livro1_matAmbAndDif[0] = 0.75164f;
      livro1_matAmbAndDif[1] = 0.60648f;
      livro1_matAmbAndDif[2] = 0.22648f;
      livro1_matAmbAndDif[3] = 1.0f;
   
      livro1_matSpec[0] = 0.628281f;
      livro1_matSpec[1] = 0.555802f;
      livro1_matSpec[2] = 0.366065f;
      livro1_matSpec[3] = 1.0f;

      livro1_matShine[0] = 51.2;

      /*------------Livro2------------*/

      livro2_matAmbAndDif[0] = 0.75164f;
      livro2_matAmbAndDif[1] = 0.60648f;
      livro2_matAmbAndDif[2] = 0.22648f;
      livro2_matAmbAndDif[3] = 1.0f;
   
      livro2_matSpec[0] = 0.628281f;
      livro2_matSpec[1] = 0.555802f;
      livro2_matSpec[2] = 0.366065f;
      livro2_matSpec[3] = 1.0f;

      livro2_matShine[0] = 51.2;

      /*------------Livro3------------*/

      livro3_matAmbAndDif[0] = 0.75164f;
      livro3_matAmbAndDif[1] = 0.60648f;
      livro3_matAmbAndDif[2] = 0.22648f;
      livro3_matAmbAndDif[3] = 1.0f;
   
      livro3_matSpec[0] = 0.628281f;
      livro3_matSpec[1] = 0.555802f;
      livro3_matSpec[2] = 0.366065f;
      livro3_matSpec[3] = 1.0f;

      livro3_matShine[0] = 51.2;

      glutPostRedisplay();
   }
}

void relogio_menu(int id)
{
   if (id == 1)
   {

      relogio_matAmbAndDif[0] = 0.75164f;
      relogio_matAmbAndDif[1] = 0.60648f;
      relogio_matAmbAndDif[2] = 0.22648f;
      relogio_matAmbAndDif[3] = 1.0f;
   
      relogio_matSpec[0] = 0.628281f;
      relogio_matSpec[1] = 0.555802f;
      relogio_matSpec[2] = 0.366065f;
      relogio_matSpec[3] = 1.0f;

      relogio_matShine[0] = 51.2;

      glutPostRedisplay();
   }
}

void quadros_menu(int id)
{
   if (id == 1)
   {

      /*------------Quadros 1------------*/

      quadros1_matAmbAndDif[0] = 0.75164f;
      quadros1_matAmbAndDif[1] = 0.60648f;
      quadros1_matAmbAndDif[2] = 0.22648f;
      quadros1_matAmbAndDif[3] = 1.0f;
   
      quadros1_matSpec[0] = 0.628281f;
      quadros1_matSpec[1] = 0.555802f;
      quadros1_matSpec[2] = 0.366065f;
      quadros1_matSpec[3] = 1.0f;

      quadros1_matShine[0] = 51.2;

      /*------------Quadros 2------------*/

      quadros2_matAmbAndDif[0] = 0.75164f;
      quadros2_matAmbAndDif[1] = 0.60648f;
      quadros2_matAmbAndDif[2] = 0.22648f;
      quadros2_matAmbAndDif[3] = 1.0f;
   
      quadros2_matSpec[0] = 0.628281f;
      quadros2_matSpec[1] = 0.555802f;
      quadros2_matSpec[2] = 0.366065f;
      quadros2_matSpec[3] = 1.0f;

      quadros2_matShine[0] = 51.2;

      glutPostRedisplay();
   }
}

void quadros_molduras_menu(int id)
{
   if (id == 1)
   {

      quadros_molduras_matAmbAndDif[0] = 0.75164f;
      quadros_molduras_matAmbAndDif[1] = 0.60648f;
      quadros_molduras_matAmbAndDif[2] = 0.22648f;
      quadros_molduras_matAmbAndDif[3] = 1.0f;
   
      quadros_molduras_matSpec[0] = 0.628281f;
      quadros_molduras_matSpec[1] = 0.555802f;
      quadros_molduras_matSpec[2] = 0.366065f;
      quadros_molduras_matSpec[3] = 1.0f;

      quadros_molduras_matShine[0] = 51.2;

      glutPostRedisplay();
   }
}


void paredes_menu(int id)
{
   if (id == 1)
   {
      paredes_matAmbAndDif[0] = 0.75164f;
      paredes_matAmbAndDif[1] = 0.60648f;
      paredes_matAmbAndDif[2] = 0.22648f;
      paredes_matAmbAndDif[3] = 1.0f;
   
      paredes_matSpec[0] = 0.628281f;
      paredes_matSpec[1] = 0.555802f;
      paredes_matSpec[2] = 0.366065f;
      paredes_matSpec[3] = 1.0f;

      paredes_matShine[0] = 51.2;

      glutPostRedisplay();

   }
}

void piso_menu(int id)
{
   if (id == 1)
   {
      piso_matAmbAndDif[0] = 0.75164f;
      piso_matAmbAndDif[1] = 0.60648f;
      piso_matAmbAndDif[2] = 0.22648f;
      piso_matAmbAndDif[3] = 1.0f;
   
      piso_matSpec[0] = 0.628281f;
      piso_matSpec[1] = 0.555802f;
      piso_matSpec[2] = 0.366065f;
      piso_matSpec[3] = 1.0f;

      piso_matShine[0] = 51.2;

      glutPostRedisplay();

   }
}

void makeMenu(void)
{
	/*Sub-menus para cada objeto	*/

	int sub_sofas = glutCreateMenu(sofas);
	glutAddMenuEntry("Ouro", 1);

	int sub_menualmofadas = glutCreateMenu(almofadas_menu);
   glutAddMenuEntry("Ouro", 1);

   int sub_menutravesseiros = glutCreateMenu(travesseiros_menu);
   glutAddMenuEntry("Ouro", 1);

	int sub_menumesas = glutCreateMenu(mesas_menu);
	glutAddMenuEntry("Ouro", 1);

	int sub_menuabajur = glutCreateMenu(abajur_menu);
	glutAddMenuEntry("Ouro", 1);

	int sub_menuabajur_suporte = glutCreateMenu(abajur_suporte_menu);
	glutAddMenuEntry("Ouro", 1);

	int sub_menuarmario = glutCreateMenu(armario_menu);
	glutAddMenuEntry("Ouro", 1);

	int sub_menuarmario_gavetas = glutCreateMenu(armario_gavetas_menu);
	glutAddMenuEntry("Ouro", 1);

   int sub_menuarvore = glutCreateMenu(arvore_menu);
   glutAddMenuEntry("Ouro", 1);

   int sub_menuarvore_vaso = glutCreateMenu(arvore_vaso_menu);
   glutAddMenuEntry("Ouro", 1);

   int sub_menuestantes = glutCreateMenu(estantes_menu);
   glutAddMenuEntry("Ouro", 1);

   int sub_menulivros = glutCreateMenu(livros_menu);
   glutAddMenuEntry("Ouro", 1);

   int sub_menurelogio = glutCreateMenu(relogio_menu);
   glutAddMenuEntry("Ouro", 1);

   int sub_menuquadros = glutCreateMenu(quadros_menu);
   glutAddMenuEntry("Ouro", 1);

   int sub_menuquadros_molduras = glutCreateMenu(quadros_molduras_menu);
   glutAddMenuEntry("Ouro", 1);

   int sub_menupiso = glutCreateMenu(piso_menu);
   glutAddMenuEntry("Ouro", 1);

   int sub_menuparedes = glutCreateMenu(paredes_menu);
   glutAddMenuEntry("Ouro", 1);

	/*Cria o sub-menu que será utilizado no menu Objeto com os menus criados anteriormente*/
	int sub_menu_objetos;
	sub_menu_objetos = glutCreateMenu(menu_objetos);
	glutAddSubMenu("Sofas", sub_sofas);
	glutAddSubMenu("Almofadas", sub_menualmofadas);
   glutAddSubMenu("Travesseiros", sub_menutravesseiros);
	glutAddSubMenu("Mesas", sub_menumesas);
	glutAddSubMenu("Abajur", sub_menuabajur);
	glutAddSubMenu("Suporte", sub_menuabajur_suporte);
	glutAddSubMenu("Armario", sub_menuarmario);
	glutAddSubMenu("Gavetas", sub_menuarmario_gavetas);
   glutAddSubMenu("Arvore", sub_menuarvore);
   glutAddSubMenu("Vaso", sub_menuarvore_vaso);
   glutAddSubMenu("Estantes", sub_menuestantes);
   glutAddSubMenu("Livros", sub_menulivros);
   glutAddSubMenu("Relogio", sub_menurelogio);
   glutAddSubMenu("Quadros", sub_menuquadros);
   glutAddSubMenu("Molduras", sub_menuquadros_molduras);
   glutAddSubMenu("Piso", sub_menupiso);
   glutAddSubMenu("Paredes", sub_menuparedes);

	/*Cria menu principal com opções Objeto e Sair*/
	glutCreateMenu(menu_principal);
	glutAddSubMenu("Objetos", sub_menu_objetos);
	glutAddMenuEntry("Sair", 1);

	/*Configura para o menu abrir com o botão direito do mouse*/
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}


void setup(void)
{

	glClearColor(0.0, 0.0, 0.0, 0.0);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_CULL_FACE);

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	glEnable(GL_NORMALIZE);
	
 
   /* ------------------ Parâmetros da fonte luminosa 1 ----------------------- */
	
	float lightAmb[] = {0.0, 0.0, 0.0, 1.0};
   float lightDifAndSpec[] = {0.3, 0.3, 0.3, 1.0};

   glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmb);
   glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDifAndSpec);
   glLightfv(GL_LIGHT0, GL_SPECULAR, lightDifAndSpec);

   float lightPos[] = {40.0, 100.0, 400.0 , 1.0};


   glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
	glEnable(GL_LIGHT0);
     

   /* ------------------ Parâmetros luz ambiente ------------------------------- */

   float globAmb[] = {0.4, 0.4, 0.4, 1.0};   
   glLightModelfv(GL_LIGHT_MODEL_AMBIENT, globAmb); // Global ambient light.


   /* ------------------ Características gerais da iluminação ----------------- */

   glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE); // Enable two-sided lighting.
   glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);

   /* ------------------------------------------------------------------------- */

	makeMenu();

}

void resize(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-30.0, 30.0, -30.0, 30.0, 2.0, 200.0);
	glMatrixMode(GL_MODELVIEW);
}
