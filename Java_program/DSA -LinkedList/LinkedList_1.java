//////////////////////////////////////////////////////////////////////////////////////////////////
//
// Class Name  : node 
// Description : Structure for a node of singly linked list
//
//////////////////////////////////////////////////////////////////////////////////////////////////

class node
{
    public int data;
    public node next;

    public node(int no)
    {
        this.data = no;
        this.next = null;
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Class Name  : SinglyLL
//  Description : implementation of Singly Linear Linked List
//  Author      : Rekha Kumawat
//  Date        : 25/12/2025
//
//////////////////////////////////////////////////////////////////////////////////////////////////

class SinglyLL
{
    private node first;
    private int iCount;

    public SinglyLL()
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
        newn.next = this.first;
        this.first = newn;

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
            return ;
        }
        else if(this.first.next == null)
        {
            this.first = null;
        }
        else
        {
            temp = first;
           while(temp.next.next != null)
           {
                temp = temp.next;
           }

           temp.next= null;

        }
        System.gc();
        this.iCount--;
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

        while(temp != null)
        {
            System.out.print("| "+temp.data+" |-> ");
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

    public void InsertAtPos(int no , int pos)
    {
        node temp = null ;
        node newn = null ;
        newn = new node(no);

        if(pos < 1 || pos > (iCount+1))
        {
            System.out.println("Invalid position");
            return ;
        }

        if(pos == 1)
        {
            this.InsertFirst(no);
        }
        else if( pos == iCount+1)
        {
            this.InsertLast(no);
        }
        else
        {
            temp = this.first;
            int iCnt = 0;
            for(iCnt = 1 ; iCnt < pos-1 ; iCnt++)
            {
                temp = temp.next;
            }
            newn.next = temp.next;
            temp.next = newn;
            this.iCount++;
        }
    }

//////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function     : DeleteAtPos
// Description  : Delete node from given position
//
//////////////////////////////////////////////////////////////////////////////////////////////////

    public void DeleteAtPos(int pos)
    {
        node temp = null ;

        if(pos < 1 || pos > (iCount))
        {
            System.out.println("Invalid position");
            return ;
        }

        if(pos == 1)
        {
            this.DeleteFirst();
        }
        else if( pos == iCount+1)
        {
            this.DeleteLast();
        }
        else
        {
            temp = this.first;
            int iCnt = 0;
            for(iCnt = 1 ; iCnt < pos-1 ; iCnt++)
            {
                temp = temp.next;
            }
            temp.next = temp.next.next;
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

class LinkedList_1
{
    public static void main(String Arr[])
    {
        SinglyLL obj =null;
        int iRet = 0 ;

        obj = new SinglyLL();

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
//    | 31 |->| 21 |->| 51 |->NULL
//    numbers of nodes are : 3
//    | 31 |->| 21 |->| 51 |->| 101 |->| 111 |->| 121 |->NULL
//    numbers of nodes are : 6
//    | 21 |->| 51 |->| 101 |->| 111 |->| 121 |->NULL
//    numbers of nodes are : 5
//    | 21 |->| 51 |->| 101 |->| 111 |->NULL
//    numbers of nodes are : 4
//    | 21 |->| 51 |->| 105 |->| 101 |->| 111 |->NULL
//    numbers of nodes are : 5
//    | 21 |->| 51 |->| 101 |->| 111 |->NULL
//    numbers of nodes are : 4
//
//////////////////////////////////////////////////////////////////////////////////////////////////