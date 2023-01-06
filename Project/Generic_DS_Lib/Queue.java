import java.lang.*;
import java.util.*;

class node
{
    public int data;
    public node next;       // struct node * next;
}

class QueueDS
{
    public node Head;
    public int Count;

    public QueueDS()
    {
        Head = null;
        Count = 0;
    }

    public void Enqueue(int no)
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
            node temp = Head;

            while(temp.next != null)
            {
                temp = temp.next;
            }
            temp.next = newn;
        }
        Count++;
    }

    public void Dequeue()
    {
        int no;
        if(Count == 0)
        {
            System.out.println("Queue is empty");
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

        System.out.print("Elements of queue are : ");
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

class Queue
{
    public static void main(String arg[])
    {
        QueueDS obj = new QueueDS();

        obj.Enqueue(11);
        obj.Enqueue(21);
        obj.Enqueue(51);

        obj.Display();
        System.out.println("Number of elements in queue are : "+obj.CountNode());

        obj.Dequeue();
        obj.Dequeue();

        obj.Display();
        System.out.println("Number of elements in queue are : "+obj.CountNode());

        obj.Dequeue();
        obj.Dequeue();

        obj.Display();
        System.out.println("Number of elements in queue are : "+obj.CountNode());
    }
}