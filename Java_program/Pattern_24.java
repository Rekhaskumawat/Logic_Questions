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
//  Date :          19/12/2025
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

    if(iRow != icol)
    {
        System.out.println("Invalid input");
        System.out.println("Row number and column number should be same");
        return;
    }
    for(iCnt1 = 1 ; iCnt1 <= iRow ; iCnt1++)
    {
        for(iCnt2 = 1; iCnt2 <= icol ; iCnt2++)
        {
            if(iCnt2 < iCnt1)
            {
                System.out.print("\t");
            } 
            else
            {
                System.out.print(iCnt2+"\t");
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

class Pattern_24
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