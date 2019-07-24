//
// Created by petar on 24.7.19..
//
#include <iostream>
#include <GL/glut.h>

void on_display();

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutInitWindowSize(300, 300);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Drive");

    glutDisplayFunc(on_display);

    glClearColor(0.75, 0.75, 0.75, 0);

    glutMainLoop();
    return 0;
}

void on_display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glutSwapBuffers();
}
