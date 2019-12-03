//Para compilar: g++ renderGL.cpp -o renderGL -lGL -lGLU -lglut && ./renderGL

#include <iostream>
#include <GL/freeglut.h>
#include <cmath>

#include "./objetos/modelsGL.h"
#include "./materiais.h"
#include "./camera.h"

using namespace std;

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

void poltrona_menu(int id)
{
	if (id == 1)
	{
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

void almofadas_poltrona_menu(int id)
{
	if (id == 1)
	{
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
		armario_matAmbAndDif[0] = 0.75164f;
   		armario_matAmbAndDif[1] = 0.60648f;
   		armario_matAmbAndDif[2] = 0.22648f;
   		armario_matAmbAndDif[3] = 1.0f;
   	
   		armario_matSpec[0] = 0.628281f;
   		armario_matSpec[1] = 0.555802f;
   		armario_matSpec[2] = 0.366065f;
   		armario_matSpec[3] = 1.0f;

   		armario_matShine[0] = 51.2;

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

void armario_puxadores_menu(int id)
{
	if (id == 1)
	{
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


void makeMenu(void)
{
	/*Sub-menus para cada objeto	*/
	int sub_menuParedes = glutCreateMenu(paredes_menu);
	glutAddMenuEntry("Ouro", 1);

	int sub_menuPiso = glutCreateMenu(piso_menu);
	glutAddMenuEntry("Ouro", 1);

	int sub_menuSofa = glutCreateMenu(sofa_menu);
	glutAddMenuEntry("Ouro", 1);

	int sub_menualmofadas_sofa = glutCreateMenu(almofadas_sofa_menu);
	glutAddMenuEntry("Ouro", 1);

	int sub_menupoltrona = glutCreateMenu(poltrona_menu);
	glutAddMenuEntry("Ouro", 1);

	int sub_menualmofadas_poltrona = glutCreateMenu(almofadas_poltrona_menu);
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

	int sub_menuarmario_puxadores = glutCreateMenu(armario_puxadores_menu);
	glutAddMenuEntry("Ouro", 1);

	/*Cria o sub-menu que será utilizado no menu Objeto com os menus criados anteriormente*/
	int sub_menu_objetos;
	sub_menu_objetos = glutCreateMenu(menu_objetos);
	glutAddSubMenu("Paredes", sub_menuParedes);
	glutAddSubMenu("Piso", sub_menuPiso);
	glutAddSubMenu("Sofa", sub_menuSofa);
	glutAddSubMenu("Almofadas do Sofa", sub_menualmofadas_sofa);
	glutAddSubMenu("Poltrona", sub_menupoltrona);
	glutAddSubMenu("Almofadas da Poltrona", sub_menualmofadas_poltrona);
	glutAddSubMenu("Mesas", sub_menumesas);
	glutAddSubMenu("Abajur", sub_menuabajur);
	glutAddSubMenu("Abajur Suporte", sub_menuabajur_suporte);
	glutAddSubMenu("Armario", sub_menuarmario);
	glutAddSubMenu("Armario Gavetas", sub_menuarmario_gavetas);
	glutAddSubMenu("Armario Puxadores", sub_menuarmario_puxadores);

	/*Cria menu principal com opções Objeto e Sair*/
	glutCreateMenu(menu_principal);
	glutAddSubMenu("Objeto", sub_menu_objetos);
	glutAddMenuEntry("Sair", 1);

	/*Configura para o menu abrir com o botão direito do mouse*/
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

/*Função do mouse*/
void mouse(int button, int state, int x, int y)
{
	if((button == 3) || (button == 4) )
	{
		if (state == GLUT_UP) return;

		(button == 3) ? transZ++ : transZ--;
	}

	if((button == 5) || (button == 6) )
	{
		if (state == GLUT_UP) return;

		(button == 5) ? transX++ : transX--;
	}

	glutPostRedisplay();
}

/*Função do teclado*/
void keyInput(unsigned char key, int x, int y)
{
	switch(key)
	{
		case 27:
			exit(0);
			break;
		case 'w':
			transZ += 1.0;
			glutPostRedisplay();
			break;
		case 'a':
			transX += 1.0;
			glutPostRedisplay();
			break;
		case 's':
			transZ -= 1.0;
			glutPostRedisplay();
			break;
		case 'd':
			transX -= 1.0;
			glutPostRedisplay();
			break;
		case 'W':
			angleBeta += pi/6;
			glutPostRedisplay();
			break;
		case 'A':
			angleAlpha += pi/6;
			glutPostRedisplay();
			break;
		case 'S':
			angleBeta -= pi/6;
			glutPostRedisplay();
			break;	
		case 'D':
			angleAlpha -= pi/6;
			glutPostRedisplay();
			break;
		default:
			break;
	}
}

void drawScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
	glLoadIdentity();

	glEnable(GL_LIGHT0);
   	

	/* ------------------------------------ TRANSFORMAÇÕES -------------------------------------- */
	glTranslatef(0.0, 0.0, -10.0); //  0.0 0.0 0.0
	glTranslatef(0.0 + transX , -50.0, 0.0 + transZ );
	glScalef(20.0, 20.0, 1.0);	
	/* ------------------------------------------------------------------------------------------- */
	

	/* ------------------------------------ DEFINIÇÃO DO OBSERVADOR ------------------------------------ */

	gluLookAt( 0.33 * cos(angleBeta) * cos(angleAlpha), 0.33 * sin(angleBeta), 0.33 * cos(angleBeta) * sin(angleAlpha), 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	/* ----------------------------------------------------------------------------------------------- */

 	/* --------------------------------------    OBJETOS:  ------------------------------------------ */


	/* ------------------------------------------------------------
						DESENHO DAS PAREDES		
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

	/* ------------------------------------------------------------------------ */

	/*
		----------------------------------- DESENHO DO PISO ---------------------------------
	*/

	
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, piso_matAmbAndDif);
   	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, piso_matSpec);
   	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, piso_matShine);
	
	glNormalPointer(GL_FLOAT, 0, piso_normais);
	glVertexPointer(3, GL_FLOAT, 0,  piso_vertices);
	glDrawElements(GL_TRIANGLES, piso_num_faces * 3, GL_UNSIGNED_INT, piso_faces);

	
	/* ------------------------------------------------------------------------------ */

	/*
		----------------------- DESENHO DO SOFA -------------------------
	*/
	
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, sofa_matAmbAndDif);
   	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, sofa_matSpec);
   	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, sofa_matShine);
	
	glVertexPointer(3, GL_FLOAT, 0, sofa_vertices);
	glNormalPointer(GL_FLOAT, 0, sofa_normais);
	glDrawElements(GL_TRIANGLES, sofa_num_faces * 3, GL_UNSIGNED_INT, sofa_faces);

	/* ---------------------------------------------------------------------- */

	/*
		----------------------- DESENHO DO ALMOFADAS SOFA -------------------------
	*/
	

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, almofadas_sofa_matAmbAndDif);
   	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, almofadas_sofa_matSpec);
   	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, almofadas_sofa_matShine);
	
	glVertexPointer(3, GL_FLOAT, 0, almofadas_sofa_vertices);
	glNormalPointer(GL_FLOAT, 0, almofadas_sofa_normais);
	glDrawElements(GL_TRIANGLES, almofadas_sofa_num_faces * 3, GL_UNSIGNED_INT, almofadas_sofa_faces);

	/* ---------------------------------------------------------------------- */

	/*
		----------------------- DESENHO DA POLTRONA -------------------------
	*/
	

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, poltrona_matAmbAndDif);
   	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, poltrona_matSpec);
   	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, poltrona_matShine);
	
	glVertexPointer(3, GL_FLOAT, 0, poltrona_vertices);
	glNormalPointer(GL_FLOAT, 0, poltrona_normais);
	glDrawElements(GL_TRIANGLES, poltrona_num_faces * 3, GL_UNSIGNED_INT, poltrona_faces);

	/* ---------------------------------------------------------------------- */

	/*
		----------------------- DESENHO DO ALMOFADAS DA POLTRONA -------------------------
	*/
	

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, almofadas_poltrona_matAmbAndDif);
   	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, almofadas_poltrona_matSpec);
   	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, almofadas_poltrona_matShine);
	
	glVertexPointer(3, GL_FLOAT, 0, almofadas_poltrona_vertices);
	glNormalPointer(GL_FLOAT, 0, almofadas_poltrona_normais);
	glDrawElements(GL_TRIANGLES, almofadas_poltrona_num_faces * 3, GL_UNSIGNED_INT, almofadas_poltrona_faces);

	/* ---------------------------------------------------------------------- */

	/*
		----------------------- DESENHO DAS MESAS -------------------------
	*/
	

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, mesas_matAmbAndDif);
   	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mesas_matSpec);
   	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mesas_matShine);
	
	glVertexPointer(3, GL_FLOAT, 0, mesas_vertices);
	glNormalPointer(GL_FLOAT, 0, mesas_normais);
	glDrawElements(GL_TRIANGLES, mesas_num_faces * 3, GL_UNSIGNED_INT, mesas_faces);

	/* ---------------------------------------------------------------------- */

		/*
		----------------------- DESENHO DAS ABAJUR -------------------------
	*/
	

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, abajur_matAmbAndDif);
   	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, abajur_matSpec);
   	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, abajur_matShine);
	
	glVertexPointer(3, GL_FLOAT, 0, abajur_vertices);
	glNormalPointer(GL_FLOAT, 0, abajur_normais);
	glDrawElements(GL_TRIANGLES, abajur_num_faces * 3, GL_UNSIGNED_INT, abajur_faces);

	/* ---------------------------------------------------------------------- */

			/*
		----------------------- DESENHO DAS ABAJUR SUPORTE -------------------------
	*/
	

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, abajur_suporte_matAmbAndDif);
   	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, abajur_suporte_matSpec);
   	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, abajur_suporte_matShine);
	
	glVertexPointer(3, GL_FLOAT, 0, abajur_suporte_vertices);
	glNormalPointer(GL_FLOAT, 0, abajur_suporte_normais);
	glDrawElements(GL_TRIANGLES, abajur_suporte_num_faces * 3, GL_UNSIGNED_INT, abajur_suporte_faces);

	/* ---------------------------------------------------------------------- */

				/*
		----------------------- DESENHO DO ARMARIO -------------------------
	*/
	
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, armario_matAmbAndDif);
   	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, armario_matSpec);
   	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, armario_matShine);
	
	glVertexPointer(3, GL_FLOAT, 0, armario_vertices);
	glNormalPointer(GL_FLOAT, 0, armario_normais);
	glDrawElements(GL_TRIANGLES, armario_num_faces * 3, GL_UNSIGNED_INT, armario_faces);

	/* ---------------------------------------------------------------------- */

					/*
		----------------------- DESENHO DO ARMARIO GAVETAS -------------------------
	*/
	
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, armario_gavetas_matAmbAndDif);
   	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, armario_gavetas_matSpec);
   	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, armario_gavetas_matShine);
	
	glVertexPointer(3, GL_FLOAT, 0, armario_gavetas_vertices);
	glNormalPointer(GL_FLOAT, 0, armario_gavetas_normais);
	glDrawElements(GL_TRIANGLES, armario_gavetas_num_faces * 3, GL_UNSIGNED_INT, armario_gavetas_faces);

	/* ---------------------------------------------------------------------- */

					/*
		----------------------- DESENHO DO ARMARIO PUXADORES -------------------------
	*/
	
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, armario_puxadores_matAmbAndDif);
   	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, armario_puxadores_matSpec);
   	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, armario_puxadores_matShine);
	
	glVertexPointer(3, GL_FLOAT, 0, armario_puxadores_vertices);
	glNormalPointer(GL_FLOAT, 0, armario_puxadores_normais);
	glDrawElements(GL_TRIANGLES, armario_puxadores_num_faces * 3, GL_UNSIGNED_INT, armario_puxadores_faces);

	/* ---------------------------------------------------------------------- */
	

	/* 
	-------------------------------Teste de Sombra-----------------------------------------------------
	*/
	

	/*------------------------------------------------------------------------------------------------------*/

	glFlush();
	glutSwapBuffers();
}

