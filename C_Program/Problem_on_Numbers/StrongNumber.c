//////////////////////////////////////////////////////////////////////////////////////////////
//
//required header file
//
//////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdbool.h>

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : StrongNumber()
//  Description :   Check wheather the number is Strong Number or Not
//  Input :         Integer
//  output :        bool
//  Author :        Rekha Shankarlal Kumawat
//  Date :          22/03/2026
//
//////////////////////////////////////////////////////////////////////////////////////////////


bool StrongNumber(int iNo)
{
    int iDigit = 0 ;
    int iSum = 0 ;
    int iFact = 0;
    int iTemp = iNo ;
    int factArr[] ={1,1,2,6,24,120,720,5040,40320 ,362880 };

    while(iNo != 0)
    {
        iDigit = iNo % 10 ;

        iSum = iSum + factArr[iDigit] ;

        iNo =  iNo / 10 ;

    }
    return iTemp == iSum ;
}

int main()
{
    int iValue = 0;
    bool iRet = false ;

    printf("Enter a Number :- ");
    scanf("%d" , &iValue);

    iRet = StrongNumber(iValue);

    if(iRet == true)
    {
        printf("%d is a Strong Number " , iValue);
    }
    else
    {
        printf("%d is not a Strong Number " , iValue);
    }
    return 0;
}