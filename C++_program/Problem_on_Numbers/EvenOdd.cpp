#include<iostream>
using namespace std;

class EvenOdd
{
    public:
        int iNo = 0 ;
        EvenOdd(int iNo)
        {
            this->iNo = iNo;
        }
    
    bool Check()
    {
        return ((iNo % 2) == 0) ;   
    }

};

int main()
{
    int iValue = 0 ;
    bool bRet = false;

    cout<<"Enter the number :"<<"\n";
    cin >> iValue ;

    EvenOdd eobj(iValue);
    bRet = eobj.Check();

    if(bRet == true)
    {
        cout<< iValue << " is Even number\n";
    }
    else
    {
        cout<< iValue << "is odd number\n";
    }

    return 0;
}