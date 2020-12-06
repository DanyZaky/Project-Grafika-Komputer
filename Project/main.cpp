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
#include "enemy.h"

CharacterObjectClass characterObject1;
CharacterFireObjectClass characterFireObject1;
BensinObjectClass bensinObject1;
BintangObjectClass bintangObject1;
EnemyObjectClass enemyObject1;

float gravity = 0;
float kananKiri = 0;
float bintangJatuh = 0;
float bensinJatuh = 0;
bool jatuh = true;
bool flipped = true;

<<<<<<< HEAD
void enemyAobject()
{
    glBegin(GL_QUADS);
    glColor3ub(123,57,90);

    glVertex2f(-8.55,9);
    glVertex2f(10,9);
    glVertex2f(10,6);
    glVertex2f(-8.55,6);

    glVertex2f(-8.4,6);
    glVertex2f(14,6);
    glVertex2f(14,2.5);
    glVertex2f(-8.4,2.5);

    glVertex2f(-12,6);
    glVertex2f(-8.5,6);
    glVertex2f(-8.5,-0.5);
    glVertex2f(-12,-0.5);

    glVertex2f(-16,2.5);
    glVertex2f(-12,2.5);
    glVertex2f(-12,-18);
    glVertex2f(-16,-18);

    glVertex2f(-12.2,-10.7);
    glVertex2f(-8.46,-10.7);
    glVertex2f(-8.46,-14.5);
    glVertex2f(-12.2,-14.5);

    glVertex2f(-8.44,-14.56);
    glVertex2f(-4.76,-14.56);
    glVertex2f(-4.76,-17.9);
    glVertex2f(-8.44,-17.9);

    glColor3ub(176,75,135);

    glVertex2f(-8.55,5.9);
    glVertex2f(14,5.9);
    glVertex2f(14,2.5);
    glVertex2f(-8.55,2.5);

    glVertex2f(-12.15,-0.45);
    glVertex2f(-8.53,-0.45);
    glVertex2f(-8.53,-10.65);
    glVertex2f(-12.15,-10.65);

    glVertex2f(-8.43,-10.6);
    glVertex2f(17.56,-10.6);
    glVertex2f(17.56,-14.5);
    glVertex2f(-8.43,-14.5);

    glVertex2f(-8.55,-4.3);
    glVertex2f(17.52,-4.3);
    glVertex2f(17.52,-10.7);
    glVertex2f(-8.55,-10.7);

    glVertex2f(-1,6);
    glVertex2f(2.75,6);
    glVertex2f(2.75,-17.9);
    glVertex2f(-1,-17.9);

    glVertex2f(6.4,-0.92);
    glVertex2f(10.2,-0.92);
    glVertex2f(10.2,-17.95);
    glVertex2f(6.4,-17.95);

    glVertex2f(13.95,2.48);
    glVertex2f(17.59,2.48);
    glVertex2f(17.59,-17.9);
    glVertex2f(13.95,-17.9);

    glVertex2f(10.16,2.48);
    glVertex2f(17.59,2.48);
    glVertex2f(17.59,-0.83);
    glVertex2f(10.16,-0.83);

    glVertex2f(10.23,6);
    glVertex2f(13.85,6);
    glVertex2f(13.85,2.55);
    glVertex2f(10.23,2.55);

    glVertex2f(-4.74,-0.9);
    glVertex2f(-1.08,-0.9);
    glVertex2f(-1.08,-4.22);
    glVertex2f(-4.74,-4.22);

    glVertex2f(10.13,-0.91);
    glVertex2f(17.65,-0.91);
    glVertex2f(17.65,-4.31);
    glVertex2f(10.13,-4.31);

    glEnd();
}
void GreenEnemy()
{
    glBegin(GL_QUADS);
    glColor3ub(14,112,58);

    glVertex2f(-6,11.5);
    glVertex2f(6,11.5);
    glVertex2f(6,8.5);
    glVertex2f(-6,8.5);

    glVertex2f(-11,8.5);
    glVertex2f(-6,8.5);
    glVertex2f(-6,6);
    glVertex2f(-11,6);

    glVertex2f(-14,6);
    glVertex2f(-11,6);
    glVertex2f(-11,0);
    glVertex2f(-14,0);

    glVertex2f(-14,0);
    glVertex2f(-9.5,0);
    glVertex2f(-9.5,-3);
    glVertex2f(-14,-3);

    glVertex2f(-9.5,-3);
    glVertex2f(-6,-3);
    glVertex2f(-6,-6);
    glVertex2f(-9.5,-6);

    glVertex2f(-12.5,-6);
    glVertex2f(-6,-6);
    glVertex2f(-6,-8.5);
    glVertex2f(-12.5,-8.5);

    glVertex2f(-16,-8.5);
    glVertex2f(-9.5,-8.5);
    glVertex2f(-9.5,-11.5);
    glVertex2f(-16,-11.5);

    glColor3ub(0,115,76);
    glVertex2f(-6,8.5);
    glVertex2f(11,8.5);
    glVertex2f(11,6);
    glVertex2f(-6,6);

    glVertex2f(6,6);
    glVertex2f(11,6);
    glVertex2f(11,3);
    glVertex2f(6,3);

    glVertex2f(9.5,-8.5);
    glVertex2f(16,-8.5);
    glVertex2f(16,-11.5);
    glVertex2f(9.5,-11.5);

    glVertex2f(6,-6);
    glVertex2f(12.5,-6);
    glVertex2f(12.5,-8.5);
    glVertex2f(6,-8.5);

    glVertex2f(3,-3);
    glVertex2f(9.5,-3);
    glVertex2f(9.5,-6);
    glVertex2f(3,-6);

    glVertex2f(11,6);
    glVertex2f(14,6);
    glVertex2f(14,-3);
    glVertex2f(9.5,-3);

    glVertex2f(-3,-6);
    glVertex2f(3,-6);
    glVertex2f(3,-9);
    glVertex2f(-3,-9);

    glVertex2f(-6,3);
    glVertex2f(-3,3);
    glVertex2f(-3,-6);
    glVertex2f(-6,-6);

    glVertex2f(-9.5,0);
    glVertex2f(14,0);
    glVertex2f(14,-3);
    glVertex2f(-9.5,-3);

    glVertex2f(3,3);
    glVertex2f(6,3);
    glVertex2f(6,-6);
    glVertex2f(3,-6);

    glVertex2f(-11,6);
    glVertex2f(-6,6);
    glVertex2f(-6,3);
    glVertex2f(-11,3);

    glVertex2f(-3,8.5);
    glVertex2f(3,8.5);
    glVertex2f(3,-3);
    glVertex2f(-3,-3);

    glVertex2f(3,8.5);
    glVertex2f(6,8.5);
    glVertex2f(6,6);
    glVertex2f(3,6);
    glEnd();
}

