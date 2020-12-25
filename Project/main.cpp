#include <iostream>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>
#include <windows.h>
#include <stdio.h>
//HEADER
#include "character.h"
#include "character-fire.h"
#include "bensin.h"
#include "bintang.h"
#include "enemy.h"
#include "particle-effect-character-damaged.h"
#include "game-ui.h"

CharacterObjectClass characterObject1;
CharacterFireObjectClass characterFireObject1;

BensinObjectClass bensinObject1;
BensinObjectClass bensinObject2;

BintangObjectClass bintangObject1;

EnemyObjectClass enemyObject1;
EnemyColliderClass enemyCollider1;
EnemyColliderClass enemyCollider2;

ParticleEffectCharacterClass particleEffectCharacter1;
ParticleEffectCharacterClass particleEffectCharacter2;
ParticleEffectCharacterClass particleEffectCharacter3;
ParticleEffectCharacterClass particleEffectCharacter4;
ParticleEffectCharacterClass particleEffectCharacter5;
ParticleEffectCharacterClass particleEffectCharacter6;

GameUI_Class game_ui;

using namespace std;

//CHARACTER
float gravity = 0;
float kananKiri = 0;
bool jatuh = true;
bool flipped = true;

//BINTANG
float bintangJatuh = 0;

//BENSIN
float bensinJatuh = 0;

//ENEMY
float enemyA_jatuh = 0;
float enemyB_jatuh = 0;
float enemyC_jatuh = 0;
float dmgCooldown = 5;

//ANIMASI OBJECT
bool membesar = false;
float scale = 1;
int scoreChara;
char cetakScore[1000];
bool gameBerjalan = true;
bool scoreBertambah = true;

//GAME UI
float bensin = 100;
bool kalah = false;

void resetDmgCooldown()
{
    dmgCooldown = 2;
    cout<<"Nabrak"<<endl;
}

void gameUI_timer(int timer)
{
    bensin -= 1;

    if (scoreBertambah = true)
    {
        scoreChara += 1;
    }

    if (dmgCooldown >= 0) {dmgCooldown -= 0.5;}
    glutTimerFunc(700,gameUI_timer,0);
    glutPostRedisplay();
}

void particleEffectBensinTimer(int timer)
{
    bensinObject1.particleAtas += bensinObject1.ms;
    bensinObject1.particleBawah -= bensinObject1.ms;
    bensinObject1.particleKanan += bensinObject1.ms;
    bensinObject1.particleKiri -= bensinObject1.ms;

    bensinObject1.opacityParticle -= 3.5;

    bensinObject2.particleAtas += bensinObject2.ms;
    bensinObject2.particleBawah -= bensinObject2.ms;
    bensinObject2.particleKanan += bensinObject2.ms;
    bensinObject2.particleKiri -= bensinObject2.ms;

    bensinObject2.opacityParticle -= 3.5;

    glutTimerFunc(50,particleEffectBensinTimer,0);
    glutPostRedisplay();
}

void particleEffectCharacterTimer(int timer)
{
    particleEffectCharacter1.particleAtasCharacter += particleEffectCharacter1.msPartChara;
    particleEffectCharacter1.particleBawahCharacter -= particleEffectCharacter1.msPartChara;
    particleEffectCharacter1.particleKananCharacter += particleEffectCharacter1.msPartChara;
    particleEffectCharacter1.particleKiriCharacter -= particleEffectCharacter1.msPartChara;

    particleEffectCharacter2.particleAtasCharacter += particleEffectCharacter2.msPartChara;
    particleEffectCharacter2.particleBawahCharacter -= particleEffectCharacter2.msPartChara;
    particleEffectCharacter2.particleKananCharacter += particleEffectCharacter2.msPartChara;
    particleEffectCharacter2.particleKiriCharacter -= particleEffectCharacter2.msPartChara;

    particleEffectCharacter3.particleAtasCharacter += particleEffectCharacter3.msPartChara;
    particleEffectCharacter3.particleBawahCharacter -= particleEffectCharacter3.msPartChara;
    particleEffectCharacter3.particleKananCharacter += particleEffectCharacter3.msPartChara;
    particleEffectCharacter3.particleKiriCharacter -= particleEffectCharacter3.msPartChara;

    particleEffectCharacter4.particleAtasCharacter += particleEffectCharacter4.msPartChara;
    particleEffectCharacter4.particleBawahCharacter -= particleEffectCharacter4.msPartChara;
    particleEffectCharacter4.particleKananCharacter += particleEffectCharacter4.msPartChara;
    particleEffectCharacter4.particleKiriCharacter -= particleEffectCharacter4.msPartChara;

    particleEffectCharacter5.particleAtasCharacter += particleEffectCharacter5.msPartChara;
    particleEffectCharacter5.particleBawahCharacter -= particleEffectCharacter5.msPartChara;
    particleEffectCharacter5.particleKananCharacter += particleEffectCharacter5.msPartChara;
    particleEffectCharacter5.particleKiriCharacter -= particleEffectCharacter5.msPartChara;

    particleEffectCharacter6.particleAtasCharacter += particleEffectCharacter6.msPartChara;
    particleEffectCharacter6.particleBawahCharacter -= particleEffectCharacter6.msPartChara;
    particleEffectCharacter6.particleKananCharacter += particleEffectCharacter6.msPartChara;
    particleEffectCharacter6.particleKiriCharacter -= particleEffectCharacter6.msPartChara;

    particleEffectCharacter1.opacityParticleCharacter -= 3.5;
    particleEffectCharacter2.opacityParticleCharacter -= 3.5;
    particleEffectCharacter3.opacityParticleCharacter -= 3.5;
    particleEffectCharacter4.opacityParticleCharacter -= 3.5;
    particleEffectCharacter5.opacityParticleCharacter -= 3.5;
    particleEffectCharacter6.opacityParticleCharacter -= 3.5;

    glutTimerFunc(50,particleEffectCharacterTimer,0);
    glutPostRedisplay();
}

