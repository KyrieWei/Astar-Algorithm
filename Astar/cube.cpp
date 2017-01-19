#include "cube.h"

cube::cube()
{
}

void cube::getF(int f){
    F = f;
}

void cube::getG(int g){
    G = g;
}

void cube::getH(int h){
    H = h;
}

void cube::getStatus(int sta){
    status = sta;
}

void cube::setLeftPoint(cube *p){
    left = p;
}

void cube::setRightPoint(cube *p){
    right = p;
}

void cube::setDownPoint(cube *p){
    down = p;
}

void cube::setUpPoint(cube *p){
    up = p;
}
