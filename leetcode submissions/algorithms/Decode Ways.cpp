class Solution {
public:
 
    int numDecodings(string s) {
      if(s=="" )
          return 0;
          
      int n=s.length();
        //n-=1;
        vector<int> dp(n+1,0);
    dp[0]=1;
    if(s[0]=='0')
        dp[1]=0;
    else
        dp[1]=1;
    for(int i=2;i<=n;i++)
    {
        int first=s[i-2]-'0';
        int second=s[i-1]-'0';
        int num=second+first*10;
        if(second)
            dp[i]=dp[i-1];
        if(num>=10 && num<=26)
           dp[i]+=dp[i-2];
   }
        return dp[n];
    }
};