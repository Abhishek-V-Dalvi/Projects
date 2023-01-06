import java.lang.*;
import java.util.*;

class node
{
    public int data;
    public node next;       // struct node * next;
}

class StackDS
{
    public node Head;
    public int Count;

    public StackDS()
    {
        Head = null;
        Count = 0;
    }

    public void PUSH(int no)
    {
        node newn = new node();

        newn.data = no;
        newn.next = null;

        if(Head == null)
        {
            Head = newn;
        }
        else
        {
            newn.next = Head;
            Head = newn;
        }
        Count++;
    }

    public void POP()
    {
        int no;
        if(Count == 0)
        {
            System.out.println("Stack is empty");
            return;
        }
        else if(Count == 1)
        {
            no = Head.data;
            Head = null;
        }
        else
        {
            no = Head.data;
            node temp = Head;
            Head = Head.next;
            temp = null;
        }
        System.out.println("Removed element is : "+no);
        Count--;
    }

    public void Display()
    {
        node temp = Head;

        System.out.print("Elements of stack are : ");
        while(temp != null)
        {
            System.out.print("|"+temp.data+"|-");
            temp = temp.next;
        }
        System.out.println("NULL");
    }

    public int CountNode()
    {
        return Count;
    }   
}

class Stack
{
    public static void main(String arg[])
    {
        StackDS obj = new StackDS();

        obj.PUSH(11);
        obj.PUSH(21);
        obj.PUSH(51);

        obj.Display();
        System.out.println("Number of elements in stack are : "+obj.CountNode());

        obj.POP();
        obj.POP();

        obj.Display();
        System.out.println("Number of elements in stack are : "+obj.CountNode());

        obj.POP();
        obj.POP();

        obj.Display();
        System.out.println("Number of elements in stack are : "+obj.CountNode());
    }
}