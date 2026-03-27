//////////////////////////////////////////////////////////////////////////////////////////////
//
//required header file
//
//////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdbool.h>

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : ArmstrongNumber()
//  Description :   Check wheather the number is ArmStrong Number or Not
//  Input :         Integer
//  output :        bool
//  Author :        Rekha Shankarlal Kumawat
//  Date :          22/03/2026
//
//////////////////////////////////////////////////////////////////////////////////////////////

bool ArmstrongNumber(int iNo)
{
        int iCount = 0 ;
        int iDigit = 0 ;
        int iPow = 0 ;
        int iTemp = 0 ;
        int iSum = 0 ;
        int iCountTemp =0 ;
        
        iTemp = iNo;

        while(iNo != 0)
        {
            iDigit = iNo % 10;               
            iCount++;
            iNo = iNo / 10;
        }

        
        iNo = iTemp ;
        iCountTemp = iCount ;

        while (iNo != 0) 
        {
            iDigit = iNo % 10;
            iCount= iCountTemp;
            iPow =1 ;

            while(iCount!= 0)
            {
                iPow = iPow*iDigit;
                iCount--;
            }

            iSum =iSum +iPow ;
            iNo = iNo / 10;
            
        }

        return iSum == iTemp;
}

//////////////////////////////////////////////////////////////////////////////////////////////
//
//Entry point function
//
//////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    int iValue = 0;
    bool iRet = false;

    printf("Enter the Numner : ");
    scanf("%d" , & iValue);

    iRet = ArmstrongNumber(iValue);

    if(iRet == true)
    {
        printf("%d is a ArmStrong Number " , iValue);
    }
    else
    {
        printf("%d is not a ArmStrong Number " , iValue);
    }
    return 0;

}