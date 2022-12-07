#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node * next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

class SinglyCLL
{
    private:
        PNODE head;
        PNODE tail;

    public:
        SinglyCLL();
        void InsertFirst(int no);
        void InsertLast(int no);
        void InsertAtPos(int no, int pos);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int pos);
        void Display();
        int Count();
};

SinglyCLL::SinglyCLL()
{
    head = NULL;
    tail = NULL;
}

void SinglyCLL::InsertFirst(int no)
{
    PNODE newn = NULL;

    newn = new NODE;

    newn->data = no;
    newn->next = NULL;

    if((head == NULL) && (tail == NULL))
    {
        head = newn;
        tail = newn;
    }
    else
    {
        newn->next = head;
        head = newn;
    }
    tail->next = head;
}

void SinglyCLL::InsertLast(int no)
{
    PNODE newn = NULL;

    newn = new NODE;

    newn->data = no;
    newn->next = NULL;

    if((head == NULL) && (tail == NULL))
    {
        head = newn;
        tail = newn;
    }
    else
    {
        tail->next = newn;
        tail = tail->next;
    }
    tail->next = head;
}

void SinglyCLL::InsertAtPos(int no, int pos)
{
    int size =  Count();

    if((pos <= 0) || (pos > size+1))
    {
        cout<<"Invalid position"<<endl;
        return;
    }
    else if(pos == 1)
    {
        InsertFirst(no);
    }
    else if(pos == size+1)
    {
        InsertLast(no);
    }
    else
    {
        PNODE newn = NULL;
        PNODE temp = NULL;
        newn = new NODE;

        newn->data = no;
        newn->next = NULL;

        temp = head;
        
        for(int iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next= newn;
    }
}

void SinglyCLL::DeleteFirst()
{
    if((head == NULL) && (tail == NULL))
    {
        return;
    }
    else if(head == tail)
    {
        delete head;
        head = NULL;
        tail = NULL;
    }
    else
    {
        head = head->next;
        delete(tail->next);
        tail->next = head;
    }
}

void SinglyCLL::DeleteLast()
{
    PNODE temp = NULL;
    
    if((head == NULL) && (tail == NULL))
    {
        return;
    }
    else if(head == tail)
    {
        delete tail;
        head = NULL;
        tail = NULL;
    }
    else
    {
        temp = head;

        while(temp->next != tail)
        {
            temp = temp->next;
        }

        delete tail;
        tail = temp;
        tail->next = head;
    }
}

void SinglyCLL::DeleteAtPos(int pos)
{
    int size =  Count();

    if((pos <= 0) || (pos > size))
    {
        cout<<"Invalid position"<<endl;
        return;
    }
    else if(pos == 1)
    {
        DeleteFirst();
    }
    else if(pos == size)
    {
        DeleteLast();
    }
    else
    {
        PNODE temp = head;
        PNODE tempdelete = NULL;
        for(int iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }
        tempdelete = temp->next;
        temp->next = temp->next->next;
        delete tempdelete;
    }
}

void SinglyCLL::Display()
{
    PNODE temp = head;

    if((head == NULL) && (tail == NULL))
    {
        cout<<"Link list is empty"<<endl;
    }
    else
    {
        do
        {
            cout<<"|"<<temp->data<<"|->";
            temp = temp->next;
        }while(temp != head);
        
    }
}

int SinglyCLL::Count()
{
    PNODE temp = head;
    int iCnt = 0;
    
    if((head == NULL) && (tail == NULL))
    {
        return 0;
    }
    else
    {
        do
        {
            iCnt++;
            temp = temp->next;
        }while(temp != head);
        cout<<endl;
        return iCnt;
    } 
}

int main()
{
    int iRet = 0;
    SinglyCLL obj;

    obj.Display();
    iRet = obj.Count();
    cout<<"Number of nodes are : "<<iRet<<endl;

    obj.InsertFirst(21);
    obj.InsertFirst(11);
    obj.Display();
    iRet = obj.Count();
    cout<<"Number of nodes are : "<<iRet<<endl;
    
    obj.InsertLast(51);
    obj.InsertLast(101);
    obj.Display();
    iRet = obj.Count();
    cout<<"Number of nodes are : "<<iRet<<endl;

    obj.DeleteFirst();
    obj.Display();
    iRet = obj.Count();
    cout<<"Number of nodes are : "<<iRet<<endl;

    obj.DeleteLast();
    obj.Display();
    iRet = obj.Count();
    cout<<"Number of nodes are : "<<iRet<<endl;

    obj.InsertAtPos(31,2);
    obj.Display();
    iRet = obj.Count();
    cout<<"Number of nodes are : "<<iRet<<endl;

    obj.DeleteAtPos(2);
    obj.Display();
    iRet = obj.Count();
    cout<<"Number of nodes are : "<<iRet<<endl;

    return 0;
}