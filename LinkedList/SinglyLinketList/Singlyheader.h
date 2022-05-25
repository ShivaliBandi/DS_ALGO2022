#include<stdio.h>
#include<stdlib.h>
#define true 1
#define false 0
typedef struct node
{
    int data;
    struct node *next;
}NODE,*PNODE,**PPNODE;

PNODE getNode(int data);
int InsertFirst(PPNODE head,int data);
int InsertLast(PPNODE head,int data);
int count(PNODE head);
void DisplayLinkedList(PNODE);
int InsertAt(PPNODE head,int data,int ipos);