//////////////////////////////////////////////////////////////////////////////////////////////
//
//required header file
//
//////////////////////////////////////////////////////////////////////////////////////////////

import java.util.Scanner;

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Class Name :    Logic
//  Function Name : Factor
//  Description :   Dispaly the factors of number
//  Input :         Integer
//  output :        void
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

    void Factor()
    {
        int iCnt = 0;
        
        for(iCnt = 1 ; iCnt <= iNo ; iCnt++)
        {
            if((iNo % iCnt) == 0 )
            {
                System.out.print(iCnt+"\t");
            }
        }
    
    }
    
}//end of the Logic class

//////////////////////////////////////////////////////////////////////////////////////////////
//
//Entery point class
//
//////////////////////////////////////////////////////////////////////////////////////////////

class Factor
{
    public static void main(String Arr[])
        {
            int iValue = 0 ;

            Scanner sobj = new Scanner(System.in);
        
            System.out.println("Enter the  number:");
            iValue = sobj.nextInt();

            Logic lobj = new Logic(iValue);
            lobj.Factor();

            
        }

}//end of main class

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Input1:6                   Output:1  2  3  4  6
//  Input1:12                  Output:1  2  3  4  6  12
//

//////////////////////////////////////////////////////////////////////////////////////////////
