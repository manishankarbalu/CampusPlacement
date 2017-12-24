#include <iostream>
using namespace std;

bool isSubsetSum(int arr[],int n,int sum)
{
	int dp[sum+1][n+1];
	for(int i=0;i<=n;i++)
	{
		dp[0][i]=true;
	}
	for(int i=1;i<=sum;i++)
	{
		dp[i][0]=false;
	}
	
	for(int i=1;i<=sum;i++)
	{
		for(int j=1;j<=n;j++)
		{
			dp[i][j]=dp[i][j-1];
			if(i>=arr[j-1])
			{
				dp[i][j]|=dp[i-arr[j-1]][j-1];
			}
		}
	}
	for(int i=0;i<=sum;i++)
	{
		for(int j=0;j<=n;j++)
		{
		cout<<dp[i][j]<<' ';
		}
		cout<<endl;
	}
	
	return dp[sum][n];
}


int main()
{
  int set[] = {1,2,3,8,5,6};
  int sum = 7;
  int n = sizeof(set)/sizeof(set[0]);
  if (isSubsetSum(set, n, sum) == true)
     printf("Found a subset with given sum");
  else
     printf("No subset with given sum");
  return 0;
}