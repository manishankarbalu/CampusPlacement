class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int front=1,back=1;
        int maxprd=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            front*=nums[i];
            back*=nums[n-i-1];
            maxprd=max(maxprd,max(front,back));
            front=(front==0)?1:front;
            back=(back==0)?1:back;
        }
        return maxprd;
}
};