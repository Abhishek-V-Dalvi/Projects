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
    int iChoice = 1;
    SinglyCLL obj;
    int iValue = 0, ipos = 0, iRet = 0;

    while(iChoice != 0)
    {
        cout<<endl;
        cout<<"Enter your choice : "<<endl;
        cout<<"1 : Insert First"<<endl;
        cout<<"2 : Insert Last"<<endl;
        cout<<"3 : Insert at position"<<endl;
        cout<<"4 : Delete First"<<endl;
        cout<<"5 : Delete Last"<<endl;
        cout<<"6 : Delete at position"<<endl;
        cout<<"7 : Display the data"<<endl;
        cout<<"8 : Count number of elements"<<endl;
        cout<<"9 : Terminate the application"<<endl;
        cin>>iChoice;

        switch(iChoice)
        {
            case 1:
                cout<<"Enter the value to insert"<<endl;
                cin>>iValue;
                obj.InsertFirst(iValue);
                break;

             case 2:
                cout<<"Enter the value to insert"<<endl;
                cin>>iValue;
                obj.InsertLast(iValue);
                break;

             case 3:
                cout<<"Enter the value to insert"<<endl;
                cin>>iValue;
                cout<<"Enter the position : "<<endl;
                cin>>ipos;
                obj.InsertAtPos(iValue,ipos);
                break;

            case 4:
                obj.DeleteFirst();
               break;

           case 5:
                obj.DeleteLast();
               break;

            case 6:
                cout<<"Enter the position : "<<endl;
                cin>>ipos;
                obj.DeleteAtPos(ipos);
                break;

            case 7:
                obj.Display();
                break;

            case 8:
                iRet = obj.Count();
                cout<<"Number of elements are : "<<iRet<<endl;
                break;

            case 9:
                cout<<"Thank you for using the application"<<endl;
                iChoice = 0;
                break;

            default:
                cout<<"Please enter proper choice\n";
                break;
        }
    }

    return 0;
}