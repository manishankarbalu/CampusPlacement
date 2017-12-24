#include <iostream>
using namespace std;

int missingnum(int arr[],int n)
{
	int l=0,r=n-1,ind=0;
	while(l<=r)
	{
		int mid=(r+l)/2;
		
		if(arr[mid]==mid+1)
		    l=mid+1;
		else
		   {ind=mid;
		   r=mid-1;}
	}
	return arr[ind]-1;
}

int main() {
	// your code goes here
int arr[]={1, 2, 4, 5, 6, 7, 8, 9,10};
int n=9;
cout<<missingnum(arr,n);
	return 0;
}