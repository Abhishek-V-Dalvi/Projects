#include <iostream>
using namespace std;

template <class T>
void Display(T Arr[], int size)
{
	int i = 0;
	for(i=0 ; i<size;i++)
	{
		cout<<Arr[i]<<endl;
	}
}


int main()
{
	float Brr [] = {10.10,20.20,30.30,40.40,50.50};
	Display(Brr,5);
	
	int Crr [] = {10,20,30,40,50};
	Display(Crr,5);
	
	char Drr [] = {'a','b','c','c','e'};
	Display(Drr,5);
		
	return 0;
}