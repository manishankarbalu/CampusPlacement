class Solution {
public:
    int rob(vector<int>& arr) {
        int n=arr.size();
        if(n==0) return 0;
        if(n==1) return arr[0];
        if(n==2) return (arr[0]>arr[1])?arr[0]:arr[1];
        int dp[n]={0};
        dp[0]=arr[0];dp[1]=(arr[0]>arr[1])?arr[0]:arr[1];
        
        for(int i=2;i<n;i++)
        {
            dp[i]=max(dp[i-1],arr[i]+dp[i-2]);
        }
        return dp[n-1];
    }
};