class Karakter{
public:
    void mainCharacter(){
    glBegin(GL_QUADS);
    //CHARA_BADAN
    glColor3ub(202,11,1);

        glVertex2f(173,341);
        glVertex2f(190,341);
        glVertex2f(190,339);
        glVertex2f(173,339);

        glVertex2f(172,339);
        glVertex2f(191,339);
        glVertex2f(191,338);
        glVertex2f(172,338);

        glVertex2f(172,338);
        glVertex2f(192,338);
        glVertex2f(192,334);
        glVertex2f(172,334);

        glVertex2f(174,334);
        glVertex2f(192,334);
        glVertex2f(192,324);
        glVertex2f(174,324);

        glVertex2f(176,324);
        glVertex2f(192,324);
        glVertex2f(192,320);
        glVertex2f(176,319);

        glVertex2f(176,319);
        glVertex2f(192,320);
        glVertex2f(196,320);
        glVertex2f(196,319);

        glVertex2f(186,319);
        glVertex2f(197,319);
        glVertex2f(188,317);
        glVertex2f(186,317);

        glVertex2f(188,317);
        glVertex2f(196,319);
        glVertex2f(197,319);
        glVertex2f(197,317);

        glVertex2f(188,317);
        glVertex2f(197,317);
        glVertex2f(197,313);
        glVertex2f(188,313);

        glVertex2f(190,313);
        glVertex2f(197,313);
        glVertex2f(197,308);
        glVertex2f(190,308);

        glVertex2f(191,308);
        glVertex2f(197,308);
        glVertex2f(197,304);
        glVertex2f(191,304);

    //BADAN_SHADOWS
    glColor3ub(169,8,0);
    //DEPAN
        glVertex2f(192,321);
        glVertex2f(197,321);
        glVertex2f(197,320);
        glVertex2f(192,320);

        glVertex2f(196,320);
        glVertex2f(198,320);
        glVertex2f(197,319);
        glVertex2f(196,319);

        glVertex2f(197,319);
        glVertex2f(198,320);
        glVertex2f(198,306);
        glVertex2f(197,306);
    //BELAKANG
        glVertex2f(171,338);
        glVertex2f(172,338);
        glVertex2f(172,312);
        glVertex2f(171,312);

        glVertex2f(172,334);
        glVertex2f(174,334);
        glVertex2f(174,311);
        glVertex2f(172,311);

        glVertex2f(174,324);
        glVertex2f(174,311);
        glVertex2f(176,311);
        glVertex2f(176,324);

        glVertex2f(176,319);
        glVertex2f(186,319);
        glVertex2f(186,311);
        glVertex2f(176,311);

        glVertex2f(186,317);
        glVertex2f(188,317);
        glVertex2f(188,311);
        glVertex2f(186,311);

        glVertex2f(173,311);
        glVertex2f(173,310);
        glVertex2f(187,310);
        glVertex2f(187,311);

        glVertex2f(188,313);
        glVertex2f(190,313);
        glVertex2f(190,304);
        glVertex2f(188,304);

        glVertex2f(190,304);
        glVertex2f(190,308);
        glVertex2f(191,308);
        glVertex2f(191,304);

        glVertex2f(189,304);
        glVertex2f(196,304);
        glVertex2f(196,303);
        glVertex2f(189,303);

    //PUNGGUNG
    glColor3ub(202,11,1);

        glVertex2f(164,334);
        glVertex2f(171,334);
        glVertex2f(171,315);
        glVertex2f(164,315);

        glVertex2f(164,333);
        glVertex2f(164,316);
        glVertex2f(163,316);
        glVertex2f(163,333);

    glColor3ub(169,8,0);

        glVertex2f(166,316);
        glVertex2f(163,316);
        glVertex2f(163,327);
        glVertex2f(166,327);

        glVertex2f(166,329);
        glVertex2f(171,329);
        glVertex2f(171,315);
        glVertex2f(166,315);

        glVertex2f(164,316);
        glVertex2f(164,315);
        glVertex2f(171,315);
        glVertex2f(171,316);

    //CHARA HELM
    glColor3ub(114,158,168);

        glVertex2f(179,335);
        glVertex2f(179,326);
        glVertex2f(193,326);
        glVertex2f(193,335);

        glVertex2f(178,334);
        glVertex2f(178,327);
        glVertex2f(194,327);
        glVertex2f(194,334);

    glColor3ub(146,202,205);

        glVertex2f(180,335);
        glVertex2f(180,328);
        glVertex2f(193,328);
        glVertex2f(193,335);

    glEnd();
    glFlush();
}

};
