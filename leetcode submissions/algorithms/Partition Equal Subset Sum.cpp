class Solution {
public:
    bool canPartition(vector<int>& arr) {
     
        int n=arr.size();
        int sum=0;
        for (int i: arr)
            sum+=i;
        
        if(sum&1)
            return false;
        sum/=2;
        
        bool dp[sum+1][n+1];
        for(int i=0;i<=n;i++)
             dp[0][i]=true;
        for(int j=1;j<=sum;j++)
              dp[j][0]=false;
            
        for(int i=1;i<=sum;i++)
        {
            for(int j=1;j<=n;j++)
            {
                dp[i][j]=dp[i][j-1];
                if(i>=arr[j-1])
                    dp[i][j]|=dp[i-arr[j-1]][j-1];
            }
        }
        return dp[sum][n];
    }
};