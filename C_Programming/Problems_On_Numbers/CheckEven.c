// Accept the number from user and check whether it is even or  odd

#include <stdio.h>
#include <stdbool.h>    // Header file to include bool datatype

bool ChkEven(int iValue)
{
    if(iValue % 2 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int iNo = 0;
    bool bRet = false;

    printf("Enter the number that you wannt to check : ");
    scanf("%d",&iNo);

    bRet = ChkEven(iNo);

    if(bRet == true)
    {
        printf("%d is Even number",iNo);
    }
    else
    {
        printf("%d is Odd number",iNo);
    }

    return 0;
}