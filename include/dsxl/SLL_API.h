#ifndef SLL_API_H
#define SLL_API_H

#include <stdarg.h>
#include "LinkedList.h"
#define sentinel 0x7FFFFFFF
#define ListHead(L) ((L).header)


typedef struct 
{
    Node* header; /* end user never touches this */\

    /* methods of this Class */
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
    int   (*GetValue) (Node*, int);
    void  (*SetValue) (Node*, int, int);
    void  (*ClearList) (Node**);
    bool  (*IsEmpty) (Node*); 
    void  (*Push) (Node** ,int count,...);
}LinkedList;

extern LinkedList List;
LinkedList new_List(int,...);

#endif