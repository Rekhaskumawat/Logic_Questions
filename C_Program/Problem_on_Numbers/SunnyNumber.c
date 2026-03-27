//////////////////////////////////////////////////////////////////////////////////////////////
//
//required header file
//
//////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdbool.h>
#include<math.h>

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : SunnyNumber()
//  Description :   Check wheather the number is Sunny Number or Not
//  Input :         Integer
//  output :        bool
//  Author :        Rekha Shankarlal Kumawat
//  Date :          22/03/2026
//
//////////////////////////////////////////////////////////////////////////////////////////////


bool SunnyNumber(int iNo)
{
    int Ans = 0;

    iNo++;

    Ans = (int)sqrt(iNo);
    
    return(iNo == (Ans*Ans));

}
int main()
{
    int iValue = 0;
    bool bRet = false ;

    printf("Enter the Number :- ");
    scanf("%d" , &iValue);
    
    bRet =  SunnyNumber(iValue);

    if(bRet == true)
    {
        printf("%d is a Sunny Number\n", iValue);
    }
    else
    {
        printf("%d is not a Sunny Number\n", iValue);
    }

    return 0 ;
}