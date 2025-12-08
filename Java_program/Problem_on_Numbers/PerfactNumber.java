//////////////////////////////////////////////////////////////////////////////////////////////
//
//required header file
//
//////////////////////////////////////////////////////////////////////////////////////////////

import java.util.Scanner;

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Class Name :    Logic
//  Function Name : PerfactNumber
//  Description :   Returns the perfact number
//  Input :         Integer
//  output :        Integer
//  Author :        Rekha Shankarlal Kumawat
//  Date :          03/12/2025
//
//////////////////////////////////////////////////////////////////////////////////////////////

class Logic
{
    int iNo ;
    
    public Logic(int iNo)
    {
        this.iNo = iNo;
    }

    int PerfactNumber()
    {
        int iCnt = 0;
        int iSum = 0 ;

        for(iCnt = 1 ; iCnt < iNo ; iCnt++)
        {
            if((iNo % iCnt) == 0 )
            {
                iSum = iSum + iCnt ;
            }
        }
        return iSum ;
    }
    
}//end of the Logic class

//////////////////////////////////////////////////////////////////////////////////////////////
//
//Entery point class
//
//////////////////////////////////////////////////////////////////////////////////////////////

class PerfactNumber
{
    public static void main(String Arr[])
        {
            int iValue = 0 ;
            int iRet = 0;

            Scanner sobj = new Scanner(System.in);
        
            System.out.println("Enter first number:");
            iValue = sobj.nextInt();

            Logic lobj = new Logic(iValue);
            iRet = lobj.PerfactNumber();

            if(iRet == iValue)
            {
                System.out.println(iValue+ " is perfect number ");
            }
            else
            {
                System.out.println(iValue+ " is not perfect number ");
            }
            
        
        }

}//end of main class

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Input1:6                   Output:6 is perfect number
//  Input1:23                  Output:23 is not perfect number
//

//////////////////////////////////////////////////////////////////////////////////////////////
