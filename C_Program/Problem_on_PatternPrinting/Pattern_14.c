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
//  Date :          15/12/2025
//
//////////////////////////////////////////////////////////////////////////////////////////////

void pattern(int iRow , int icol)
{
    int iCnt1 = 0 ;
    int iCnt2 = 0 ;
    int iCount = 0 ;

    for(iCnt1 = 1 , iCount= 1 ; iCnt1 <= iRow ; iCnt1++ )
    {
        for(iCnt2 = 1 ; iCnt2 <= icol ; iCnt2++ , iCount++)
        {
            if(iCount>=10)
            {
                iCount = 1 ;
            }
            printf("%d\t",iCount);
            
        }
        printf("\n");
    }
}//end of pattern function

//////////////////////////////////////////////////////////////////////////////////////////////
//
//Entery point function
//
//////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    int iValue1 = 0 ;
    int iValue2 = 0 ;

    printf("Enter the number of Rows:\n");
    scanf("%d",&iValue1);

    printf("Enter the number of Columns:\n");
    scanf("%d",&iValue2);
    
    pattern(iValue1 , iValue2);

}// end of main function

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Input1:4          Input2:4                      Output: 1       2       3       4
//                                                          5       6       7       8
//                                                          9       1       2       3
//                                                          4       5       6       7
//
//  Input1:3          Input2:3                       Output: 1       2       3
//                                                           4       5       6
//                                                           7       8       9      
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////