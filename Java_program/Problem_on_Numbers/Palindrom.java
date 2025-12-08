//////////////////////////////////////////////////////////////////////////////////////////////
//
//required header file
//
//////////////////////////////////////////////////////////////////////////////////////////////

import java.util.Scanner;

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Class Name  :   Logic
//  Function Name : palindrom
//  Description :   check number is palindrom or not
//  Input :         Integer
//  output :        Integer
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

    public int palindrom()
    {
        int iDigit = 0 ;
        int iRev = 0 ;
        while(iNo != 0 )
        {
            iDigit = iNo % 10 ;
            iNo = iNo /10 ;
            iRev = iRev*10 + iDigit;
        }
        return iRev;
    }
}// end of Logic Class

//////////////////////////////////////////////////////////////////////////////////////////////
//
//Entry point class
//
//////////////////////////////////////////////////////////////////////////////////////////////

class Palindrom
{
    public static void main(String Arr [])
    {
        Scanner sobj = new Scanner(System.in);
        int iRet = 0 ;
        int iValue = 0 ;
        System.out.println("Enter the number:");
        iValue = sobj.nextInt();

        Logic lobj = new Logic(iValue);
        iRet = lobj.palindrom();

        if(iRet == iValue)
        {
            System.out.println(iValue+" is palindrom number");
        }
        else
        {
             System.out.println(iValue+" is not a palindrom number");
        }

    }
}//end of main function

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Input1:121                  Output:121 is palindrom number
//  Input1:23                   Output:23 is not a palindrom number
//
//////////////////////////////////////////////////////////////////////////////////////////////