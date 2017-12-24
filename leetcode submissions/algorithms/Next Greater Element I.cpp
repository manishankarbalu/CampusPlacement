class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        vector<int> v;
        stack<int> s;
        unordered_map<int,int> m;
        for(int i=nums.size()-1;i>=0;i--)
        {
            while(!s.empty() && nums[i]>=s.top())
              s.pop();
            if(!s.empty())
              m[nums[i]]=s.top();
            else
            m[nums[i]]=-1;
            
            s.push(nums[i]);
        }
       
        for(int i : findNums) v.push_back(m.count(i)?m[i]:-1);
        return v;
    }
};