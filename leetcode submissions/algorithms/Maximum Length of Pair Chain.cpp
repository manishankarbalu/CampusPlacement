class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        if(pairs.size()==0) return 0;
        sort(pairs.begin(),pairs.end(),cmp);
        int i=0,j=0,cnt=0;
        for(;j<pairs.size();j++)
        {
            if(pairs[i][1]<pairs[j][0] || j==0)
            {
                cnt++;i=j;
            }
        }
        return cnt;
    }
    static bool cmp(vector<int>a,vector<int>b)
    {
        return a[1]<b[1];
    }
};