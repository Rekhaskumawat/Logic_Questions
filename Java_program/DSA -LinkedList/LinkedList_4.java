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
//  Description : implementation of Doubly Circular Linked List
//  Author      : Rekha Kumawat
//  Date        : 25/12/2025
//
//////////////////////////////////////////////////////////////////////////////////////////////////

class DoublyCL
{
    private node first;
    private node last ;
    private int iCount;

    public DoublyCL()
    {
        this.first =null;
        this.last = null;
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
    
    if(this.first == null && this.last == null)
    {
        this.first = newn;
        this.last = newn;
    }
    else
    {
        newn.next = this.first;
        first.prev= newn;
        this.first = newn;
    }
    this.last.next = this.first;
    this.first. prev = this.last;
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
    
    if(this.first == null && this.last == null)
    {
        this.first = newn;
        this.last = newn;
    }
    else
    {
        this.last.next = newn;
        newn.prev = this.last;
        this.last = newn;

    }
    this.last.next = this.first;
    this.first.prev = this.last;
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
        if(this.first == null && this.last == null)
        {
            System.out.println("List is Empty");
            return;
        }
        else if( this.first == this.last)
        {
            this.first = null;
            this.last = null;
        }
        else
        {
            first = first.next;
        }
        this.last.next = this.first;
        this.first.prev = this.last;
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
    if(this.first == null && this.last == null)
    {
        System.out.println("List is Empty");
        return;
    }
    else if( this.first == this.last)
    {
        
        this.first = null;
        this.last = null;
    }
    else
    {
        this.last = this.last.prev;
        
    }
    this.last.next = this.first;
    this.first.prev = this.last;
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
    if(this.first == null)
    {
        System.out.println("Linked List is Empty");
        return;
    }
    System.out.print("<=>");
    do
    {
        System.out.print("| "+temp.data+" | <=>");
        temp = temp.next;

    } while (temp != this.first);
    System.out.println("");
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

    if(iPos < 1 || iPos > iCount)
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

        for(iCnt =1 ; iCnt < iPos -1 ;iCnt++)
        {
            temp = temp.next;
        }
        temp.next = temp.next.next;
        temp.next.prev = temp;
    }
    System.gc();
    this.iCount--;
}

}


//////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Main class
//
//////////////////////////////////////////////////////////////////////////////////////////////////

class LinkedList_4
{
    public static void main(String Arr[])
    {
        DoublyCL obj =null;
        int iRet = 0 ;

        obj = new DoublyCL();

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
//     <=>| 11 |<=> | 21 |<=> | 51 |<=> 
//    Number of node are :3
//     <=>| 11 |<=> | 21 |<=> | 51 |<=> | 101 |<=> | 111 |<=> | 121 |<=> 
//    Number of node are :6
//     <=>| 21 |<=> | 51 |<=> | 101 |<=> | 111 |<=> | 121 |<=> 
//    Number of node are :5
//     <=>| 21 |<=> | 51 |<=> | 101 |<=> | 111 |<=> 
//    Number of node are :4
//     <=>| 21 |<=> | 51 |<=> | 105 |<=> | 101 |<=> | 111 |<=> 
//    Number of node are :5
//     <=>| 21 |<=> | 51 |<=> | 101 |<=> | 111 |<=> 
//    Number of node are :4
//

////////////////////////////////////////////////////////////////////////////////////////////////
