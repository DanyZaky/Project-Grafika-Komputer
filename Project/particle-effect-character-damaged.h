class ParticleEffectCharacterClass
{
public:
    float opacityParticleCharacter = 255;
    float msPartChara;
    bool particleMuncul = false;

    float particleAtasCharacter;
    float particleBawahCharacter;
    float particleKananCharacter;
    float particleKiriCharacter;

    void particleEffectCharacter()
    {
        glPushMatrix();
        glBegin(GL_QUADS);
        glColor4ub(255,255,255,opacityParticleCharacter);
            glVertex2f(2,2);
            glVertex2f(2,-2);
            glVertex2f(-2,-2);
            glVertex2f(-2,2);
        glEnd();
        glPopMatrix();
    }

    void ParticleEffectCharacterSpawner()
    {
        glPushMatrix();
        glTranslatef(0,particleAtasCharacter,0);
        particleEffectCharacter();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(0,particleBawahCharacter,0);
        particleEffectCharacter();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(particleKananCharacter,0,0);
        particleEffectCharacter();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(particleKiriCharacter,0,0);
        particleEffectCharacter();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(particleKananCharacter,particleAtasCharacter,0);
        particleEffectCharacter();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(particleKiriCharacter,particleAtasCharacter,0);
        particleEffectCharacter();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(particleKananCharacter,particleBawahCharacter,0);
        particleEffectCharacter();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(particleKiriCharacter,particleBawahCharacter,0);
        particleEffectCharacter();
        glPopMatrix();
    }
};
