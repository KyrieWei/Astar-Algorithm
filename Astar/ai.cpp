#include "ai.h"
#include "cube.h"
#include <iostream>
#include "list.h"
using namespace std;
AI::AI()
{

}

void AI::newalgorithm(cube *cubeArr[40][40], int startpoint_x, int startpoint_y, int finalpoint_x, int finalpoint_y){
        int G = 0, H = 0, F = 0, position = 0;
        node *p;
        cubeArr[startpoint_x][startpoint_y]->getH(0);
        cubeArr[startpoint_x][startpoint_y]->getG(0);
        cubeArr[startpoint_x][startpoint_y]->getF();

        cube *tempCube;
        tempCube = cubeArr[startpoint_x][startpoint_y];
        cube *parentCube = cubeArr[startpoint_x][startpoint_y];

        mylist OpenList;
        mylist ClosedList;

        //add startpoint to OpenList
        OpenList.insertNode(tempCube);
        //cout << "OpenList: " << endl;
        //OpenList.length();
        cout << "start point: ";
        cout << OpenList.head->pNext->currentCube->coord.x << ", " ;
        cout << OpenList.head->pNext->currentCube->coord.y  <<  endl;
        while(!OpenList.isEmpty()){

           // find the next cube which has the smallest F
            int nextCubePos = OpenList.findNextCube();
            //cout << "next cube position: " << nextCubePos << endl;
            p = OpenList.head;
            for(int i = 0; i < nextCubePos; i ++){
                p = p->pNext;
                tempCube = p->currentCube;
            }

            parentCube = tempCube;

            cout << "next smallest F cube and parentCube: " << parentCube->coord.x << ", " << parentCube->coord.y << endl;

            //add parentCube to ClosedList
            //ClosedList.length();
            ClosedList.insertNode(parentCube);
            //ClosedList.length();

            //delete parentCube from OpenList
            position = OpenList.traverseLinkList(tempCube);
            //cout << "position: " << position << endl;
            OpenList.deleteNode(position);
            //OpenList.length();

            //set G,H,F of the node around parentCube
            //check the up

            if(parentCube->up != NULL){
                tempCube = parentCube->up;
//                if(tempCube->status == 2){
//                    break;
//                }
                if (tempCube->status != 1){
                    if (ClosedList.traverseLinkList(tempCube) == 0){//not in ClosedList
                        if (OpenList.traverseLinkList(tempCube) == 0){//not in OpenList
                            tempCube->setParentPoint(parentCube);
                            H = (abs(finalpoint_x - tempCube->coord.x) + abs(finalpoint_y - tempCube->coord.y))*10;
                            G = tempCube->parent->G + 10;
                            F = H + G;
                            tempCube->getG(G);
                            tempCube->getH(H);
                            tempCube->getF();
                            OpenList.insertNode(tempCube);
                            cout << "add up button!" << endl;
                        }
                        else {//in OpenList
                            H = (abs(finalpoint_x - tempCube->coord.x) + abs(finalpoint_y - tempCube->coord.y))*10;
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
            }

            if(parentCube->left != NULL){
                tempCube = parentCube->left;
//                if(tempCube->status == 2){
//                    break;
//                }
                if (tempCube->status != 1){
                    if (ClosedList.traverseLinkList(tempCube) == 0){
                        if (OpenList.traverseLinkList(tempCube) == 0){
                            tempCube->setParentPoint(parentCube);
                            H = (abs(finalpoint_x - tempCube->coord.x) + abs(finalpoint_y - tempCube->coord.y))*10;
                            G = tempCube->parent->G + 10;
                            F = H + G;
                            tempCube->getG(G);
                            tempCube->getH(H);
                            tempCube->getF();
                            OpenList.insertNode(tempCube);
                            cout << "add left button!" << endl;
                        }
                        else {
                            H = (abs(finalpoint_x - tempCube->coord.x) + abs(finalpoint_y - tempCube->coord.y))*10;
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
            }

            if (parentCube->right != NULL){
                tempCube = parentCube->right;
//                if(tempCube->status == 2){
//                    break;
//                }
                if (tempCube->status != 1){
                    if (ClosedList.traverseLinkList(tempCube) == 0){
                        if (OpenList.traverseLinkList(tempCube) == 0){
                            tempCube->setParentPoint(parentCube);
                            H = (abs(finalpoint_x - tempCube->coord.x) + abs(finalpoint_y - tempCube->coord.y))*10;
                            G = tempCube->parent->G + 10;
                            F = H + G;
                            tempCube->getG(G);
                            tempCube->getH(H);
                            tempCube->getF();
                            OpenList.insertNode(tempCube);
                            cout << "add right button!" << endl;
                        }
                        else {
                            H = (abs(finalpoint_x - tempCube->coord.x) + abs(finalpoint_y - tempCube->coord.y))*10;
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
            }

            if(parentCube->down != NULL){
                tempCube = parentCube->down;
//                if(tempCube->status == 2){
//                    break;
//                }
                if (tempCube->status != 1){
                    if (ClosedList.traverseLinkList(tempCube) == 0){
                        if (OpenList.traverseLinkList(tempCube) == 0){
                            tempCube->setParentPoint(parentCube);
                            H = (abs(finalpoint_x - tempCube->coord.x) + abs(finalpoint_y - tempCube->coord.y))*10;
                            G = tempCube->parent->G + 10;
                            F = H + G;
                            tempCube->getG(G);
                            tempCube->getH(H);
                            tempCube->getF();
                            OpenList.insertNode(tempCube);
                            cout << "add down button!" << endl;
                        }
                        else {
                            H = (abs(finalpoint_x - tempCube->coord.x) + abs(finalpoint_y - tempCube->coord.y))*10;
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
            }

            if(parentCube->left_up != NULL){
                tempCube = parentCube->left_up;
//                if(tempCube->status == 2){
//                    break;
//                }
                if (tempCube->status != 1){
                    if (ClosedList.traverseLinkList(tempCube) == 0){
                        if (OpenList.traverseLinkList(tempCube) == 0){
                            tempCube->setParentPoint(parentCube);
                            H = (abs(finalpoint_x - tempCube->coord.x) + abs(finalpoint_y - tempCube->coord.y))*10;
                            G = tempCube->parent->G + 14;
                            F = H + G;
                            tempCube->getG(G);
                            tempCube->getH(H);
                            tempCube->getF();
                            OpenList.insertNode(tempCube);
                            cout << "add left_up button!" << endl;
                        }
                        else {
                            H = (abs(finalpoint_x - tempCube->coord.x) + abs(finalpoint_y - tempCube->coord.y))*10;
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
            }

            if(parentCube->left_down){
                tempCube = parentCube->left_down;
//                if(tempCube->status == 2){
//                    break;
//                }
                if (tempCube->status != 1){
                    if (ClosedList.traverseLinkList(tempCube) == 0){
                        if (OpenList.traverseLinkList(tempCube) == 0){
                            tempCube->setParentPoint(parentCube);
                            H = (abs(finalpoint_x - tempCube->coord.x) + abs(finalpoint_y - tempCube->coord.y))*10;
                            G = tempCube->parent->G + 14;
                            F = H + G;
                            tempCube->getG(G);
                            tempCube->getH(H);
                            tempCube->getF();
                            OpenList.insertNode(tempCube);
                            cout << "add left_down button!" << endl;
                        }
                        else {
                            H = (abs(finalpoint_x - tempCube->coord.x) + abs(finalpoint_y - tempCube->coord.y))*10;
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
            }

            if(parentCube->right_up != NULL){
                tempCube = parentCube->right_up;
//                if(tempCube->status == 2){
//                    break;
//                }
                if (tempCube->status != 1){
                    if (ClosedList.traverseLinkList(tempCube) == 0){
                        if (OpenList.traverseLinkList(tempCube) == 0){
                            tempCube->setParentPoint(parentCube);
                            H = (abs(finalpoint_x - tempCube->coord.x) + abs(finalpoint_y - tempCube->coord.y))*10;
                            G = tempCube->parent->G + 14;
                            F = H + G;
                            tempCube->getG(G);
                            tempCube->getH(H);
                            tempCube->getF();
                            OpenList.insertNode(tempCube);
                            cout << "add right_up button!" << endl;
                        }
                        else {
                            H = (abs(finalpoint_x - tempCube->coord.x) + abs(finalpoint_y - tempCube->coord.y))*10;
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
            }

            if(parentCube->right_down){
                tempCube = parentCube->right_down;
//                if(tempCube->status == 2){
//                    break;
//                }
                if (tempCube->status != 1){
                    if (ClosedList.traverseLinkList(tempCube) == 0){
                        if (OpenList.traverseLinkList(tempCube) == 0){
                            tempCube->setParentPoint(parentCube);
                            H = (abs(finalpoint_x - tempCube->coord.x) + abs(finalpoint_y - tempCube->coord.y))*10;
                            G = tempCube->parent->G + 14;
                            F = H + G;
                            tempCube->getG(G);
                            tempCube->getH(H);
                            tempCube->getF();
                            OpenList.insertNode(tempCube);
                            cout << "add right_down button!" << endl;
                        }
                        else {
                            H = (abs(finalpoint_x - tempCube->coord.x) + abs(finalpoint_y - tempCube->coord.y))*10;
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
            }


            cout << "end of the code: " << endl;
            OpenList.length();
            p = OpenList.head;
            int a = 1;
            cout << "OpenList node info:" << endl;
            while(p->pNext != NULL){
                p = p->pNext;
                cout << "node " << a << endl;
                cout << "coord: " << p->currentCube->coord.x << ", " << p->currentCube->coord.y << endl;
                cout << "G: " << p->currentCube->G << ",  H: " << p->currentCube->H << ",  H: " << p->currentCube->F << endl;
                cout << "status: " << p->currentCube->status << endl;
                cout << "parent: " << p->currentCube->parent->coord.x << " "  << p->currentCube->parent->coord.y << endl;
                a ++;
            }

           if(OpenList.isFinalPointInList()){
               break;
           }
        }
}


