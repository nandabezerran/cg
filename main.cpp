#include <GL/glew.h>
#include <GL/gl.h>
#include <GLFW/glfw3.h>
#include <GL/glut.h>
#include <vector>
#include <fstream>
#include <iostream>
#include "C:\MinGW\glm\glm.hpp"
#include "tiny_obj_loader.h"

using namespace std;

#define TINYOBJLOADER_IMPLEMENTATION // define this in only *one* .cc
#include "tiny_obj_loader.h"

GLint attribute_v_coord = -1;
GLint attribute_v_normal = -1;
GLuint vbo_mesh_vertices, vbo_mesh_normals;

void load_obj(const char* filename, vector<glm::vec4> &vertices, vector<glm::vec3> &normals, vector<GLushort> &elements)
{
    ifstream in(filename, ios::in);
    if (!in)
    {
        cerr << "Cannot open " << filename << endl; exit(1);
    }

    string line;
    while (getline(in, line))
    {
        if (line.substr(0,2) == "v ")
        {
            istringstream s(line.substr(2));
            glm::vec4 v; s >> v.x; s >> v.y; s >> v.z; v.w = 1.0f;
            vertices.push_back(v);
        }
        else if (line.substr(0,2) == "f ")
        {
            istringstream s(line.substr(2));
            GLushort a,b,c;
            s >> a; s >> b; s >> c;
            a--; b--; c--;
            elements.push_back(a); elements.push_back(b); elements.push_back(c);
        }
        else if (line[0] == '#')
        {
            /* ignoring this line */
        }
        else
        {
            /* ignoring this line */
        }
    }

    normals.resize(vertices.size(), glm::vec3(0.0, 0.0, 0.0));
    for (int i = 0; i < elements.size(); i+=3)
    {
        GLushort ia = elements[i];
        GLushort ib = elements[i+1];
        GLushort ic = elements[i+2];
        glm::vec3 normal = glm::normalize(glm::cross(
                glm::vec3(vertices[ib]) - glm::vec3(vertices[ia]),
                glm::vec3(vertices[ic]) - glm::vec3(vertices[ia])));
        normals[ia] = normals[ib] = normals[ic] = normal;
    }
}



void wall(double thickness)
{
    glPushMatrix();
    glTranslated(0.5,0.5*thickness,0.5);
    glScaled(1.0,thickness,1.0);
    glutSolidCube(1.0);
    glPopMatrix();
}


void Blender(void) {

    vector<glm::vec4> table_vertices;
    vector<glm::vec3> table_normals;
    vector<GLushort> table_elements;
    load_obj("mesa.obj", table_vertices, table_normals, table_elements);
    glEnableVertexAttribArray(attribute_v_coord);
    // Describe our vertices array to OpenGL (it can't guess its format automatically)
    glBindBuffer(GL_ARRAY_BUFFER, vbo_mesh_vertices);
    glVertexAttribPointer(
            attribute_v_coord,  // attribute
            4,                  // number of elements per vertex, here (x,y,z,w)
            GL_FLOAT,           // the type of each element
            GL_FALSE,           // take our values as-is
            0,                  // no extra data between each position
            0                   // offset of first element
    );

    glEnableVertexAttribArray(attribute_v_normal);
    glBindBuffer(GL_ARRAY_BUFFER, vbo_mesh_normals);
    glVertexAttribPointer(
            attribute_v_normal, // attribute
            3,                  // number of elements per vertex, here (x,y,z)
            GL_FLOAT,           // the type of each element
            GL_FALSE,           // take our values as-is
            0,                  // no extra data between each position
            0                   // offset of first element
    );
    int ibo_mesh_elements;
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo_mesh_elements);
    int size;  glGetBufferParameteriv(GL_ELEMENT_ARRAY_BUFFER, GL_BUFFER_SIZE, &size);
    glDrawElements(GL_TRIANGLES, size/sizeof(GLushort), GL_UNSIGNED_SHORT, 0);

}



void displaySolid(void) {


    GLfloat mat_ambient[]={0.7f,0.7f,0.7f,1.0f};
    GLfloat mat_diffuse[]={0.5f,0.5f,0.5f,1.0f};
    GLfloat mat_specular[]={1.0f,1.0f,1.0f,1.0f};
    GLfloat mat_shininess[]={50.0f};

    glMaterialfv(GL_FRONT,GL_AMBIENT,mat_ambient);
    glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse);
    glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular);
    glMaterialfv(GL_FRONT,GL_SHININESS,mat_shininess);
    GLfloat lightIntensity[]={0.7f,0.7f,0.7f,0.7f};
    GLfloat light_position[]={2.0f,6.0f,3.0f,0.0f};

    //The glLightfv function returns light source parameter values.
    glLightfv(GL_LIGHT0,GL_POSITION,light_position);
    glLightfv(GL_LIGHT0,GL_DIFFUSE,lightIntensity);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    double winHt=1.0;
    glOrtho(-winHt*64/48.0,winHt*64/48.0,-winHt,winHt,0.1,100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(2.3,1.3,2.0,0.0,0.25,0.0,0.0,1.0,0.0);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();

    glTranslatef ( 0.0f, -2.0f, 0.0f );

    glPushMatrix();
    glTranslated(0.4,0.4,0.6);
    glRotated(45,0,0,1);
    glScaled(0.08,0.08,0.08);
    glPopMatrix();
    glPushMatrix();
    glTranslated(0.6,0.38,0.5);
    glRotated(30,0,1,0);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.25,0.42,0.35);
    glPopMatrix();
    glPushMatrix();
    glTranslated(0.4,0,0.4);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.4,0.4,0.6);
    glRotated(45,0,0,1);
    glScaled(0.08,0.08,0.08);
    glPopMatrix();
    glPushMatrix();
    glTranslated(0.6,0.38,0.5);
    glRotated(30,0,1,0);
    Blender;
    glPopMatrix();


    wall(0.02);
    glPushMatrix();
    glRotated(90.0,0.0,0.0,1.0);    //draw second wall after rotating x axis by 90degre
    wall(0.02);
    glPopMatrix();
    glPushMatrix();
    glRotated(-90.0,1.0,0.0,0.0);   //draw floor
    wall(0.02);
    glPopMatrix();
    glFlush();
}

int main(int argc,char **argv) {
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Simple shaded scene consisting of a teapot");
    glutDisplayFunc(displaySolid);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glShadeModel(GL_SMOOTH);//Specifies a symbolic value representing a shading technique. Accepted values are GL_FLAT and GL_SMOOTH.
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);
    glClearColor(0.1,0.1,0.1,0.0);
    glViewport(0,0,640,480);
    glutMainLoop();
}