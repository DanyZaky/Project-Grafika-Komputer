class Bensin{
public:
    void bensin(){
    glBegin(GL_QUADS);
    glColor3ub(182,182,183);
    glVertex2f(192,607);
    glVertex2f(173,607);
    glVertex2f(173,623);
    glVertex2f(192,623);

    glVertex2f(175,625);
    glVertex2f(190,625);
    glVertex2f(190,605);
    glVertex2f(175,605);

    glVertex2f(176,628);
    glVertex2f(176,625);
    glVertex2f(181,628);
    glVertex2f(181,625);

    glVertex2f(181,629);
    glVertex2f(181,627);
    glVertex2f(188,629);
    glVertex2f(188,626);

    glVertex2f(187,626);
    glVertex2f(187,625);
    glVertex2f(189,626);
    glVertex2f(189,625);

    glVertex2f(186,627);
    glVertex2f(188,627);
    glVertex2f(186,626);
    glVertex2f(188,626);

    glEnd();
    glFlush();
    }

};
