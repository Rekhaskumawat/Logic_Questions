//////////////////////////////////////////////////////////////////////////////////////////////
//
//required header file
//
//////////////////////////////////////////////////////////////////////////////////////////////

import java.util.Scanner;

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Class Name :    Logic
//  Function Name : coPrime
//  Description :   check weather two number are co-prime or not
//  Input :         Integer , Integer
//  output :        Boolean
//  Author :        Rekha Shankarlal Kumawat
//  Date :          08/12/2025
//
//////////////////////////////////////////////////////////////////////////////////////////////

class Logic
{
    int iNo1 ;
    int iNo2 ; 
    
    public Logic(int iNo1 , int iNo2)
    {
        this.iNo1 = iNo1;
        this.iNo2 = iNo2;
    }

    public boolean coPrime()
    {
        int iCnt = 0;
        int itemp = 0;
        int iCount = 0 ;
        if(iNo1 > iNo2)
        {
            itemp = iNo1;
            iNo1 = iNo2;
            iNo2 = itemp ;
        }
        
        for(iCnt = 1 ; iCnt <= iNo2 ; iCnt++)
        {
            if((iNo1 % iCnt) == 0 && (iNo2 % iCnt) == 0)
            {
                iCount++;
            }
        }
        if(iCount == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
}//end of the Logic class

//////////////////////////////////////////////////////////////////////////////////////////////
//
//Entery point class
//
//////////////////////////////////////////////////////////////////////////////////////////////

class CoPrime
{
    public static void main(String Arr[])
        {
            int iValue1 = 0 ;
            int iValue2 = 0 ;
            boolean bRet= false;

            Scanner sobj = new Scanner(System.in);
        
            System.out.println("Enter first number:");
            iValue1 = sobj.nextInt();

            System.out.println("Enter Second number:");
            iValue2 = sobj.nextInt();

            Logic lobj = new Logic(iValue1 , iValue2);
            bRet = lobj.coPrime();

        if(bRet == true)
        {
           System.out.println(iValue1 +" and "+iValue2+ " are co prime number");
        }
        else
        {
            System.out.println(iValue1 +" and "+iValue2+ " are not co prime number");
        }
        }

}//end of main class

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Input1:12            Input2:2           Output:12 and 2 are not co prime number
//  Input1:8             Input2:15          Output:8 and 15 are co prime number
//
//////////////////////////////////////////////////////////////////////////////////////////////