class Solution {
public:
    int robber(vector<int>& arr,int s,int e) {
                
       int inc=arr[s],ex=0,ne=0;
       for(int i=s+1;i<=e;i++)
       {
           ne=max(inc,ex);
           inc=ex+arr[i];
           ex=ne;
       }
    return max(inc,ex);
    }
    int rob(vector<int>& arr) {
        int n=arr.size();

        if(n==0) return 0;
        if(n==1) return arr[0];
        if(n==2) return (arr[0]>arr[1])?arr[0]:arr[1];
return max(robber(arr,0,n-2),robber(arr,1,n-1));       
    }
};