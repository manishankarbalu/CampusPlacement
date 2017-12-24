#include <iostream>
#include <map>
using namespace std;

int maxSubarray10(int arr[],int n)
{
	map<int,int> m;
	m[0]=-1;
	int sum=0,maxlen=0;
	for(int i=0;i<n;i++)
	{
        sum+=(arr[i]==0)?-1:1;
        auto it=m.find(sum);
        if(it!=m.end())
        	maxlen=max(maxlen,i-it->second);
        else
        	m[sum]=i;
	}
	return maxlen;
}

int main() {
	// your code goes here
	//int arr[]={0,0,0,1,1,1,0};
	int arr[]={0,1,0};
	int n=sizeof(arr)/sizeof(arr[0]);
	cout<<maxSubarray10(arr,n);
	return 0;
}