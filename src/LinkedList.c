#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include "../headers/LinkedList.h"
#include "../headers/SLL_API.h"
Node* CreateNode(int data){
    Node* NewNode = malloc(sizeof(Node));
    if (!NewNode) {
        fprintf(stderr,"Malloc Failed\n");
        exit(1);
    }
    NewNode->data = data;
    NewNode->next = NULL;
    return NewNode;
}
/* static helper - private */
static void KillNode(Node* node){
    free(node);
}
void InsertFront(Node** head,int data){
    Node* NewNode = CreateNode(data);
    NewNode->next = *head;
    *head = NewNode;
}

void InsertBack(Node** head,int data){
    Node* NewNode = CreateNode(data);
    if(*head == NULL){
        *head = NewNode;
        return;
    } 
    else {
        Node* TempNode = *head;
        while (TempNode->next != NULL){
            TempNode = TempNode -> next;
        }
        TempNode->next = NewNode;
        return;
    }
}

void Insert(Node** head, int data,int idx){

    /* if head is empty  */
    if (!*head){
        if (idx == 0){
            *head = CreateNode(data);
            return;
        }
        else{
            fprintf(stderr,"HINT : Create a node first before inserting anything\n");
            return;
        }
    }
    /* if head isnt empty */
    else{
        if(idx == 0){
            InsertFront(head,data);
            return;
        }
        int Length = GetLength(*head);
        if (idx > Length){
            fprintf(stderr,"Invalid index\n");
            return;
        }
        if (idx == Length){
            InsertBack(head,data);
            return;
        }
    }

    Node* NewNode = CreateNode(data);
        int LeftTarget = idx- 1;
        int RightTarget = idx;
        Node* LeftTemp  = *head;
        Node* RightTemp = *head;
        for (int i = 0 ; i < LeftTarget ;++i){
            LeftTemp = LeftTemp -> next;
        }
        RightTemp = LeftTemp ->next;
        LeftTemp->next = NewNode;
        NewNode->next = RightTemp;
        return;
}

void DeleteAtIndex(Node** head,int idx){
    if(!*head) return ;
    if(idx < 0) {
        fprintf(stderr,"Invalid index\n");
        return;
    }
    if (idx == 0) {
        DeleteAtFront(head);
        return;
    }
    int Length = GetLength(*head);
    if (idx > Length -1){
        fprintf(stderr,"Invalid index\n");
        return;
    }
    if (idx == Length -1){
        DeleteAtBack(head);
        return;
    }
    int LeftTarget = idx -1;
    int RightTarget = idx ;
    Node* LeftTemp = *head;
    Node* RightTemp = *head;
    for(int i = 0 ; i < LeftTarget ; ++i){
        LeftTemp = LeftTemp ->next;
    }
    RightTemp  = LeftTemp -> next;
    Node* TempNode = LeftTemp->next;
    LeftTemp->next = RightTemp->next;
    KillNode(TempNode);
    TempNode = NULL;
}


void DeleteAtFront(Node** head){
    if(!*head) return ;
    int Length = GetLength(*head);
    if (Length == 1) {
        free(*head);
        *head = NULL;
        return;
    }
    Node* PreviousHead = *head;
    Node* SuccessorNode = *head;
    SuccessorNode = SuccessorNode ->next;
    *head = SuccessorNode;
    PreviousHead->next = NULL;
    KillNode(PreviousHead);
}

void DeleteAtBack(Node** head){
    if(!*head) return ;
    int Length = GetLength(*head);
    if (Length == 1) {
        free(*head);
        *head = NULL;
        return;
    }
    Node* SuccessorNode = *head;
    for (int i = 0 ; i < Length - 2 ; ++i){
        SuccessorNode = SuccessorNode ->next;
    }
    Node* TempNode = SuccessorNode->next;
    KillNode(TempNode);
    SuccessorNode->next = NULL;
}

int GetLength (Node* head){
    if(head == NULL) {
        return 0;
    }
    int length = 0;
    Node* TempNode = head;
    while(TempNode != NULL){
        TempNode = TempNode -> next;
        length++;
    }
    return length;
}
/* 
    * returns -1 if fails or returns the index  
*/
int Locate (Node* head, int value){
    int Length = GetLength(head);
    int idx;
    Node* TempNode = head;
    for (int i = 0 ; i < Length ; ++i){
        if (TempNode->data == value){
            idx = i;
            return idx;
        }
        TempNode = TempNode ->next;
    }
    return -1;
}

bool Contains(Node* head, int value){
    int Result =  Locate(head,value);
    return Result >=0 ? true : false ;
}

/* 
    *returns the value at idx 
*/
int GetValue(Node* head,int idx){
    if(head == NULL || idx < 0){
        printf("Invalid Operation!\n");
        exit(1);
    }
    Node* TempNode = head;
    int Length = GetLength(head);
    if (idx > Length -1){
        printf("INVALID INDEX\n");
        exit(1);
    }
    for (int i = 0 ; i < idx ; ++i){
        TempNode = TempNode ->next;
    }
    return TempNode->data;
}
/* 
    *updates the value at certain index 
*/
void SetValue(Node* head,int data,int idx){
    if(head == NULL || idx < 0){
        fprintf(stderr,"Invalid Operation\n");
        exit(1);
    }
    int Length = GetLength(head);
    if (idx > Length -1){
        fprintf(stderr,"INVALID INDEX\n");
        exit(1);
    }
    Node* TempNode = head;
    for (int i = 0 ; i < idx ; ++i){
        TempNode = TempNode ->next;
    }
    TempNode ->data = data;
}
/* 
    *prints the linked list in a pretty format
*/
void PrintList(Node* head){
    if(head == NULL) {
        printf("EMPTY LIST\n");
        return;
    }
    Node* TempNode = head;
    while(TempNode!=NULL){
        printf("%d -> ",TempNode->data);
        TempNode = TempNode -> next;
    }
    printf("NULL");
    printf("\n");
}
/* 
    *free memory
*/
void ClearList(Node** head){
    Node* TempNode = *head;
    while(TempNode!=NULL){
        Node* LoopNode = TempNode->next;
        KillNode(TempNode);
        TempNode = LoopNode;
    } 
    *head = NULL;
}

bool IsEmpty(Node* head){
    if (head == NULL) 
        return true;
    return false;
}

int main(){
    Node* node1 = CreateNode(1);
    Node* node2 = NULL;
   /*  PrintList(node1);
    Insert(&node1,2,1);
    PrintList(node1);
    Insert(&node1,3,3);
    printf("%d \n",IsEmpty(node1));
    ClearList(&node1); */
    Insert(&node2,10,0);
    PrintList(node2);
    Node* node3  = LinkedList.CreateNode(40);
    LinkedList.PrintList(node3);
    
    return 0;
}
