/* Funções do Menu */
void menu_principal(int id)
{
	if (id == 1) exit(0);
}

void menu_objetos(int id)
{
	if (id == 1) exit(0);
}

void menu_luzes(int id){
   if(id == 1) exit(0);
}

void sofas(int id)
{
	if (id == 1)
	{

      /*------------Sofa------------*/

	   sofa_matAmbAndDif[0] = 0.25f;
      sofa_matAmbAndDif[1] = 0.148f;
      sofa_matAmbAndDif[2] = 0.06475f;
      sofa_matAmbAndDif[3] = 1.0f;
  
      sofa_matSpec[0] = 0.774597f;
      sofa_matSpec[1] = 0.458561f;
      sofa_matSpec[2] = 0.200621f;
      sofa_matSpec[3] = 1.0f;

      sofa_matShine[0] = 76.8f;	

      /*------------Poltrona------------*/

      poltrona_matAmbAndDif[0] = 0.25f;
      poltrona_matAmbAndDif[1] = 0.148f;
      poltrona_matAmbAndDif[2] = 0.06475f;
      poltrona_matAmbAndDif[3] = 1.0f;
  
      poltrona_matSpec[0] = 0.774597f;
      poltrona_matSpec[1] = 0.458561f;
      poltrona_matSpec[2] = 0.200621f;
      poltrona_matSpec[3] = 1.0f;

      poltrona_matShine[0] = 76.8f;

      poltrona_matShine[0] = 51.2;

      glutPostRedisplay();
	}

   else if(id == 2){

      show_sofas = !show_sofas;
      glutPostRedisplay();

   }
}

void almofadas_menu(int id)
{
   if (id == 1)
   {
 /*------------Almofadas Sofa------------*/

      almofadas_sofa_matAmbAndDif[0] = 0.25f;
      almofadas_sofa_matAmbAndDif[1] = 0.148f;
      almofadas_sofa_matAmbAndDif[2] = 0.06475f;
      almofadas_sofa_matAmbAndDif[3] = 1.0f;
  
      almofadas_sofa_matSpec[0] = 0.774597f;
      almofadas_sofa_matSpec[1] = 0.458561f;
      almofadas_sofa_matSpec[2] = 0.200621f;
      almofadas_sofa_matSpec[3] = 1.0f;

      almofadas_sofa_matShine[0] = 76.8f;

      /*------------Almofadas Poltrona------------*/

      almofadas_poltrona_matAmbAndDif[0] = 0.25f;
      almofadas_poltrona_matAmbAndDif[1] = 0.148f;
      almofadas_poltrona_matAmbAndDif[2] = 0.06475f;
      almofadas_poltrona_matAmbAndDif[3] = 1.0f;
  
      almofadas_poltrona_matSpec[0] = 0.774597f;
      almofadas_poltrona_matSpec[1] = 0.458561f;
      almofadas_poltrona_matSpec[2] = 0.200621f;
      almofadas_poltrona_matSpec[3] = 1.0f;

      almofadas_poltrona_matShine[0] = 76.8f;

      glutPostRedisplay();
   }

   else if(id == 2){

      show_almofadas = !show_almofadas;
      glutPostRedisplay();

   }
}

