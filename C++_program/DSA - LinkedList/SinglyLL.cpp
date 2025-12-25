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
typedef struct node* PNODE;

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
    private:                            
        PNODE first;
        int iCount;

    public:
        SinglyLL();

        void InsertFirst(int no);
        void InsertLast(int no);
        void DeleteFirst();
        void DeleteLast();
        void Display();
        int Count();
        void InsertAtPos(int no , int pos);
        void DeleteAtPos(int pos);
};
 
//////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function    : SinglyLL
// Description : Constructor definition
//
//////////////////////////////////////////////////////////////////////////////////////////////////

SinglyLL :: SinglyLL()
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

void SinglyLL :: InsertFirst(int no)                    
{
    PNODE newn = NULL;
    newn = new NODE;
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

void SinglyLL :: InsertLast(int no)
{
    PNODE newn = NULL;
    newn = new NODE;
    newn->data = no;
    newn->next = NULL;

    PNODE temp = NULL;

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

void SinglyLL :: DeleteFirst()
{
    PNODE temp = NULL;

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

void SinglyLL :: DeleteLast()
{
    PNODE temp =NULL;

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

void SinglyLL :: Display()
{
    PNODE temp = NULL;
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

int SinglyLL :: Count()
{
    return this->iCount;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function    : InsertPos
// Description : Insert node at given position
//
//////////////////////////////////////////////////////////////////////////////////////////////////

void SinglyLL :: InsertAtPos(int no , int pos)
{
    PNODE temp =NULL;
    PNODE newn =NULL;
    
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
        newn = new NODE ;
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

void SinglyLL :: DeleteAtPos(int pos)
{
    PNODE temp =NULL;
    PNODE target =NULL;

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
    SinglyLL obj;
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