class Solution {
public:
    vector<int> searchRange(vector<int>& arr, int x) {
        
        vector<int> ans(2,-1);
        if(arr.size()<1) return ans;
        int l=0,h=arr.size()-1;
        
        while(l<h)
        {
            int mid=(l+h)/2;
            if(arr[mid]<x)
                l=mid+1;
            else
                h=mid;
        }
        if(arr[l]==x) ans[0]=l;
        
        else return ans;
        h=arr.size()-1;
        while(l<h)
        {
            int mid=(l+h)/2+1;
            if(arr[mid]>x)
                h=mid-1;
            else
                l=mid;
            
        }
        ans[1]=h;
        return ans;
    }
};