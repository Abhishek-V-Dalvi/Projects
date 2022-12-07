// Demonstration of itteration using while loop

#include <stdio.h>

void Display(int iValue); //Function Declaration

int main()
{
    int iNo = 0;

    printf("Enter how mny times you want to display on screen : \t");
    scanf("%d",&iNo);
    
    Display(iNo);  //Function call

    return 0;
}

void Display(int iValue)  //Function defination
{
    int iCnt = 1;

    if(iValue < 0)          //Updater
    {
        iValue = -iValue;
    }

    while(iCnt<=iValue)
    {
        printf("Hello %d\n",iCnt);
        iCnt++;
    }
}