// C++ program to count number of strictly
// increasing subarrays
#include<bits/stdc++.h>
using namespace std;

int countIncreasing(int arr[], int n)
{
	// Initialize count of subarrays as 0
	int cnt = 0;

	// Pick starting point
	for (int i=0; i<n; i++)
	{
		// Pick ending point
		for (int j=i+1; j<n; j++)
		{
			if (arr[j] > arr[j-1])
				cnt++;

			// If subarray arr[i..j] is not strictly 
			// increasing, then subarrays after it , i.e., 
			// arr[i..j+1], arr[i..j+2], .... cannot
			// be strictly increasing
			else
				break;
		}
	}
	return cnt;
}

// Driver program
int main()
{
int arr[] = {1, 2, 3, 40,5,6,7,50,45,44};
int n = sizeof(arr)/sizeof(arr[0]);
cout << "Count of strictly increasing subarrays is "
	<< countIncreasing(arr, n);
return 0;
}
