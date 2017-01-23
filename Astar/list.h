#ifndef LIST_H
#define LIST_H
#include "cube.h"

struct node{
    cube *currentCube;
    node *pNext;
};

class mylist
{
public:
    mylist();
    node *head;
    void insertNode(cube *tempCube);
    void length();
    bool isEmpty();
    int findNextCube();
    int traverseLinkList(cube *tempCube);
    void deleteNode(int position);
    bool isFinalPointInList();
};

#endif // LIST_H
