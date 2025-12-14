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
        int iOdd = 0 ;

        for(iCnt1 = 1 ; iCnt1 <= iRow ; iCnt1++ )
        {
            for(iCnt2 = 1 , iOdd = 1 ; iCnt2 <= icol ; iCnt2++ )
            {
                if((iCnt1%2)==1)
                {
                   cout<<(iCnt2*2)<< "\t";
                }
                else
                {
                    cout<<(iOdd)<< "\t";
                    iOdd+=2 ;
                }
                
                
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
//  Input1:4          Input2:4                      Output: 2       4       6       8
//                                                          1       3       5       7
//                                                          2       4       6       8
//                                                          1       3       5       7
//
//  Input1:3          Input2:3                       Output:  2       4       6       8
//                                                            1       3       5       7
//                                                            2       4       6       8
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////