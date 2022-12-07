// Addition of two numbers using header file 

#include "Header5.h"

/////////////////////////////////////////////////////////////////////
// Write a program to perform addition of 2 numbers
/////////////////////////////////////////////////////////////////////

int main()
{
    int iNo1 = 0;
    int iNo2 = 0;
    int iAns = 0;

    printf("Enter first number :\n");
    scanf("%d",&iNo1);

    printf("Enter second number :\n");
    scanf("%d",&iNo2);

    iAns = Addition(iNo1,iNo2);     //Function call from main

    printf("Addition is : %d",iAns);
    return 0;
}


/////////////////////////////////////////////////////////////////////
//
//  Input   :   11      10
//  Output  :   21
//
/////////////////////////////////////////////////////////////////////