#include <iostream>
using namespace std;

int main() {
	// your code goes here
	string s="g  eeks   for ge  eeks  ";
	int i=0;
	for(char c : s)
	{
		if(c!=' ')
		  {s[i]=c;i++;}
		  
	}
//	s[--i]='\0';
    s=s.substr(0,i);
	cout<<s;

	return 0;
}