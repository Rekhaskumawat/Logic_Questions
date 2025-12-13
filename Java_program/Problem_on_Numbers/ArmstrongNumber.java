//////////////////////////////////////////////////////////////////////////////////////////////
//
//required header file
//
//////////////////////////////////////////////////////////////////////////////////////////////

import java.util.Scanner;                   // for taking input from user
import java.lang.Math;                      //for exponent use

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Class Name  :   Logic
//  Function Name : armstrong
//  Description :   checks armstrong number
//  Input :         Integer
//  output :        Integer
//  Author :        Rekha Shankarlal Kumawat
//  Date :          10/12/2025
//
//////////////////////////////////////////////////////////////////////////////////////////////

class Logic
{
    int iNo ;
    public Logic(int iNo)
    {
        this.iNo = iNo;
    }

    public int armstrong()
    {
        int iDigit = 0 ;
        int iSum = 0 ;
        int iCount = 0 ;
        int iTemp = iNo ;

        while(iNo != 0 )
        {
            
            iDigit = iNo % 10 ;
            iNo = iNo /10 ;
            iCount++;
        }

        while(iTemp != 0 )
        {
            iDigit = iTemp % 10 ;
            iTemp = iTemp /10 ;
            iSum = iSum + (int)Math.pow(iDigit, iCount);
        }
       return iSum ;
    }
}// end of Logic Class

//////////////////////////////////////////////////////////////////////////////////////////////
//
//Entry point class
//
//////////////////////////////////////////////////////////////////////////////////////////////

class ArmstrongNumber
{
    public static void main(String Arr [])
    {
        Scanner sobj = new Scanner(System.in);
        int iRet = 0 ;
        int iValue = 0 ;
        System.out.println("Enter the number:");
        iValue = sobj.nextInt();

        Logic lobj = new Logic(iValue);
        iRet = lobj.armstrong();

        if(iRet == iValue)
        {
            System.out.println(iValue+ " is an armstrong number");
        }
        else
        {
            System.out.println(iValue+ " is not an armstrong number");
        }
    }
}//end of main function

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Input1:153                        Output:153 is an armstrong number
//  Input1:123                        Output:123 is not an armstrong number
//
//////////////////////////////////////////////////////////////////////////////////////////////