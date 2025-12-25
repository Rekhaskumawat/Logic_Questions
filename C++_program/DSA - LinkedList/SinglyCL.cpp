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
};
typedef struct node NODE;
typedef struct node* PNODE ;

//////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Class Name  : SinglyCL
//  Description : implementation of Singly Circular Linked List
//  Author      : Rekha Kumawat
//  Date        : 25/12/2025
//
//////////////////////////////////////////////////////////////////////////////////////////////////

class SinglyCL
{
    private:
        PNODE first;
        PNODE last;
        int iCount;

    public:
        SinglyCL();
        void InsertFirst(int iNo);
        void InsertLast(int iNo);
        void InsertAtPos(int iNo, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);

        void Display();
        int Count();
};

//////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function    : SinglyCL
// Description : Constructor definition
//
//////////////////////////////////////////////////////////////////////////////////////////////////

SinglyCL :: SinglyCL()
{
    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function    : InsertFirst
// Description : Insert node at beginning
//
//////////////////////////////////////////////////////////////////////////////////////////////////

void SinglyCL :: InsertFirst(int iNo)
{
    PNODE newn = NULL;
    newn = new NODE;
    newn->data = iNo;
    newn->next = NULL;

    if(this->first == NULL && this->last == NULL)
    {
        this->first = newn;
        this->last = newn;
    }
    else  
    {
        newn->next = this->first;
        this->first = newn;
    
    }
    this->last->next = this->first;
    this->iCount++;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function    : InsertLast
//  Description : Insert node at end
//
//////////////////////////////////////////////////////////////////////////////////////////////////

void SinglyCL :: InsertLast(int iNo)
{
    PNODE newn = NULL;
    newn = new NODE;
    newn->data = iNo;
    newn->next= NULL;

    if(first == NULL || last == NULL)
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        this->last->next = newn ;
        this->last = newn;
    }
    this->last->next = this->first;
    this->iCount ++ ;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function    : InsertAtPos
// Description : Insert node at given position
//
//////////////////////////////////////////////////////////////////////////////////////////////////

void SinglyCL :: InsertAtPos(int iNo , int iPos)
{   
    PNODE temp = NULL;
    PNODE newn = NULL;
    newn = new NODE ;
    newn->data = iNo;
    newn->next = NULL;

    if(iPos <1 || iPos >(iCount+1))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(iPos == 1)
    {
        this->InsertFirst(iNo);
    }
    else if(iPos == iCount+1)
    {
        this->InsertLast(iNo);
    }
    else
    {
        temp = this->first;

        int iCnt = 0;
        for(iCnt = 1 ; iCnt < iPos-1 ; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;
        this->iCount++;
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function    : DeleteFirst
// Description : Delete first node
//
//////////////////////////////////////////////////////////////////////////////////////////////////

void SinglyCL :: DeleteFirst()
{

    if(this->first == NULL && this->last == NULL)
    {
        cout<<"Nothing to delete\n";
        return;
    }
    else if(this->first == this->last)
    {
        delete this->first;
        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        this->first = this->first->next;
        delete this->last->next;
        this->last->next = this->first;
    }
    this->iCount--;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function    : DeleteLast
// Description : Delete last node
//
//////////////////////////////////////////////////////////////////////////////////////////////////

void SinglyCL :: DeleteLast()
{
    PNODE temp = NULL;

    if(this->first == NULL && this->last == NULL)
    {
        cout<<"Nothing to delete\n";
        return;
    }
    else if(this->first == this->last)
    {
        delete this->first;
        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        temp = this->first;

        while(temp->next->next != this->first)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = this->first;
    }
    this->iCount--;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function     : DeleteAtPos
// Description  : Delete node from given position
//
//////////////////////////////////////////////////////////////////////////////////////////////////

void SinglyCL :: DeleteAtPos(int iPos)
{
    PNODE temp = NULL;
    PNODE target = NULL;
    
    if(iPos <1 || iPos >(iCount))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(iPos == 1)
    {
        this->DeleteFirst();
    }
    else if(iPos == iCount)
    {
        this->DeleteLast();
    }
    else
    {
        temp = this->first;
        int iCnt = 0;

        for(iCnt = 1 ; iCnt < iPos-1 ; iCnt++)
        {
            temp = temp->next;
        }
        target = temp->next;
        temp->next = target->next;
        delete target;
        this->iCount--;
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function    : Display
// Description : Display linked list
//
//////////////////////////////////////////////////////////////////////////////////////////////////

void SinglyCL :: Display()
{
    PNODE temp = NULL;
    temp = this->first;
    if(temp == NULL)
    {
        cout<<"Linked list is Empty\n";
        return ;
    }

    do
    {
        cout<<"| "<<temp->data<<" | <=>";
        temp = temp->next ;
    } while (temp != this->first);
    cout<<"\n";
    
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function     : Count
//  Description  : Return number of nodes
//
//////////////////////////////////////////////////////////////////////////////////////////////////

int SinglyCL :: Count()
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
    SinglyCL sobj;

    int iRet = 0;

    sobj.InsertFirst(51);
    sobj.InsertFirst(21);
    sobj.InsertFirst(11);
    sobj.Display();
    iRet = sobj.Count();
    cout<<"Number of nodes linked list have :"<<iRet<<"\n";

    sobj.InsertLast(101);
    sobj.InsertLast(111);
    sobj.InsertLast(121);
    sobj.Display();
    iRet = sobj.Count();
    cout<<"Number of nodes linked list have :"<<iRet<<"\n";

    sobj.DeleteFirst();
    sobj.Display();
    iRet = sobj.Count();
    cout<<"Number of nodes linked list have :"<<iRet<<"\n";

    sobj.DeleteLast();
    sobj.Display();
    iRet = sobj.Count();
    cout<<"Number of nodes linked list have :"<<iRet<<"\n";

    sobj.InsertAtPos(105 , 3);
    sobj.Display();
    iRet = sobj.Count();
    cout<<"Number of nodes linked list have :"<<iRet<<"\n";

    sobj.DeleteAtPos( 3);
    sobj.Display();
    iRet = sobj.Count();
    cout<<"Number of nodes linked list have :"<<iRet<<"\n";

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