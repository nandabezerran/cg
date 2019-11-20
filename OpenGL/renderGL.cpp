//Para compilar: g++ renderGL.cpp -o renderGL -lGL -lGLU -lGLEW -lglut -lm && ./renderGL

#include <iostream>
#include <GL/freeglut.h>
#include <GL/glext.h>
#include <cmath>

#include "./modelsGL.h"

using namespace std;



//float porta_faces_vertices[porta_num_faces * 3 * 3];

float rot = 0.0f;
float rot2 = 0.0f;


float transZ = 0.0f;
float transX = 0.0f;

float angleAlpha = 0.0f;
float angleBeta = 0.0f;
float pi = 3.14159265359;

/* -------------------------- PARÂMETROS DOS MATERIAIS ----------------------------------- */

	float matAmbAndDif1[] = {1.0, 0.5, 1.0, 1.0};
	float matAmbAndDifT[] = {0.7, 0.3, 0.7, 0.7};
   	float matAmbAndDif2[] = {0.5, 0.31, 1.0, 1.0};
   	float matAmbAndDif3[] = {0.0, 0.0, 0.9, 1.0};
   	float matSpec[] = {0.1, 0.1, 0.1, 1.0};
   	float matShine[] = {1.0};


   	float matAmbAndDifOuro[] = {0.75164f, 0.60648f, 0.22648f, 1.0f};
   	float matSpecOuro[] = {0.628281f, 0.555802f, 0.366065f, 1.0f};
   	float matShineOuro[] = {51.2};

   	float paredes_matAmbAndDif[] = {1.0, 0.5, 0.31, 1.0};
   	float paredes_matSpec[] = {0.1, 0.1, 0.1, 1.0};
   	float paredes_matShine[] = {1.0};

   	float piso_matAmbAndDif[] = {1.0, 0.5, 0.31, 1.0};
   	float piso_matSpec[] = {0.1, 0.1, 0.1, 1.0};
   	float piso_matShine[] = {1.0};

   	float sofa_matAmbAndDif[] = {1.0, 0.5, 0.31, 1.0};
   	float sofa_matSpec[] = {0.1, 0.1, 0.1, 1.0};
   	float sofa_matShine[] = {1.0};

   	float almofadas_sofa_matAmbAndDif[] = {1.0, 0.5, 0.31, 1.0};
   	float almofadas_sofa_matSpec[] = {0.1, 0.1, 0.1, 1.0};
   	float almofadas_sofa_matShine[] = {1.0};



/* ------------------------------------------------------------------------------------------ */   	


/*

	Funções para lidar com eventos do scroll do mouse e para criar o menu.
	O menu é ativado com um clique do botão direito do mouse.



*/


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

void top_menu(int id)
{
	if (id == 1) exit(0);
}

void color_menu(int id)
{
	if (id == 1) exit(0);
}

void paredes_menu(int id)
{
	if (id == 1) exit(0);
	if (id == 2)
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
	if (id == 1) exit(0);
	if (id == 2)
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
	if (id == 1) exit(0);
	if (id == 2)
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
	if (id == 1) exit(0);
	if (id == 2)
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
	int sub_menuParedes = glutCreateMenu(paredes_menu);
	glutAddMenuEntry("Sair", 1);
	glutAddMenuEntry("Ouro", 2);

	int sub_menuPiso = glutCreateMenu(piso_menu);
	glutAddMenuEntry("Sair", 1);
	glutAddMenuEntry("Ouro", 2);

	int sub_menuSofa = glutCreateMenu(sofa_menu);
	glutAddMenuEntry("Sair", 1);
	glutAddMenuEntry("Ouro", 2);

	int sub_menuAlmofadas_Sofa = glutCreateMenu(almofadas_sofa_menu);
	glutAddMenuEntry("Sair", 1);
	glutAddMenuEntry("Ouro", 2);

	int sub_menu;
	sub_menu = glutCreateMenu(color_menu);
	glutAddSubMenu("Paredes", sub_menuParedes);
	glutAddSubMenu("Piso", sub_menuPiso);
	glutAddSubMenu("Sofa", sub_menuSofa);
	glutAddSubMenu("Almofadas do Sofa", sub_menuAlmofadas_Sofa);
	glutAddMenuEntry("Sair", 1);

	glutCreateMenu(top_menu);
	glutAddSubMenu("Objeto", sub_menu);
	glutAddMenuEntry("Sair", 1);

	glutAttachMenu(GLUT_RIGHT_BUTTON);
}


