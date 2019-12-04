//Para compilar: g++ main.cpp -o main -lGL -lGLU -lglut && ./main

#include <iostream>
#include <GL/freeglut.h>
#include <cmath>
#include "./main.h"

using namespace std;


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