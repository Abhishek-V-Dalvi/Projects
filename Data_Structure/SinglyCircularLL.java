import java.lang.*;
import java.util.*;

class node
{
    public int data;
    public node next;       // struct node * next;
}

class SinglyCLL
{
    public node Head;
    public node Tail;
    public int Count;

    public SinglyCLL()
    {
        Head = null;
        Tail = null;
        Count = 0;
    }

    public void InsertFirst(int no)
    {
        node newn = new node();

        newn.data = no;
        newn.next = null;

        if((Head == null) && (Tail == null))
        {
            Head = newn;
            Tail = newn;
        }
        else
        {
            newn.next = Head;
            Head = newn;
        }
        Tail.next = Head;
        Count++;
    }
    
    public void InsertLast(int no)
    {
        node newn = new node();

        newn.data = no;
        newn.next = null;

        if((Head == null) && (Tail == null))
        {
            Head = newn;
            Tail = newn;
        }
        else
        {
            Tail.next = newn;
            Tail = Tail.next;            
        }
        Tail.next = Head;
        Count++;
    }

    public void Display()
    {
        node temp = Head;

        if((Head == null) && (Tail == null))
        {
            System.out.println("Link list is empty");
        }
        else
        {
            do
            {
                System.out.print("|"+temp.data+"|->");
                temp = temp.next;
            }while(temp != Head);          
            System.out.println("");  
        }
    }

    public int CountNode()
    {
        return Count;
    }
    
    public void DeleteFirst()
    {
        if(Count == 0)
        {
            return;
        }
        else if(Count == 1)
        {
            Head = null;
            Tail = null;
        }
        else
        {
            node temp = Head;
            Head = Head.next;
            Tail.next = Head;
            temp = null;
        }
        Count--;
    }

    public void DeleteLast()
    {
        if(Count == 0)
        {
            return;
        }
        else if(Count == 1)
        {
            Head = null;
            Tail = null;
        }
        else
        {
            node temp = Head;
            while(temp.next.next != Head)
            {
                temp = temp.next;
            }
            temp.next = null;
            temp.next = Head;
        }
        Count--;
    }
    
    public void InsertAtPos(int no, int pos)
    {
        if((pos < 1) || (pos > Count+1))
        {
            return;
        }

        if(pos == 1)
        {
            InsertFirst(no);
        }
        else if(pos == Count+1)
        {
            InsertLast(no);
        }
        else
        {
            node newn = new node();
            newn.data = no;
            newn.next = null;

            node temp = Head;

            for(int i = 1; i< pos-1; i++)
            {
                temp = temp.next;
            }

            newn.next = temp.next;
            temp.next = newn;

            Count++;
        }
    }
    
    public void DeleteAtPos(int pos)
    {
        if((pos < 1) || (pos > Count))
        {
            return;
        }

        if(pos == 1)
        {
            DeleteFirst();
        }
        else if(pos == Count)
        {
            DeleteLast();
        }
        else
        {
            node temp = Head;
            node tempdelete = null;

            for(int i = 1; i< pos-1; i++)
            {
                temp = temp.next;
            }
            tempdelete = temp.next;
            temp.next = temp.next.next;
            tempdelete= null;
            Count--;
        }
    }
}

class SinglyCircularLL
{
    public static void main(String arg[])
    {
        SinglyCLL obj = new SinglyCLL();

        obj.InsertFirst(51);
        obj.InsertFirst(21);
        obj.InsertFirst(11);
        obj.Display();
        System.out.println("Number of nodes are : "+obj.CountNode());

        obj.InsertLast(101);
        obj.InsertLast(111);
        obj.Display();
        System.out.println("Number of nodes are : "+obj.CountNode());

        obj.InsertAtPos(55,4);
        obj.Display();
        System.out.println("Number of nodes are : "+obj.CountNode());

        obj.DeleteAtPos(4);
        obj.Display();
        System.out.println("Number of nodes are : "+obj.CountNode());
        
        obj.DeleteFirst();
        obj.Display();
        System.out.println("Number of nodes are : "+obj.CountNode());

        obj.DeleteLast();
        obj.Display();
        System.out.println("Number of nodes are : "+obj.CountNode());
    }
}


/*
    All DS code in C                            6
    All DS code in C++ (Specific)         6
    All DS code in C++ (Generic)         6
    All DS code in Java (Specific)         6

    Total applications : 24
*/
