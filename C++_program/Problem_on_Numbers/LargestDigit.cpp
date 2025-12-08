//////////////////////////////////////////////////////////////////////////////////////////////
//
//required header file
//
//////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Class Name  :   Logic
//  Function Name : largestDigit
//  Description :   find largest digit among given number
//  Input :         Integer
//  output :        Integer
//  Author :        Rekha Shankarlal Kumawat
//  Date :          08/12/2025
//
//////////////////////////////////////////////////////////////////////////////////////////////

class Logic
{
    int iNo ;
    public:
    Logic(int iNo)
    {
        this->iNo = iNo;
    }
    int largestDigit()
    {
        int ilargest = 0 ;
        int iDigit = 0 ;
        while(iNo != 0 )
        {
            iDigit = iNo % 10 ;
            iNo = iNo /10 ;
           if(ilargest <= iDigit)
           {
             ilargest = iDigit ;
           }
        }
       return ilargest;
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
    
    cout<<"Enter the Number :\n";
    cin>>iValue;

    Logic lobj(iValue);
    iRet = lobj.largestDigit();

    cout<<"Largest digit is : "<<iRet<<"\n";

}//end of main function

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Input1:12549                       Output:Largest digit is : 9
//  Input1:004352                      Output:Largest digit is : 5
//
//////////////////////////////////////////////////////////////////////////////////////////////