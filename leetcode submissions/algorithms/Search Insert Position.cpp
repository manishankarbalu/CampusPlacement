class Solution {
public:
    int searchInsert(vector<int>& arr, int x) {
        
        int l=0,h=arr.size()-1;
        //if(l+1==h) return (arr[h]==x)?h:h+1;
        while(l<h)
        {
            int mid=(l+h)/2;
            
            if(arr[mid]==x)
                return mid;
                if(arr[mid]<x)
                    l=mid+1;
                else
                 h=mid-1;
        }
        return (arr[l]<x)?l+1:l;
        
    }
};