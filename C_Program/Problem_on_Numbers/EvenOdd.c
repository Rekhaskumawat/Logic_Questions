#include<stdio.h>
#include<stdbool.h>

bool EvenOdd(int iNo)
{
    return ((iNo % 2) == 0) ;
} 


int main()
{
    int iValue = 0 ;
    bool bRet = false;

    printf("Enter the number :");
    scanf("%d", &iValue);

    bRet = EvenOdd(iValue);

    if(bRet == true)
    {
        printf("%d is Even number", iValue);
    }
    else
    {
        printf("%d is odd number", iValue);
    }

    return 0;
}