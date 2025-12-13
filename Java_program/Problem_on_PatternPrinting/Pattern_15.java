//////////////////////////////////////////////////////////////////////////////////////////////
//
//required header file
//
//////////////////////////////////////////////////////////////////////////////////////////////

import java.util.Scanner;

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Class Name :    Pattern
//  Function Name : pattern
//  Description :   Display pattern
//  Input :         Integer 
//  output :        void
//  Author :        Rekha Shankarlal Kumawat
//  Date :          11/12/2025
//
//////////////////////////////////////////////////////////////////////////////////////////////

class Pattern
{
    int iRow ;
    int icol ;

    public Pattern(int iNo1 , int iNo2)
    {
        this.iRow = iNo1 ;
        this.icol = iNo2 ;
    }


    public void pattern()
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
                   System.out.print((iCnt2*2)+ "\t");
                }
                else
                {
                    System.out.print((iOdd)+ "\t");
                    iOdd+=2 ;
                }
                
                
            }
            System.out.print("\n");
        }
    }
}//end of Pattern class

//////////////////////////////////////////////////////////////////////////////////////////////
//
//Entery point class
//
//////////////////////////////////////////////////////////////////////////////////////////////

class Pattern_15
{
    public static void main(String A[])
    {
        int iValue1 = 0 ;
        int iValue2 = 0 ;

        Scanner sobj = new Scanner(System.in);

        System.out.println("Enter the number of Rows:");
        iValue1 = sobj.nextInt();

        System.out.println("Enter the number of Columns:");
        iValue2 = sobj.nextInt();

        Pattern pobj = new Pattern(iValue1 , iValue2);
        pobj.pattern();
    }
}// end of main class

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