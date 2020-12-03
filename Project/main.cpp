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

void item()
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


void mainCharacterMove(){

    glPushMatrix();
    if (flip){
        //glTranslatef(0,0,0);
        //glRotatef(180,0,1,0);
    }else if(flip == false){
        //glTranslatef(0,0,0);
        //glRotatef(0,0,1,0);
    }
    glTranslatef(kananKiri,gravity,0);
    karakter1.mainCharacter();
    if (GetAsyncKeyState(VK_RIGHT))
    {
        flip = true;
        animasiApi();
    }
    if (GetAsyncKeyState(VK_LEFT))
    {
        flip = false;
        animasiApi();
    }
    glPopMatrix();
}

void displayMe()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.06,0.16,0.2,0);
    glMatrixMode(GL_MODELVIEW);


    bintang();

    item();

    //glPushMatrix();
    //glTranslatef(kananKiri,gravity,0);
    //mainCharacter();
    //glPopMatrix();

    mainCharacterMove();

}

void timer(int t)
{
    if (jatuh == true)
    {
        gravity -= 3;
    }
    else
    {
        gravity = 0;
    }

    if (GetAsyncKeyState(VK_RIGHT))
    {
        //gravity = 0;
        //kananKiri = 0;
        gravity += 10;
        kananKiri += 7;
    }
    else if (GetAsyncKeyState(VK_LEFT))
    {
        //gravity = 0;
        //kananKiri = 0;
        gravity += 10;
        kananKiri -= 7;
    }
    glutTimerFunc(25,timer,0);
    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(500,760);
    glutCreateWindow("The Rocket Man");

    gluOrtho2D(0,360,0,640);
    glutTimerFunc(5,timer,0);
    glutDisplayFunc(displayMe);
    glutMainLoop();
}
