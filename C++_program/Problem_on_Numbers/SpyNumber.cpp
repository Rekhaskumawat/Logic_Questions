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
//  Function Name : SpyNumber()
//  Description :   check number is Spy number or not
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
    bool SpyNumber()
    {

        int iSum = 0 ;
        int iprod = 0 ;
        int iDigit = 0; 
        int iTemp = 0;
        
        iTemp = this->iNo ;

        iprod = 1 ;
        while(this->iNo != 0)
        {
            iDigit = this->iNo % 10 ;
            iSum = iSum + iDigit;
            iprod = iprod*iDigit;

            this->iNo = this->iNo /10 ;
        }
        return iSum == iprod;
        
    }
};
int main()
{
    int iValue = 0;
    bool bRet = false ;

    cout<<"Enter the Number :- \n";
    cin>>iValue;
    
    Logic lobj(iValue);
    bRet =  lobj.SpyNumber();

    if(bRet == true)
    {
        cout<<iValue<<" is a Spy Number\n";
    }
    else
    {
        cout<<iValue<<" is not a Spy Number\n";
        
    }

    return 0 ;
}