class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        if(nums.size()==0 || k<=0)
            return;
        int n=nums.size();
        vector<int> arr(nums);
        for(int i=0;i<n;i++)
            nums[(i+k)%n]=arr[i];
        
    }
};