void characterMovement(int timer)
{
    jatuh = true;
    //jatuhnya character
    if (jatuh == true)
    {
        characterObject1.charaPosY[0] -= 3;
        characterObject1.charaPosY[1] -= 3;

        gravity -= 3;
    }
    //gerak character kiri kanan
    if (GetAsyncKeyState(VK_RIGHT))
        {
            if (characterObject1.charaPosX[1] <= 360)
            {
                characterObject1.charaPosX[0] += 4;
                characterObject1.charaPosX[1] += 4;

                kananKiri += 4;
            }

            if (characterObject1.charaPosY[0] <= 640)
            {
                characterObject1.charaPosY[0] += 10;
                characterObject1.charaPosY[1] += 10;

                gravity += 10;
            }
        }
        else if (GetAsyncKeyState(VK_LEFT))
        {
            if (characterObject1.charaPosX[0] >= 0)
            {
                characterObject1.charaPosX[0] -= 4;
                characterObject1.charaPosX[1] -= 4;

                kananKiri -= 4;
            }

            if (characterObject1.charaPosY[0] <= 640)
            {
                characterObject1.charaPosY[0] += 10;
                characterObject1.charaPosY[1] += 10;

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
    float gravityBensin = 1;
    //object move down
    bensinJatuh -= gravityBensin;
    //collider move down
    bensinObject1.posYben[0] -= gravityBensin;
    bensinObject1.posYben[1] -= gravityBensin;

    bensinObject2.posYben2[0] -= gravityBensin;
    bensinObject2.posYben2[1] -= gravityBensin;

    //collision collider bensin to collider character

    glutTimerFunc(25,bensinMovement,0);
    glutPostRedisplay();
}

void enemyA_Movement(int timer)
{
    float gravityEnemyA = 1.5;

    enemyA_jatuh -= gravityEnemyA;

    enemyCollider1.posYenemyA[0] -= gravityEnemyA;
    enemyCollider1.posYenemyA[1] -= gravityEnemyA;

    enemyCollider2.posYenemyA2[0] -= gravityEnemyA;
    enemyCollider2.posYenemyA2[1] -= gravityEnemyA;

    glutTimerFunc(25,enemyA_Movement,0);
    glutPostRedisplay();
}

void enemyB_Movement(int timer)
{
    float gravityEnemyB = 1;

    enemyB_jatuh -= gravityEnemyB;

    enemyCollider1.posYenemyB[0] -= gravityEnemyB;
    enemyCollider1.posYenemyB[1] -= gravityEnemyB;

    enemyCollider2.posYenemyB2[0] -= gravityEnemyB;
    enemyCollider2.posYenemyB2[1] -= gravityEnemyB;

    glutTimerFunc(25,enemyB_Movement,0);
    glutPostRedisplay();
}

void enemyC_Movement(int timer)
{
    float gravityEnemyC = 1.25;

    enemyC_jatuh -= gravityEnemyC;

    enemyCollider1.posYenemyC[0] -= gravityEnemyC;
    enemyCollider1.posYenemyC[1] -= gravityEnemyC;

    enemyCollider2.posYenemyC2[0] -= gravityEnemyC;
    enemyCollider2.posYenemyC2[1] -= gravityEnemyC;

    glutTimerFunc(25,enemyC_Movement,0);
    glutPostRedisplay();
}

void animasiObject(int timer)
{
    if(scale >= 1){
       membesar = false;
    }
    else if (scale <= 0.8)
    {
       membesar = true;
    }

    if (membesar == false)
    {
       scale -= 0.02;
    }
    else if (membesar == true)
    {
        scale += 0.02;
    }
    glutTimerFunc(50,animasiObject,0);
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

    if (characterObject1.charaPosY[0] <= 0 && kalah == false)
    {
        kalah = true;
        cout<<"Kalah"<<endl;
        bensin -= 100;
    }
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
                glPushMatrix();
                glScalef(scale,scale,0);
                bensinObject1.bensinObject();
                glPopMatrix();
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
                glPushMatrix();
                glScalef(scale,scale,0);
                enemyObject1.enemyAobject();
                glPopMatrix();
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

            if (i%2 == 0)
            {
                enemyB_Pos = 64;
            }
            else if (i%2 == 1)
            {
                enemyB_Pos = 225;
            }
            glTranslatef(enemyB_Pos,0,0);
            glPushMatrix();
            glTranslatef(0,enemyB_jatuh,0);

                glPushMatrix();
                glTranslatef(0,500,0);
                glPushMatrix();
                glScalef(scale,scale,0);
                enemyObject1.enemyBobject();
                glPopMatrix();
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
                glPushMatrix();
                glScalef(scale,scale,0);
                enemyObject1.enemyCobject();
                glPopMatrix();
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
    bensinObject1.posXben[0] = 20;
    bensinObject1.posXben[1] = 48;
    bensinObject1.colliderBensin();

    if (bensinObject1.posYben[0] <= -14)
    {
        bensinObject1.destroyBensin = false;
        bensinObject1.posYben[0] += 640*2;
        bensinObject1.posYben[1] += 640*2;
        bensinObject1.opacity = 255;
    }
    //COLLIDER BENSIN KANAN
    bensinObject2.posXben[0] = 310;
    bensinObject2.posXben[1] = 338;
    bensinObject2.colliderBensin();

    if (bensinObject2.posYben2[0] <= -14)
    {
        bensinObject2.destroyBensin = false;
        bensinObject2.posYben2[0] += 640*2;
        bensinObject2.posYben2[1] += 640*2;
        bensinObject1.opacity = 255;
    }

    //COLIISON COLIIDER BENSIN TO COLLIDER CHARACTER
    if (
            ((characterObject1.charaPosX[0] >= bensinObject1.posXben[0] && characterObject1.charaPosX[0] <= bensinObject1.posXben[1]) && (characterObject1.charaPosY[0] <= bensinObject1.posYben[0] && characterObject1.charaPosY[0] >= bensinObject1.posYben[1])) ||
            ((characterObject1.charaPosX[1] >= bensinObject1.posXben[0] && characterObject1.charaPosX[1] <= bensinObject1.posXben[1]) && (characterObject1.charaPosY[0] <= bensinObject1.posYben[0] && characterObject1.charaPosY[0] >= bensinObject1.posYben[1])) ||
            ((characterObject1.charaPosX[1] >= bensinObject1.posXben[0] && characterObject1.charaPosX[1] <= bensinObject1.posXben[1]) && (characterObject1.charaPosY[1] <= bensinObject1.posYben[1] && characterObject1.charaPosY[1] >= bensinObject1.posYben[1])) ||
            ((characterObject1.charaPosX[0] >= bensinObject1.posXben[0] && characterObject1.charaPosX[0] <= bensinObject1.posXben[1]) && (characterObject1.charaPosY[1] <= bensinObject1.posYben[0] && characterObject1.charaPosY[1] >= bensinObject1.posYben[1]))
            )
    {
        bensinObject1.particleMuncul = true;

        if (bensinObject1.destroyBensin == false)
        {
            bensinObject1.destroyBensin = true;
            bensin += 10;
            if (bensin >= 100)
            {
                bensin = 100;
            }

            bensinObject1.opacity = 0;
        }
    }

    if (
            ((characterObject1.charaPosX[0] >= bensinObject2.posXben[0] && characterObject1.charaPosX[0] <= bensinObject2.posXben[1]) && (characterObject1.charaPosY[0] <= bensinObject2.posYben2[0] && characterObject1.charaPosY[0] >= bensinObject2.posYben2[1])) ||
            ((characterObject1.charaPosX[1] >= bensinObject2.posXben[0] && characterObject1.charaPosX[1] <= bensinObject2.posXben[1]) && (characterObject1.charaPosY[0] <= bensinObject2.posYben2[0] && characterObject1.charaPosY[0] >= bensinObject2.posYben2[1])) ||
            ((characterObject1.charaPosX[1] >= bensinObject2.posXben[0] && characterObject1.charaPosX[1] <= bensinObject2.posXben[1]) && (characterObject1.charaPosY[1] <= bensinObject2.posYben2[1] && characterObject1.charaPosY[1] >= bensinObject2.posYben2[1])) ||
            ((characterObject1.charaPosX[0] >= bensinObject2.posXben[0] && characterObject1.charaPosX[0] <= bensinObject2.posXben[1]) && (characterObject1.charaPosY[1] <= bensinObject2.posYben2[0] && characterObject1.charaPosY[1] >= bensinObject2.posYben2[1]))
            )
    {
        bensinObject2.particleMuncul = true;

        if (bensinObject2.destroyBensin == false)
        {
            bensinObject2.destroyBensin = true;
            bensin += 10;
            if (bensin >= 100)
            {
                bensin = 100;
            }

            bensinObject1.opacity = 0;
        }
    }

    if (bensinObject1.particleMuncul == true)
    {
        bensinObject1.ms = 0.5;

        float posX_particle = bensinObject1.posXben[0]-10;
        float posY_particle = bensinObject1.posYben[1];

        glPushMatrix();
        glTranslatef(posX_particle,posY_particle,0);
        bensinObject1.particleEffectBensinSpawner();
        glPopMatrix();
    }
    else if (bensinObject1.particleMuncul == false)
    {
        bensinObject1.particleAtas = 0;
        bensinObject1.particleBawah = 0;
        bensinObject1.particleKanan = 0;
        bensinObject1.particleKiri = 0;

        bensinObject1.opacityParticle = 255;

        bensinObject1.ms = 0;
    }

    if (bensinObject1.opacityParticle <= 0)
    {
        bensinObject1.particleMuncul = false;
    }

    if (bensinObject2.particleMuncul == true)
    {
        bensinObject2.ms = 0.5;

        float posX_particle = bensinObject2.posXben[0]-10;
        float posY_particle = bensinObject2.posYben2[1];

        glPushMatrix();
        glTranslatef(posX_particle,posY_particle,0);
        bensinObject2.particleEffectBensinSpawner();
        glPopMatrix();
    }
    else if (bensinObject2.particleMuncul == false)
    {
        bensinObject2.particleAtas = 0;
        bensinObject2.particleBawah = 0;
        bensinObject2.particleKanan = 0;
        bensinObject2.particleKiri = 0;
        bensinObject2.opacityParticle = 255;

        bensinObject2.ms = 0;
    }

    if (bensinObject2.opacityParticle <= 0)
    {
        bensinObject2.particleMuncul = false;
    }

    if (bensin <= 0)
    {
        bensin = 0;
        cout << "lu dah kalah oy" << endl;
    }

}

void mainEnemyA_colliderSpawner()
{
    enemyCollider1.posXenemyA[0] = 62;
    enemyCollider1.posXenemyA[1] = 99;
    enemyCollider1.colliderEnemyA();

    if (enemyCollider1.posYenemyA[0] <= 0)
    {
        enemyCollider1.posYenemyA[0] += 740*2;
        enemyCollider1.posYenemyA[1] += 740*2;
    }

    enemyCollider2.posXenemyA[0] = 242;
    enemyCollider2.posXenemyA[1] = 280;
    enemyCollider2.colliderEnemyA();

    if (enemyCollider2.posYenemyA2[0] <= 0)
    {
        enemyCollider2.posYenemyA2[0] += 740*2;
        enemyCollider2.posYenemyA2[1] += 740*2;
    }
    //Fungsi Collision player and colliderEnemyA
    if ((
            ((characterObject1.charaPosX[0] >= enemyCollider1.posXenemyA[0] && characterObject1.charaPosX[0] <= enemyCollider1.posXenemyA[1]) && (characterObject1.charaPosY[0] <= enemyCollider1.posYenemyA[0] && characterObject1.charaPosY[0] >= enemyCollider1.posYenemyA[1])) ||
            ((characterObject1.charaPosX[1] >= enemyCollider1.posXenemyA[0] && characterObject1.charaPosX[1] <= enemyCollider1.posXenemyA[1]) && (characterObject1.charaPosY[0] <= enemyCollider1.posYenemyA[0] && characterObject1.charaPosY[0] >= enemyCollider1.posYenemyA[1])) ||
            ((characterObject1.charaPosX[1] >= enemyCollider1.posXenemyA[0] && characterObject1.charaPosX[1] <= enemyCollider1.posXenemyA[1]) && (characterObject1.charaPosY[1] <= enemyCollider1.posYenemyA[0] && characterObject1.charaPosY[1] >= enemyCollider1.posYenemyA[1])) ||
            ((characterObject1.charaPosX[0] >= enemyCollider1.posXenemyA[0] && characterObject1.charaPosX[0] <= enemyCollider1.posXenemyA[1]) && (characterObject1.charaPosY[1] <= enemyCollider1.posYenemyA[0] && characterObject1.charaPosY[1] >= enemyCollider1.posYenemyA[1]))
        ) && (dmgCooldown <= 0))
    {
        particleEffectCharacter1.particleMuncul = true;

        resetDmgCooldown();
        bensin -= 10;
    }
    //Fungsi Collision player and colliderEnemyA2
    if ((
            ((characterObject1.charaPosX[0] >= enemyCollider2.posXenemyA[0] && characterObject1.charaPosX[0] <= enemyCollider2.posXenemyA[1] ) && (characterObject1.charaPosY[0] <= enemyCollider2.posYenemyA2[0]  && characterObject1.charaPosY[0] >= enemyCollider2.posYenemyA2[1] )) ||
            ((characterObject1.charaPosX[1] >= enemyCollider2.posXenemyA[0] && characterObject1.charaPosX[1] <= enemyCollider2.posXenemyA[1] ) && (characterObject1.charaPosY[0] <= enemyCollider2.posYenemyA2[0]  && characterObject1.charaPosY[0] >= enemyCollider2.posYenemyA2[1] )) ||
            ((characterObject1.charaPosX[1] >= enemyCollider2.posXenemyA[0] && characterObject1.charaPosX[1] <= enemyCollider2.posXenemyA[1] ) && (characterObject1.charaPosY[1] <= enemyCollider2.posYenemyA2[0]  && characterObject1.charaPosY[1] >= enemyCollider2.posYenemyA2[1] )) ||
            ((characterObject1.charaPosX[0] >= enemyCollider2.posXenemyA[0] && characterObject1.charaPosX[0] <= enemyCollider2.posXenemyA[1] ) && (characterObject1.charaPosY[1] <= enemyCollider2.posYenemyA2[0]  && characterObject1.charaPosY[1] >= enemyCollider2.posYenemyA2[1] ))
        ) && (dmgCooldown <= 0))
    {
        particleEffectCharacter2.particleMuncul = true;

        resetDmgCooldown();
        bensin -= 10;
    }

    if (particleEffectCharacter1.particleMuncul == true)
    {
        particleEffectCharacter1.msPartChara = 0.5;

        float posXpart_chara = ((enemyCollider1.posXenemyA[1] - enemyCollider1.posXenemyA[0]) / 2 ) + enemyCollider1.posXenemyA[0];
        float posYpart_chara = ((enemyCollider1.posYenemyA[1] - enemyCollider1.posYenemyA[0]) / 2 ) + enemyCollider1.posYenemyA[0];

        glPushMatrix();
        glTranslatef(posXpart_chara,posYpart_chara,0);
        particleEffectCharacter1.ParticleEffectCharacterSpawner();
        glPopMatrix();
    }
    else if (particleEffectCharacter1.particleMuncul == false)
    {
        particleEffectCharacter1.particleAtasCharacter = 0;
        particleEffectCharacter1.particleBawahCharacter = 0;
        particleEffectCharacter1.particleKananCharacter = 0;
        particleEffectCharacter1.particleKiriCharacter = 0;

        particleEffectCharacter1.opacityParticleCharacter = 255;
        particleEffectCharacter1.msPartChara = 0;
    }

    if (particleEffectCharacter1.opacityParticleCharacter <= 0)
    {
        particleEffectCharacter1.particleMuncul = false;
    }

    //=================== particle 2 ===================
    if (particleEffectCharacter2.particleMuncul == true)
    {
        particleEffectCharacter2.msPartChara = 0.5;

        float posXpart_chara = ((enemyCollider2.posXenemyA[1] - enemyCollider2.posXenemyA[0]) / 2 ) + enemyCollider2.posXenemyA[0];
        float posYpart_chara = ((enemyCollider2.posYenemyA2[1] - enemyCollider2.posYenemyA2[0]) / 2 ) + enemyCollider2.posYenemyA2[0];

        glPushMatrix();
        glTranslatef(posXpart_chara,posYpart_chara,0);
        particleEffectCharacter2.ParticleEffectCharacterSpawner();
        glPopMatrix();
    }
    else if (particleEffectCharacter2.particleMuncul == false)
    {
        particleEffectCharacter2.particleAtasCharacter = 0;
        particleEffectCharacter2.particleBawahCharacter = 0;
        particleEffectCharacter2.particleKananCharacter = 0;
        particleEffectCharacter2.particleKiriCharacter = 0;

        particleEffectCharacter2.opacityParticleCharacter = 255;
        particleEffectCharacter2.msPartChara = 0;
    }

    if (particleEffectCharacter2.opacityParticleCharacter <= 0)
    {
        particleEffectCharacter2.particleMuncul = false;
    }
}

void mainEnemyB_colliderSpawner()
{
    enemyCollider1.posXenemyB[0] = 48;
    enemyCollider1.posXenemyB[1] = 79;
    enemyCollider1.colliderEnemyB();

    if (enemyCollider1.posYenemyB[0] <= 100)
    {
        enemyCollider1.posYenemyB[0] += 250*2;
        enemyCollider1.posYenemyB[1] += 250*2;
    }

    enemyCollider2.posXenemyB[0] = 210;
    enemyCollider2.posXenemyB[1] = 240;
    enemyCollider2.colliderEnemyB();

    if (enemyCollider2.posYenemyB2[0] <= 100)
    {
        enemyCollider2.posYenemyB2[0] += 250*2;
        enemyCollider2.posYenemyB2[1] += 250*2;
    }
    //Fungsi Collision player and colliderEnemyB
    if ((
            ((characterObject1.charaPosX[0] >= enemyCollider1.posXenemyB[0] && characterObject1.charaPosX[0] <= enemyCollider1.posXenemyB[1] ) && (characterObject1.charaPosY[0] <= enemyCollider1.posYenemyB[0]  && characterObject1.charaPosY[0] >= enemyCollider1.posYenemyB[1] )) ||
            ((characterObject1.charaPosX[1] >= enemyCollider1.posXenemyB[0] && characterObject1.charaPosX[1] <= enemyCollider1.posXenemyB[1] ) && (characterObject1.charaPosY[0] <= enemyCollider1.posYenemyB[0]  && characterObject1.charaPosY[0] >= enemyCollider1.posYenemyB[1] )) ||
            ((characterObject1.charaPosX[1] >= enemyCollider1.posXenemyB[0] && characterObject1.charaPosX[1] <= enemyCollider1.posXenemyB[1] ) && (characterObject1.charaPosY[1] <= enemyCollider1.posYenemyB[0]  && characterObject1.charaPosY[1] >= enemyCollider1.posYenemyB[1] )) ||
            ((characterObject1.charaPosX[0] >= enemyCollider1.posXenemyB[0] && characterObject1.charaPosX[0] <= enemyCollider1.posXenemyB[1] ) && (characterObject1.charaPosY[1] <= enemyCollider1.posYenemyB[0]  && characterObject1.charaPosY[1] >= enemyCollider1.posYenemyB[1] ))
        ) && (dmgCooldown <= 0))
    {
        particleEffectCharacter3.particleMuncul = true;

        resetDmgCooldown();
        bensin -= 5;
    }
    //Fungsi Collision player and colliderEnemyB2
    if ((
            ((characterObject1.charaPosX[0] >= enemyCollider2.posXenemyB[0] && characterObject1.charaPosX[0] <= enemyCollider2.posXenemyB[1] ) && (characterObject1.charaPosY[0] <= enemyCollider2.posYenemyB2[0]  && characterObject1.charaPosY[0] >= enemyCollider2.posYenemyB2[1] )) ||
            ((characterObject1.charaPosX[1] >= enemyCollider2.posXenemyB[0] && characterObject1.charaPosX[1] <= enemyCollider2.posXenemyB[1] ) && (characterObject1.charaPosY[0] <= enemyCollider2.posYenemyB2[0]  && characterObject1.charaPosY[0] >= enemyCollider2.posYenemyB2[1] )) ||
            ((characterObject1.charaPosX[1] >= enemyCollider2.posXenemyB[0] && characterObject1.charaPosX[1] <= enemyCollider2.posXenemyB[1] ) && (characterObject1.charaPosY[1] <= enemyCollider2.posYenemyB2[0]  && characterObject1.charaPosY[1] >= enemyCollider2.posYenemyB2[1] )) ||
            ((characterObject1.charaPosX[0] >= enemyCollider2.posXenemyB[0] && characterObject1.charaPosX[0] <= enemyCollider2.posXenemyB[1] ) && (characterObject1.charaPosY[1] <= enemyCollider2.posYenemyB2[0]  && characterObject1.charaPosY[1] >= enemyCollider2.posYenemyB2[1] ))
        ) && (dmgCooldown <= 0))
    {
        particleEffectCharacter4.particleMuncul = true;

        resetDmgCooldown();
        bensin -= 5;
    }

    //===================== kondisi particle 3 ========================
    if (particleEffectCharacter3.particleMuncul == true)
    {
        particleEffectCharacter3.msPartChara = 0.5;

        float posXpart_chara = ((enemyCollider1.posXenemyB[1] - enemyCollider1.posXenemyB[0]) / 2 ) + enemyCollider1.posXenemyB[0];
        float posYpart_chara = ((enemyCollider1.posYenemyB[1] - enemyCollider1.posYenemyB[0]) / 2 ) + enemyCollider1.posYenemyB[0];

        glPushMatrix();
        glTranslatef(posXpart_chara,posYpart_chara,0);
        particleEffectCharacter3.ParticleEffectCharacterSpawner();
        glPopMatrix();
    }
    else if (particleEffectCharacter3.particleMuncul == false)
    {
        particleEffectCharacter3.particleAtasCharacter = 0;
        particleEffectCharacter3.particleBawahCharacter = 0;
        particleEffectCharacter3.particleKananCharacter = 0;
        particleEffectCharacter3.particleKiriCharacter = 0;

        particleEffectCharacter3.opacityParticleCharacter = 255;
        particleEffectCharacter3.msPartChara = 0;
    }

    if (particleEffectCharacter3.opacityParticleCharacter <= 0)
    {
        particleEffectCharacter3.particleMuncul = false;
    }

    //===================== kondisi particle 4 ========================
    if (particleEffectCharacter4.particleMuncul == true)
    {
        particleEffectCharacter4.msPartChara = 0.5;

        float posXpart_chara = ((enemyCollider2.posXenemyB[1] - enemyCollider2.posXenemyB[0]) / 2 ) + enemyCollider2.posXenemyB[0];
        float posYpart_chara = ((enemyCollider2.posYenemyB2[1] - enemyCollider2.posYenemyB2[0]) / 2 ) + enemyCollider2.posYenemyB2[0];

        glPushMatrix();
        glTranslatef(posXpart_chara,posYpart_chara,0);
        particleEffectCharacter4.ParticleEffectCharacterSpawner();
        glPopMatrix();
    }
    else if (particleEffectCharacter4.particleMuncul == false)
    {
        particleEffectCharacter4.particleAtasCharacter = 0;
        particleEffectCharacter4.particleBawahCharacter = 0;
        particleEffectCharacter4.particleKananCharacter = 0;
        particleEffectCharacter4.particleKiriCharacter = 0;

        particleEffectCharacter4.opacityParticleCharacter = 255;
        particleEffectCharacter4.msPartChara = 0;
    }

    if (particleEffectCharacter4.opacityParticleCharacter <= 0)
    {
        particleEffectCharacter4.particleMuncul = false;
    }
}

void mainEnemyC_colliderSpawner()
{
    enemyCollider1.posXenemyC[0] = 102;
    enemyCollider1.posXenemyC[1] = 138;
    enemyCollider1.colliderEnemyC();

    if (enemyCollider1.posYenemyC[0] <= 0)
    {
        enemyCollider1.posYenemyC[0] += 450*2;
        enemyCollider1.posYenemyC[1] += 450*2;
    }

    enemyCollider2.posXenemyC[0] = 175;
    enemyCollider2.posXenemyC[1] = 215;
    enemyCollider2.colliderEnemyC();

    if (enemyCollider2.posYenemyC2[0] <= 0)
    {
        enemyCollider2.posYenemyC2[0] += 450*2;
        enemyCollider2.posYenemyC2[1] += 450*2;
    }
    //Fungsi Collision player and colliderEnemyC
    if ((
            ((characterObject1.charaPosX[0] >= enemyCollider1.posXenemyC[0] && characterObject1.charaPosX[0] <= enemyCollider1.posXenemyC[1] ) && (characterObject1.charaPosY[0] <= enemyCollider1.posYenemyC[0]  && characterObject1.charaPosY[0] >= enemyCollider1.posYenemyC[1] )) ||
            ((characterObject1.charaPosX[1] >= enemyCollider1.posXenemyC[0] && characterObject1.charaPosX[1] <= enemyCollider1.posXenemyC[1] ) && (characterObject1.charaPosY[0] <= enemyCollider1.posYenemyC[0]  && characterObject1.charaPosY[0] >= enemyCollider1.posYenemyC[1] )) ||
            ((characterObject1.charaPosX[1] >= enemyCollider1.posXenemyC[0] && characterObject1.charaPosX[1] <= enemyCollider1.posXenemyC[1] ) && (characterObject1.charaPosY[1] <= enemyCollider1.posYenemyC[0]  && characterObject1.charaPosY[1] >= enemyCollider1.posYenemyC[1] )) ||
            ((characterObject1.charaPosX[0] >= enemyCollider1.posXenemyC[0] && characterObject1.charaPosX[0] <= enemyCollider1.posXenemyC[1] ) && (characterObject1.charaPosY[1] <= enemyCollider1.posYenemyC[0]  && characterObject1.charaPosY[1] >= enemyCollider1.posYenemyC[1] ))
        ) && (dmgCooldown <= 0))
    {
        particleEffectCharacter5.particleMuncul = true;

        resetDmgCooldown();
        bensin -= 15;
    }
    //Fungsi Collision player and colliderEnemyC2
    if ((
            ((characterObject1.charaPosX[0] >= enemyCollider2.posXenemyC[0] && characterObject1.charaPosX[0] <= enemyCollider2.posXenemyC[1] ) && (characterObject1.charaPosY[0] <= enemyCollider2.posYenemyC2[0]  && characterObject1.charaPosY[0] >= enemyCollider2.posYenemyC2[1] )) ||
            ((characterObject1.charaPosX[1] >= enemyCollider2.posXenemyC[0] && characterObject1.charaPosX[1] <= enemyCollider2.posXenemyC[1] ) && (characterObject1.charaPosY[0] <= enemyCollider2.posYenemyC2[0]  && characterObject1.charaPosY[0] >= enemyCollider2.posYenemyC2[1] )) ||
            ((characterObject1.charaPosX[1] >= enemyCollider2.posXenemyC[0] && characterObject1.charaPosX[1] <= enemyCollider2.posXenemyC[1] ) && (characterObject1.charaPosY[1] <= enemyCollider2.posYenemyC2[0]  && characterObject1.charaPosY[1] >= enemyCollider2.posYenemyC2[1] )) ||
            ((characterObject1.charaPosX[0] >= enemyCollider2.posXenemyC[0] && characterObject1.charaPosX[0] <= enemyCollider2.posXenemyC[1] ) && (characterObject1.charaPosY[1] <= enemyCollider2.posYenemyC2[0]  && characterObject1.charaPosY[1] >= enemyCollider2.posYenemyC2[1] ))
        ) && (dmgCooldown <= 0))
    {
        particleEffectCharacter6.particleMuncul = true;

        resetDmgCooldown();
        bensin -= 15;
    }

    //===================== kondisi particle 5 ========================
    if (particleEffectCharacter5.particleMuncul == true)
    {
        particleEffectCharacter5.msPartChara = 0.5;

        float posXpart_chara = ((enemyCollider1.posXenemyC[1] - enemyCollider1.posXenemyC[0]) / 2 ) + enemyCollider1.posXenemyC[0];
        float posYpart_chara = ((enemyCollider1.posYenemyC[1] - enemyCollider1.posYenemyC[0]) / 2 ) + enemyCollider1.posYenemyC[0];

        glPushMatrix();
        glTranslatef(posXpart_chara,posYpart_chara,0);
        particleEffectCharacter5.ParticleEffectCharacterSpawner();
        glPopMatrix();
    }
    else if (particleEffectCharacter5.particleMuncul == false)
    {
        particleEffectCharacter5.particleAtasCharacter = 0;
        particleEffectCharacter5.particleBawahCharacter = 0;
        particleEffectCharacter5.particleKananCharacter = 0;
        particleEffectCharacter5.particleKiriCharacter = 0;

        particleEffectCharacter5.opacityParticleCharacter = 255;
        particleEffectCharacter5.msPartChara = 0;
    }
    if (particleEffectCharacter5.opacityParticleCharacter <= 0)
    {
        particleEffectCharacter5.particleMuncul = false;
    }

    //===================== kondisi particle 6 ========================
    if (particleEffectCharacter6.particleMuncul == true)
    {
        particleEffectCharacter6.msPartChara = 0.5;

        float posXpart_chara = ((enemyCollider2.posXenemyC[1] - enemyCollider2.posXenemyC[0]) / 2 ) + enemyCollider2.posXenemyC[0];
        float posYpart_chara = ((enemyCollider2.posYenemyC2[1] - enemyCollider2.posYenemyC2[0]) / 2 ) + enemyCollider2.posYenemyC2[0];

        glPushMatrix();
        glTranslatef(posXpart_chara,posYpart_chara,0);
        particleEffectCharacter6.ParticleEffectCharacterSpawner();
        glPopMatrix();
    }
    else if (particleEffectCharacter6.particleMuncul == false)
    {
        particleEffectCharacter6.particleAtasCharacter = 0;
        particleEffectCharacter6.particleBawahCharacter = 0;
        particleEffectCharacter6.particleKananCharacter = 0;
        particleEffectCharacter6.particleKiriCharacter = 0;

        particleEffectCharacter6.opacityParticleCharacter = 255;
        particleEffectCharacter6.msPartChara = 0;
    }
    if (particleEffectCharacter6.opacityParticleCharacter <= 0)
    {
        particleEffectCharacter6.particleMuncul = false;
    }
}

void mainScene()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.06,0.16,0.2,0);
    glMatrixMode(GL_MODELVIEW);

    mainEnemyA_colliderSpawner();
    enemyA_Spawner();

    mainEnemyB_colliderSpawner();
    enemyB_Spawner();

    mainEnemyC_colliderSpawner();
    enemyC_Spawner();

    mainBintangSpawner();

    mainBensinColliderSpawner();
    mainBensinSpawner();

    characterObject1.colliderCharacter();
    mainCharacterMove();

    game_ui.bensinBarView(bensin);
    sprintf(cetakScore, "%d",scoreChara);
    game_ui.drawText(20,615, cetakScore);

    glFlush();
    glutSwapBuffers();
}

