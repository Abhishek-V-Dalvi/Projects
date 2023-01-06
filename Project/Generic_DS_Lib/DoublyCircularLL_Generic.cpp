#include <iostream>
using namespace std;

template<class T>
struct node
{
    T data;
    struct node *next;
    struct node *prev;
};

template<class T>
class DoublyCLL
{
    private:
        struct node<T> * head;
        struct node<T> * tail;
        int CountNode;

    public:
        DoublyCLL();

        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T, int);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);

        int Count();
        void Display();

};

template<class T>
DoublyCLL<T>::DoublyCLL()
{
    head = NULL;
    tail = NULL;
    CountNode = 0;
}

template<class T>
void DoublyCLL<T>::InsertFirst(T iNo)
{
    struct node<T> * newn = NULL;

    newn = new node<T>;

    newn->next = NULL;
    newn->prev = NULL;
    newn->data = iNo;

    if(CountNode == 0)
    {
        head = newn;
        tail = newn;
    }
    else
    {
        newn->next = head;
        head->prev = newn;
        head = newn;
        head->prev = tail;
    }

    head->prev = tail;
    tail->next = head;
    CountNode++;
}

template<class T>
void DoublyCLL<T>::InsertLast(T iNo)
{
    struct node<T> * newn = NULL;
    newn = new node<T>;

    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;

    if(CountNode == 0)  // if((Head == NULL) && (Tail == NULL))
    {
        head = newn;
        tail = newn;
    }
    else
    {
           tail->next = newn;
           newn->prev = tail;

           tail = newn;
    }

    head->prev = tail;
    tail->next = head;

    CountNode++;
}

template<class T>
void DoublyCLL<T>::InsertAtPos(T iNo, int iPos)
{
    if((iPos < 1) || (iPos > CountNode+1))
        {
            cout<<"Invalid position\n";
            return;
        }

        if(iPos == 1)
        {
            InsertFirst(iNo);
        }
        else if(iPos == CountNode+1)
        {
            InsertLast(iNo);
        }
        else
        {
            struct node<T> * newn = NULL;
            newn = new node<T>;

            newn->data = iNo;
            newn->next = NULL;
            newn->prev = NULL;

            struct node<T> * temp = head;

            for(int i = 1; i<iPos-1; i++)
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

template<class T>
void DoublyCLL<T>::DeleteFirst()
{
    if(CountNode == 0)
    {
            return;
    }
    else if(CountNode == 1)
    {
            delete head;
            head = NULL;
            tail = NULL;
    }
    else
    {
            head = head->next;
            delete tail->next;          // delete Head->prev;
    }

    tail->next = head;
    head->prev = tail;
    CountNode--;
}

template<class T>
void DoublyCLL<T>::DeleteLast()
{
    if(CountNode == 0)
    {
            return;
    }
    else if(CountNode == 1)
    {
            delete tail;
            head = NULL;
            tail = NULL;
    }
    else
    {
            tail = tail->prev;
            delete tail->next;          // delete Head->prev;
    }

    tail->next = head;
    head->prev = tail;
    CountNode--;
}

template<class T>
void DoublyCLL<T>::DeleteAtPos(int iPos)
{
    if((iPos < 1) || (iPos > CountNode))
        {
            cout<<"Invalid position\n";
            return;
        }

        if(iPos == 1)
        {
            DeleteFirst();
        }
        else if(iPos == CountNode)
        {
            DeleteLast();
        }
        else
        {
             struct node<T> * temp = head;

            for(int i = 1; i<iPos-1; i++)
            {
                temp = temp->next;
            }

            temp->next = temp->next->next;
            delete temp->next->prev;
            temp->next->prev = temp;

            CountNode--;
        }
}

template<class T>
void DoublyCLL<T>::Display()
{
    int iCnt = 0;
       struct node<T> * temp = head;

       if(CountNode == 0)
       {
            cout<<"Link list is empty";
       }
       else
       {
            for(iCnt = 1; iCnt<= CountNode; iCnt++)
            {
                    cout<<"|"<<temp->data<<"|<=>";
                    temp = temp->next;
            }
       }
       cout<<endl;
}

template<class T>
int DoublyCLL<T>::Count()
{
    return CountNode;
}

int main()
{
    DoublyCLL<int> obj;
    int iRet = 0;

    obj.Display();
    obj.InsertFirst(21);
    obj.InsertFirst(11);
    obj.Display();
    iRet = obj.Count();
    cout<<"Number of nodes are : "<<iRet<<endl;

    obj.InsertLast(31);
    obj.InsertLast(41);
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

    obj.InsertAtPos(25,2);
    obj.Display();
    iRet = obj.Count();
    cout<<"Number of nodes are : "<<iRet<<endl;

    obj.DeleteAtPos(2);
    obj.Display();
    iRet = obj.Count();
    cout<<"Number of nodes are : "<<iRet<<endl;

    cout<<"--------------------------------------------------------"<<endl;

    DoublyCLL <float>obj2;

    obj2.InsertFirst(51.20);
    obj2.InsertFirst(21.95);
    obj2.Display();
    iRet = obj2.Count();
    cout<<"Number of nodes are : "<<iRet<<endl;

    obj2.InsertLast(101.75);
    obj2.InsertLast(111.38);
    obj2.Display();
    iRet = obj2.Count();
    cout<<"Number of nodes are : "<<iRet<<endl;

    obj2.InsertAtPos(105.55,4);
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

    obj2.DeleteAtPos(2);
    obj2.Display();
    iRet = obj2.Count();
    cout<<"Number of nodes are : "<<iRet<<endl;

    return 0;
}