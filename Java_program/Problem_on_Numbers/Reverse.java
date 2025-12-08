//////////////////////////////////////////////////////////////////////////////////////////////
//
//required header file
//
//////////////////////////////////////////////////////////////////////////////////////////////

import java.util.Scanner;

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Class Name  :   Logic
//  Function Name : Reverse
//  Description :   reverse the number
//  Input :         Integer
//  output :        void
//  Author :        Rekha Shankarlal Kumawat
//  Date :          08/12/2025
//
//////////////////////////////////////////////////////////////////////////////////////////////

class Logic
{
    int iNo ;
    public Logic(int iNo)
    {
        this.iNo = iNo;
    }

    public void reverse()
    {
        int iDigit = 0 ;
        int iRev = 0 ;
        while(iNo != 0 )
        {
            iDigit = iNo % 10 ;
            iNo = iNo /10 ;
            iRev = iRev*10 + iDigit;
        }
       System.out.print("Reversed Number : "+iRev);;
    }
}// end of Logic Class

//////////////////////////////////////////////////////////////////////////////////////////////
//
//Entry point class
//
//////////////////////////////////////////////////////////////////////////////////////////////

class Reverse
{
    public static void main(String Arr [])
    {
        Scanner sobj = new Scanner(System.in);

        int iValue = 0 ;
        System.out.println("Enter the number:");
        iValue = sobj.nextInt();

        Logic lobj = new Logic(iValue);
        lobj.reverse();

    }
}//end of main function

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Input1:21                        Output:Reversed Number : 12
//  Input1:43233434                  Output:Reversed Number : 43433234
//
//////////////////////////////////////////////////////////////////////////////////////////////