#include <iostream>
using namespace std;

class ArrayX
{
    private:
        int iLength;
        int *Arr;

    public:
        ArrayX()
        {
            Accept();
        }

        ~ArrayX()
        {
            delete []Arr;
        }

        void Accept()
        {
            int iCnt = 0;

            cout<<"Enter the size of an array : ";
            cin>>iLength;
            Arr = new int [iLength];

            cout<<"Enter the elements in an array : "<<endl;
            for(iCnt = 0; iCnt<iLength; iCnt++)
            {
                cin>>Arr[iCnt];
            }
        }

        void Display()
        {
            int iCnt = 0;

            cout<<"Elements of an array are : ";
            for(iCnt = 0; iCnt<iLength; iCnt++)
            {
                cout<<Arr[iCnt]<<"\t";
            }
            cout<<endl;
        }

        void DisplayEven()
        {
            int iCnt = 0;

            cout<<"Even elements in array are : ";
            for(iCnt = 0; iCnt<iLength; iCnt++)
            {
                if(Arr[iCnt] % 2 == 0)
                {
                    cout<<Arr[iCnt]<<"\t";
                }
            }
            cout<<endl;
        }

        void CountEven()
        {
            int iCnt = 0, iEvenCount = 0;

            cout<<"Number of even elements in array are : ";
            for(iCnt = 0; iCnt<iLength; iCnt++)
            {
                if(Arr[iCnt] % 2 == 0)
                {
                    iEvenCount++;
                }
            }
            cout<<iEvenCount<<endl;
        }

        void ChkNumber()
        {
            int iSearch = 0, iCnt = 0;
            cout<<"Enter the number you want to search in array : ";
            cin>>iSearch;
           
            for(iCnt = 0; iCnt<iLength; iCnt++)
            {
                if(Arr[iCnt] == iSearch)
                {
                    break;
                }
            }
            if(iCnt < iLength)
            {
                cout<<iSearch<<" is present in array"<<endl;
            }
            else
            {
                cout<<iSearch<<" is not present in array"<<endl;
            }
        }

        void ChkNumberFreq()
        {
            int iSearch = 0, iCnt = 0, iFreq = 0;
            cout<<"Enter the number whose frequency you want to check in array : ";
            cin>>iSearch;
           
            for(iCnt = 0; iCnt<iLength; iCnt++)
            {
                if(Arr[iCnt] == iSearch)
                {
                    iFreq++;
                }
            }
            cout<<"Frequency of "<<iSearch<<" in array is "<<iFreq<<endl;
        }

        void Maximum()
        {
            int iMax = 0, iCnt = 0;
            iMax = Arr[iCnt];
            for(iCnt = 1; iCnt<iLength; iCnt++)
            {
                if(Arr[iCnt] > iMax)
                {
                    iMax = Arr[iCnt];
                }
            }
            cout<<"Largest number in an array is "<<iMax<<endl;
        }

        void Minimum()
        {
            int iMin = 0, iCnt = 0;
            iMin = Arr[iCnt];
            for(iCnt = 1; iCnt<iLength; iCnt++)
            {
                if(Arr[iCnt] < iMin)
                {
                    iMin = Arr[iCnt];
                }
            }
            cout<<"Smallest number in an array is "<<iMin<<endl;
        }

        void Summation()
        {
            int iSum = 0, iCnt = 0;
            
            for(iCnt = 0; iCnt<iLength; iCnt++)
            {
                iSum = iSum + Arr[iCnt];
            }
            cout<<"Summation of all numbers in an array is "<<iSum<<endl;
        }

        void SearchFirstOccurance()
        {
            int iSearch = 0, iCnt = 0;
            cout<<"Enter thr number whose first occurance you want to search : ";
            cin>>iSearch;
            
            for(iCnt = 0; iCnt<iLength; iCnt++)
            {
                if(iSearch == Arr[iCnt])
                {
                    break;
                }
            }
            if(iCnt == iLength)
            {
                cout<<"Number is not present in an array"<<endl;
            }
            else
            {
                cout<<"First occurance of "<<iSearch<<" is at index "<<iCnt<<endl;
            }
        }

        void SearchLastOccurance()
        {
            int iSearch = 0, iCnt = 0;
            cout<<"Enter thr number whose last occurance you want to search : ";
            cin>>iSearch;
            
            for(iCnt = iLength-1; iCnt>=0; iCnt--)
            {
                if(iSearch == Arr[iCnt])
                {
                    break;
                }
            }
            if(iCnt == -1)
            {
                cout<<"Number is not present in an array"<<endl;
            }
            else
            {
                cout<<"Last occurance of "<<iSearch<<" is at index "<<iCnt<<endl;
            }
        }
};

int main()
{
    ArrayX obj;
    
    obj.Display();
    cout<<endl;
    obj.DisplayEven();
    cout<<endl;
    obj.CountEven();
    cout<<endl;
    obj.ChkNumber();
    cout<<endl;
    obj.ChkNumberFreq();
    cout<<endl;
    obj.Maximum();
    cout<<endl;
    obj.Minimum();
    cout<<endl;
    obj.Summation();
    cout<<endl;
    obj.SearchFirstOccurance();
    cout<<endl;
    obj.SearchLastOccurance();


    return 0;
}