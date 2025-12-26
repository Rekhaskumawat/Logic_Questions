//////////////////////////////////////////////////////////////////////////////////////////////////
//
// Class Name  : node 
// Description : Structure for a node of Doubly linked list
//
//////////////////////////////////////////////////////////////////////////////////////////////////

class node
{
    public int data;
    public node next;
    public node prev;

    public node(int no)
    {
        this.data = no;
        this.next = null;
        this.prev = null;
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Class Name  : DoublyLL
//  Description : implementation of Doubly Linear Linked List
//  Author      : Rekha Kumawat
//  Date        : 25/12/2025
//
//////////////////////////////////////////////////////////////////////////////////////////////////

class DoublyLL
{
    private node first;
    private int iCount;

    public DoublyLL()
    {
        this.first =null;
        this.iCount = 0;
    }

//////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function    : InsertFirst
// Description : Insert node at beginning
//
//////////////////////////////////////////////////////////////////////////////////////////////////

    public void InsertFirst(int no)
    {
        node newn = null;
        newn = new node(no);                    
        
        if(this.first == null)
        {
            this.first = newn;
        }
        else
        {
            newn.next = this.first;
            first.prev = newn;
            this.first = newn;
        }
        this.iCount++;
    }

//////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function    : InsertLast
//  Description : Insert node at end
//
//////////////////////////////////////////////////////////////////////////////////////////////////

    public void InsertLast(int no)
    {
        node newn = null;
        newn = new node(no);
        node temp = null ;
        
        if(this.first == null)
    {
        this.first = newn;
    }
    else
    {
        temp = this.first;

        while(temp.next != null)
        {
            temp = temp.next;
        }

        temp.next = newn;
        newn.prev = temp;
    }
    this.iCount++;
    }
    
//////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function    : DeleteFirst
// Description : Delete first node
//
//////////////////////////////////////////////////////////////////////////////////////////////////

    public void DeleteFirst()
    {
        if(this.first == null)
        {
            return ;
        }
        else if(this.first.next == null)
        {
            this.first = null;
        }
        else
        {
            this.first = this.first.next;
            this.first.prev = null;
        }
        System.gc();
        this.iCount--;
    }

//////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function    : DeleteLast
// Description : Delete last node
//
//////////////////////////////////////////////////////////////////////////////////////////////////

    public void DeleteLast()
    {
        node temp = null;

        if(this.first == null)
        {
            System.out.println("Linked List is Empty");
            return;
        }
        else if(this.first.next == null)
        {
            this.first = null;
        }
        else
        {
            temp = this.first;

            while (temp.next.next != null)
            {
                temp = temp.next;
            }

            temp.next = null;
            
        }
        this.iCount--;
        System.gc();
    }
    
//////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function    : Display
// Description : Display linked list
//
//////////////////////////////////////////////////////////////////////////////////////////////////

public void Display()
{
    node temp = null;
    temp = this.first;
    System.out.print("null <=>");
    while(temp != null)
    {
        System.out.print("| "+temp.data+" |<=> ");
        temp = temp.next;
    }
    System.out.println("null");
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function     : Count
//  Description  : Return number of nodes
//
//////////////////////////////////////////////////////////////////////////////////////////////////

public int Count()
{
    return this.iCount;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function    : InsertAtPos
// Description : Insert node at given position
//
//////////////////////////////////////////////////////////////////////////////////////////////////

public void InsertAtPos(int no , int iPos)
{
    node temp = null ;
    node newn = null ;
    newn = new node(no);

    if(iPos <1 || iPos > iCount+1)
{
    System.out.println("Invalid position");
    return;
}

if(iPos ==1)
{
    this.InsertFirst(no);
}
else if(iPos == iCount+1)
{
    this.InsertLast(no);
}
else
{
    int iCnt = 0;
    temp = this.first;

    for(iCnt =1 ; iCnt < iPos-1 ; iCnt++)
    {
        temp = temp.next;
    }

    newn.next = temp.next;
    temp.next.prev= newn;
    temp.next = newn;
    newn.prev = temp ;
    this.iCount++;
}

}

//////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function     : DeleteAtPos
// Description  : Delete node from given position
//
//////////////////////////////////////////////////////////////////////////////////////////////////

public void DeleteAtPos(int iPos)
{
    node temp = null;
    node target = null;

    if(iPos <1 || iPos > iCount)
    {
        System.out.println("Invalid position");
        return;
    }

    if(iPos ==1)
    {
        this.DeleteFirst();
    }
    else if(iPos == iCount)
    {
        this.DeleteLast();
    }
    else
    {
        int iCnt = 0;
        temp = this.first;
        
        for(iCnt =1 ; iCnt < iPos-1 ; iCnt++)
        {
            temp = temp.next;
        }
        target = temp.next;
        temp.next = target .next;
        target.next.prev = temp;
        System.gc();
        this.iCount--;
    }


}
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Main class
//
//////////////////////////////////////////////////////////////////////////////////////////////////

class LinkedList_3
{
    public static void main(String Arr[])
    {
        DoublyLL obj =null;
        int iRet = 0 ;

        obj = new DoublyLL();

        obj.InsertFirst(51);
        obj.InsertFirst(21);
        obj.InsertFirst(11);
        obj.Display();
        iRet = obj.Count();
        System.out.println("Number of node are :"+iRet);

        obj.InsertLast(101);
        obj.InsertLast(111);
        obj.InsertLast(121);
        obj.Display();
        iRet = obj.Count();
        System.out.println("Number of node are :"+iRet);

        obj.DeleteFirst();
        obj.Display();
        iRet = obj.Count();
        System.out.println("Number of node are :"+iRet);

        obj.DeleteLast();
        obj.Display();
        iRet = obj.Count();
        System.out.println("Number of node are :"+iRet);

        obj.InsertAtPos(105, 3);
        obj.Display();
        iRet = obj.Count();
        System.out.println("Number of node are :"+iRet);

        obj.DeleteAtPos(3);
        obj.Display();
        iRet = obj.Count();
        System.out.println("Number of node are :"+iRet);

        obj = null;
        System.gc();
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//
//    null <=>| 11 |<=> | 21 |<=> | 51 |<=> null
//    Number of node are :3
//    null <=>| 11 |<=> | 21 |<=> | 51 |<=> | 101 |<=> | 111 |<=> | 121 |<=> null
//    Number of node are :6
//    null <=>| 21 |<=> | 51 |<=> | 101 |<=> | 111 |<=> | 121 |<=> null
//    Number of node are :5
//    null <=>| 21 |<=> | 51 |<=> | 101 |<=> | 111 |<=> null
//    Number of node are :4
//    null <=>| 21 |<=> | 51 |<=> | 105 |<=> | 101 |<=> | 111 |<=> null
//    Number of node are :5
//    null <=>| 21 |<=> | 51 |<=> | 101 |<=> | 111 |<=> null
//    Number of node are :4
//
////////////////////////////////////////////////////////////////////////////////////////////////