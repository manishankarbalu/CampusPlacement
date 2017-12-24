class Solution {
public:
    string longestPalindrome(string s) {
        string ns;int n=s.length();
        int st=0,ed=1;
        for(int i=0;i<n;)
        {
            int j=i,k=i;
            while(k<n-1 && s[k+1]==s[k]) ++k;
            i=k+1;
            while(k<n-1 && j>0 && s[k+1]==s[j-1]) {k++;j--;}
            int len=k-j+1;
            if(len>ed){st=j;ed=len;};
        }
        return s.substr(st,ed);
    }
};