// Calculate the summation of all the elements of an array using OOP approach

#include <iostream>
using namespace std;

class ArrayX
{
    private:
        int iSize;
        int *Arr;

    public:
        ArrayX(int No)                  //Parametrised constructor
        {
            this->iSize = No;           
            Arr = new int[iSize];       //Resource allocation
        }

        ~ArrayX()                       //Destructor
        {
            delete []Arr;               //Resource deallocation
        }

        void Accept()                   // Getter method
        {
            int iCnt = 0;

            cout<<"Enter the elements in an array : "<<endl;
           
            for(iCnt = 0; iCnt < iSize;  iCnt++)
            {
                cin>>Arr[iCnt];
            }
        }

        void Display()                  // Setter method
        {
            int iCnt = 0;

            cout<<"Elements of array are : "<<endl;

            for(iCnt = 0; iCnt < iSize; iCnt++)
            {
                cout<<Arr[iCnt]<<endl;
            }
        }

        int Summation()
        {
            int iCnt = 0, iSum = 0;

            for(iCnt = 0;  iCnt < iSize;  iCnt++)
            {
                iSum = iSum + Arr[iCnt];
            }
            return iSum;
        }
};

int main()
{
    int iLength = 0, iRet = 0;

    cout<<"-----Program of summation of N numbers-----"<<endl;
    cout<<"Enter the length of an array : "<<endl;
    cin>>iLength;
    
    ArrayX obj1(iLength);
    obj1.Accept();
    obj1.Display();
    iRet = obj1.Summation();
    cout<<"Summation of all elemets of an array is : "<<iRet<<endl;

    return 0;
}