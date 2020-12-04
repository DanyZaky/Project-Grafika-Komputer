#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>
#include <windows.h>

//header
#include "karakter.h"

Karakter karakter1;

float gravity = 0;
float kananKiri = 0;
float bintangJatuh = 0;
float bensinJatuh = 0;

bool jatuh = true;
bool flip = true;

void traped(){
    glBegin(GL_QUADS);
    glColor3ub(240,141,3);

        glVertex2f(0,0);
        glVertex2f(0,20);
        glVertex2f(20,30);
        glVertex2f(20,0);
    glEnd();
    glFlush();
}

void animasiApi()
{
    glBegin(GL_QUADS);
    glColor3ub(240,141,3);

        glVertex2f(165,315);
        glVertex2f(170,315);
        glVertex2f(170,312);
        glVertex2f(165,312);

        glVertex2f(166,312);
        glVertex2f(169,312);
        glVertex2f(169,308);
        glVertex2f(166,308);

        glVertex2f(167,308);
        glVertex2f(168,308);
        glVertex2f(168,305);
        glVertex2f(167,305);

    glEnd();
    glFlush();
}

void bintang()
{
    glBegin(GL_QUADS);
    glColor3ub(182,182,183);
    glVertex2f(180,639);
    glVertex2f(182,639);
    glVertex2f(182,633);
    glVertex2f(180,633);

    glVertex2f(178,637);
    glVertex2f(178,635);
    glVertex2f(184,637);
    glVertex2f(184,635);

    glEnd();
    glFlush();
}

void bensin()
{
    glBegin(GL_QUADS);
    glColor3ub(182,182,183);
    glVertex2f(192,607);
    glVertex2f(173,607);
    glVertex2f(173,623);
    glVertex2f(192,623);

    glVertex2f(175,625);
    glVertex2f(190,625);
    glVertex2f(190,605);
    glVertex2f(175,605);

    glVertex2f(176,628);
    glVertex2f(176,625);
    glVertex2f(181,628);
    glVertex2f(181,625);

    glVertex2f(181,629);
    glVertex2f(181,627);
    glVertex2f(188,629);
    glVertex2f(188,626);

    glVertex2f(187,626);
    glVertex2f(187,625);
    glVertex2f(189,626);
    glVertex2f(189,625);

    glVertex2f(186,627);
    glVertex2f(188,627);
    glVertex2f(186,626);
    glVertex2f(188,626);

    glEnd();
    glFlush();
}


void characterMovement(int timer)
{
    //jatuhnya character
    if (jatuh == true)
    {
        gravity -= 3;
    }

    //gerak ke kanan dan kiri
    if (GetAsyncKeyState(VK_RIGHT))
    {
        gravity += 10;
        kananKiri += 7;
    }
    else if (GetAsyncKeyState(VK_LEFT))
    {
        gravity += 10;
        kananKiri -= 7;
    }
    glutTimerFunc(25,characterMovement,0);
    glutPostRedisplay();
}

void bintangMovement(int timer)
{
    bintangJatuh -= 1;

    glutTimerFunc(25,bintangMovement,0);
    glutPostRedisplay();
}

void bensinMovement(int timer)
{
    bensinJatuh -= 1;

    glutTimerFunc(25,bensinMovement,0);
    glutPostRedisplay();
}

void mainCharacterMove(){

    glPushMatrix();

    glTranslatef(kananKiri,gravity,0);
    karakter1.mainCharacter();

    if (GetAsyncKeyState(VK_RIGHT))
    {
        animasiApi();
    }
    if (GetAsyncKeyState(VK_LEFT))
    {
        animasiApi();
    }
    glPopMatrix();
}

void mainBintangSpawner()
{
    float bintangSpawn = 0;

    for (int i = 0; i<= 1000; i++)
    {
        glPushMatrix();
        glTranslatef(0,bintangSpawn,0);
            glPushMatrix();
            glTranslatef(0,bintangJatuh,0);
            bintang();
            glPopMatrix();
        glPopMatrix();
        bintangSpawn += 160;
    }
}

void mainBensinSpawner()
{
    float bensinSpawn = 0;

    for (int i = 0; i<= 1000; i++)
    {
        glPushMatrix();
        glTranslatef(0,bensinSpawn,0);
            glPushMatrix();
            glTranslatef(150,0,0);
            glPushMatrix();
            glTranslatef(0,bensinJatuh,0);
            bensin();
            glPopMatrix();
            glPopMatrix();
        glPopMatrix();
        bensinSpawn += 360;
    }
}

void displayMe()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.06,0.16,0.2,0);
    glMatrixMode(GL_MODELVIEW);

    mainBintangSpawner();
    mainBensinSpawner();
    mainCharacterMove();

    glFlush();
    glutSwapBuffers();
}

void myinit()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    glClearColor(0.0,0.8,1.0,1.0);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(500,760);
    glutCreateWindow("The Rocket Man");
    gluOrtho2D(0,360,0,640);

    glutDisplayFunc(displayMe);
    glutTimerFunc(1,characterMovement,0);
    glutTimerFunc(1,bintangMovement,0);
    glutTimerFunc(1,bensinMovement,0);
    myinit();
    glutMainLoop();
    return 0;
}
