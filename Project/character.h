class CharacterObjectClass
{
public:

    float charaPosX[2] = {160,200};
    float charaPosY[2] = {340,300};

    float colorChara1[3] = {202,11,1};
    float colorChara2[3] = {169,8,0};

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

    void characterObject()
    {
        glPushMatrix();
        glBegin(GL_QUADS);
        //BADAN BELAKANG
        glColor3ub(colorChara1[0],colorChara1[1],colorChara1[2]);

            glVertex2f(-15.5,12.5);
            glVertex2f(-9.5,12.5);
            glVertex2f(-9.5,7.5);
            glVertex2f(-15.5,7.5);

            glVertex2f(-17.5,10.5);
            glVertex2f(-17.5,4.5);
            glVertex2f(-14.5,4.5);
            glVertex2f(-14.5,10.5);

        glColor3ub(colorChara2[0],colorChara2[1],colorChara2[2]);

            glVertex2f(-14.5,7.5);
            glVertex2f(-9.5,7.5);
            glVertex2f(-9.5,-6.5);
            glVertex2f(-14.5,-6.5);

            glVertex2f(-14.5,4.5);
            glVertex2f(-15.5,-4.5);
            glVertex2f(-15.5,-6.5);
            glVertex2f(-14.5,-6.5);

            glVertex2f(-14.5,4.5);
            glVertex2f(-15.5,-4.5);
            glVertex2f(-17.5,-4.5);
            glVertex2f(-17.5,4.5);
        //BADANUTAMA
        glColor3ub(colorChara1[0],colorChara1[1],colorChara1[2]);

            glVertex2f(-7.5,18.5);
            glVertex2f(9.5,18.5);
            glVertex2f(9.5,16.5);
            glVertex2f(-7.5,16.5);

            glVertex2f(-8.5,16.5);
            glVertex2f(11.5,16.5);
            glVertex2f(11.5,12.5);
            glVertex2f(-8.5,12.5);

            glVertex2f(-6.5,12.5);
            glVertex2f(11.5,12.5);
            glVertex2f(11.5,2.5);
            glVertex2f(-6.5,2.5);

            glVertex2f(-4.5,2.5);
            glVertex2f(11.5,2.5);
            glVertex2f(11.5,-2.5);
            glVertex2f(-4.5,-2.5);

            glVertex2f(5.5,-1.5);
            glVertex2f(14.5,-1.5);
            glVertex2f(14.5,-4.5);
            glVertex2f(5.5,-4.5);

            glVertex2f(7.5,-3.5);
            glVertex2f(16.5,-3.5);
            glVertex2f(16.5,-8.5);
            glVertex2f(7.5,-8.5);

            glVertex2f(9.5,-8.5);
            glVertex2f(16.5,-8.5);
            glVertex2f(16.5,-13.5);
            glVertex2f(9.5,-13.5);

            glVertex2f(9.5,-8.5);
            glVertex2f(16.5,-8.5);
            glVertex2f(16.5,-13.5);
            glVertex2f(9.5,-13.5);

            glVertex2f(11,-13.5);
            glVertex2f(16.5,-13.5);
            glVertex2f(16.5,-16.5);
            glVertex2f(11,-16.5);

        glColor3ub(colorChara2[0],colorChara2[1],colorChara2[2]);

            glVertex2f(-9.5,16.5);
            glVertex2f(-8.5,16.5);
            glVertex2f(-8.5,12.5);
            glVertex2f(-9.5,12.5);

            glVertex2f(-9.5,12.5);
            glVertex2f(-6.5,12.5);
            glVertex2f(-6.5,2.5);
            glVertex2f(-9.5,2.5);

            glVertex2f(-9.5,2.5);
            glVertex2f(-4.5,2.5);
            glVertex2f(-4.5,-2.5);
            glVertex2f(-9.5,-2.5);

            glVertex2f(-9.5,-2.5);
            glVertex2f(5.5,-2.5);
            glVertex2f(5.5,-4.5);
            glVertex2f(-9.5,-4.5);

            glVertex2f(-9.5,-4.5);
            glVertex2f(7.5,-4.5);
            glVertex2f(7.5,-9.5);
            glVertex2f(-9.5,-9.5);

            glVertex2f(7.5,-8.5);
            glVertex2f(9.5,-8.5);
            glVertex2f(9.5,-16.5);
            glVertex2f(7.5,-16.5);

            glVertex2f(9.5,-13.5);
            glVertex2f(11.5,-13.5);
            glVertex2f(11.5,-18.5);
            glVertex2f(9.5,-18.5);

            glVertex2f(9.5,-16.5);
            glVertex2f(14.5,-16.5);
            glVertex2f(14.5,-18.5);
            glVertex2f(9.5,-18.5);

            glVertex2f(-7.5,-9.5);
            glVertex2f(-7.5,-11.5);
            glVertex2f(5.5,-11.5);
            glVertex2f(5.5,-9.5);

            glVertex2f(11.5,0);
            glVertex2f(11.5,-1.5);
            glVertex2f(16,-1.5);
            glVertex2f(16,0);

            glVertex2f(14.5,-1.5);
            glVertex2f(16,-1.5);
            glVertex2f(16,-3.5);
            glVertex2f(14.5,-3.5);

            glVertex2f(16.5,-2);
            glVertex2f(18,-2);
            glVertex2f(18,-15);
            glVertex2f(16,-15);
        //FACE
        glColor3ub(114,158,168);

            glVertex2f(-0.5,13.5);
            glVertex2f(11.5,13.5);
            glVertex2f(11.5,4.5);
            glVertex2f(-0.5,4.5);

            glVertex2f(-2.5,11.5);
            glVertex2f(13.5,11.5);
            glVertex2f(13.5,6.5);
            glVertex2f(-2.5,6.5);

        glColor3ub(146,202,205);

            glVertex2f(-0.5,13.5);
            glVertex2f(11.5,13.5);
            glVertex2f(11.5,6.5);
            glVertex2f(-0.5,6.5);

        glEnd();
        glPopMatrix();
    }
};
