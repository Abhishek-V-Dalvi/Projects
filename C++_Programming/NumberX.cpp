#include <iostream>
using namespace std;

class NumberX
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

        int SumTillNumber()
        {
            int iCnt = 0, iSum = 0;

            for(iCnt = 1; iCnt <= iNo; iCnt++)
            {
                iSum = iSum + iCnt;
            }
            return iSum;
        }

        int ReverseNumber()
        {
            int iCnt = 0, iRev = 0, iDigit = 0, iTemp = 0;
            iTemp = iNo;
            while(iTemp != 0)
            {
                iDigit = iTemp % 10;
                iTemp = iTemp / 10;
                iRev = iRev * 10 + iDigit;
            }
            return iRev;
        }

        unsigned long int Factorial()
        {
            unsigned long long int iFact = 1;
            int iCnt = 0;
            if(iNo < 13)
            {
                for(iCnt = 2; iCnt <= iNo; iCnt++)
                {
                    iFact = iFact * iCnt;
                }
                return iFact;
            }
            else
            {
                cout<<"Can not find factorial of number more than 13"<<endl;
                return 0;
            }
        }

        void DisplayFactor()
        {
            int iCnt = 0, iTemp = 0;
            iTemp = iNo;
            cout<<"Factors of "<<iNo<<" are :\t";
            for(iCnt = 1; iCnt <= (iTemp/2)+1; iCnt++)
            {
                if(iTemp % iCnt == 0)
                {
                    cout<<iCnt<<"\t";
                }
            }
            cout<<endl;
        }

        void DisplayNonFactor()
        {
            int iCnt = 0;

            cout<<"Non factors of "<<iNo<<" are :\t";
            for(iCnt = 1; iCnt < iNo; iCnt++)
            {
                if(iNo % iCnt != 0)
                {
                    cout<<iCnt<<"\t";
                }
            }
            cout<<endl;
        }

        int CountFactor()
        {
            int iCnt = 0, iTemp = 0, iCount = 0;
            iTemp = iNo;
            for(iCnt = 1; iCnt <= (iTemp/2)+1; iCnt++)
            {
                if(iTemp % iCnt == 0)
                {
                    iCount++;
                }
            }
            return iCount;
        }

        void CheckPrime()
        {
            int iCnt = 0,  iTemp = 0;
            iTemp = iNo;
            for(iCnt = 2; iCnt <= (iTemp/2); iCnt++)
            {
                if(iTemp % iCnt == 0)
                {
                    break;
                }
            }
            if(iCnt > (iTemp/2))
            {
                cout<<iNo<<" is a prime number"<<endl;
            }
            else
            {
                cout<<iNo<<" is not a prime number"<<endl;

            }
        }

        void CheckPerfect()
        {
            int iCnt = 0,  iTemp = 0, iSum = 0;
            iTemp = iNo;
            for(iCnt = (iTemp/2); (iCnt >= 1) && (iSum <= iTemp); iCnt--)
            {
                if(iTemp % iCnt == 0)
                {
                    iSum = iSum + iCnt;
                }
            }
            if(iSum == iTemp)
            {
                cout<<iNo<<" is a perfect number"<<endl;
            }
            else
            {
                cout<<iNo<<" is not a perfect number"<<endl;

            }
        }

        void CheckPallindrome()
        {
            int iAns = 0;

            iAns = ReverseNumber();
            if(iAns == iNo)
            {
                cout<<iNo<<" is a pallindrome number"<<endl;
            }
            else
            {
                cout<<iNo<<" is not a pallindrome number"<<endl;
            }
        }

        void CheckArmstrong()
        {
            int iCnt = 0, iTemp = 0, iDigit = 0, iDigcnt = 0, iMult = 1, iSum = 0;

            iTemp = iNo;

            while(iTemp > 0)
            {
                iTemp = iTemp / 10;
                iDigcnt++;
            }
            iTemp = iNo;
            while(iTemp > 0)
            {
                iMult = 1;
                iDigit = iTemp % 10;
                iTemp = iTemp / 10;
                for(iCnt = 1; iCnt <= iDigcnt; iCnt++)
                {
                    iMult = iMult * iDigit;
                }
                iSum = iSum + iMult;
            }
            if(iSum == iNo)
            {
                cout<<iNo<<" is an armstrong number"<<endl;
            }
            else
            {
                cout<<iNo<<" is not an armstrong number"<<endl;
            }
        }
};

int main()
{
    int iRet = 0;
    unsigned long long int ulRet = 0;
    NumberX obj;

    obj.Accept();
    obj.Display();

    iRet = obj.SumTillNumber();
    cout<<"Summation of all numbers till input number is : "<<iRet<<endl;

    iRet = obj.ReverseNumber();
    cout<<"Reverse number is : "<<iRet<<endl;

    ulRet = obj.Factorial();
    cout<<"Factorial is : "<<ulRet<<endl;

    obj.DisplayFactor();

    obj.DisplayNonFactor();    

   iRet = obj.CountFactor();
   cout<<"Count of factors is : "<<iRet<<endl;

    obj.CheckPrime();

    obj.CheckPerfect();

    obj.CheckPallindrome();

    obj.CheckArmstrong();

    return 0;
}