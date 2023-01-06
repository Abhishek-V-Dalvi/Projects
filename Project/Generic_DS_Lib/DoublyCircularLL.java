import java.lang.*;
import java.util.*;

class node
{
    public int data;
    public node next;       // struct node * next;
    public node prev;
}

class DoublyCLL
{
    public node Head;
    public node Tail;
    public int Count;

    public DoublyCLL()
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
        newn.prev = null;

        if(Count == 0)
        {
            Head = newn;
            Tail = newn;
        }
        else
        {
            newn.next = Head;            
            Head.prev = newn;
            Head = newn;
        }
        Head.prev = Tail;
        Tail.next = Head;
        Count++;
    }
    
    public void InsertLast(int no)
    {
        node newn = new node();

        newn.data = no;
        newn.next = null;
        newn.prev = null;

        if(Count == 0) 
        {
            Head = newn;
            Tail = newn;
        }
        else
        {
            Tail.next = newn;
            newn.prev = Tail;
            Tail = newn;            
        }
        Head.prev = Tail;
        Tail.next = Head;
        Count++;
    }

    public void Display()
    {
        node temp = Head;

        if(Count == 0)
        {
            System.out.println("Link list is empty");
        }
        else
        {
            for(int iCnt = 1; iCnt<= Count; iCnt++)
            {
                System.out.print("|"+temp.data+"|<=>");
                temp = temp.next;
            }          
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
            node temp = Tail;
            Tail = Tail.prev;
            temp = null;
        }
        Tail.next = Head;
        Head.prev = Tail;
        Count--;
    }
    
    public void InsertAtPos(int no, int pos)
    {
        if((pos < 1) || (pos > Count+1))
        {
            System.out.println("Invalid Position");
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
            newn.prev = null;

            node temp = Head;

            for(int i = 1; i< pos-1; i++)
            {
                temp = temp.next;
            }

            newn.next = temp.next;
            temp.next.prev = newn;
            temp.next = newn;
            newn.prev = temp;

            Count++;
        }
    }
    
    public void DeleteAtPos(int pos)
    {
        if((pos < 1) || (pos > Count))
        {
            System.out.println("Invalid Position");
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

            for(int i = 1; i< pos-1; i++)
            {
                temp = temp.next;
            }

            temp.next = temp.next.next;
            temp.next.prev = null;
            temp.next.prev = temp;

            Count--;
        }
    }
}

class DoublyCircularLL
{
    public static void main(String arg[])
    {
        DoublyCLL obj = new DoublyCLL();

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