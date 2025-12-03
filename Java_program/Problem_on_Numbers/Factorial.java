//////////////////////////////////////////////////////////////////////////////////////////////
//
//required header file
//
//////////////////////////////////////////////////////////////////////////////////////////////

import java.util.Scanner;

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Class Name :    Logic
//  Function Name : Factorial
//  Description :   return the factorial of number
//  Input :         Integer
//  output :        Integer
//  Author :        Rekha Shankarlal Kumawat
//  Date :          03/12/2025
//
//////////////////////////////////////////////////////////////////////////////////////////////

class Logic
{
    int iNo = 0;
    
    public Logic(int iNo)
    {
        this.iNo = iNo;
    }

    int Factorial()
    {
        int iCnt = 0;
        int iFact =1 ;
        for(iCnt = 1 ; iCnt <= iNo ; iCnt++)
        {
            iFact = iFact*iCnt ;
        }
        
        return iFact ;
    }
    
}//end of the Logic class

//////////////////////////////////////////////////////////////////////////////////////////////
//
//Entery point class
//
//////////////////////////////////////////////////////////////////////////////////////////////

class Factorial
{
    public static void main(String Arr[])
        {
            int iValue = 0 ;
            int iRet = 0 ;
            Scanner sobj = new Scanner(System.in);
        
            System.out.println("Enter first number:");
            iValue = sobj.nextInt();

            Logic lobj = new Logic(iValue);
            iRet = lobj.Factorial();

            System.out.println("Factorial of "+iValue+" is:" +iRet );
            
        }

}//end of main class

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Input1:5                   Output:Factorial of 5 is:120
//  Input1:3                   Output:Factorial of 3 is:6
//
//////////////////////////////////////////////////////////////////////////////////////////////