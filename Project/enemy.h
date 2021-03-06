class EnemyObjectClass
{
public:

    bool animasiEnemyDamaged = false;

    void enemyAobject()
    {
        glBegin(GL_QUADS);
        glColor3ub(123,57,90);

        glVertex2f(-8.55,9);
        glVertex2f(10,9);
        glVertex2f(10,6);
        glVertex2f(-8.55,6);

        glVertex2f(-8.4,6);
        glVertex2f(14,6);
        glVertex2f(14,2.5);
        glVertex2f(-8.4,2.5);

        glVertex2f(-12,6);
        glVertex2f(-8.5,6);
        glVertex2f(-8.5,-0.5);
        glVertex2f(-12,-0.5);

        glVertex2f(-16,2.5);
        glVertex2f(-12,2.5);
        glVertex2f(-12,-18);
        glVertex2f(-16,-18);

        glVertex2f(-12.2,-10.7);
        glVertex2f(-8.46,-10.7);
        glVertex2f(-8.46,-14.5);
        glVertex2f(-12.2,-14.5);

        glVertex2f(-8.44,-14.56);
        glVertex2f(-4.76,-14.56);
        glVertex2f(-4.76,-17.9);
        glVertex2f(-8.44,-17.9);

        glColor3ub(176,75,135);

        glVertex2f(-8.55,5.9);
        glVertex2f(14,5.9);
        glVertex2f(14,2.5);
        glVertex2f(-8.55,2.5);

        glVertex2f(-12.15,-0.45);
        glVertex2f(-8.53,-0.45);
        glVertex2f(-8.53,-10.65);
        glVertex2f(-12.15,-10.65);

        glVertex2f(-8.43,-10.6);
        glVertex2f(17.56,-10.6);
        glVertex2f(17.56,-14.5);
        glVertex2f(-8.43,-14.5);

        glVertex2f(-8.55,-4.3);
        glVertex2f(17.52,-4.3);
        glVertex2f(17.52,-10.7);
        glVertex2f(-8.55,-10.7);

        glVertex2f(-1,6);
        glVertex2f(2.75,6);
        glVertex2f(2.75,-17.9);
        glVertex2f(-1,-17.9);

        glVertex2f(6.4,-0.92);
        glVertex2f(10.2,-0.92);
        glVertex2f(10.2,-17.95);
        glVertex2f(6.4,-17.95);

        glVertex2f(13.95,2.48);
        glVertex2f(17.59,2.48);
        glVertex2f(17.59,-17.9);
        glVertex2f(13.95,-17.9);

        glVertex2f(10.16,2.48);
        glVertex2f(17.59,2.48);
        glVertex2f(17.59,-0.83);
        glVertex2f(10.16,-0.83);

        glVertex2f(10.23,6);
        glVertex2f(13.85,6);
        glVertex2f(13.85,2.55);
        glVertex2f(10.23,2.55);

        glVertex2f(-4.74,-0.9);
        glVertex2f(-1.08,-0.9);
        glVertex2f(-1.08,-4.22);
        glVertex2f(-4.74,-4.22);

        glVertex2f(10.13,-0.91);
        glVertex2f(17.65,-0.91);
        glVertex2f(17.65,-4.31);
        glVertex2f(10.13,-4.31);

        glEnd();
    }

    float colorEnemyB1[3] = {14,112,58};
    float colorEnemyB2[3] = {0,115,76};

    void enemyBobject()
    {
        glBegin(GL_QUADS);

        glColor3ub(colorEnemyB1[0],colorEnemyB1[1],colorEnemyB1[2]);

        glVertex2f(-6,11.5);
        glVertex2f(6,11.5);
        glVertex2f(6,8.5);
        glVertex2f(-6,8.5);

        glVertex2f(-11,8.5);
        glVertex2f(-6,8.5);
        glVertex2f(-6,6);
        glVertex2f(-11,6);

        glVertex2f(-14,6);
        glVertex2f(-11,6);
        glVertex2f(-11,0);
        glVertex2f(-14,0);

        glVertex2f(-14,0);
        glVertex2f(-9.5,0);
        glVertex2f(-9.5,-3);
        glVertex2f(-14,-3);

        glVertex2f(-9.5,-3);
        glVertex2f(-6,-3);
        glVertex2f(-6,-6);
        glVertex2f(-9.5,-6);

        glVertex2f(-12.5,-6);
        glVertex2f(-6,-6);
        glVertex2f(-6,-8.5);
        glVertex2f(-12.5,-8.5);

        glVertex2f(-16,-8.5);
        glVertex2f(-9.5,-8.5);
        glVertex2f(-9.5,-11.5);
        glVertex2f(-16,-11.5);

        glColor3ub(colorEnemyB2[0],colorEnemyB2[1],colorEnemyB2[2]);

        glVertex2f(-6,8.5);
        glVertex2f(11,8.5);
        glVertex2f(11,6);
        glVertex2f(-6,6);

        glVertex2f(6,6);
        glVertex2f(11,6);
        glVertex2f(11,3);
        glVertex2f(6,3);

        glVertex2f(9.5,-8.5);
        glVertex2f(16,-8.5);
        glVertex2f(16,-11.5);
        glVertex2f(9.5,-11.5);

        glVertex2f(6,-6);
        glVertex2f(12.5,-6);
        glVertex2f(12.5,-8.5);
        glVertex2f(6,-8.5);

        glVertex2f(3,-3);
        glVertex2f(9.5,-3);
        glVertex2f(9.5,-6);
        glVertex2f(3,-6);

        glVertex2f(11,6);
        glVertex2f(14,6);
        glVertex2f(14,-3);
        glVertex2f(9.5,-3);

        glVertex2f(-3,-6);
        glVertex2f(3,-6);
        glVertex2f(3,-9);
        glVertex2f(-3,-9);

        glVertex2f(-6,3);
        glVertex2f(-3,3);
        glVertex2f(-3,-6);
        glVertex2f(-6,-6);

        glVertex2f(-9.5,0);
        glVertex2f(14,0);
        glVertex2f(14,-3);
        glVertex2f(-9.5,-3);

        glVertex2f(3,3);
        glVertex2f(6,3);
        glVertex2f(6,-6);
        glVertex2f(3,-6);

        glVertex2f(-11,6);
        glVertex2f(-6,6);
        glVertex2f(-6,3);
        glVertex2f(-11,3);

        glVertex2f(-3,8.5);
        glVertex2f(3,8.5);
        glVertex2f(3,-3);
        glVertex2f(-3,-3);

        glVertex2f(3,8.5);
        glVertex2f(6,8.5);
        glVertex2f(6,6);
        glVertex2f(3,6);
        glEnd();

    }

    void enemyCobject()
    {
        glBegin(GL_QUADS);
        glColor3ub(115,51,30);

        glVertex2f(-4,16);
        glVertex2f(4,16);
        glVertex2f(4,12);
        glVertex2f(-4,12);

        glVertex2f(-8,12);
        glVertex2f(-4,12);
        glVertex2f(-4,8);
        glVertex2f(-8,8);

        glVertex2f(-12,8);
        glVertex2f(-8,8);
        glVertex2f(-8,4);
        glVertex2f(-12,4);

        glVertex2f(-16,4);
        glVertex2f(-12,4);
        glVertex2f(-12,0);
        glVertex2f(-16,0);

        glVertex2f(-16,0);
        glVertex2f(-4,0);
        glVertex2f(-4,-4);
        glVertex2f(-16,-4);

        glVertex2f(-8,-4);
        glVertex2f(-4,-4);
        glVertex2f(-4,-8);
        glVertex2f(-8,-8);

        glVertex2f(-12,-8);
        glVertex2f(-8,-8);
        glVertex2f(-8,-12);
        glVertex2f(-12,-12);

        glVertex2f(-16,-12);
        glVertex2f(-12,-12);
        glVertex2f(-12,-16);
        glVertex2f(-16,-16);

        glVertex2f(-8,-12);
        glVertex2f(-4,-12);
        glVertex2f(-4,-16);
        glVertex2f(-8,-16);


        glColor3ub(240,67,35);

        glVertex2f(-4,12);
        glVertex2f(8,12);
        glVertex2f(8,8);
        glVertex2f(-4,8);

        glVertex2f(-8,8);
        glVertex2f(12,8);
        glVertex2f(12,4);
        glVertex2f(-8,4);

        glVertex2f(-12,4);
        glVertex2f(-8,4);
        glVertex2f(-8,0);
        glVertex2f(-12,0);

        glVertex2f(-8,0);
        glVertex2f(-4,0);
        glVertex2f(-4,-4);
        glVertex2f(-8,-4);

        glVertex2f(-4,12);
        glVertex2f(4,12);
        glVertex2f(4,-4);
        glVertex2f(-4,-4);

        glVertex2f(4,0);
        glVertex2f(8,0);
        glVertex2f(8,-4);
        glVertex2f(4,-4);

        glVertex2f(12,4);
        glVertex2f(16,4);
        glVertex2f(16,0);
        glVertex2f(12,0);

        glVertex2f(8,0);
        glVertex2f(16,0);
        glVertex2f(16,-4);
        glVertex2f(8,-4);

        glVertex2f(4,12);
        glVertex2f(8,12);
        glVertex2f(8,-4);
        glVertex2f(4,-4);

        glVertex2f(12,-12);
        glVertex2f(16,-12);
        glVertex2f(16,-16);
        glVertex2f(12,-16);

        glVertex2f(4,-4);
        glVertex2f(8,-4);
        glVertex2f(8,-8);
        glVertex2f(4,-8);

        glVertex2f(-4,-8);
        glVertex2f(4,-8);
        glVertex2f(4,-12);
        glVertex2f(-4,-12);

        glVertex2f(4,-12);
        glVertex2f(8,-12);
        glVertex2f(8,-16);
        glVertex2f(4,-16);

        glVertex2f(8,-8);
        glVertex2f(12,-8);
        glVertex2f(12,-12);
        glVertex2f(8,-12);

        glVertex2f(6,8.5);
        glVertex2f(11,8.5);
        glVertex2f(11,6);
        glVertex2f(6,6);


        glEnd();
    }
};

