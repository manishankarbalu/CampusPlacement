#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int palindromeSubsequence(string s)
{
	int n=s.length();
	int a[n][n]={0};
	for(int i=0;i<n;i++)
	     a[i][i]=1;
	for(int l=2;l<=n;l++)
	{
		for(int i=0;i<n-l+1;i++)
		{
			int j=i+l-1;
			
			if(s[i]==s[j] && l==2)
			     a[i][j]=2;
			else
			   if(s[i]==s[j])
			       a[i][j]=2+a[i+1][j-1];
			else
			   a[i][j]=max(a[i+1][j],a[i][j-1]);
			
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<a[i][j]<<' ';
		}
		cout<<endl;
	}
	return a[0][n-1];
}

int palindromePartition(string s)
{
	int n=s.length();
	int a[n][n]={0};
	bool b[n][n]={false};
	for(int i=0;i<n;i++)
	    { a[i][i]=0;b[i][i]=true;}
	for(int l=2;l<=n;l++)
	{
		for(int i=0;i<n-l+1;i++)
		{
			int j=i+l-1;
			
			if(l==2)
			     b[i][j]=(s[i]==s[j]);
			else
			     b[i][j]=(s[i]==s[j] && a[i+1][j-1]);
			     
			if(b[i][j])
			    a[i][j]=0;
			else
			{
				a[i][j]=INT_MAX;
				for(int k=i;k<j;k++)
				    a[i][j]=min(a[i][j],a[i][k]+a[k+1][j]+1);
			}
			
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<a[i][j]<<' ';
		}
		cout<<endl;
	}
	return a[0][n-1];
	
}
int main() {
	// your code goes here
	string s="madam";
	string s1="abbca";
	//cout<<palindromeSubsequence(s)<<endl;
	cout<<palindromePartition(s)<<endl;
	return 0;
}