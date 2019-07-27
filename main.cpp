//
// Created by petar on 24.7.19..
//
#include <iostream>
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <vector>
#include <algorithm>
#include "figures.h"

#define TIMER_ID 0
#define TIMER_INTERVAL 10

void on_timer(int value);
void on_display();
void on_keyboard(unsigned char key, int x, int y);
void on_reshape(int w, int h);
void init();

int window_width = 800;
int window_height = 500;
std::vector<float> camera_pos {1.0, 1.0, 1.0};

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

    init();


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
            camera_pos[0], camera_pos[1], camera_pos[2],
            0.0, 0.0, 0.0,
            0.0, 1.0, 0.0
            );

    ground();
    coordinates();
    car();

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

    glutPostRedisplay();
}


void init()
{
    glClearColor(0.75, 0.75, 0.75, 0);
    glEnable(GL_DEPTH_TEST);
}

