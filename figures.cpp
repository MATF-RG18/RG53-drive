//
// Created by petar on 27.7.19..
//

#include "figures.h"

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

void coordinates()
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

void ground()
{
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
}
