#include<stdio.h>
#include<stdlib.h>
#include <dsxl/SLL_API.h>
#include <dsxl/DLL_API.h>
#include <dsxl/LinkedList.h>
#include <dsxl/DLinkedList.h>

int main(){
    LinkedList list = new_List(10,20,30,sentinel);
    list.PrintList(ListHead(list));
    list.DeleteAtBack(&ListHead(list));
    list.PrintList(ListHead(list));
    list.ClearList(&ListHead(list));
    list.PrintList(ListHead(list));
    return 0;
}