void travesseiros_menu(int id)
{
   if (id == 1)
   {
      /*------------Travesseiro 1------------*/

      travesseiro1_matAmbAndDif[0] = 0.05f;
      travesseiro1_matAmbAndDif[1] = 0.4f;
      travesseiro1_matAmbAndDif[2] = 0.4f;
      travesseiro1_matAmbAndDif[3] = 1.0f;
   
      travesseiro1_matSpec[0] = 0.7f;
      travesseiro1_matSpec[1] = 0.04f;
      travesseiro1_matSpec[2] = 0.04f;
      travesseiro1_matSpec[3] = 1.0f;

      travesseiro1_matShine[0] = 10.0f;

      /*------------Travesseiro 2------------*/

      travesseiro2_matAmbAndDif[0] = 0.05f;
      travesseiro2_matAmbAndDif[1] = 0.4f;
      travesseiro2_matAmbAndDif[2] = 0.4f;
      travesseiro2_matAmbAndDif[3] = 1.0f;
   
      travesseiro2_matSpec[0] = 0.7f;
      travesseiro2_matSpec[1] = 0.04f;
      travesseiro2_matSpec[2] = 0.04f;
      travesseiro2_matSpec[3] = 1.0f;

      travesseiro2_matShine[0] = 10.0f;

      /*------------Travesseiro 3------------*/

      travesseiro3_matAmbAndDif[0] = 0.05f;
      travesseiro3_matAmbAndDif[1] = 0.4f;
      travesseiro3_matAmbAndDif[2] = 0.4f;
      travesseiro3_matAmbAndDif[3] = 1.0f;
   
      travesseiro3_matSpec[0] = 0.7f;
      travesseiro3_matSpec[1] = 0.04f;
      travesseiro3_matSpec[2] = 0.04f;
      travesseiro3_matSpec[3] = 1.0f;

      travesseiro3_matShine[0] = 10.0f;

      /*------------Travesseiro 4------------*/

      travesseiro4_matAmbAndDif[0] = 0.05f;
      travesseiro4_matAmbAndDif[1] = 0.4f;
      travesseiro4_matAmbAndDif[2] = 0.4f;
      travesseiro4_matAmbAndDif[3] = 1.0f;
   
      travesseiro4_matSpec[0] = 0.7f;
      travesseiro4_matSpec[1] = 0.04f;
      travesseiro4_matSpec[2] = 0.04f;
      travesseiro4_matSpec[3] = 1.0f;

      travesseiro4_matShine[0] = 10.0f;

      glutPostRedisplay();
   }

   else if(id == 2){

      show_travesseiros = !show_travesseiros;
      glutPostRedisplay();

   }
}

void mesas_menu(int id)
{
	if (id == 1)
	{

		mesas_matAmbAndDif[0] = 0.7038f;
      mesas_matAmbAndDif[1] = 0.27048f;
      mesas_matAmbAndDif[2] = 0.0828f;
      mesas_matAmbAndDif[3] = 1.0f;
   
      mesas_matSpec[0] = 0.580594f;
      mesas_matSpec[1] = 0.223257f;
      mesas_matSpec[2] = 0.0695701f;
      mesas_matSpec[3] = 1.0f;

      mesas_matShine[0] = 76.8f;

      glutPostRedisplay();
	}

   else if(id == 2){

      show_mesas = !show_mesas;
      glutPostRedisplay();

   }
}

void abajur_menu(int id)
{
	if (id == 1)
	{

		abajur_matAmbAndDif[0] = 0.34615f;
      abajur_matAmbAndDif[1] = 0.3143f;
      abajur_matAmbAndDif[2] = 0.0903f;
      abajur_matAmbAndDif[3] = 1.0f;
   
      abajur_matSpec[0] = 0.797357f;
      abajur_matSpec[1] = 0.723991f;
      abajur_matSpec[2] = 0.208006f;
      abajur_matSpec[3] = 1.0f;

      abajur_matShine[0] = 83.2f;

      glutPostRedisplay();
	}

   else if(id == 2){

      show_abajur = !show_abajur;
      glutPostRedisplay();

   }
}

void abajur_suporte_menu(int id)
{
	if (id == 1)
	{
          
		abajur_suporte_matAmbAndDif[0] = 1.0f;
      abajur_suporte_matAmbAndDif[1] = 0.829f;
      abajur_suporte_matAmbAndDif[2] = 0.829f;
      abajur_suporte_matAmbAndDif[3] = 0.922f;
   
      abajur_suporte_matSpec[0] = 0.296648f;
      abajur_suporte_matSpec[1] = 0.296648f;
      abajur_suporte_matSpec[2] = 0.296648f;
      abajur_suporte_matSpec[3] = 0.922f;

      abajur_suporte_matShine[0] = 11.264;

      glutPostRedisplay();
	}

   else if(id == 2){

      show_suporte = !show_suporte;
      glutPostRedisplay();

   }
}

