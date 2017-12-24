class Solution {
public:
    vector<int> countBits(int num) {
        vector<int>dp(num+1,0);
        for(int i=1;i<=num;i++)
        {
                dp[i]=dp[i&i-1]+1;
        }
        return dp;
    }
};