    #include <iostream>
    using namespace std;
     
    int longestPalindrome(string s) {
            string ns;int n=s.length();
            int len=0,i;int st,e;int maxlen=0;
            for(i=1;i<n;i++)
            {
                int j=i,k=i;
                while(k<n-1 && s[k]==s[k+1]) k++;
                i=k+1;
                while(k<n-1 && j>0 && s[j-1]==s[k+1]){j--;k++;}
                len=k-j+1;
                if(maxlen<len)
                {
                	maxlen=len;
                	st=j;e=len;
                }
                 cout<<len<<endl;
            }
               // cout<<endl<<len<<endl;
            
            cout<<s.substr(st,e)<<endl;
            return len;
        }
     
    int main() {
    	// your code goes here
    	string s="babad";
    	string s1="1538023";
    	cout<<s<<endl;
    cout<<longestPalindrome(s);
     
    	return 0;
    }