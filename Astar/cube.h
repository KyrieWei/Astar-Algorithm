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
    int status; //-1: original point; 0: start point; 1: block point; 2: final point

    cube *left;
    cube *right;
    cube *up;
    cube *down;
    cube *left_up;
    cube *right_up;
    cube *left_down;
    cube *right_down;
    cube *parent;

public:
    void getF();
    void getG(int g);
    void getH(int h);
    void getStatus(int sta);
    void setLeftPoint(cube *leftCube);
    void setRightPoint(cube *rightCube);
    void setUpPoint(cube *upCube);
    void setDownPoint(cube *downCube);
    void setLeft_UpPoint(cube *left_upCube);
    void setRight_UpPoint(cube *right_upCube);
    void setLeft_DownPoint(cube *left_downCube);
    void setRight_DownPoint(cube *right_downCube);
    void setParentPoint(cube *parent);
private slots:
   // void on_CubeButton_Clicked();

};

#endif // CUBE_H
