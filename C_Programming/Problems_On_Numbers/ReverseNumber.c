#include <stdio.h>

int Reverse(int iNo)
{
    int iDigit = 0;
    int iRev = 0;

    while(iNo > 0)
    {
       iDigit = iNo % 10;        //543   iDigit = 3     4       5
       iRev = iRev * 10 + iDigit;    // iRev = 3    30+4=34     340+5=345

       iNo = iNo / 10;                 //54         5
    }

    return iRev;
}

int main()
{
    int iValue = 0;
    int iRet = 0;

    printf("Enter the number : ");
    scanf("%d",&iValue);

    iRet = Reverse(iValue);
    printf("Reversed number is : %d",iRet);

    return  0;
}