#include <stdio.h>

typedef unsigned long int ULONG;

ULONG PowerX(int iNo1, int iNo2)
{
    ULONG lMult = 1;
    register int iCnt = 0;

    for(iCnt = 1; iCnt<=iNo2; iCnt++)
    {
        lMult = lMult * iNo1;
    }

    return lMult;
}

int main()
{
    auto int iBase = 0;
    auto int iPower = 0;
    ULONG lRet = 0;

    printf("Enter the base number : ");
    scanf("%d",&iBase);
    
    printf("Enter the power : ");
    scanf("%d",&iPower);

    lRet = PowerX(iBase,iPower);
    printf("%d to the power %d is : %d",iBase,iPower,lRet);
    
    return 0;
}