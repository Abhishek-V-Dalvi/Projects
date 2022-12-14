// Double linear linked list

#include <stdio.h>
#include <stdlib.h>

/*
1.InsertFirst()
2.InsertLast()
3.InsertAtPos()
4.DeleteFirst()
5.DelereLast()
6.DeleteAtPos()
7.Count()
8.Display()
*/

struct node
{
    int data;
    struct node * next;
    struct node * prev;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void Display(PNODE head)
{
    printf("Doubly Linked list is :\t");

    while(head != NULL)
    {
        printf("|%d|<=>",head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int Count(PNODE head)
{
    int iCnt = 0;

    while(head != NULL)
    {
        iCnt++;
        head = head->next;
    }
    return iCnt;
}

void InsertFirst(PPNODE head, int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(*head == NULL)
    {
        *head = newn;
    }
    else
    {
        newn->next = *head;
        (*head)->prev = newn;
        *head = newn;
    }
}

void InsertLast(PPNODE head, int no)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(*head == NULL)
    {
        *head = newn;
    }
    else
    {
        temp = *head;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
        newn->prev = temp;
    }
}

void  InsertAtPos(PPNODE head, int no, int pos)
{
    PNODE newn = NULL;
    PNODE temp = NULL;
    int size = 0, iCnt = 0;

    size = Count(*head);

    if((pos < 1) || (pos > size+1))
    {
        printf("Invalid position\n");
        return;
    }
    else if(pos == 1)
    {
        InsertFirst(head,no);
    }
    else if(pos == size+1)
    {
        InsertLast(head,no);
    }
    else
    {
        newn = (PNODE)malloc(sizeof(NODE));
        newn->data = no;
        newn->next = NULL;

        temp = *head;

        for(iCnt = 1; iCnt < size-1; iCnt++)
        {
            temp = temp->next;
        }
        newn->prev = temp;
        newn->next = temp->next;
        temp->next->prev = newn;
        temp->next = newn;

    }
}

void DeleteFirst(PPNODE head)
{
    if(*head == NULL)
    {
        return;
    }
    else if ((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
    }
    else
    {
        (*head) = (*head)->next;
         free((*head)->prev);
        (*head)->prev = NULL;
    }
}

void DeleteLast(PPNODE head)
{
    PNODE temp = NULL;;

    if(*head == NULL)
    {
        return;
    }
    else if ((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
    }
    else
    {
        temp = *head;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
}

void  DeleteAtPos(PPNODE head,int pos)
{
    PNODE temp = NULL;
    
    int size = 0, iCnt = 0;

    size = Count(*head);

    if((pos < 1) || (pos > size))
    {
        printf("Invalid position\n");
        return;
    }
    else if(pos == 1)
    {
        DeleteFirst(head);
    }
    else if(pos == size)
    {
        DeleteLast(head);
    }
    else
    {
        temp = *head;

        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }
        
        temp->next = temp->next->next;
        free(temp->next->prev);
        temp->next->prev = temp;
    }
}

int main()
{
    PNODE first = NULL;
    int ret = 0;

    InsertFirst(&first,21);
    InsertFirst(&first,11);

    Display(first);
    ret = Count(first);
    printf("Number of nodes are : %d\n",ret);

    InsertLast(&first,51);
    InsertLast(&first,101);
    Display(first);
    ret = Count(first);
    printf("Number of nodes are : %d\n",ret);

    DeleteFirst(&first);
    Display(first);
    ret = Count(first);
    printf("Number of nodes are : %d\n",ret);

    DeleteLast(&first);
    Display(first);
    ret = Count(first);
    printf("Number of nodes are : %d\n",ret);

    InsertAtPos(&first,200,2);
    Display(first);
    ret = Count(first);
    printf("Number of nodes are : %d\n",ret);

    DeleteAtPos(&first,2);
    Display(first);
    ret = Count(first);
    printf("Number of nodes are : %d\n",ret);
    
    return 0;
}