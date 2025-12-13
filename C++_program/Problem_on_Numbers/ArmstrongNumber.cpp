//////////////////////////////////////////////////////////////////////////////////////////////
//
//required header file
//
//////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
#include <cmath>                        // for exponent use
using namespace std;

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Class Name  :   Logic
//  Function Name : armstrong
//  Description :   checks armstrong number
//  Input :         Integer
//  output :        Integer
//  Author :        Rekha Shankarlal Kumawat
//  Date :          10/12/2025
//
//////////////////////////////////////////////////////////////////////////////////////////////

class Logic
{
    public:
    int iNo ;
    Logic(int iNo)
    {
        this->iNo = iNo;
    }

    int armstrong()
    {
        int iDigit = 0 ;
        int iSum = 0 ;
        int iCount = 0 ;
        int iTemp = iNo ;

        while(iNo != 0 )
        {
            iDigit = iNo % 10 ;
            iNo = iNo /10 ;
            iCount++;
        }

        while(iTemp != 0 )
        {
            iDigit = iTemp % 10 ;
            iTemp = iTemp /10 ;
            iSum = iSum + pow(iDigit,iCount);
        }

       return iSum ;
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
    cout<<"Enter the number:";
    cin>>iValue;

    Logic lobj(iValue);
    iRet = lobj.armstrong();

    if(iRet == iValue)
    {
        cout<< iValue<< " is an armstrong number";
    }
    else
    {
        cout<<iValue<< " is not an armstrong number";
    }

}//end of main function

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Input1:153                        Output:153 is an armstrong number
//  Input1:123                        Output:123 is not an armstrong number
//
//////////////////////////////////////////////////////////////////////////////////////////////