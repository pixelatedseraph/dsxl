#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>
#include<stddef.h>
#include"stringsxl.h"

#pragma GCC diagnostic ignored "-Wint-conversion"


#define SENTINEL_INT        -999999999
#define SENTINEL_DOUBLE     -999999999.99999999
#define SENTINEL_FLOAT      -999999999.9999
#define SENTINEL_CHAR        0x1F
#define SENTINEL_STRING      "\xC0\xAF"

#define new_Int(x, ...) \
        new_int_impl(x, __VA_ARGS__, SENTINEL_INT)

#define new_Double(x, ...) \
        new_double_impl(x, __VA_ARGS__, SENTINEL_DOUBLE)

#define new_Float(x, ...) \
        new_float_impl(x, __VA_ARGS__, SENTINEL_FLOAT)

#define new_Char(x, ...) \
        new_char_impl(x, __VA_ARGS__, SENTINEL_CHAR)

#define new_String(x, ...) \
        new_string_impl(x, __VA_ARGS__, SENTINEL_STRING)

#define TypeError(x,...) \
        _Generic((x), default: _ERROR_invalid_constructor_type)()

#define new(...) CallGenerics(__VA_ARGS__)

#define CallGenerics(x,...)     \
        _Generic((x),            \
        string* : new_String(x, __VA_ARGS__),         \
        const string* : new_String(x, __VA_ARGS__),   \
        int     : new_Int(x, __VA_ARGS__),        \
        float   : new_Float(x, __VA_ARGS__),        \
        char    : new_Char(x, __VA_ARGS__),          \
        double  : new_Double(x, __VA_ARGS__),      \
        default : TypeError(x)             \
)


typedef struct Array
{
    void*   data;
    int     bounds;
}Array;

static inline void _ERROR_invalid_constructor_type(void){
    fprintf(stderr,"[Error] Unsupported type passed in the new constructor\n");
    exit(1);
}

static Array** ArrayRegistry;
static size_t reg_count = 0;
static size_t reg_cap = 0;
static void register_array(Array* _arr_obj){
    if(reg_count == reg_cap){
        reg_cap = reg_cap ? 2 * reg_cap : 4;
        ArrayRegistry = realloc(ArrayRegistry,sizeof(Array*) * reg_cap );
        if(!ArrayRegistry) exit(1);
    }
    ArrayRegistry[reg_count++] = _arr_obj;
}

//private 
static Array* new_int_impl(int count,...){ // user doesnt call this
    /* first pass - count elements */
    va_list args;
    va_start(args,count);
    int ArrayLen = 0;
    int value = count;
    while(value != SENTINEL_INT){
        ArrayLen++;
        value = va_arg(args,int);
    }
    va_end(args);
    /* allocate ArrayObjects */
    Array* ArrayObject = malloc(sizeof(Array));
    if(!ArrayObject) exit(1);
    ArrayObject -> data = malloc(sizeof(int) * ArrayLen);
    if(!ArrayObject->data) exit(1);
    /* second pass - store the elements */
    va_start (args, count);
    value = count;
    for (size_t i = 0 ; i < ArrayLen ; ++i){
        ((int*)ArrayObject -> data)[i] = value;
        value = va_arg(args,int);
    }
    va_end(args);
    ArrayObject ->bounds = ArrayLen;
    register_array(ArrayObject);
    return ArrayObject;
}

static Array* new_double_impl(double count,...){ // user doesnt call this
    /* first pass - count elements */
    va_list args;
    va_start(args,count);
    int ArrayLen = 0;
    double value = count;
    while(value != SENTINEL_DOUBLE){
        ArrayLen++;
        value = va_arg(args,double);
    }
    va_end(args);
    /* allocate ArrayObjects */
    Array* ArrayObject = malloc(sizeof(Array));
    if(!ArrayObject) exit(1);
    ArrayObject -> data = malloc(sizeof(double) * ArrayLen);
    if(!ArrayObject->data) exit(1);
    /* second pass - store the elements */
    va_start (args, count);
    value = count;
    for (size_t i = 0 ; i < ArrayLen ; ++i){
        ((double*)ArrayObject -> data)[i] = value;
        value = va_arg(args,double);
    }
    va_end(args);
    ArrayObject ->bounds = ArrayLen;
    register_array(ArrayObject);
    return ArrayObject;
}


