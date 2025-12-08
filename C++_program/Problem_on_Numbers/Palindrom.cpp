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
//  Function Name : palindrom
//  Description :   check number is palindrom or not
//  Input :         Integer
//  output :        Integer
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
    int palindrom()
    {
        int iDigit = 0 ;
        int iRev = 0 ;
        while(iNo != 0 )
        {
            iDigit = iNo % 10 ;
            iNo = iNo /10 ;
            iRev = iRev*10 + iDigit;
        }
        return iRev;
    }
};// end of Logic Class

//////////////////////////////////////////////////////////////////////////////////////////////
//
//Entry point function
//
//////////////////////////////////////////////////////////////////////////////////////////////


int main()
{
    int iRet = 0 ;
    int iValue = 0 ;
    
    cout<<"Enter the number:\n";
    cin>>iValue;

    Logic lobj(iValue);
    iRet = lobj.palindrom();

    if(iRet == iValue)
    {
        cout<<iValue<< " is palindrom number"<<"\n";
    }
    else
    {
        cout<<iValue<<" is not a palindrom number"<<"\n";
    }

}
//end of main function

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Input1:121                  Output:121 is palindrom number
//  Input1:23                   Output:23 is not a palindrom number
//
//////////////////////////////////////////////////////////////////////////////////////////////