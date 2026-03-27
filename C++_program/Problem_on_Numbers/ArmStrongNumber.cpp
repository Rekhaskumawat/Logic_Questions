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
//  Function Name : ArmstrongNumber()
//  Description :   check number is Armstrong number or not
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

        bool ArmstrongNumber()
        {
                int iCount = 0 , iDigit = 0 , iPow = 0 , iTemp = 0 ,iSum = 0 , iCountTemp =0 ;
                
                iTemp = this->iNo;

                while(this->iNo != 0)
                {
                    iDigit = this->iNo % 10;               
                    iCount++;
                    this->iNo = this->iNo / 10;
                }

                
                this->iNo = iTemp ;
                iCountTemp = iCount ;

                while (this->iNo != 0) 
                {
                    iDigit = this->iNo % 10;
                    iCount= iCountTemp;
                    iPow =1 ;

                    while(iCount!= 0)
                    {
                        iPow = iPow*iDigit;
                        iCount--;
                    }

                    iSum =iSum +iPow ;
                    this->iNo = this->iNo / 10;
                    
                }

                return iSum == iTemp;
        }

};
int main()
{
    int iValue = 0;
    bool iRet = false;

    cout<<"Enter the Numner : ";
    cin>>iValue;

    Logic lobj(iValue);
    iRet = lobj.ArmstrongNumber();

    if(iRet == true)
    {
        cout<<iValue<<" is a ArmStrong Number " <<"\n";
    }
    else
    {
        cout<<iValue<<" is a ArmStrong Number " <<"\n";
    }
    return 0;

}