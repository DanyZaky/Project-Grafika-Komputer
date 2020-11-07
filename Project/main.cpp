#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>
#include <windows.h>

float gravity = 0;
float kananKiri = 0;
bool jatuh = true;

void mainBackground()
{
    glColor3ub(16,42,52);
    glBegin(GL_QUADS);

        glVertex2i(0,0);
        glVertex2i(0,640);
        glVertex2i(360,640);
        glVertex2i(360,0);

    glEnd();
    glFlush();
}
void animasiApi()
{
    glBegin(GL_QUADS);
    glColor3ub(240,141,3);

        glVertex2i(165,315);
        glVertex2i(170,315);
        glVertex2i(170,312);
        glVertex2i(165,312);

        glVertex2i(166,312);
        glVertex2i(169,312);
        glVertex2i(169,308);
        glVertex2i(166,308);

        glVertex2i(167,308);
        glVertex2i(168,308);
        glVertex2i(168,305);
        glVertex2i(167,305);

    glEnd();
    glFlush();
}

void mainCharacter()
{
    glBegin(GL_QUADS);
    //CHARA_BADAN
    glColor3ub(202,11,1);

        glVertex2i(173,341);
        glVertex2i(190,341);
        glVertex2i(190,339);
        glVertex2i(173,339);

        glVertex2i(172,339);
        glVertex2i(191,339);
        glVertex2i(191,338);
        glVertex2i(172,338);

        glVertex2i(172,338);
        glVertex2i(192,338);
        glVertex2i(192,334);
        glVertex2i(172,334);

        glVertex2i(174,334);
        glVertex2i(192,334);
        glVertex2i(192,324);
        glVertex2i(174,324);

        glVertex2i(176,324);
        glVertex2i(192,324);
        glVertex2i(192,320);
        glVertex2i(176,319);

        glVertex2i(176,319);
        glVertex2i(192,320);
        glVertex2i(196,320);
        glVertex2i(196,319);

        glVertex2i(186,319);
        glVertex2i(197,319);
        glVertex2i(188,317);
        glVertex2i(186,317);

        glVertex2i(188,317);
        glVertex2i(196,319);
        glVertex2i(197,319);
        glVertex2i(197,317);

        glVertex2i(188,317);
        glVertex2i(197,317);
        glVertex2i(197,313);
        glVertex2i(188,313);

        glVertex2i(190,313);
        glVertex2i(197,313);
        glVertex2i(197,308);
        glVertex2i(190,308);

        glVertex2i(191,308);
        glVertex2i(197,308);
        glVertex2i(197,304);
        glVertex2i(191,304);

    //BADAN_SHADOWS
    glColor3ub(169,8,0);
    //DEPAN
        glVertex2i(192,321);
        glVertex2i(197,321);
        glVertex2i(197,320);
        glVertex2i(192,320);

        glVertex2i(196,320);
        glVertex2i(198,320);
        glVertex2i(197,319);
        glVertex2i(196,319);

        glVertex2i(197,319);
        glVertex2i(198,320);
        glVertex2i(198,306);
        glVertex2i(197,306);
    //BELAKANG
        glVertex2i(171,338);
        glVertex2i(172,338);
        glVertex2i(172,312);
        glVertex2i(171,312);

        glVertex2i(172,334);
        glVertex2i(174,334);
        glVertex2i(174,311);
        glVertex2i(172,311);

        glVertex2i(174,324);
        glVertex2i(174,311);
        glVertex2i(176,311);
        glVertex2i(176,324);

        glVertex2i(176,319);
        glVertex2i(186,319);
        glVertex2i(186,311);
        glVertex2i(176,311);

        glVertex2i(186,317);
        glVertex2i(188,317);
        glVertex2i(188,311);
        glVertex2i(186,311);

        glVertex2i(173,311);
        glVertex2i(173,310);
        glVertex2i(187,310);
        glVertex2i(187,311);

        glVertex2i(188,313);
        glVertex2i(190,313);
        glVertex2i(190,304);
        glVertex2i(188,304);

        glVertex2i(190,304);
        glVertex2i(190,308);
        glVertex2i(191,308);
        glVertex2i(191,304);

        glVertex2i(189,304);
        glVertex2i(196,304);
        glVertex2i(196,303);
        glVertex2i(189,303);

    //PUNGGUNG
    glColor3ub(202,11,1);

        glVertex2i(164,334);
        glVertex2i(171,334);
        glVertex2i(171,315);
        glVertex2i(164,315);

        glVertex2i(164,333);
        glVertex2i(164,316);
        glVertex2i(163,316);
        glVertex2i(163,333);

    glColor3ub(169,8,0);

        glVertex2i(166,316);
        glVertex2i(163,316);
        glVertex2i(163,327);
        glVertex2i(166,327);

        glVertex2i(166,329);
        glVertex2i(171,329);
        glVertex2i(171,315);
        glVertex2i(166,315);

        glVertex2i(164,316);
        glVertex2i(164,315);
        glVertex2i(171,315);
        glVertex2i(171,316);

    //CHARA HELM
    glColor3ub(114,158,168);

        glVertex2i(179,335);
        glVertex2i(179,326);
        glVertex2i(193,326);
        glVertex2i(193,335);

        glVertex2i(178,334);
        glVertex2i(178,327);
        glVertex2i(194,327);
        glVertex2i(194,334);

    glColor3ub(146,202,205);

        glVertex2i(180,335);
        glVertex2i(180,328);
        glVertex2i(193,328);
        glVertex2i(193,335);

    glEnd();
    glFlush();
}

void displayMe()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);

    glTranslatef(kananKiri,gravity,0);
    mainCharacter();

    //KONDISI KELUARNYA API
    if (GetAsyncKeyState(VK_RIGHT))
    {
        animasiApi();
    }
    if (GetAsyncKeyState(VK_LEFT))
    {
        animasiApi();
    }


}

void timer(int t)
{
    if (jatuh == true)
    {

        gravity -= 0.3;
    }
    if (GetAsyncKeyState(VK_RIGHT))
    {
        gravity = 0;
        kananKiri = 0;
        gravity += 6;
        kananKiri += 2;
    }
    else if (GetAsyncKeyState(VK_LEFT))
    {
        gravity = 0;
        kananKiri = 0;
        gravity += 6;
        kananKiri -= 2;
    }

    glutPostRedisplay();
    glutTimerFunc(25,timer,0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(500,780);
    glutCreateWindow("The Rocket Man");

    gluOrtho2D(0,360,0,640);
    glutTimerFunc(5,timer,0);
    glutDisplayFunc(displayMe);
    glutMainLoop();
}

