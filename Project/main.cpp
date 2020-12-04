#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>
#include <windows.h>

//header
#include "karakter.h"
#include "bintang.h"
#include "bensin.h"
#include "animasiapi.h"

Karakter karakter1;
Bintang bintang1;
Bensin bensin1;
AnimasiApi animasiapi1;

float gravity = 0;
float kananKiri = 0;
float bintangJatuh = 0;
float bensinJatuh = 0;

bool jatuh = true;
bool flip = true;
void enemyAobject()
{
    glBegin(GL_QUADS);
    glColor3ub(123,57,90);
    //rambut
    glVertex2f(-11,18);
    glVertex2f(11,18);
    glVertex2f(-11,14);
    glVertex2f(11,14);
    //rambut2
    glVertex2f(-16,14);
    glVertex2f(-12,14);
    glVertex2f(-16,6);
    glVertex2f(-12,6);
    //jambang
    glVertex2f(-20,10);
    glVertex2f(-16,10);
    glVertex2f(-20,-15);
    glVertex2f(-16,-15);
    //jambang2
    glVertex2f(-16,-6);
    glVertex2f(-12,-6);
    glVertex2f(-16,-11);
    glVertex2f(-12,-11);
    //kaki
    glVertex2f(-11,-11);
    glVertex2f(-7,-11);
    glVertex2f(-11,-15);
    glVertex2f(-7,-15);

    glColor3ub(176,75,135);
    //jidat
    glVertex2f(-11,14);
    glVertex2f(16,14);
    glVertex2f(-11,10);
    glVertex2f(16,10);
    //kanal
    glVertex2f(11,14);
    glVertex2f(16,14);
    glVertex2f(11,-11);
    glVertex2f(16,-11);
    //kanal2
    glVertex2f(15,10);
    glVertex2f(20,10);
    glVertex2f(15,-15);
    glVertex2f(20,-15);
    //telinga kiri
    glVertex2f(-16,6);
    glVertex2f(-12,6);
    glVertex2f(-16,-6);
    glVertex2f(-12,-6);
    //bawah mata kiri
    glVertex2f(-11,1);
    glVertex2f(-7,1);
    glVertex2f(-11,-11);
    glVertex2f(-7,-11);
    //tengah
    glVertex2f(-2,14);
    glVertex2f(2,14);
    glVertex2f(-2,-15);
    glVertex2f(2,-15);
    //bawah mata kanan
    glVertex2f(7,5);
    glVertex2f(11,5);
    glVertex2f(7,-15);
    glVertex2f(11,-15);
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
        animasiapi1.animasiApi();
    }
    if (GetAsyncKeyState(VK_LEFT))
    {
        animasiapi1.animasiApi();
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
            bintang1.bintang();
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
            bensin1.bensin();
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
    enemyAobject();
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
