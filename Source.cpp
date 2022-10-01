//***********************************
// Author: Aqabal Alvarez (Alex)    *
// Course: CS3233                   *
// Project: Pentagonal Bipyramid    *
// Due date: 09/30/2022             *
//***********************************

#ifdef _WIN32
#include <GL/glut.h>
#elif __linux__
#include <GL/glut.h>
#elif __APPLE__
#define GL_SILENCE_DEPRECATION
#include <OpenGL/gl.h>
#include <GLUT/glut.h>
#endif
#include <iostream>
#include <math.h>

void display() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // glOrtho(left, right, bottom, top, near, far)
    glOrtho(-2.0f, 2.0f, -2.0f, 2.0f, -2.0f, 2.0f);

    //Getting the 5 points of the pentagonal bipyramid
    float pentaX[5];
    float pentaZ[5];
    int vertexNumber = 5;
    float radius = 1.2f;
    float twoPI = 2 * 3.14159;
    float x = 0, z = 0;
    for (int i = 0; i < 5; i++) {
        pentaX[i] = x + (radius * cosf(i * twoPI / vertexNumber));
        pentaZ[i] = z + (radius * sinf(i * twoPI / vertexNumber));
    }
    // Vertices for the pyramid
    float point[][3] = {
        {pentaX[0],0,pentaZ[0]}, {pentaX[1],0,pentaZ[1]}, {0,1.5,0},
        {pentaX[1],0,pentaZ[1]}, {pentaX[2],0,pentaZ[2]}, {0,1.5,0},
        {pentaX[2],0,pentaZ[2]}, {pentaX[3],0,pentaZ[3]}, {0,1.5,0},
        {pentaX[3],0,pentaZ[3]}, {pentaX[4],0,pentaZ[4]}, {0,1.5,0},
        {pentaX[4],0,pentaZ[4]}, {pentaX[0],0,pentaZ[0]}, {0,1.5,0},

        {pentaX[0],0,pentaZ[0]}, {pentaX[1],0,pentaZ[1]}, {0,-1.5,0},
        {pentaX[1],0,pentaZ[1]}, {pentaX[2],0,pentaZ[2]}, {0,-1.5,0},
        {pentaX[2],0,pentaZ[2]}, {pentaX[3],0,pentaZ[3]}, {0,-1.5,0},
        {pentaX[3],0,pentaZ[3]}, {pentaX[4],0,pentaZ[4]}, {0,-1.5,0},
        {pentaX[4],0,pentaZ[4]}, {pentaX[0],0,pentaZ[0]}, {0,-1.5,0},
    };

    glRotatef(25.0f, 1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLES);

    //Top Pyramid
    //1st Face
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3fv(point[0]);
    glVertex3fv(point[1]);
    glVertex3fv(point[2]);

    //2nd Face
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3fv(point[3]);
    glVertex3fv(point[4]);
    glVertex3fv(point[5]);

    //3rd Face
    glColor3f(1.0f, 0.65f, 0.0f);
    glVertex3fv(point[6]);
    glVertex3fv(point[7]);
    glVertex3fv(point[8]);

    //4th Face
    glColor3f(0.82f, 0.13f, 0.56f);
    glVertex3fv(point[9]);
    glVertex3fv(point[10]);
    glVertex3fv(point[11]);

    //5th Face
    glColor3f(0.63f, 0.13f, 0.94f);
    glVertex3fv(point[12]);
    glVertex3fv(point[13]);
    glVertex3fv(point[14]);

    //Bottom pyramid
    //1st Face
    glColor3f(0.0f, 0.0f, 0.5f);
    glVertex3fv(point[15]);
    glVertex3fv(point[16]);
    glVertex3fv(point[17]);

    //2nd Face
    glColor3f(0.52f, 0.42f, 1.0f);
    glVertex3fv(point[18]);
    glVertex3fv(point[19]);
    glVertex3fv(point[20]);

    //3rd Face
    glColor3f(0.0f, 1.0f, 1.0f);
    glVertex3fv(point[21]);
    glVertex3fv(point[22]);
    glVertex3fv(point[23]);

    //4th Face
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3fv(point[24]);
    glVertex3fv(point[25]);
    glVertex3fv(point[26]);

    //5th Face
    glColor3f(0.0f, 1.0f, 0.5f);
    glVertex3fv(point[27]);
    glVertex3fv(point[28]);
    glVertex3fv(point[29]);

    glEnd();

    glFlush();  // Render now
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(840, 840);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("Bypiramid");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
