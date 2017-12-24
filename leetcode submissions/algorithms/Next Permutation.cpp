class Solution {
public:
    void nextPermutation(vector<int>& arr) {
        
        int n=arr.size(),i;
        if(n<2)
            return;
        for(i=n-1;i>0;i--)
        {
            if(arr[i]>arr[i-1])
                break;
        }
        if(i==0)
        {
            reverse(arr.begin(),arr.end());
            return;
        
        }int x=arr[i-1],small=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]>x)
                small=j;
        }
        swap(arr[i-1],arr[small]);
            sort(arr.begin()+i,arr.end());
        for(int i : arr)
            cout<<i<<' ';
    }
};