class EnemyColliderClass
{
public:
    float posXenemyA[2];
    float posYenemyA[2] = {850,820};
    float posYenemyA2[2] = {850+740,820+740};

    float posXenemyB[2];
    float posYenemyB[2] = {515,485};
    float posYenemyB2[2] = {515+250,485+250};;

    float posXenemyC[2];
    float posYenemyC[2] = {660,620};
    float posYenemyC2[2] = {660+450,620+450};

    void colliderEnemyA()
    {
        glPushMatrix();
        glBegin(GL_POLYGON);
        glColor4ub(255,255,255,0);
            glVertex2f(posXenemyA[0],posYenemyA[0]);
            glVertex2f(posXenemyA[1],posYenemyA[0]);
            glVertex2f(posXenemyA[1],posYenemyA[1]);
            glVertex2f(posXenemyA[0],posYenemyA[1]);
        glEnd();
        glPopMatrix();
    }

    void colliderEnemyB()
    {
        glPushMatrix();
        glBegin(GL_POLYGON);
        glColor4ub(255,255,255,0);
            glVertex2f(posXenemyB[0],posYenemyB[0]);
            glVertex2f(posXenemyB[1],posYenemyB[0]);
            glVertex2f(posXenemyB[1],posYenemyB[1]);
            glVertex2f(posXenemyB[0],posYenemyB[1]);
        glEnd();
        glPopMatrix();
    }

    void colliderEnemyC()
    {
        glPushMatrix();
        glBegin(GL_POLYGON);
        glColor4ub(255,255,255,0);
            glVertex2f(posXenemyC[0],posYenemyC[0]);
            glVertex2f(posXenemyC[1],posYenemyC[0]);
            glVertex2f(posXenemyC[1],posYenemyC[1]);
            glVertex2f(posXenemyC[0],posYenemyC[1]);
        glEnd();
        glPopMatrix();
    }
};
