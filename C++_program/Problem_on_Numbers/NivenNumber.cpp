//////////////////////////////////////////////////////////////////////////////////////////////
//
//required header file
//
//////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;

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
    public:
    Logic(int iNo)
    {
        this->iNo = iNo;
    }
    bool nivenNumber()
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
};// end of Logic Class

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Entry point function
//
//////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    
    bool bRet = false ;
    int iValue = 0 ;
    cout<<"Enter the number:\n";
    cin>>iValue;

    Logic lobj(iValue);
    bRet = lobj.nivenNumber();

    if(bRet == true)
    {
        cout<<iValue <<" is Niven number"<<"\n";
    }
    else
    {
            cout<<iValue <<" is not a Niven number"<<"\n";
    }

}//end of main function

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Input1:12                   Output:12 is Niven number
//  Input1:15                   Output:15 is not Niven number
//
//////////////////////////////////////////////////////////////////////////////////////////////