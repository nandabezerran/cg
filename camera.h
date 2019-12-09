double objx, objy, objz;
/* PARÂMETROS DOS MOVIMENTOS DA CÂMERA */

float rot = 0.0f;
float rot2 = 0.0f;

float transZ = 0.0f;
float transX = 0.0f;

float angleAlpha = 45.0f;
float angleBeta = -6.0f;
float pi = 3.14159265359;

/* PARÂMETROS DE VIZUALIZAÇÃO DOS OBJETOS */

bool show_sofas = true;
bool show_almofadas = true;
bool show_travesseiros = true;
bool show_mesas = true;
bool show_abajur = true;
bool show_suporte = true;
bool show_armario = true;
bool show_gavetas = true;
bool show_arvore = true;
bool show_vaso = true;
bool show_estantes = true;
bool show_livros = true;
bool show_relogio = true;
bool show_quadros = true;
bool show_molduras = true;
bool show_piso = true;
bool show_paredes = true;

/* PARÂMETROS DE VIZUALIZAÇÃO DAS LUZES */

bool show_ambiente = true;
bool show_difusa = true;
bool show_especular = true;



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

void processMouse(int button, int state, int x, int y)
{
    double modelview[16], projection[16];
    int viewport[4];
    float z;
    
	//get the modelview matrix		
    glGetDoublev( GL_MODELVIEW_MATRIX, modelview );
    //get the projection matrix
    glGetDoublev( GL_PROJECTION_MATRIX, projection );
	//get the viewport		
    glGetIntegerv( GL_VIEWPORT, viewport );
	
    //Read the window z co-ordinate 
    //(the z value on that point in unit cube)		
    glReadPixels( x, viewport[3]-y, 1, 1,
		 GL_DEPTH_COMPONENT, GL_FLOAT, &z );
 
    //Unproject the window co-ordinates to 
    //find the world co-ordinates.
    gluUnProject( x, viewport[3]-y, z, modelview, 
		projection, viewport, &objx, &objy, &objz );
 
    std::cout << objx << " , " << objy << " , " << objz << "\n";
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
			angleBeta += pi/9;
			glutPostRedisplay();
			break;
		case 'A':
			angleAlpha += pi/9;
			glutPostRedisplay();
			break;
		case 'S':
			angleBeta -= pi/9;
			glutPostRedisplay();
			break;	
		case 'D':
			angleAlpha -= pi/9;
			glutPostRedisplay();
			break;
		default:
			break;
	}
}

/*---------------------------------------*/
