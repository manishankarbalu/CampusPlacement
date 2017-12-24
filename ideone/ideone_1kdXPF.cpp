#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int arr[]={4,2,3,4,3,5,6,7,1};
	unordered_set<int> s;int k=3;vector<int> v;
	for(int i=0;i<9;i++)
	{
		 if(i>=k) s.erase(arr[i-k]);
		
		if(s.count(arr[i]))
		  v.push_back(arr[i]);
		
		s.insert(arr[i]);
	   
	   for(int k : s)
	     cout<<k<<' ';
	     cout<<endl;
	    
	}
	cout<<endl;
	for(int i : v)
	cout<<i<<' ';
	
	return 0;
}