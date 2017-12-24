class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> v(nums.size());
        stack<int> s;
        for(int i=nums.size()-1;i>=0;i--)
        {
            s.push(nums[i])   ;
        }
        for(int i=nums.size()-1;i>=0;i--)
        {
            while(!s.empty() && nums[i]>=s.top())
              s.pop();
            if(!s.empty())
              v[i]=s.top();
            else
            v[i]=-1;
            
            s.push(nums[i]);
        }
     return v;   
    }
};