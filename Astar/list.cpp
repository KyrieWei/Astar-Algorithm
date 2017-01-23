#include "list.h"
#include <iostream>
using namespace std;

mylist::mylist()
{
    head = (node*)malloc(sizeof(node));
    head->pNext = NULL;
}

void mylist::length(){
    int length = 0;
    node *p = head;
    while(p->pNext != NULL){
        length ++;
        p = p->pNext;
    }
    cout << "the length of list is: " << length << endl;
}

void mylist::insertNode(cube *tempCube){
    node *newNode = (node *)malloc(sizeof(node));
    node *tempNode = head->pNext;
    newNode->currentCube = tempCube;
    head->pNext = newNode;
    newNode->pNext = tempNode;
}

bool mylist::isEmpty(){
    if (head->pNext == NULL){
        return true;
    }
    else
        return false;
}

int mylist::findNextCube(){
    node *tempNode, *smallestNode;
    int position = 1, currentPosition = 1;
    tempNode = head->pNext;
    smallestNode = tempNode;
    while(tempNode->pNext != NULL){
        tempNode = tempNode->pNext;
        currentPosition ++;
        if(smallestNode->currentCube->F > tempNode->currentCube->F){
            smallestNode = tempNode;
            position = currentPosition;
        }
    }
    return position;
}

int mylist::traverseLinkList(cube *tempCube){
    int position = 0;
    node *p = head;
    while(p->pNext != NULL){
        p = p->pNext;
        position ++;
        if(p->currentCube->coord.x == tempCube->coord.x && p->currentCube->coord.y == tempCube->coord.y){
            return position;
        }
    }

    return 0;
}

void mylist::deleteNode(int position){
    node *tempNode, *pDelete;
    tempNode = head;
    for (int i = 0; i < position-1; i ++){
        tempNode = tempNode->pNext;
    }
    pDelete = tempNode->pNext;
    tempNode->pNext = pDelete->pNext;
    delete pDelete;
    pDelete = NULL;
}

bool mylist::isFinalPointInList(){
    node *p = head;
    while(p->pNext != NULL){
        p = p->pNext;
        if (p->currentCube->status == 2)
            return true;
    }
    return false;
}
