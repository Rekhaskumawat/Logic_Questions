//////////////////////////////////////////////////////////////////////////////////////////////
//
//required header file
//
//////////////////////////////////////////////////////////////////////////////////////////////

import java.util.Scanner;

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Class Name :    Logic
//  Function Name : Prime
//  Description :   check weather number is prime or not
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

    public boolean Prime()
    {
        int iCnt = 0;
        int itemp = 0;
        
        for(iCnt = 2 ; iCnt < iNo; iCnt++)
        {
           if(iNo % iCnt == 0)
           {
            return false;
           }  
        }
        return true;
    }
    
}//end of the Logic class

//////////////////////////////////////////////////////////////////////////////////////////////
//
//Entery point class
//
//////////////////////////////////////////////////////////////////////////////////////////////

class Prime
{
    public static void main(String Arr[])
        {
            int iValue= 0 ;
            
            boolean bRet= false;

            Scanner sobj = new Scanner(System.in);
        
            System.out.println("Enter first number:");
            iValue = sobj.nextInt();

            Logic lobj = new Logic(iValue);
            bRet = lobj.Prime();

            if(bRet == true)
            {
            System.out.println(iValue+ " is prime number");
            }
            else
            {
                System.out.println(iValue+ " is not prime number");
            }
        }

}//end of main class

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Input1:12                  Output:12 is not prime number
//  Input1:15                  Output:15 is prime number
//
//////////////////////////////////////////////////////////////////////////////////////////////