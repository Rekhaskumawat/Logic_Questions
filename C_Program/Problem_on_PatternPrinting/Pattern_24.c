///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//required header file
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>                                              // for input output

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : Display
//  Description :   Display the pattern of character
//  Input :         Integer
//  output :        Void
//  Author :        Rekha Shankarlal Kumawat
//  Date :          19/12/2025
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Display(int iRow , int iCol)
{
    int iCnt1 = 0 ;
    int iCnt2 = 0 ;
    if(iRow != iCol)
        {
            printf("Invalid input");
            printf("Row number and column number should be same");
            return;
        }
    for(iCnt1 = 1 ; iCnt1 <= iRow ; iCnt1++)
    {
        for(iCnt2 = 1; iCnt2 <= iCol ; iCnt2++)
        {
            if(iCnt2 < iCnt1)
            {
                printf("\t");
            } 
            else
            {
                printf("%d\t", iCnt2);
            }
        }
        printf("\n");
    }
}//end of the Display function

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//Entery point function
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    int iValue1 = 0 ;
    int iValue2 = 0 ;

    printf("Enter the number of rows:");
    scanf("%d", &iValue1);

    printf("Enter the number of columns:");
    scanf("%d", &iValue2);

    Display(iValue1 , iValue2);

    return 0 ;
}//end of main function

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Input1:4    Input2:4   Output:1       2       3       4
//                                        2       3       4
//                                                3       4
//                                                        4
//
//  Input1:3    Input2:3   Output:1       2       3
//                                        2       3
//                                                3
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////