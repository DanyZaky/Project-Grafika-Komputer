#include <iostream>
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

using namespace std;
float gravity = 0;
float kananKiri = 0;
float bintangJatuh = 0;
float bensinJatuh = 0;
bool jatuh = true;
bool flipped = true;

//COLLIDER ARRAY VARIABLE
float charaPosX[2] = {-20,20};
float charaPosY[2] = {-20,20};

float bensinPosX[2] = {-14,14};//28
float bensinPosY[2] = {-14,20};//34

void colliderCharacter()
{
    glPushMatrix();
    glTranslatef(180,320,0);
    glBegin(GL_POLYGON);
    glColor4ub(110,110,110,100);
        glVertex2f(charaPosX[0],charaPosY[0]);
        glVertex2f(charaPosX[1],charaPosY[0]);
        glVertex2f(charaPosX[1],charaPosY[1]);
        glVertex2f(charaPosX[0],charaPosY[1]);
    glEnd();
    glPopMatrix();
}

void colliderBensin()
{
    glPushMatrix();
    //glTranslatef(180,320,0);
    glBegin(GL_POLYGON);
    glColor4ub(255,255,255,90);
        glVertex2f(bensinPosX[0],bensinPosY[0]);
        glVertex2f(bensinPosX[1],bensinPosY[0]);
        glVertex2f(bensinPosX[1],bensinPosY[1]);
        glVertex2f(bensinPosX[0],bensinPosY[1]);
    glEnd();
    glPopMatrix();
}

void colliderBensin2()
{
    glPushMatrix();
    //glTranslatef(180,320,0);
    glBegin(GL_POLYGON);
    glColor4ub(255,100,100,125);
        glVertex2f(bensinPosX[0],bensinPosY[0]);
        glVertex2f(bensinPosX[1],bensinPosY[0]);
        glVertex2f(bensinPosX[1],bensinPosY[1]);
        glVertex2f(bensinPosX[0],bensinPosY[1]);
    glEnd();
    glPopMatrix();
}

void characterMovement(int timer)
{
    jatuh = true;
    //jatuhnya character
    if (jatuh == true)
    {
        charaPosY[0] -= 3;
        charaPosY[1] -= 3;

        gravity -= 3;
    }
    //gerak character kiri kanan
    if (GetAsyncKeyState(VK_RIGHT))
        {
            if (charaPosX[1] <= 180)
            {
                charaPosX[0] += 4;
                charaPosX[1] += 4;

                kananKiri += 4;
            }

            if (charaPosY[1] <= 320)
            {
                charaPosY[0] += 10;
                charaPosY[1] += 10;

                gravity += 10;
            }
        }
        else if (GetAsyncKeyState(VK_LEFT))
        {
            if (charaPosX[0] >= -180)
            {
                charaPosX[0] -= 4;
                charaPosX[1] -= 4;

                kananKiri -= 4;
            }

            if (charaPosY[1] <= 320)
            {
                charaPosY[0] += 10;
                charaPosY[1] += 10;

                gravity += 10;
            }
        }
    //detector collider player dan collider bensin
    if ((charaPosX[0] >= bensinPosX[0] && charaPosX[0] <= bensinPosX[1]) && (charaPosY[0] >= bensinPosY[0] && charaPosY[0] <= bensinPosY[1]))
    {
        //glClearColor(1.0,1.0,1.0,1.0);
        cout<<bensinPosX[0];
    }
    glutTimerFunc(5,characterMovement,0);
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
    //bensinPosY[0] -= 1;
    //bensinPosY[1] -= 1;

    glutTimerFunc(25,bensinMovement,0);
    glutPostRedisplay();
}

void mainCharacterMove(){


    glPushMatrix();
    colliderCharacter();
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
                colliderBensin();
                bensinObject1.bensinObject();
                glPopMatrix();

            glPopMatrix();
            glPopMatrix();
        glPopMatrix();
        bensinSpawn += 640;
    }
}

void displayMe()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.06,0.16,0.2,0);
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    glTranslatef(50,50,0);
    enemyObject1.enemyBobject();
    glPopMatrix();

    mainBintangSpawner();
    mainBensinSpawner();
    //colliderBensin();
    colliderBensin2();
    glPushMatrix();


    mainCharacterMove();
    glPopMatrix();

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
