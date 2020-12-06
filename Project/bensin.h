class BensinObjectClass
{
public:
    void bensinObject()
    {
        glBegin(GL_QUADS);
        glColor3ub(155,93,12);

            glVertex2f(-9,20);
            glVertex2f(8,20);
            glVertex2f(8,17.5);
            glVertex2f(-9,17.5);

            glVertex2f(-9,14.5);
            glVertex2f(-9,17.5);
            glVertex2f(-3.5,17.5);
            glVertex2f(-3.5,14.5);

            glVertex2f(-11.5,14.5);
            glVertex2f(-6,14.5);
            glVertex2f(-6,12);
            glVertex2f(-11.5,12);

            glVertex2f(-14,12);
            glVertex2f(-8.5,12);
            glVertex2f(-8.5,-11);
            glVertex2f(-14,-11);

            glVertex2f(-11,-10);
            glVertex2f(0,-10);
            glVertex2f(0,-14);
            glVertex2f(-11,-14);

        glColor3ub(240,141,3);

            glVertex2f(-3.5,17.5);
            glVertex2f(-2,17.5);
            glVertex2f(-2,14.5);
            glVertex2f(-3.5,14.5);

            glVertex2f(5,17.5);
            glVertex2f(8,17.5);
            glVertex2f(8,16);
            glVertex2f(5,16);

            glVertex2f(6.5,16);
            glVertex2f(6.5,14.5);
            glVertex2f(8,14.5);
            glVertex2f(8,16);

            glVertex2f(-6,14.5);
            glVertex2f(-6,12);
            glVertex2f(11,12);
            glVertex2f(11,14.5);

            glVertex2f(-8.5,12);
            glVertex2f(-8.5,-10);
            glVertex2f(14,-10);
            glVertex2f(14,12);

            glVertex2f(0,-10);
            glVertex2f(0,-11);
            glVertex2f(14,-11);
            glVertex2f(14,-10);

            glVertex2f(0,-11);
            glVertex2f(0,-14);
            glVertex2f(11,-14);
            glVertex2f(11,-11);

        glEnd();
    }
};
