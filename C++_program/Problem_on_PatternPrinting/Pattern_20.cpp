///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//required header file
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>                                              // for input output
using namespace std;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : Display
//  Description :   Display the pattern of character
//  Input :         Integer
//  output :        Void
//  Author :        Rekha Shankarlal Kumawat
//  Date :          19/12/2025
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Pattern
{
    public:

    int iRow ;
    int icol ;

    Pattern(int iNo1 , int iNo2)
    {
        this->iRow = iNo1 ;
        this->icol = iNo2 ;
    }

    void pattern()
    {
    int iCnt1 = 0 ;
    int iCnt2 = 0 ;
    if(iRow != iCol)
    {
        printf("Invalid input");
        printf("Row number and column number should be same");
        return;
    }
    for(iCnt1 = 1 ; iCnt1 <= iRow ; iCnt1++)
    {
        for(iCnt2 = 1; iCnt2 <= iCnt1 ; iCnt2++)
        {
            cout<<"*\t";       
        }
        cout<<"\n";
    }
    }
};//end of the pattern class

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//Entery point function
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    int iValue1 = 0 ;
    int iValue2 = 0 ;

    cout<<"Enter the number of Rows:";
    cin>>iValue1;

    cout<<"Enter the number of Columns:";
    cin>>iValue2;

    Pattern pobj(iValue1 , iValue2);
    pobj.pattern();
    
}// end of main function

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Input1:4    Input2:4   Output:*
//                                *       *
//                                *       *       *
//                                *       *       *       *
//
//  Input1:3    Input2:3   Output:*
//                                *       *
//                                *       *       *
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////