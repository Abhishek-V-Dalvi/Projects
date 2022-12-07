// Demonstration of itteration using for loop

#include <stdio.h>

void Display(); //Function Declaration

int main()
{
    Display();  //Function call

    return 0;
}

void Display()  //Function defination
{
    int iCnt = 0;

    /*
        1 = Initialization
        2 = Condition
        3 = Displacement
        4 = Loop body
    */

            //1     //2     //3
    for(iCnt = 1; iCnt<=5; iCnt++)
    {
        printf("Hello %d\n",iCnt);      //4
    }
}