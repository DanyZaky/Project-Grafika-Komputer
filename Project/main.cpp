#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>
#include <windows.h>

//HEADER
#include "character.h"
#include "character-fire.h"
#include "bensin.h"
#include "bintang.h"

CharacterObjectClass characterObject1;
CharacterFireObjectClass characterFireObject1;
BensinObjectClass bensinObject1;
BintangObjectClass bintangObject1;

float gravity = 0;
float kananKiri = 0;
float bintangJatuh = 0;
float bensinJatuh = 0;
bool jatuh = true;
bool flipped = true;

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
    glEnd();
}


void characterMovement(int timer)
{
    jatuh = true;
    //jatuhnya character
    if (jatuh == true)
    {
        gravity -= 3;
    }
    else if (jatuh == false)
    {
        gravity -=3;
        kananKiri += 7;
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

    if (GetAsyncKeyState(VK_RIGHT))
    {
        flipped = true;

        glPushMatrix();
        glTranslatef(180,320,0);
        characterFireObject1.characterFireObject();
        glPopMatrix();
    }
    else if (GetAsyncKeyState(VK_LEFT))
    {
        flipped = false;

        glPushMatrix();
        glTranslatef(180,320,0);
        glRotatef(180,0,1,0);
        characterFireObject1.characterFireObject();
        glPopMatrix();
    }

    if (flipped == true)
    {
        glPushMatrix();
        glTranslatef(180,320,0);
        characterObject1.characterObject();
        glPopMatrix();
    }
    else if (flipped == false)
    {
        glPushMatrix();
        glTranslatef(180,320,0);
        glRotatef(180,0,1,0);
        characterObject1.characterObject();
        glPopMatrix();
    }
    glPopMatrix();
}

void mainBintangSpawner()
{
    float bintangSpawn = 0;

    for (int i = 0; i<= 10000; i++)
    {
        glPushMatrix();
        glTranslatef(0,bintangSpawn,0);
        glPushMatrix();

            float bintangPos;

            if (i%9 == 0)
            {
                bintangPos = 148;
            }
            else if (i%9 == 1)
            {
                bintangPos = 290;
            }
            else if (i%9 == 2)
            {
                bintangPos = 105;
            }
            else if (i%9 == 3)
            {
                bintangPos = 117;
            }
            else if (i%9 == 4)
            {
                bintangPos = 269;
            }
            else if (i%9 == 5)
            {
                bintangPos = 223;
            }
            else if (i%9 == 6)
            {
                bintangPos = 135;
            }
            else if (i%9 == 7)
            {
                bintangPos = 258;
            }
            else if (i%9 == 8)
            {
                bintangPos = 56;
            }
            else
            {
                bintangPos = 305;
            }

            glTranslatef(bintangPos,0,0);

            glPushMatrix();
            glTranslatef(0,bintangJatuh,0);
            bintangObject1.bintangObject();
            glPopMatrix();
            glPopMatrix();
        glPopMatrix();
        bintangSpawn += 100;
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

            float bensinPos;

            if (i%9 == 0)
            {
                bensinPos = 20;
            }
            else if (i%9 == 1)
            {
                bensinPos = 312;
            }
            else if (i%9 == 2)
            {
                bensinPos = 31;
            }
            else if (i%9 == 3)
            {
                bensinPos = 326;
            }
            else if (i%9 == 4)
            {
                bensinPos = 14;
            }
            else if (i%9 == 5)
            {
                bensinPos = 339;
            }
            else if (i%9 == 6)
            {
                bensinPos = 24;
            }
            else if (i%9 == 7)
            {
                bensinPos = 324;
            }
            else if (i%9 == 8)
            {
                bensinPos = 43;
            }
            else
            {
                bensinPos = 340;
            }

            glTranslatef(bensinPos,0,0);
            glPushMatrix();
            glTranslatef(0,bensinJatuh,0);

                glPushMatrix();
                glTranslatef(0,650,0);
                bensinObject1.bensinObject();
                glPopMatrix();

            glPopMatrix();
            glPopMatrix();
        glPopMatrix();
        bensinSpawn += 640*3;
    }
}

void displayMe()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.06,0.16,0.2,0);
    glMatrixMode(GL_MODELVIEW);

    /*glPushMatrix();
    glTranslatef(50,50,0);
    bintangObject();
    glPopMatrix();*/

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
    glutInitWindowSize(360,640);
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
