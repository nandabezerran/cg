//Para compilar: g++ main.cpp -o main -lGL -lGLU -lglut && ./main

#include <iostream>
#include <GL/freeglut.h>
#include <cmath>
#include "./main.h"

using namespace std;


void resize(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-30.0, 30.0, -30.0, 30.0, 2.0, 200.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void setup(void)
{

   glClearColor(0.12,0.3,0.45,0.2);
   glShadeModel(GL_SMOOTH);
   //Habilita o uso de iluminação
   glEnable(GL_LIGHTING);  

   // Habilita o depth-buffering
   glEnable(GL_DEPTH_TEST);

   glEnableClientState(GL_VERTEX_ARRAY);
   glEnableClientState(GL_NORMAL_ARRAY);
   glEnable(GL_NORMALIZE);

   makeMenu();

}

int main(int argc, char **argv)
{
	
	/*Print interação*/
	cout << "Interaction:\nPress ESC to exit" << endl;

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

	/*Cena que será renderizada (drawScene.h)*/
	glutDisplayFunc(drawScene);
	
	/*Irá dá um resize nos objetos criando a projeção especificada (menu.h)*/
	glutReshapeFunc(resize);

	/*Adição da operação de teclado (camera.h)*/
	glutKeyboardFunc(keyInput);

	/*Adição da operação de mouse (camera.h)*/
	glutMouseFunc(mouse);

	/* Inicializa (menu.h)*/
	setup();

	glutMainLoop();

	return 0;
}