class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& arr) {
        vector<int> res;
        if(arr.size()==0)
            return res;
        int n=arr.size();
        vector<int> v(n,1);
        sort(arr.begin(),arr.end());
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(arr[i]%arr[j]==0 && v[i]<v[j]+1)
                    v[i]=v[j]+1;
            }
        }
        for(int i : v)
            cout<<i<<' ';
        int maxindex=0;
        for(int i=1;i<n;i++)
            maxindex=(v[i]>v[maxindex])?i:maxindex;
        int temp=arr[maxindex]; 
        int cur=v[maxindex];
        //res.push_back(arr[maxindex]);
        for(int i=maxindex;i>=0;i--)
        {
            if(temp%arr[i]==0 && cur==v[i])
            {
                res.push_back(arr[i]);
                temp=arr[i];
                cur--;
            }
        }
     reverse(res.begin(),res.end());
     return res;
    }
};