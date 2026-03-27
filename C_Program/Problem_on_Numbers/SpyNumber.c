//////////////////////////////////////////////////////////////////////////////////////////////
//
//required header file
//
//////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdbool.h>

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : SpyNumber()
//  Description :   Check wheather the number is Spy Number or Not
//  Input :         Integer
//  output :        bool
//  Author :        Rekha Shankarlal Kumawat
//  Date :          22/03/2026
//
//////////////////////////////////////////////////////////////////////////////////////////////

bool SpyNumber(int iNo)
{

    int iSum = 0 ;
    int iprod = 0 ;
    int iDigit = 0; 
    int iTemp = 0;
    
    iTemp = iNo ;

    iprod = 1 ;
    while(iNo != 0)
    {
        iDigit = iNo % 10 ;
        iSum = iSum + iDigit;
        iprod = iprod*iDigit;

        iNo = iNo /10 ;
    }
    return iSum == iprod;
    
}
int main()
{
    int iValue = 0;
    bool bRet = false ;

    printf("Enter the Number :- ");
    scanf("%d" , &iValue);
    
    bRet =  SpyNumber(iValue);

    if(bRet == true)
    {
        printf("%d is a Spy Number\n", iValue);
    }
    else
    {
        printf("%d is not a Spy Number\n", iValue);
    }

    return 0 ;
}