#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

void display();

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(360,640);
    glutCreateWindow("The Rocket Man");
    glutDisplayFunc(display);
    gluOrtho2D(0,90,0,160);
    glutMainLoop();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);

    //test

    glColor3ub(255,255,255);

    glBegin(GL_QUADS);

        glVertex2i(0,0);
        glVertex2i(0,50);
        glVertex2i(40,50);
        glVertex2i(40,0);

    glEnd();
    glFlush();
}