void orangeEnemy()
{
    glBegin(GL_QUADS);
    glColor3ub(115,51,30);

    glVertex2f(-4,16);
    glVertex2f(4,16);
    glVertex2f(4,12);
    glVertex2f(-4,12);

    glVertex2f(-8,12);
    glVertex2f(-4,12);
    glVertex2f(-4,8);
    glVertex2f(-8,8);

    glVertex2f(-12,8);
    glVertex2f(-8,8);
    glVertex2f(-8,4);
    glVertex2f(-12,4);

    glVertex2f(-16,4);
    glVertex2f(-12,4);
    glVertex2f(-12,0);
    glVertex2f(-16,0);

    glVertex2f(-16,0);
    glVertex2f(-4,0);
    glVertex2f(-4,-4);
    glVertex2f(-16,-4);

    glVertex2f(-8,-4);
    glVertex2f(-4,-4);
    glVertex2f(-4,-8);
    glVertex2f(-8,-8);

    glVertex2f(-12,-8);
    glVertex2f(-8,-8);
    glVertex2f(-8,-12);
    glVertex2f(-12,-12);

    glVertex2f(-16,-12);
    glVertex2f(-12,-12);
    glVertex2f(-12,-16);
    glVertex2f(-16,-16);

    glVertex2f(-8,-12);
    glVertex2f(-4,-12);
    glVertex2f(-4,-16);
    glVertex2f(-8,-16);


    glColor3ub(240,67,35);

    glVertex2f(-4,12);
    glVertex2f(8,12);
    glVertex2f(8,8);
    glVertex2f(-4,8);

    glVertex2f(-8,8);
    glVertex2f(12,8);
    glVertex2f(12,4);
    glVertex2f(-8,4);

    glVertex2f(-12,4);
    glVertex2f(-8,4);
    glVertex2f(-8,0);
    glVertex2f(-12,0);

    glVertex2f(-8,0);
    glVertex2f(-4,0);
    glVertex2f(-4,-4);
    glVertex2f(-8,-4);

    glVertex2f(-4,12);
    glVertex2f(4,12);
    glVertex2f(4,-4);
    glVertex2f(-4,-4);

    glVertex2f(4,0);
    glVertex2f(8,0);
    glVertex2f(8,-4);
    glVertex2f(4,-4);

    glVertex2f(12,4);
    glVertex2f(16,4);
    glVertex2f(16,0);
    glVertex2f(12,0);

    glVertex2f(8,0);
    glVertex2f(16,0);
    glVertex2f(16,-4);
    glVertex2f(8,-4);

    glVertex2f(4,12);
    glVertex2f(8,12);
    glVertex2f(8,-4);
    glVertex2f(4,-4);

    glVertex2f(12,-12);
    glVertex2f(16,-12);
    glVertex2f(16,-16);
    glVertex2f(12,-16);

    glVertex2f(4,-4);
    glVertex2f(8,-4);
    glVertex2f(8,-8);
    glVertex2f(4,-8);

    glVertex2f(-4,-8);
    glVertex2f(4,-8);
    glVertex2f(4,-12);
    glVertex2f(-4,-12);

    glVertex2f(4,-12);
    glVertex2f(8,-12);
    glVertex2f(8,-16);
    glVertex2f(4,-16);

    glVertex2f(8,-8);
    glVertex2f(12,-8);
    glVertex2f(12,-12);
    glVertex2f(8,-12);

    glVertex2f(6,8.5);
    glVertex2f(11,8.5);
    glVertex2f(11,6);
    glVertex2f(6,6);


    glEnd();
}

=======
>>>>>>> 0274bd13ef81bec6f0298951df47f71ecfad9a04
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

    glPushMatrix();
    glTranslatef(50,50,0);
    enemyAobject();
    glPopMatrix();

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
