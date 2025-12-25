//////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Required header files
//
//////////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;

//////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Structure for a node of singly linked list
//
//////////////////////////////////////////////////////////////////////////////////////////////////


struct node
{
    int data;
    struct node*next;
    struct node*prev;

};

typedef struct node NODE;
typedef struct node* PNODE;

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
    private:
        PNODE first;
        int iCount;
    
    public:
        DoublyLL();
        void InsertFirst(int iNo);
        void InsertLast(int iNo);
        void InsertAtPos(int iNo , int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);

        void Display();
        int Count();
};

//////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function    : DoublyLL
// Description : Constructor definition
//
//////////////////////////////////////////////////////////////////////////////////////////////////

DoublyLL :: DoublyLL()
{
    this->first  = NULL;
    this->iCount = 0 ;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function    : InsertFirst
// Description : Insert node at beginning
//
//////////////////////////////////////////////////////////////////////////////////////////////////


void DoublyLL ::InsertFirst(int iNo)
{
    PNODE newn = NULL;
    newn = new NODE;
    newn->data = iNo;
    newn->next= NULL;
    newn->prev = NULL;

    if(this->first == NULL)
    {
        this->first = newn;
    }
    else
    {
        newn->next = this->first;
        first->prev = newn;
        this->first = newn;
    }
    this->iCount++;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function    : InsertLast
//  Description : Insert node at end
//
//////////////////////////////////////////////////////////////////////////////////////////////////

void DoublyLL ::InsertLast(int iNo)
{
    PNODE newn = NULL;
    PNODE temp = NULL;
    newn = new NODE;
    newn->data = iNo;
    newn->next= NULL;
    newn->prev = NULL;

    if(this->first == NULL)
    {
        this->first = newn;
    }
    else
    {
        temp = this->first;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
        newn->prev = temp;
    }
    this->iCount++;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function    : InsertAtPos
// Description : Insert node at given position
//
//////////////////////////////////////////////////////////////////////////////////////////////////

void DoublyLL ::InsertAtPos(int iNo , int iPos)
{
    PNODE newn = NULL;
    PNODE temp = NULL;
    newn = new NODE;
    newn->data = iNo;
    newn->next= NULL;
    newn->prev = NULL;

    if(iPos <1 || iPos > iCount+1)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(iPos ==1)
    {
        this->InsertFirst(iNo);
    }
    else if(iPos == iCount+1)
    {
        this->InsertLast(iNo);
    }
    else
    {
        int iCnt = 0;
        temp = this->first;

        for(iCnt =1 ; iCnt < iPos-1 ; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next->prev= newn;
        temp->next = newn;
        newn->prev = temp ;

    }
    this->iCount++;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function    : DeleteFirst
// Description : Delete first node
//
//////////////////////////////////////////////////////////////////////////////////////////////////

void DoublyLL :: DeleteFirst()
{
    PNODE temp = NULL;

    if(this->first == NULL)
    {
        cout<<"Linked List is Empty\n";
        return;
    }
    else if(this->first->next == NULL)
    {
        delete this->first;
        this->first = NULL;
    }
    else
    {
        temp= this->first;
        this->first = this->first->next;
        delete temp;

    }
    this->iCount--;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function    : DeleteLast
// Description : Delete last node
//
//////////////////////////////////////////////////////////////////////////////////////////////////

void DoublyLL :: DeleteLast()
{
    PNODE temp = NULL;

    if(this->first == NULL)
    {
        cout<<"Linked List is Empty\n";
        return;
    }
    else if(this->first->next == NULL)
    {
        delete this->first;
        this->first = NULL;
    }
    else
    {
        temp = this->first;

        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete temp->next;

        temp->next = NULL;
        
    }
    this->iCount--;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function     : DeleteAtPos
// Description  : Delete node from given position
//
//////////////////////////////////////////////////////////////////////////////////////////////////

void DoublyLL ::DeleteAtPos(int iPos)
{
    PNODE temp = NULL;
    PNODE target = NULL;

    if(iPos <1 || iPos > iCount)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(iPos ==1)
    {
        this->DeleteFirst();
    }
    else if(iPos == iCount)
    {
        this->DeleteLast();
    }
    else
    {
        int iCnt = 0;
        temp = this->first;
        
        for(iCnt =1 ; iCnt < iPos-1 ; iCnt++)
        {
            temp = temp->next;
        }
        target = temp->next;
        temp->next = target ->next;
        target->prev= temp;
        delete target ;
        
        this->iCount--;
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function    : Display
// Description : Display linked list
//
//////////////////////////////////////////////////////////////////////////////////////////////////

void DoublyLL ::Display()
{
    PNODE temp = NULL;
    temp = this->first;
    cout<<"NULL <=>";
    while (temp != NULL)
    {
        cout<<"| "<<temp->data<<" | <=>";
        temp = temp->next;
    }
    cout<<"NULL\n";
    
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function     : Count
//  Description  : Return number of nodes
//
//////////////////////////////////////////////////////////////////////////////////////////////////

int DoublyLL ::Count()
{
    return this->iCount;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Entry Point Function
//
//////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    DoublyLL dobj;
    int iRet = 0;

    dobj.InsertFirst(51);
    dobj.InsertFirst(21);
    dobj.InsertFirst(11);
    dobj.Display();
    iRet = dobj.Count();
    cout<<"Number of nodes in linked list:"<<iRet<<"\n";

    dobj.InsertLast(101);
    dobj.InsertLast(111);
    dobj.InsertLast(121);
    dobj.Display();
    iRet = dobj.Count();
    cout<<"Number of nodes in linked list:"<<iRet<<"\n";

    dobj.DeleteFirst();
    dobj.Display();
    iRet = dobj.Count();
    cout<<"Number of nodes in linked list:"<<iRet<<"\n";

    dobj.DeleteLast();
    dobj.Display();
    iRet = dobj.Count();
    cout<<"Number of nodes in linked list:"<<iRet<<"\n";

    dobj.InsertAtPos(105, 3);
    dobj.Display();
    iRet = dobj.Count();
    cout<<"Number of nodes in linked list:"<<iRet<<"\n";

    dobj.DeleteAtPos(3);
    dobj.Display();
    iRet = dobj.Count();
    cout<<"Number of nodes in linked list:"<<iRet<<"\n";

    return 0;

}

//////////////////////////////////////////////////////////////////////////////////////////////////
//
//    NULL <=>| 11 | <=>| 21 | <=>| 51 | <=>NULL
//    Number of nodes in linked list:3
//    NULL <=>| 11 | <=>| 21 | <=>| 51 | <=>| 101 | <=>| 111 | <=>| 121 | <=>NULL
//   Number of nodes in linked list:6
//    NULL <=>| 21 | <=>| 51 | <=>| 101 | <=>| 111 | <=>| 121 | <=>NULL
//    Number of nodes in linked list:5
//    NULL <=>| 21 | <=>| 51 | <=>| 101 | <=>| 111 | <=>NULL
//    Number of nodes in linked list:4
//    NULL <=>| 21 | <=>| 51 | <=>| 105 | <=>| 101 | <=>| 111 | <=>NULL
//   Number of nodes in linked list:5
//    NULL <=>| 21 | <=>| 51 | <=>| 101 | <=>| 111 | <=>NULL
//    Number of nodes in linked list:4
//
//////////////////////////////////////////////////////////////////////////////////////////////////