void armario_menu(int id)
{
	if (id == 1)
	{

      /*------------Armario------------*/

	   armario_matAmbAndDif[0] = 0.7038f;
      armario_matAmbAndDif[1] = 0.27048f;
      armario_matAmbAndDif[2] = 0.0828f;
      armario_matAmbAndDif[3] = 1.0f;
   
      armario_matSpec[0] = 0.580594f;
      armario_matSpec[1] = 0.223257f;
      armario_matSpec[2] = 0.0695701f;
      armario_matSpec[3] = 1.0f;


      /*------------Armario Puxadores------------*/

      armario_puxadores_matAmbAndDif[0] = 0.25f;
      armario_puxadores_matAmbAndDif[1] = 0.148f;
      armario_puxadores_matAmbAndDif[2] = 0.06475f;
      armario_puxadores_matAmbAndDif[3] = 1.0f;
  
      armario_puxadores_matSpec[0] = 0.774597f;
      armario_puxadores_matSpec[1] = 0.458561f;
      armario_puxadores_matSpec[2] = 0.200621f;
      armario_puxadores_matSpec[3] = 1.0f;

      armario_puxadores_matShine[0] = 76.8f;


      glutPostRedisplay();
	}

   else if(id == 2){

      show_armario = !show_armario;
      glutPostRedisplay();

   }
}

void armario_gavetas_menu(int id)
{
	if (id == 1)
	{
		armario_gavetas_matAmbAndDif[0] = 0.7038f;
      armario_gavetas_matAmbAndDif[1] = 0.27048f;
      armario_gavetas_matAmbAndDif[2] = 0.0828f;
      armario_gavetas_matAmbAndDif[3] = 1.0f;
   
      armario_gavetas_matSpec[0] = 0.580594f;
      armario_gavetas_matSpec[1] = 0.223257f;
      armario_gavetas_matSpec[2] = 0.0695701f;
      armario_gavetas_matSpec[3] = 1.0f;

      glutPostRedisplay();
	}

   else if(id == 2){

      show_gavetas = !show_gavetas;
      glutPostRedisplay();

   }
}

void arvore_menu(int id)
{
   if (id == 1)
   {
      arvore_matAmbAndDif[0] = 0.1f;
      arvore_matAmbAndDif[1] = 0.35f;
      arvore_matAmbAndDif[2] = 0.1f;
      arvore_matAmbAndDif[3] = 1.0f;
   
      arvore_matSpec[0] = 0.45f;
      arvore_matSpec[1] = 0.55f;
      arvore_matSpec[2] = 0.45f;
      arvore_matSpec[3] = 1.0f;

      arvore_matShine[0] = 32.0f;

      glutPostRedisplay();
   }

   else if(id == 2){

      show_arvore = !show_arvore;
      glutPostRedisplay();

   }
}

void arvore_vaso_menu(int id)
{
   if (id == 1)
   {
     arvore_vaso_matAmbAndDif[0] = 0.05f;
      arvore_vaso_matAmbAndDif[1] = 0.05f;
      arvore_vaso_matAmbAndDif[2] = 0.06625f;
      arvore_vaso_matAmbAndDif[3] = 0.82f;
   
      arvore_vaso_matSpec[0] = 0.332741f;
      arvore_vaso_matSpec[1] = 0.328634f;
      arvore_vaso_matSpec[2] = 0.346435f;
      arvore_vaso_matSpec[3] = 0.82f;

      arvore_vaso_matShine[0] = 38.4f;

      glutPostRedisplay();
   }

   else if(id == 2){

      show_vaso = !show_vaso;
      glutPostRedisplay();

   }
}

