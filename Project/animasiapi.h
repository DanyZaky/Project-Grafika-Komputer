class AnimasiApi{
public:
    void animasiApi(){
    glBegin(GL_QUADS);
    glColor3ub(240,141,3);

        glVertex2f(165,315);
        glVertex2f(170,315);
        glVertex2f(170,312);
        glVertex2f(165,312);

        glVertex2f(166,312);
        glVertex2f(169,312);
        glVertex2f(169,308);
        glVertex2f(166,308);

        glVertex2f(167,308);
        glVertex2f(168,308);
        glVertex2f(168,305);
        glVertex2f(167,305);

    glEnd();
    glFlush();
    }

};
