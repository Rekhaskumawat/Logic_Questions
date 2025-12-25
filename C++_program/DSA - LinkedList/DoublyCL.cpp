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
    int data ; 
    struct node*next;
    struct node*prev;

};

typedef struct node NODE;
typedef struct node* PNODE ;

//////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Class Name  : DoublyCL
//  Description : implementation of Doubly Circular Linked List
//  Author      : Rekha Kumawat
//  Date        : 25/12/2025
//
//////////////////////////////////////////////////////////////////////////////////////////////////

class DoublyCL
{
    private:
        PNODE first;
        PNODE last;
        int iCount;

    public:
        DoublyCL();

        void InsertFirst(int iNo );
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
// Function    : DoublyCL
// Description : Constructor definition
//
//////////////////////////////////////////////////////////////////////////////////////////////////

DoublyCL :: DoublyCL()
{
    this->first = NULL;
    this->last = NULL;
    this->iCount = 0 ;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function    : InsertFirst
// Description : Insert node at beginning
//
//////////////////////////////////////////////////////////////////////////////////////////////////

void DoublyCL :: InsertFirst(int iNo )
{
    PNODE newn = NULL;
    newn = new NODE;
    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;

    if(this->first == NULL && this->last == NULL)
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        newn->next = this->first;
        first->prev= newn;
        this->first = newn;
    }
    this->last->next = this->first;
    this->first-> prev = this->last;
    this->iCount++;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function    : InsertLast
//  Description : Insert node at end
//
//////////////////////////////////////////////////////////////////////////////////////////////////

void DoublyCL :: InsertLast(int iNo)
{
    PNODE newn = NULL;
    newn = new NODE;
    newn->data= iNo;
    newn->next = NULL;
    newn->prev = NULL;

    if(this->first == NULL && this->last == NULL)
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        this->last->next = newn;
        newn->prev = this->last;
        this->last = newn;

    }
    this->last->next = this->first;
    this->first->prev = this->last;
    this->iCount++;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function    : InsertAtPos
// Description : Insert node at given position
//
//////////////////////////////////////////////////////////////////////////////////////////////////

void DoublyCL ::InsertAtPos(int iNo , int iPos)
{
    PNODE temp = NULL;
    PNODE newn = NULL;
    newn = new NODE;
    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;

    if(iPos < 1 || iPos > iCount+1)
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

        for(iCnt =1 ; iCnt < iPos -1 ;iCnt++)
        {
            temp = temp->next;
        }
        newn -> next = temp->next;
        temp->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;
        this->iCount++;
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function    : DeleteFirst
// Description : Delete first node
//
//////////////////////////////////////////////////////////////////////////////////////////////////

void DoublyCL ::DeleteFirst()
{
    if(this->first == NULL && this->last == NULL)
    {
        cout<<"List is Empty\n";
        return;
    }
    else if( this->first == this->last)
    {
        delete this->first;
        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        first = first->next;
        delete first->prev;
    }
    this->last->next = this->first;
    this->first->prev = this->last;
    this->iCount--;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function    : DeleteLast
// Description : Delete last node
//
//////////////////////////////////////////////////////////////////////////////////////////////////

void DoublyCL ::DeleteLast()
{
    if(this->first == NULL && this->last == NULL)
    {
        cout<<"List is Empty\n";
        return;
    }
    else if( this->first == this->last)
    {
        delete this->first;
        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        this->last = this->last->prev;
        delete this->last->next;
    }
    this->last->next = this->first;
    this->first->prev = this->last;
    this->iCount--;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function     : DeleteAtPos
// Description  : Delete node from given position
//
//////////////////////////////////////////////////////////////////////////////////////////////////

void DoublyCL ::DeleteAtPos(int iPos)
{
    PNODE temp = NULL;

    if(iPos < 1 || iPos > iCount)
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

        for(iCnt =1 ; iCnt < iPos -1 ;iCnt++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;
        this->iCount--;
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function    : Display
// Description : Display linked list
//
//////////////////////////////////////////////////////////////////////////////////////////////////

void DoublyCL :: Display()
{
    PNODE temp = NULL;
    temp = this->first;
    if(this->first == NULL)
    {
        cout<<"Linked List is Empty\n";
        return;
    }
    cout<<"<=>";
    do
    {
        cout<<"| "<<temp->data<<" | <=>";
        temp = temp->next;

    } while (temp != this->first);
    cout<<"\n";
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function     : Count
//  Description  : Return number of nodes
//
//////////////////////////////////////////////////////////////////////////////////////////////////

int DoublyCL :: Count()
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
    DoublyCL dobj;
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

    return 0 ;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//
//    | 11 | <=>| 21 | <=>| 51 | <=>
//    Number of nodes linked list have :3
//    | 11 | <=>| 21 | <=>| 51 | <=>| 101 | <=>| 111 | <=>| 121 | <=>
//    Number of nodes linked list have :6
//   | 21 | <=>| 51 | <=>| 101 | <=>| 111 | <=>| 121 | <=>
//    Number of nodes linked list have :5
//    | 21 | <=>| 51 | <=>| 101 | <=>| 111 | <=>
//    Number of nodes linked list have :4
//    | 21 | <=>| 51 | <=>| 105 | <=>| 101 | <=>| 111 | <=>
//    Number of nodes linked list have :5
//    | 21 | <=>| 51 | <=>| 101 | <=>| 111 | <=>
//    Number of nodes linked list have :4
//
//////////////////////////////////////////////////////////////////////////////////////////////////