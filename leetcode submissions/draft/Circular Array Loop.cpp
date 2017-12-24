class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int sum=0;
        for(int i : nums)
            sum+=i;
           if(sum>0 && sum>nums.size())
              return true;
              else
                return false;
    }
};