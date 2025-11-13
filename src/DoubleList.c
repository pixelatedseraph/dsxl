#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<../headers/DLinkedList.h>

DNode* CreateDNode(int data){
    DNode* NewNode = malloc(sizeof(DNode));
    if(!NewNode){
        fprintf(stderr,"Malloc failed\n");
    }
    NewNode->data = data;
    NewNode->next = NULL;
    NewNode->prev = NULL;
    return NewNode;
}

