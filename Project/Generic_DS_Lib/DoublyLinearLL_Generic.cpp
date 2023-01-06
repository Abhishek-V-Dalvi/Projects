#include <iostream>
using namespace std;

template<class T>
struct node
{
    T data;
    struct node * next;
    struct node * prev;
};

template<class T>
class DoublyLinearLL
{
    private:
        struct node<T> * head;
        int CountNode;

    public:
        DoublyLinearLL();
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
DoublyLinearLL<T>::DoublyLinearLL()
{
    head = NULL;
    CountNode = 0;
}

template<class T>
void DoublyLinearLL<T>::InsertFirst(T no)
{
    struct node<T> *newn = NULL;

    newn = new node<T>;

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

template<class T>
void DoublyLinearLL<T>::InsertLast(T no)
{
    struct node<T> * temp = NULL;
    struct node<T> * newn = NULL;

    newn = new node<T>;

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

template<class T>
void DoublyLinearLL<T>::InsertAtPos(T no, int pos)
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
        struct node<T> * temp = head;
        struct node<T> * newn = NULL;

        newn = new node<T>;
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

template<class T>
void DoublyLinearLL<T>::DeleteFirst()
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

template<class T>
void DoublyLinearLL<T>::DeleteLast()
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
        struct node<T> * temp = head;
        
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    CountNode--;
}

template<class T>
void DoublyLinearLL<T>::DeleteAtPos(int pos)
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
        struct node<T> * temp = head;

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

template<class T>
void DoublyLinearLL<T>::Display()
{
    struct node<T> * temp = head;

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

template<class T>
int DoublyLinearLL<T>::Count()
{
    return CountNode;
}

int main()
{
    int iRet = 0;
    DoublyLinearLL<int> obj;

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

    cout<<"--------------------------------------------------------"<<endl;

    DoublyLinearLL <float>obj2;

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