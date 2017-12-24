#include <iostream>
#include <vector>
using namespace std;

int main() {
	// your code goes here
	vector<int> v={1,2,3};
	for(int i:v)
	   cout<<i<<' ';
	   v.erase(v.end()-1);
	for(int i:v)
	   cout<<i<<' ';
//	   
//	cout<<v[v.begin()]<<' '<<v[v.end()];
	return 0;
}