// Input :  Row 4   Columns     4
/*
1   2   3   4
1   2   3   4
1   2   3   4
1   2   3   4
*/



#include<stdio.h>

void Display(int iRow, int iCol)
{
    int iCnt1 = 0, iCnt2;

    for(iCnt1 = 1; iCnt1 <= iRow; iCnt1++)
    {
        for(iCnt2 = 1; iCnt2 <= iCol; iCnt2++)
        {
            printf("%d\t",iCnt2);
        }
        printf("\n");
    }
}

int main()
{
    int iRow = 0, iCol = 0;

    printf("Enter the number of rows :\t");
    scanf("%d",&iRow);

    printf("Enter the number of columns :\t");
    scanf("%d",&iCol);
    
    Display(iRow,iCol);

    return 0;
}