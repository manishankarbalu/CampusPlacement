class Solution {
public:
    bool search(vector<int>& nums, int target) {
       if(nums.size()<1) return false;
        if(nums.size()==1) return (nums[0]==target)?true:false;
      int l = 0, h = nums.size() - 1;
        while (l < h) {
            int mid = l + (h - l) / 2;
            if (nums[mid] == target) return true;
            if (nums[mid] < nums[l]) {
                if (nums[mid] < target && nums[h] >= target) l = mid + 1;
                else h = mid - 1;
            } else if (nums[mid] > nums[l]) {
                if (nums[mid] > target && nums[l] <= target) h = mid - 1;
                else l = mid + 1;
            } else {////nums[mid] == nums[l]
                l++;
            }
        }
        return nums[l] == target;
    }
};