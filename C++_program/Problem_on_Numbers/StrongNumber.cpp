//////////////////////////////////////////////////////////////////////////////////////////////
//
//required header file
//
//////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>                   // for taking input from user
using namespace std ;

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Class Name  :   Logic
//  Function Name : StrongNumber()
//  Description :   check number is Strong number or not
//  Input :         Integer
//  output :        void
//  Author :        Rekha Shankarlal Kumawat
//  Date :          22/03/2025
//
//////////////////////////////////////////////////////////////////////////////////////////////

class Logic
{
    public:
        int iNo;
        
        Logic(int iNo)
        {
            this->iNo = iNo ;
        }

        bool StrongNumber()
        {
            int iDigit = 0 ;
            int iSum = 0 ;
            int iTemp = this->iNo ;
            int factArr[] ={1,1,2,6,24,120,720,5040,40320 ,362880 };

            while(iNo != 0)
            {
                iDigit = this->iNo % 10 ;

                iSum = iSum + factArr[iDigit];

                this->iNo =  this->iNo / 10 ;
            }
            return iTemp == iSum ;
        }

};

int main()
{
    int iValue = 0;
    bool iRet = false ;

    cout<<"Enter a Number :- ";
    cin>>iValue;

    Logic lobj(iValue);
    iRet = lobj.StrongNumber();

    if(iRet == true)
    {
        cout<<iValue<<" is a Strong Number "<<"\n";
    }
    else
    {
        cout<<iValue<<" is a not Strong Number "<<"\n";
    }
    return 0;
}