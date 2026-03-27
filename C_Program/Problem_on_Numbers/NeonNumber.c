//////////////////////////////////////////////////////////////////////////////////////////////
//
//required header file
//
//////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdbool.h>

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : NeonNumber()
//  Description :   Check wheather the number is Neon Number or Not
//  Input :         Integer
//  output :        bool
//  Author :        Rekha Shankarlal Kumawat
//  Date :          22/03/2026
//
//////////////////////////////////////////////////////////////////////////////////////////////


bool NeonNumber(int iNo)
{
    int iCount = 0 ;
    int iDigit = 0 ;
    int iTemp = 0  ;
    int iSum = 0 ;

    iTemp = iNo ;

    iNo = iNo * iNo;

    while (iNo != 0) 
    {
        iDigit = iNo % 10;
        iSum = iSum+iDigit ;
        iNo = iNo / 10;
    }

    return iSum == iTemp;
} 

int main()
{
    int iValue = 0;
    bool bRet = false ;

    printf("Enter the Number :- ");
    scanf("%d" , &iValue);
    
    bRet =  NeonNumber(iValue);

    if(bRet == true)
    {
        printf("%d is a Neon Number\n", iValue);
    }
    else
    {
        printf("%d is not a Neon Number\n", iValue);
    }

    return 0 ;
}