#include <stdio.h>
 
// Returns number of ways to reach score n
int count(int n)
{
	int S[]={3,5,10};
	int temp[n+1];
	for(int i=0;i<n+1;i++)
	{
		temp[i]=0;
	}
	temp[0]=1;
	for(int i=0;i<3;i++)
	{
		for(int j=S[i];j<=n;j++)
		  temp[j]+=temp[j-S[i]];
	}
	return temp[n];
}
 
 
// Driver program
int main(void)
{
    int n = 20;
    printf("Count for %d is %d\n", n, count(n));
 
    n = 13;
    printf("Count for %d is %d", n, count(n));
    return 0;
}