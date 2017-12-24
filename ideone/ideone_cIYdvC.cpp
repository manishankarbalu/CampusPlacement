#include <iostream>
using namespace std;
void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
    *b=temp;
}
void Seggregate(int arr[],int size)
{
	int l=0,h=size-1;
	while(l<h)
	{
		while(arr[l]<0)
			l++;
		while(arr[h]>=0)
			h--;
		if(l<h)
		{
			swap(&arr[l],&arr[h]);
			l++;h--;
		}
	}
   l=0;
   while(l<size && h<size)
   {
   	  swap(&arr[l],&arr[h]);
   	  l+=2;
   	  h++;
   }
   for(int l=0;l<size;l++)
   {
   	cout<<arr[l]<<' ';
   }
}
int main()
{
  int arr[] = {5, -20, 10, 2, -10,-6};
  int arr_size = sizeof(arr)/sizeof(arr[0]);
  Seggregate(arr, arr_size);
  
  return 0;
}