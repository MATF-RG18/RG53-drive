//
// Created by petar on 24.7.19..
//
#include <iostream>
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <vector>
#include <algorithm>

#define TIMER_ID 0
#define TIMER_INTERVAL 10


void on_timer(int value);
void on_display();
void on_keyboard(unsigned char key, int x, int y);
void on_reshape(int w, int h);
void draw_coordinates();
void car();
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

    draw_coordinates();

    //ground
    glPushMatrix();
    glColor3d(30, 30, 0);
    glBegin(GL_POLYGON);
        glVertex3f(10, -0.05, 10);
        glVertex3f(10, -0.05, -10);
        glVertex3f(-10, -0.05, -10);
        glVertex3f(-10, -0.05, 10);
    glEnd();
    glPopMatrix();

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

void init()
{
    glClearColor(0.75, 0.75, 0.75, 0);
    glEnable(GL_DEPTH_TEST);
}

void car()
{
    GLfloat size = 0.2;
    GLfloat wheel_init = 0.1;

    // vozilo
    glPushMatrix();
        glColor3f(0, 0, 0);
        glTranslatef(0, 0.1, 0);
        glutWireCube(size);
    glPopMatrix();

    // prednji tockovi
    glPushMatrix();
        glColor3f(1, 0, 1);
        glTranslatef(-wheel_init, 0, -wheel_init);
        // levi tocak
        glutWireSphere(0.05, 10, 10);

        glTranslatef(2 * wheel_init, 0, 0);
        // desni tocak
        glutWireSphere(0.05, 10, 10);
    glPopMatrix();

    // zadnji tockovi
    glPushMatrix();
        glTranslatef(-wheel_init, 0, wheel_init);
        // levi tocak
        glutWireSphere(0.05, 10, 10);

        glTranslatef(2 * wheel_init, 0, 0);
        // desni tocak
        glutWireSphere(0.05, 10, 10);
    glPopMatrix();

}
