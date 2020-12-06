class CharacterFireObjectClass
{
public:
    void characterFireObject()
    {
        glPushMatrix();
        glBegin(GL_QUADS);
        glColor3ub(240,141,3);

            glVertex2f(-15.5,-6.5);
            glVertex2f(-9.5,-6.5);
            glVertex2f(-9.5,-9.5);
            glVertex2f(-15.5,-9.5);

            glVertex2f(-14.5,-9.5);
            glVertex2f(-10.5,-9.5);
            glVertex2f(-10.5,-13.5);
            glVertex2f(-14.5,-13.5);

            glVertex2f(-13.5,-13.5);
            glVertex2f(-11.5,-13.5);
            glVertex2f(-11.5,-16.5);
            glVertex2f(-13.5,-16.5);

        glEnd();
        glPopMatrix();
    }
};