void loseConditionScene()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.06,0.16,0.2,0);
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    glColor3ub(255,255,255);
    game_ui.drawText(150,340,"YOU LOSE");
    game_ui.drawText(110,325,"Your Score : ");
    sprintf(cetakScore, "%d", scoreChara);
    game_ui.drawText(230,325,cetakScore);
    game_ui.drawText(75,300,"Press 'Enter' to Play Again");
    glPopMatrix();

    glFlush();
    glutSwapBuffers();
}

void sceneManager(int timer)
{
    if (gameBerjalan == true)
    {
        glutDisplayFunc(mainScene);
    }

    if (bensin <= 0)
    {
        gameBerjalan = false;
        scoreBertambah = false;
        glutDisplayFunc(loseConditionScene);
    }

    if (GetAsyncKeyState(VK_UP))
    {
        gameBerjalan = true;
        scoreChara = 0;
        glutDisplayFunc(mainScene);
    }

    glutTimerFunc(50,sceneManager,0);
    glutPostRedisplay();
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

    glutTimerFunc(1,characterMovement,0);
    glutTimerFunc(1,bintangMovement,0);
    glutTimerFunc(1,bensinMovement,0);
    glutTimerFunc(1,gameUI_timer,0);
    glutTimerFunc(1,enemyA_Movement,0);
    glutTimerFunc(1,enemyB_Movement,0);
    glutTimerFunc(1,enemyC_Movement,0);
    glutTimerFunc(1,particleEffectBensinTimer,0);
    glutTimerFunc(1,animasiObject,0);
    glutTimerFunc(1,particleEffectCharacterTimer,0);
    glutTimerFunc(1,sceneManager,0);

    myinit();
    glutMainLoop();
    return 0;
}
