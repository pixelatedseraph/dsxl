#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<stdarg.h>
#include <dsxl/LinkedList.h>
#include <dsxl/SLL_API.h>
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
static void KillNode(Node* head){
    free(head);
}

void InsertFront(LinkedList* List,int data){
    Node* NewNode = CreateNode(data);
    if(List->header == NULL){
        List->header = NewNode;
        List->length++;
        return;
    }
    NewNode->next = List->header;
    List->header = NewNode;
    List->length++;
    return;
}

void InsertBack(LinkedList* List,int data){
    Node* NewNode = CreateNode(data);
    if(List->header == NULL){
        List->header = NewNode;
        List->length++;
        return;
    } 
    else {
        Node* TempNode = List->header;
        while (TempNode->next != NULL){
            TempNode = TempNode -> next;
        }
        TempNode->next = NewNode;
        List->length++;
        return;
    }
}

void Insert(LinkedList* List, int data,int idx){

    /* if head is empty  */
    if (!List -> header){
        if (idx == 0){
            List -> header = CreateNode(data);
            List->length++;
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
            InsertFront(List,data);
            return;
        }
        int Length = List->length;
        if (idx > Length){
            fprintf(stderr,"Invalid index\n");
            return;
        }
        if (idx == Length){
            InsertBack(List,data);
            return;
        }
    }

    Node* NewNode = CreateNode(data);
        int LeftTarget = idx- 1;
        int RightTarget = idx;
        Node* LeftTemp  = List -> header;
        Node* RightTemp = List -> header;
        for (int i = 0 ; i < LeftTarget ;++i){
            LeftTemp = LeftTemp -> next;
        }
        RightTemp = LeftTemp ->next;
        LeftTemp->next = NewNode;
        NewNode->next = RightTemp;
        List -> length++;
        return;
}

void DeleteAtIndex(LinkedList* List,int idx){
    if(!List -> header) return ;
    if(idx < 0) {
        fprintf(stderr,"Invalid index\n");
        return;
    }
    if (idx == 0) {
        DeleteAtFront(List);
        return;
    }
    int Length =  List->length;
    if (idx > Length -1){
        fprintf(stderr,"Invalid index\n");
        return;
    }
    if (idx == Length -1){
        DeleteAtBack(List);
        return;
    }
    int LeftTarget = idx -1;
    int RightTarget = idx ;
    Node* LeftTemp = List -> header;
    Node* RightTemp = List -> header;
    for(int i = 0 ; i < LeftTarget ; ++i){
        LeftTemp = LeftTemp ->next;
    }
    RightTemp  = LeftTemp -> next;
    Node* TempNode = LeftTemp->next;
    LeftTemp->next = RightTemp->next;
    KillNode(TempNode);
    TempNode = NULL;
    List -> length--;
    return;
}

void DeleteAtFront(LinkedList* List){
    if(!List -> header) return;
    int Length = List->length;
    if (Length == 1) {
        free(List -> header);
        List -> header = NULL;
        List -> length--;
        return;
    }
    Node* PreviousHead = List -> header;
    Node* SuccessorNode = List -> header;
    SuccessorNode = SuccessorNode ->next;
    List -> header = SuccessorNode;
    PreviousHead->next = NULL;
    KillNode(PreviousHead);
    List -> length--;
    return;
}

void DeleteAtBack(LinkedList* List){
    if(!List -> header) return ;
    int Length = List->length;
    if (Length == 1) {
        free(List -> header);
        List -> header = NULL;
        List -> length--;
        return;
    }
    Node* SuccessorNode = List -> header;
    for (int i = 0 ; i < Length - 2 ; ++i){
        SuccessorNode = SuccessorNode ->next;
    }
    Node* TempNode = SuccessorNode->next;
    KillNode(TempNode);
    SuccessorNode->next = NULL;
    List -> length--;
    return ;
}

int GetLength (LinkedList* List){
    if(List->header == NULL) {
        return 0;
    }
    return List->length;
}
/* 
    * returns -1 if fails or returns the index  
*/
int Locate (LinkedList* List, int value){
    int Length = List->length;
    int idx = 0 ;
    Node* TempNode = List -> header ;
    for (int i = 0 ; i < Length ; ++i){
        if (TempNode->data == value){
            idx = i;
            return idx;
        }
        TempNode = TempNode ->next;
    }
    return -1;
}

bool Contains(LinkedList* List, int value){
    int Result =  Locate(List,value);
    return Result >=0 ? true : false ;
}

/* 
    *returns the value at idx 
*/
int GetValue(LinkedList* List,int idx){
    if(List->header == NULL || idx < 0){
        printf("Invalid Operation!\n");
        exit(1);
    }
    Node* TempNode = List->header;
    int Length = List->length;
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
void SetValue(LinkedList* List,int data,int idx){
    if(List->header == NULL || idx < 0){
        fprintf(stderr,"Invalid Operation\n");
        exit(1);
    }
    int Length =  List->length;
    if (idx > Length -1){
        fprintf(stderr,"INVALID INDEX\n");
        exit(1);
    }
    Node* TempNode = List -> header;
    for (int i = 0 ; i < idx ; ++i){
        TempNode = TempNode ->next;
    }
    TempNode ->data = data;
}
/* 
    *prints the linked list in a pretty format
*/
void PrintList(LinkedList* List){
    if(List -> header == NULL) {
        printf("EMPTY LIST\n");
        return;
    }
    Node* TempNode = List -> header;
    while(TempNode!=NULL){
        printf("%d -> ",TempNode->data);
        TempNode = TempNode -> next;
    }
    printf("NULL");
    printf("\n");
}

/* 
    * prints with extra information
 */

 void VerbosePrintList(LinkedList* List){
    if (!List->header) {
        printf("EMPTY LIST\n");
        return;
    }
    int Length =  List->length;
    Node* TempNode = List->header;
    Node* InfoNode = List->header;
        for (int i =0 ; i < Length ; ++i){
            printf("- - - - - - - - "); printf("- - - - - - - - - ");
        } 
    printf("\n");
        for (int i =0 ; i < Length ; ++i){
            printf("|   %d         | ",TempNode->data); printf("%p  | ",TempNode->next);
            TempNode = TempNode ->next;
        }
    printf("\n");
        for (int i =0 ; i < Length ; ++i){
            printf("- - - - - - - - "); printf("- - - - - - - - - ");
        } 
    printf("\n");
        for (int i =0 ; i < Length ; ++i){
            printf("Node%d: %p              ",i+1,InfoNode);
            InfoNode = InfoNode ->next;
        }
    printf("\n");
    return;
 }

/* 
    *free memory
*/
void ClearList(LinkedList* List){
    Node* TempNode = List -> header;
    while(TempNode!=NULL){
        Node* LoopNode = TempNode->next;
        KillNode(TempNode);
        TempNode = LoopNode;
    } 
    List -> header = NULL;
    List -> length = 0;
}

bool IsEmpty(LinkedList* List){
    if (List->header == NULL) 
        return true;
    return false;
}


/* int main(){
    Node* node1 = CreateNode(1);
    Node* node2 = NULL;
    PrintList(node1);
    Insert(&node1,2,1);
    PrintList(node1);
    Insert(&node1,3,3);
    printf("%d \n",IsEmpty(node1));
    ClearList(&node1); 
    Insert(&node2,10,0);
    PrintList(node2);
    Node* node3  = LinkedList.CreateNode(40);
    LinkedList.PrintList(node3);
    
    return 0;
} */
