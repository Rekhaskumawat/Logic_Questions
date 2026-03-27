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
//  Function Name : NeonNumber()
//  Description :   check number is Neon number or not
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
        bool NeonNumber()
        {
            int iCount = 0 ;
            int iDigit = 0 ;
            int iTemp = 0  ;
            int iSum = 0 ;

            iTemp = iNo ;

            iNo = iNo * iNo;

            while (iNo != 0) 
            {
                iDigit = iNo % 10;
                iSum = iSum+iDigit ;
                iNo = iNo / 10;
            }

            return iSum == iTemp;
        } 
};
int main()
{
    int iValue = 0;
    bool bRet = false ;

    cout<<"Enter the Number :- ";
    cin>>iValue;
    
    Logic lobj(iValue);
    bRet =  lobj.NeonNumber();

    if(bRet == true)
    {
        cout<<iValue<<" is a Neon Number\n";
    }
    else
    {
        cout<<iValue<<" is not  a Neon Number\n";
    }

    return 0 ;
}