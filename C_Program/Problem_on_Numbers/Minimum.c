//////////////////////////////////////////////////////////////////////////////////////////////
//
//required header file
//
//////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : Minimum
//  Description :   return Minimum number
//  Input :         Integer
//  output :        Integer
//  Author :        Rekha Shankarlal Kumawat
//  Date :          05/12/2025
//
//////////////////////////////////////////////////////////////////////////////////////////////


    
int Minimum(int iNo1 , int iNo2 , int iNo3)
{
    if(iNo1 < iNo2)
    {
        if(iNo1 < iNo3)
        {
            return iNo1;
        }
        else
        {
            return iNo3;
        }
    }
    else if(iNo2 < iNo3)
    {
        return iNo2;
    }
    else
    {
        return iNo3 ;
    }
}
//end of the Minimum function

//////////////////////////////////////////////////////////////////////////////////////////////
//
//Entery point function
//
//////////////////////////////////////////////////////////////////////////////////////////////


int main()
{
    int iValue1 = 0 ;
    int iValue2 = 0 ;
    int iValue3 = 0 ;
    int iRet = 0 ;
    
    printf("enter first number :" );
    scanf("%d", &iValue1);

    printf("enter Second number :" );
    scanf("%d", &iValue2);

    printf("enter third number :" );
    scanf("%d", &iValue3);

    iRet = Minimum(iValue1 , iValue2 , iValue3);

    printf("Minimum number is : %d ",iRet);

    return 0 ;
}//end of main function

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Input1:6      Input2:15       Input3:32         Output:Minimun  numbers :6
//  Input1:23     Input2:43      Input3:54          Output:Minimun  numbers :23
//
//////////////////////////////////////////////////////////////////////////////////////////////