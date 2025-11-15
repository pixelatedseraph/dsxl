#ifndef DLL_API_H
#define DLL_API_H

#include "DLinkedList.h"


typedef struct 
{
    DNode* (*CreateNode) (int);
    void  (*InsertFront) (DNode**, int);
    void  (*InsertBack) (DNode**,int);
    void  (*Insert) (DNode**,int,int);
    void  (*DeleteAtIndex) (DNode**,int);
    void  (*DeleteAtFront) (DNode**);
    void  (*DeleteAtBack) (DNode**);
    int   (*GetLength) (DNode*);
    void  (*PrintList) (DNode*);
    void  (*PrintReversedList) (DNode*);
    void  (*GetValue) (DNode*,int);
    void  (*SetValue) (DNode* ,int , int);
    void  (*ListDuplicates) (DNode*);
}DLL_API;

extern DLL_API DoubleLList;


#endif