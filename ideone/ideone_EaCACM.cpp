#include<bits/stdc++.h>
using namespace std;
 
// Returns maximum subsequence sum such that no three
// elements are consecutive
int maxSumWO3Consec(int arr[], int n)
{
    // Stores result for subarray arr[0..i], i.e.,
    // maximum possible sum in subarray arr[0..i]
    // such that no three elements are consecutive.
    int sum[n];
 
    // Base cases (process first three elements)
    sum[0] = arr[0];
    sum[1] = arr[0] + arr[1];
    sum[2] = max(sum[1], arr[2] + sum[0]);
    //sum[3] = max(max(sum[2], arr[3] + sum[1]),arr[3] + arr[2]+ sum[0]);
    // Process rest of the elements
    // We have three cases
    // 1) Exclude arr[i],  i.e.,  sum[i] = sum[i-1]
    // 2) Exclude arr[i-1], i.e., sum[i] = sum[i-2] + arr[i]
    // 3) Exclude arr[i-2], i.e., sum[i-3] + arr[i] + arr[i-1]
    for (int i=3; i<n; i++)
        sum[i] = max(max(sum[i-1], sum[i-2] + arr[i]),
                     arr[i] + arr[i-1] + sum[i-3]);
 
    return sum[n-1];
}
 
// Driver code
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << maxSumWO3Consec(arr, n);
    return 0;
}