class BensinObjectClass
{
public:
    float opacity = 255;

    float posXben[2];
    float posYben[2] = {660,626};
    float posYben2[2] = {660+640,626+640};

    float opacityParticle = 255;
    float particleAtas;
    float particleBawah;
    float particleKanan;
    float particleKiri;
    float ms;
    bool particleMuncul = false;

    bool destroyBensin = false;

    void particleEffectBensin()
    {
        glPushMatrix();
        glTranslatef(20,20,0);
        glBegin(GL_QUADS);
        glColor4ub(240,141,3,opacityParticle);
            glVertex2f(2,2);
            glVertex2f(2,-2);
            glVertex2f(-2,-2);
            glVertex2f(-2,2);
        glEnd();
        glPopMatrix();
    }

    void particleEffectBensinSpawner()
    {
        glPushMatrix();
        glTranslatef(0,particleAtas,0);
        particleEffectBensin();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(0,particleBawah,0);
        particleEffectBensin();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(particleKanan,0,0);
        particleEffectBensin();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(particleKiri,0,0);
        particleEffectBensin();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(particleKanan,particleAtas,0);
        particleEffectBensin();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(particleKiri,particleAtas,0);
        particleEffectBensin();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(particleKanan,particleBawah,0);
        particleEffectBensin();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(particleKiri,particleBawah,0);
        particleEffectBensin();
        glPopMatrix();
    }

    void colliderBensin()
    {
        glPushMatrix();
        glBegin(GL_POLYGON);
        glColor4ub(255,255,255,0);
            glVertex2f(posXben[0],posYben[0]);
            glVertex2f(posXben[1],posYben[0]);
            glVertex2f(posXben[1],posYben[1]);
            glVertex2f(posXben[0],posYben[1]);
        glEnd();
        glPopMatrix();
    }

    void bensinObject()
    {
        glBegin(GL_QUADS);
        glColor4ub(155,93,12,opacity);

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

        glColor4ub(240,141,3,opacity);

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
