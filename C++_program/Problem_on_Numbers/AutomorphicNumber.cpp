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
//  Function Name : AutomorphicNumber()
//  Description :   check number is Automorphic number or not
//  Input :         Integer
//  output :        void
//  Author :        Rekha Shankarlal Kumawat
//  Date :          22/03/2025
//
//////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
using namespace std ;

class Logic
{

    public:
        int iNo;

        Logic(int iNo)
        {
            this->iNo = iNo;
        }
        bool AutomorphicNumber()
        {
            int iCount = 0 ;
            int iTemp = 0 ;
            int iSqr = 0 ;
            int iDeno = 0;
            int iCnt = 0 ;

            iTemp = this->iNo ;

            while (this->iNo != 0) 
            {
                iCount++ ;
                this->iNo = this->iNo / 10;
                
            }

            this->iNo = iTemp;
            iSqr = this->iNo * this->iNo;
            iDeno = 1 ;
            for(iCnt = 0; iCnt < iCount; iCnt++)
            {
                iDeno = iDeno * 10;
            }

            return((iSqr % iDeno) == iTemp);  
        }
};
int main()
{
    int iValue = 0;
    bool bRet = false ;

    cout<<"Enter the Number :- ";
    cin>>iValue;
    
    Logic lobj(iValue);
    bRet =lobj.AutomorphicNumber();

    if(bRet == true)
    {
        cout<<iValue<<" is a Automorphic Number\n";
    }
    else
    {
        cout<<iValue<<" is not a Automorphic Number\n";
        
    }
    return 0 ;
}