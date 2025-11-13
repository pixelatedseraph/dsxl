#include "../headers/LinkedList.h"
#include "../headers/SLL_API.h"

/* 
    * instantiate the struct with functions
*/

SLL_API LinkedList = {
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
    .PrintList    =   PrintList    ,
};