#include<stdio.h>
#include<stdlib.h>
#include <dsxl/SLL_API.h>
#include <dsxl/DLL_API.h>
#include <dsxl/LinkedList.h>
#include <dsxl/DLinkedList.h>

int main(){
    LinkedList list = new_List(10,20,30,sentinel);
    list.PrintList(ref(list));
    list.InsertBack(ref(list),40);
    list.PrintList(ref(list));
    list = new_List(50,60,70,sentinel);
    list.PrintList(ref(list));
     list.VerbosePrintList(ref(list)); 
    return 0;
}