#include <iostream>
using namespace std;
int binarySearch(int* arr,int l,int r,int k)
{
   if(l>r) return -1;
   int mid=(l+r)/2;
   if(arr[mid]==k)
   	return mid;
   if(arr[mid]>k)
   	return binarySearch(arr,l,mid-1,k);
   else
   	return binarySearch(arr,mid+1,r,k);
}
void findCeilAndFloor(int *arr,int size,int k)
{
	int pos=binarySearch(arr,0,size-1,k);
	if(pos-1>=0 && pos-1 <= size-1)
		cout<<"floor : "<<arr[pos-1]<<endl;
	if(pos+1>=0 && pos+1 <= size-1)
		cout<<"ceil : "<<arr[pos+1]<<endl;
}
int main()
{
   int arr[] = {1, 2, 8, 10, 10, 12, 19};
   int n = sizeof(arr)/sizeof(arr[0]);
   int x = 10;
   findCeilAndFloor(arr,n,x);
   return 0;
}