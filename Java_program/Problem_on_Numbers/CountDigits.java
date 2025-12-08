//////////////////////////////////////////////////////////////////////////////////////////////
//
//required header file
//
//////////////////////////////////////////////////////////////////////////////////////////////

import java.util.Scanner;

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Class Name  :   Logic
//  Function Name : countDigit
//  Description :   count number of digit in number
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

    public int countDigit()
    {
        int iCount = 0;
        int iDigit = 0 ;
        while(iNo != 0 )
        {
            iDigit = iNo % 10 ;
            iNo = iNo /10 ;
           iCount++;
        }
       return iCount;
    }
}// end of Logic Class

//////////////////////////////////////////////////////////////////////////////////////////////
//
//Entry point class
//
//////////////////////////////////////////////////////////////////////////////////////////////

class CountDigits
{
    public static void main(String Arr [])
    {
        Scanner sobj = new Scanner(System.in);
        int iRet = 0 ;
        int iValue = 0 ;
        System.out.println("Enter the number:");
        iValue = sobj.nextInt();

        Logic lobj = new Logic(iValue);
        iRet = lobj.countDigit();

        System.out.println("Number of digits are : "+iRet);

    }
}//end of main function

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Input1:12549                       Output:Number of digits are :5
//  Input1:004352                      Output:Number of digits are :6
//
//////////////////////////////////////////////////////////////////////////////////////////////