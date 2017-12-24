class Solution {
public:
    bool func1(vector<int>& nums, int k,int l,int r)
    {
        if(r-l<2)
          return false;
        int sum=0;
        for(int i=l;i<r;i++)
           sum+=nums[i];
          if(sum==0 && k==0) return true;
        else
          if(sum!=0 && k==0) return false;
          else
          if(sum%k==0 ) return true;
        
        else
           return func1(nums,k,l+1,r) || func1(nums,k,l,r-1);
    }

    bool checkSubarraySum(vector<int>& nums, int k) {
       
        //return func1(nums,k,0,nums.size());

        set<int> s;
        int sum=0;int pre=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            
            int mod= (k==0)? sum: sum%k;
            
            if(s.count(mod)) return true;
            
            s.insert(pre);
            pre=mod;
            
        }
        return false;
    }
};