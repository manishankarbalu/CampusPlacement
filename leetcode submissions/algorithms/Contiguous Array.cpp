class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
        map<int,int> m;int sum=0,maxlen=0;
        m[0]=-1;
        for(int i=0;i<nums.size();i++)
        {
            sum+=(nums[i]==0)?-1:1;
            auto it=m.find(sum);
            if(it!=m.end())
            {
                maxlen=max(maxlen,i-it->second);
            }
            else
                m[sum]=i;
        }
        return maxlen;
            
    }
};