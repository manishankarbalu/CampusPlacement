#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int arr[]={2,4,3,1,7,8,9,5};
	int n=8;
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(arr[j]>arr[j+1])
			   swap(arr[j],arr[j+1]);
		}
	}
	for(int i :arr)
	  cout<<i<<' ';
	return 0;
}