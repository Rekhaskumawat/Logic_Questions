//////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Required header files
//
//////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>

//////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Structure for a node of singly linked list
//
//////////////////////////////////////////////////////////////////////////////////////////////////

struct node
{
    int data ; 
    struct node*next;
};

typedef struct node NODE;
typedef struct node* PNODE ;
typedef struct node** PPNODE;

//////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Description : implementation of Singly Linear Linked List
// Function     : InsertFirst
// Description  : Insert node at beginning
//  Author      : Rekha Kumawat
//  Date        : 25/12/2025
//
//////////////////////////////////////////////////////////////////////////////////////////////////

void InsertFirst(PPNODE first , int iNo)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data= iNo ;
    newn->next =  NULL;

    if((*first) == NULL)
    {
        (*first) = newn;
    }
    else
    {
        newn->next = (*first);
        (*first) = newn;
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function    : InsertLast
//  Description : Insert node at end
//
//////////////////////////////////////////////////////////////////////////////////////////////////

void InsertLast(PPNODE first , int iNo)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data= iNo ;
    newn->next =  NULL;

    if((*first) == NULL)
    {
        (*first) = newn;
    }
    else
    {
        temp = (*first);

        while ((temp->next) != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn; 
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function    : DeleteFirst
// Description : Delete first node
//
//////////////////////////////////////////////////////////////////////////////////////////////////

void DeleteFirst(PPNODE first)
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
        *first = (*first)->next ;
        free(temp);
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
    PNODE temp =NULL ;

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
        temp = *first ;

        while ((temp->next->next) != NULL)
        {
            temp = temp->next ;
        }

        free(temp->next);
        temp->next = NULL;
        
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
    while (first != NULL)
    {
        printf("| %d | -> ", first->data);

        first = first->next;   
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
        iCount++;
        first = first->next;   
    }

    return iCount ;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function    : InsertAtPos
// Description : Insert node at given position
//
//////////////////////////////////////////////////////////////////////////////////////////////////

void InsertAtPos(PPNODE first , int iNo , int pos)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    int iSize = 0;
    iSize = Count(*first);

    if(pos < 1 || pos > (iSize+1))   // filter invalid position
    {
        printf("Invalid position\n");
        return ;
    }
    if(pos == 1)
    {
        InsertFirst(first , iNo);
    }
    else if(pos == iSize+1 )
    {
        InsertLast(first , iNo);
    }
    else
    {
        int iCnt = 0;

        newn = (PNODE)malloc(sizeof(NODE));

        temp = *first ;
        newn->data = iNo;
        newn->next = NULL;

        for(iCnt = 1 ; iCnt < pos-1 ; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;
    }

}

//////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function     : DeleteAtPos
// Description  : Delete node from given position
//
//////////////////////////////////////////////////////////////////////////////////////////////////

void DeleteAtPos(PPNODE first ,int pos)
{
    PNODE temp = NULL;
    PNODE target = NULL;

    int iSize = 0;
    iSize = Count(*first);

    if(pos < 1 || pos > iSize)            // filter invalid position
    {
        printf("Invalid position\n");
        return ;
    }
    if(pos == 1)
    {
        DeleteFirst(first);
    }
    else if(pos == iSize)
    {
        DeleteLast(first );
    }
    else
    {
        temp = *first;

        int iCnt = 0;

        for(iCnt = 1 ; iCnt < pos-1 ; iCnt++)
        {
            temp = temp -> next;
        }
        target = temp -> next ;

        temp-> next =  target->next;
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
    int iRet = 0 ;

    InsertFirst(&head , 51);
    InsertFirst(&head , 21);
    InsertFirst(&head , 11);
    Display(head);
    iRet = Count(head);
    printf("Number of node are : %d\n", iRet);

    InsertLast(&head , 101);
    InsertLast(&head , 111);
    InsertLast(&head , 121);
    Display(head);
    iRet = Count(head);
    printf("Number of node are : %d\n", iRet);

    DeleteFirst(&head);
    Display(head);
    iRet = Count(head);
    printf("Number of node are : %d\n", iRet);

    DeleteLast(&head);
    Display(head);
    iRet = Count(head);
    printf("Number of node are : %d\n", iRet);

    InsertAtPos(&head , 105, 3);
    Display(head);
    iRet = Count(head);
    printf("Number of node are : %d\n", iRet);

    DeleteAtPos(&head , 3);
    Display(head);
    iRet = Count(head);
    printf("Number of node are : %d\n", iRet);

    return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//
//    | 11 | ->| 21 | ->| 51 | ->NULL
//    Number of nodes linked list have :3
//    | 11 | ->| 21 | ->| 51 | ->| 101 | ->| 111 | ->| 121 | ->NULL
//    Number of nodes linked list have :6
//   | 21 | ->| 51 | ->| 101 | ->| 111 | ->| 121 | ->NULL
//    Number of nodes linked list have :5
//    | 21 | ->| 51 | ->| 101 | ->| 111 | ->NULL
//    Number of nodes linked list have :4
//    | 21 | ->| 51 | ->| 105 | ->| 101 | ->| 111 | ->NULL
//    Number of nodes linked list have :5
//    | 21 | ->| 51 | ->| 101 | ->| 111 | ->NULL
//    Number of nodes linked list have :4
//
//////////////////////////////////////////////////////////////////////////////////////////////////