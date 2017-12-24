#include <iostream>
#include <set>
using namespace std;

bool ispair(int arr[],int n,int x)
{
	set<int> s;
	for(int i=0;i<n;i++)
	{
		int search=x-arr[i];
		if(s.count(search))
		   return true;
		s.insert(arr[i]);
	}
	return false;
}

int main() {
int arr[]={1, 4, 45, 6, 10, 8};
	int n=6;
	int x=40;
	cout<<ispair(arr,n,x);
	return 0;
}