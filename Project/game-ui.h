class GameUI_Class
{
public:
    void *font = GLUT_BITMAP_9_BY_15;

    void drawText(int x, int y, const char *string)
    {
        glColor3ub(255,255,255);
        glRasterPos2f(x, y);
        int panjang = (int)strlen(string);
        for (int i = 0; i < panjang; i++)
        {
            glutBitmapCharacter(font, string[i]);
        }
    }

    void bensinBarView(float x)
    {
        glPushMatrix();
        glTranslatef(20,-20,0);
        glBegin(GL_QUADS);

        glColor3ub(143,143,143);

            glVertex2f(-5,625);
            glVertex2f(-5,605);
            glVertex2f(105,605);
            glVertex2f(105,625);

        glColor3ub(212,212,212);
            glVertex2f(0,620);
            glVertex2f(0,610);
            glVertex2f(x,610);
            glVertex2f(x,620);

        glEnd();
        glPopMatrix();
    }
};
