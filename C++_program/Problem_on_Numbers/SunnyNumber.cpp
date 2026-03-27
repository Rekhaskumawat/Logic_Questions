//////////////////////////////////////////////////////////////////////////////////////////////
//
//required header file
//
//////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>                   // for taking input from user
#include<cmath>
using namespace std ;

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Class Name  :   Logic
//  Function Name : SunnyNumber()
//  Description :   check number is Sunny number or not
//  Input :         Integer
//  output :        void
//  Author :        Rekha Shankarlal Kumawat
//  Date :          22/03/2025
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
        bool SunnyNumber()
        {
            int Ans = 0;

            this->iNo = this->iNo +1;

            Ans = (int)sqrt(this->iNo);
            
            return(this->iNo == (Ans*Ans));

        }
};
int main()
{
    int iValue = 0;
    bool bRet = false ;

    cout<<"Enter the Number :- \n";
    cin>>iValue;

    Logic lobj(iValue);
    bRet =  lobj.SunnyNumber();

    if(bRet == true)
    {
        cout<<iValue<<" is a Sunny Number\n";
    }
    else
    {
        cout<<iValue<<" is not a Sunny Number\n";
        
    }

    return 0 ;
}