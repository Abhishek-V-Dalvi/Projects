#include <stdio.h>
#include <stdlib.h>

void DisplayEven(int *ptr1, int iLength)
{
    for(int iCnt = 0; iCnt < iLength; iCnt++)
    {
        if(*ptr1 % 2 == 0)      //if(ptr1[iCnt] % 2 == 0)
        {
            printf("%d\t",*ptr1);   // printf("%d\t",ptr1[iCnt]);
        }
        ptr1++;                     //Not required in 2nd way
    }
}

int main()
{
    int iSize = 0, iCnt = 0;
    int *ptr = NULL;
    

    printf("Enter number of elements in an array : \t");
    scanf("%d",&iSize);

    ptr = (int *)malloc(iSize * sizeof(int));
    if(ptr == NULL)
    {
        printf("Unable to allocate memory\n");
    }
    else
    {
        printf("Memory successfully allocated \n");
    
    
        printf("Enter the elements of an array : \n");
        for(iCnt = 0; iCnt < iSize; iCnt++)
        {
        scanf("%d",&ptr[iCnt]);
        }
    }    
 
    DisplayEven(ptr,iSize);

    free(ptr);

    return 0;
}

/*

    Steps to solve Problems on N numbers

    Step 1 :        Accept the size of array from user                          (main)

    Step 2 :        Allocate the memory dinamically for that array       (main)

    Step 3 :        Accept the values from user and store in the array  (main)

    Step 4 :        Pass that array and size to the function (Logic)        (Helper Function)

    Step 5 :        Deallocate memory of that array                             (main)

*/