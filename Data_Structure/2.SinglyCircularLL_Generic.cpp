#include <iostream>
using namespace std;

template<class T>
struct node
{
    T data;
    struct node * next;
};

//typedef struct node NODE;
//typedef struct node * PNODE;
//typedef struct node ** PPNODE;

template<class T>
class SinglyCLL
{
    private:
        struct node<T> * head;
        struct node<T> * tail;

    public:
        SinglyCLL();
        void InsertFirst(T no);
        void InsertLast(T no);
        void InsertAtPos(T no, int pos);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int pos);
        void Display();
        int Count();
};

template<class T>
SinglyCLL<T>::SinglyCLL()
{
    head = NULL;
    tail = NULL;
}

template<class T>
void SinglyCLL<T>::InsertFirst(T no)
{
    struct node<T> * newn = NULL;

    newn = new node<T>;

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

template<class T>
void SinglyCLL<T>::InsertLast(T no)
{
    struct node<T> * newn = NULL;

    newn = new node<T>;

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

template<class T>
void SinglyCLL<T>::InsertAtPos(T no, int pos)
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
        struct node<T> * newn = NULL;
        struct node<T> * temp = NULL;
        newn = new node<T>;

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

template<class T>
void SinglyCLL<T>::DeleteFirst()
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

template<class T>
void SinglyCLL<T>::DeleteLast()
{
    struct node<T> * temp = NULL;
    
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

template<class T>
void SinglyCLL<T>::DeleteAtPos(int pos)
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
        struct node<T> * temp = head;
        struct node<T> * tempdelete = NULL;
        for(int iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }
        tempdelete = temp->next;
        temp->next = temp->next->next;
        delete tempdelete;
    }
}

template<class T>
void SinglyCLL<T>::Display()
{
    struct node<T> * temp = head;

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

template<class T>
int SinglyCLL<T>::Count()
{
    struct node<T> * temp = head;
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
    SinglyCLL <int>obj;

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

    cout<<"-----------------------------------"<<endl;

    SinglyCLL <float>obj2;

    obj2.Display();
    iRet = obj2.Count();
    cout<<"Number of nodes are : "<<iRet<<endl;

    obj2.InsertFirst(21.32);
    obj2.InsertFirst(11.65);
    obj2.Display();
    iRet = obj2.Count();
    cout<<"Number of nodes are : "<<iRet<<endl;
    
    obj2.InsertLast(51.75);
    obj2.InsertLast(101.25);
    obj2.Display();
    iRet = obj2.Count();
    cout<<"Number of nodes are : "<<iRet<<endl;

    obj2.DeleteFirst();
    obj2.Display();
    iRet = obj2.Count();
    cout<<"Number of nodes are : "<<iRet<<endl;

    obj2.DeleteLast();
    obj2.Display();
    iRet = obj2.Count();
    cout<<"Number of nodes are : "<<iRet<<endl;

    obj2.InsertAtPos(31.90,2);
    obj2.Display();
    iRet = obj2.Count();
    cout<<"Number of nodes are : "<<iRet<<endl;

    obj2.DeleteAtPos(2);
    obj2.Display();
    iRet = obj2.Count();
    cout<<"Number of nodes are : "<<iRet<<endl;

    return 0;
}