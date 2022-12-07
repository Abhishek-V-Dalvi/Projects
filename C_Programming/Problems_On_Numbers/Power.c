#include <stdio.h>

int PowerX(int iNo1, int iNo2)
{
    int iMult = 1;
    
    for(int iCnt = 1; iCnt<=iNo2; iCnt++)
    {
        iMult = iMult * iNo1;
    }

    return iMult;
}

int main()
{
    int iBase = 0;
    int iPower = 0;
    int iRet = 0;

    printf("Enter the base number : ");
    scanf("%d",&iBase);
    
    printf("Enter the power : ");
    scanf("%d",&iPower);

    iRet = PowerX(iBase,iPower);
    printf("%d to the power %d is : %d",iBase,iPower,iRet);
    
    return 0;
}