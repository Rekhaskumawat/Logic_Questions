//////////////////////////////////////////////////////////////////////////////////////////////
//
//required header file
//
//////////////////////////////////////////////////////////////////////////////////////////////

import java.util.Scanner;

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Class Name :    Logic
//  Function Name : Maximum
//  Description :   Returns the largest number
//  Input :         Integer , Integer , Integer
//  output :        Integer
//  Author :        Rekha Shankarlal Kumawat
//  Date :          03/12/2025
//
//////////////////////////////////////////////////////////////////////////////////////////////

class Logic
{
    int iNo1 ;
    int iNo2 ;
    int iNo3 ;

    public Logic(int iNo1 , int iNo2 , int iNo3)
    {
        this.iNo1= iNo1 ;
        this.iNo2= iNo2 ;
        this.iNo3= iNo3 ;
    }

    int Maximum()
    {
        if(iNo1 > iNo2)
        {
            if(iNo1 > iNo3)
            {
                return iNo1;
            }
            else
            {
                return iNo3;
            }
        }
        else if(iNo2 > iNo3)
        {
            return iNo2;
        }
        else
        {
            return iNo3 ;
        }
    }
    
}//end of the Logic class

//////////////////////////////////////////////////////////////////////////////////////////////
//
//Entery point class
//
//////////////////////////////////////////////////////////////////////////////////////////////

class Maximum
{
    public static void main(String Arr[])
        {
            int iValue1 = 0 ;
            int iValue2 = 0;
            int iValue3 = 0 ;
            int iRet = 0;

            Scanner sobj = new Scanner(System.in);
            

            System.out.println("Enter first number:");
            iValue1 = sobj.nextInt();

            System.out.println("Enter Second number:");
            iValue2 = sobj.nextInt();

            System.out.println("Enter third number:");
            iValue3 = sobj.nextInt();

            Logic lobj = new Logic(iValue1 , iValue2 , iValue3);
            iRet = lobj.Maximum();

            System.out.println("Maximum number : "+iRet);
        
        }

}//end of main class

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Input1:6      Input2:15       Input3:32         Output:Maximun  numbers :32
//  Input1:23     Input2:43      Input3:54          Output:Maximun  numbers :54
//

//////////////////////////////////////////////////////////////////////////////////////////////
