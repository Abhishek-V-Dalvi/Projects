// Demonstration of itteration using for loop

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
    int iCnt = 0;

    if(iValue < 0)          //Filter
    {
        printf("Please enter positive value");
        return;
    }

    for(iCnt = 1; iCnt<=iValue; iCnt++)
    {
        printf("Hello %d\n",iCnt);      
    }
}