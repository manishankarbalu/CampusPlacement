#include<bits/stdc++.h>
using namespace std;


int maximumProductSubarray(int arr[],int size)
{
	int max_sofar=1,max_ending=1,min_ending=1;

	for(int i=0;i<size;i++)
	{
		if(arr[i]>0)
		{
			max_ending=max_ending*arr[i];
			min_ending=min(min_ending*arr[i],1);
		}
		else
			if(arr[i]==0)
			{
				max_ending=1;
				min_ending=1;
			}
			else
			{
				int temp=max_ending;
				max_ending=max(min_ending*arr[i],1);
				min_ending=temp*arr[i];
			}
	max_sofar=max(max_sofar,max_ending);
	}
	return max_sofar;
}
int main()
{
    int arr[] = {-3, 6, -10, 0, 2};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<maximumProductSubarray(arr,n);
    return 0;
}