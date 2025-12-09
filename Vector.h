#pragma once


#include <stddef.h>

typedef struct Vector
{
    void*   data;
    size_t  size;
    size_t  element_size;
    size_t  capacity;
}Vector;


/* functions of the vector struct go underneath */


