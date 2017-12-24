#include <bits/stdc++.h>
using namespace std;
bool checkForDuplicateAtKDistance(int arr[],int size,int k)
{
	unordered_set<int> s;
	for(int i=0;i<size;i++)
	{
		if(i>=k)
			s.erase(arr[i-k]); 
			
		if(s.find(arr[i])==s.end())
		{
			s.insert(arr[i]);
		}
		else
			return false;
		
	}
	return true;
}

int main() {
	int arr[] = {3, 5, 4, 3, 1, 5, 6};
	int k=3;
	int size=sizeof(arr)/sizeof(arr[0]);
	if(checkForDuplicateAtKDistance(arr,size,k))
	  cout<<"no duplicate"<<endl;
	  else
	  cout<<"duplicate"<<endl;
	return 0;
}