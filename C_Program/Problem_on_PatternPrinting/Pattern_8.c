//////////////////////////////////////////////////////////////////////////////////////////////
//
//required header file
//
//////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : pattern
//  Description :   Display pattern
//  Input :         Integer 
//  output :        void
//  Author :        Rekha Shankarlal Kumawat
//  Date :          11/12/2025
//
//////////////////////////////////////////////////////////////////////////////////////////////

void pattern(int iRow , int icol)
{
    int iCnt1 = 0 ;
    int iCnt2 = 0 ;

    for(iCnt1 = 1 ; iCnt1 <= iRow ; iCnt1++ )
    {
        for(iCnt2 = icol ; iCnt2 >= 1 ; iCnt2--)
        {
            printf("%d\t",iCnt2);
        }
        printf("\n");
    }
    }//end of Pattern function

//////////////////////////////////////////////////////////////////////////////////////////////
//
//Entry point function
//
//////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    int iValue1 = 0 ;
    int iValue2 = 0 ;

    printf("Enter the Number of Rows:\n");
    scanf("%d", &iValue1);

    printf("Enter the Number of Columns:\n");
    scanf("%d", &iValue2);
    
    pattern(iValue1 , iValue2);

}// end of main function

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Input1:4          Input2:4                       Output: 4       3       2       1
//                                                           4       3       2       1
//                                                           4       3       2       1
//                                                           4       3       2       1
//
//  Input1:3          Input2:3                       Output: 3       2       1
//                                                           3       2       1
//                                                           3       2       1
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////