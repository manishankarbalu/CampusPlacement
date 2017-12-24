class Solution {
public:
    int minDistance(string w1, string w2) {
   int n1=w1.size();int n2=w2.size();
        if(n1==0) return n2;
        if(n2==0) return n1;
        //vector<vector<int>> v(w1.size(),vector<int> (w2.size(),0));
         int v[n1+1][n2+1]={0};  
            for(int i=0;i<=n2;i++)
                v[0][i]=i;
         for(int i=0;i<=n1;i++)
                v[i][0]=i;
        for(int i=1;i<=n1;i++)
        {
            for(int j=1;j<=n2;j++)
            {
                if(w1[i-1]==w2[j-1])
                    v[i][j]=v[i-1][j-1];
                else
                    v[i][j]=min(v[i][j-1]+1,v[i-1][j]+1);
            }
        }
        return v[n1][n2];
    }
};