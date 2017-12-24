#include <bits/stdc++.h>
using namespace std;

int func(int n)
{
  string s=bitset<8>(n).to_string();
  int l=0,r=s.length()-1;
  cout<<s<<endl;
  while(l<r)
  {
  	if(s[l]=='0')
  		l++;
  	else
  		break;
  }
  while(l<r)
  {
  	if(s[l]==s[r])
  	{
  		r--;
  		l++;
  	}
  	else
  	{
  		return -1;
  	}
  }
  int count=0;
 for(auto i : s)
 {
 	if(i=='1')
 		count++;
 }
 return count;
}
int main()
{
	int n=15;
	cout<<func(n);
	return 1;
}