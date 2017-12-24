class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        if(nums.size()<3) return 0;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        return max(nums[n-1]*nums[n-2]*nums[n-3],nums[0]*nums[1]*nums[n-1]);
        
    }
};