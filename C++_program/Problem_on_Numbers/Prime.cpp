//////////////////////////////////////////////////////////////////////////////////////////////
//
//required header file
//
//////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;

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
   
    public:
    Logic(int iNo)
    {
        this->iNo = iNo;
    }

    bool Prime()
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
    
};//end of the Logic class

//////////////////////////////////////////////////////////////////////////////////////////////
//
//Entery point function
//
//////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    int iValue= 0 ;
    
    bool bRet= false;

    cout<<"Enter the number:\n";
    cin>>iValue;

    Logic lobj(iValue);
    bRet = lobj.Prime();

    if(bRet == true)
    {
        cout<<iValue<< " is prime number";
    }
    else
    {
        cout<<iValue<< " is not prime number";
    }
}//end of main class

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Input1:12                  Output:12 is not prime number
//  Input1:15                  Output:15 is prime number
//
//////////////////////////////////////////////////////////////////////////////////////////////