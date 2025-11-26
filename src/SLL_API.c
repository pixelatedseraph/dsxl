#include <dsxl/LinkedList.h>
#include <dsxl/SLL_API.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdarg.h>

/* 
    * instantiate the struct with functions
*/

/* 
    * constructor function to LinkedList
*/
LinkedList new_List(int first,...){
    LinkedList List;
    va_list args;
    va_start (args, first);
    List.header        =  NULL           ;
    List.length        =  0              ;
    int value = first;
    while (value != sentinel) {
        InsertBack(&List, value);
        value = va_arg(args, int);
    }
    va_end (args);
    List.CreateNode    =  CreateNode    ;
    List.InsertFront   =  InsertFront   ; 
    List.InsertBack    =  InsertBack    ;
    List.Insert        =  Insert        ;
    List.DeleteAtIndex =  DeleteAtIndex ;
    List.DeleteAtFront =  DeleteAtFront ;
    List.DeleteAtBack  =  DeleteAtBack  ;
    List.GetLength     =  GetLength     ;
    List.Locate        =  Locate        ;
    List.Contains      =  Contains      ;
    List.PrintList     =  PrintList     ;
    List.VerbosePrintList = VerbosePrintList ;
    List.GetValue      =  GetValue      ;
    List.SetValue      =  SetValue      ;
    List.ClearList     =  ClearList     ;
    List.IsEmpty       =  IsEmpty       ;
    return List;
};


/* SLL_API LinkedList = {
    .CreateNode    =  CreateNode   ,
    .InsertFront   =  InsertFront  , 
    .InsertBack    =  InsertBack   ,
    .Insert        =  Insert       ,
    .DeleteAtIndex =  DeleteAtIndex,
    .DeleteAtFront =  DeleteAtFront,
    .DeleteAtBack  =  DeleteAtBack ,
    .GetLength     =  GetLength    ,
    .Locate        =  Locate       ,
    .Contains      =  Contains     ,
    .PrintList     =  PrintList    ,
}; */