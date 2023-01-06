// Stack

#include <stdio.h>
#include <stdlib.h>

/*
1.PUSH()
2.POP()
3.Count()
4.Display()
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

void PUSH(PPNODE Head, int No)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = No;
    newn->next = NULL;

    if(*Head == NULL)       
    {
        *Head = newn;
    }
    else                    
    {
        newn->next = *Head;
        *Head = newn;
    }
    printf("Entered element is : %d\n",No);
}

void POP(PPNODE Head)
{
    int no = 0;
    PNODE temp = NULL;

    if(*Head == NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    else if((*Head)->next == NULL)
    {
        no = (*Head)->data;
        free(*Head);
        *Head = NULL;
        printf("Removed element is : %d\n",no);
    }
    else
    {
        temp = *Head;
        no = (*Head)->data;
        *Head = (*Head)->next;
        free(temp);
        printf("Removed element is : %d\n",no);
    }
}

int main()
{
    int Ret = 0;
    PNODE First = NULL;

    PUSH(&First,11);
    PUSH(&First,21);
    PUSH(&First,51);
    
    Display(First);
    Ret = Count(First);
    printf("Number of elements in stack are : %d\n",Ret);

    POP(&First);
    POP(&First);
    Display(First);
    Ret = Count(First);
    printf("Number of elements in stack are : %d\n",Ret);

    POP(&First);
    POP(&First);
    Display(First);
    Ret = Count(First);
    printf("Number of elements in stack are : %d\n",Ret);

    return 0;
}