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
    int data;
    struct node*next;
};
typedef struct node NODE;
typedef struct node* PNODE ;
typedef struct node** PPNODE;

//////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Class Name  : SinglyCL
//  Description : implementation of Singly Circular Linked List
//  Function    : InsertFirst
//  Description : Insert node at beginning
//  Author      : Rekha Kumawat
//  Date        : 25/12/2025
//
//////////////////////////////////////////////////////////////////////////////////////////////////

void InsertFirst(PPNODE first , PPNODE last , int no)
{
    PNODE newn = NULL;
    
    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no ;
    newn->next = NULL;

    if((*first == NULL) && (*last == NULL))         //@
    {
        *first = newn ;
        *last = newn ;
    }
    else
    {
        newn->next = *first;
        *first = newn ;
    }

    (*last)->next = *first ;                    //@
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function    : InsertLast
//  Description : Insert node at end
//
//////////////////////////////////////////////////////////////////////////////////////////////////

void InsertLast(PPNODE first , PPNODE last , int no)
{
    PNODE newn = NULL;
    
    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no ;
    newn->next = NULL;

    if((*first == NULL) && (*last == NULL))
    {
        *first = newn ;
        *last = newn ;
    }
    else
    {
        (*last)->next = newn ;                      //@
        *last = newn ;                           //@
    }

    (*last)->next = *first ;                    //@
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function    : DeleteFirst
// Description : Delete first node
//
//////////////////////////////////////////////////////////////////////////////////////////////////

void DeleteFirst(PPNODE first , PPNODE last)
{

    PNODE temp = NULL;

    if((*first == NULL) && (*last == NULL))
    {
        return ;
    }
    else if(*first == *last)
    {
        free(*first);
        *first = NULL ;
        *last = NULL ;
    }
    else
    {
        temp = *first ;

        *first = (*first)->next ;
        free(temp);

        (*last)->next = *first ;
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
    PNODE temp = NULL ;

    if((*first == NULL) && (*last == NULL))
    {
        return ;
    }
    else if(*first == *last)
    {
        free(*first);
        *first = NULL ;
        *last = NULL ;
    }
    
    else
    {
        temp = *first ;

        while(temp->next != *last)
        {
            
            temp = temp->next;
        }
        free(*last);
        *last = temp ;
        
        (*last)->next = *first ;
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
    if(first == NULL)
    {
        printf("List is empty\n");
        return;
    }
    do
    {
        printf("| %d | -> ", first->data);
        first = first ->next;

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
    int iCount = 0 ;
        if(first == NULL)
    {
        printf("List is empty\n");
        return 0;
    }
    do
    {
        iCount++ ;

        first = first ->next;

    } while (first != last->next);

    return iCount ;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function    : InsertAtPos
// Description : Insert node at given position
//
//////////////////////////////////////////////////////////////////////////////////////////////////

void InsertAtPos(PPNODE first , PPNODE last , int no , int pos)
{
    int isize = 0;
    PNODE newn = NULL;

    isize = Count(*first, *last);

    if((pos < 1) || (pos > (isize +1)))
    {
        printf("Invalid input");
        return ;
    }
    if(pos == 1)
    {
        InsertFirst(first , last , no);
    }
    else if( pos == (isize +1))
    {
        InsertLast(first , last , no);
    }
    else
    {
        int iCnt = 0;

        PNODE temp = NULL ;
        newn = (PNODE)malloc((sizeof(NODE)));
        newn->data = no;
        newn->next = NULL ;
        temp = *first ;

        for(iCnt =1 ; iCnt < pos-1 ; iCnt++)
        {
            temp= temp -> next ;
        }

        newn->next = temp ->next ;
        temp->next = newn;
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
    int isize = 0;

    isize = Count(*first, *last);

    if((pos < 1) || (pos > (isize)))
    {
        printf("Invalid input");
        return ;
    }
    if(pos == 1)
    {
        DeleteFirst(first , last );
    }
    else if( pos == (isize))
    {
        DeleteLast(first , last);
    }
    else
    {
        int iCnt = 0;
        PNODE temp = NULL ;
        PNODE target = NULL;

        temp = *first ;
        for(iCnt =1 ; iCnt < pos-1 ; iCnt++)
        {
            temp= temp -> next ;
        }
        target = temp ->next ;
        
        temp->next = target->next;
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
        PNODE head = NULL;
    PNODE tail = NULL ;                             //@
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