// Input :  Row 4   Columns     4
/*
$   2   3   4
1   $   3   4
1   2   $   4
1   2   3   $
*/




#include<stdio.h>

void Display(int iRow, int iCol)
{
    int iCnt1 = 0, iCnt2;

    if(iRow != iCol)
        {
            printf("Invalid input. Number of Rows and column should be same.\n");
            return;
        }

    for(iCnt1 = 1; iCnt1 <= iRow; iCnt1++)
    {
        for(iCnt2 = 1; iCnt2 <= iCol; iCnt2++)
        {
            if(iCnt1 != iCnt2)
            {
                printf("%d\t",iCnt2);
            }
            else
            {
                printf("$\t");
            }
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