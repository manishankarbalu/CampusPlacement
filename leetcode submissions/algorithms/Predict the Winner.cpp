class Solution {
public:
    
    int getVal(vector<int>& arr,int i,int j)
    {
        if(i==j) return arr[i];
        if(i+1==j) return max(arr[i],arr[j]);
        return max(arr[i]+min(getVal(arr,i+2,j),getVal(arr,i+1,j-1)),arr[j]+min(getVal(arr,i+1,j-1),getVal(arr,i,j-2)));
    }
    bool PredictTheWinner(vector<int>& arr) {
        
        int n=arr.size();
        int p1=0,p2=0;//bool flag=true;
        for(int i : arr)
            p2+=i;
        p1=getVal(arr,0,n-1);
        return (p1>=p2-p1)?true:false;
    }
};