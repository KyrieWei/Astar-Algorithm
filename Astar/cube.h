#ifndef CUBE_H
#define CUBE_H
#include "mybutton.h"

class cube
{
public:
    cube();

    Coord coord;
    int F;
    int G;
    int H;
    int status; //0: start point; 1: block point; 2: final point

private:
    cube *left;
    cube *right;
    cube *up;
    cube *down;

public:
    void getF(int f);
    void getG(int g);
    void getH(int h);
    void getStatus(int sta);
    void setLeftPoint(cube *leftCube);
    void setRightPoint(cube *rightCube);
    void setUpPoint(cube *upCube);
    void setDownPoint(cube *downCube);

private slots:
   // void on_CubeButton_Clicked();

};

#endif // CUBE_H
