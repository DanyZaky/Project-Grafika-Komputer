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

float bensin = 100;

using namespace std;
float gravity = 0;
float kananKiri = 0;
float bintangJatuh = 0;
float bensinJatuh = 0;
float enemyA_jatuh = 0;
float enemyB_jatuh = 0;
float enemyC_jatuh = 0;

float particleAtas;
float particleBawah;
float particleKanan;
float particleKiri;
float opacityParticle = 255;

bool jatuh = true;
bool flipped = true;
bool destroyBensin = false;
bool destroyBensin2 = false;

//COLLIDER ARRAY VARIABLE
float charaPosX[2] = {160,200};
float charaPosY[2] = {340,300};

float posXben[2];
float posXben2[2];
float posYben[2] = {660,626};
float posYben2[2] = {660+640,626+640};

void particleEffectBensin()
{
    glPushMatrix();
    glTranslatef(20,20,0);
    glBegin(GL_QUADS);
    glColor4ub(255,255,255,opacityParticle);
        glVertex2f(2,2);
        glVertex2f(2,-2);
        glVertex2f(-2,-2);
        glVertex2f(-2,2);
    glEnd();
    glPopMatrix();
}

void particleEffectBensinSpawner()
{
    glPushMatrix();
    glTranslatef(0,particleAtas,0);
    particleEffectBensin();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,particleBawah,0);
    particleEffectBensin();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(particleKanan,0,0);
    particleEffectBensin();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(particleKiri,0,0);
    particleEffectBensin();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(particleKanan,particleAtas,0);
    particleEffectBensin();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(particleKiri,particleAtas,0);
    particleEffectBensin();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(particleKanan,particleBawah,0);
    particleEffectBensin();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(particleKiri,particleBawah,0);
    particleEffectBensin();
    glPopMatrix();
}

void particleEffectBensinTimer(int timer)
{
    float ms = 0.5;

    particleAtas += ms;
    particleBawah -= ms;
    particleKanan += ms;
    particleKiri -= ms;

    opacityParticle -= 3.5;

    glutTimerFunc(50,particleEffectBensinTimer,0);
    glutPostRedisplay();
}

void colliderCharacter()
{
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor4ub(110,110,110,0);
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
    glBegin(GL_POLYGON);
    glColor4ub(255,255,255,0);
        glVertex2f(posXben[0],posYben[0]);
        glVertex2f(posXben[1],posYben[0]);
        glVertex2f(posXben[1],posYben[1]);
        glVertex2f(posXben[0],posYben[1]);
    glEnd();
    glPopMatrix();
}

void colliderBensin2()
{
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor4ub(255,255,255,0);
        glVertex2f(posXben2[0],posYben2[0]);
        glVertex2f(posXben2[1],posYben2[0]);
        glVertex2f(posXben2[1],posYben2[1]);
        glVertex2f(posXben2[0],posYben2[1]);
    glEnd();
    glPopMatrix();
}

void scoreCharacter(int timer)
{
    bensin -= 1;

    glutTimerFunc(700,scoreCharacter,0);
    glutPostRedisplay();
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
            if (charaPosX[1] <= 360)
            {
                charaPosX[0] += 4;
                charaPosX[1] += 4;

                kananKiri += 4;
            }

            if (charaPosY[0] <= 640)
            {
                charaPosY[0] += 10;
                charaPosY[1] += 10;

                gravity += 10;
            }
        }
        else if (GetAsyncKeyState(VK_LEFT))
        {
            if (charaPosX[0] >= 0)
            {
                charaPosX[0] -= 4;
                charaPosX[1] -= 4;

                kananKiri -= 4;
            }

            if (charaPosY[0] <= 640)
            {
                charaPosY[0] += 10;
                charaPosY[1] += 10;

                gravity += 10;
            }
        }

    glutTimerFunc(5,characterMovement,0);
    glutPostRedisplay();
}

void bintangMovement(int timer)
{
    //bintang move down
    bintangJatuh -= 1;

    glutTimerFunc(25,bintangMovement,0);
    glutPostRedisplay();
}

