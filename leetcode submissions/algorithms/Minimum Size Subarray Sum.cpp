class Solution {
public:
    int minSubArrayLen(int s, vector<int>& arr) {
        int n=arr.size();
        int sum=0,start=0,minlen=INT_MAX;
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
            while(sum>=s)
            {
                minlen=min(minlen,i-start+1);
                sum-=arr[start++];
            }
        }
        return (minlen==INT_MAX)?0:minlen;
    }
};