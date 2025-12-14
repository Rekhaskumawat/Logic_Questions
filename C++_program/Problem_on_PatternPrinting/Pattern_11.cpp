//////////////////////////////////////////////////////////////////////////////////////////////
//
//required header file
//
//////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Class Name :    Pattern
//  Function Name : pattern
//  Description :   Display pattern
//  Input :         Integer 
//  output :        void
//  Author :        Rekha Shankarlal Kumawat
//  Date :          13/12/2025
//
//////////////////////////////////////////////////////////////////////////////////////////////

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
        char ch = 'A';

        for(iCnt1 = 1 ; iCnt1 <= iRow ; iCnt1++ )
        {
            for(iCnt2 = 1 , ch = 'A' ; iCnt2 <= icol ; iCnt2++ , ch++)
            {
                
                cout<<ch<< "\t";
                
            }
            cout<<"\n";
        }
    }

};//end of Pattern class

//////////////////////////////////////////////////////////////////////////////////////////////
//
//Entery point function
//
//////////////////////////////////////////////////////////////////////////////////////////////

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

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Input1:4          Input2:4                      Output: A       B       C       D
//                                                          A       B       C       D
//                                                          A       B       C       D
//                                                          A       B       C       D
//
//  Input1:3          Input2:3                       Output: A       B       C 
//                                                           A       B       C
//                                                           A       B       C
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////