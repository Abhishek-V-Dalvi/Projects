#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node * next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void Display(PNODE Head, PNODE Tail)
{
    if((Head == NULL) && (Tail == NULL))
    {
        printf("Link list is empty\n");
    }
    else
    {
        do
        {
            printf("|%d|->",Head->data);
            Head = Head->next;    
        }while(Head != Tail->next);
        printf("\n");
    }
}

int Count(PNODE Head, PNODE Tail)
{
    int iCnt = 0;

    if((Head == NULL) && (Tail == NULL))
    {
        iCnt = 0;
    }
    else
    {
        do
        {
            iCnt++;
            Head = Head->next;    
        }while(Head != Tail->next);
    }
    return iCnt;
}

void InsertFirst(PPNODE Head, PPNODE Tail, int No)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = No;
    newn->next = NULL;

    if((*Head == NULL) && (*Tail == NULL))       // LL is empty
    {
        *Head = newn;
        *Tail = *Head;
    }
    else                    // If LL has atleast one element
    {
        newn->next = *Head;
        *Head = newn;
        (*Tail)->next = *Head;
    }
}

void InsertLast(PPNODE Head, PPNODE Tail, int No)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = No;
    newn->next = NULL;

    if((*Head == NULL) && (*Tail == NULL))
    {
        *Head = newn;
        *Tail = *Head;
    }
    else
    {
        (*Tail)->next = newn;
        *Tail = newn;
        (*Tail)->next = *Head;
    }
}
void InsertAtPos(PPNODE Head, PPNODE Tail, int No, int pos)
{
    PNODE newn = NULL;
    PNODE temp = NULL;
    int size = 0, iCnt = 0;

    size = Count(*Head, *Tail);

    if((pos < 1) || (pos > size+1))
    {
        printf("Invalid position \n");
        return;
    }
    else if(pos == 1)
    {
        InsertFirst(Head,Tail,No);
    }
    else if(pos == size+1)
    {
        InsertLast(Head,Tail,No);
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

void DeleteFirst(PPNODE Head, PPNODE Tail)
{
    PNODE temp = NULL;

    if((*Head == NULL) && (*Tail == NULL))
    {
        printf("Linkd list is empty\n");
        return;
    }
    else if((*Head) == (*Tail))
    {
        free(*Head);
        *Head = NULL;
        *Tail = NULL;
    }
    else
    {
        temp = *Head;
        *Head = (*Head)->next;
        (*Tail)->next = *Head;
        free(temp);
    }
}

void DeleteLast(PPNODE Head, PPNODE Tail)
{
    PNODE temp = NULL;

    if((*Head == NULL) && (*Tail == NULL))
    {
        printf("Linkd list is empty\n");
        return;
    }
    else if((*Head) == (*Tail))
    {
        free(*Head);
        *Head = NULL;
        *Tail = NULL;
    }
    else
    {
        temp = *Head;
        
        while(temp->next->next != *Head)
        {
            temp = temp->next;
        }
        free(temp->next);
        *Tail = temp;
        (*Tail)->next = *Head;
    }
}

void DeleteAtPos(PPNODE Head, PPNODE Tail, int pos)
{
    PNODE temp = NULL;
    PNODE tempdelete = NULL;

    int size = 0, iCnt = 0;

    size = Count(*Head,*Tail);

    if((pos < 1) || (pos > size))
    {
        printf("Invalid position \n");
        return;
    }
    else if(pos == 1)
    {
        DeleteFirst(Head,Tail);
    }
    else if(pos == size)
    {
        DeleteLast(Head,Tail);
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
    PNODE Last = NULL;

    Display(First,Last);
    Ret = Count(First,Last);
    printf("Number of nodes are  : %d\n",Ret);
    
    InsertFirst(&First, &Last, 21);
    InsertFirst(&First, &Last, 11);
    Display(First,Last);
    Ret = Count(First,Last);
    printf("Number of nodes are  : %d\n",Ret);

    InsertLast(&First, &Last, 51);
    InsertLast(&First, &Last, 101);
    Display(First,Last);
    Ret = Count(First,Last);
    printf("Number of nodes are  : %d\n",Ret);

    InsertAtPos(&First, &Last, 71, 3);
    Display(First,Last);
    Ret = Count(First,Last);
    printf("Number of nodes are  : %d\n",Ret);

    DeleteFirst(&First,&Last);
    Display(First,Last);
    Ret = Count(First,Last);
    printf("Number of nodes are  : %d\n",Ret);

    DeleteLast(&First,&Last);
    Display(First,Last);
    Ret = Count(First,Last);
    printf("Number of nodes are  : %d\n",Ret);

    DeleteAtPos(&First,&Last,2);
    Display(First,Last);
    Ret = Count(First,Last);
    printf("Number of nodes are  : %d\n",Ret);

    return 0;
}