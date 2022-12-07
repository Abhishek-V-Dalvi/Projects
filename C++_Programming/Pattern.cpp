#include<iostream>
using namespace std;

class LinePattern
{
    private:
        int  iNo;

    public:
        LinePattern(int a)
        {
            this->iNo = a;
        }

        void StarLine()
        {
            int iCnt = 0;

            for(iCnt = 1; iCnt <= iNo; iCnt++)
            {
                cout<<"*\t";
            }
            cout<<endl;
        }

        void ForwardNumberLine()
        {
            int iCnt = 0;

            for(iCnt = 1; iCnt <= iNo; iCnt++)
            {
                cout<<iCnt<<"\t";
            }
            cout<<endl;
        }

        void BackwardNumberLine()
        {
            int iCnt = 0;

            for(iCnt = iNo; iCnt >= 1; iCnt--)
            {
                cout<<iCnt<<"\t";
            }
            cout<<endl;
        }

        void MixForwardNumberStarLine()
        {
            int iCnt = 0;

            for(iCnt = 1; iCnt <= iNo; iCnt++)
            {
                cout<<iCnt<<"\t"<<"*\t";
            }
            cout<<endl;
        }

        void MixBackwardNumberStarLine()
        {
            int iCnt = 0;

            for(iCnt = iNo; iCnt >= 1; iCnt--)
            {
                cout<<iCnt<<"\t"<<"*\t";
            }
            cout<<endl;
        }

        void ForwardMirrorNumber()
        {
            int iCnt = 0;

            for(iCnt = 1; iCnt <= iNo; iCnt++)
            {
                cout<<iCnt<<"\t";
            }
            for(iCnt = iNo; iCnt >= 1; iCnt--)
            {
                cout<<iCnt<<"\t";
            }
            cout<<endl;
        }
        
        void BackwardMirrorNumber()
        {
            int iCnt = 0;

            for(iCnt = iNo; iCnt >= 1; iCnt--)
            {
                cout<<iCnt<<"\t";
            }
            for(iCnt = 1; iCnt <= iNo; iCnt++)
            {
                cout<<iCnt<<"\t";
            }
            cout<<endl;
        }

        void BothSignNumber()
        {
            int iCnt = 0;

            for(iCnt = -iNo; iCnt <= iNo; iCnt++)
            {
                cout<<iCnt<<"\t";
            }
            cout<<endl;
        }
};

class MatrixPattern
{
    private:
        int iRow, iCol;

    public:
        MatrixPattern(int a)
        {
            this->iRow = a;
            this->iCol = a;
        }

        void DisplayMatrixSymbol()
        {
                int i =0, j = 0;

                for(i=1;i<=iRow; i++)
                {
                    for(j =1; j<=iCol; j++)
                    {
                        cout<<"*"<<"\t";
                    }
                    cout<<endl;
                }
                cout<<endl;
        }

        void DisplayMatrixNumber1()
        {
                int i =0, j = 0;

                for(i=1;i<=iRow; i++)
                {
                    for(j =1; j<=iCol; j++)
                    {
                        cout<<j<<"\t";
                    }
                    cout<<endl;
                }
                cout<<endl;
        }

        void DisplayMatrixNumber2()
        {
                int i =0, j = 0;

                for(i=1;i<=iRow; i++)
                {
                    for(j =1; j<=iCol; j++)
                    {
                        cout<<i<<"\t";
                    }
                    cout<<endl;
                }
                cout<<endl;
        }

        void DigonalSymbol()
        {
            int i =0, j = 0;

                for(i=1;i<=iRow; i++)
                {
                    for(j =1; j<=iCol; j++)
                    {
                        if(i != j)
                        {
                            cout<<"*"<<"\t";
                        }
                        else
                        {
                            cout<<"$"<<"\t";
                        }
                    }
                    cout<<endl;
                }
                cout<<endl;
        }

        void DigonalUpStarLowHash()
        {
            int i =0, j = 0;

                for(i=1;i<=iRow; i++)
                {
                    for(j =1; j<=iCol; j++)
                    {
                        if(i < j)
                        {
                            cout<<"*"<<"\t";
                        }
                        else if(i == j)
                        {
                            cout<<"$"<<"\t";
                        }
                        else
                        {
                            cout<<"#"<<"\t";
                        }
                    }
                    cout<<endl;
                }
                cout<<endl;
        }

        void Border1()
        {
            int i =0, j = 0;

                for(i=1;i<=iRow; i++)
                {
                    for(j =1; j<=iCol; j++)
                    {
                        if((i==1) || (i==iRow) || (j==1) || (j==iCol))
                        {
                            cout<<"*"<<"\t";
                        }
                        else
                        {
                            cout<<"&"<<"\t";
                        }
                    }
                    cout<<endl;
                }
                cout<<endl;
        }

