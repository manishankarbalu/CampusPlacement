// C++ implementation of randomized quickSelect
#include<iostream>
#include<climits>
#include<cstdlib>
using namespace std;
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int arr[],int l,int r)
{
	int x=arr[r],i=l;
	for(int j=l;j<=r-1;j++)
	{
		if(arr[j]<=x)  //put>= for largest kth ele
		{
          swap(&arr[i],&arr[j]);
          i++;
		}			
	}
	swap(&arr[i],&arr[r]);
    return i;
}


int randomPartition(int arr[],int l,int r)
{
	int n=r-l+1;
	int pivot=rand()%n;
	swap(&arr[l+pivot],&arr[r]);
	return partition(arr,l,r);
}
int KthElement(int arr[],int l,int r,int k)
{
	if(k>0 && k<=r-l+1)
	{
		int pos=randomPartition(arr,l,r);

		if(pos-l==k-1)
			return arr[pos];
		if(pos-l>k-1)
		{
			return KthElement(arr,l,pos-1,k);
		}
		return KthElement(arr,pos+1,r,k-(pos-l+1));
	}
	return INT_MAX;
}

int main()
{
    int arr[] = {12,3, 5, 7, 4, 19, 26};
    int n = sizeof(arr)/sizeof(arr[0]), k =3 ;
    for(int p=1;p<n;p++)
    cout << "K'th smallest element is " << KthElement(arr, 0, n-1, n-p)<<'\t'<<p<<endl;
   // cout << "K'th largest element is " << KthElement(arr, 0, n-1, n-k);
    return 0;
}