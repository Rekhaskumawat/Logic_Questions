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
//  Description : implementation of Doubly circular Linked List
//  Author      : Rekha Kumawat
//  Date        : 25/12/2025
// Function     : InsertFirst
// Description  : Insert node at beginning
//
//////////////////////////////////////////////////////////////////////////////////////////////////

void InsertFirst(PPNODE first , PPNODE last , int no)
{
    PNODE newn = NULL ;
    newn= (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next =NULL;
    newn->prev= NULL;

    if(*first == NULL && *last == NULL)            // Linked list is empty
    {
        *first = newn ;
        *last = newn;
    }
    else                                          // linked contain one or more node
    {
        newn->next = *first;
        (*first)->prev = newn ;
        *first = newn;
    }
    (*last)->next = *first;
    (*first)->prev = *last ;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function    : InsertLast
//  Description : Insert node at end
//
//////////////////////////////////////////////////////////////////////////////////////////////////

void InsertLast(PPNODE first , PPNODE last , int no)
{
    PNODE newn = NULL ;
    newn= (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next =NULL;
    newn->prev= NULL;

    if(*first == NULL && *last == NULL)             // Linked list is empty
    {
        *first = newn ;
        *last = newn;
    }
    else                                            // linked contain one or more node
    {
        (*last)->next = newn ;
        newn->prev = *last;
        *last = newn;
    }
    (*last)->next = *first;
    (*first)->prev = *last ;
}
//////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function    : DeleteFirst
// Description : Delete first node
//
//////////////////////////////////////////////////////////////////////////////////////////////////

void DeleteFirst(PPNODE first , PPNODE last)
{
    if(*first == NULL && *last == NULL) 
    {
        printf("Empty list");
        return;
    }
    else if(*first == *last)                              // LL contains one node
    {
        free(*first);
        *first =NULL;
        *last = NULL ;
    }
    else
    {
        *first = (*first)->next ;
        free((*first)->prev);
        (*last)->next = *first;
        (*first)->prev = *last;
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function    : DeleteLast
// Description : Delete last node
//
//////////////////////////////////////////////////////////////////////////////////////////////////

void DeleteLast(PPNODE first , PPNODE last)
{
    if(*first == NULL && *last == NULL)
    {
        printf("Empty list");
        return;
    }
    else if(*first == *last)
    {
        free(*first);
        *first =NULL;
        *last = NULL ;
    }
    else
    {
        
        *last = (*last)->prev;
        free((*last)->next);
        (*last)->next = *first;
        (*first)->prev = *last;

    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function    : Display
// Description : Display linked list
//
//////////////////////////////////////////////////////////////////////////////////////////////////

void Display(PNODE first , PNODE last)
{
    
    if(first == NULL  && last == NULL)                      // linked list is empty
    {
        printf("linked list is empty\n");
        return ;
    }
    printf("<=>");
    do
    {
        printf("| %d | <=> ",first->data);
        first = first->next ;

    } while (first != last->next);
    printf("\n");
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function     : Count
//  Description  : Return number of nodes
//
//////////////////////////////////////////////////////////////////////////////////////////////////

int Count(PNODE first , PNODE last)
{
    
    if(first == NULL && last == NULL)                  // linked list is empty
    {
        return 0 ;
    }
    int iCount = 0;
    do
    {
        iCount++;
        first = first->next ;

    } while (first != last->next);

    return iCount;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function    : InsertAtPos
// Description : Insert node at given position
//
//////////////////////////////////////////////////////////////////////////////////////////////////

void InsertAtPos(PPNODE first , PPNODE last , int no , int pos)
{
    int iSize = 0;
    PNODE temp =NULL ;
    PNODE newn =NULL;

    iSize = Count(*first ,*last);

    if((pos < 1) || (pos > (iSize +1)))
    {
        printf("invalid position\n");
        return ;
    }

    if (pos == 1)
    {
        InsertFirst(first , last ,no);
    }
    else if(pos == iSize+1)
    {
        InsertLast(first, last , no);
    }
    else
    {
        newn = (PNODE)malloc(sizeof(NODE));

        newn->data= no ;
        newn->next=NULL;
        newn->prev=NULL;

        int iCnt = 0;
        temp = *first;
        for(iCnt = 1 ; iCnt < pos-1 ; iCnt++)
        {
            temp= temp->next;
        }
        newn->next =temp->next;
        temp->next->prev = newn ;
        temp->next = newn;
        newn->prev = temp ;
    }
    
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function     : DeleteAtPos
// Description  : Delete node from given position
//
//////////////////////////////////////////////////////////////////////////////////////////////////

void DeleteAtPos(PPNODE first , PPNODE last , int pos)
{
    int iSize = 0;
    PNODE temp =NULL ;

    iSize = Count(*first ,*last);

    if((pos < 1) || (pos > (iSize)))
    {
        printf("invalid position\n");
        return ;
    }

    if (pos == 1)
    {
        DeleteFirst(first , last);
    }
    else if(pos == iSize)
    {
        DeleteLast(first, last );
    }
    else
    {
        int iCnt = 0;
        temp = *first;
        for(iCnt = 1 ; iCnt < pos-1 ; iCnt++)
        {
            temp= temp->next;
        }
        temp->next = temp ->next->next;
        free(temp->next->prev);
        temp->next->prev= temp;
    }
        
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Entry Point Function
//
//////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    PNODE head = NULL;
    PNODE tail = NULL ;                             
    int iRet = 0 ;

    InsertFirst(&head , &tail , 51);
    InsertFirst(&head , &tail , 21);
    InsertFirst(&head , &tail , 11);
    Display(head , tail);
    iRet = Count(head , tail);
    printf("Number of nodes : %d\n", iRet);

    InsertLast(&head , &tail , 101);
    InsertLast(&head , &tail , 111);
    InsertLast(&head , &tail , 121);
    Display(head , tail);
    iRet = Count(head , tail);
    printf("Number of nodes : %d\n", iRet);

    DeleteFirst(&head , &tail);
    Display(head , tail);
    iRet = Count(head , tail);
    printf("Number of nodes : %d\n", iRet);

    DeleteLast(&head , &tail);
    Display(head , tail);
    iRet = Count(head , tail);
    printf("Number of nodes : %d\n", iRet);

    InsertAtPos(&head , &tail ,105 , 3);
    Display(head , tail);
    iRet = Count(head , tail);
    printf("Number of nodes : %d\n", iRet);

    DeleteAtPos(&head ,&tail ,  3);
    Display(head , tail);
    iRet = Count(head , tail);
    printf("Number of nodes : %d\n", iRet);

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