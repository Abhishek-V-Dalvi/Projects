#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node * next;
    struct node * prev;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

class DoublyLinearLL
{
    private:
        PNODE head;
        int CountNode;

    public:
        DoublyLinearLL();
        void InsertFirst(int no);
        void InsertLast(int no);
        void InsertAtPos(int no, int pos);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int pos);
        void Display();
        int Count();
};

DoublyLinearLL::DoublyLinearLL()
{
    head = NULL;
    CountNode = 0;
}

void DoublyLinearLL::InsertFirst(int no)
{
    PNODE newn = NULL;

    newn = new NODE;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(head == NULL)       //If LL is empty
    {
        head = newn;
    }
    else                  //If LL contain atleast 1 node
    {
        newn->next = head;
        head->prev = newn;
        head = newn;
    }
    CountNode++;
}

void DoublyLinearLL::InsertLast(int no)
{
    PNODE temp = NULL;
    PNODE newn = NULL;

    newn = new NODE;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(head == NULL)       //If LL is empty
    {
        head = newn;
    }
    else                  //If LL contain atleast 1 node
    {
        temp = head;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

       temp->next = newn;
       newn->prev = temp;
    }
    CountNode++;
}

void DoublyLinearLL::InsertAtPos(int no, int pos)
{
    if((pos < 1) || (pos > CountNode+1))
    {
        cout<<"Invalid Position"<<endl;
    }
    else if(pos == 1)
    {
        InsertFirst(no);
    }
    else if(pos == CountNode+1)
    {
        InsertLast(no);
    }
    else
    {
        PNODE temp = head;
        PNODE newn = NULL;

        newn = new NODE;
        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        for(int cnt = 1; cnt < pos-1; cnt++)      //cnt  2  temp  200 pos 3 
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;

        CountNode++; 
    }
}

void DoublyLinearLL::DeleteFirst()
{
    if(CountNode == 0)        // if LL  is empty
    {
        return;
    }
    else if(CountNode == 1)
    {
        delete head->next;
        head = NULL;
    }
    else
    {
        head = head->next;
        delete head->prev;
        head->prev = NULL;
    }
    CountNode--;
}

void DoublyLinearLL::DeleteLast()
{
    if(CountNode == 0)        // if LL  is empty
    {
        return;
    }
    else if(CountNode == 1)
    {
        delete head->next;
        head = NULL;
    }
    else
    {
        PNODE temp = head;
        
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    CountNode--;
}

void DoublyLinearLL::DeleteAtPos(int pos)
{
    if((pos < 1) || (pos > CountNode))
    {
        cout<<"Invalid Position"<<endl;
        return;
    }
    else if(pos == 1)
    {
        DeleteFirst();
    }
    else if(pos == CountNode)
    {
        DeleteLast();
    }
    else
    {
        PNODE temp = head;

        for(int cnt = 1; cnt < pos-1; cnt++)       // icnt  1      temp  100      pos 2
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        CountNode--;
    }
}

void DoublyLinearLL::Display()
{
    PNODE temp = head;

    if(head == NULL)
    {
        cout<<"Link list is empty"<<endl;
    }
    else
    {
        while(temp != NULL)
        {
            cout<<"|"<<temp->data<<"|<=>";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }
}

int DoublyLinearLL::Count()
{
    return CountNode;
}

int main()
{
    int iRet = 0;
    DoublyLinearLL obj;

    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.Display();
    iRet = obj.Count();
    cout<<"Number of nodes are : "<<iRet<<endl;
    
    obj.InsertLast(101);
    obj.InsertLast(111);
    obj.Display();
    iRet = obj.Count();
    cout<<"Number of nodes are : "<<iRet<<endl;
    
    obj.InsertAtPos(105,4);
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

    obj.DeleteAtPos(2);
    obj.Display();
    iRet = obj.Count();
    cout<<"Number of nodes are : "<<iRet<<endl;
    
    return 0;
}