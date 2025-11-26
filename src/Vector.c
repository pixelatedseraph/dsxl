#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<dsxl/Vector.h>
#include<stdarg.h>

#define end 0x7FFFFFFF

Vector new_vec(int first, ...){
    Vector res;
    res.capacity = 1;
    res.size = 0;
    res.element_size = 4;
    res.data = malloc(res.element_size * res.capacity);
    if (!res.data) exit(1);
    va_list args;
    va_start(args,first);
    int value = first;
    int idx = 0;
    while(value != end){
        ((int*)res.data)[idx++] = value;
        res.size++;
        while(res.capacity <= res.size){
            res.capacity *= 2;
            res.data = realloc(res.data,res.element_size * res.capacity);
            if(!res.data) exit(1);
        } 
        value = va_arg(args,int);
    }
    va_end(args);
    return res;
}

void PrintVector(Vector* v){
    
}