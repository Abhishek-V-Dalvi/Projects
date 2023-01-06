#include<iostream>
using namespace std;

struct node
{
    char data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;

class Stack
{
    public:
        PNODE Head;
        int Count;

        Stack();
        void Push(char);        // InsertFirst
        void Pop();            // DeleteFirst
        void Display();
        int CountNode();
};

Stack::Stack()
{
    Head = NULL;
    Count = 0;
}

void Stack::Push(char no)
{
    PNODE newn = NULL;
    newn = new NODE;

    newn->data = no;
    newn->next = NULL;

    newn->next = Head;
    Head = newn;
    cout<<"Entered element is : "<<no<<endl;
    Count++;
}

void Stack::Pop()       // Deletefirst
{
    char no;   // int no;

    if(Count == 0)
    {
        cout<<"Stack is empty"<<endl;
        return;
    }

    no = Head -> data;
    PNODE temp = Head;
    Head = Head->next;
    delete temp;

    Count--;
    cout<<"Removed element is : "<<no<<endl;
}

void Stack::Display()
{
    cout<<"Elements from Stack are : "<<endl;
    PNODE temp = Head;
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int Stack::CountNode()
{
    return Count;
}

int main()
{
        Stack obj1;

        obj1.Push('A');
        obj1.Push('B');
        obj1.Push('C');
        obj1.Push('D');

        obj1.Display();

        obj1.Pop();
        obj1.Pop();

        obj1.Display();

        obj1.Push('Z');
        obj1.Pop();

        return 0;
}