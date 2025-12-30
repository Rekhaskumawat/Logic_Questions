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

template <class T>
struct SinglyLLLnode
{
    T data;
    struct SinglyLLLnode<T> *next;
};

//////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Class Name  : SinglyLLL
//  Description : implementation of Singly Linear Linked List
//  Author      : Rekha Kumawat
//  Date        : 30/12/2025
//
//////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class SinglyLLL
{
    private:                            
        struct SinglyLLLnode<T>*first;
        int iCount;

    public:
        SinglyLLL();

        void InsertFirst(T no);
        void InsertLast(T no);
        void DeleteFirst();
        void DeleteLast();
        void Display();
        int Count();
        void InsertAtPos(T no , int pos);
        void DeleteAtPos(int pos);
};
 
//////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function    : SinglyLLL
// Description : Constructor definition
//
//////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
SinglyLLL<T> :: SinglyLLL()
{
    this->first = NULL;
    this->iCount = 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function    : InsertFirst
// Description : Insert node at beginning
//
//////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>

void SinglyLLL<T> :: InsertFirst(T no)                    
{
    struct SinglyLLLnode<T>* newn = NULL;
    newn = new struct SinglyLLLnode<T>;
    newn->data = no;
    newn->next = NULL;

    newn->next = this->first;
    this->first = newn ;

    this->iCount++;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function    : InsertLast
//  Description : Insert node at end
//
//////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>

void SinglyLLL<T> :: InsertLast(T no)
{
    struct SinglyLLLnode<T>*newn = NULL;
    newn = new struct SinglyLLLnode<T>;
    newn->data = no;
    newn->next = NULL;

    struct SinglyLLLnode<T>*temp = NULL;

    if(this->first == NULL)                                // If list is empty          
    {
        this->first = newn;
    }
    else
    {
        temp = this->first ;
        
        while(temp->next != NULL)
        {
        temp = temp->next;
        }

        temp->next = newn;
    }

    this->iCount++;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function    : DeleteFirst
// Description : Delete first node
//
//////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T> :: DeleteFirst()
{
    struct SinglyLLLnode<T>*temp = NULL;

    if(this->first == NULL)                                 // If list is empty
    {
        cout<<"Linked list is empty\n";
        return ;
    }
    else if(this->first->next == NULL)                      //If only one node //else if(this->iCount ==1)
    {
        delete this->first ;
        this->first = NULL;
    }
    else
    {
        temp = this->first;
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

template <class T>

void SinglyLLL<T> :: DeleteLast()
{
    struct SinglyLLLnode<T>*temp =NULL;

    if(this->first == NULL)                               // If list is empty
    {
        return ;
    }
    else if(this->first->next == NULL)                    // If only one node  //else if(this->iCount ==1)
    {
        delete this->first ;
        this->first = NULL;
    }
    else
    {
        temp = this->first;
        while ((temp->next->next != NULL))
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
// Function    : Display
// Description : Display linked list
//
//////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T> :: Display()
{
    struct SinglyLLLnode<T>*temp = NULL;
    temp = this->first ;
    while(temp != NULL)          
    {
        cout<<"| "<<temp->data<<" |->";
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

int SinglyLLL<T> :: Count()
{
    return this->iCount;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function    : InsertAtPos
// Description : Insert node at given position
//
//////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>

void SinglyLLL<T> :: InsertAtPos(T no , int pos)
{
    struct SinglyLLLnode<T>*temp =NULL;
    struct SinglyLLLnode<T>*newn =NULL;
    
    if(pos < 1 || pos > (this->iCount+1))                 // Validate position                             
    {
        cout<<"Invalid position\n";
        return ;
    }
    
    if(pos == 1)                                          // Insert at beginning
    {
        this->InsertFirst(no);
    }
    else if(pos == (this->iCount+1))                       // Insert at end
    {
        this->InsertLast(no);
    }
    else
    {
        int iCnt = 0;
        newn = new struct SinglyLLLnode<T> ;
        newn->data = no;
        newn->next = NULL;

        temp = this->first;
        for(iCnt = 1 ; iCnt < pos -1 ; iCnt++)
        {
            temp = temp-> next;
        }

        newn->next = temp->next;
        temp->next = newn;
        this->iCount++;
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function     : DeleteAtPos
// Description  : Delete node from given position
//
//////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>

void SinglyLLL<T> :: DeleteAtPos(int pos)
{
    struct SinglyLLLnode<T>*temp =NULL;
    struct SinglyLLLnode<T>*target =NULL;

    if(pos < 1 || pos > (this->iCount))                             // Validate position
    {
        cout<<"Invalid position\n";
        return ;
    }
    
    if(pos == 1)                                                   // Delete first node
    {
        this->DeleteFirst();
    }
    else if(pos == (this->iCount))                                // Delete last node     
    {
        this->DeleteLast();
    }
    else
    {
        int iCnt = 0;
        temp = this->first;
        for(iCnt = 1 ; iCnt < pos -1 ; iCnt++)
        {
            temp = temp-> next;
        }
        target = temp ->next ;
        temp->next = target->next;
        delete target;

        this->iCount--;
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Entry Point Function
//
//////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    SinglyLLL<int> obj;
    int iRet = 0;

    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(31);
    obj.Display();
    iRet = obj.Count();
    cout<<"numbers of nodes are : "<<iRet<<"\n";

    obj.InsertLast(101);
    obj.InsertLast(111);
    obj.InsertLast(121);
    obj.Display();
    iRet = obj.Count();
    cout<<"numbers of nodes are : "<<iRet<<"\n";

    obj.DeleteFirst();
    obj.Display();
    iRet = obj.Count();
    cout<<"numbers of nodes are : "<<iRet<<"\n";
    
    obj.DeleteLast();
    obj.Display();
    iRet = obj.Count();
    cout<<"numbers of nodes are : "<<iRet<<"\n";

    obj.InsertAtPos(105,3);
    obj.Display();
    iRet = obj.Count();
    cout<<"numbers of nodes are : "<<iRet<<"\n";

    obj.DeleteAtPos(3);
    obj.Display();
    iRet = obj.Count();
    cout<<"numbers of nodes are : "<<iRet<<"\n";



    return 0 ;

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