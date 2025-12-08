//////////////////////////////////////////////////////////////////////////////////////////////
//
//required header file
//
//////////////////////////////////////////////////////////////////////////////////////////////

import java.util.Scanner;
//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Class Name  :   Logic
//  Function Name : check
//  Description :   check number is even or odd
//  Input :         Integer
//  output :        Boolean
//  Author :        Rekha Shankarlal Kumawat
//  Date :          08/12/2025
//
//////////////////////////////////////////////////////////////////////////////////////////////

class Logic
{
    int iNo ;

    public Logic(int iNo)
    {
        this.iNo = iNo ;
    }

    boolean Check()
    {
        return ((iNo % 2) == 0);
    }
    
}// end of Logic Class

//////////////////////////////////////////////////////////////////////////////////////////////
//
//Entry point class
//
//////////////////////////////////////////////////////////////////////////////////////////////

class EvenOdd
{
    public static void main(String Arr[])
        {
            int iValue = 0 ;
            boolean bRet = false;

            Scanner sobj = new Scanner(System.in);
            

            System.out.println("Enter the number:");
            iValue = sobj.nextInt();

            Logic lobj = new Logic(iValue);
            bRet = lobj.Check();

            if(bRet == true)
            {
                System.out.println(iValue + " is an Even Number");
            }
            else
            {
                System.out.println(iValue + " is an Odd Number ");
            }

        }
}//end of main function

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Input1:12                   Output:12 an Even number
//  Input1:15                   Output:15 an Odd number
//
//////////////////////////////////////////////////////////////////////////////////////////////
