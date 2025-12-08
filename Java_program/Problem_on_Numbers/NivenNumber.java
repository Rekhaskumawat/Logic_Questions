//////////////////////////////////////////////////////////////////////////////////////////////
//
//required header file
//
//////////////////////////////////////////////////////////////////////////////////////////////

import java.util.Scanner;

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Class Name  :   Logic
//  Function Name : nivenNumber
//  Description :   check number is niven number or not
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
        this.iNo = iNo;
    }

    public boolean nivenNumber()
    {
        int iDigit = 0 ;
        int iSum = 0 ;
        int itemp = iNo;
        while(iNo != 0 )
        {
            iDigit = iNo % 10 ;
            iNo = iNo /10 ;
            iSum = iSum + iDigit;
        }
        if((itemp % iSum) == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
        
    }
}// end of Logic Class

//////////////////////////////////////////////////////////////////////////////////////////////
//
//Entry point class
//
//////////////////////////////////////////////////////////////////////////////////////////////

class NivenNumber
{
    public static void main(String Arr [])
    {
        Scanner sobj = new Scanner(System.in);
        boolean bRet = false ;
        int iValue = 0 ;
        System.out.println("Enter the number:");
        iValue = sobj.nextInt();

        Logic lobj = new Logic(iValue);
        bRet = lobj.nivenNumber();

        if(bRet == true)
        {
            System.out.println(iValue +" is Niven number");
        }
        else
        {
             System.out.println(iValue+" is not a Niven number");
        }

    }
}//end of main function

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Input1:12                   Output:12 is Niven number
//  Input1:15                   Output:15 is not Niven number
//
//////////////////////////////////////////////////////////////////////////////////////////////