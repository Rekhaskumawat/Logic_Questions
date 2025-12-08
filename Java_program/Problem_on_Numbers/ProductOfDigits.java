//////////////////////////////////////////////////////////////////////////////////////////////
//
//required header file
//
//////////////////////////////////////////////////////////////////////////////////////////////

import java.util.Scanner;

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Class Name  :   Logic
//  Function Name : productOfDigits
//  Description :   return sum of Digits
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

    public int productOfDigits()
    {
        int iDigit = 0 ;
        int iProd = 1 ;
        while(iNo != 0 )
        {
            iDigit = iNo % 10 ;
            iNo = iNo /10 ;
            iProd = iProd*iDigit;
        }
       return iProd ;
    }
}// end of Logic Class

//////////////////////////////////////////////////////////////////////////////////////////////
//
//Entry point class
//
//////////////////////////////////////////////////////////////////////////////////////////////

class ProductOfDigits
{
    public static void main(String Arr [])
    {
        Scanner sobj = new Scanner(System.in);
        int iRet = 0 ;
        int iValue = 0 ;
        System.out.println("Enter the number:");
        iValue = sobj.nextInt();

        Logic lobj = new Logic(iValue);
        iRet = lobj.productOfDigits();

        System.out.println("Product of Digits of number is :"+iRet);
    }
}//end of main function

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Input1:21                        Output:Product of Digits of number is :2
//  Input1:43233434                  Output:Product of Digits of number is :10368
//
//////////////////////////////////////////////////////////////////////////////////////////////