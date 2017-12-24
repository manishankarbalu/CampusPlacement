class Solution {
public:
    int countSubstrings(string s) {
          if(s.length()==0)
              return 0;
          int n=s.length();
       int cnt=0;
        for(int i=0;i<n;i++)
        {
            cnt+=findlen(s,i,i,n);
            cnt+=findlen(s,i,i+1,n);
        }
        return cnt;
    }
    int findlen(string s,int l,int r,int n)
    {    int cnt=0;
        while(l>=0 && r<n && s[l--]==s[r++])cnt++;
        return cnt;
    }
};