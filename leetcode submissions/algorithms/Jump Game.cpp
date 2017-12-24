class Solution {
public:
    int mini(int a,int b)
    {
        return (a<b)?a:b;
    }
    bool canJump(vector<int>& nums) {
     
     int jumps[nums.size()];
     memset(jumps,INT_MAX,sizeof(jumps));
     jumps[0]=0;
     for(int i=1;i<nums.size();i++)
     {   jumps[i] = INT_MAX;
         for(int j=0;j<i;j++)
         {
             if(i<=j+nums[j] && jumps[j]!=INT_MAX)
                {jumps[i]=min(jumps[i],jumps[j]+1);break;}
         }
     }
     return (jumps[nums.size()-1]==INT_MAX)?false:true;    
        
    }
};