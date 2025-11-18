#pragma once
#include <stdbool.h>
#include <stdarg.h>
typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* CreateNode(int);
void InsertFront(Node**, int);
void InsertBack(Node**,int);
void Insert(Node**,int,int);
void DeleteAtIndex(Node**,int);
void DeleteAtFront(Node**);
void DeleteAtBack(Node**);
int GetLength(Node*);
int Locate(Node*,int);
bool Contains(Node*,int);
void PrintList(Node*);
int GetValue(Node*,int);
void SetValue(Node*,int,int);
void ClearList(Node**);
bool IsEmpty(Node*);
void push(Node** ,int,...);