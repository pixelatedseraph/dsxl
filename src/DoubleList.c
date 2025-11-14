#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "../headers/DLinkedList.h"

DNode* CreateDNode(int data){
    DNode* NewNode = malloc(sizeof(DNode));
    if(!NewNode){
        fprintf(stderr,"Malloc failed\n");
        exit(1);
    }
    NewNode->data = data;
    NewNode->next = NULL;
    NewNode->prev = NULL;
    return NewNode;
}

static void KillDNode(DNode* node){
    free(node);
}

void DInsertFront(DNode** head,int data){
    if (!*head){
       DNode* TempNode = CreateDNode(data);
        *head = TempNode;
        return;
    }
    DNode* TempNode = CreateDNode(data);
    DNode* BuffNode = *head;
    TempNode->next = *head;
    BuffNode->prev = TempNode;
    *head = TempNode;
}


void DInsertBack(DNode** head ,int data){
    if(!*head) {
        fprintf(stderr, "HINT: Create a node first \n");
        return;
    }
    DNode* NewNode = CreateDNode(data);
    int Length = DGetLength(*head);
    DNode* TempNode = *head;
    for (int i = 0 ; i < Length-1 ; ++i){
        TempNode = TempNode -> next;
    }
    TempNode->next = NewNode;
    NewNode->prev = TempNode;
}

void DInsert(DNode** head, int data,int idx){
    if(!*head){
        if(idx == 0){
            *head = CreateDNode(data);
            return;
        }
        else{
            fprintf(stderr,"Hint: Create a List first !\n");
            return;
        }
    }
    else{
    int Length = DGetLength(*head);
    if(*head && idx < 0 ){
        fprintf(stderr,"Invalid index\n");
        return;
    }
     if(*head && idx > Length ){
        fprintf(stderr,"Invalid index\n");
        return;
    }
    if (*head && idx == 0){
        DInsertFront(head,data);
        return ;
    }
    if (*head && idx == Length){
        DInsertBack(head,data);
        return;
    }
    if (*head && idx <= Length-1 ){
        DNode* NewNode = CreateDNode(data);
        DNode* TempNode = *head;
        for (int i = 0 ; i < idx-1 ; ++i){
            TempNode = TempNode->next;
        }
        DNode* BuffNode = TempNode->next;
        TempNode->next = NewNode;
        NewNode->prev = TempNode;
        NewNode->next = BuffNode;
        BuffNode->prev = NewNode;
        return;
        }
    }
}

void DDeleteAtFront(DNode** head){
    if (!*head) return;
    DNode* TempNode = *head;
    *head = TempNode -> next;
    if (*head){
       (*head)->prev = NULL;
    }
    KillDNode(TempNode);
    return ;
}


int DGetLength(DNode* head){
    if (!head) return -1;
    int Length = 0;
    DNode* TempNode = head;
    while (TempNode){
        Length++;
        TempNode = TempNode->next;
    }
    return Length;
}

void DPrintList(DNode* head){
    if (!head) {
        fprintf(stderr,"No valid list found\n");
        return ;
    }
    while (head){
        printf("%d -> ",head->data);
        head = head->next;
    }
    printf("NULL");
    printf("\n");
}

void DReversePrintList(DNode* head){
    if(!head){
        fprintf(stderr,"No valid list found!\n");
        return;
    }
    while (head->next){
        head = head ->next;
    }
    DNode* LastNode = head;
    while (LastNode){
        printf("%d -> ",LastNode->data);
        LastNode = LastNode->prev;
    }
    printf("NULL");
    printf("\n");
    return;
}



int main(){
   /*  DNode* node1 = CreateDNode(100);
    DPrintList(node1);
    DInsertBack(&node1,200);
    DPrintList(node1);
    DInsertFront(&node1,50);
    DPrintList(node1); */


    DNode* node2 = CreateDNode(1);
    DInsert(&node2,2,0);
    DInsert(&node2,3,1);
    DPrintList(node2);
    DDeleteAtFront(&node2);
    DPrintList(node2);
    DDeleteAtFront(&node2);
    DPrintList(node2);
    DDeleteAtFront(&node2);
    DDeleteAtFront(&node2);
    DDeleteAtFront(&node2);
    DDeleteAtFront(&node2);
    DPrintList(node2);
   /*  DReversePrintList(node2); */
   
    return 0;
}