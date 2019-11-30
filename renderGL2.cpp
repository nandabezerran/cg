//Para compilar: g++ renderGL.cpp -o renderGL -lGL -lGLU -lglut && ./renderGL

#include <iostream>
#include <GL/freeglut.h>
#include <cmath>

#include "./modelsGL.h"
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

void drawScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //Limpa e cria os dois buffers que serão utilzados (color: atual, buffer: próximo)
	glLoadIdentity(); //Carrega a matriz identidade
	
	glTranslatef(0.0, 0.0, -10.0); //Coloca os objetos a uma distancia Z do observador (Quanto menor mais longe)
	glTranslatef(0.0 + transX , -50.0, 0.0 + transZ ); //Coloca os objetos na posição 0 + transX = 0 (x), -50 (y) e 0+transZ = 0 (z)
	glScalef(10.0, 20.0, 0.8); //Realiza uma escala nos objetos

	/*Define as caracteristicas do observador. Todas as variáveis são 0 inicialmente*/

	/* Em ordem:

	(x,y,z) -- posição do olho (observador)
	(centerX,centerY,centerZ) -- posição do ponto de referencia
	(upX, upY, upZ) -- direção do vetor up 

	*/

	gluLookAt(cos(angleBeta) * cos(angleAlpha),  sin(angleBeta), cos(angleBeta) * sin(angleAlpha), 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	/* Objeto 1: Paredes */

	glVertexPointer(3, GL_FLOAT, 0,  paredes_vertices);
	glNormalPointer(GL_FLOAT, 0, paredes_normais);
	glDrawElements(GL_TRIANGLES, paredes_num_faces * 3, GL_UNSIGNED_INT, paredes_faces);

	/* ----------------- */

	/* Objeto 2: Piso */

	glNormalPointer(GL_FLOAT, 0, piso_normais);
	glVertexPointer(3, GL_FLOAT, 0,  piso_vertices);
	glDrawElements(GL_TRIANGLES, piso_num_faces * 3, GL_UNSIGNED_INT, piso_faces);

	/* ----------------- */	

	/*Troca de buffer logo mostra as operações feitas no buffer na tela*/
	glutSwapBuffers();
}

void setup(void){
    glClearColor(0.0,0.0,0.0,1.0);
    glEnable(GL_DEPTH_TEST);
	
	glEnable(GL_LIGHTING); //Ativa o recurso de iluminação

	glEnableClientState(GL_VERTEX_ARRAY); //Habilita o uso de um array de vertices para ser utilizado no glDrawElements
	glEnableClientState(GL_NORMAL_ARRAY); //Habilida o uso de array de normais 	(imprescindível para calculo da luz)
	glEnable(GL_RESCALE_NORMAL); // Mais eficiente que o GL_NORMALIZE
	/*glEnable(GL_NORMALIZE);*/ //Vetores são normalizados para tamanho unitário depois da transformação e antes da iluminação
	
	makeMenu();
}

void resize(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION); //Define a matriz de projeção
	glLoadIdentity(); //Carrega a matriz identidade
	
	/*left: -30 right: 30 bottom: -30 top: 30 near:2 far:200*/
	glFrustum(-30.0, 30.0, -30.0, 30.0, 2.0, 200.0);

	/*2D: x = [-10:10] e y=[-10:10]
	/*gluOrtho2D(-10,10,-10,10);*/

    /*zNear = 2 e zFar = 50 (objetos no z = -2 ao -50)*/
	/*fovy = 60 (angulo na direcao y) aspect = 1 (proporcao)*/
    /*gluPerspective(60,1,2,50.0);*/

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
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);

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

	/*Funções extras para o funcionamento da janela*/
	setup();

	glutMainLoop();

	return 0;
}