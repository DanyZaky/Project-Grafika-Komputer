class BintangObjectClass
{
public:
    void bintangObject()
    {
        glBegin(GL_QUADS);
        glColor3ub(182,182,183);

            glVertex2f(-1,3);
            glVertex2f(1,3);
            glVertex2f(1,-3);
            glVertex2f(-1,-3);

            glVertex2f(-3,1);
            glVertex2f(3,1);
            glVertex2f(3,-1);
            glVertex2f(-3,-1);

        glEnd();
    }
};
