//Summation of N numbers in an array

#include <stdio.h>
#include <stdlib.h>

int Summation(int Arr[], int iLength)
{
    int iCnt = 0, iSum = 0;

    for(iCnt = 0;iCnt < iLength; iCnt++)
    {
        iSum = iSum + Arr[iCnt];
    }
    return iSum;
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

    iRet = Summation(ptr,iSize);
    printf("Summation of numbers is : %d\n",iRet);

    free(ptr);

    return 0;
}