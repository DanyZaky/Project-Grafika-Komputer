class Bintang{
public:
    void bintang(){
    glBegin(GL_QUADS);
    glColor3ub(182,182,183);
    glVertex2f(180,639);
    glVertex2f(182,639);
    glVertex2f(182,633);
    glVertex2f(180,633);

    glVertex2f(178,637);
    glVertex2f(178,635);
    glVertex2f(184,637);
    glVertex2f(184,635);

    glEnd();
    glFlush();
    }
};
