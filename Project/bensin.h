class BensinObjectClass
{
public:
    float bensinPosX[14] = {-14,-11.5,-11,-9,-8.5,-6,-3.5,-2,0,5,6.5,8,11,14};
    float bensinPosY[8] = {-14,-11,-10,12,14.5,16,17.5,20};
    void bensinObject()
    {
        glBegin(GL_QUADS);
        glColor3ub(155,93,bensinPosY[3]);

            glVertex2f(bensinPosX[3], bensinPosY[7]);
            glVertex2f(bensinPosX[11],bensinPosY[7]);
            glVertex2f(bensinPosX[11],bensinPosY[6]);
            glVertex2f(bensinPosX[3] ,bensinPosY[6]);

            glVertex2f(bensinPosX[3] ,bensinPosY[4]);
            glVertex2f(bensinPosX[3] ,bensinPosY[6]);
            glVertex2f(bensinPosX[6],bensinPosY[6]);
            glVertex2f(bensinPosX[6],bensinPosY[4]);

            glVertex2f(bensinPosX[1] ,bensinPosY[4]);
            glVertex2f(bensinPosX[5],bensinPosY[4]);
            glVertex2f(bensinPosX[5],bensinPosY[3]);
            glVertex2f(bensinPosX[1] ,bensinPosY[3]);

            glVertex2f(bensinPosX[0] ,bensinPosY[3]);
            glVertex2f(bensinPosX[4],bensinPosY[3]);
            glVertex2f(bensinPosX[4],bensinPosY[1]);
            glVertex2f(bensinPosX[0] ,bensinPosY[1]);

            glVertex2f(bensinPosX[2] ,bensinPosY[2]);
            glVertex2f(bensinPosX[8],bensinPosY[2]);
            glVertex2f(bensinPosX[8],bensinPosY[0]);
            glVertex2f(bensinPosX[2] ,bensinPosY[0]);

        glColor3ub(240,141,3);

            glVertex2f(bensinPosX[6],bensinPosY[6]);
            glVertex2f(bensinPosX[7],bensinPosY[6]);
            glVertex2f(bensinPosX[7],bensinPosY[4]);
            glVertex2f(bensinPosX[6],bensinPosY[4]);

            glVertex2f(bensinPosX[9],bensinPosY[6]);
            glVertex2f(bensinPosX[11],bensinPosY[6]);
            glVertex2f(bensinPosX[11],bensinPosY[5]);
            glVertex2f(bensinPosX[9],bensinPosY[5]);

            glVertex2f(bensinPosX[10],bensinPosY[5]);
            glVertex2f(bensinPosX[10],bensinPosY[4]);
            glVertex2f(bensinPosX[11],bensinPosY[4]);
            glVertex2f(bensinPosX[11],bensinPosY[5]);

            glVertex2f(bensinPosX[5],bensinPosY[4]);
            glVertex2f(bensinPosX[5],bensinPosY[3]);
            glVertex2f(bensinPosX[12],bensinPosY[3]);
            glVertex2f(bensinPosX[12],bensinPosY[4]);

            glVertex2f(bensinPosX[4],bensinPosY[3]);
            glVertex2f(bensinPosX[4],bensinPosY[2]);
            glVertex2f(bensinPosX[13],bensinPosY[2]);
            glVertex2f(bensinPosX[13],bensinPosY[3]);

            glVertex2f(bensinPosX[8],bensinPosY[2]);
            glVertex2f(bensinPosX[8],bensinPosY[1]);
            glVertex2f(bensinPosX[13],bensinPosY[1]);
            glVertex2f(bensinPosX[13],bensinPosY[2]);

            glVertex2f(bensinPosX[8],bensinPosY[1]);
            glVertex2f(bensinPosX[8],bensinPosY[0]);
            glVertex2f(bensinPosX[12],bensinPosY[0]);
            glVertex2f(bensinPosX[12],bensinPosY[1]);

        glEnd();
    }
};
