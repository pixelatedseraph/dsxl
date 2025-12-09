#pragma once

typedef struct DNode {
    int data;
    struct DNode* next;
    struct DNode* prev;
} DNode;

typedef struct LocateResult{
    int* indices; /* array of indices that mathced with value passed */
    int size; /* size of the array */
}LocateResult;


DNode* CreateDNode(int);
void DInsertFront(DNode** ,int);
void DInsertBack(DNode** ,int);
void DInsert(DNode** , int , int);
void DDeleteAtFront(DNode**);
void DDeleteAtBack(DNode**);
void DDeleteAtIndex(DNode**,int);
int  DGetLength(DNode*);
void DPrintList(DNode*);
void DReversePrintList(DNode*);
void DGetValue(DNode*,int);
void DSetValue(DNode* , int , int);
void DDuplicates(DNode*);
