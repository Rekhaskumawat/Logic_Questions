//////////////////////////////////////////////////////////////////////////////////////////////
//
//required header file
//
//////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : PerfectNumber
//  Description :   checks the perfect number
//  Input :         Integer
//  output :        Integer
//  Author :        Rekha Shankarlal Kumawat
//  Date :          04/12/2025
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
    
        int PerfectNumber()
        {
            int iCnt = 0 ;
            int iSum = 0 ;
            for(iCnt = 1 ; iCnt < iNo ; iCnt++)
            {
                if((iNo % iCnt) == 0)
                {
                    iSum = iSum + iCnt;
                }
            }
            return iSum;
        }
};//end of the Logic class

//////////////////////////////////////////////////////////////////////////////////////////////
//
//Entery point function
//
//////////////////////////////////////////////////////////////////////////////////////////////


int main()
{
    int iValue = 0 ;
    int iRet = 0 ;
    
    cout<<"enter the number :\n";
    cin>>iValue;

    Logic lobj(iValue);
    iRet = lobj.PerfectNumber();

    if(iRet == iValue)
    {
        cout<<iValue<<" is perfect number\n";
    }
    else
    {
        cout<<iValue<<" is not perfect number\n";
    }

    return 0 ;
}//end of main function

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Input1:6                   Output:6 is perfect number
//  Input1:23                  Output:23 is not perfect number
//
//////////////////////////////////////////////////////////////////////////////////////////////