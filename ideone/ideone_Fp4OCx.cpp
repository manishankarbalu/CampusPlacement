#include <iostream>
#include <limits.h>
using namespace std;

void indexOf1stoflip(int arr[],int size,int &start,int &end)
{
//	int size=sizeof(arr)/sizeof(arr[0]);
    int max_ending=0,max_sofar=INT_MIN,s=0;
    for(int i=0;i<size;i++)
    {
    	max_ending+=(arr[i]==0)?1:-1;
    	if(max_sofar<max_ending)
    	{
    		max_sofar = max_ending;
    		start=s;
    		end=i;
    	}
    	if(max_ending<=0)
    	{
    		max_ending=0;
    		s=i+1;
    	}
    }
    cout<<max_sofar<<endl;
}
int main() {
	// your code goes here
	int arr[]={0,1,0,0,0,1,1,0,0,0,1};
	int n=sizeof(arr)/sizeof(arr[0]);int start=0,end=0;
	indexOf1stoflip(arr,n,start,end);
	cout<<start<<"   "<<end<<endl;
	return 0;
}