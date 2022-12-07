// Count even numbers in an array

#include <stdio.h>
#include <stdlib.h>

int CountEven(int Arr[], int iLength)
{
    int iCnt = 0, iEvenCount = 0;

    for(iCnt = 0;iCnt < iLength; iCnt++)
    {
        if(Arr[iCnt] % 2 == 0)
        {
            iEvenCount++;
        }
    }
    return iEvenCount;
}

int main()
{
    int iSize = 0,  iCnt = 0, iRet = 0;
    int*ptr = NULL;

    printf("Enter the size of an array : \t");
    scanf("%d",&iSize);

    ptr = (int *)malloc(iSize * sizeof(int));
    if(ptr == NULL)
    {  printf("Unable to allocate the memory\n"); }
    else
    { printf("Memory successfully allocated\n"); }

    printf("Enter the elements in an array : \n");
    for(iCnt = 0; iCnt < iSize; iCnt++)
    {
        scanf("%d",&ptr[iCnt]);
    }

    iRet = CountEven(ptr,iSize);
    printf("Count of even numbers is : %d\n",iRet);

    free(ptr);

    return 0;
}