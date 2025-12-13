//////////////////////////////////////////////////////////////////////////////////////////////
//
//required header file
//
//////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include <math.h>                        // for exponent use

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : armstrong
//  Description :   checks armstrong number
//  Input :         Integer
//  output :        Integer
//  Author :        Rekha Shankarlal Kumawat
//  Date :          10/12/2025
//
//////////////////////////////////////////////////////////////////////////////////////////////

int armstrong(int iNo)
{
    int iDigit = 0 ;
    int iSum = 0 ;
    int iCount = 0 ;
    int iTemp = iNo ;

    while(iNo != 0 )
    {
        iDigit = iNo % 10 ;
        iNo = iNo /10 ;
        iCount++;
    }

    while(iTemp != 0 )
    {
        iDigit = iTemp % 10 ;
        iTemp = iTemp /10 ;
        iSum = iSum + pow(iDigit,iCount);
    }

    return iSum ;
    
}// end of armstrong function

//////////////////////////////////////////////////////////////////////////////////////////////
//
//Entry point function
//
//////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    
    int iRet = 0 ;
    int iValue = 0 ;
    printf("Enter the number:");
    scanf("%d",&iValue);

    armstrong(iValue);

    if(iRet == iValue)
    {
        printf( "%d is an armstrong number",iValue);
    }
    else
    {
        printf( "%d is not an armstrong number",iValue);
    }

}//end of main function

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Input1:153                        Output:153 is an armstrong number
//  Input1:123                        Output:123 is not an armstrong number
//
//////////////////////////////////////////////////////////////////////////////////////////////