void bensinMovement(int timer)
{
    float gravityBensin = 2.5;
    //object move down
    bensinJatuh -= gravityBensin;
    //collider move down
    posYben[0] -= gravityBensin;
    posYben[1] -= gravityBensin;

    posYben2[0] -= gravityBensin;
    posYben2[1] -= gravityBensin;

    //collision collider bensin to collider character

    glutTimerFunc(25,bensinMovement,0);
    glutPostRedisplay();
}

void enemyA_Movement(int timer)
{
    float gravityEnemyA = 1;

    enemyA_jatuh -= gravityEnemyA;

    glutTimerFunc(25,enemyA_Movement,0);
    glutPostRedisplay();
}

void enemyB_Movement(int timer)
{
    float gravityEnemyB = 1;

    enemyB_jatuh -= gravityEnemyB;

    glutTimerFunc(25,enemyB_Movement,0);
    glutPostRedisplay();
}

void enemyC_Movement(int timer)
{
    float gravityEnemyC = 1;

    enemyC_jatuh -= gravityEnemyC;

    glutTimerFunc(25,enemyC_Movement,0);
    glutPostRedisplay();
}

void mainCharacterMove()
{

    glPushMatrix();

    glTranslated(kananKiri,gravity,0);

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

            if (i%2 == 0)
            {
                bensinPos = 34;
            }
            else if (i%2 == 1)
            {
                bensinPos = 324;
            }
            glTranslatef(bensinPos,0,0);
            glPushMatrix();
            glTranslatef(0,bensinJatuh,0);

                glPushMatrix();
                glTranslatef(0,640,0);
                bensinObject1.bensinObject();
                glPopMatrix();

            glPopMatrix();
            glPopMatrix();
        glPopMatrix();
        bensinSpawn += 640;
    }
}

void enemyA_Spawner() //damage high
{
    float enemyA_Spawn = 0;
    for (int i = 0; i<= 1000; i++)
    {
        glPushMatrix();
        glTranslatef(0,enemyA_Spawn,0);
            glPushMatrix();

            float enemyA_Pos;

            if (i%2 == 0)
            {
                enemyA_Pos = 80;
            }
            else if (i%2 == 1)
            {
                enemyA_Pos = 260;
            }
            glTranslatef(enemyA_Pos,0,0);
            glPushMatrix();
            glTranslatef(0,enemyA_jatuh,0);

                glPushMatrix();
                glTranslatef(0,840,0);
                enemyObject1.enemyAobject();
                glPopMatrix();

            glPopMatrix();
            glPopMatrix();
        glPopMatrix();
        enemyA_Spawn += 740;
    }
}

void enemyB_Spawner() // damage low
{
    float enemyB_Spawn = 0;
    for (int i = 0; i<= 1000; i++)
    {
        glPushMatrix();
        glTranslatef(0,enemyB_Spawn,0);
            glPushMatrix();

            float enemyB_Pos;

            if (i%3 == 0)
            {
                enemyB_Pos = 64;
            }
            else if (i%3 == 1)
            {
                enemyB_Pos = 250;
            }
            else if (i%3 == 2)
            {
                enemyB_Pos == 165;
            }
            glTranslatef(enemyB_Pos,0,0);
            glPushMatrix();
            glTranslatef(0,enemyB_jatuh,0);

                glPushMatrix();
                glTranslatef(0,500,0);
                enemyObject1.enemyBobject();
                glPopMatrix();

            glPopMatrix();
            glPopMatrix();
        glPopMatrix();
        enemyB_Spawn += 250;
    }
}

void enemyC_Spawner() // damage mid
{
    float enemyC_Spawn = 0;
    for (int i = 0; i<= 1000; i++)
    {
        glPushMatrix();
        glTranslatef(0,enemyC_Spawn,0);
            glPushMatrix();

            float enemyC_Pos;

            if (i%2 == 0)
            {
                enemyC_Pos = 120;
            }
            else if (i%2 == 1)
            {
                enemyC_Pos = 195;
            }
            glTranslatef(enemyC_Pos,0,0);
            glPushMatrix();
            glTranslatef(0,enemyC_jatuh,0);

                glPushMatrix();
                glTranslatef(0,640,0);
                enemyObject1.enemyCobject();
                glPopMatrix();

            glPopMatrix();
            glPopMatrix();
        glPopMatrix();
        enemyC_Spawn += 450;
    }
}

