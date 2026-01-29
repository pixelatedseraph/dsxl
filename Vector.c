#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"strings.h"

typedef enum Type{
    INT    =  4,
    STRING =  8,
    FLOAT  =  4,
    DOUBLE =  8,
    CHAR   =  1,
} Type;

typedef struct Vec{
    void*   data;
    size_t  size;
    size_t  cap;
    Type    type;
} Vec;

#define ArrayLength(arr) (sizeof(arr)/sizeof(arr)[0])

#define UNCHARP unsigned char*

Vec* newVec(Type T){
    Vec* vec  = malloc(sizeof(Vec));
    vec->data = malloc(T * 4);
    vec->size = 0;
    vec->cap  = 4;
    vec->type = T;
    return vec;
}

void pushBack(Vec* vec, void* data){
    if(!vec || !data) {
        fprintf(stderr,"Invalid Vec or NULL data");
        return;
    }

    if (vec->size == vec->cap){
        size_t newCap = vec->cap * 2;
        void* tmpVecData = realloc(vec->data,newCap * vec->type);
        
        if(!tmpVecData) {
            fprintf(stderr,"Realloc Failure");
            return;
        }
        vec->cap = newCap;
        vec->data = tmpVecData;
    }

    memcpy(
        (UNCHARP)vec->data + vec->size * vec->type,
        data,
        vec->type
    );
    vec->size++;

}

void delVec(Vec* vec){
    free(vec->data);
    vec->data = NULL;
    vec->cap  = 0;
    vec->size = 0;
    vec->type = 0;
    free(vec);
    vec = NULL;
}

void pushByList(Vec* vec , void* list, size_t len){
    for(size_t i = 0 ; i < len ; ++i){
        pushBack(
            vec,
            (UNCHARP)list + i * vec->type
        );
    }
} 


/* void _sanity_print(int* data){
    int* array = malloc(sizeof(int) * 6);
    
    memcpy(array,data,sizeof(int));
    printf("Read and stored %d\n",array)    
}


void sanity_test(){
    int arr [] = {1,2,3,4,5,6};
    for(int i = 0 ; i < ArrayLength(arr) ; ++i){
        _sanity_print(arr+i);
    }
}
 */
int main(int argc , char** argv){

    Vec* v1 = newVec(INT);
    if(!v1) return -1;

    Vec* v2 = newVec(STRING);
    if(!v2) return -1;

    String p1 = new_string("Sammy");
    String p2 = new_string("Loves");
    String p3 = new_string("Faizan");


    pushBack(v2,p1);
    pushBack(v2,p2);
    pushBack(v2,p3);


/*     for(int i = 0 ; i < (int) v1->size ; ++i){
        printf("%d ", *(int*)((UNCHARP)v1->data + i * v1->type));
    }
    printf("\n");
 */
     int list[] = {20,30,40,50,60,70};
    pushByList(v1,list,ArrayLength(list));

    for(int i = 0 ; i < (int) v1->size ; ++i){
        printf("%d ", *(int*)((UNCHARP)v1->data + i * v1->type));
    }
    printf("\n");

    for(int i = 0 ; i < (int) v2->size ; ++i){
        displayln("%S ",(String)((UNCHARP)v2->data + i * v2->type));
    }

    delVec(v1);
    delVec(v2);

    return 0;
}