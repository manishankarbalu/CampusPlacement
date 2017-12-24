class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obs) {
      
        
        int m=obs.size(),n=obs[0].size();
        if(obs[0][0]!=0 || obs[m-1][n-1]!=0) return 0;
        int arr[m+1][n+1];//={{0}};
        for(int i=0;i<=m;i++)
            for(int j=0;j<=n;j++)
                    arr[i][j]=0;
        
        arr[0][1]=1;
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(obs[i-1][j-1]==0)
                arr[i][j]=arr[i-1][j]+arr[i][j-1];
            }
        }
        return arr[m][n];
    }   
    
};