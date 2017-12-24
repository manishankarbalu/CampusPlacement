#include <bits/stdc++.h>
using namespace std;

int nextPalin(vector<int> v)
{   int n=v.size()/2;
	int mid=n;
	int i=mid-1;
	bool lar=false;
	int j=(n%2)?mid+1:mid;
	while(v[i]==v[j])
		{i--;j++;}
	if(v[i]<v[j])  lar=true;
	while(i>=0)
		v[j++]=v[i--];
	if(lar)
	{
		i=mid-1;
		int carry=1;
		if(n%2)
		{
			v[mid]+=carry;
			carry=v[mid]/10;
			v[mid]%10;
			j=mid+1;
		}
		else
			 j=mid;
		while(i>=0)
		{
			v[i]+=carry;
			carry=v[i]/10;
			v[i]%=10;
		    v[j++]=v[i--];
		}

	}
	int num=0;
	for(int i : v)
         num=num*10+i;
    return num;
}
bool areAll9(vector<int> v)
{
	for(int i : v)
	  if(i!=9)
	    return false;
	return true;
}
int findnextPalindrome(int num){
	vector<int> v;
	while(num>0)
	{
		v.push_back(num%10);
		num/=10;
	}
	if(areAll9(v))
	{
		int num=1;
		for(int j=0;j<v.size();j++)
		{
			num=num*10;
		}
		return num+1;
	}
	else
		return nextPalin(v);
}
int main() {
	// your code goes here
	cout<<findnextPalindrome(999)<<endl;
	cout<<findnextPalindrome(1211)<<endl;
	return 0;
}