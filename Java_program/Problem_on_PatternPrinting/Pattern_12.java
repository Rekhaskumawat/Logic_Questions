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
        char ch = '\0';

        for(iCnt1 = 1 ; iCnt1 <= iRow ; iCnt1++ )
        {
            for(iCnt2 = 1 , ch = 'A' ; iCnt2 <= icol ; iCnt2++ , ch++)
            {
                if(iCnt1%2 == 0)
                {
                    System.out.print(ch+ "\t");
                }
                else
                {
                    System.out.print((char)(ch+32)+ "\t");
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

class Pattern_12
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
//  Input1:4          Input2:4                      Output: a       b       c       d
//                                                          A       B       C       D
//                                                          a       b       c       d
//                                                          A       B       C       D
//
//  Input1:3          Input2:3                       Output: a       b       c       
//                                                           A       B       C       
//                                                           a       b       c       
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////