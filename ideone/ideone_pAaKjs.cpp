#include <iostream>
using namespace std;

int longestPalindrome(string s) {
        string ns;int n=s.length();
        int len=0;
        for(int i=1;i<n;i++)
        {
            int j=i-1,k=i;
            int s1=0,s2=0;
            while(j>=0 && k<=n-1)
            {
            	s1+=s[k++]-'0';
            	s2+=s[j--]-'0';
            	//k=(k<n-2)?k++:k;
            	//j=(j>0):j--:j;
            	cout<<s2<<' '<<s1<<' ';
            	len = (s1==s2 && (k-j)&1)?k-j-1:len;
            }
            cout<<endl<<len<<endl;
        }
        return len;
    }

int main() {
	// your code goes here
	string s="123123";
	string s1="1538023";
cout<<longestPalindrome(s1);
	
	return 0;
}