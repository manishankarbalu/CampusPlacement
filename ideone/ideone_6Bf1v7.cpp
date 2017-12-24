#include <iostream>
using namespace std;

void reverse(string &s,int st,int end)
{
	
	while(st<end)
	{
	char temp;
	temp=s[st];
	s[st++]=s[end];
	s[end--]=temp;
	}
	
}
int main() {
	string s="I love you";
	int n=s.length();
	int st=0,end=0,i=0;
	while(i<n)
	{
		if( (st==-1) && (s[i]!=' '))
		    st=i;
		if( (st!=-1) && (s[i+1]==' ' || s[i+1]=='\0'))
		{
			reverse(s,st,i);
			cout<<st<<' '<<i<<endl;
			st=-1;
		}
		i++;
	}
	cout<<s;
	
	return 0;
}