// Singly linear linked list

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
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void Display(PNODE Head)
{
    int iCnt = 0;

    while(Head != NULL)
    {
        printf("|%d|->",Head->data);
        Head = Head->next;
    }
    printf("NULL\n");
}

int Count(PNODE Head)
{
    int iCnt = 0;

    while(Head != NULL)
    {
        iCnt++;
        Head = Head->next;
    }
    return iCnt;
}

void InsertFirst(PPNODE Head, int No)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = No;
    newn->next = NULL;

    if(*Head == NULL)       // LL is empty
    {
        *Head = newn;
    }
    else                    // If LL has atleast one element
    {
        newn->next = *Head;
        *Head = newn;
    }
}

void InsertLast(PPNODE Head, int No)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = No;
    newn->next = NULL;

    if(*Head == NULL)
    {
        *Head = newn;
    }
    else
    {
        temp = *Head;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
}

void InsertAtPos(PPNODE Head, int No, int pos)
{
    PNODE newn = NULL;
    PNODE temp = NULL;
    int size = 0, iCnt = 0;

    size = Count(*Head);

    if((pos < 1) || (pos > size+1))
    {
        printf("Invalid position \n");
        return;
    }
    else if(pos == 1)
    {
        InsertFirst(Head,No);
    }
    else if(pos == size+1)
    {
        InsertLast(Head,No);
    }
    else
    {
        newn = (PNODE)malloc(sizeof(NODE));
        newn->next = NULL;
        newn->data = No;
        temp = *Head;

        for(iCnt = 1 ; iCnt < pos-1 ; iCnt++)
        {
            temp = temp->next;    
        }
        newn->next = temp->next;
        temp->next = newn;
    }
}

void DeleteFirst(PPNODE Head)
{
    PNODE temp = NULL;

    if(*Head == NULL)
    {
        printf("Linkd list is empty\n");
        return;
    }
    else if((*Head)->next == NULL)
    {
        free(*Head);
        *Head = NULL;
    }
    else
    {
        temp = *Head;
        *Head = (*Head)->next;
        free(temp);
    }
}

void DeleteLast(PPNODE Head)
{
    PNODE temp = NULL;

    if(*Head == NULL)
    {
        printf("Linkd list is empty\n");
        return;
    }
    else if((*Head)->next == NULL)
    {
        free(*Head);
        *Head = NULL;
    }
    else
    {
        temp = *Head;
        
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
}

void DeleteAtPos(PPNODE Head, int pos)
{
    PNODE temp = NULL;
    PNODE tempdelete = NULL;

    int size = 0, iCnt = 0;

    size = Count(*Head);

    if((pos < 1) || (pos > size))
    {
        printf("Invalid position \n");
        return;
    }
    else if(pos == 1)
    {
        DeleteFirst(Head);
    }
    else if(pos == size)
    {
        DeleteLast(Head);
    }
    else
    {
        temp = *Head;

        for(iCnt = 1 ; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;    
        }
        tempdelete = temp->next;
        temp->next = temp->next->next;
        free(tempdelete);
    }
}

int main()
{
    int Ret = 0;
    PNODE First = NULL;

    InsertFirst(&First,40);
    InsertFirst(&First,30);
    InsertFirst(&First,20);
    InsertFirst(&First,10);
    Display(First);
    Ret = Count(First);
    printf("Number of nodes are : %d\n",Ret);

    InsertLast(&First,50);
    Display(First);
    Ret = Count(First);
    printf("Number of nodes are : %d\n",Ret);

    InsertAtPos(&First,35,4);
    Display(First);
    Ret = Count(First);
    printf("Number of nodes are : %d\n",Ret);

    DeleteFirst(&First);
    Display(First);
    Ret = Count(First);
    printf("Number of nodes are : %d\n",Ret);

    DeleteLast(&First);
    Display(First);
    Ret = Count(First);
    printf("Number of nodes are : %d\n",Ret);

    DeleteAtPos(&First,3);
    Display(First);
    Ret = Count(First);
    printf("Number of nodes are : %d\n",Ret);

    return 0;
    }