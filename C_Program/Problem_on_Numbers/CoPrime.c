//////////////////////////////////////////////////////////////////////////////////////////////
//
//required header file
//
//////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdbool.h>

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : coPrime
//  Description :   check weather two number are co-prime or not
//  Input :         Integer , Integer
//  output :        Boolean
//  Author :        Rekha Shankarlal Kumawat
//  Date :          09/12/2025
//
//////////////////////////////////////////////////////////////////////////////////////////////


bool coPrime(int iNo1 , int iNo2)
{
    int iCnt = 0;
    int itemp = 0;
    int iCount = 0 ;
    if(iNo1 > iNo2)
    {
        itemp = iNo1;
        iNo1 = iNo2;
        iNo2 = itemp ;
    }
    
    for(iCnt = 1 ; iCnt <= iNo2 ; iCnt++)
    {
        if((iNo1 % iCnt) == 0 && (iNo2 % iCnt) == 0)
        {
            iCount++;
        }
    }
    if(iCount == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}//end of the coPrime function

//////////////////////////////////////////////////////////////////////////////////////////////
//
//Entery point function
//
//////////////////////////////////////////////////////////////////////////////////////////////

int main()
{

    int iValue1 = 0 ;
    int iValue2 = 0 ;
    bool bRet= false;

    printf("Enter first number :\n");
    scanf("%d", &iValue1);

    printf("Enter Second number :\n");
    scanf("%d", &iValue2);

    bRet = coPrime(iValue1 , iValue2);

    if(bRet == true)
    {
        printf("%d and %d are co prime number\n", iValue1,iValue2);
    }
    else
    {
        printf("%d and %d are not co prime number\n", iValue1,iValue2);
    }

    return 0 ;
}//end of main function

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Input1:12            Input2:2           Output:12 and 2 are not co prime number
//  Input1:8             Input2:15          Output:8 and 15 are co prime number
//
//////////////////////////////////////////////////////////////////////////////////////////////