void mainBensinColliderSpawner()
{
    //COLLIDER BENSIN KIRI
    posXben[0] = 20;
    posXben[1] = 48;
    colliderBensin();

    if (posYben[0] <= -14)
    {
        destroyBensin = false;
        posYben[0] += 640*2;
        posYben[1] += 640*2;
        bensinObject1.opacity = 255;
    }
    //COLLIDER BENSIN KANAN
    posXben2[0] = 310;
    posXben2[1] = 338;
    colliderBensin2();

    if (posYben2[0] <= -14)
    {
        destroyBensin2 = false;
        posYben2[0] += 640*2;
        posYben2[1] += 640*2;
        bensinObject1.opacity = 255;
    }

    //COLIISON COLIIDER BENSIN TO COLLIDER CHARACTER
    if (
            ((charaPosX[0] >= posXben[0] && charaPosX[0] <= posXben[1]) && (charaPosY[0] <= posYben[0] && charaPosY[0] >= posYben[1])) ||
            ((charaPosX[1] >= posXben[0] && charaPosX[1] <= posXben[1]) && (charaPosY[0] <= posYben[0] && charaPosY[0] >= posYben[1])) ||
            ((charaPosX[1] >= posXben[0] && charaPosX[1] <= posXben[1]) && (charaPosY[1] <= posYben[1] && charaPosY[1] >= posYben[1])) ||
            ((charaPosX[0] >= posXben[0] && charaPosX[0] <= posXben[1]) && (charaPosY[1] <= posYben[0] && charaPosY[1] >= posYben[1]))
            )
    {
        if (destroyBensin == false)
        {
            destroyBensin = true;
            bensin += 10;
            if (bensin >= 100)
            {
                bensin = 100;
            }
            cout << bensin << endl;
            bensinObject1.opacity = 0;
        }
    }

    if (
            ((charaPosX[0] >= posXben2[0] && charaPosX[0] <= posXben2[1]) && (charaPosY[0] <= posYben2[0] && charaPosY[0] >= posYben2[1])) ||
            ((charaPosX[1] >= posXben2[0] && charaPosX[1] <= posXben2[1]) && (charaPosY[0] <= posYben2[0] && charaPosY[0] >= posYben2[1])) ||
            ((charaPosX[1] >= posXben2[0] && charaPosX[1] <= posXben2[1]) && (charaPosY[1] <= posYben2[1] && charaPosY[1] >= posYben2[1])) ||
            ((charaPosX[0] >= posXben2[0] && charaPosX[0] <= posXben2[1]) && (charaPosY[1] <= posYben2[0] && charaPosY[1] >= posYben2[1]))
            )
    {
        if (destroyBensin2 == false)
        {
            destroyBensin2 = true;
            bensin += 10;
            if (bensin >= 100)
            {
                bensin = 100;
            }
            cout << bensin << endl;
            bensinObject1.opacity = 0;
        }
    }
}

void displayMe()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.06,0.16,0.2,0);
    glMatrixMode(GL_MODELVIEW);

    particleEffectBensinSpawner();

    enemyA_Spawner();
    enemyB_Spawner();
    enemyC_Spawner();

    mainBintangSpawner();

    mainBensinColliderSpawner();
    mainBensinSpawner();

    colliderCharacter();
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
    glutTimerFunc(1,scoreCharacter,0);
    glutTimerFunc(1,enemyA_Movement,0);
    glutTimerFunc(1,enemyB_Movement,0);
    glutTimerFunc(1,enemyC_Movement,0);
    glutTimerFunc(1,particleEffectBensinTimer,0);

    myinit();
    glutMainLoop();
    return 0;
}