void estantes_menu(int id)
{
   if (id == 1)
   {

      estantes_matAmbAndDif[0] = 0.7038f;
      estantes_matAmbAndDif[1] = 0.27048f;
      estantes_matAmbAndDif[2] = 0.0828f;
      estantes_matAmbAndDif[3] = 1.0f;
   
      estantes_matSpec[0] = 0.580594f;
      estantes_matSpec[1] = 0.223257f;
      estantes_matSpec[2] = 0.0695701f;
      estantes_matSpec[3] = 1.0f;

      estantes_matShine[0] = 76.8f;
     

      glutPostRedisplay();
   }

   else if(id == 2){

      show_estantes = !show_estantes;
      glutPostRedisplay();

   }
}

void livros_menu(int id)
{
   if (id == 1)
   {

      /*------------Livro1------------*/

      livro1_matAmbAndDif[0] = 0.05f;
      livro1_matAmbAndDif[1] = 0.4f;
      livro1_matAmbAndDif[2] = 0.4f;
      livro1_matAmbAndDif[3] = 1.0f;
   
      livro1_matSpec[0] = 0.7f;
      livro1_matSpec[1] = 0.04f;
      livro1_matSpec[2] = 0.04f;
      livro1_matSpec[3] = 1.0f;

      livro1_matShine[0] = 10.0f;

      /*------------Livro2------------*/
      livro2_matAmbAndDif[0] = 0.61424f;
      livro2_matAmbAndDif[1] = 0.04136f;
      livro2_matAmbAndDif[2] = 0.04136f;
      livro2_matAmbAndDif[3] = 0.55f;
   
      livro2_matSpec[0] = 0.727811f;
      livro2_matSpec[1] = 0.626959f;
      livro2_matSpec[2] = 0.626959f;
      livro2_matSpec[3] = 0.55f;

      livro2_matShine[0] = 76.8f;

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

   else if(id == 2){

      show_livros = !show_livros;
      glutPostRedisplay();

   }
}

void relogio_menu(int id)
{
   if (id == 1)
   {
		relogio_matAmbAndDif[0] = 0.25f;
      relogio_matAmbAndDif[1] = 0.148f;
      relogio_matAmbAndDif[2] = 0.06475f;
      relogio_matAmbAndDif[3] = 1.0f;
  
      relogio_matSpec[0] = 0.774597f;
      relogio_matSpec[1] = 0.458561f;
      relogio_matSpec[2] = 0.200621f;
      relogio_matSpec[3] = 1.0f;

      relogio_matShine[0] = 76.8f;

      glutPostRedisplay();
   }

   else if(id == 2){

      show_relogio = !show_relogio;
      glutPostRedisplay();

   }
}

void quadros_menu(int id)
{
   if (id == 1)
   {

      /*------------Quadros 1------------*/

      quadros1_matAmbAndDif[0] = 0.396f;
      quadros1_matAmbAndDif[1] = 0.74151f;
      quadros1_matAmbAndDif[2] = 0.69102f;
      quadros1_matAmbAndDif[3] = 0.8f;
   
      quadros1_matSpec[0] = 0.297254f;
      quadros1_matSpec[1] = 0.30829f;
      quadros1_matSpec[2] = 0.306678f;
      quadros1_matSpec[3] = 0.8f;

      quadros1_matShine[0] = 12.8f;

      /*------------Quadros 2------------*/
  
      quadros2_matAmbAndDif[0] = 0.396f;
      quadros2_matAmbAndDif[1] = 0.74151f;
      quadros2_matAmbAndDif[2] = 0.69102f;
      quadros2_matAmbAndDif[3] = 0.8f;
   
      quadros2_matSpec[0] = 0.297254f;
      quadros2_matSpec[1] = 0.30829f;
      quadros2_matSpec[2] = 0.306678f;
      quadros2_matSpec[3] = 0.8f;

      quadros2_matShine[0] = 12.8f;

      glutPostRedisplay();
   }

   else if(id == 2){

      show_quadros = !show_quadros;
      glutPostRedisplay();

   }
}

void quadros_molduras_menu(int id)
{
   if (id == 1)
   {
      quadros_molduras_matAmbAndDif[0] = 0.61424f;
      quadros_molduras_matAmbAndDif[1] = 0.04136f;
      quadros_molduras_matAmbAndDif[2] = 0.04136f;
      quadros_molduras_matAmbAndDif[3] = 0.55f;
   
      quadros_molduras_matSpec[0] = 0.727811f;
      quadros_molduras_matSpec[1] = 0.626959f;
      quadros_molduras_matSpec[2] = 0.626959f;
      quadros_molduras_matSpec[3] = 0.55f;

      quadros_molduras_matShine[0] = 76.8f;

      glutPostRedisplay();
   }

   else if(id == 2){

      show_molduras = !show_molduras;
      glutPostRedisplay();

   }
}

void piso_menu(int id)
{
   if (id == 1)
   {

      piso_matAmbAndDif[0] = 0.23125f;
      piso_matAmbAndDif[1] = 0.23125f;
      piso_matAmbAndDif[2] = 0.23125f;
      piso_matAmbAndDif[3] = 1.0f;
   
      piso_matSpec[0] = 0.773911f;
      piso_matSpec[1] = 0.773911f;
      piso_matSpec[2] = 0.773911f;
      piso_matSpec[3] = 1.0f;

      piso_matShine[0] = 89.6f;
      glutPostRedisplay();
   }

   else if(id == 2){

      show_piso = !show_piso;
      glutPostRedisplay();

   }

}

void paredes_menu(int id)
{
   if (id == 1)
   {
      paredes_matAmbAndDif[0] = 0.55f;
      paredes_matAmbAndDif[1] = 0.55f;
      paredes_matAmbAndDif[2] = 0.55f;
      paredes_matAmbAndDif[3] = 1.0f;
   
      paredes_matSpec[0] = 0.70f;
      paredes_matSpec[1] = 0.70f;
      paredes_matSpec[2] = 0.70f;
      paredes_matSpec[3] = 1.0f;

      paredes_matShine[0] = 32.0f;
      glutPostRedisplay();

   }

   else if(id == 2){

      show_paredes = !show_paredes;
      glutPostRedisplay();

   }
}

/* SUB MENU LUZES */

void direcional_menu(int id){

   if(id == 1){
      intensidade_direcional = (intensidade_direcional + 1)%3;
      glutPostRedisplay();
   }

   else if(id == 2){

      glutPostRedisplay();
   }

   else if(id == 3){
      show_direcional = !show_direcional;
      glutPostRedisplay();
   }
}

void spot_menu(int id){
   
   if(id == 1){
      intensidade_spot = (intensidade_spot + 1)%3;
      glutPostRedisplay();
   }

   else if(id == 2){

      glutPostRedisplay();
   }

   else if(id == 3){
      show_spot = !show_spot;
      glutPostRedisplay();
   }
}

void pontual_menu(int id){
   
   if(id == 1){
      intensidade_pontual = (intensidade_pontual + 1)%3;
      glutPostRedisplay();
   }

   else if(id == 2){

      glutPostRedisplay();
   }

   else if(id == 3){
      show_pontual = !show_pontual;
      glutPostRedisplay();
   }
}


void makeMenu(void)
{
	/*Sub-menus pra cada objeto */

	int sub_sofas = glutCreateMenu(sofas);
	glutAddMenuEntry("Bronze", 1);
   glutAddMenuEntry("Deletar/Adicionar", 2);

	int sub_menualmofadas = glutCreateMenu(almofadas_menu);
   glutAddMenuEntry("Bronze", 1);
   glutAddMenuEntry("Deletar/Adicionar", 2);

   int sub_menutravesseiros = glutCreateMenu(travesseiros_menu);
   glutAddMenuEntry("Ciano", 1);
   glutAddMenuEntry("Deletar/Adicionar", 2);

	int sub_menumesas = glutCreateMenu(mesas_menu);
	glutAddMenuEntry("Cobre", 1);
   glutAddMenuEntry("Deletar/Adicionar", 2);

	int sub_menuabajur = glutCreateMenu(abajur_menu);
	glutAddMenuEntry("Ouro", 1);
   glutAddMenuEntry("Deletar/Adicionar", 2);

	int sub_menuabajur_suporte = glutCreateMenu(abajur_suporte_menu);
	glutAddMenuEntry("Perola", 1);
   glutAddMenuEntry("Deletar/Adicionar", 2);

	int sub_menuarmario = glutCreateMenu(armario_menu);
	glutAddMenuEntry("Cobre", 1);
   glutAddMenuEntry("Deletar/Adicionar", 2);

	int sub_menuarmario_gavetas = glutCreateMenu(armario_gavetas_menu);
	glutAddMenuEntry("Cobre", 1);
   glutAddMenuEntry("Deletar/Adicionar", 2);

   int sub_menuarvore = glutCreateMenu(arvore_menu);
   glutAddMenuEntry("Verde", 1);
   glutAddMenuEntry("Deletar/Adicionar", 2);

   int sub_menuarvore_vaso = glutCreateMenu(arvore_vaso_menu);
   glutAddMenuEntry("Preto", 1);
   glutAddMenuEntry("Deletar/Adicionar", 2);

   int sub_menuestantes = glutCreateMenu(estantes_menu);
   glutAddMenuEntry("Bronze", 1);
   glutAddMenuEntry("Deletar/Adicionar", 2);

   int sub_menulivros = glutCreateMenu(livros_menu);
   glutAddMenuEntry("Ciano, vermelho", 1);
   glutAddMenuEntry("Deletar/Adicionar", 2);

   int sub_menurelogio = glutCreateMenu(relogio_menu);
   glutAddMenuEntry("Bronze", 1);
   glutAddMenuEntry("Deletar/Adicionar", 2);

   int sub_menuquadros = glutCreateMenu(quadros_menu);
   glutAddMenuEntry("Ciano", 1);
   glutAddMenuEntry("Deletar/Adicionar", 2);

   int sub_menuquadros_molduras = glutCreateMenu(quadros_molduras_menu);
   glutAddMenuEntry("Vermelho", 1);
   glutAddMenuEntry("Deletar/Adicionar", 2);

   int sub_menupiso = glutCreateMenu(piso_menu);
   glutAddMenuEntry("Obsidiana", 1);
   glutAddMenuEntry("Deletar/Adicionar", 2);

   int sub_menuparedes = glutCreateMenu(paredes_menu);
   glutAddMenuEntry("Prata", 1);
   glutAddMenuEntry("Deletar/Adicionar", 2);

   /*Sub-menus pra cada luz */


   int sub_menudirecional = glutCreateMenu(direcional_menu);
   glutAddMenuEntry("Intensidade", 1);
   glutAddMenuEntry("Posicao", 2);
   glutAddMenuEntry("Apagar/Acender", 3);


   int sub_menuspot = glutCreateMenu(spot_menu);
   glutAddMenuEntry("Intensidade", 1);
   glutAddMenuEntry("Posicao", 2);
   glutAddMenuEntry("Apagar/Acender", 3);

   int sub_menupontual = glutCreateMenu(pontual_menu);
   glutAddMenuEntry("Intensidade", 1);
   glutAddMenuEntry("Posicao", 2);
   glutAddMenuEntry("Apagar/Acender", 3);

   /*Sub-menus de vizualização para cada objeto */


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

   int sub_menu_luzes;
   sub_menu_luzes = glutCreateMenu(menu_luzes);
   glutAddSubMenu("Direcional", sub_menudirecional);
   glutAddSubMenu("SpotLight", sub_menuspot);
   glutAddSubMenu("Pontual", sub_menupontual);

	/*Cria menu principal com opções Objeto e Sair*/
	glutCreateMenu(menu_principal);
	glutAddSubMenu("Objetos", sub_menu_objetos);
   glutAddSubMenu("Luzes", sub_menu_luzes);
	glutAddMenuEntry("Sair", 1);

	/*Configura para o menu abrir com o botão direito do mouse*/
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}


