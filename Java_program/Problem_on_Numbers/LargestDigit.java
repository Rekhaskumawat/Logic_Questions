//////////////////////////////////////////////////////////////////////////////////////////////
//
//required header file
//
//////////////////////////////////////////////////////////////////////////////////////////////

import java.util.Scanner;

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Class Name  :   Logic
//  Function Name : largestDigit
//  Description :   find largest digit among given number
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

    public int largestDigit()
    {
        int ilargest = 0 ;
        int iDigit = 0 ;
        while(iNo != 0 )
        {
            iDigit = iNo % 10 ;
            iNo = iNo /10 ;
           if(ilargest <= iDigit)
           {
             ilargest = iDigit ;
           }
        }
       return ilargest;
    }
}// end of Logic Class

//////////////////////////////////////////////////////////////////////////////////////////////
//
//Entry point class
//
//////////////////////////////////////////////////////////////////////////////////////////////

class LargestDigit
{
    public static void main(String Arr [])
    {
        Scanner sobj = new Scanner(System.in);
        int iRet = 0 ;
        int iValue = 0 ;
        System.out.println("Enter the number:");
        iValue = sobj.nextInt();

        Logic lobj = new Logic(iValue);
        iRet = lobj.largestDigit();

        System.out.println("Largest digit is : "+iRet);

    }
}//end of main function

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Input1:12549                       Output:Largest digit is : 9
//  Input1:004352                      Output:Largest digit is : 5
//
//////////////////////////////////////////////////////////////////////////////////////////////