class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n=s.length();
        int L[n][n];
        memset(L,0,sizeof(L));
        for(int i=0;i<n;i++)
          L[i][i]=1;
        for(int cl=2;cl<=n;cl++)
        {
            for(int i=0;i<n-cl+1;i++)
            {
                int j=i+cl-1;
                
                if(s[i]==s[j] && cl==2)
                  L[i][j]=2;
                else
                  if(s[i]==s[j])
                   L[i][j]=L[i+1][j-1]+2;
                   else
                   L[i][j]=max(L[i+1][j],L[i][j-1]);
            }
        }
         return L[0][n-1] ;
    }
};