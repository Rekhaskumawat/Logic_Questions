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
        int iOdd = 0 ;

        for(iCnt1 = 1 ; iCnt1 <= iRow ; iCnt1++ )
        {
            for(iCnt2 = 1 , iOdd = 1 ; iCnt2 <= icol ; iCnt2++ )
            {
                if((iCnt1%2)==1)
                {
                   printf("%d\t",(iCnt2*2));
                }
                else
                {
                    printf("%d\t",iOdd);
                    iOdd+=2 ;
                }
                
                
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
//  Input1:4          Input2:4                      Output: 2       4       6       8
//                                                          1       3       5       7
//                                                          2       4       6       8
//                                                          1       3       5       7
//
//  Input1:3          Input2:3                       Output:  2       4       6       8
//                                                            1       3       5       7
//                                                            2       4       6       8
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////