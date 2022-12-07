// Summation of a number till the input number

#include <stdio.h>

int Summation(int iValue)
{
    int iSum = 0;
    int iCnt = 0;

    if(iValue < 0)      //Updater
    {
        iValue = -iValue;
    }

    for(iCnt = 1; iCnt<=iValue; iCnt++)
    {
        iSum = iSum + iCnt;
    }

    return iSum;
}

int main()
{
    int iNo = 0;
    int iAns = 0;

    printf("Enter the number : ");
    scanf("%d",&iNo);

    iAns = Summation(iNo);
    printf("Summation is : %d",iAns );

    return 0;
}