#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<int> printKMax(int arr[],int n,int k)
{
	vector<int> v;
	if(n==0 || n-1<k)
	   return v;
	set<int> s;int i=0,j=0;
	for(;i<k;i++)
	     s.insert(arr[i]);
	for(;i<n;i++)
	{
		v.push_back(*s.rbegin());
	/*	for(int j : s)
		  cout<<j<<' ';
		  cout<<endl;
	*/	s.erase(arr[j++]);
		s.insert(arr[i]);
	}
	v.push_back(*s.rbegin());
	return v;
}
 
int main()
{
    int arr[] = {1, 2, 3, 1, 4, 5, 2, 3, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;
    vector<int> v=printKMax(arr, n, k);
    for(int i : v)
      cout<<i<<' ';
    return 0;
}