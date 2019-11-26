#include <iostream>
#include "./materiais.h"
#include <GL/freeglut.h>

/* Funções do Menu */

void menu_principal(int id)
{
	if (id == 1) exit(0);
}

void menu_objetos(int id)
{
	if (id == 1) exit(0);
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

void sofa_menu(int id)
{
	if (id == 1)
	{
		sofa_matAmbAndDif[0] = 0.75164f;
   		sofa_matAmbAndDif[1] = 0.60648f;
   		sofa_matAmbAndDif[2] = 0.22648f;
   		sofa_matAmbAndDif[3] = 1.0f;
   	
   		sofa_matSpec[0] = 0.628281f;
   		sofa_matSpec[1] = 0.555802f;
   		sofa_matSpec[2] = 0.366065f;
   		sofa_matSpec[3] = 1.0f;

   		sofa_matShine[0] = 51.2;

   		glutPostRedisplay();
	}
}

void almofadas_sofa_menu(int id)
{
	if (id == 1)
	{
		almofadas_sofa_matAmbAndDif[0] = 0.75164f;
   		almofadas_sofa_matAmbAndDif[1] = 0.60648f;
   		almofadas_sofa_matAmbAndDif[2] = 0.22648f;
   		almofadas_sofa_matAmbAndDif[3] = 1.0f;
   	
   		almofadas_sofa_matSpec[0] = 0.628281f;
   		almofadas_sofa_matSpec[1] = 0.555802f;
   		almofadas_sofa_matSpec[2] = 0.366065f;
   		almofadas_sofa_matSpec[3] = 1.0f;

   		almofadas_sofa_matShine[0] = 51.2;

   		glutPostRedisplay();
	}
}

void makeMenu(void)
{
	/*Sub-menus para cada objeto	*/
	int sub_menuParedes = glutCreateMenu(paredes_menu);
	glutAddMenuEntry("Ouro", 1);

	int sub_menuPiso = glutCreateMenu(piso_menu);
	glutAddMenuEntry("Ouro", 1);

	int sub_menuSofa = glutCreateMenu(sofa_menu);
	glutAddMenuEntry("Ouro", 1);

	int sub_menuAlmofadas_Sofa = glutCreateMenu(almofadas_sofa_menu);
	glutAddMenuEntry("Ouro", 1);

	/*Cria o sub-menu que será utilizado no menu Objeto com os menus criados anteriormente*/
	int sub_menu_objetos;
	sub_menu_objetos = glutCreateMenu(menu_objetos);
	glutAddSubMenu("Paredes", sub_menuParedes);
	glutAddSubMenu("Piso", sub_menuPiso);
	glutAddSubMenu("Sofa", sub_menuSofa);
	glutAddSubMenu("Almofadas do Sofa", sub_menuAlmofadas_Sofa);

	/*Cria menu principal com opções Objeto e Sair*/
	glutCreateMenu(menu_principal);
	glutAddSubMenu("Objeto", sub_menu_objetos);
	glutAddMenuEntry("Sair", 1);

	/*Configura para o menu abrir com o botão direito do mouse*/
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}