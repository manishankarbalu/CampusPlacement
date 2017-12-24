class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        vector<int> v;
        int s=0,e=arr.size()-1;
        while(s<e)
        {
            int sum=arr[s]+arr[e];
            if(sum==target)
            {
                v.push_back(s+1);
                v.push_back(e+1);
                return v;
            }
            else
              if(sum>target)
                e--;
                else
                  s++;
        }
        return v;
    }
};