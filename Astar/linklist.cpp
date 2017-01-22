#include "linklist.h"
#include <iostream>
using namespace std;

LinkList::LinkList()
{
     head->currentCube = NULL;
     head->pNext = NULL;
}


void LinkList::insertNode(cube *tempCube){
    node *newNode, *tempNode;
    tempNode = head->pNext;
    newNode->currentCube = tempCube;
    head->pNext = newNode;
    newNode->pNext = tempNode;
}

void LinkList::deleteNode(int position){
    node *tempNode, *pDelete;
    tempNode = head;
    for (int i = 0; i < position - 1; i ++){
       tempNode = tempNode->pNext;
    }
    pDelete = tempNode->pNext;
    tempNode->pNext = pDelete->pNext;
    delete pDelete;
    pDelete = NULL;
}

int LinkList::traverseLinkList(cube *tempCube){
    int position = 1;
    node *p = head->pNext;
    while(p->pNext != NULL){
        if(p->currentCube->coord.x == tempCube->coord.x && p->currentCube->coord.y == tempCube->coord.y){
            cout << "success of traverse!" << endl;
            return position;
        }
        else {
            p = p->pNext;
            position ++;
        }
    }
    cout << "success of traverse!" << endl;
    return 0;
}

bool LinkList::isEmpty(){
    if (head->pNext == NULL){
        return true;
    }
    else
        return false;
}

node LinkList::findNextCube(){
    node *tempNode,*smallestNode;
    tempNode = head->pNext;
    smallestNode = tempNode;
    while(tempNode->pNext != NULL){
        tempNode = tempNode->pNext;
        if(smallestNode->currentCube->F > tempNode->currentCube->F){
            smallestNode = tempNode;
        }
    }
    return *smallestNode;
}
