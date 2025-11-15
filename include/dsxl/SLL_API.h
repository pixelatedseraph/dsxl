#ifndef SLL_API_H
#define SLL_API_H

#include "LinkedList.h"

typedef struct 
{
    Node* (*CreateNode) (int);
    void  (*InsertFront) (Node**, int);
    void  (*InsertBack) (Node**,int);
    void  (*Insert) (Node**,int,int);
    void  (*DeleteAtIndex) (Node**,int);
    void  (*DeleteAtFront) (Node**);
    void  (*DeleteAtBack) (Node**);
    int   (*GetLength) (Node*);
    int   (*Locate) (Node*,int);
    bool  (*Contains) (Node*,int);
    void  (*PrintList) (Node*);
}SLL_API;

extern SLL_API LinkedList;

#endif