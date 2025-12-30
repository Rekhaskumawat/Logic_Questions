//////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Required header files
//
//////////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;

//////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Structure for a node of Doubly linked list
//
//////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
struct DoublyCLLnode
{
    T data ; 
    struct DoublyCLLnode<T>*next;
    struct DoublyCLLnode<T>*prev;

};

//////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Class Name  : DoublyCLL
//  Description : implementation of Doubly Circular Linked List
//  Author      : Rekha Kumawat
//  Date        : 30/12/2025
//
//////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>

class DoublyCLL
{
    private:
        struct DoublyCLLnode<T>* first;
        struct DoublyCLLnode<T>* last;
        int iCount;

    public:
        DoublyCLL();

        void InsertFirst(T iNo );
        void InsertLast(T iNo);
        void InsertAtPos(T iNo , int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);

        void Display();
        int Count();
    
};

//////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function    : DoublyCLL
// Description : Constructor definition
//
//////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>

DoublyCLL<T> :: DoublyCLL()
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

template <class T >

void DoublyCLL<T> :: InsertFirst(T iNo )
{
    struct DoublyCLLnode<T>* newn = NULL;
    newn = new struct DoublyCLLnode<T>;
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

template <class T>

void DoublyCLL<T> :: InsertLast(T iNo)
{
    struct DoublyCLLnode<T>* newn = NULL;
    newn = new struct DoublyCLLnode<T>;
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

template <class T >

void DoublyCLL<T> ::InsertAtPos(T iNo , int iPos)
{
    struct DoublyCLLnode<T>* temp = NULL;
    struct DoublyCLLnode<T>* newn = NULL;
    newn = new struct DoublyCLLnode<T>;
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

template <class T>

void DoublyCLL<T> ::DeleteFirst()
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

template <class T>
void DoublyCLL<T> ::DeleteLast()
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

template <class T>
void DoublyCLL<T> ::DeleteAtPos(int iPos)
{
    struct DoublyCLLnode<T>* temp = NULL;

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

template <class T>
void DoublyCLL<T> :: Display()
{
    struct DoublyCLLnode<T>* temp = NULL;
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

template <class T>

int DoublyCLL<T> :: Count()
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
    DoublyCLL<int> dobj;
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