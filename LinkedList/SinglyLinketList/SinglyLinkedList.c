#include"Singlyheader.h"
int main(int argc,char **argv)
{
    PNODE head=NULL;
    printf("Count %d\n",count(head));
    InsertFirst(&head,50);
    InsertFirst(&head,40);
    InsertFirst(&head,30);
    DisplayLinkedList(head);
    InsertLast(&head,60);
    InsertLast(&head,70);
    DisplayLinkedList(head);
    printf("Count %d\n",count(head));
    InsertAt(&head,100,3);
    InsertAt(&head,200,4);
    InsertAt(&head,300,1);
    InsertAt(&head,500,count(head)+1);
    InsertAt(&head,600,count(head));
    DisplayLinkedList(head);
    printf("Count %d\n",count(head));
    
    return 0;
}
/**
 * @brief
 * Function:getNode
 * Input:value to store in in linkedlist
 * Output:return pointer of struct node 
 * Use:This function is used to create a new node and initialize its
 *  element with given value and its next pointer to NULL
 * 
 */
PNODE getNode(int data)
{
    PNODE newNode=(PNODE)malloc(sizeof(NODE));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}


/**
 * @brief
 * Function:InsertFirst
 * Input:Address of head to make change in linkedlist and value to store in in linkedlist
 * Output:return true or false that is integer vallue 1 or 0 
 * Use:This function is used to insert elements at first of the linkedlist
 * 
 * 
 */
int InsertFirst(PPNODE head,int data)
{
    PNODE newNode=getNode(data);
    PNODE temp=*head;
    if(temp==NULL)
    {
        temp=newNode;
        *head=temp;
    }
    else
    {
        newNode->next=temp;
        *head=newNode;
    }
    return true;
}

int InsertLast(PPNODE head,int data)
{
    PNODE newNode=getNode(data);
    PNODE temp=*head;
    if(temp==NULL)
    {
        *head=newNode;
    }
    else
    {
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=newNode;
    }
    return true;
}
int count(PNODE head)
{
    int count=0;
    while(head!=NULL)
    {
        count++;
        head=head->next;
    }
    return count;
}
void DisplayLinkedList(PNODE head)
{
  
    while(head!=NULL)
    {
        printf("%d->",head->data);
        head=head->next;
    }
    printf("\n");
}

int InsertAt(PPNODE head,int data,int ipos)
{
    PNODE newNode=getNode(data);
    PNODE temp=*head;
    int icount=count(*head);
    if((ipos>0)&&(ipos<=icount+1))
    {
        if(ipos==1)
            InsertFirst(head,data);
        else if((ipos>1) && (ipos<=icount))
        {
            int tmpCount=1;
            while(tmpCount<=ipos-2)
            {
                temp=temp->next;
                tmpCount++;
            }
            newNode->next=temp->next;
            temp->next=newNode;
        }
        else
            InsertLast(head,data);
        return true;
    }
    else
        return false;

}