#pragma once
#include <stdbool.h>
#include <stdarg.h>
#include <dsxl/SLL_API.h>
typedef struct Node{
    int data;
    struct Node*  next;
}Node;

Node*  CreateNode(int);
void InsertFront(LinkedList* , int);
void InsertBack(LinkedList* ,int);
void Insert(LinkedList* ,int,int);
void DeleteAtIndex(LinkedList* ,int);
void DeleteAtFront(LinkedList* );
void DeleteAtBack(LinkedList* );
int GetLength(LinkedList* );
int Locate(LinkedList* ,int);
bool Contains(LinkedList* ,int);
void PrintList(LinkedList* );
void VerbosePrintList (LinkedList* );
int GetValue(LinkedList* ,int);
void SetValue(LinkedList* ,int,int);
void ClearList(LinkedList* );
bool IsEmpty(LinkedList*);
