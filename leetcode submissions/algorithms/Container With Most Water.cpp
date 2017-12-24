class Solution {
public:
    int maxArea(vector<int>& arr) {
        int water=0,l=0,r=arr.size()-1;
        while(l<r)
        {
            int h=min(arr[l],arr[r]);
            water=max(water,(r-l)*h);
            while(arr[l]<=h && l<r) l++;
            while(arr[r]<=h && l<r) r--;
        }
        return water;
    }
};