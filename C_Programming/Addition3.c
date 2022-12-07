// Addition of two numbers 

/////////////////////////////////////////////////////////////////////
//
//  Function Name   :   Addition
//  Description     :   Used to perform addition of 2 numbers
//  Input           :   Integer, Integer
//  Output          :   Integer
//  Date            :   12/04/2022
//  Author          :   Abhishek Vinayak Dalvi
//
/////////////////////////////////////////////////////////////////////


#include <stdio.h>

int Addition(int iValue1,int iValue2)   //User define function of addition
{
    int iSum = 0;
    iSum = iValue1 + iValue2;
    return iSum;
    //return iValue1+iValue2;          //Another way of returning the value in short
}

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