/* -------------------------------------------------- */


void drawScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
	glLoadIdentity();
	
	
	glEnable(GL_LIGHT0);
   	

	/* ------------------------------------ TRANSFORMAÇÕES -------------------------------------- */
	glTranslatef(0.0, 0.0, -10.0); //  0.0 0.0 0.0
	glTranslatef(0.0 + transX , -50.0, 0.0 + transZ ); //transx + 8, 0.0, 0.0, 0.0+transZ-100
	glScalef(20.0, 20.0, 1.0);
	//glRotatef(-rot, 0, 1, 0);	
	/* ------------------------------------------------------------------------------------------- */
	

	/* ------------------------------------ DEFINIÇÃO DO OBSERVADOR ------------------------------------ */

	//gluLookAt(0.33 * cos(angle), 0.0, 0.33 * sin(angle), 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	gluLookAt( 0.33 * cos(angleBeta) * cos(angleAlpha), 0.33 * sin(angleBeta), 0.33 * cos(angleBeta) * sin(angleAlpha), 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	//gluLookAt( 1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0); //Em caso de projeção paralela. (Isométrica)
	

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
	glDrawElements(GL_TRIANGLES, almofadas_sofa_num_faces * 3, GL_UNSIGNED_INT, sofa_faces);

	/* ---------------------------------------------------------------------- */
	

	/* 
	-------------------------------Teste de Sombra-----------------------------------------------------
	*/
	

	/*------------------------------------------------------------------------------------------------------*/

	

	glFlush();
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

   	//float lightPos[] = {0.0, 20.0, 0.0 , 1.0};

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
	//float cabinet[16] = {1, 0, 0, 0, 0, 1, 0, 0, 5 * cos(0.523599), 5 * sin(0.523599), 1, 0, 0, 0, 0, 1};
	//float cavalier[16] = {1, 0, 0, 0, 0, 1, 0, 0, 3 , 3 , 1, 0, 0, 0, 0, 1};
	//glLoadMatrixf(cavalier);

	glFrustum(-30.0, 30.0, -30.0, 30.0, 2.0, 200.0);
	//glOrtho(-10.0, 10.0, -10.0, 10.0, -2.0, 200.0); //em caso de projeção paralela : isométrica
	
	glMatrixMode(GL_MODELVIEW);
	
	glLoadIdentity();

}


void keyInput(unsigned char key, int x, int y)
{
	switch(key)
	{
		case 27:
			exit(0);
			break;
		case 'q':
			rot += 50; //95
			glutPostRedisplay();
			break;
		case 'e':
			rot -= 50;
			glutPostRedisplay();
			break;
		case 'w':
			transZ += 1.0;
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
		case 'a':
			transX += 1.0;
			glutPostRedisplay();
			break;
		case 'z':
			angleAlpha += pi/6;
			glutPostRedisplay();
			break;	
		case 'x':
			angleAlpha -= pi/6;
			glutPostRedisplay();
			break;
		case 'Z':
			angleBeta += pi/6;
			glutPostRedisplay();
			break;
		case 'X':
			angleBeta -= pi/6;
			glutPostRedisplay();
			break;
		default:
			break;
	}
}

void printInteraction(void)
{
	cout << "Interaction: " << endl;
	cout << "Press ESC to exit" << endl;

}

int main(int argc, char **argv)
{
	printInteraction();
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(1000, 1000);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("cenarioOPENGL");
	glutDisplayFunc(drawScene);
	glutReshapeFunc(resize);
	glutKeyboardFunc(keyInput);
	glutMouseFunc(mouse);

	setup();

	glutMainLoop();

	return 0;
}