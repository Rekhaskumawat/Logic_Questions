//////////////////////////////////////////////////////////////////////////////////////////////
//
//required header file
//
//////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdbool.h>

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : AutomorphicNumber()
//  Description :   Check wheather the number is Automorphic Number or Not
//  Input :         Integer
//  output :        bool
//  Author :        Rekha Shankarlal Kumawat
//  Date :          22/03/2026
//
//////////////////////////////////////////////////////////////////////////////////////////////

bool AutomorphicNumber(int iNo)
{
    int iCount = 0 ;
    int iTemp = 0 ;
    int iSqr = 0 ;
    int iDeno = 0;
    int iCnt = 0 ;

    iTemp = iNo ;

    while (iNo != 0) 
    {
        iCount++ ;
        iNo = iNo / 10;
        
    }

    iNo = iTemp;
    iSqr = iNo * iNo;
    iDeno = 1 ;
    for(iCnt = 0; iCnt < iCount; iCnt++)
    {
        iDeno = iDeno * 10;
    }

    return((int)(iSqr % iDeno) == iTemp);
    
}

//////////////////////////////////////////////////////////////////////////////////////////////
//
//Entry point function
//
//////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    int iValue = 0;
    bool bRet = false ;

    printf("Enter the Number :- ");
    scanf("%d" , &iValue);
    
    bRet =  AutomorphicNumber(iValue);

    if(bRet == true)
    {
        printf("%d is a Automorphic Number\n", iValue);
    }
    else
    {
        printf("%d is not a Automorphic Number\n", iValue);
    }

    return 0 ;
}