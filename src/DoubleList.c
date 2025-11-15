#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include <dsxl/DLinkedList.h>

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


void DDeleteAtBack(DNode** head){
    if(!*head) return ;
    DNode* TempNode = *head;
    int Length = DGetLength(*head);
    if (Length ==1){
        DDeleteAtFront(head);
        return;
    }
    for (int i = 0 ; i < Length - 2; ++i){
        TempNode = TempNode -> next;
    }
    DNode* LastNode = TempNode -> next;
    KillDNode(LastNode);
    TempNode->next = NULL;
    return;
}


void DDeleteAtIndex(DNode** head, int idx){
    if (!*head) return;
    int Length = DGetLength(*head);
    DNode* TempNode = *head;
    if (idx > 0 && idx < Length -1){
        for (int i = 0 ; i < idx -1  ; ++i){
            TempNode = TempNode -> next;
        }
        DNode* DelNode = TempNode -> next;
        DNode* NewLink = DelNode -> next;
        TempNode -> next = NewLink;
        NewLink-> prev = TempNode;
        KillDNode(DelNode);
        return;
    }
    if (idx >= Length){
        fprintf(stderr,"Invalid Index\n");
        return;
    }
    if (idx == 0){
        DDeleteAtFront(head);
        return;
    }
    if(idx == Length -1){
        DDeleteAtBack(head);
        return;
    }
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

void DGetValue(DNode* head,int idx){
    if (!head) return;
    if (idx < 0) return;
    int Length = DGetLength(head);
    if (idx >= Length) return;
    DNode* TempNode = head;
    for (int i =0 ; i < idx -1 ; ++i){
        TempNode = TempNode->next;
    }
    printf("%d \n",(TempNode->next)->data);
    return;
}


void DSetValue(DNode* head ,int data ,int idx){
    if (!head) return;
    if (idx < 0) return;
    int Length = DGetLength(head);
    if (idx >= Length) return;
    DNode* TempNode = head;
    for (int i = 0 ; i < idx -1 ; ++i){
        TempNode = TempNode -> next;
    }
    (TempNode->next)->data = data;
    return;
}

/* static helper function */
static LocateResult* DLocateDuplicates(DNode* head){
    if (!head) return NULL;

    int length = DGetLength(head);
    if (length <= 1) return NULL;

    LocateResult* Result = malloc(sizeof(LocateResult));
    if (!Result) return NULL;

    Result->indices = malloc(sizeof(int) * length);
    if (!Result->indices) {
        free(Result);
        return NULL;
    }

    int* seen = calloc(length, sizeof(int));

    DNode* CurrentNode = head;
    int i = 0;

    while (CurrentNode) {
        DNode* RunnerNode = CurrentNode->next;
        int j = i + 1;

        while (RunnerNode) {
            if (CurrentNode->data == RunnerNode->data) {
                seen[i] = 1;
                seen[j] = 1;
            }
            RunnerNode = RunnerNode->next;
            j++;
        }
        CurrentNode = CurrentNode->next;
        i++;
    }

    // pack unique indices into Result
    Result->size = 0;
    for (int k = 0; k < length; k++) {
        if (seen[k])
            Result->indices[Result->size++] = k;
    }

    free(seen);
    return Result;
}

void DDuplicates(DNode* head){
    LocateResult* Res = DLocateDuplicates(head);

    if (!Res || Res->size == 0) {
        printf("None\n");
        return;
    }

    for (int i = 0; i < Res->size; i++)
        printf("%d ", Res->indices[i]);

    printf("\n");

    free(Res->indices);
    free(Res);
}



/* int main(){
   DNode* node1 = CreateDNode(100);
    DPrintList(node1);
    DInsertBack(&node1,200);
    DPrintList(node1);
    DInsertFront(&node1,50);
    DPrintList(node1); 


    DNode* node2 = CreateDNode(1);
    DInsert(&node2,2,0);
    DInsert(&node2,3,1);
    DPrintList(node2);
    DDeleteAtBack(&node2);
    DPrintList(node2);
    DDeleteAtBack(&node2);
    DPrintList(node2);
    DDeleteAtBack(&node2);
    DPrintList(node2);
    DDeleteAtBack(&node2);
    DPrintList(node2); 
   DReversePrintList(node2); 
   

    DNode* node3 = CreateDNode(5);
    DInsertBack(&node3,10);
    DInsertBack(&node3,15);
    DInsertBack(&node3,20);
    DInsertBack(&node3,25);
    DInsertBack(&node3,30);
    DPrintList(node3);
    DDeleteAtIndex(&node3,3);
    DPrintList(node3);
    DDeleteAtIndex(&node3,1);
    DPrintList(node3);
    DDeleteAtIndex(&node3,3);
    DPrintList(node3);
    DDeleteAtIndex(&node3,0);
    DPrintList(node3);
    DDeleteAtIndex(&node3,1);
    DPrintList(node3);
    DDeleteAtIndex(&node3,1);
    DPrintList(node3); 


    DNode* node3 = CreateDNode(10);
    DInsertBack(&node3,10);
    DInsertBack(&node3,30);
    DInsertBack(&node3,10);
    DInsertBack(&node3,50);
    DInsertBack(&node3,60);
    DPrintList(node3);
     DDuplicates(node3); 
    DGetValue(node3,1);
    DSetValue(node3,90,1);
    DPrintList(node3);
    return 0;
} */