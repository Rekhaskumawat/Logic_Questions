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

struct DoublyLLLnode
{
    T data;
    struct DoublyLLLnode<T>*next;
    struct DoublyLLLnode<T>*prev;

};


//////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Class Name  : DoublyLLL
//  Description : implementation of Doubly Linear Linked List
//  Author      : Rekha Kumawat
//  Date        : 30/12/2025
//
//////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>

class DoublyLLL
{
    private:

        struct DoublyLLLnode<T>* first;
        int iCount;
    
    public:
        DoublyLLL();
        void InsertFirst(T iNo);
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
// Function    : DoublyLLL
// Description : Constructor definition
//
//////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
DoublyLLL<T> :: DoublyLLL()
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

template <class T>

void DoublyLLL<T> ::InsertFirst(T iNo)
{
    struct DoublyLLLnode<T>*newn = NULL;
    newn = new struct DoublyLLLnode<T>;
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

template <class T>

void DoublyLLL<T> ::InsertLast(T iNo)
{
    struct DoublyLLLnode<T>* newn = NULL;
    struct DoublyLLLnode<T>* temp = NULL;
    newn = new struct DoublyLLLnode<T>;
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

template <class T>

void DoublyLLL<T> ::InsertAtPos(T iNo , int iPos)
{
    struct DoublyLLLnode<T>* newn = NULL;
    struct DoublyLLLnode<T>* temp = NULL;
    newn = new struct DoublyLLLnode<T>;
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

void DoublyLLL<T> :: DeleteFirst()
{
    struct DoublyLLLnode<T>* temp = NULL;

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
        this->first->prev = NULL;
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

template <class T>
void DoublyLLL<T> :: DeleteLast()
{
    struct DoublyLLLnode<T>* temp = NULL;

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

template <class T >

void DoublyLLL<T> ::DeleteAtPos(int iPos)
{
    struct DoublyLLLnode<T>* temp = NULL;
    struct DoublyLLLnode<T>* target = NULL;

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
        target->next->prev = temp;
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

template <class T>
void DoublyLLL<T> ::Display()
{
    struct DoublyLLLnode<T>* temp = NULL;
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

template <class T>

int DoublyLLL<T> ::Count()
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
    DoublyLLL<int> dobj;
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