#include<bits/stdc++.h>
using namespace std;

int countIncreasingSubarrays(int arr[],int size)
{
	int count=1,totcnt=0;
	for(int i=0;i<size;i++)
	{
		if(arr[i]<arr[i+1])
			count++;
		else
		{
			totcnt+=((count-1)*count)/2;
			count=1;
		}
	}
	if(count>1)
	  totcnt+=((count-1)*count)/2;
	return totcnt;
}
 
// Driver program
int main()
{
  int arr[] = {1, 2, 3, 4};
  int n = sizeof(arr)/sizeof(arr[0]);
  cout << "Count of strictly increasing subarrays is "
       << countIncreasingSubarrays(arr, n);
  return 0;
}