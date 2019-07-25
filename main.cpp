//
// Created by petar on 24.7.19..
//
#include <iostream>
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>

void on_display();
void on_keyboard(unsigned char key, int x, int y);
void on_reshape(int w, int h);
void draw_coordinates();

int window_width = 500;
int window_height = 500;

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutInitWindowSize(window_width, window_height);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Drive");

    glutDisplayFunc(on_display);
    glutKeyboardFunc(on_keyboard);
    glutReshapeFunc(on_reshape);

    glClearColor(0.75, 0.75, 0.75, 0);

    glutMainLoop();
    return 0;
}

void on_display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(
            60,
            window_width/(float)window_height,
            1, 25);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(
            1.0, 1.0, 1.0,
            0.0, 0.0, 0.0,
            0.0, 1.0, 0.0
            );

    draw_coordinates();

    glBegin(GL_POLYGON);
        glVertex3f(0.5, 0, 0);
        glVertex3f(0.5, 0.5, 0);
        glVertex3f(0, 0.5, 0);
        glVertex3f(0, 0, 0);
    glEnd();
    glutSwapBuffers();
}

void on_reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei) w,  (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(
            60,
            w/(float)h,
            1, 25);
}

void on_keyboard(unsigned char key, int x, int y)
{
    switch(key) {
        case 27:
            exit(0);
            break;
    }
}

void draw_coordinates()
{
    glBegin(GL_LINES);
        // draws red x-axis
        glColor3f(1, 0, 0);
        glVertex3f(10, 0, 0);
        glVertex3f(-10, 0, 0);

        // draws green y-axis
        glColor3f(0, 1, 0);
        glVertex3f(0, 10, 0);
        glVertex3f(0, -10, 0);

        // draws blue z-axis
        glColor3f(0, 0, 1);
        glVertex3f(0, 0, 10);
        glVertex3f(0, 0, -10);
    glEnd();

}

