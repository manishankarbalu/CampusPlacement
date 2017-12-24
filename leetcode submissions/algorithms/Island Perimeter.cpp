class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
     
        if(grid.size()==0)
            return 0;
        if(grid[0].size()==0)
            return 0;
        int m=grid.size(),n=grid[0].size(),cnt=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                 
                {cnt+=checkpts(i,j,m,n,grid);}
                    
            }
        }
        return cnt;
    }
    int checkpts(int i,int j,int m,int n,vector<vector<int>> grid)
    {
        int cnt=0;
        if(i-1<0)
            cnt++;
        else
            if(grid[i-1][j]==0)
                cnt++;
        if(i+1>=m)
            cnt++;
        else
            if(grid[i+1][j]==0)
                cnt++;
        
        
        if(j-1<0)
            cnt++;
        else
            if(grid[i][j-1]==0)
                cnt++;
         if(j+1>=n)
            cnt++;
        else
            if(grid[i][j+1]==0)
                cnt++;
        return cnt;
    }
};