class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
       
       int cur=0,count=0;
       map<int,int> result;
       result[0]++;
       for(int i=0;i<nums.size();i++)
       {
           cur+=nums[i];
           count+=result[cur-k];
           result[cur]++;
       }
        return count;
    }
};