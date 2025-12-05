//////////////////////////////////////////////////////////////////////////////////////////////
//
//required header file
//
//////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : Maximum
//  Description :   return maximum number
//  Input :         Integer
//  output :        Integer
//  Author :        Rekha Shankarlal Kumawat
//  Date :          05/12/2025
//
//////////////////////////////////////////////////////////////////////////////////////////////

class Logic
{
    public:
        int iNo1 ;
        int iNo2 ;
        int iNo3 ;

        Logic(int iNo1 , int iNo2 , int iNo3)
        {
            this->iNo1 = iNo1;
            this->iNo2 = iNo2;
            this->iNo3 = iNo3;
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
};//end of the Logic class

//////////////////////////////////////////////////////////////////////////////////////////////
//
//Entery point function
//
//////////////////////////////////////////////////////////////////////////////////////////////


int main()
{
    int iValue1 = 0 ;
    int iValue2 = 0 ;
    int iValue3 = 0 ;
    int iRet = 0 ;
    
    cout<<"enter first number :\n";
    cin>>iValue1;

    cout<<"enter second number :\n";
    cin>>iValue2;

    cout<<"enter third number :\n";
    cin>>iValue3;

    Logic lobj(iValue1 , iValue2 , iValue3);
    iRet = lobj.Maximum();

    cout<<"Maximum number is "<<iRet<<"\n";

    return 0 ;
}//end of main function

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Input1:6      Input2:15       Input3:32         Output:Maximun  numbers :32
//  Input1:23     Input2:43      Input3:54          Output:Maximun  numbers :54
//
//////////////////////////////////////////////////////////////////////////////////////////////