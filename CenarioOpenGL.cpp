//#include <GL/glut.h>
//#include <cmath>
//#define M_PI 3.14159265358979323846
//
//class GlPonto{
//public:
//    GLfloat x;
//    GLfloat y;
//    GLfloat z;
//};
//
//GLint faces[6][4] = {  /* Vertex indices for the 6 faces of a cube. */
//        {0, 1, 2, 3}, {3, 2, 6, 7}, {7, 6, 5, 4},
//        {4, 5, 1, 0}, {5, 6, 2, 1}, {7, 4, 0, 3} };
//
//GlPonto pontos[8];
//int mode = 2;
//double alpha = -45.0;
//
//void glObl(){
//    double axoMatrix[16];
//    glGetDoublev(GL_MODELVIEW_MATRIX, axoMatrix);
//    double angle = (M_PI / 180.0f) * alpha;
//    if (mode == 1){
//        axoMatrix[8]= -cos(angle);
//        axoMatrix[9]= sin(angle);
//    }
//    if(mode == 2){
//        axoMatrix[8]= -cos(angle)/2;
//        axoMatrix[9]= sin(angle)/2;
//    }
//
//    glMultMatrixd(axoMatrix);
//}
//
//void drawBox(void){
//    int i;
//    for (i = 0; i < 6; i++) {
//        glBegin(GL_LINE_LOOP);
//        glColor3f(0.9f,0.4f,1.0f);
//        glVertex3f(pontos[faces[i][0]].x,pontos[faces[i][0]].y,pontos[faces[i][0]].z);
//        glVertex3f(pontos[faces[i][1]].x,pontos[faces[i][1]].y,pontos[faces[i][1]].z);
//        glVertex3f(pontos[faces[i][2]].x,pontos[faces[i][2]].y,pontos[faces[i][2]].z);
//        glVertex3f(pontos[faces[i][3]].x,pontos[faces[i][3]].y,pontos[faces[i][3]].z);
//        glEnd();
//    }
//}
//
//void display(void){
//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//    glObl();
//    drawBox();
//    glutSwapBuffers();
//}
//
//void resize(int w, int h) {
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    glOrtho(-10.0, 10.0, -10.0, 10.0, 1.0, 10.0);
//}
//
//static void glutKeyboard(unsigned char key, int x, int y) {
//    switch(key) {
//        case '1':
//            mode = 1;
//            break;
//        case '2':
//            mode = 2;
//            break;
//        case 'a':
//            alpha += 0.5f;
//    }
//    glLoadIdentity();
//    glOrtho(-10.0, 10.0, -10.0, 10.0, 1.0, 10.0);
//    display();
//}
//
//void init(void){
//    pontos[0] = GlPonto{-1.0, -1.0, -3.0};
//    pontos[1] = GlPonto{-1.0, -1.0, -5.0};
//    pontos[2] = GlPonto{-1.0, 1.0, -5.0};
//    pontos[3] = GlPonto{-1.0, 1.0, -3.0};
//
//    pontos[4] = GlPonto{1.0, -1.0, -3.0};
//    pontos[5] = GlPonto{1.0, -1.0, -5.0};
//    pontos[6] = GlPonto{1.0, 1.0, -5.0};
//    pontos[7] = GlPonto{1.0, 1.0, -3.0};
//
//    glEnable(GL_DEPTH_TEST);
//
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    glOrtho(-10.0, 10.0, -10.0, 10.0, 1.0, 10.0);
//
//}
//
//int main(int argc, char **argv){
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
//    glutInitWindowPosition(100,100);
//    glutInitWindowSize(320, 320);
//    glutCreateWindow("Trabalhim Top");
//    glutDisplayFunc(display);
//    init();
//    glutReshapeFunc(resize);
//    glutKeyboardFunc(glutKeyboard);
//    glutMainLoop();
//    return 0;
//}