static Array* new_float_impl(double count,...){ // user doesnt call this
    /* first pass - count elements */
    va_list args;
    va_start(args,count);
    int ArrayLen = 0;
    double value =  count;
    while(value != SENTINEL_FLOAT){
        ArrayLen++;
        value = va_arg(args,double);
    }
    va_end(args);
    /* allocate ArrayObjects */
    Array* ArrayObject = malloc(sizeof(Array));
    if(!ArrayObject) exit(1);
    ArrayObject -> data = malloc(sizeof(double) * ArrayLen);
    if(!ArrayObject->data) exit(1);
    /* second pass - store the elements */
    va_start (args, count);
    value = count;
    for (size_t i = 0 ; i < ArrayLen ; ++i){
        ((float*)ArrayObject -> data)[i] = (float) value;
        value = va_arg(args,double);
    }
    va_end(args);
    ArrayObject ->bounds = ArrayLen;
    register_array(ArrayObject);
    return ArrayObject;
}

static Array* new_char_impl(int count,...){ // user doesnt call this
    /* first pass - count elements */
    va_list args;
    va_start(args,count);
    int ArrayLen = 0;
    int value = count;
    while(value != SENTINEL_CHAR){
        ArrayLen++;
        value = va_arg(args,int);
    }
    va_end(args);
    /* allocate ArrayObjects */
    Array* ArrayObject = malloc(sizeof(Array));
    if(!ArrayObject) exit(1);
    ArrayObject -> data = malloc(sizeof(char) * ArrayLen);
    if(!ArrayObject->data) exit(1);
    /* second pass - store the elements */
    va_start (args, count);
    value = count;
    for (size_t i = 0 ; i < ArrayLen ; ++i){
        ((char*)ArrayObject -> data)[i] = (char)value;
        value = va_arg(args,int);
    }
    va_end(args);
    ArrayObject ->bounds = ArrayLen;
    register_array(ArrayObject);
    return ArrayObject;
}

static Array* new_string_impl(string* count,...){ // user doesnt call this
    /* first pass - count elements */
    va_list args;
    va_start(args,count);
    int ArrayLen = 0;
    string* value = count;
    string* sen = new_string(SENTINEL_STRING);
    while(!string_equals(value,sen)){
        ArrayLen++;
        value = va_arg(args,string*);
    }
    va_end(args);
    /* allocate ArrayObjects */
    Array* ArrayObject = malloc(sizeof(Array));
    if(!ArrayObject) exit(1);
    ArrayObject -> data = malloc(sizeof(string*) * ArrayLen);
    if(!ArrayObject->data) exit(1);
    string** slots = ArrayObject->data;
    /* second pass - store the elements */
    va_start (args, count);
    value = count;
    for (size_t i = 0 ; i < ArrayLen ; ++i){
        slots[i] = value;
        value = va_arg(args,string *);
    }
    va_end(args);
    ArrayObject ->bounds = ArrayLen;
    register_array(ArrayObject);
    return ArrayObject;
}

//garbage collector
__attribute__((destructor))
static void destroy_all_arrays(void){
    for(int i = 0 ; i < reg_count ; ++i){
        free(ArrayRegistry[i]->data);
        free(ArrayRegistry[i]);
    }
    free(ArrayRegistry);
}

int main(){
    Array* arr = new(1, 2, 3);
    Array* arr1 = new(new_string("Hello"),new_string("World"),new_string("Welcome"));
    displayln("%S\n",((string*)arr1->data)[2]);
    return 0;
}