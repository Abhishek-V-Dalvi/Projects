#include <iostream>
using namespace std;

template <class T>
T Maximum(T Arr[], int size)
{
	int i = 0;
	T Max = Arr[0];
	for(i=0 ; i<size;i++)
	{
		if(Arr[i]>Max)
		{
			Max = Arr[i];
		}
	}
	return Max;
}


int main()
{
	int Brr [] = {10,20,30,40,50};
	int iRet = 0;
	iRet = Maximum(Brr,5);
	cout<<"Maximum number is : "<<iRet<<endl;
	
	float Crr [] = {10.10,20.20,30.30,40.40,50.50};
	float fRet = 0;
	fRet = Maximum(Crr,5);
	cout<<"Maximum number is : "<<fRet<<endl;
		
	return 0;
}