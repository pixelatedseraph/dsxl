#include<dsxl/DLinkedList.h>
#include<dsxl/DLL_API.h>


DLL_API DoubleLList = {
    .CreateNode         =  CreateDNode          ,
    .InsertFront        =  DInsertFront         , 
    .InsertBack         =  DInsertBack          ,
    .Insert             =  DInsert              ,
    .DeleteAtIndex      =  DDeleteAtIndex       ,
    .DeleteAtFront      =  DDeleteAtFront       ,
    .DeleteAtBack       =  DDeleteAtBack        ,
    .GetLength          =  DGetLength           ,
    .PrintList          =  DPrintList           ,
    .PrintReversedList  =  DReversePrintList    ,
    .GetValue           =  DGetValue            ,
    .SetValue           =  DSetValue            ,
    .ListDuplicates     =  DDuplicates          ,
};