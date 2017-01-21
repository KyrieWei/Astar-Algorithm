#include "ai.h"
#include "cube.h"
#include "linklist.h"
#include <iostream>
using namespace std;
AI::AI()
{

}

void AI::algorithm(cube *cubeArr[40][40], int startpoint_x, int startpoint_y, int finalpoint_x, int finalpoint_y){
    cout << "success!" << endl;

    int G = 0, H = 0, F = 0;
    cubeArr[startpoint_x][startpoint_y]->getH(0);
    cubeArr[startpoint_x][startpoint_y]->getG(0);
    cubeArr[startpoint_x][startpoint_y]->getF();

    cube *tempCube = cubeArr[startpoint_x][startpoint_y];
    cube *parentCube;

    LinkList *OpenList = new LinkList();
    LinkList *ClosedList = new LinkList();

    //add startpoint to ClosedList
    ClosedList->insertNode(tempCube);

    while(true){


        //set G, H, F of the node around startpoint

        //check the up
        parentCube = tempCube;
        tempCube = tempCube->up;
        if(tempCube->status == 2){
            break;
        }
        if (tempCube->status == -1){
            if (ClosedList->traverseLinkList(tempCube) == 0){//not in ClosedList
                if (OpenList->traverseLinkList(tempCube) == 0){//not in OpenList
                    tempCube->setParentPoint(parentCube);
                    H = abs(finalpoint_x - tempCube->coord.x) + abs(finalpoint_y - tempCube->coord.y);
                    G = tempCube->parent->G + 10;
                    F = H + G;
                    tempCube->getG(G);
                    tempCube->getH(H);
                    tempCube->getF();
                    OpenList->insertNode(tempCube);
                }
                else {//in OpenList
                    H = abs(finalpoint_x - tempCube->coord.x) + abs(finalpoint_y - tempCube->coord.y);
                    G = parentCube->G + 10;
                    F = H + G;
                    if (tempCube->F > F){//better choice
                        tempCube->setParentPoint(parentCube);
                        tempCube->getG(G);
                        tempCube->getH(H);
                        tempCube->getF();
                    }

                }
           }
        }

        tempCube = tempCube->left;
        if(tempCube->status == 2){
            break;
        }
        if (tempCube->status == -1){
            if (ClosedList->traverseLinkList(tempCube) == 0){
                if (OpenList->traverseLinkList(tempCube) == 0){
                    tempCube->setParentPoint(parentCube);
                    H =abs(finalpoint_x - tempCube->coord.x) + abs(finalpoint_y - tempCube->coord.y);
                    G = tempCube->parent->G + 10;
                    F = H + G;
                    tempCube->getG(G);
                    tempCube->getH(H);
                    tempCube->getF();
                    OpenList->insertNode(tempCube);
                }
                else {
                    H = abs(finalpoint_x - tempCube->coord.x) + abs(finalpoint_y - tempCube->coord.y);
                    G = parentCube->G + 10;
                    F = H + G;
                    if (tempCube->F > F){
                        tempCube->setParentPoint(parentCube);
                        tempCube->getG(G);
                        tempCube->getH(H);
                        tempCube->getF();
                    }
                }
            }
        }

        tempCube = tempCube->right;
        if(tempCube->status == 2){
            break;
        }
        if (tempCube->status == -1){
            if (ClosedList->traverseLinkList(tempCube) == 0){
                if (OpenList->traverseLinkList(tempCube) == 0){
                    tempCube->setParentPoint(parentCube);
                    H = abs(finalpoint_x - tempCube->coord.x) + abs(finalpoint_y - tempCube->coord.y);
                    G = tempCube->parent->G + 10;
                    F = H + G;
                    tempCube->getG(G);
                    tempCube->getH(H);
                    tempCube->getF();
                    OpenList->insertNode(tempCube);
                }
                else {
                    H = abs(finalpoint_x - tempCube->coord.x) + abs(finalpoint_y - tempCube->coord.y);
                    G = parentCube->G + 10;
                    F = H + G;
                    if (tempCube->F > F){
                        tempCube->setParentPoint(parentCube);
                        tempCube->getG(G);
                        tempCube->getH(H);
                        tempCube->getF();
                    }
                }
            }
        }

        tempCube = tempCube->down;
        if(tempCube->status == 2){
            break;
        }
        if (tempCube->status == -1){
            if (ClosedList->traverseLinkList(tempCube) == 0){
                if (OpenList->traverseLinkList(tempCube) == 0){
                    tempCube->setParentPoint(parentCube);
                    H = abs(finalpoint_x - tempCube->coord.x) + abs(finalpoint_y - tempCube->coord.y);
                    G = tempCube->parent->G + 10;
                    F = H + G;
                    tempCube->getG(G);
                    tempCube->getH(H);
                    tempCube->getF();
                    OpenList->insertNode(tempCube);
                }
                else {
                    H = abs(finalpoint_x - tempCube->coord.x) + abs(finalpoint_y - tempCube->coord.y);
                    G = parentCube->G + 10;
                    F = H + G;
                    if (tempCube->F > F){
                        tempCube->setParentPoint(parentCube);
                        tempCube->getG(G);
                        tempCube->getH(H);
                        tempCube->getF();
                    }
                }
            }
        }

        tempCube = tempCube->left_up;
        if(tempCube->status == 2){
            break;
        }
        if (tempCube->status == -1){
            if (ClosedList->traverseLinkList(tempCube) == 0){
                if (OpenList->traverseLinkList(tempCube) == 0){
                    tempCube->setParentPoint(parentCube);
                    H = abs(finalpoint_x - tempCube->coord.x) + abs(finalpoint_y - tempCube->coord.y);
                    G = tempCube->parent->G + 14;
                    F = H + G;
                    tempCube->getG(G);
                    tempCube->getH(H);
                    tempCube->getF();
                    OpenList->insertNode(tempCube);
                }
                else {
                    H = abs(finalpoint_x - tempCube->coord.x) + abs(finalpoint_y - tempCube->coord.y);
                    G = parentCube->G + 14;
                    F = H + G;
                    if (tempCube->F > F){
                        tempCube->setParentPoint(parentCube);
                        tempCube->getG(G);
                        tempCube->getH(H);
                        tempCube->getF();
                    }
                }
            }
        }

        tempCube = tempCube->left_down;
        if(tempCube->status == 2){
            break;
        }
        if (tempCube->status == -1){
            if (ClosedList->traverseLinkList(tempCube) == 0){
                if (OpenList->traverseLinkList(tempCube) == 0){
                    tempCube->setParentPoint(parentCube);
                    H = abs(finalpoint_x - tempCube->coord.x) + abs(finalpoint_y - tempCube->coord.y);
                    G = tempCube->parent->G + 14;
                    F = H + G;
                    tempCube->getG(G);
                    tempCube->getH(H);
                    tempCube->getF();
                    OpenList->insertNode(tempCube);
                }
                else {
                    H = abs(finalpoint_x - tempCube->coord.x) + abs(finalpoint_y - tempCube->coord.y);
                    G = parentCube->G + 14;
                    F = H + G;
                    if (tempCube->F > F){
                        tempCube->setParentPoint(parentCube);
                        tempCube->getG(G);
                        tempCube->getH(H);
                        tempCube->getF();
                    }
                }
            }
        }

        tempCube = tempCube->right_up;
        if(tempCube->status == 2){
            break;
        }
        if (tempCube->status == -1){
            if (ClosedList->traverseLinkList(tempCube) == 0){
                if (OpenList->traverseLinkList(tempCube) == 0){
                    tempCube->setParentPoint(parentCube);
                    H = abs(finalpoint_x - tempCube->coord.x) + abs(finalpoint_y - tempCube->coord.y);
                    G = tempCube->parent->G + 14;
                    F = H + G;
                    tempCube->getG(G);
                    tempCube->getH(H);
                    tempCube->getF();
                    OpenList->insertNode(tempCube);
                }
                else {
                    H = abs(finalpoint_x - tempCube->coord.x) + abs(finalpoint_y - tempCube->coord.y);
                    G = parentCube->G + 14;
                    F = H + G;
                    if (tempCube->F > F){
                        tempCube->setParentPoint(parentCube);
                        tempCube->getG(G);
                        tempCube->getH(H);
                        tempCube->getF();
                    }
                }
            }
        }

        tempCube = tempCube->right_down;
        if(tempCube->status == 2){
            break;
        }
        if (tempCube->status == -1){
            if (ClosedList->traverseLinkList(tempCube) == 0){
                if (OpenList->traverseLinkList(tempCube) == 0){
                    tempCube->setParentPoint(parentCube);
                    H = abs(finalpoint_x - tempCube->coord.x) + abs(finalpoint_y - tempCube->coord.y);
                    G = tempCube->parent->G + 14;
                    F = H + G;
                    tempCube->getG(G);
                    tempCube->getH(H);
                    tempCube->getF();
                    OpenList->insertNode(tempCube);
                }
                else {
                    H = abs(finalpoint_x - tempCube->coord.x) + abs(finalpoint_y - tempCube->coord.y);
                    G = parentCube->G + 14;
                    F = H + G;
                    if (tempCube->F > F){
                        tempCube->setParentPoint(parentCube);
                        tempCube->getG(G);
                        tempCube->getH(H);
                        tempCube->getF();
                    }
                }
            }
        }

        //find the next cube which has the smallest F
        node tempNode = OpenList->findNextCube();;

        //add parentCube to ClosedList
        ClosedList->insertNode(parentCube);
        tempCube = tempNode.currentCube;
    }

}
