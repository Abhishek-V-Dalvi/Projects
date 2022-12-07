#include <iostream>
using namespace std;

class Digit
{
    private:
        int iNo;

    public:
        void Accept()
        {
            cout<<"Enter the number  : ";
            cin>>this->iNo;
        }

        void Display()
        {
            cout<<"Entered number is : "<<this->iNo<<endl;
        }

        void DisplayDigit()
        {
            int iTemp = 0, iDigit = 0;
            iTemp = iNo;
            cout<<"Digits in the given number are : ";
            while(iTemp > 0)
            {
                iDigit = iTemp % 10;
                iTemp = iTemp / 10;
                cout<<iDigit<<"\t";
            }
            cout<<endl;
        }

        void DisplayEvenDigit()
        {
            int iTemp = 0, iDigit = 0;
            iTemp = iNo;
            cout<<"Even digits in the given number are : ";
            while(iTemp > 0)
            {
                iDigit = iTemp % 10;
                iTemp = iTemp / 10;
                if(iDigit % 2 == 0)
                {
                    cout<<iDigit<<"\t";
                }
            }
            cout<<endl;
        }
        
        void DisplayOddDigit()
        {
            int iTemp = 0, iDigit = 0;
            iTemp = iNo;
            cout<<"Odd digits in the given number are  : ";
            while(iTemp > 0)
            {
                iDigit = iTemp % 10;
                iTemp = iTemp / 10;
                if(iDigit % 2 != 0)
                {
                    cout<<iDigit<<"\t";
                }
            }
            cout<<endl;
        }

        int CountDigit()
        {
            int iCnt = 0, iTemp = 0;
            iTemp = iNo;
            while(iTemp > 0)
            {
                iTemp = iTemp / 10;
                iCnt++;
            }
            return iCnt;
        }

        int SumDigit()
        {
            int iSum = 0, iTemp = 0, iDigit = 0;
            iTemp = iNo;
            while(iTemp > 0)
            {
                iDigit = iTemp % 10;
                iTemp = iTemp / 10;
                iSum = iSum + iDigit;
            }
            return iSum;
        }
};

int main()
{
    int iRet = 0;

    Digit obj;
    obj.Accept();
    obj.Display();

    obj.DisplayDigit();

    obj.DisplayEvenDigit();

    obj.DisplayOddDigit();

    iRet = obj.CountDigit();
    cout<<"Number of digits are : "<<iRet<<endl;

    iRet = obj.SumDigit();
    cout<<"Sum of all digits is : "<<iRet<<endl;

    return 0;
}