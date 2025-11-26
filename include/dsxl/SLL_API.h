#ifndef SLL_API_H
#define SLL_API_H

#include <stdarg.h>
#include <stdbool.h>

typedef struct Node Node;

#define sentinel 0x7FFFFFFF
#define ref(L) (&(L))


typedef struct LinkedList
{
    Node*   header; /* end user never touches this */
    int     length;
    /* methods of this Class */
    Node* (*CreateNode) (int);
    void  (*InsertFront) (struct LinkedList*, int);
    void  (*InsertBack) (struct LinkedList*,int);
    void  (*Insert) (struct LinkedList*,int,int);
    void  (*DeleteAtIndex) (struct LinkedList*,int);
    void  (*DeleteAtFront) (struct LinkedList*);
    void  (*DeleteAtBack) (struct LinkedList*);
    int   (*GetLength) (struct LinkedList*);
    int   (*Locate) (struct LinkedList*,int);
    bool  (*Contains) (struct LinkedList*,int);
    void  (*PrintList) (struct LinkedList*);
    void  (*VerbosePrintList) (struct LinkedList*);
    int   (*GetValue) (struct LinkedList*, int);
    void  (*SetValue) (struct LinkedList*, int, int);
    void  (*ClearList) (struct LinkedList*);
    bool  (*IsEmpty) (struct LinkedList*); 
}LinkedList;

extern LinkedList List;
LinkedList new_List(int,...);

#endif