        void Border2()
        {
            int i =0, j = 0;

                for(i=1;i<=iRow; i++)
                {
                    for(j =1; j<=iCol; j++)
                    {
                        if((i==1) || (i==iRow) || (j==1) || (j==iCol))
                        {
                            cout<<"*"<<"\t";
                        }
                        else
                        {
                            cout<<" "<<"\t";
                        }
                    }
                    cout<<endl;
                }
                cout<<endl;
        }

        void BorderAndDiagonal()
        {
            int i =0, j = 0;

                for(i=1;i<=iRow; i++)
                {
                    for(j =1; j<=iCol; j++)
                    {
                        if((i==1) || (i==iRow) || (j==1) || (j==iCol) || (i == j))
                        {
                            cout<<"*"<<"\t";
                        }
                        else
                        {
                            cout<<" "<<"\t";
                        }
                    }
                    cout<<endl;
                }
                cout<<endl;
        }

        void BorderDiagonalUpLow()
        {
            int i =0, j = 0;

                for(i=1;i<=iRow; i++)
                {
                    for(j =1; j<=iCol; j++)
                    {
                        if((i==1) || (i==iRow) || (j==1) || (j==iCol) || (i == j))
                        {
                            cout<<"*"<<"\t";
                        }
                        else if (i<j)
                        {
                            cout<<"$"<<"\t";
                        }
                        else
                        {
                            cout<<"&"<<"\t";
                        }
                    }
                    cout<<endl;
                }
                cout<<endl;
        }

        void LowerTriangle1()
        {
            int i =0, j = 0;

                for(i=1;i<=iRow; i++)
                {
                    for(j =1; j<=i; j++)
                    {
                        
                        cout<<"*"<<"\t";
                    }
                    cout<<endl;
                }
                cout<<endl;
        }

        void LowerTriangle2()
        {
            int i =0, j = 0;

                for(i = 1; i <= iRow;i++)
                {
                    for(j = iCol; j>=1; j--)
                    {
                        if(i >= j)
                        {
                            cout<<"*\t";
                        }
                        else
                        {
                            cout<<" \t";;
                        }    
                    }
                    cout<<endl;    
                } 
                cout<<endl;
        }

        void UpperTriangle()
        {
            int i =0, j = 0;

                for(i=iRow;i>=1; i--)
                {
                    for(j =1; j<=i; j++)
                    {
                        
                        cout<<"*"<<"\t";
                    }
                    cout<<endl;
                }
                cout<<endl;
        }

        void Flag1()
        {
            int i =0, j = 0;

                for(i=iRow;i>=1; i--)
                {
                    for(j =1; j<=i; j++)
                    {
                        
                        cout<<"*"<<"\t";
                    }
                    cout<<endl;
                }
                for(i=2;i<=iRow; i++)
                {
                    for(j =1; j<=i; j++)
                    {
                        
                        cout<<"*"<<"\t";
                    }
                    cout<<endl;
                }
                cout<<endl;
        }

        void Flag2()
        {
            int i =0, j = 0;
                
                for(i=1;i<=iRow; i++)
                {
                    for(j =1; j<=i; j++)
                    {
                        
                        cout<<"*"<<"\t";
                    }
                    cout<<endl;
                }
                for(i=iRow-1;i>=1; i--)
                {
                    for(j =1; j<=i; j++)
                    {
                        
                        cout<<"*"<<"\t";
                    }
                    cout<<endl;
                }
                cout<<endl;
        }

        void Diagonal2()
        {
            int i =0, j = 0;

                for(i=1;i<=iRow; i++)
                {
                    for(j =iCol; j>=1; j--)
                    {
                        if(i == j)
                        {
                            cout<<"$"<<"\t";
                        }
                        else
                        {
                            cout<<"*"<<"\t";
                        }
                    }
                    cout<<endl;
                }
                cout<<endl;
        }
};

int main()
{
    int iSize = 0;
    cout<<"Enter the pattern size : ";
    cin>>iSize;
    LinePattern lobj(iSize);
    MatrixPattern mobj(iSize);
    
    lobj.StarLine();
    lobj.ForwardNumberLine();
    lobj.BackwardNumberLine();
    lobj.MixForwardNumberStarLine();
    lobj.MixBackwardNumberStarLine();
    lobj.ForwardMirrorNumber();
    lobj.BackwardMirrorNumber();
    lobj.BothSignNumber();

    mobj.DisplayMatrixSymbol();
    mobj.DisplayMatrixNumber1();
    mobj.DisplayMatrixNumber2();
    mobj.DigonalSymbol();
    mobj.DigonalUpStarLowHash();
    mobj.Border1();
    mobj.Border2();
    mobj.BorderAndDiagonal();
    mobj.BorderDiagonalUpLow();
    mobj.LowerTriangle1();
    mobj.UpperTriangle();
    mobj.Flag1();
    mobj.Flag2();
    mobj.LowerTriangle2();
    mobj.Diagonal2();

    return 0;
}