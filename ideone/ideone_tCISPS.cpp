#include <iostream>
using namespace std;

// we can do  sorting for the second array and binary search for the element;

void countEleLessThanOrEqual(int arr1[], int arr2[], 
                             int m, int n)
{
//Your code goes here
int max=arr1[0];
for(int i=1;i<m;i++)
   max=(arr1[i]>max)?arr1[i]:max;
int dp[max+1]={0};
for(int i=0;i<n;i++)
{
    if(arr2[i]<=max)
      dp[arr2[i]]++;
}
for(int i=1;i<max+1;i++)
   dp[i]+=dp[i-1];
for(int i=0;i<m;i++)
   
    cout<<dp[arr1[i]]<<' ';
    
}
int main() {
	// your code goes here
    int arr1[]={1, 2, 3, 4, 7, 9};
    //int arr1[]={0,4, 8, 7, 5, 1};
    int m=sizeof(arr1)/sizeof(arr1[0]);
int arr2[]={0, 1, 2, 1, 1, 4};
  //int arr2[]={4, 48, 3, 1, 1, 5};
    int n=sizeof(arr2)/sizeof(arr2[0]);
countEleLessThanOrEqual(arr1,arr2,m,n);
	return 0;
}