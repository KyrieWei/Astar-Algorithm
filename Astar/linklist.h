#ifndef LINKLIST_H
#define LINKLIST_H
#include "cube.h"

struct node{
    cube *currentCube;
    node *pNext;
};

class LinkList
{
public:
    LinkList();

    //int length;

    void insertNode(cube *tempCube);
    void deleteNode(int position);
    int traverseLinkList(cube *tempCube);
    node findNextCube();
    bool isEmpty();

private:
    node *head;
};

#endif // LINKLIST_H
