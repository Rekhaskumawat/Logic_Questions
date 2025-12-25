//////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Required header files
//
//////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>

//////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Structure for a node of Doubly linked list
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
typedef struct node** PPNODE;

//////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Description : implementation of Doubly Linear Linked List
// Function     : InsertFirst
// Description  : Insert node at beginning
//  Author      : Rekha Kumawat
//  Date        : 25/12/2025
//
//////////////////////////////////////////////////////////////////////////////////////////////////

void InsertFirst(PPNODE first , int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->next = NULL;
    newn->prev =NULL ;                  
    newn->data = no ;

    if(*first == NULL)
    {
        *first = newn;
    }
    else
    {
        newn->next = *first;
        (*first)->prev = newn ;         
        *first = newn ;

    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function    : InsertLast
//  Description : Insert node at end
//
//////////////////////////////////////////////////////////////////////////////////////////////////

void InsertLast(PPNODE first , int no)
{
    PNODE newn = NULL;
    PNODE temp = NULL ;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->next = NULL;
    newn->prev =NULL ;                  
    newn->data = no ;

    if(*first == NULL)
    {
        *first = newn;
    }
    else
    {
        temp = *first ;
        while((temp->next) != NULL)
        {
            temp = temp->next ;
        }

        temp->next = newn ;
        newn->prev = temp ;                  temp->next->prev = temp ;
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function    : DeleteFirst
// Description : Delete first node
//
//////////////////////////////////////////////////////////////////////////////////////////////////

void DeleteFirst(PPNODE first )
{
    PNODE temp = NULL;

    if(*first == NULL)
    {
        return;
    }
    else if((*first)->next == NULL)
    {
        free(*first);
        *first = NULL ;
    }
    else
    {
        temp = *first;
        *first =(*first)->next;
        free(temp);
        (*first)->prev = NULL ;             

    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function    : DeleteLast
// Description : Delete last node
//
//////////////////////////////////////////////////////////////////////////////////////////////////

void DeleteLast(PPNODE first)
{
    PNODE temp = NULL ;

    if(*first == NULL)
    {
        return;
    }
    else if((*first)->next == NULL)
    {
        free(*first);
        *first = NULL ;
    }
    else
    {
        temp = *first;

        while(temp->next->next != NULL)
        {
            temp = temp->next ;
        }

        free(temp->next);
        temp->next = NULL ;
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function    : Display
// Description : Display linked list
//
//////////////////////////////////////////////////////////////////////////////////////////////////

void Display(PNODE first)
{
    printf("\n NULL <=>");

    while (first != NULL)
    {
        printf("| %d | <=> " , first->data);
        first= first->next ;
    }
    printf("NULL\n");
    
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function     : Count
//  Description  : Return number of nodes
//
//////////////////////////////////////////////////////////////////////////////////////////////////

int Count(PNODE first)
{
    int iCount = 0;
    while (first != NULL)
    {
        iCount++ ;
        first= first->next ;
    }
    return iCount;

}

//////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function    : InsertAtPos
// Description : Insert node at given position
//
//////////////////////////////////////////////////////////////////////////////////////////////////

void InsertAtPos(PPNODE first , int no , int pos)
{
    int iSize = Count(*first);

    PNODE newn = NULL;
    PNODE temp = NULL;

    if(pos < 1 || pos > (iSize+1))
    {
        printf("Invalid position\n");
        return;
    }

    if(pos == 1)
    {
        InsertFirst(first, no);
    }
    else if(pos == iSize + 1)
    {
        InsertLast(first, no);
    }
    else
    {
        newn = (PNODE)malloc(sizeof(NODE));
        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        temp = *first;

        for(int i = 1; i < pos-1; i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        newn->prev = temp;
        temp->next->prev = newn;
        temp->next = newn;
    }
}


//////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function     : DeleteAtPos
// Description  : Delete node from given position
//
//////////////////////////////////////////////////////////////////////////////////////////////////

void DeleteAtPos(PPNODE first , int pos)
{
    int iSize = Count(*first);

    PNODE temp = NULL;
    PNODE target = NULL;

    if(pos < 1 || pos > iSize)
    {
        printf("Invalid position\n");
        return;
    }

    if(pos == 1)
    {
        DeleteFirst(first);
    }
    else if(pos == iSize)
    {
        DeleteLast(first);
    }
    else
    {
        temp = *first;

        for(int i = 1; i < pos-1; i++)
        {
            temp = temp->next;
        }

        target = temp->next;

        temp->next = target->next;
        target->next->prev = temp;

        free(target);
    }
}


//////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Entry Point Function
//
//////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    PNODE head = NULL ;
    int iRet = 0;

    InsertFirst(&head , 51);
    InsertFirst(&head , 21);
    InsertFirst(&head , 11);
    Display(head);
    iRet = Count(head);
    printf("Total number of node : %d", iRet);

    InsertLast(&head , 101);
    InsertLast(&head , 111);
    InsertLast(&head , 121);
    Display(head);
    iRet = Count(head);
    printf("Total number of node : %d", iRet);

    DeleteFirst(&head);
    Display(head);
    iRet = Count(head);
    printf("Total number of node : %d", iRet);

    DeleteLast(&head);
    Display(head);
    iRet = Count(head);
    printf("Total number of node : %d", iRet);

    InsertAtPos(&head , 105 , 2);
    Display(head);
    iRet = Count(head);
    printf("Total number of node : %d", iRet);

    return 0;

}

//////////////////////////////////////////////////////////////////////////////////////////////////
//
//    NULL <=>| 11 | <=>| 21 | <=>| 51 | <=>NULL
//    Number of nodes in linked list:3
//    NULL <=>| 11 | <=>| 21 | <=>| 51 | <=>| 101 | <=>| 111 | <=>| 121 | <=>NULL
//    Number of nodes in linked list:6
//    NULL <=>| 21 | <=>| 51 | <=>| 101 | <=>| 111 | <=>| 121 | <=>NULL
//    Number of nodes in linked list:5
//    NULL <=>| 21 | <=>| 51 | <=>| 101 | <=>| 111 | <=>NULL
//    Number of nodes in linked list:4
//    NULL <=>| 21 | <=>| 51 | <=>| 105 | <=>| 101 | <=>| 111 | <=>NULL
//    Number of nodes in linked list:5
//    NULL <=>| 21 | <=>| 51 | <=>| 101 | <=>| 111 | <=>NULL
//    Number of nodes in linked list:4
//
//////////////////////////////////////////////////////////////////////////////////////////////////