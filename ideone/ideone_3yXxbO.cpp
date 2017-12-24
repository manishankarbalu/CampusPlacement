#include <iostream>
#include <map>
#include <unordered_set>
#include <string.h>
using namespace std;

int main() {
	string s="This is mani shankar",word;
//	istringstream ss(s);
	for(char i : s)
	  cout<<i;
//	while(ss >> word)
//	{
//		cout<<word<<endl;
//	}
map<char,int> m;
unordered_set<int> se;
m['a']=2;m['b']=1;se.insert(1);se.insert(1);
	cout<<m['a']<<m['b']<<m['c'];
	cout<<se.count(1)<<se.count(2);
	return 0;
}