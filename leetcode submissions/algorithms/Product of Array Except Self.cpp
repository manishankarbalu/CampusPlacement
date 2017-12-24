class Solution {
public:
   
   void prd(vector<int> &arr,int i,int n,int *l,int *r)
   {
       if(i==n)
       {
           *r=1;
           return;
       }
       
       int l1=*l;
       (*l)=(*l)*arr[i];
       prd(arr,i+1,n,l,r);
       int t=arr[i];
       arr[i]=l1*(*r);
       (*r)=(*r)*t;
   }

    vector<int> productExceptSelf(vector<int>& nums) {
        int l=1,r=1;
        prd(nums,0,nums.size(),&l,&r);
        return nums;
    }
};