void setup(void)
{
	//prepararModelo();
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
   	
   	/* -------------------------------------------------------------------------- */
   	

   	/* ------------------ Parâmetros luz ambiente ------------------------------- */
   	float globAmb[] = {0.4, 0.4, 0.4, 1.0};   
   	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, globAmb); // Global ambient light.

   	/* ----------------------------------------------------------------------- */
   	

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

void printInteraction(void)
{
	cout << "Interaction: " << endl;
	cout << "Press ESC to exit" << endl;
}

int main(int argc, char **argv)
{
	printInteraction();

	/*Inicizaliação do glut*/
	glutInit(&argc, argv);
	
	/*Profundidade, buffer duplo e suporte a todas as cores*/
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);

	/*Posição da janela*/
	glutInitWindowPosition(100, 100);

	/*Tamanho da janela*/
	glutInitWindowSize(1000, 1000);
	
	/*Criação da janela passando o título*/
	glutCreateWindow("cenarioOPENGL");

	/*Cena que será renderizada*/
	glutDisplayFunc(drawScene);
	
	/*Irá dá um resize nos objetos criando a projeção especificada*/
	glutReshapeFunc(resize);

	/*Adição da operação de teclado*/
	glutKeyboardFunc(keyInput);

	/*Adição da operação de mouse*/
	glutMouseFunc(mouse);

	setup();

	glutMainLoop();

	return 0;
}