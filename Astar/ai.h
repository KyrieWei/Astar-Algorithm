#ifndef AI_H
#define AI_H
#include "cube.h"

class AI
{
public:
    AI();

    void algorithm(cube *cubeArr[40][40], int startpoint_x, int startpoint_y);
};

#endif // AI_H
